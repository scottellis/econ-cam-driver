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


/*
 * Include Header file
 */

#include "inc_header.h"

/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	:	
 *  Name	:	all_clk_disable	
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
FNRESLT all_clk_disable(cam_data *cam)
{
	if(!(IS_ERR(cam->cam_mclk)))
	{
		clk_disable(cam->cam_mclk);
	}

	if(!(IS_ERR(cam->cam_ick)))
	{
		clk_disable(cam->cam_ick);
	}
	cam->clk_enable	= DISABLE;

	return SUCCESS;
}
/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	:	
 *  Name	:	all_clk_unregister
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
FNRESLT all_clk_unregister(cam_data *cam)
{
	if(!(IS_ERR(cam->cam_ick)))
	{
		clk_put(cam->cam_ick);
	}

	if(!(IS_ERR(cam->cam_mclk)))
	{
		clk_put(cam->cam_mclk);
	}

	return SUCCESS;
}
/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	:	
 *  Name	:	free_all_irq
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
FNRESLT free_all_irq(cam_data *cam)
{
	free_irq(cam->irq,cam);
	return SUCCESS;
}
/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	:	OMAP_V4L2_BASE
 *  Name	:	isp_remove
 *  Parameter1	:	struct platform_device *pdev
 *  Returns	:	INT32	- On sucess returns 0
 *  				- On Failure a negative number be returned
 *  Description	: 	
 *  Comments	:  	
 ************************************************************************************************************/
INT32 isp_remove(struct platform_device *pdev)
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

	if(cam->cam_sensor.exit)
	{
		ret_val	= cam->cam_sensor.exit(cam);
		if(CHECK_IN_FAIL_LIMIT(ret_val))
		{
			TRACE_ERR_AND_RET(FAIL);
		}
	}

	if(cam->cam_flash.exit)
	{
		ret_val	= cam->cam_flash.exit(cam);
		if(CHECK_IN_FAIL_LIMIT(ret_val))
		{
			TRACE_ERR_AND_RET(FAIL);
		}
	}

	ret_val	= disable_isp_irq0(cam);
	if(CHECK_IN_FAIL_LIMIT(ret_val))
	{
		TRACE_ERR_AND_RET(FAIL);
		
	}

	ret_val	= free_all_irq(cam);
	if(CHECK_IN_FAIL_LIMIT(ret_val))
	{
		TRACE_ERR_AND_RET(FAIL);
		
	}

	ret_val	= all_clk_disable(cam);
	if(CHECK_IN_FAIL_LIMIT(ret_val))
	{
		TRACE_ERR_AND_RET(FAIL);
	}

	ret_val	= all_clk_unregister(cam);
	if(CHECK_IN_FAIL_LIMIT(ret_val))
	{
		TRACE_ERR_AND_RET(FAIL);
	}

	ret_val	= exit_omap_hwr(cam);
	if(CHECK_IN_FAIL_LIMIT(ret_val))
	{
		TRACE_ERR_AND_RET(FAIL);
	}

	video_unregister_device(cam->video_dev);
//	video_device_release(cam->video_dev);

	return SUCCESS;
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
	FNRESLT ret_val;
	cam_data *cam;

/*
 * TODO:
 * 	Release the hardware resource properly
 */

	ret_val	= v4l2_base_struct(&cam,GET_ADDRESS);
	if(CHECK_IN_FAIL_LIMIT(ret_val))
	{
		printk(KERN_ERR "Failed to get the camera base address\n");
		return ;		
	}

	platform_driver_unregister(&cam->omap3isp_driver);

	printk(KERN_INFO MODULE_NAME ":unregistering v4l2 camera driver\n");

	cam->video_dev	= NULL;
	v4l2_base_struct(&cam,MAKE_ADDRESS_INVALID);

	return ;
}
module_exit(omap_v4l2_camera_driver_exit);
