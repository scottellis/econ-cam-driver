/**********************************************************************************************************
 *   Copyright (C) 2009 by e-con Systems                                                                  *
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
 * ----------------------------------------------------------------------------------------------------------
 *
 * 					Header files inclusion part
 *
 * ----------------------------------------------------------------------------------------------------------
 */

#include "inc_header.h"

/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	: 
 *  Name	:	omap_v4l2_capability
 *  Parameter1	:	cam_data *cam	- Base address of camera structure pointer
 *  Parameter2	:	struct v4l2_capability *cap
 *  Returns	:	FNRESLT		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative value be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *  Description	: 	
 *  Comments	:  	
 ************************************************************************************************************/
FNRESLT omap_v4l2_capability(cam_data *cam,struct v4l2_capability *cap)
{
	memcpy(cap,&cam->v4l2_cap,sizeof(struct v4l2_capability));
	return SUCCESS;
}

/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	: 
 *  Name	:	omap_v4l2_s_fmt
 *  Parameter1	:	cam_data *cam	- Base address of camera structure pointer
 *  Parameter2	:	struct v4l2_format *f
 *  Returns	:	FNRESLT		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative value be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *  Description	: 	
 *  Comments	:  	
 ************************************************************************************************************/
FNRESLT omap_v4l2_s_fmt(cam_data *cam, struct v4l2_format *f)
{
	FNRESLT ret_val;
	
	if(f->type		== V4L2_BUF_TYPE_VIDEO_CAPTURE)
	{
		if(cam->cam_sensor.fix_fmt_support)
		{
			memcpy(&cam->cam_sensor.fmt,f,sizeof(struct v4l2_format));
			ret_val	= cam->cam_sensor.fix_fmt_support(cam);
			if(CHECK_IN_FAIL_LIMIT(ret_val))
			{	
				TRACE_ERR_AND_RET(FAIL);
			}
		}
		memcpy(&cam->capture.v2f,&cam->cam_sensor.fmt,sizeof(struct v4l2_format));
		memcpy(f,&cam->cam_sensor.fmt,sizeof(struct v4l2_format));

	}else
	{
		printk(KERN_INFO "Searching for f->type %d\n",f->type);
		TRACE_ERR_AND_RET(FAIL);
	}

	return SUCCESS;
}

/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	: 
 *  Name	:	omap_v4l2_g_fmt
 *  Parameter1	:	cam_data *cam	- Base address of camera structure pointer
 *  Parameter2	:	struct v4l2_format *f
 *  Returns	:	FNRESLT		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative value be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *  Description	: 	
 *  Comments	:  	
 ************************************************************************************************************/

FNRESLT omap_v4l2_g_fmt(cam_data *cam, struct v4l2_format *f)
{
	if(f->type		== V4L2_BUF_TYPE_VIDEO_CAPTURE)
	{
		memcpy(f,&cam->capture.v2f,sizeof(struct v4l2_format));
	}else
	{
		return FAIL;
	}
	return SUCCESS;
}

/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	: 
 *  Name	:	omap_v4l2_ctrl
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

