/**********************************************************************************************************
 *   Copyright (C) 2009 by e-con Systems.                                                                 *
 *   www.e-consystems.com                                                                                 *
 *                                                                                                        *
 *   This file is licensed under the terms of the GNU General Public License                              *
 *   version 2. This program is licensed "as is" without any warranty of any                              *
 *   kind, whether express or implied.                                                                    *
 *                                                                                                        *
 *                                                                                                        *
 *   PROJECT	           :        OMAP Camera development                                               *
 *   MODULE NAME           :                                                                              *
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
#include "phy_mem.h"

/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	: 
 *  Name	:	omap_v4l2_open	
 *  Parameter1	:	struct file *file
 *  Returns	:	INT32	- On sucess returns 0
 *  				- On Failure a negative number be returned
 *  Description	: 	perform open operation of v4l2 
 *  Comments	:  	
 ************************************************************************************************************/
INT32 omap_v4l2_open(struct file *file)
{
	INT32 err = 0;
	struct video_device *dev = video_devdata(file);
	cam_data *cam;
	FNRESLT ret_val;

	ret_val	= v4l2_base_struct(&cam,GET_ADDRESS);
	if(CHECK_IN_FAIL_LIMIT(ret_val))
	{
		printk(KERN_ERR "Failed to get base node of camera device\n");
		TRACE_ERR_AND_RET(FAIL);		
	}
	
	if (cam	== NULL)
	{
		printk(KERN_ERR "Internal error, cam_data not found!\n");
		return -EBADF;
	}
	file->private_data = dev;

	strcpy(cam->v4l2_cap.driver, "omap_v4l2");
	cam->v4l2_cap.version		= KERNEL_VERSION(0, 1, 11);
	cam->v4l2_cap.capabilities 	=	V4L2_CAP_VIDEO_CAPTURE	|	\
						V4L2_CAP_READWRITE	|	\
						V4L2_CAP_STREAMING;

	cam->v4l2_cap.card[0]		= '\0';
	cam->v4l2_cap.bus_info[0]	= '\0';

	return err;
}

/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	: 
 *  Name	:	omap_v4l2_close
 *  Parameter1	:	struct file *file
 *  Returns	:	INT32	- On sucess returns 0
 *  				- On Failure a negative number be returned
 *  Description	: 	
 *  Comments	:  	
 ************************************************************************************************************/
INT32 omap_v4l2_close(struct file *file)
{
	INT32 err = 0;
	FNRESLT ret_val;

	cam_data *cam;

	ret_val	= v4l2_base_struct(&cam,GET_ADDRESS);
	if(CHECK_IN_FAIL_LIMIT(ret_val))
	{
		printk(KERN_ERR "Failed to get base node of camera device\n");
		TRACE_ERR_AND_RET(FAIL);		
	}

	if (cam	== NULL)
	{
		printk(KERN_ERR "Internal error, cam_data not found!\n");
		return -EBADF;
	}

	ret_val	= omap_v4l2_stream_off(cam,NULL);
	if(CHECK_IN_FAIL_LIMIT(ret_val))
	{
		TRACE_ERR_AND_RET(ret_val);
	}

	return err;
}

/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	: 
 *  Name	:	cam_get_pages
 *  Parameter1	:	UPINT32 vir_addr	- Virtual of available physical address available
 *  Parameter2	:	UINT32 size		- size of memory free and available
 *  Parameter3	:	UPINT32 phy_addr	- Physical address of memory available from the kernel
 *  Returns	:	FNRESLT		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative value be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *  Description	: 	get the free memory available from the kernel.  				
 *  Comments	:  	
 ************************************************************************************************************/
FNRESLT cam_get_pages(UPINT32 vir_addr,UINT32 size,UPINT32 phy_addr)
{
	ULINT32 adr;

	*vir_addr	= (UINT32)__get_free_pages(GFP_KERNEL |					\
						GFP_DMA,get_order(size));
	if(*vir_addr == DISABLE)
	{
		printk(KERN_INFO "Memory not sufficient ...\n");
		return FAIL;
	}

        adr = (ULINT32)*vir_addr;
        size = PAGE_SIZE << (get_order(size));
	for(;size > 0;)
	{
		SetPageReserved(virt_to_page(adr));
		adr += PAGE_SIZE;
		size -= PAGE_SIZE;
	}
	*phy_addr	= (UINT32)virt_to_phys((PINT0)*vir_addr);

	return SUCCESS;
}
/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	: 
 *  Name	:	cam_free_pages
 *  Parameter1	:	UINT32 addr		- Virtural address of allocated physical pages
 *  Parameter2	:	UINT32 bufsize		- buffer size
 *  Returns	:	FNRESLT		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative value be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *  Description	: 	Free the memory region allocated by cam_get_pages
 *  Comments	:  	
 ************************************************************************************************************/

