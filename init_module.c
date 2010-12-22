/*
   Copyright (C) 2007 by e-con Systems.
   www.e-consystems.com

   This file is licensed under the terms of the GNU General Public License
   version 2. This program is licensed "as is" without any warranty of any
   kind, whether express or implied.

   Original Author : Ananthapadmanaban
   
   Modified: Scott Ellis, Jumpnow, www.jumpnowtek.com
 */

#include "inc_header.h"

static INT32 video_nr = -1;


static int init_plat_res(cam_data *cam)
{
	/* Allocate the memory region in the isp */
	if (!cam->pdev) {
		printk(KERN_ALERT "init_plat_res: cam->pdev is NULL\n");
		return -1;
	}
		
	cam->mem = platform_get_resource(cam->pdev, IORESOURCE_MEM, 0);

	if (!cam->mem) {
		printk(KERN_ALERT "init_plat_res: fail get IORESOURCE_MEM\n");
		return -1;
	} 

	/* FIXME : Unable to request the memory region */
#if 0
	if (!request_mem_region(cam->mem->start, MAP_ISP_REGION,
				cam->pdev->name))
	{
		TRACE_ERR_AND_RET(FAIL);
	}
#endif

	cam->isp = (isp_reg_bit_access*)ioremap_nocache(cam->mem->start, 
							MAP_ISP_REGION);
	
	if (!cam->isp) {
		printk(KERN_ALERT "init_plat_res: ioremap failed\n");
		return -1;
	}
	
	return 0;
}

static int init_plat_irq(cam_data *cam)
{
	cam->irq = platform_get_irq(cam->pdev, 0);
	
	if (cam->irq <= 0) {
		printk(KERN_ALERT "init_plat_irq: failed to get plat irq\n");
		return -1;
	} 
	
	if (request_irq(cam->irq, omap34xx_isp_isr, IRQF_SHARED, 
			"omap3cameraisp", cam)) {
		printk(KERN_ALERT "init_plat_irq: request_irq failed\n");
		return -1;
	}
	
	return 0;
}

static int init_hwr_clock(cam_data *cam)
{
	struct device_driver camera_drv = {
		.name = "camera"
	};

	struct device camera_dev = {
		.driver = &camera_drv,
	};
	
	cam->cam_ick = clk_get(&camera_dev, "cam_ick");
	
	if (IS_ERR(cam->cam_ick)) {
		printk(KERN_ALERT "init_hwr_clock: error getting cam_ick\n");
		return -1;
	}

	cam->cam_mclk = clk_get(&camera_dev, "cam_mclk");

	if (IS_ERR(cam->cam_mclk)) {
		printk(KERN_ALERT "init_hwr_clock: error getting cam_mclk\n");
		return -1;
	}

	return 0;
}

static int all_clk_enable(cam_data *cam)
{
	if (cam->clk_enable)
		return 0;
	
	if (clk_enable(cam->cam_mclk))
		return -1;

	if (clk_enable(cam->cam_ick)) {
		clk_disable(cam->cam_mclk);
		return -1;
	}

	cam->clk_enable = 1;

	return 0;
}

static void init_cam_struct(cam_data *cam)
{
	cam->capture.v2f.fmt.pix.width 	= 480;
	cam->capture.v2f.fmt.pix.height = 640;
	cam->capture.v2f.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	cam->capture.v2f.fmt.pix.pixelformat = V4L2_PIX_FMT_UYVY;

	init_waitqueue_head(&cam->still.dma_frame_complete_still);
	init_waitqueue_head(&cam->capture.capture_frame_complete);	
}