FNRESLT omap_v4l2_ctrl(cam_data *cam)
{
	FNRESLT ret_val;
  	typedef FNRESLT (*camera_register_dump) (cam_data *cam);
	camera_register_dump sensor_register_dump	= NULL;

	switch (cam->ctrl.id)
	{
		case V4L2_CID_BRIGHTNESS:
		case V4L2_CID_BLACK_LEVEL:
		{
			sensor_register_dump = cam->cam_sensor.brightness;
		}break;

		case V4L2_CID_CONTRAST:
		{
			sensor_register_dump = cam->cam_sensor.contrast;
		
		}break;

		case V4L2_CID_SATURATION:
		{
			sensor_register_dump = cam->cam_sensor.saturation;
		
		}break;

		case V4L2_CID_HUE:
		{
			sensor_register_dump = cam->cam_sensor.hue;
		
		}break;

		case V4L2_CID_AUTO_WHITE_BALANCE:
		case V4L2_CID_DO_WHITE_BALANCE:
		case V4L2_CID_WHITE_BALANCE_TEMPERATURE:
		{
			sensor_register_dump = cam->cam_sensor.whitebalance;
		
		}break;


		case V4L2_CID_RED_BALANCE:
		case V4L2_CID_BLUE_BALANCE:
		case V4L2_CID_GAMMA:
		{
			sensor_register_dump = cam->cam_sensor.colour_balance;
		
		}break;

		case V4L2_CID_EXPOSURE:
		{
			sensor_register_dump = cam->cam_sensor.exposure;

		}break;

		case V4L2_CID_AUTOGAIN:
		case V4L2_CID_GAIN:
		{
			sensor_register_dump = cam->cam_sensor.gain;

		}break;

		case V4L2_CID_HFLIP:
		{
			sensor_register_dump = cam->cam_sensor.h_mirror;

		}break;

		case V4L2_CID_VFLIP:
		{
			sensor_register_dump = cam->cam_sensor.v_flip;

		}break;

		case V4L2_CID_SHARPNESS:
		{
			sensor_register_dump = cam->cam_sensor.sharpness;

		}break;
		
		case V4L2_CID_FOCUS_ABSOLUTE:
		case V4L2_CID_FOCUS_RELATIVE:
		case V4L2_CID_FOCUS_AUTO:
		case V4L2_SENS_TRIG_FOCUS:
		case V4L2_SENS_FOCUS_DISABLE:
		case V4L2_SENS_FCS_OLAY:
		{
			sensor_register_dump = cam->cam_sensor.focus;
		}break;
/*
 * Sensor related private controls
 */
		case V4L2_SENS_ANTISHAKE:
		case V4L2_SENS_ANTISHAKE_STATUS:
		{
			sensor_register_dump = cam->cam_sensor.antishake;
		}break;
/*
 * Private control
 */
		case V4L2_SENS_FLASH_STROBE:
		{
			cam->cam_sensor.sens_strobe_en	= (cam->ctrl.value)?ENABLE:DISABLE;
			sensor_register_dump = cam->cam_sensor.sens_strobe;
		}break;

		case V4L2_SENS_EFFECTS:
		{
			sensor_register_dump = cam->cam_sensor.effects;
		}break;

/*
 * Flash private controls
 */
		case V4L2_SENS_FLASH_FLASH:
		{
			sensor_register_dump = cam->cam_flash.flash;
		}break;

		case V4L2_SENS_FLASH_TORCH:
		{
			sensor_register_dump = cam->cam_flash.torch;
			
		}break;

		case V4L2_SENS_FLASH_LUM:
		{
			sensor_register_dump = cam->cam_flash.lum_ctrl;
		}break;

		case V4L2_SENS_FLASH_FLASH_LUM:
		{
			sensor_register_dump = cam->cam_flash.flash_lum_ctrl;
		}break;

		case V4L2_SENS_FLASH_TORCH_LUM:
		{
			sensor_register_dump = cam->cam_flash.torch_lum_ctrl;
		}break;

		case V4L2_SENS_FLASH:
		{
			cam->cam_flash.enable	= DISABLE;
			sensor_register_dump	= cam->cam_flash.unit_enable;
			
		}break;
#if 0
		case V4L2_READ_MEM_MAP:
		{
			cam->ctrl.value	= cam->still.buf.phy_buf_addr;
		}break;

		case V4L2_READ_SKIP_USER_CPY:
		{
			if(cam->cam_sensor.get_data_frm_sensor	== ENABLE)
			{
				cam->ctrl.value	= cam->still.read_ctrl.bit.skip_copy_to_user;
			}else
			{
				if(cam->ctrl.value)
				{
					cam->still.read_ctrl.bit.skip_copy_to_user	= ENABLE;
				}else
				{
					cam->still.read_ctrl.bit.skip_copy_to_user	= DISABLE;
				}
			}
		}break;
#endif

	}

	if(sensor_register_dump)
	{
		ret_val	= sensor_register_dump(cam);
		if(CHECK_IN_FAIL_LIMIT(ret_val))
		{
			TRACE_ERR_AND_RET(FAIL);
		}
	
	}else
	{
		TRACE_ERR_AND_RET(-EINVAL);
	}
	
	return SUCCESS;
}
/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	: 
 *  Name	:	omap_v4l2_req_buf
 *  Parameter1	:	cam_data *cam	- Base address of camera structure pointer
 *  Parameter2	:	struct v4l2_requestbuffers *req
 *  Returns	:	FNRESLT		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative value be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *  Description	: 	
 *  Comments	:  	
 ************************************************************************************************************/
