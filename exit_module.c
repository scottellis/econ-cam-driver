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
 *
 *==========================================================================================================
 */


#include "inc_header.h"
#include "Headerfile.h"
#include "v4l2_driver_base.h"
#include "fn_protype.h"

static void all_clk_disable(cam_data *cam)
{
	if (!(IS_ERR(cam->cam_mclk)))
		clk_disable(cam->cam_mclk);
	
	if (!(IS_ERR(cam->cam_ick)))
		clk_disable(cam->cam_ick);
	
	cam->clk_enable	= 0;
}

static void all_clk_unregister(cam_data *cam)
{
	if (!(IS_ERR(cam->cam_ick)))
		clk_put(cam->cam_ick);
	
	if (!(IS_ERR(cam->cam_mclk)))
		clk_put(cam->cam_mclk);
}

static void free_all_irq(cam_data *cam)
{
	free_irq(cam->irq,cam);
}

static int exit_omap_hwr(cam_data *cam)
{
	if (exit_cam_interface(cam))
		return -1;

	if (exit_cam_isp_ccdc(cam))
		return -1;

	return 0;
}

int isp_remove(struct platform_device *pdev)
{
	cam_data *cam;

	if (v4l2_base_struct(&cam, GET_ADDRESS) < 0) {
		printk(KERN_ERR "isp_remove error\n");
		return -1;
	}

	if (cam->cam_sensor.exit) {
		if (cam->cam_sensor.exit(cam) < 0)
			return -1;
	}

	if(cam->cam_flash.exit) {
		if (cam->cam_flash.exit(cam) < 0)
			return -1;
	}

	if (disable_isp_irq0(cam) < 0)
		return -1;

	free_all_irq(cam);

	all_clk_disable(cam);

	all_clk_unregister(cam);

	if (exit_omap_hwr(cam))
		return -1;

	video_unregister_device(cam->video_dev);
//	video_device_release(cam->video_dev);

	return 0;
}

/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	:	OMAP_V4L2_BASE_00
 *  Name	:	omap_v4l2_camera_driver_exit
 *  Parameter1	:	INT0
 *  Returns	:	INT0
 *  Description	: 	
 *  Comments	:  	
 ************************************************************************************************************/

static void __exit omap_v4l2_camera_driver_exit(void)
{
	cam_data *cam;

	if (v4l2_base_struct(&cam, GET_ADDRESS) < 0) {
		printk(KERN_ERR "Failed to get the camera base address\n");
		return;
	}

	platform_driver_unregister(&cam->omap3isp_driver);

	printk(KERN_INFO MODULE_NAME ":unregistering v4l2 camera driver\n");

	cam->video_dev = NULL;

	v4l2_base_struct(&cam, MAKE_ADDRESS_INVALID);
}
module_exit(omap_v4l2_camera_driver_exit);
