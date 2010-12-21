/**********************************************************************************************************
 *   Copyright (C) 2007 by e-con Systems.                                                                 *
 *   www.e-consystems.com                                                                                 *
 *                                                                                                        *
 *   This file is licensed under the terms of the GNU General Public License                              *
 *   version 2. This program is licensed "as is" without any warranty of any                              *
 *   kind, whether express or implied.                                                                    *
 *                                                                                                        *
 *                                                                                                        *
 *   PROJECT	           :        OMAP Camera development                                               *
 *   MODULE NAME           :        OV3640                                                                *
 *   MODULE VERSION        :        VER 1.0                                                               *
 *                                                                                                        *
 *                                                                                                        *
 *                                                                                                        *
 *   Version No	: 000-0001                                                          CODE_REV  : 0.0.1.0   *
 **********************************************************************************************************/

/*
 *==========================================================================================================
 *                                        REVISION HISTORY                                  
 *----------------------------------------------------------------------------------------------------------
 * CODE_REV  REASON FOR MODIFICATION                MODIFIED FUNCTION NAME  	            AUTHOR
 *----------------------------------------------------------------------------------------------------------
 * 
 * 0.0.1.0   ------------------------ Driver development ---------------------------- Ananthapadmanaban
 *
 *==========================================================================================================
 */

/*
 * ----------------------------------------------------------------------------------------------------------
 *
 * 					Header files inclusion part
 *
 * ----------------------------------------------------------------------------------------------------------
 */

#include "inc_header.h"

/*
 * Global variables
 */

static INT32 video_nr = -1;

/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	:	OMAP_V4L2_BASE
 *  Name	:	init_plat_res
 *  Parameter1	:	cam_data *cam	- Base address of camera structure pointer
 *  Returns	:	FNRESLT		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative value be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *  Description	: 	
 *  Comments	:  	
 ************************************************************************************************************/
FNRESLT init_plat_res(cam_data *cam)
{
/*
 * Allocate the memory region in the isp
 */

	if(cam->pdev == NULL)
	{
		TRACE_ERR_AND_RET(FAIL);
	}
		
	cam->mem = platform_get_resource(cam->pdev, IORESOURCE_MEM, 0);
	if (!cam->mem)
	{
		TRACE_ERR_AND_RET(FAIL);
	}
/*
 * FIXME :
 * 	Unable to request the memory region
 */
#if 0
	if (!request_mem_region(cam->mem->start, MAP_ISP_REGION,cam->pdev->name))
	{
		TRACE_ERR_AND_RET(FAIL);
	}
#endif
	/* map the region */
	cam->isp = (isp_reg_bit_access*)ioremap_nocache(cam->mem->start,MAP_ISP_REGION);
	if (cam->isp	== NULL)
	{
		TRACE_ERR_AND_RET(FAIL);
	}
	
	return SUCCESS;
}
/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	:	OMAP_V4L2_BASE
 *  Name	:	init_plat_irq
 *  Parameter1	:	cam_data *cam	- Base address of camera structure pointer
 *  Returns	:	FNRESLT		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative value be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *  Description	: 	
 *  Comments	:  	
 ************************************************************************************************************/
FNRESLT init_plat_irq(cam_data *cam)
{
	cam->irq	= platform_get_irq(cam->pdev, 0);
	if (cam->irq <= 0)
	{
		TRACE_ERR_AND_RET(FAIL);
	}
	
	if (request_irq(cam->irq, omap34xx_isp_isr, IRQF_SHARED,
				"Omap 3 Camera ISP",cam))
	{
		TRACE_ERR_AND_RET(FAIL);
	}

	return SUCCESS;
}

/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	:	OMAP_V4L2_BASE
 *  Name	:	init_hwr_clock
 *  Parameter1	:	cam_data *cam	- Base address of camera structure pointer
 *  Returns	:	FNRESLT		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative value be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *  Description	: 	
 *  Comments	:  	
 ************************************************************************************************************/