FNRESLT omap_v4l2_req_buf(cam_data *cam,struct v4l2_requestbuffers *req)
{
	UINT32 i;
	FNRESLT ret_val;

	if(cam->task.bit.capture	== ENABLE)
	{
/*
 * TODO:
 * 	return type here tobe EBUSY
 */
		TRACE_ERR_AND_RET(FAIL);
	}

	if (	(req->type != V4L2_BUF_TYPE_VIDEO_CAPTURE) || 				\
		(req->memory != V4L2_MEMORY_MMAP))
	{
/*
 * TODO:
 * 	return type here tobe EINVAL
 */

		TRACE_ERR_AND_RET(FAIL);
	}

	if(req->count >= (MAX_FRAME_SUPPORT-1))
	{
/*
 * MAX_FRAME_SUPPORT -1 is coded due to need of dummy buffer
 */
		req->count	= cam->capture.available_buf	= (MAX_FRAME_SUPPORT-1);
	}
/*
 * Free the allocated buffers
 */

	for(i = 0;i < MAX_FRAME_SUPPORT;i++)
	{
		if(cam->capture.frame[i].buffer.m.offset)
		{
			ret_val	= free_phy_mem(cam->capture.frame[i].buffer.m.offset);
			if(CHECK_IN_FAIL_LIMIT(ret_val))
			{
				TRACE_ERR_AND_RET(FAIL);
			}
			cam->capture.frame[i].buffer.m.offset		= DISABLE;
		}
	}
/*
 * request and allocate the buffer needed by the user
 * Ask for the dummy buffer and make empty copy when there is no queued buffer (skip the frame)
 */

	for(i = 0;i < (req->count+1);i++)
	{
		ret_val	= get_free_phy_mem(	cam->capture.v2f.fmt.pix.sizeimage,
						(UPINT32)&cam->capture.frame[i].buffer.m.offset,NULL);

		if(CHECK_IN_FAIL_LIMIT(ret_val))
		{
			break;
		}

		cam->capture.frame[i].buffer.index	= i;
		cam->capture.frame[i].buffer.flags	= V4L2_BUF_FLAG_MAPPED;
		cam->capture.frame[i].buffer.type	= V4L2_BUF_TYPE_VIDEO_CAPTURE;
		cam->capture.frame[i].buffer.length	= PAGE_ALIGN(cam->capture.v2f.fmt.pix.sizeimage);
		cam->capture.frame[i].buffer.memory	= V4L2_MEMORY_MMAP;
		cam->capture.frame[i].width		= cam->capture.v2f.fmt.pix.width;
		cam->capture.frame[i].height		= cam->capture.v2f.fmt.pix.height;
	}

	cam->capture.available_buf	=req->count	= i-1;
	return SUCCESS;
}
/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	: 
 *  Name	:	omap_v4l2_query_buf
 *  Parameter1	:	cam_data *cam	- Base address of camera structure pointer
 *  Parameter2	:	struct v4l2_buffer *buf
 *  Returns	:	FNRESLT		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative value be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *  Description	: 	
 *  Comments	:  	
 ************************************************************************************************************/
FNRESLT omap_v4l2_query_buf(cam_data *cam,struct v4l2_buffer *buf)
{

	if(buf->type != V4L2_BUF_TYPE_VIDEO_CAPTURE)
	{
		printk(KERN_ERR " pxa_cam VIDIOC_QUERYBUF buffer type not supported\n");
		TRACE_ERR_AND_RET(FAIL);
	}

	if (buf->index < 0 || buf->index >= cam->capture.available_buf)
	{
		printk(KERN_ERR "omap_v4l2_buffer_status buffers not allocated 	\
				buf index %d buffer available %d\n",buf->index,cam->capture.available_buf);
		TRACE_ERR_AND_RET(FAIL);
	}

	memcpy(buf, &(cam->capture.frame[buf->index].buffer), sizeof(struct v4l2_buffer));
	
	return SUCCESS;
}

/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	: 
 *  Name	:	omap_v4l2_queue_buf
 *  Parameter1	:	cam_data *cam	- Base address of camera structure pointer
 *  Parameter2	:	struct v4l2_buffer *buf
 *  Returns	:	FNRESLT		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative value be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *  Description	: 	
 *  Comments	:  	
 ************************************************************************************************************/
