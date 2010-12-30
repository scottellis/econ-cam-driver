/**********************************************************************************************************
 *   Copyright (C) 2007 by e-con Systems .                                                                *
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

/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	:	
 *  Name	:	v4l2_base_struct
 *  Parameter1	:	cam_data **cam	- pointer need to register
 *  Parameter2	:	UINT8 option	- set or get the address
 *  Returns	:	int		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative value be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *  Description	: 	
 *  Comments	:  	
 ************************************************************************************************************/
int v4l2_base_struct(cam_data **cam,UINT8 option)
{

/*
 * SET_ADDRESS 
 * GET_ADDRESS 
 * MAKE_ADDRESS_INVALID
 */
	static unsigned int g_cam_st_addr;

	if(cam == NULL)
	{
		TRACE_ERROR(MEMORY_NOT_VALID);	
		return MEMORY_NOT_VALID;
	}

	if(option == SET_ADDRESS)
	{
		g_cam_st_addr =(unsigned int)*cam;
	}else if(option == GET_ADDRESS)
	{
		if(g_cam_st_addr)
		{
			*cam	= (cam_data *)g_cam_st_addr;
		}else
		{
			TRACE_ERR_AND_RET(FAIL);
		}
	}else if(option == MAKE_ADDRESS_INVALID)
	{
		g_cam_st_addr =0;
		kfree(*cam);
	}else
	{
		TRACE_ERR_AND_RET(FAIL);
	}
		
	return SUCCESS;
}
EXPORT_SYMBOL(v4l2_base_struct);

/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	:	
 *  Name	:	init_v4l2_base_struct	
 *  Parameter1	:	cam_data *cam	- Base address of camera structure pointer
 *  Parameter2	:	
 *  Returns	:	int		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative value be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *  Description	: 	
 *  Comments	:  	
 ************************************************************************************************************/
int init_v4l2_base_struct(cam_data *cam)
{

	static struct v4l2_file_operations omap_v4l_fops = 	\
	{
		.owner		= THIS_MODULE,
		.ioctl		= omap_v4l2_ioctl,
//		.poll		= ,
		.mmap		= omap_mmap,
		.open		= omap_v4l2_open,
		.release	= omap_v4l2_close,
		.read		= omap_v4l2_read,

	};

	static struct video_device omap_v4l_template =		\
	{
		.minor		= -1,
		.fops		= &omap_v4l_fops,
		.ioctl_ops	= NULL,

		.name		= "omap camera",
//		.type		= 0,
//		.type2		= VID_TYPE_CAPTURE,
		.release	= video_device_release,
	};

	if(cam == NULL)
	{
		TRACE_ERR_AND_RET(FAIL);
	}

	cam->video_dev		= video_device_alloc();
	if (cam->video_dev == NULL)
	{
		return ALLOCATION_MEMORY_FAILED;
	}

	*(cam->video_dev)	= omap_v4l_template;
	video_set_drvdata(cam->video_dev, cam);
	cam->video_dev->minor	= -1;


	return SUCCESS;
}