FNRESLT init_hwr_clock(cam_data *cam)
{
	struct device_driver camera_drv =	\
	{
		.name = "camera"
	};

	struct device camera_dev = 		\
	{
		.driver = &camera_drv,
	};
	
	cam->cam_ick = clk_get(&camera_dev, "cam_ick");
	if (IS_ERR(cam->cam_ick))
	{
//		ret_err = PTR_ERR(isp_obj.cam_ick);
		TRACE_ERR_AND_RET(FAIL);		

	}
	cam->cam_mclk = clk_get(&camera_dev, "cam_mclk");
	if (IS_ERR(cam->cam_mclk))
	{
//		ret_err = PTR_ERR(cam->cam_mclk);
		TRACE_ERR_AND_RET(FAIL);		
	}

	return SUCCESS;
}
/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	:	OMAP_V4L2_BASE
 *  Name	:	all_clk_enable
 *  Parameter1	:	cam_data *cam	- Base address of camera structure pointer
 *  Returns	:	FNRESLT		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative value be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *  Description	: 	
 *  Comments	:  	
 ************************************************************************************************************/
FNRESLT all_clk_enable(cam_data *cam)
{
	INT32 ret_err = DISABLE;

	if(cam->clk_enable	== DISABLE)
	{
		cam->clk_enable	= ENABLE;
	}else
	{
		return SUCCESS;
	}
	
	ret_err = clk_enable(cam->cam_mclk);
	if(ret_err)
	{
		goto err;
	}

	ret_err = clk_enable(cam->cam_ick);
	if(ret_err)
	{
		clk_disable(cam->cam_mclk);
		goto err;
	}
	return SUCCESS;

	err:
	{
/*
 * TODO:
 * Implement all clock disable function here
 */
		cam->clk_enable	= DISABLE;
		TRACE_ERR_AND_RET(FAIL);		
	}
}

/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	:	OMAP_V4L2_BASE
 *  Name	:	init_cam_struct
 *  Parameter1	:	cam_data *cam	- Base address of camera structure pointer
 *  Returns	:	FNRESLT		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative value be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *  Description	: 	
 *  Comments	:  	
 ************************************************************************************************************/
FNRESLT init_cam_struct(cam_data *cam)
{
	if(cam == NULL)
	{
		TRACE_ERR_AND_RET(FAIL);
	}

	
	cam->capture.v2f.fmt.pix.width		= 480;
	cam->capture.v2f.fmt.pix.height		= 640;
	cam->capture.v2f.type			= V4L2_BUF_TYPE_VIDEO_CAPTURE;
	cam->capture.v2f.fmt.pix.pixelformat	= V4L2_PIX_FMT_UYVY;
/*
 * init the wait queue
 */

	init_waitqueue_head(&cam->still.dma_frame_complete_still);
	init_waitqueue_head(&cam->capture.capture_frame_complete);	
	
	return SUCCESS;
}

/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	:	OMAP_V4L2_BASE
 *  Name	:	isp_probe_late_init
 *  Parameter1	:	cam_data *cam
 *  Returns	:	FNRESLT		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative value be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *  Description	: 	
 *  Comments	:  	
 ************************************************************************************************************/

FNRESLT isp_probe_late_init(cam_data *cam)
{
	FNRESLT ret_val;
	INT32 ret;

/*
 * initialize the camera structre
 */

	ret_val	= init_v4l2_base_struct(cam);
	if(CHECK_IN_FAIL_LIMIT(ret_val))
	{
		printk(KERN_ERR "Failed to initialize camera device\n");
		TRACE_ERR_AND_RET(FAIL);
	}
/*
 * Get the platform resource
 */
	ret_val	= init_plat_res(cam);
	if(CHECK_IN_FAIL_LIMIT(ret_val))
	{
		TRACE_ERR_AND_RET(ret_val);
	}
	
	ret_val	= init_plat_irq(cam);
	if(CHECK_IN_FAIL_LIMIT(ret_val))
	{
		TRACE_ERR_AND_RET(ret_val);
	}
/*
 * TODO: initialize the hardware 
 *
 */
/*
 * initialize the camera structure
 */
	ret_val	= init_cam_struct(cam);
	if(CHECK_IN_FAIL_LIMIT(ret_val))
	{
		TRACE_ERR_AND_RET(ret_val);
	}
/*
 * Configure the camera interface lines
 */

	ret_val	= init_hwr_clock(cam);
	if(CHECK_IN_FAIL_LIMIT(ret_val))
	{
		TRACE_ERR_AND_RET(ret_val);
	}

	ret_val	= all_clk_enable(cam);
	if(CHECK_IN_FAIL_LIMIT(ret_val))
	{
		TRACE_ERR_AND_RET(ret_val);
	}

	ret_val	= init_omap_hwr(cam);
	if(CHECK_IN_FAIL_LIMIT(ret_val))
	{
		printk(KERN_ERR "Failed to initialize omap hardware device\n");
		TRACE_ERR_AND_RET(ret_val);
	}

/*
 * TODO:
 * 	initialize the sensor 
 */

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
/*
 * register the flash driver
 */

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

/*
 * register the video device
 */
	ret	= video_register_device(cam->video_dev, VFL_TYPE_GRABBER, video_nr);
	if (ret	== FAIL)
	{
		video_device_release(cam->video_dev);
		cam->video_dev	= NULL;

		v4l2_base_struct(&cam,MAKE_ADDRESS_INVALID);
		printk(KERN_ERR "video_register_device failed\n");
		TRACE_ERR_AND_RET(ret_val);
	}
	return SUCCESS;
}
/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	:	OMAP_V4L2_BASE
 *  Name	:	isp_probe
 *  Parameter1	:	struct platform_device *pdev
 *  Returns	:	INT32	- On sucess returns 0
 *  				- On Failure a negative number be returned
 *  Description	: 	
 *  Comments	:  	
 ************************************************************************************************************/