FNRESLT cam_free_pages(UINT32 addr, UINT32 bufsize)
{
        UINT32 size, ad = addr;

        size = PAGE_SIZE << (get_order(bufsize));
        if (!addr)
	{
                TRACE_ERR_AND_RET(FAIL);
	}

        while (size > 0)
	{
                ClearPageReserved(virt_to_page(addr));
                addr += PAGE_SIZE;
                size -= PAGE_SIZE;
        }

        free_pages(ad, get_order(bufsize));
	return SUCCESS;
}

/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	: 
 *  Name	:	omap_v4l2_read
 *  Parameter1	:	struct file *file
 *  Parameter2	:	INT8 *buf
 *  Parameter3	:	size_t count
 *  Parameter4	:	loff_t * ppos
 *  Returns	:	INT32	- On sucess returns 0
 *  				- On Failure a negative number be returned	
 *  Description	: 	perform read operation of camera driver
 *  Comments	:  	
 ************************************************************************************************************/
INT32 omap_v4l2_read(struct file *file, INT8 *buf, size_t count, loff_t * ppos)
{
//	struct video_device *dev = video_devdata(file);
	FNRESLT ret_val;
	cam_data *cam = NULL;
	INT32 err;
	UINT32 wait_event_ret_val	= DISABLE;


	ret_val	= v4l2_base_struct(&cam,GET_ADDRESS);
	if(CHECK_IN_FAIL_LIMIT(ret_val))
	{
		printk(KERN_ERR "Failed to register the camera device\n");
		TRACE_ERR_AND_RET(FAIL);		
	}

	if(cam->task.bit.capture	== ENABLE)
	{
		TRACE_ERR_AND_RET(-EBUSY);	
	}

	cam->task.bit.still	= ENABLE;

/*
 * configure the sensor
 */
	if(cam->cam_sensor.config_dim)
	{
		ret_val	= cam->cam_sensor.config_dim(cam);
		if(CHECK_IN_FAIL_LIMIT(ret_val))
		{
			goto exit;
		}
	}else
	{
		goto exit;
	}
/*
 * reset the isp 
 */

	ret_val	= isp_reset(cam);
	if(CHECK_IN_FAIL_LIMIT(ret_val))
	{
		goto exit;
	}

	ret_val	= isp_configure(cam);
	if(CHECK_IN_FAIL_LIMIT(ret_val))
	{
		goto exit;
	}

/*
 * Get the memory from the kernel
 */

	if (get_free_phy_mem(cam->capture.v2f.fmt.pix.sizeimage,
				&cam->still.phy_addr, &cam->still.vir_addr))
		goto exit;


	ret_val	= isp_prg_sdram_addr(cam);
	if(CHECK_IN_FAIL_LIMIT(ret_val))
	{
		goto exit;
	}

	cam->still.frame_count	= DISABLE;
	cam->still.wait_queue_head_t_dma_frame_complete_still	= DISABLE;

/*
 * Enable sensor strobe
 */
	if(cam->cam_sensor.sens_strobe)
	{
		cam->ctrl.id	= V4L2_SENS_FLASH_STROBE;
		cam->ctrl.value	= ENABLE;
		ret_val	= cam->cam_sensor.sens_strobe(cam);
		if(CHECK_IN_FAIL_LIMIT(ret_val))
		{
			goto exit;
		}

	}


	ret_val	= enable_ccdc(cam);
	if(CHECK_IN_FAIL_LIMIT(ret_val))
	{
		goto exit;
	}

	ret_val	= enable_isp_irq0(cam);
	if(CHECK_IN_FAIL_LIMIT(ret_val))
	{
		goto exit;
	}
/*
 * Wait for interrupt from the isp interrupt service routine
 */
	if(cam->still.wait_queue_head_t_dma_frame_complete_still	== DISABLE)
	{
		wait_event_ret_val	= wait_event_interruptible_timeout(cam->still.dma_frame_complete_still,		\
					      cam->still.frame_count >= STILL_IMAGE_CAPTURE_FRAME_NUMBER,		\
						10 * HZ);
	}
	
/*
 * Disable sensor strobe
 */
	if(cam->cam_sensor.sens_strobe)
	{
		cam->ctrl.id	= V4L2_SENS_FLASH_STROBE;
		cam->ctrl.value	= DISABLE;
		ret_val	= cam->cam_sensor.sens_strobe(cam);
		if(CHECK_IN_FAIL_LIMIT(ret_val))
		{
			goto exit;
		}

	}

	ret_val	= disable_ccdc(cam);
	if(CHECK_IN_FAIL_LIMIT(ret_val))
	{
		goto exit;
	}

	ret_val	= disable_isp_irq0(cam);
	if(CHECK_IN_FAIL_LIMIT(ret_val))
	{
		goto exit;
	}

	if(wait_event_ret_val == DISABLE)
	{
		printk(KERN_DEBUG "wait_event_interruptible_timeout %s %d \n",__FUNCTION__,__LINE__);	
		printk(KERN_ERR "omap_v4l_read timeout - Frame count %d\n",cam->still.frame_count);

		cam->task.bit.still = DISABLE;
	
		if (free_phy_mem(cam->still.phy_addr))
			goto exit;

		return -ETIME;
	}
	err = copy_to_user(buf,(UPINT8)cam->still.vir_addr, cam->capture.v2f.fmt.pix.sizeimage);

	if (free_phy_mem(cam->still.phy_addr))
		goto exit;

	cam->task.bit.still	= DISABLE;

	return (cam->capture.v2f.fmt.pix.sizeimage);

	exit:
	{
		cam->task.bit.still	= DISABLE;
		return 0;
	}
}

