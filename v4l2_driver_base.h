/**********************************************************************************************************
 *   Copyright (C) 2007 by e-con Systems.                                                                *
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

#include <media/v4l2-dev.h>
#include <mach/gpio.h>
#include <media/v4l2-ioctl.h>

#include "isp.h"
#include "omap_camera_interface.h"


/*
 * Global definitions
 */
#define MAX_FRAME_SUPPORT			10
#define MAX_PIX_FORMAT_SUPPORTED		10
#define MACRO_MAX_DISCREATE_FROMAT_SUPPORT	10
#define GET_DATA_FRM_SENSOR		1
#define SET_DATA_TO_SENSOR		2
#define QUERY_DATA_FRM_SENSOR		3

typedef struct __cam_base_data
{
	struct video_device			*video_dev;

	struct v4l2_capability			v4l2_cap;		// capture capability
	struct v4l2_control			ctrl;			// ctrl based
	struct v4l2_input 			vinp;
	union
	{
		UINT8			task_state;
		struct
		{
			UINT8			still	:1;
			UINT8			capture	:1;
		}bit;
	}task;

	struct
	{
		struct v4l2_format		v2f;			// v4l2 format 
		struct v4l2_crop		crop;			// crop structure
		struct v4l2_streamparm 		s_parm;			// stream parameter  

//		struct v4l2_requestbuffers 	req_buf;
		SINT32				available_buf;		// This will represet the Number of buffer
									// chain can be formed in the qbuf - dqbuf process

		INT32				using_buf;		// This will represet the current buffer 
									// used by ccdc unit
		INT32				valid_buf;		// This will mention the current valid buffer	
		UINT64				buffer_sequence;	// Total number of effective buffer delivered be
									// available in this byte.
		wait_queue_head_t 		capture_frame_complete;

		struct __capture_dq_buf
		{
			UINT32			width;
			UINT32			height;
			UINT32			size;

			struct v4l2_buffer	buffer;			// physical address to be
									// updated in m.offset
		}frame[MAX_FRAME_SUPPORT];
	}capture;

	struct
	{
		UINT8				wait_queue_head_t_dma_frame_complete_still;

		wait_queue_head_t 		dma_frame_complete_still;
		UINT32				frame_count;

		UINT32				phy_addr;
		UINT32				vir_addr;
	}still;

	cam_interface_pin_config		*pin;
	isp_reg_bit_access			*isp;

/*
 * Place the platform specific content here
 */
	struct platform_driver omap3isp_driver;
	struct device *dev;

/*
 * camera irq routine will be obtained from platform data
 */
	struct platform_device 			*pdev;
	struct resource				*mem;
	UINT32					irq;

	UINT8					clk_enable;
	struct clk 				*cam_mclk;
	struct clk 				*cam_ick;
	
/*
 * Board specific function callbacks
 */
	FNRESLT (*modify_mclk_to_sensor)	(struct __cam_base_data *cam,UINT32 clk_need,UPINT32 clk_set); 
	

/*
 * sensor specific 
 */
	struct camera_sensor
	{
/*
 * platform specific data
 */
		struct i2c_driver i2c_driver;
		
		UINT32 totol_fmt_desc;
		struct v4l2_fmtdesc formats[MAX_PIX_FORMAT_SUPPORTED];
		struct v4l2_queryctrl qctrl;
		struct v4l2_cropcap cropcap;
		struct v4l2_crop scrop;
		struct v4l2_streamparm s_parm;

		UINT32 total_frms_support;
		struct v4l2_frmsizeenum frms[MACRO_MAX_DISCREATE_FROMAT_SUPPORT],*fmt_frm_user;

		UINT32 total_frm_interval_support;
		struct v4l2_frmivalenum frm_interval_support[MACRO_MAX_DISCREATE_FROMAT_SUPPORT],*frame_interval_frm_user;

		UINT8	cmd_to_sensor;
		struct i2c_client 			*client;

		FNRESLT (*find_device) 			(struct __cam_base_data *cam); 
		FNRESLT (*init) 			(struct __cam_base_data *cam); 
		FNRESLT (*reset) 			(struct __cam_base_data *cam); 
		FNRESLT (*config_dim) 			(struct __cam_base_data *cam);
		FNRESLT (*brightness) 			(struct __cam_base_data *cam);
		FNRESLT (*contrast) 			(struct __cam_base_data *cam);
		FNRESLT (*saturation) 			(struct __cam_base_data *cam);
		FNRESLT (*hue) 				(struct __cam_base_data *cam);
		FNRESLT (*whitebalance) 		(struct __cam_base_data *cam);
		FNRESLT (*colour_balance) 		(struct __cam_base_data *cam);
		FNRESLT (*exposure) 			(struct __cam_base_data *cam);
		FNRESLT (*gain) 			(struct __cam_base_data *cam);
		FNRESLT (*v_flip) 			(struct __cam_base_data *cam);
		FNRESLT (*h_mirror) 			(struct __cam_base_data *cam);
		FNRESLT (*sharpness) 			(struct __cam_base_data *cam);

		UINT8	sens_strobe_en;
		FNRESLT (*sens_strobe) 			(struct __cam_base_data *cam);

		FNRESLT (*auto_focus_init) 		(struct __cam_base_data *cam);
		FNRESLT (*focus) 			(struct __cam_base_data *cam);
		FNRESLT (*effects) 			(struct __cam_base_data *cam);
		FNRESLT (*antishake) 			(struct __cam_base_data *cam);
		FNRESLT (*frame_rate_ctrl) 		(struct __cam_base_data *cam);
		FNRESLT (*supported_formats) 		(struct __cam_base_data *cam);
		FNRESLT (*frame_interval) 		(struct __cam_base_data *cam);

		FNRESLT (*crop) 			(struct __cam_base_data *cam);
		FNRESLT (*exit)				(struct __cam_base_data *cam); 

/*
 * Query sensor
 */
		struct v4l2_format			fmt,qfmt;	 
		FNRESLT (*qfmt_support) 		(struct __cam_base_data *cam);
		FNRESLT (*fix_fmt_support) 		(struct __cam_base_data *cam);


	}cam_sensor;

/*
 * Flash specific feature
 */

	struct _flash_driver
	{
		UINT8 enable;
		struct i2c_driver 			i2c;
		struct i2c_client 			*client;

		FNRESLT (*init)				(struct __cam_base_data *cam); 
		FNRESLT (*exit)				(struct __cam_base_data *cam); 
		FNRESLT (*lum_ctrl)			(struct __cam_base_data *cam);
		FNRESLT (*flash)			(struct __cam_base_data *cam);
		FNRESLT (*flash_lum_ctrl)		(struct __cam_base_data *cam);
		FNRESLT (*torch)			(struct __cam_base_data *cam);
		FNRESLT (*torch_lum_ctrl)		(struct __cam_base_data *cam);

		FNRESLT (*unit_enable)			(struct __cam_base_data *cam);
	}cam_flash;

}cam_data;