FNRESLT omap_v4l2_queue_buf(cam_data *cam,struct v4l2_buffer *buf)
{
	UINT32 index		= buf->index;

	if ((cam->capture.frame[index].buffer.flags & 0x7) == V4L2_BUF_FLAG_MAPPED)
	{
		cam->capture.frame[index].buffer.flags |= V4L2_BUF_FLAG_QUEUED;
	}else if(cam->capture.frame[index].buffer.flags & V4L2_BUF_FLAG_QUEUED)
	{
		printk(KERN_ERR "VIDIOC_QBUF: buffer already queued\n");
	}else if(cam->capture.frame[index].buffer.flags & V4L2_BUF_FLAG_DONE)
	{
		printk(KERN_ERR "VIDIOC_QBUF: buffer overwrite doned\n");
		cam->capture.frame[index].buffer.flags &= ~V4L2_BUF_FLAG_DONE;
		cam->capture.frame[index].buffer.flags |= V4L2_BUF_FLAG_QUEUED;
	}else
	{
		printk(KERN_ERR "VIDIOC_QBUF: buffer must be mapped before queued\n");
		return FAIL;
	}			
	buf->flags = cam->capture.frame[index].buffer.flags;

	return SUCCESS;
}

/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	: 
 *  Name	:	omap_v4l2_dqueue_buf
 *  Parameter1	:	cam_data *cam	- Base address of camera structure pointer
 *  Parameter2	:	struct v4l2_buffer *buf
 *  Returns	:	FNRESLT		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative value be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *  Description	: 	
 *  Comments	:  	
 ************************************************************************************************************/
FNRESLT omap_v4l2_dqueue_buf(cam_data *cam,struct v4l2_buffer *buf)
{
	UINT32 wait_event_ret_val;
	INT32 index		= -1;
	struct timeval timestamp;
	UINT32 i		= DISABLE;
	memset(&timestamp,DISABLE,sizeof(struct timeval));

/*
 * Clear the driver used flags
 */
	wait_event_ret_val	= wait_event_interruptible_timeout(	cam->capture.capture_frame_complete,		\
					     				(cam->capture.valid_buf	>= ENABLE),		\
									10 * HZ);
	if(wait_event_ret_val == DISABLE)
	{
		TRACE_ERR_AND_RET(-EBUSY);
	}

	for(i = 0;i < cam->capture.available_buf;i++)
	{
		if(	(cam->capture.frame[i].buffer.flags & 								\
			(V4L2_BUF_FLAG_DONE |V4L2_BUF_FLAG_MAPPED)) == 							\
			(V4L2_BUF_FLAG_DONE |V4L2_BUF_FLAG_MAPPED)	)
		{
			if((timestamp.tv_sec	== DISABLE) && 	(timestamp.tv_usec	== DISABLE))
			{
				memcpy(	&timestamp,									\
					&cam->capture.frame[i].buffer.timestamp,					\
					sizeof(struct timeval));
				index	=	i;
				continue;
			}

			if(	(timestamp.tv_sec > cam->capture.frame[i].buffer.timestamp.tv_sec)	||		\
				((timestamp.tv_sec == cam->capture.frame[i].buffer.timestamp.tv_sec)	&&		\
				(timestamp.tv_usec > cam->capture.frame[i].buffer.timestamp.tv_usec)))

			{
				memcpy(	&timestamp,									\
					&cam->capture.frame[i].buffer.timestamp,					\
					sizeof(struct timeval));
				index	=	i;
			}
		}
		
	}
#if defined(CONFIG_DRIVER_DEBUG)
	printk(KERN_DEBUG "Index dqed %d \n",index);
#endif
	if(index < DISABLE)
	{
		TRACE_ERR_AND_RET(FAIL);
	}
	cam->capture.frame[index].buffer.flags	       &= ~(V4L2_BUF_FLAG_DONE |V4L2_BUF_FLAG_QUEUED);

	buf->bytesused					= cam->capture.v2f.fmt.pix.sizeimage;
	buf->index					= index;
	buf->flags					= cam->capture.frame[index].buffer.flags;
	buf->m						= cam->capture.frame[index].buffer.m;
	buf->timestamp					= cam->capture.frame[index].buffer.timestamp;

	cam->capture.valid_buf--;
	return SUCCESS;
}

/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	: 
 *  Name	:	omap_v4l2_stream_on
 *  Parameter1	:	cam_data *cam	- Base address of camera structure pointer
 *  Parameter2	:	INT32 *type
 *  Returns	:	FNRESLT		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative value be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *  Description	: 	
 *  Comments	:  	
 ************************************************************************************************************/