static INT32 isp_probe(struct platform_device *pdev)
{

	FNRESLT ret_val;
	cam_data *cam;
/*
 * register the camera base pointer
 */

	ret_val	= v4l2_base_struct(&cam,GET_ADDRESS);
	if(CHECK_IN_FAIL_LIMIT(ret_val))
	{
		printk(KERN_ERR "Failed to register the camera device\n");
		TRACE_ERR_AND_RET(FAIL);
	}

	cam->pdev	= pdev;
	
/*
 * register the driver content into platform
 */
	platform_set_drvdata(pdev, cam);

/*
 * Have a device structure copy in the driver
 */
	cam->dev = &pdev->dev;


	return SUCCESS;
}
/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	:	OMAP_V4L2_BASE
 *  Name	:	cam_driver_init
 *  Parameter1	:	INT0
 *  Returns	:	INT32	- On sucess returns 0
 *  				- On Failure a negative number be returned
 *  Description	: 	
 *  Comments	:  	
 ************************************************************************************************************/

static __init INT32 cam_driver_init(INT0)
{
	INT32 plat_ret;
	FNRESLT ret_val;

	cam_data *cam	= NULL;
	printk(KERN_INFO "Driver Module info : "MODULE_NAME "\n");
	printk(KERN_INFO "Version info : "VERSION_NO "\n");

	if ((cam = kmalloc(sizeof(cam_data), GFP_KERNEL)) == NULL)
	{
		printk(KERN_ERR "Failed to allocate memory to register the camera device\n");
		TRACE_ERR_AND_RET(FAIL);
	}
/*
 * Clear the memory 
 */
	memset(cam, 0, sizeof(cam_data));

	ret_val	= v4l2_base_struct(&cam,SET_ADDRESS);
	if(CHECK_IN_FAIL_LIMIT(ret_val))
	{
		printk(KERN_ERR "Failed to register the camera device\n");
		TRACE_ERR_AND_RET(FAIL);
	}
/*
 * init the reserved memory for camera 
 */

	ret_val	= init_phy_mem();
	if(CHECK_IN_FAIL_LIMIT(ret_val))
	{
		TRACE_ERR_AND_RET(FAIL);
	}

	cam->omap3isp_driver.probe		= isp_probe;
	cam->omap3isp_driver.remove		= isp_remove;
	cam->omap3isp_driver.driver.name	= "omap3isp";

	plat_ret = platform_driver_register(&cam->omap3isp_driver);
	if (plat_ret)
	{
		TRACE_ERR_AND_RET(plat_ret);
	}

	ret_val	= isp_probe_late_init(cam);
	if(CHECK_IN_FAIL_LIMIT(ret_val))
	{
		goto exit;
	}

	return SUCCESS;

	exit:
	{
		platform_driver_unregister(&cam->omap3isp_driver);
		
		ret_val	= v4l2_base_struct(&cam,MAKE_ADDRESS_INVALID);
		if(CHECK_IN_FAIL_LIMIT(ret_val))
		{
			printk(KERN_ERR "Failed to register the camera device\n");
			TRACE_ERR_AND_RET(FAIL);
		}
		TRACE_ERR_AND_RET(FAIL);
	}
}

module_init(cam_driver_init);

module_param(video_nr, int, 0444);
MODULE_AUTHOR("e-consystems india pvt. lmt");
MODULE_DESCRIPTION("V4L2 capture driver for omap based cameras");
MODULE_LICENSE("GPL");
MODULE_SUPPORTED_DEVICE("video");
