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

static UINT32 cam_mclk	= 24000000;
module_param(cam_mclk,int, 0444);

/************************************************************************************************************
 *  
 *  MODULE TYPE	:	ISR ROUTINE				MODULE ID	:	OMAP_V4L2_BASE	
 *  Name	:	omap34xx_isp_isr	
 *  Parameter1	:	INT32 irq
 *  Parameter2	:	PINT0 _cam	- private data number
 *  Returns	:	irq - handled information
 *  Description	: 	interrupt service routine 
 *  Comments	:  	
 ************************************************************************************************************/

irqreturn_t omap34xx_isp_isr(INT32 irq,PINT0 _cam)
{
	cam_data *cam	= _cam;
	FNRESLT ret_val;

	if(cam->isp->isp_main.reg.isp_irq0status.bit.ccdc_vd0_irq			== ENABLED)
	{
		if(cam->task.bit.still	== ENABLE)
		{
			cam->still.frame_count++;
			if(cam->still.frame_count >= STILL_IMAGE_CAPTURE_FRAME_NUMBER)
			{
				wake_up_interruptible(&cam->still.dma_frame_complete_still);
				cam->still.wait_queue_head_t_dma_frame_complete_still	= ENABLE;
			}
		}else if(cam->task.bit.capture	== ENABLE)
		{
/*
 * Trigger the wake up event
 */
			ret_val	= isp_prg_sdram_addr(cam);
			if(CHECK_IN_FAIL_LIMIT(ret_val))
			{
				
			}
		}
	}

	if(cam->isp->isp_main.reg.isp_irq0status.bit.ccdc_vd1_irq			== ENABLED)
	{	
	}

	if(cam->isp->isp_main.reg.isp_irq0status.bit.ccdc_vd2_irq			== ENABLED)
	{
	}

	if(cam->isp->isp_main.reg.isp_irq0status.bit.ccdc_err_irq			== ENABLED)
	{
	}
	
	if(cam->isp->isp_main.reg.isp_irq0status.bit.h3a_af_done_irq			== ENABLED)
	{
	}
	
	if(cam->isp->isp_main.reg.isp_irq0status.bit.h3a_awb_done_irq			== ENABLED)
	{
	}

	if(cam->isp->isp_main.reg.isp_irq0status.bit.hist_done_irq			== ENABLED)
	{
	}

	if(cam->isp->isp_main.reg.isp_irq0status.bit.ccdc_lsc_done			== ENABLED)
	{
	}

	if(cam->isp->isp_main.reg.isp_irq0status.bit.ccdc_lsc_prefectch_completed	== ENABLED)
	{
	}

	if(cam->isp->isp_main.reg.isp_irq0status.bit.ccdc_lsc_prefectch_error		== ENABLED)
	{
	}

	if(cam->isp->isp_main.reg.isp_irq0status.bit.prv_done_irq			== ENABLED)
	{
	}

	if(cam->isp->isp_main.reg.isp_irq0status.bit.cbuff_irq				== ENABLED)
	{
	}

	if(cam->isp->isp_main.reg.isp_irq0status.bit.rsz_done_irq			== ENABLED)
	{
	}

	if(cam->isp->isp_main.reg.isp_irq0status.bit.ovf_irq				== ENABLED)
	{
	}

	if(cam->isp->isp_main.reg.isp_irq0status.bit.mmu_err_irq			== ENABLED)
	{
	}
	
	if(cam->isp->isp_main.reg.isp_irq0status.bit.ocp_err_irq			== ENABLED)
	{
	}

	if(cam->isp->isp_main.reg.isp_irq0status.bit.sec_err_irq			== ENABLED)
	{
	}

	if(cam->isp->isp_main.reg.isp_irq0status.bit.hs_vs_irq				== ENABLED)
	{
	}

	cam->isp->isp_main.reg.isp_irq0status.ISP_IRQ0STATUS	= cam->isp->isp_main.reg.isp_irq0status.ISP_IRQ0STATUS;
	cam->isp->isp_main.reg.isp_irq1status.ISP_IRQ1STATUS	= cam->isp->isp_main.reg.isp_irq1status.ISP_IRQ1STATUS;

	return IRQ_HANDLED;
}


/*
 *  Parameter1	: cam_data *cam	- Base address of camera structure pointer
 *  Parameter2	: xclk		- Needed mclk given to sensor
 *  Parameter3	: xclksel	- Needed xclk mode in the omap
 *  
 *  Description	: 	Sets the mclk provided to the sensor
 */