static int isp_probe_late_init(cam_data *cam)
{
	FNRESLT ret_val;
	INT32 ret;

	ret_val	= init_v4l2_base_struct(cam);
	if(CHECK_IN_FAIL_LIMIT(ret_val))
	{
		printk(KERN_ERR "Failed to initialize camera device\n");
		return -1;
	}

	if (!cam)
		return -1;

	if (init_plat_res(cam))
		return -1;

	if (init_plat_irq(cam))
		return -1;

	init_cam_struct(cam);

	if (init_hwr_clock(cam))
		return -1;

	if (all_clk_enable(cam))
		return -1;


	ret_val	= init_omap_hwr(cam);
	if(CHECK_IN_FAIL_LIMIT(ret_val))
	{
		printk(KERN_ERR "Failed to initialize omap hardware device\n");
		TRACE_ERR_AND_RET(ret_val);
	}

	ret_val	= register_sensor_bus(cam);
	if(CHECK_IN_FAIL_LIMIT(ret_val))
	{
		TRACE_ERR_AND_RET(ret_val);
	}

	if(cam->cam_sensor.init)
	{
		ret_val	= cam->cam_sensor.init(cam);
		if(CHECK_IN_FAIL_LIMIT(ret_val))
		{
			return ret_val;
		}
	}

#if defined(CONFIG_HAVE_LED_FLASH)
	ret_val	= register_flash_driver(cam);
	if(CHECK_IN_FAIL_LIMIT(ret_val))
	{
		return ret_val;
	}
#endif
	if(cam->cam_flash.init)
	{
		ret_val	= cam->cam_flash.init(cam);
		if(CHECK_IN_FAIL_LIMIT(ret_val))
		{
			return ret_val;
		}
	}

	ret = video_register_device(cam->video_dev, VFL_TYPE_GRABBER, video_nr);
	if (ret	== FAIL)
	{
		video_device_release(cam->video_dev);
		cam->video_dev	= NULL;

		v4l2_base_struct(&cam, MAKE_ADDRESS_INVALID);
		printk(KERN_ERR "video_register_device failed\n");
		TRACE_ERR_AND_RET(ret_val);
	}
	return SUCCESS;
}

static int isp_probe(struct platform_device *pdev)
{
	FNRESLT ret_val;
	cam_data *cam;

	ret_val	= v4l2_base_struct(&cam, GET_ADDRESS);
	if(CHECK_IN_FAIL_LIMIT(ret_val))
	{
		printk(KERN_ERR "Failed to register the camera device\n");
		TRACE_ERR_AND_RET(FAIL);
	}

	cam->pdev = pdev;
	
	platform_set_drvdata(pdev, cam);

	cam->dev = &pdev->dev;

	return 0;
}

static __init int cam_driver_init(void)
{
	FNRESLT ret_val;
	cam_data *cam;

	printk(KERN_INFO "Driver Module info : "MODULE_NAME "\n");
	printk(KERN_INFO "Version info : "VERSION_NO "\n");
	
	cam = kmalloc(sizeof(cam_data), GFP_KERNEL);

	if (!cam) {
		printk(KERN_ERR "Mem alloc fail for camera device\n");
		return -ENOMEM;
	}

	memset(cam, 0, sizeof(cam_data));

	ret_val	= v4l2_base_struct(&cam, SET_ADDRESS);
	if(CHECK_IN_FAIL_LIMIT(ret_val))
	{
		printk(KERN_ERR "Failed to register the camera device\n");
		TRACE_ERR_AND_RET(FAIL);
	}

	if (init_phy_mem())
		return -1;

	cam->omap3isp_driver.probe = isp_probe;
	cam->omap3isp_driver.remove = isp_remove;
	cam->omap3isp_driver.driver.name = "omap3isp";

	if (platform_driver_register(&cam->omap3isp_driver)) {
		printk(KERN_ALERT "platform_driver_register failed\n");
		return -1;
	}
		

	if (isp_probe_late_init(cam)) {
		platform_driver_unregister(&cam->omap3isp_driver);
		v4l2_base_struct(&cam, MAKE_ADDRESS_INVALID);
		return -1;
	}

	return 0;
}
module_init(cam_driver_init);

module_param(video_nr, int, 0444);
MODULE_AUTHOR("e-consystems india pvt. lmt");
MODULE_DESCRIPTION("V4L2 capture driver for omap based cameras");
MODULE_LICENSE("GPL");
MODULE_SUPPORTED_DEVICE("video");