FNRESLT omap_v4l2_stream_on(cam_data *cam,INT32 *type)
{
	FNRESLT ret_val;
	if(cam->task.bit.capture	== ENABLE)
	{
		TRACE_ERR_AND_RET(FAIL);
	}
/*
 * TODO:
 * 	Re-Init the camera configuration and restart the isp and ccdc
 */
	ret_val	= cam->cam_sensor.config_dim(cam);
	if(CHECK_IN_FAIL_LIMIT(ret_val))
	{
		TRACE_ERR_AND_RET(FAIL);
	}
/*
 * reset the isp 
 */

	ret_val	= isp_reset(cam);
	if(CHECK_IN_FAIL_LIMIT(ret_val))
	{
		TRACE_ERR_AND_RET(FAIL);
	}
	ret_val	= isp_configure(cam);
	if(CHECK_IN_FAIL_LIMIT(ret_val))
	{
		TRACE_ERR_AND_RET(FAIL);
	}
	ret_val	= program_dummy_isp_sdram_addr(cam);
	if(CHECK_IN_FAIL_LIMIT(ret_val))
	{
		TRACE_ERR_AND_RET(FAIL);
	}
	ret_val	= enable_ccdc(cam);
	if(CHECK_IN_FAIL_LIMIT(ret_val))
	{
		TRACE_ERR_AND_RET(FAIL);
	}
	ret_val	= enable_isp_irq0(cam);
	if(CHECK_IN_FAIL_LIMIT(ret_val))
	{
		TRACE_ERR_AND_RET(FAIL);
	}
	cam->task.bit.capture	= ENABLE;

	return SUCCESS;
}

/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	: 
 *  Name	:	omap_v4l2_stream_off
 *  Parameter1	:	cam_data *cam	- Base address of camera structure pointer
 *  Parameter2	:	INT32 *type
 *  Returns	:	FNRESLT		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative value be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *  Description	: 	
 *  Comments	:  	
 ************************************************************************************************************/
FNRESLT omap_v4l2_stream_off(cam_data *cam,INT32 *type)
{
	FNRESLT	ret_val;
	UINT32	i;

	ret_val	= disable_ccdc(cam);
	if(CHECK_IN_FAIL_LIMIT(ret_val))
	{
		TRACE_ERR_AND_RET(ret_val);
	}

	ret_val	= disable_isp_irq0(cam);
	if(CHECK_IN_FAIL_LIMIT(ret_val))
	{
		TRACE_ERR_AND_RET(ret_val);
	}
/*
 * Free the allocated buffers
 */

	for(i = 0;i < MAX_FRAME_SUPPORT;i++)
	{
		if(cam->capture.frame[i].buffer.m.offset)
		{
			ret_val	= free_phy_mem(cam->capture.frame[i].buffer.m.offset);
			if(CHECK_IN_FAIL_LIMIT(ret_val))
			{
				TRACE_ERR_AND_RET(ret_val);
			}
			cam->capture.frame[i].buffer.m.offset		= DISABLE;
		}
		memset(&cam->capture.frame[i],DISABLE,sizeof(struct __capture_dq_buf));
	}

	cam->task.bit.capture		= DISABLE;
	cam->capture.valid_buf		= DISABLE;
	cam->capture.available_buf	= DISABLE;

	return SUCCESS;
}

/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	: 
 *  Name	:	omap_v4l2_enum_fmt
 *  Parameter1	:	cam_data *cam	- Base address of camera structure pointer
 *  Parameter2	:	struct v4l2_fmtdesc *fmt
 *  Returns	:	FNRESLT		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative value be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *  Description	: 	
 *  Comments	:  	
 ************************************************************************************************************/
FNRESLT omap_v4l2_enum_fmt(cam_data *cam,struct v4l2_fmtdesc *fmt)
{
	if(cam->cam_sensor.totol_fmt_desc <= fmt->index)
	{
		TRACE_ERR_AND_RET(-EINVAL);
	}
	
	if(fmt->type	!= cam->cam_sensor.formats[fmt->index].type)
	{
		TRACE_ERR_AND_RET(FAIL);
	}

	memcpy(fmt,&cam->cam_sensor.formats[fmt->index],sizeof(struct v4l2_fmtdesc));
	return SUCCESS;
}