#define CM_CAM_MCLK_HZ			216000000
#define ISPTCTRL_CTRL_DIV_BYPASS	0x1F
static int isp_set_xclk(cam_data *cam, u32 xclk, u8 xclksel, u32 *current_xclk)
{
	u32 divisor;
	u32 currentxclk;

	if (xclk >= CM_CAM_MCLK_HZ) {
		divisor = ISPTCTRL_CTRL_DIV_BYPASS;
		currentxclk = CM_CAM_MCLK_HZ;
	}
	else if (xclk >= 2) {
		divisor = CM_CAM_MCLK_HZ / xclk;

		if (divisor >= ISPTCTRL_CTRL_DIV_BYPASS)
			divisor = ISPTCTRL_CTRL_DIV_BYPASS - 1;

		currentxclk = CM_CAM_MCLK_HZ / divisor;
	}
	else {
		divisor = xclk;
		currentxclk = 0;
	}

	switch (xclksel) {
	case 0:
		cam->isp->isp_main.reg.tctrl_ctrl.bit.diva	= divisor;
		break;

	case 1:
		cam->isp->isp_main.reg.tctrl_ctrl.bit.divb	= divisor;
		break;

	default:
		return -1;
	}

	if (current_xclk)
		*current_xclk = currentxclk;

	return 0;
}

/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	:	OMAP_V4L2_BASE	
 *  Name	:	mclk_to_sensor
 *  Parameter1	:	cam_data *cam	- Base address of camera structure pointer
 *  Parameter2	:	option		- command to perform 
 *  
 *  Returns	:	FNRESLT		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative value be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *
 *  Description	: 	Function callback exposed to other layers.
 *  Comments	:  	
 ************************************************************************************************************/

FNRESLT mclk_to_sensor(cam_data *cam, UINT32 xclk, UPINT32 clk_set)
{
	return isp_set_xclk(cam, xclk, 0, clk_set);
}

/*
 * Maintain the base pointer of pin configuration.
 */
static int omap_isp_base_struct(cam_data *cam, u8 option)
{
	static UINT32 g_cam_isp;

	if (!cam)
		return -EINVAL;

	switch (option) {
	case SET_ADDRESS:
		g_cam_isp = (UINT32)cam->pin;			
		break;
	
	case GET_ADDRESS:
		cam->isp = (isp_reg_bit_access*) g_cam_isp;
		break;

	case MAKE_ADDRESS_INVALID:
		if (!cam->isp)
			return -EINVAL;

		iounmap(cam->isp);
		cam->isp = NULL;
		g_cam_isp = 0;
		break;
	
	case CREATE_ADDRESS:
		cam->isp = ioremap(BADDR_ISP, MAP_ISP_REGION);

		if (!cam->isp) {
			printk(KERN_ERR "Unable to remap the isp registers\n");
			return -ENOMEM;
		}

		break;

	default:
		return -EINVAL;
	}

	return 0;
}

/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	:	OMAP_V4L2_BASE	
 *  Name	:	
 *  Parameter1	:	cam_data *cam	- Base address of camera structure pointer
 *  Returns	:	FNRESLT		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative value be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *
 *  Description	: 	reset the isp and ccdc interface
 *  Comments	:  	
 ************************************************************************************************************/
FNRESLT isp_reset(cam_data *cam)
{
	UINT32 time_out	= 10;
	if(cam == NULL)
	{
		TRACE_ERR_AND_RET(FAIL);
	}
	
/*
 * Clear all the status register and irq registers
 */
	cam->isp->isp_main.reg.isp_irq0enable.ISP_IRQ0ENABLE	= DISABLE;
	cam->isp->isp_main.reg.isp_irq0status.ISP_IRQ0STATUS	= cam->isp->isp_main.reg.isp_irq0status.ISP_IRQ0STATUS;

	cam->isp->isp_main.reg.isp_irq1enable.ISP_IRQ1ENABLE	= DISABLE;
	cam->isp->isp_main.reg.isp_irq1status.ISP_IRQ1STATUS	= cam->isp->isp_main.reg.isp_irq1status.ISP_IRQ1STATUS;

/*
 * Enable the soft reset
 */
	cam->isp->isp_main.reg.isp_sysconfig.bit.soft_reset	= ENABLE;

/*
 * Check the reset is done 
 */
	for(;time_out--;)
	{
		if(cam->isp->isp_main.reg.isp_sysstatus.bit.reset_done	== ENABLE)
		{
			break;
		}
		mdelay(100);
	}

	cam->isp->isp_main.reg.isp_sysconfig.bit.midle_mode	= ENABLE;
	cam->isp->isp_main.reg.isp_sysconfig.bit.auto_idle	= DISABLE;
	return SUCCESS;
}
/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	:	OMAP_V4L2_BASE	
 *  Name	:	program_dummy_isp_sdram_addr
 *  Parameter1	:	cam_data *cam	- Base address of camera structure pointer
 *  Returns	:	FNRESLT		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative value be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *
 *  Description	:
 *  Comments	:
 ************************************************************************************************************/