/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	: 
 *  Name	:	omap_mmap
 *  Parameter1	:	struct file *file
 *  Parameter2	:	struct vm_area_struct *vma
 *  Returns	:	INT32	- On sucess returns 0
 *  				- On Failure a negative number be returned	
 *  Description	: 	perform mmap operation 
 *  Comments	:  	
 ************************************************************************************************************/
INT32 omap_mmap(struct file *file, struct vm_area_struct *vma)
{
	#define VGA_IMAGE_SIZE	(640 *480 *2)

	ULINT32 size;
	INT32 res = DISABLE;

	pr_debug("pgoff=0x%lx, start=0x%lx, end=0x%lx\n",vma->vm_pgoff, vma->vm_start, vma->vm_end);

	size = vma->vm_end - vma->vm_start;

	vma->vm_page_prot = pgprot_writecombine(vma->vm_page_prot);

	if(size	 >= VGA_IMAGE_SIZE)
	{
		vma->vm_page_prot = PAGE_SHARED;
	}else
	{
		vma->vm_page_prot = pgprot_noncached(vma->vm_page_prot);
	}

	if (remap_pfn_range(vma, vma->vm_start,vma->vm_pgoff, size, vma->vm_page_prot))
	{
		printk(KERN_ERR "omap_mmap: remap_pfn_range failed\n");
		res = -ENOBUFS;
		goto omap_mmap_exit;
	}

	vma->vm_flags |= VM_RESERVED;
	omap_mmap_exit:
	{
		return res;
	}
}

/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	: 
 *  Name	:	omap_v4l2_do_ioctl
 *  Parameter1	:	struct file *file
 *  Parameter2	:	UINT32 ioctlnr
 *  Parameter3	:	PINT0 arg
 *  Returns	:	LINT32	- On sucess returns 0
 *  				- On Failure a negative number be returned
 *  Description	: 	process ioctl commands here
 *  Comments	:  	
 ************************************************************************************************************/
LINT32 omap_v4l2_do_ioctl(struct file *file,UINT32 ioctlnr,PINT0 arg)
{
	FNRESLT ret_val;
	cam_data *cam = NULL;

	ret_val	= v4l2_base_struct(&cam,GET_ADDRESS);
	if(CHECK_IN_FAIL_LIMIT(ret_val))
	{
		printk(KERN_ERR "Failed to register the camera device\n");
		TRACE_ERR_AND_RET(FAIL);		
	}

//	printk(KERN_ERR MODULE_NAME ": IOCTL Number is :%d\n",_IOC_NR(ioctlnr));

	switch (ioctlnr)
	{
		case VIDIOC_QUERYCAP:
		{
			struct v4l2_capability *cap = arg;
			ret_val = omap_v4l2_capability(cam,cap);
			if(CHECK_IN_FAIL_LIMIT(ret_val))
			{
				TRACE_ERR_AND_RET(FAIL);
			}	
	
		}break;

		case VIDIOC_S_FMT:
		{
			struct v4l2_format *sf = arg;
			ret_val = omap_v4l2_s_fmt(cam, sf);
			if(CHECK_IN_FAIL_LIMIT(ret_val))
			{
				TRACE_ERR_AND_RET(FAIL);
			}	
		}break;

		case VIDIOC_G_FMT:
		{
			struct v4l2_format *gf = arg;
			ret_val = omap_v4l2_g_fmt(cam, gf);
			if(CHECK_IN_FAIL_LIMIT(ret_val))
			{
				TRACE_ERR_AND_RET(FAIL);
			}	
		}break;

		case VIDIOC_G_CTRL:
		{
			cam->cam_sensor.cmd_to_sensor	= GET_DATA_FRM_SENSOR;
			memcpy(&cam->ctrl,arg,sizeof(struct v4l2_control));

			ret_val	= omap_v4l2_ctrl(cam);
			if(CHECK_IN_FAIL_LIMIT(ret_val))
			{
				TRACE_ERR_AND_RET(FAIL);
			}
			memcpy(arg,&cam->ctrl,sizeof(struct v4l2_control));

		}break;

		case VIDIOC_S_CTRL:
		{
			cam->cam_sensor.cmd_to_sensor	= SET_DATA_TO_SENSOR;
			memcpy(&cam->ctrl,arg,sizeof(struct v4l2_control));

			ret_val	= omap_v4l2_ctrl(cam);
			if(CHECK_IN_FAIL_LIMIT(ret_val))
			{
				TRACE_ERR_AND_RET(FAIL);
			}
		}break;

		case VIDIOC_QUERYCTRL:
		{
			struct v4l2_queryctrl *qctrl	= arg;
			memset(&cam->cam_sensor.qctrl,0x00,sizeof(struct v4l2_queryctrl));
			cam->cam_sensor.cmd_to_sensor	= QUERY_DATA_FRM_SENSOR;

			cam->ctrl.id	= qctrl->id;
			
			ret_val	= omap_v4l2_ctrl(cam);
			if(CHECK_IN_FAIL_LIMIT(ret_val))
			{
				cam->cam_sensor.qctrl.flags	= V4L2_CTRL_FLAG_DISABLED;
				memcpy(qctrl,&cam->cam_sensor.qctrl,sizeof(struct v4l2_queryctrl));
				TRACE_ERR_AND_RET(-EINVAL);
			}
			memcpy(qctrl,&cam->cam_sensor.qctrl,sizeof(struct v4l2_queryctrl));
			
		}break;
//--------------------------------------------------------------------------------------------------
		case VIDIOC_REQBUFS:
		{
			ret_val	= omap_v4l2_req_buf(cam, arg);
			if(CHECK_IN_FAIL_LIMIT(ret_val))
			{
				TRACE_ERR_AND_RET(ret_val);
			}
		}break;

		case VIDIOC_QUERYBUF:
		{
			ret_val	= omap_v4l2_query_buf(cam, arg);
			if(CHECK_IN_FAIL_LIMIT(ret_val))
			{
				TRACE_ERR_AND_RET(ret_val);
			}
		}break;

		case VIDIOC_QBUF:
		{
			ret_val	= omap_v4l2_queue_buf(cam, arg);
			if(CHECK_IN_FAIL_LIMIT(ret_val))
			{
				TRACE_ERR_AND_RET(ret_val);
			}
		}break;

		case VIDIOC_DQBUF:
		{
			ret_val	= omap_v4l2_dqueue_buf(cam, arg);
			if(CHECK_IN_FAIL_LIMIT(ret_val))
			{
				TRACE_ERR_AND_RET(ret_val);
			}
		}break;

		case VIDIOC_STREAMON:
		{
			ret_val	= omap_v4l2_stream_on(cam, arg);
			if(CHECK_IN_FAIL_LIMIT(ret_val))
			{
				TRACE_ERR_AND_RET(ret_val);
			}
		}break;

		case VIDIOC_STREAMOFF:
		{
			ret_val	= omap_v4l2_stream_off(cam, arg);
			if(CHECK_IN_FAIL_LIMIT(ret_val))
			{
				TRACE_ERR_AND_RET(ret_val);
			}
		}break;

		case VIDIOC_ENUMINPUT:
		{
			struct v4l2_input *vinp_arg	= arg;
			if(vinp_arg->index	== 0)
			{
				strlcpy(cam->vinp.name, "camera", sizeof(cam->vinp.name));
				cam->vinp.type = V4L2_INPUT_TYPE_CAMERA;
				
				strlcpy(vinp_arg->name, "camera", sizeof(vinp_arg->name));
				vinp_arg->type = V4L2_INPUT_TYPE_CAMERA;

			}else
			{
				TRACE_ERR_AND_RET(-EINVAL);
			}
		}break;
		case VIDIOC_G_INPUT:
		{
			int *index	= arg;
			*index	= 0;
		}break;

		case VIDIOC_ENUM_FMT:
		{
			ret_val	= omap_v4l2_enum_fmt(cam,arg);
			if(CHECK_IN_FAIL_LIMIT(ret_val))
			{
				TRACE_ERR_AND_RET(ret_val);
			}
		}break;

		case VIDIOC_ENUMSTD:
		{
			TRACE_ERR_AND_RET(-EINVAL);
		}break;

		case VIDIOC_S_INPUT:
		{
			printk(KERN_DEBUG "FUNCTION %s FILE %s LINE %d\n",__func__,__FILE__,__LINE__);
		}break;

		case VIDIOC_G_STD:
		{
			v4l2_std_id *std	=  arg;
			*std	= V4L2_STD_PAL;
		}break;

		case VIDIOC_TRY_FMT:
		{
			struct v4l2_format *cam_try_fmt = arg;
			memcpy(&cam->cam_sensor.qfmt,cam_try_fmt,sizeof(struct v4l2_format));
			if(cam->cam_sensor.qfmt_support)
			{
				ret_val	= cam->cam_sensor.qfmt_support(cam);
				if(CHECK_IN_FAIL_LIMIT(ret_val))
				{
					TRACE_ERR_AND_RET(ret_val);
				}
			}else
			{
				TRACE_ERR_AND_RET(FAIL);
			}
		}break;

		case VIDIOC_G_PARM:
		{
			struct v4l2_streamparm *s_parm	= arg;

#if defined(CONFIG_CTRL_FRAME_RATE_FRM_SENSOR)
			memcpy(&cam->cam_sensor.s_parm,s_parm,sizeof(struct v4l2_streamparm));
			cam->cam_sensor.cmd_to_sensor	= GET_DATA_FRM_SENSOR;

			if(cam->cam_sensor.frame_rate_ctrl)
			{
				ret_val	= cam->cam_sensor.frame_rate_ctrl(cam);
				if(CHECK_IN_FAIL_LIMIT(ret_val))
				{
					TRACE_ERR_AND_RET(ret_val);
				}

			}
#else
			if(s_parm->type	== V4L2_BUF_TYPE_VIDEO_CAPTURE)
			{
				/* do nothing */
			}
#endif
			else
			{
				TRACE_ERR_AND_RET(-EINVAL);
			}
#if defined (CONFIG_CTRL_FRAME_RATE_FRM_SENSOR)
			memcpy(s_parm,&cam->cam_sensor.s_parm,sizeof(struct v4l2_streamparm));
#else
			memcpy(s_parm,&cam->capture.s_parm,sizeof(struct v4l2_streamparm));
#endif
		}break;

		case VIDIOC_S_PARM:
		{
			struct v4l2_streamparm *s_parm	= arg;

#if defined(CONFIG_CTRL_FRAME_RATE_FRM_SENSOR)
			memcpy(&cam->cam_sensor.s_parm,s_parm,sizeof(struct v4l2_streamparm));
			cam->cam_sensor.cmd_to_sensor	= SET_DATA_TO_SENSOR;

			if(cam->cam_sensor.frame_rate_ctrl)
			{
				ret_val	= cam->cam_sensor.frame_rate_ctrl(cam);
				if(CHECK_IN_FAIL_LIMIT(ret_val))
				{
					TRACE_ERR_AND_RET(ret_val);
				}
			}
#else
			memcpy(&cam->capture.s_parm,s_parm,sizeof(struct v4l2_streamparm));
			if(cam->capture.s_parm.type	!= V4L2_BUF_TYPE_VIDEO_CAPTURE)
			{
				TRACE_ERR_AND_RET(-EINVAL);
			}

			memcpy(&cam->cam_sensor.s_parm,s_parm,sizeof(struct v4l2_streamparm));
			cam->cam_sensor.cmd_to_sensor	= GET_DATA_FRM_SENSOR;

			if(cam->cam_sensor.frame_rate_ctrl)
			{
				ret_val	= cam->cam_sensor.frame_rate_ctrl(cam);
				if(CHECK_IN_FAIL_LIMIT(ret_val))
				{
					TRACE_ERR_AND_RET(ret_val);
				}
			}

			if (cam->cam_sensor.s_parm.parm.capture.timeperframe.denominator	>= 	\
				cam->capture.s_parm.parm.capture.timeperframe.denominator)
			{
				/* do nothing */
			}			

#endif			
			else
			{
				TRACE_ERR_AND_RET(FAIL);
			}

		}break;

		case VIDIOC_ENUM_FRAMESIZES:
		{
			cam->cam_sensor.cmd_to_sensor	= GET_DATA_FRM_SENSOR;
			cam->cam_sensor.fmt_frm_user	= arg;

			if(cam->cam_sensor.supported_formats)
			{
				ret_val	= cam->cam_sensor.supported_formats(cam);
				if(CHECK_IN_FAIL_LIMIT(ret_val))
				{
					TRACE_ERR_AND_RET(ret_val);
				}
			}else
			{
				TRACE_ERR_AND_RET(-EINVAL);
			}
		}break;

		case VIDIOC_ENUM_FRAMEINTERVALS:
		{
			cam->cam_sensor.cmd_to_sensor		= GET_DATA_FRM_SENSOR;
			cam->cam_sensor.frame_interval_frm_user	= arg;

			if(cam->cam_sensor.frame_interval)
			{
				ret_val	= cam->cam_sensor.frame_interval(cam);
				if(CHECK_IN_FAIL_LIMIT(ret_val))
				{
					TRACE_ERR_AND_RET(ret_val);
				}

			}else
			{
				TRACE_ERR_AND_RET(-EINVAL);
			}
		}break;
#if 0

		case VIDIOC_CROPCAP:
		{
///			struct v4l2_cropcap *crp_cap;
			printk("FUNCTION %s FILE %s LINE %d\n",__func__,__FILE__,__LINE__);
		}break;

		case VIDIOC_S_CROP:
		{
			printk("FUNCTION %s FILE %s LINE %d\n",__func__,__FILE__,__LINE__);

		}break;

		case VIDIOC_G_CROP:
		{
			printk("FUNCTION %s FILE %s LINE %d\n",__func__,__FILE__,__LINE__);

		}break;

		case VIDIOC_S_STD:
		{
			printk("FUNCTION %s FILE %s LINE %d\n",__func__,__FILE__,__LINE__);
			break;
		}

#endif		
//--------------------------------------------------------------------------------------------------
		default:
		{
			printk(KERN_ERR MODULE_NAME ":" "Ioctl currently not implemented IOCTL Number is :%d\n"	\
							,_IOC_NR(ioctlnr));
			TRACE_ERR_AND_RET(-EINVAL);
		}
	}
	return SUCCESS;

}
/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	: 
 *  Name	:	omap_v4l2_ioctl
 *  Parameter1	:	struct file *file
 *  Parameter2	:	UINT32 cmd
 *  Parameter3	:	ULINT32 arg
 *
 *  Returns	:	LINT32	- On sucess returns 0
 *  				- On Failure a negative number be returned
 *  Description	: 	
 *  Comments	:  	
 ************************************************************************************************************/
LINT32 omap_v4l2_ioctl( struct file *file,UINT32 cmd,ULINT32 arg)
{
	return video_usercopy(file, cmd, arg,omap_v4l2_do_ioctl);
}