FNRESLT program_dummy_isp_sdram_addr(cam_data *cam)
{
	if(cam->capture.available_buf	<= DISABLE)
	{
		TRACE_ERR_AND_RET(FAIL);
	}

	cam->isp->isp_ccdc.reg.CCDC_SDR_ADDR	= cam->capture.frame[cam->capture.available_buf].buffer.m.offset;
	return SUCCESS;
}
/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	:	OMAP_V4L2_BASE	
 *  Name	:	
 *  Parameter1	:	cam_data *cam	- Base address of camera structure pointer
 *  Returns	:	FNRESLT		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative value be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *
 *  Description	: 	program the ccdc sdram address.
 *  Comments	:  	In the programed sdram address the new frame from the sensor be filled.
 ************************************************************************************************************/
FNRESLT isp_prg_sdram_addr(cam_data *cam)
{
	INT32	i;
	UINT32	load_address_base_index	= DISABLE;
	static struct timeval timestamp;
	UINT32	dummy_count	= DISABLE;
	UINT32	valid_buf	= DISABLE;
	struct tm timecode;

#ifndef CONFIG_CTRL_FRAME_RATE_FRM_SENSOR
	static UINT32 frame_skip_count;
	static UINT32 capture_frame_rate;
	static UINT32 current_fps	= SENS_MAX_FPS;
	static struct timeval timestamp_rec;
#endif

	if(cam == NULL)
	{
		TRACE_ERR_AND_RET(FAIL);
	}
/*
 * Take the current time stamp
 */
	do_gettimeofday(&timestamp);

#ifndef CONFIG_CTRL_FRAME_RATE_FRM_SENSOR
	if(timestamp_rec.tv_sec	== DISABLE && timestamp_rec.tv_usec == DISABLE)
	{
		do_gettimeofday(&timestamp_rec);
	}

	if (timestamp.tv_sec > timestamp_rec.tv_sec)
	{
		current_fps		= capture_frame_rate;
		capture_frame_rate	= DISABLE;
		timestamp_rec		= timestamp;
	}
	capture_frame_rate++;
#endif

	if(cam->task.bit.still	== ENABLE)
	{
		cam->isp->isp_ccdc.reg.CCDC_SDR_ADDR	= cam->still.phy_addr;
	}else if(cam->task.bit.capture == ENABLE)
	{

		for(valid_buf = DISABLE,i = DISABLE;i< cam->capture.available_buf;i++)
		{
			if((cam->capture.frame[i].buffer.flags & 			\
			(V4L2_BUF_FLAG_QUEUED |V4L2_BUF_FLAG_MAPPED)) == 		\
			(V4L2_BUF_FLAG_QUEUED |V4L2_BUF_FLAG_MAPPED))
			{
				if(	(cam->capture.frame[i].buffer.timestamp.tv_sec < timestamp.tv_sec) ||	\
					((cam->capture.frame[i].buffer.timestamp.tv_sec == timestamp.tv_sec) &&	\
					(cam->capture.frame[i].buffer.timestamp.tv_usec <= timestamp.tv_usec)))
				{
					memcpy(&timestamp,&cam->capture.frame[i].buffer.timestamp,sizeof(struct timeval));
					load_address_base_index	= i;
				}

				if((cam->capture.frame[i].buffer.flags & V4L2_BUF_FLAG_DONE) == V4L2_BUF_FLAG_DONE)
				{
					valid_buf++;
					wake_up_interruptible(&cam->capture.capture_frame_complete);

				}

			}else
			{
				dummy_count++;
			}
		}

#ifndef CONFIG_CTRL_FRAME_RATE_FRM_SENSOR
		frame_skip_count	+= ((1000000*cam->capture.s_parm.parm.capture.			\
					timeperframe.denominator)/current_fps);
		if(frame_skip_count > 1000000)
		{
			frame_skip_count -=1000000;
		}else
		{
			dummy_count	= cam->capture.available_buf;
		}
#endif

		if(dummy_count	== cam->capture.available_buf)
		{
			cam->isp->isp_ccdc.reg.CCDC_SDR_ADDR	= cam->capture.frame[cam->capture.available_buf].	\
								  buffer.m.offset;
			cam->capture.using_buf	= cam->capture.available_buf;
		}else
		{
			cam->capture.buffer_sequence++;
/*
 * Fill the New time stamp
 */
			do_gettimeofday(&cam->capture.frame[load_address_base_index].buffer.timestamp);

			cam->isp->isp_ccdc.reg.CCDC_SDR_ADDR	= cam->capture.frame[load_address_base_index].	\
								  buffer.m.offset;
			cam->capture.using_buf	= load_address_base_index;
			cam->capture.frame[load_address_base_index].buffer.flags	|= V4L2_BUF_FLAG_DONE;

			time_to_tm(cam->capture.frame[load_address_base_index].buffer.timestamp.tv_sec,DISABLE, &timecode);
			cam->capture.frame[load_address_base_index].buffer.timecode.seconds	= timecode.tm_sec;
			cam->capture.frame[load_address_base_index].buffer.timecode.minutes	= timecode.tm_min;
			cam->capture.frame[load_address_base_index].buffer.timecode.hours	= timecode.tm_hour;
			cam->capture.frame[load_address_base_index].buffer.timecode.type	= V4L2_TC_TYPE_30FPS;
			cam->capture.frame[load_address_base_index].buffer.timecode.flags	= V4L2_TC_FLAG_COLORFRAME;
			cam->capture.frame[load_address_base_index]	\
				.buffer.timecode.frames				= cam->capture.buffer_sequence;
			cam->capture.frame[load_address_base_index]	\
				.buffer.sequence				= cam->capture.buffer_sequence;
		}
/*
 * Note the valid buffers available in the pool
 */
		cam->capture.valid_buf	= valid_buf;
	}
	
	return SUCCESS;
}


FNRESLT disable_isp_irq0(cam_data *cam)
{
	cam->isp->isp_main.reg.isp_irq0enable.ISP_IRQ0ENABLE	= DISABLE;
	return SUCCESS;
}

FNRESLT isp_configure(cam_data *cam)
{
	if(cam == NULL)
	{
		TRACE_ERR_AND_RET(FAIL);
	}

	cam->isp->isp_main.reg.isp_ctrl.ISP_CTRL		= DISABLE;
	cam->isp->isp_main.reg.isp_ctrl.bit.ccdc_clk_en		= ENABLE;
	cam->isp->isp_main.reg.isp_ctrl.bit.par_bridge		= ISPM_ISP_CTRL_MEM_ORDER_MSB_LSB;

	cam->isp->isp_main.reg.isp_ctrl.bit.par_ser_clk_sel	= DISABLE;
	cam->isp->isp_main.reg.isp_ctrl.bit.ccdc_ram_en		= ENABLE;
	cam->isp->isp_main.reg.isp_ctrl.bit.sync_detect		= ISPM_ISP_CTRL_SYNC_DETECT_VS_FALL;
	cam->isp->isp_main.reg.isp_ctrl.bit.shift		= ISPM_ISP_CTRL_BIT_SHIFT_CAMEXT13_2_CAM11_0;


	cam->isp->isp_ccdc.reg.ccdc_hsize_off.bit.lnofst	= cam->capture.v2f.fmt.pix.bytesperline;

	cam->isp->isp_ccdc.reg.ccdc_cfg.bit.vdlc		= ENABLE;

	cam->isp->isp_ccdc.reg.ccdc_syn_mode.bit.vdhden		= ENABLE;
	cam->isp->isp_ccdc.reg.ccdc_syn_mode.bit.datsiz		= 0x0;
	cam->isp->isp_ccdc.reg.ccdc_syn_mode.bit.inpmod		= ISP_CCDC_CCDC_SYNC_MODE_IMPMOD_YUV_16BIT;
	cam->isp->isp_ccdc.reg.ccdc_syn_mode.bit.wen		= ENABLE;

	cam->isp->isp_ccdc.reg.ccdc_horz_info.bit.nph		= cam->capture.v2f.fmt.pix.width -1;
	cam->isp->isp_ccdc.reg.ccdc_vert_start.bit.slv0		= DISABLE;
	cam->isp->isp_ccdc.reg.ccdc_vert_start.bit.slv1		= DISABLE;

	switch(cam->cam_sensor.fmt.fmt.pix.pixelformat)	
	{
		case V4L2_PIX_FMT_YUV420:
		{
			cam->isp->isp_ccdc.reg.ccdc_vert_lines.bit.nlv	= (cam->capture.v2f.fmt.pix.height*3/4) -1;
		}break;

		default:
		{
			cam->isp->isp_ccdc.reg.ccdc_vert_lines.bit.nlv	= cam->capture.v2f.fmt.pix.height -1;
		}break;
	}
	return SUCCESS;
}
/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	:	OMAP_V4L2_BASE	
 *  Name	:	
 *  Parameter1	:	cam_data *cam	- Base address of camera structure pointer
 *  Returns	:	FNRESLT		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative value be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *
 *  Description	: 	After configuration isp irq0 is enabled
 *  Comments	:  	
 ************************************************************************************************************/
FNRESLT enable_isp_irq0(cam_data *cam)
{
	cam->isp->isp_ccdc.reg.ccdc_vdint.bit.vdint0		= cam->capture.v2f.fmt.pix.height -1;
	cam->isp->isp_main.reg.isp_irq0enable.ISP_IRQ0ENABLE	= DISABLE;
	cam->isp->isp_main.reg.isp_irq0enable.bit.ccdc_vd0_irq	= ENABLE;

	return SUCCESS;
}
/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	:	OMAP_V4L2_BASE	
 *  Name	:	
 *  Parameter1	:	cam_data *cam	- Base address of camera structure pointer
 *  Returns	:	FNRESLT		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative value be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *
 *  Description	: 	enable the ccdc unit.
 *  Comments	:  	Once ccdc unit is enabled it will copy the frame into programmed sdram address.
 ************************************************************************************************************/
FNRESLT enable_ccdc(cam_data *cam)
{
	if(cam == NULL)
	{
		TRACE_ERR_AND_RET(FAIL);
	}
	cam->isp->isp_ccdc.reg.ccdc_pcr.bit.enable		= ENABLE;
	return SUCCESS;
}

/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	:	OMAP_V4L2_BASE	
 *  Name	:	disable_ccdc
 *  Parameter1	:	cam_data *cam	- Base address of camera structure pointer
 *  Returns	:	FNRESLT		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative value be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *
 *  Description	: 	disable ccdc unit
 *  Comments	:  	
 ************************************************************************************************************/
FNRESLT disable_ccdc(cam_data *cam)
{
	if(cam == NULL)
	{
		TRACE_ERR_AND_RET(FAIL);
	}
	cam->isp->isp_ccdc.reg.ccdc_pcr.bit.enable		= DISABLE;
	return SUCCESS;
}

/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	:	OMAP_V4L2_BASE	
 *  Name	:	init_cam_isp_ccdc
 *  Parameter1	:	cam_data *cam	- Base address of camera structure pointer
  *  Returns	:	FNRESLT		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative value be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *
 *  Description	: 	init routine of ccdc done here
 *  Comments	:  	
 ************************************************************************************************************/
int init_cam_isp_ccdc(cam_data *cam)
{
	if (!cam)
		return -EINVAL;

/*
 * map the physical address of isp registers 
 * to kernel virtual address
 */
#if 0
	ret_val	= omap_isp_base_struct(cam,CREATE_ADDRESS);
	if(CHECK_IN_FAIL_LIMIT(ret_val))
	{
		printk(KERN_ERR "Failed to map the camera isp registers\n");
		TRACE_ERR_AND_RET(FAIL);		
	}
#endif
	if (omap_isp_base_struct(cam, SET_ADDRESS)) {
		printk(KERN_ERR "Failed to map the camera isp registers\n");
		return -1;
	}

	if (cam_mclk) {
		if (isp_set_xclk(cam, cam_mclk, 0, NULL))
			return -1;
	}
/*
 * Call back function for changing the mclk is assinged here
 */
	cam->modify_mclk_to_sensor = mclk_to_sensor;

	return 0;
}

int exit_cam_isp_ccdc(cam_data *cam)
{
	if (!cam)
		return -EINVAL;

	if (omap_isp_base_struct(cam, MAKE_ADDRESS_INVALID)) {
		printk(KERN_ERR "Failed to unmap the camera isp registers\n");
		return -1;		
	}

	return 0;
}
