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
 *   MODULE NAME           :        OV3640                                                                *
 *   MODULE VERSION        :        VER 1.0                                                               *
 *                                                                                                        *
 *                                                                                                        *
 *                                                                                                        *
 *   Version No	: 000-0001                                                          CODE_REV  : 0.0.1.1   *
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
 * 0.0.1.1
 *==========================================================================================================
 */

#include "inc_header.h"
#include "Headerfile.h"
#include "v4l2_driver_base.h"
#include "fn_protype.h"
#include "omap_v4l2.h"
#include "sens_ov3640.h"


/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	: SENS_OV3640_01	
 *  Name	:	ov3640_init_config
 *  Parameter1	:	cam_data *cam	- Base address of camera structure pointer
 *  Returns	:	int		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative value be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *
 *  Description	:	configure the ov3640 sensor to its default register settings mode	
 *  Comments	:  	
 ************************************************************************************************************/
int ov3640_init_config(cam_data *cam)
{
	ov3640_write_reg(0x3012 ,0x80);
	ov3640_write_reg(0x304d ,0x45);
	ov3640_write_reg(0x30a7 ,0x5e);
	ov3640_write_reg(0x3087 ,0x16);
	ov3640_write_reg(0x309C ,0x1a);
	ov3640_write_reg(0x30a2 ,0xe4);
	ov3640_write_reg(0x30aa ,0x42);
	ov3640_write_reg(0x30b0 ,0xff);
	ov3640_write_reg(0x30b1 ,0xff);
	ov3640_write_reg(0x30b2 ,0x10);

	ov3640_write_reg(0x300e ,0x32);
	ov3640_write_reg(0x300f ,0x21);
	ov3640_write_reg(0x3010 ,0x20);
	ov3640_write_reg(0x3011 ,0x04);
	ov3640_write_reg(0x304c ,0x82);
	ov3640_write_reg(0x30d7 ,0x10);

	ov3640_write_reg(0x30d9 ,0x0d);
	ov3640_write_reg(0x30db ,0x08);
	ov3640_write_reg(0x3016 ,0x82);

	ov3640_write_reg(0x3018 ,0x38);
	ov3640_write_reg(0x3019 ,0x30);
	ov3640_write_reg(0x301a ,0x61);
	ov3640_write_reg(0x307d ,0x00);
	ov3640_write_reg(0x3087 ,0x02);
	ov3640_write_reg(0x3082 ,0x20);

	ov3640_write_reg(0x3015 ,0x12);
	ov3640_write_reg(0x3014 ,0x0c);
	ov3640_write_reg(0x3013 ,0xf7);

	ov3640_write_reg(0x303c ,0x08);
	ov3640_write_reg(0x303d ,0x18);
	ov3640_write_reg(0x303e ,0x06);
	ov3640_write_reg(0x303F ,0x0c);
	ov3640_write_reg(0x3030 ,0x62);	
	ov3640_write_reg(0x3031 ,0x26);
	ov3640_write_reg(0x3032 ,0xe6);
	ov3640_write_reg(0x3033 ,0x6e);
	ov3640_write_reg(0x3034 ,0xea);
	ov3640_write_reg(0x3035 ,0xae);
	ov3640_write_reg(0x3036 ,0xa6);
	ov3640_write_reg(0x3037 ,0x6a);

	ov3640_write_reg(0x3104 ,0x02);
	ov3640_write_reg(0x3105 ,0xfd);
	ov3640_write_reg(0x3106 ,0x00);
	ov3640_write_reg(0x3107 ,0xff);

	ov3640_write_reg(0x3300 ,0x13);
	ov3640_write_reg(0x3301 ,0xde);

	ov3640_write_reg(0x3302 ,0xcf);

	ov3640_write_reg(0x3312 ,0x26);
	ov3640_write_reg(0x3314 ,0x42);
	ov3640_write_reg(0x3313 ,0x2b);
	ov3640_write_reg(0x3315 ,0x42);
	ov3640_write_reg(0x3310 ,0xd0);
	ov3640_write_reg(0x3311 ,0xbd);
	ov3640_write_reg(0x330c ,0x18);
	ov3640_write_reg(0x330d ,0x18);
	ov3640_write_reg(0x330e ,0x56);
	ov3640_write_reg(0x330f ,0x5c);
	ov3640_write_reg(0x330b ,0x1c);
	ov3640_write_reg(0x3306 ,0x5c);
	ov3640_write_reg(0x3307 ,0x11);

	ov3640_write_reg(0x336a ,0x52);
	ov3640_write_reg(0x3370 ,0x44);
	ov3640_write_reg(0x3376 ,0x40);
	ov3640_write_reg(0x3300 ,0x13);

	ov3640_write_reg(0x30b8 ,0x20);
	ov3640_write_reg(0x30b9 ,0x17);
	ov3640_write_reg(0x30ba ,0x04);
	ov3640_write_reg(0x30bb ,0x08);

	ov3640_write_reg(0x3500 ,0x00);
	ov3640_write_reg(0x3507 ,0x06);
	ov3640_write_reg(0x350a ,0x4f);
	ov3640_write_reg(0x3610 ,0x60);

	ov3640_write_reg(0x3100 ,0x32);
	ov3640_write_reg(0x363d ,0x60);

	ov3640_write_reg(0x3301 ,0xde);
	ov3640_write_reg(0x3304 ,0x00);
	ov3640_write_reg(0x3400 ,0x00);
	ov3640_write_reg(0x3404 ,0x00);
	ov3640_write_reg(0x3600 ,0xc0);

	ov3640_write_reg(0x304c ,0x81);
	ov3640_write_reg(0x3011 ,0x04);

	ov3640_write_reg(0x335f ,0x68);
	ov3640_write_reg(0x3360 ,0x18);
	ov3640_write_reg(0x3361 ,0x0c);
	ov3640_write_reg(0x3362 ,0x46);
	ov3640_write_reg(0x3363 ,0x48);
	ov3640_write_reg(0x3364 ,0xb4);

	ov3640_write_reg(0x3012 ,0x00);
	ov3640_write_reg(0x3020 ,0x01);
	ov3640_write_reg(0x3021 ,0x1d);
	ov3640_write_reg(0x3022 ,0x00);
	ov3640_write_reg(0x3023 ,0x0a);
	ov3640_write_reg(0x3024 ,0x08);
	ov3640_write_reg(0x3025 ,0x18);
	ov3640_write_reg(0x3026 ,0x06);
	ov3640_write_reg(0x3027 ,0x0c);
	ov3640_write_reg(0x302a ,0x06);
	ov3640_write_reg(0x302b ,0x20);
	ov3640_write_reg(0x3075 ,0x44);
	ov3640_write_reg(0x300d ,0x00);
	ov3640_write_reg(0x30d7 ,0x10);
	ov3640_write_reg(0x3069 ,0x44);
	ov3640_write_reg(0x303e ,0x01);
	ov3640_write_reg(0x303f ,0x80);

	ov3640_write_reg(0x3302 ,0xef);
	ov3640_write_reg(0x335f ,0x68);
	ov3640_write_reg(0x3360 ,0x18);
	ov3640_write_reg(0x3361 ,0x0c);

	ov3640_write_reg(0x3404 ,0x02);
	ov3640_write_reg(0x3100 ,0x02);


	return SUCCESS;
}


/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION					MODULE ID	: SENS_OV3640_02	
 *  Name	:	configure_dimention_change
 *  Parameter1	:	cam_data *cam	- Base address of camera structure pointer
 *  Returns	:	int		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative value be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *
 *  Description	: 	Configure the mode of streaming (QXGA (or) XGA) based on the Image dimension  
 *  			request given by driver.
 *
 *  Comments	:  	Ov3640 supports two modes XGA and QXGA 
 *
 *  			In XGA mode upto maximum of 30 fps be acheived.
 *  			In QXGA mode upto maximum of 15 fps be acheived.
 ************************************************************************************************************/
int configure_dimention_change(cam_data *cam)
{
	static INT32 width,height,old_logic_case;
	unsigned int logic_case;

	if(	(cam->cam_sensor.fmt.fmt.pix.width <= MODE_XGA_WIDTH) && 	\
		(cam->cam_sensor.fmt.fmt.pix.height <= MODE_XGA_HEIGHT))
	{
		logic_case	= 1;
	}else
	{
		logic_case	= 2;
	}


	if(	 old_logic_case == logic_case)
	{
		return SUCCESS;
	}else
	{
		old_logic_case	= logic_case;
		width		= cam->cam_sensor.fmt.fmt.pix.width;
		height		= cam->cam_sensor.fmt.fmt.pix.height;
	}
	

	switch(logic_case)
	{
		case 1:
		{
			ov3640_write_reg(0x3012, 0x10);
			ov3640_write_reg(0x3023, 0x06);
			ov3640_write_reg(0x3026, 0x03);
			ov3640_write_reg(0x3027, 0x04);

			ov3640_write_reg(0x302a, 0x03);
			ov3640_write_reg(0x302b, 0x10);
			ov3640_write_reg(0x3075, 0x24);
			ov3640_write_reg(0x300d, 0x01);
			ov3640_write_reg(0x30d7, 0x90);
			ov3640_write_reg(0x3069, 0x04);
			ov3640_write_reg(0x303e, 0x00);
			ov3640_write_reg(0x303f, 0xc0);
			ov3640_write_reg(0x3302, 0xef);
			ov3640_write_reg(0x335f, 0x34);
			ov3640_write_reg(0x3360, 0x0c);
			ov3640_write_reg(0x3361, 0x04);
			ov3640_write_reg(0x3362, 0x34);
			ov3640_write_reg(0x3363, 0x08);
			ov3640_write_reg(0x3364, 0x04);
			ov3640_write_reg(0x3403, 0x42);
			ov3640_write_reg(0x3088, 0x04);
			ov3640_write_reg(0x3089, 0x00);
			ov3640_write_reg(0x308a, 0x03);
			ov3640_write_reg(0x308b, 0x00);
			ov3640_write_reg(0x300e, 0x32);
			ov3640_write_reg(0x300f, 0x21);
			ov3640_write_reg(0x3010, 0x20);
			ov3640_write_reg(0x3011, 0x00);
			ov3640_write_reg(0x304c, 0x82);
			break;

		}
		case 2:
		default:
		{
			ov3640_write_reg(0x3100 ,0x32);
			ov3640_write_reg(0x363d ,0x60);

			ov3640_write_reg(0x3301 ,0xde);
			ov3640_write_reg(0x3304 ,0x00);
			ov3640_write_reg(0x3400 ,0x00);
			ov3640_write_reg(0x3404 ,0x00);
			ov3640_write_reg(0x3600 ,0xc0);

			ov3640_write_reg(0x304c ,0x81);
			ov3640_write_reg(0x3011 ,0x01);

			ov3640_write_reg(0x335f ,0x68);
			ov3640_write_reg(0x3360 ,0x18);
			ov3640_write_reg(0x3361 ,0x0c);
			ov3640_write_reg(0x3362 ,0x46);
			ov3640_write_reg(0x3363 ,0x48);
			ov3640_write_reg(0x3364 ,0xb4);

			ov3640_write_reg(0x3012 ,0x00);
			ov3640_write_reg(0x3020 ,0x01);
			ov3640_write_reg(0x3021 ,0x1d);
			ov3640_write_reg(0x3022 ,0x00);
			ov3640_write_reg(0x3023 ,0x0a);
			ov3640_write_reg(0x3024 ,0x08);
			ov3640_write_reg(0x3025 ,0x18);
			ov3640_write_reg(0x3026 ,0x06);
			ov3640_write_reg(0x3027 ,0x0c);
			ov3640_write_reg(0x302a ,0x06);
			ov3640_write_reg(0x302b ,0x20);
			ov3640_write_reg(0x3075 ,0x44);
			ov3640_write_reg(0x300d ,0x00);
			ov3640_write_reg(0x30d7 ,0x10);
			ov3640_write_reg(0x3069 ,0x44);
			ov3640_write_reg(0x303e ,0x01);
			ov3640_write_reg(0x303f ,0x80);

			ov3640_write_reg(0x3302 ,0xef);
			ov3640_write_reg(0x335f ,0x68);
			ov3640_write_reg(0x3360 ,0x18);
			ov3640_write_reg(0x3361 ,0x0c);

			ov3640_write_reg(0x3404 ,0x02);
			ov3640_write_reg(0x3100 ,0x02);
			break;
		}
	}

	ov3640_write_reg(0x3100 ,0x02);
/*
 * colour bar
 */
//	ov3640_write_reg(0x3300 ,0x08);

	return SUCCESS;
}

/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	: SENS_OV3640_03
 *  Name	:	ov3640_change_dim_config
 *  Parameter1	:	cam_data *cam	- Base address of camera structure pointer
 *  Returns	:	int		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative value be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *
 *  Description	: 	Configure the image width and height to the sensor
 *
 *  Comments	:  	Based on the driver request, changing the pixelformat also be performed here.
 *  			Note:
 *  				bfw_count be added for intel pxa based processor to overcome the loss of 
 *  				first line
 ************************************************************************************************************/
int ov3640_change_dim_config(cam_data *cam)
{
	static INT32 old_width, old_height;
	unsigned int width, height, bfw_count = 2;
	int ret_val;

	UINT8 y_start = 2;
	UINT8 x_start = 4;
#if 0 
	static INT32 focus_box	= ENABLE;
	if(focus_box == ENABLE)
	{
		ov3640_write_reg(0x3F00 ,0x04);
		ov3640_write_reg(0x3F00 ,0x01);
		focus_box = DISABLE;
	}else
	{
		ov3640_write_reg(0x3F00 ,0x02);
		focus_box = ENABLE;
	}
#endif
	if (cam->cam_sensor.fix_fmt_support) {
		ret_val	= cam->cam_sensor.fix_fmt_support(cam);

		if(CHECK_IN_FAIL_LIMIT(ret_val))
			TRACE_ERR_AND_RET(FAIL);
	}

	if (cam->cam_sensor.fmt.fmt.pix.width == MODE_XGA_WIDTH &&
		cam->cam_sensor.fmt.fmt.pix.height == MODE_XGA_HEIGHT) {
	        width = cam->cam_sensor.fmt.fmt.pix.width + x_start + 4;
        	height = cam->cam_sensor.fmt.fmt.pix.height+ y_start + 2;
	}
	else {
		width = cam->cam_sensor.fmt.fmt.pix.width + x_start + 4;
        	height = cam->cam_sensor.fmt.fmt.pix.height + y_start + 2 + bfw_count;
	}

	if (width == old_width && height == old_height) {
		goto config_pix_format_dump;
	}
	else {
		old_width = width;
		old_height = height;
	}

	ret_val	= configure_dimention_change(cam);

	if(CHECK_IN_FAIL_LIMIT(ret_val))
		TRACE_ERR_AND_RET(FAIL);
	
	ov3640_write_reg(0x3362, ((height & 0xFF00) >> 4) | ((width & 0xFF00) >> 8));
	ov3640_write_reg(0x3363, (width & 0xFF));
	ov3640_write_reg(0x3364, (height & 0xFF));
	ov3640_write_reg(0x3403, ((x_start << 4) | y_start));
	ov3640_write_reg(0x3088, (cam->cam_sensor.fmt.fmt.pix.width & 0xFF00) >> 8);
	ov3640_write_reg(0x3089, (cam->cam_sensor.fmt.fmt.pix.width & 0xFF));
	ov3640_write_reg(0x308a, ((cam->cam_sensor.fmt.fmt.pix.height + bfw_count) & 0xFF00) >> 8);
	ov3640_write_reg(0x308b, ((cam->cam_sensor.fmt.fmt.pix.height + bfw_count) & 0xFF));

/*
 * Update the autofocus driver that the width and height of the sensor be changed
 */
	ov3640_write_reg(0x3f00, 0x09);

config_pix_format_dump:

	switch (cam->cam_sensor.fmt.fmt.pix.pixelformat) {
	case V4L2_PIX_FMT_UYVY:
	default:
		ov3640_write_reg(0x3400, 0x00);
		ov3640_write_reg(0x3404, 0x02);
		break;

	case V4L2_PIX_FMT_YUYV:
		ov3640_write_reg(0x3400, 0x00);
		ov3640_write_reg(0x3404, 0x00);
		break;
#if 0			
	case V4L2_PIX_FMT_YUV420:
		ov3640_write_reg(0x3400, 0x00);
		ov3640_write_reg(0x3404, 0x08);
		break;
#endif
	case V4L2_PIX_FMT_YUV444:
		ov3640_write_reg(0x3400, 0x00);
		ov3640_write_reg(0x3404, 0x0E);
		break;

	case V4L2_PIX_FMT_BGR32:
		ov3640_write_reg(0x3400, 0x01);
		ov3640_write_reg(0x3404, 0x1C);
		break;

	case V4L2_PIX_FMT_RGB555:
		ov3640_write_reg(0x3400, 0x01); 
		ov3640_write_reg(0x3404, 0x13);
		break;

	case V4L2_PIX_FMT_RGB565:
		ov3640_write_reg(0x3400, 0x01); 
		ov3640_write_reg(0x3404, 0x30);
		break;	

	case V4L2_PIX_FMT_SBGGR8:
		ov3640_write_reg(0x3400, 0x01);
		ov3640_write_reg(0x3404, 0x18);
		break;
	}
	
	return SUCCESS;
}
/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	: SENS_OV3640_20	
 *  Name	:	ov3640_crop
 *  Parameter1	:	cam_data *cam	- Base address of camera structure pointer 	
 *  Returns	:	int		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative value be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *
 *  Description	: 	
 *  Comments	:  	
 ************************************************************************************************************/

int ov3640_crop(cam_data *cam)
{
	switch(cam->cam_sensor.cmd_to_sensor)
	{
		case GET_DATA_FRM_SENSOR:
		{
			cam->cam_sensor.cropcap.bounds.top = DISABLE;
			cam->cam_sensor.cropcap.bounds.left = DISABLE;
			cam->cam_sensor.cropcap.bounds.width = MAX_OV3640_WIDTH;
			cam->cam_sensor.cropcap.bounds.height = MAX_OV3640_HEIGHT;
			cam->cam_sensor.cropcap.defrect = cam->cam_sensor.cropcap.bounds;
			cam->cam_sensor.cropcap.pixelaspect.numerator = 1;
			cam->cam_sensor.cropcap.pixelaspect.denominator = 1;

		}break;
		case SET_DATA_TO_SENSOR:
		{

		}break;
		case QUERY_DATA_FRM_SENSOR:
		{

		}break;		
	}
	return SUCCESS;
}
/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	: SENS_OV3640_04	
 *  Name	:	ov3640_brightness
 *  Parameter1	:	cam_data *cam	- Base address of camera structure pointer 	
 *  Returns	:	int		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative value be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *
 *  Description	: 	Image brightness from the sensor can be increased (or) decrease
 *  Comments	:  	
 ************************************************************************************************************/
int ov3640_brightness(cam_data *cam)
{
/*
 * Value must be in the range of 
 * -0x30  0x0  0x30
 *  -48   0   +48
 */
	printk(KERN_DEBUG "Brightness Value is %d\n",cam->ctrl.value);

	switch(cam->cam_sensor.cmd_to_sensor)
	{
		case GET_DATA_FRM_SENSOR:
		{
			UINT8 reg_value;
			ov3640_read_reg(0x3354,&reg_value);
			if(reg_value == 0x08)
			{
				ov3640_read_reg(0x335e,&reg_value);
				cam->ctrl.value	= -reg_value;
			}else
			{
				ov3640_read_reg(0x335e,&reg_value);
				cam->ctrl.value	= reg_value;
			}
			cam->ctrl.value	= (cam->ctrl.value)>48?48:		\
						(cam->ctrl.value)<-48?-48:	\
						(cam->ctrl.value);
		}break;

		case SET_DATA_TO_SENSOR:
		{
			if(cam->ctrl.value >= 0)
			{
				ov3640_write_reg(0x335e,0xFF & (cam->ctrl.value));
				ov3640_write_reg(0x3355,0x04);
				ov3640_write_reg(0x3354,0x01);
			}else
			{
				ov3640_write_reg(0x335e,0xFF & (-cam->ctrl.value));
				ov3640_write_reg(0x3355,0x04);
				ov3640_write_reg(0x3354,0x08);
			}
		}break;

		case QUERY_DATA_FRM_SENSOR:
		{
			cam->cam_sensor.qctrl.id	= V4L2_CID_BRIGHTNESS;
			cam->cam_sensor.qctrl.type	= V4L2_CTRL_TYPE_INTEGER;
			strncpy(cam->cam_sensor.qctrl.name,"Brightness",strlen("Brightness"));
			cam->cam_sensor.qctrl.minimum = -48;
			cam->cam_sensor.qctrl.maximum = 48;
			cam->cam_sensor.qctrl.step = 1;
			cam->cam_sensor.qctrl.default_value = 0;
			cam->cam_sensor.qctrl.flags = V4L2_CTRL_FLAG_SLIDER;

		}break;

		default:
		{
			TRACE_ERR_AND_RET(-EINVAL);	
		}
	}
	return SUCCESS;
}

/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	: SENS_OV3640_05
 *  Name	:	ov3640_exposure
 *  Parameter1	:	cam_data *cam	- Base address of camera structure pointer
 *  Returns	:	int		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative value be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *
 *  Description	: 	Histogram based exposure algorithm to increase the exposure of the image
 *  Comments	:  	In ov3640 sensor Average based and Histogram based algorithm be available
 *  			
 ************************************************************************************************************/
int ov3640_exposure(cam_data *cam)
{
/*
 * Histogram-based Algorithm
 * Value must be in the range of 
 * 0x38 - 0x88
 *  -40 - +40
 */
	printk(KERN_DEBUG "ov3640_exposure %d\n",cam->ctrl.value);

	switch(cam->cam_sensor.cmd_to_sensor)
	{
		case GET_DATA_FRM_SENSOR:
		{
			UINT8 reg_value;
			ov3640_read_reg(0x3018,&reg_value);
			cam->ctrl.value	= reg_value -0x80;
			cam->ctrl.value	= (cam->ctrl.value)>40?40:		\
						(cam->ctrl.value)<-40?-40:	\
						(cam->ctrl.value);

		}break;

		case SET_DATA_TO_SENSOR:
		{
			if((cam->ctrl.value >= -40) && (cam->ctrl.value <= 40))
			{
				ov3640_write_reg(0x3018, 0x80 + cam->ctrl.value );
				ov3640_write_reg(0x3019, 0x60 + cam->ctrl.value );

			}else
			{
				ov3640_write_reg(0x3018, 0x80);
				ov3640_write_reg(0x3019, 0x60);
			}

		}break;

		case QUERY_DATA_FRM_SENSOR:
		{
			cam->cam_sensor.qctrl.id	= V4L2_CID_EXPOSURE;
			cam->cam_sensor.qctrl.type	= V4L2_CTRL_TYPE_INTEGER;
			strncpy(cam->cam_sensor.qctrl.name,"Exposure",strlen("Exposure"));
			cam->cam_sensor.qctrl.minimum = -40;
			cam->cam_sensor.qctrl.maximum = 40;
			cam->cam_sensor.qctrl.step = 1;
			cam->cam_sensor.qctrl.default_value = 0;
			cam->cam_sensor.qctrl.flags = V4L2_CTRL_FLAG_SLIDER;

		}break;

		default:
		{
			TRACE_ERR_AND_RET(-EINVAL);	
		}
	}
	return SUCCESS;
}
/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	: SENS_OV3640_06	
 *  Name	:	ov3640_sharpness
 *  Parameter1	:	cam_data *cam	- Base address of camera structure pointer
 *  Returns	:	int		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative value be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *
 *  Description	: 	Image output sharpness from the sensor be increased or decreased. 
 *  Comments	:  	
 ************************************************************************************************************/
int ov3640_sharpness(cam_data *cam)
{
/*
 * Value must be in the range of 
 * 0x42 0x45 0x48
 *  -3   0   +3
 */
	printk(KERN_DEBUG "ov3640_sharpness %d\n",cam->ctrl.value);
	switch(cam->cam_sensor.cmd_to_sensor)
	{
		case GET_DATA_FRM_SENSOR:
		{
			UINT8 reg_value;
			ov3640_read_reg(0x332d,&reg_value);
			cam->ctrl.value	= reg_value -0x45;
			cam->ctrl.value	= (cam->ctrl.value)>3?3:		\
						(cam->ctrl.value)<-3?-3:	\
						(cam->ctrl.value);

		}break;

		case SET_DATA_TO_SENSOR:
		{
			if((cam->ctrl.value >= -3) && (cam->ctrl.value <= 3))
			{
				ov3640_write_reg(0x332d, 0x45 + (cam->ctrl.value));
				ov3640_write_reg(0x332f, 0x03);
			}else
			{
				ov3640_write_reg(0x332d, 0x60);
				ov3640_write_reg(0x332f, 0x03);
			}
		}break;

		case QUERY_DATA_FRM_SENSOR:
		{
			cam->cam_sensor.qctrl.id	= V4L2_CID_SHARPNESS;
			cam->cam_sensor.qctrl.type	= V4L2_CTRL_TYPE_INTEGER;
			strncpy(cam->cam_sensor.qctrl.name,"sharpness",strlen("sharpness"));
			cam->cam_sensor.qctrl.minimum = -3;
			cam->cam_sensor.qctrl.maximum = 3;
			cam->cam_sensor.qctrl.step = 1;
			cam->cam_sensor.qctrl.default_value = 0;
			cam->cam_sensor.qctrl.flags = V4L2_CTRL_FLAG_SLIDER;

		}break;

		default:
		{
			TRACE_ERR_AND_RET(-EINVAL);	
		}
	}
	return SUCCESS;
}
/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	: SENS_OV3640_07
 *  Name	:	ov3640_effects
 *  Parameter1	:	cam_data *cam	- Base address of camera structure pointer
 *  Returns	:	int		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative value be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *
 *  Description	: 	Camera effects supported by the sensor  	
 *  Comments	:  	Supported effects by the sensor are Sepia,Monochrome,Negative,Bluish,Greenish
 *  			and Yellowish
 ************************************************************************************************************/

int ov3640_effects(cam_data *cam)
{
/*
 * Value must be in the range of 
 * 0 to 7
 *
 * 	Normal			0
 * 	Sepia(antique)		1
 * 	Mono chrome		2
 * 	Negative		3
 * 	Bluish			4
 * 	Greenish		5
 * 	Reddish			6
 * 	Yellowish		7
 */
	printk(KERN_DEBUG "ov3640_effects %d\n",cam->ctrl.value);

	switch(cam->ctrl.value)
	{
		case 0:
		{
			ov3640_write_reg(0x3302, 0xef);
			ov3640_write_reg(0x3355, 0x00);
		}break;

		case 1:
		{
			ov3640_write_reg(0x3302, 0xef);
			ov3640_write_reg(0x3355, 0x18);
			ov3640_write_reg(0x335a, 0x40);
			ov3640_write_reg(0x335b, 0xa6);

		}break;

		case 2:
		{
			ov3640_write_reg(0x3302, 0xef);
			ov3640_write_reg(0x3355, 0x18);	// bit[4]fix u enable, bit[3]fix v enable
			ov3640_write_reg(0x335a, 0x80);
			ov3640_write_reg(0x335b, 0x80);

		}break;

		case 3:
		{
			ov3640_write_reg(0x3302, 0xef);
			ov3640_write_reg(0x3355, 0x40);	// bit[6] negative
		}break;

		case 4:
		{
			ov3640_write_reg(0x3302, 0xef);
			ov3640_write_reg(0x3355, 0x18);
			ov3640_write_reg(0x335a, 0xa0);
			ov3640_write_reg(0x335b, 0x40);
		}break;

		case 5:
		{
			ov3640_write_reg(0x3302, 0xef);
			ov3640_write_reg(0x3355, 0x18);
			ov3640_write_reg(0x335a, 0x60);
			ov3640_write_reg(0x335b, 0x60);

		}break;

		case 6:
		{
			ov3640_write_reg(0x3302, 0xef);
			ov3640_write_reg(0x3355, 0x18);
			ov3640_write_reg(0x335a, 0x80);
			ov3640_write_reg(0x335b, 0xc0);

		}break;

		case 7:
		{
			ov3640_write_reg(0x3302, 0xef);
			ov3640_write_reg(0x3355, 0x18);
			ov3640_write_reg(0x335a, 0x30);
			ov3640_write_reg(0x335b, 0x90);

		}break;
	}
	return SUCCESS;
}

/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	: SENS_OV3640_08
 *  Name	:	ov3640_saturation
 *  Parameter1	:	cam_data *cam	- Base address of camera structure pointer
 *  Returns	:	int		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative value be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *
 *  Description	: 	Image output saturation from the sensor be increased or decreased.
 *  Comments	:  	
 ************************************************************************************************************/

int ov3640_saturation(cam_data *cam)
{
	printk(KERN_DEBUG "ov3640_saturation %d\n",cam->ctrl.value);

/*
 * Value must be in the range of 
 * 0x10 0x20 0x70
 *  -48   0   +48
 */
	switch(cam->cam_sensor.cmd_to_sensor)
	{
		case GET_DATA_FRM_SENSOR:
		{
			UINT8 reg_value;
			ov3640_read_reg(0x3358,&reg_value);
			cam->ctrl.value	= reg_value - 0x30;
			cam->ctrl.value	= (cam->ctrl.value)>48?48:		\
						(cam->ctrl.value)<-48?-48:	\
						(cam->ctrl.value);
		}break;

		case SET_DATA_TO_SENSOR:
		{
			if((cam->ctrl.value >= -48) && (cam->ctrl.value <= 48))
			{
				ov3640_write_reg(0x3302, 0xef);
				ov3640_write_reg(0x3355, 0x02);
				ov3640_write_reg(0x3358, 0x30 + (cam->ctrl.value));
				ov3640_write_reg(0x3359, 0x30 + (cam->ctrl.value));
			}
		}break;

		case QUERY_DATA_FRM_SENSOR:
		{
			cam->cam_sensor.qctrl.id	= V4L2_CID_SATURATION;
			cam->cam_sensor.qctrl.type	= V4L2_CTRL_TYPE_INTEGER;
			strncpy(cam->cam_sensor.qctrl.name,"saturation",strlen("saturation"));
			cam->cam_sensor.qctrl.minimum = -48;
			cam->cam_sensor.qctrl.maximum = 48;
			cam->cam_sensor.qctrl.step = 1;
			cam->cam_sensor.qctrl.default_value = 0;
			cam->cam_sensor.qctrl.flags = V4L2_CTRL_FLAG_SLIDER;

		}break;

		default:
		{
			TRACE_ERR_AND_RET(-EINVAL);	
		}
	}
	return SUCCESS;
}

/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	: SENS_OV3640_09
 *  Name	:	ov3640_contrast
 *  Parameter1	:	cam_data *cam	- Base address of camera structure pointer
 *  Returns	:	int		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative value be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *
 *  Description	: 	Image output contrast from the sensor be increased or decreased.
 *  Comments	:  	
 ************************************************************************************************************/

int ov3640_contrast(cam_data *cam)
{
	printk(KERN_DEBUG "ov3640_contrast %d\n",cam->ctrl.value);

/*
 * Value must be in the range of 
 * 0x14 0x20 0x2c
 * -12   0   12
 */
	switch(cam->cam_sensor.cmd_to_sensor)
	{
		case GET_DATA_FRM_SENSOR:
		{
			UINT8 reg_value;
			ov3640_read_reg(0x335c,&reg_value);
			cam->ctrl.value	= reg_value - 0x20;
			cam->ctrl.value	= (cam->ctrl.value)>12?12:		\
						(cam->ctrl.value)<-12?-12:	\
						(cam->ctrl.value);
		}break;

		case SET_DATA_TO_SENSOR:
		{
			if((cam->ctrl.value >= -12) && (cam->ctrl.value <= 12))
			{
				ov3640_write_reg(0x3302, 0xef);
				ov3640_write_reg(0x3355, 0x04);
				ov3640_write_reg(0x3354, 0x01);
				ov3640_write_reg(0x335c, 0x20 + (cam->ctrl.value));
				ov3640_write_reg(0x335d, 0x20 + (cam->ctrl.value));
			}
		}break;

		case QUERY_DATA_FRM_SENSOR:
		{
			cam->cam_sensor.qctrl.id	= V4L2_CID_CONTRAST;
			cam->cam_sensor.qctrl.type	= V4L2_CTRL_TYPE_INTEGER;
			strncpy(cam->cam_sensor.qctrl.name,"contrast",strlen("contrast"));
			cam->cam_sensor.qctrl.minimum = -12;
			cam->cam_sensor.qctrl.maximum = 12;
			cam->cam_sensor.qctrl.step = 1;
			cam->cam_sensor.qctrl.default_value = 0;
			cam->cam_sensor.qctrl.flags = V4L2_CTRL_FLAG_SLIDER;

		}break;

		default:
		{
			TRACE_ERR_AND_RET(-EINVAL);	
		}
	}
	return SUCCESS;
}
/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	: SENS_OV3640_10
 *  Name	:	planckian_locus_lookuptable
 *  Parameter1	:	INT32 value	- Temperature of the source.
 *  Returns	:	int		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative value be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *
 *  Description	:	Adjust the whilebalance of the sensor based on envionment source temperature		
 *  Comments	:  	
 ************************************************************************************************************/

int planckian_locus_lookuptable(INT32 value)
{
	typedef struct _aw_temp_gain_adj
	{
		unsigned int temp;
		UINT8 r;
		UINT8 g;
		UINT8 b;
	}aw_gain_adj;

	aw_gain_adj temp_aw_gain[]	=	{				\
							{3000,0x44,0x40,0x70},	\
							{4000,0x52,0x40,0x48},	\
							{5000,0x68,0x40,0x4e},	\
							{5500,0x5e,0x40,0x46}	\
						}; 

	unsigned int i	= DISABLE;
	
	for(i	= DISABLE; i < (sizeof(temp_aw_gain)/sizeof(temp_aw_gain[0]));i++)
	{
		if(temp_aw_gain[i].temp >= value)
		{
			break;
		}
	}
	ov3640_write_reg(0x33a7,temp_aw_gain[i].r);
	ov3640_write_reg(0x33a8,temp_aw_gain[i].g);
	ov3640_write_reg(0x33a9,temp_aw_gain[i].b);

	return SUCCESS;
}

/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	: SENS_OV3640_11	
 *  Name	:	ov3640_white_balance
 *  Parameter1	:	cam_data *cam	- Base address of camera structure pointer
 *  Returns	:	int		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative value be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *
 *  Description	: 	Image Whitebalance settings from the sensor
 *  Comments	:  	Auto White balance, Daylight,Tungsten,Fluorescent and cloudy settings are 
 *  			available 
 ************************************************************************************************************/
int ov3640_white_balance(cam_data *cam)
{
	int ret_val;
	printk(KERN_DEBUG "ov3640_white_balance %d\n",cam->ctrl.value);

	switch(cam->cam_sensor.cmd_to_sensor)
	{
		case GET_DATA_FRM_SENSOR:
		{
		}break;

		case SET_DATA_TO_SENSOR:
		{
			switch(cam->ctrl.id)
			{
				case V4L2_CID_AUTO_WHITE_BALANCE:
				{
					if(!cam->ctrl.value)
					{
						ov3640_write_reg(0x332b, 0x08);
						return SUCCESS;
					}
				}

				case V4L2_CID_DO_WHITE_BALANCE:
				{
					ov3640_write_reg(0x332b,0x00);
				}break;

				case V4L2_CID_WHITE_BALANCE_TEMPERATURE:
				{
					ov3640_write_reg(0x332b, 0x08);
					ret_val	= planckian_locus_lookuptable(cam->ctrl.value);
					if(CHECK_IN_FAIL_LIMIT(ret_val))
					{
						TRACE_ERR_AND_RET(FAIL);
					}
				}break;
			}

		}break;

		case QUERY_DATA_FRM_SENSOR:
		{
		}break;

		default:
		{
			TRACE_ERR_AND_RET(-EINVAL);	
		}
	}
	return SUCCESS;
}

/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	: SENS_OV3640_12	
 *  Name	:	ov3640_vertical_flip
 *  Parameter1	:	cam_data *cam	- Base address of camera structure pointer
 *  Returns	:	int		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative value be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *
 *  Description	: 	Change the Image display order - Vertical flip 
 *  Comments	:  	
 ************************************************************************************************************/

int ov3640_vertical_flip(cam_data *cam)
{
	UINT8 reg_value;
	ov3640_read_reg(0x307c,&reg_value);

	switch(cam->cam_sensor.cmd_to_sensor)
	{
		case GET_DATA_FRM_SENSOR:
		{
			if(reg_value & (0x1 <<0))
			{
				cam->ctrl.value = ENABLE;
			}else
			{
				cam->ctrl.value	= DISABLE;
			}
		}break;

		case SET_DATA_TO_SENSOR:
		{
			if(cam->ctrl.value)
			{
				reg_value = (reg_value |(0x1<<0));
			}else
			{
				reg_value &=  ~((0x1<<0));
			}
			ov3640_write_reg(0x307c,reg_value);
		}break;

		case QUERY_DATA_FRM_SENSOR:
		{
			cam->cam_sensor.qctrl.id	= V4L2_CID_VFLIP;
			cam->cam_sensor.qctrl.type	= V4L2_CTRL_TYPE_BOOLEAN;
			strncpy(cam->cam_sensor.qctrl.name,"Vertical flip",strlen("Vertical flip"));
			cam->cam_sensor.qctrl.minimum = 0;
			cam->cam_sensor.qctrl.maximum = 1;
			cam->cam_sensor.qctrl.step = 1;
			cam->cam_sensor.qctrl.default_value = 0;
		}break;

		default:
		{
			TRACE_ERR_AND_RET(-EINVAL);	
		}
	}
	return SUCCESS;
}

/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	: SENS_OV3640_13	
 *  Name	:	ov3640_horizontal_mirror
 *  Parameter1	:	cam_data *cam	- Base address of camera structure pointer
 *  Returns	:	int		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative value be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *
 *  Description	: 	Change the Image display order - Horizontal mirror
 *  Comments	:  	
 ************************************************************************************************************/

int ov3640_horizontal_mirror(cam_data *cam)
{
	UINT8 reg_value;
	ov3640_read_reg(0x3090,&reg_value);
	switch(cam->cam_sensor.cmd_to_sensor)
	{
		case GET_DATA_FRM_SENSOR:
		{
			if(reg_value & (0x1 <<3))
			{
				cam->ctrl.value = ENABLE;
			}else
			{
				cam->ctrl.value	= DISABLE;
			}
		}break;

		case SET_DATA_TO_SENSOR:
		{
			if(cam->ctrl.value)
			{
				reg_value = (reg_value |(0x1<<3));
			}else
			{
				reg_value &=  ~((0x1<<3));
			}
			ov3640_write_reg(0x3090,reg_value);
		}break;

		case QUERY_DATA_FRM_SENSOR:
		{
			cam->cam_sensor.qctrl.id	= V4L2_CID_HFLIP;
			cam->cam_sensor.qctrl.type	= V4L2_CTRL_TYPE_BOOLEAN;
			strncpy(cam->cam_sensor.qctrl.name,"Horizontal mirror",strlen("Horizontal mirror"));
			cam->cam_sensor.qctrl.minimum = 0;
			cam->cam_sensor.qctrl.maximum = 1;
			cam->cam_sensor.qctrl.step = 1;
			cam->cam_sensor.qctrl.default_value = 0;

		}break;

		default:
		{
			TRACE_ERR_AND_RET(-EINVAL);	
		}
	}
	return SUCCESS;
}

/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	: SENS_OV3640_21
 *
 *  Name	:	ov3640_antishake_firmware_ctrl
 *  Parameter1	:	cam_data *cam	- Base address of camera structure pointer
 *  Returns	:	int		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative value be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *
 *  Description	: 	Auto focus firmware register dump
 *  Comments	:  	Before performing autofocus related operations -Auto focus firmware dump should be 
 *  			applied
 ************************************************************************************************************/

int ov3640_antishake_firmware_ctrl(cam_data *cam)
{
	switch(cam->cam_sensor.cmd_to_sensor)
	{	
		case GET_DATA_FRM_SENSOR:
		{
			UINT8 reg_value	= DISABLE;
			switch(cam->ctrl.id)
			{
				case V4L2_SENS_ANTISHAKE_STATUS:
				{
					ov3640_read_reg(0x3f07,&reg_value);
					cam->ctrl.value	= reg_value;
				}break;
			}

		}break;

		case SET_DATA_TO_SENSOR:
		{
			switch(cam->ctrl.id)
			{
				case V4L2_SENS_ANTISHAKE:
				{
					ov3640_write_reg(0x308c,0x00);
					ov3640_write_reg(0x3104,0x02);
					ov3640_write_reg(0x3105,0xff);
					ov3640_write_reg(0x3106,0x00);
					ov3640_write_reg(0x3107,0xff);
					ov3640_write_reg(0x8000,0x02);
					ov3640_write_reg(0x8001,0x07);
					ov3640_write_reg(0x8002,0xE0);
					ov3640_write_reg(0x8003,0x02);
					ov3640_write_reg(0x8004,0x00);
					ov3640_write_reg(0x8005,0x06);
					ov3640_write_reg(0x8006,0xC0);
					ov3640_write_reg(0x8007,0xE0);
					ov3640_write_reg(0x8008,0xC0);
					ov3640_write_reg(0x8009,0xF0);
					ov3640_write_reg(0x800A,0xC0);
					ov3640_write_reg(0x800B,0x83);
					ov3640_write_reg(0x800C,0xC0);
					ov3640_write_reg(0x800D,0x82);
					ov3640_write_reg(0x800E,0xC0);
					ov3640_write_reg(0x800F,0xD0);
					ov3640_write_reg(0x8010,0x75);
					ov3640_write_reg(0x8011,0xD0);
					ov3640_write_reg(0x8012,0x00);
					ov3640_write_reg(0x8013,0xC0);
					ov3640_write_reg(0x8014,0x00);
					ov3640_write_reg(0x8015,0xC0);
					ov3640_write_reg(0x8016,0x04);
					ov3640_write_reg(0x8017,0xC0);
					ov3640_write_reg(0x8018,0x05);
					ov3640_write_reg(0x8019,0xC0);
					ov3640_write_reg(0x801A,0x06);
					ov3640_write_reg(0x801B,0xC0);
					ov3640_write_reg(0x801C,0x07);
					ov3640_write_reg(0x801D,0x90);
					ov3640_write_reg(0x801E,0x37);
					ov3640_write_reg(0x801F,0x08);
					ov3640_write_reg(0x8020,0xE0);
					ov3640_write_reg(0x8021,0x20);
					ov3640_write_reg(0x8022,0xE3);
					ov3640_write_reg(0x8023,0x03);
					ov3640_write_reg(0x8024,0x02);
					ov3640_write_reg(0x8025,0x02);
					ov3640_write_reg(0x8026,0x05);
					ov3640_write_reg(0x8027,0x90);
					ov3640_write_reg(0x8028,0x3F);
					ov3640_write_reg(0x8029,0x01);
					ov3640_write_reg(0x802A,0xE0);
					ov3640_write_reg(0x802B,0x04);
					ov3640_write_reg(0x802C,0xF0);
					ov3640_write_reg(0x802D,0x30);
					ov3640_write_reg(0x802E,0x0D);
					ov3640_write_reg(0x802F,0x03);
					ov3640_write_reg(0x8030,0x02);
					ov3640_write_reg(0x8031,0x01);
					ov3640_write_reg(0x8032,0xFB);
					ov3640_write_reg(0x8033,0x30);
					ov3640_write_reg(0x8034,0x0A);
					ov3640_write_reg(0x8035,0x07);
					ov3640_write_reg(0x8036,0x90);
					ov3640_write_reg(0x8037,0x30);
					ov3640_write_reg(0x8038,0xB4);
					ov3640_write_reg(0x8039,0xE0);
					ov3640_write_reg(0x803A,0x44);
					ov3640_write_reg(0x803B,0x08);
					ov3640_write_reg(0x803C,0xF0);
					ov3640_write_reg(0x803D,0x05);
					ov3640_write_reg(0x803E,0x45);
					ov3640_write_reg(0x803F,0xE5);
					ov3640_write_reg(0x8040,0x45);
					ov3640_write_reg(0x8041,0x70);
					ov3640_write_reg(0x8042,0x03);
					ov3640_write_reg(0x8043,0x75);
					ov3640_write_reg(0x8044,0x45);
					ov3640_write_reg(0x8045,0x01);
					ov3640_write_reg(0x8046,0x90);
					ov3640_write_reg(0x8047,0x3A);
					ov3640_write_reg(0x8048,0x00);
					ov3640_write_reg(0x8049,0x74);
					ov3640_write_reg(0x804A,0x80);
					ov3640_write_reg(0x804B,0xF0);
					ov3640_write_reg(0x804C,0x90);
					ov3640_write_reg(0x804D,0x3A);
					ov3640_write_reg(0x804E,0x03);
					ov3640_write_reg(0x804F,0xE0);
					ov3640_write_reg(0x8050,0xF5);
					ov3640_write_reg(0x8051,0x51);
					ov3640_write_reg(0x8052,0xE0);
					ov3640_write_reg(0x8053,0xF5);
					ov3640_write_reg(0x8054,0x53);
					ov3640_write_reg(0x8055,0xE0);
					ov3640_write_reg(0x8056,0xF5);
					ov3640_write_reg(0x8057,0x55);
					ov3640_write_reg(0x8058,0xE0);
					ov3640_write_reg(0x8059,0xF5);
					ov3640_write_reg(0x805A,0x57);
					ov3640_write_reg(0x805B,0xE0);
					ov3640_write_reg(0x805C,0xF5);
					ov3640_write_reg(0x805D,0x52);
					ov3640_write_reg(0x805E,0xE0);
					ov3640_write_reg(0x805F,0xF5);
					ov3640_write_reg(0x8060,0x54);
					ov3640_write_reg(0x8061,0xE0);
					ov3640_write_reg(0x8062,0xF5);
					ov3640_write_reg(0x8063,0x56);
					ov3640_write_reg(0x8064,0xE0);
					ov3640_write_reg(0x8065,0xF5);
					ov3640_write_reg(0x8066,0x58);
					ov3640_write_reg(0x8067,0xE5);
					ov3640_write_reg(0x8068,0x55);
					ov3640_write_reg(0x8069,0xF5);
					ov3640_write_reg(0x806A,0x27);
					ov3640_write_reg(0x806B,0xE5);
					ov3640_write_reg(0x806C,0x53);
					ov3640_write_reg(0x806D,0xF5);
					ov3640_write_reg(0x806E,0x28);
					ov3640_write_reg(0x806F,0xE5);
					ov3640_write_reg(0x8070,0x72);
					ov3640_write_reg(0x8071,0x64);
					ov3640_write_reg(0x8072,0x01);
					ov3640_write_reg(0x8073,0x60);
					ov3640_write_reg(0x8074,0x03);
					ov3640_write_reg(0x8075,0x02);
					ov3640_write_reg(0x8076,0x01);
					ov3640_write_reg(0x8077,0x18);
					ov3640_write_reg(0x8078,0x20);
					ov3640_write_reg(0x8079,0x0A);
					ov3640_write_reg(0x807A,0x03);
					ov3640_write_reg(0x807B,0x02);
					ov3640_write_reg(0x807C,0x01);
					ov3640_write_reg(0x807D,0x24);
					ov3640_write_reg(0x807E,0x20);
					ov3640_write_reg(0x807F,0x0A);
					ov3640_write_reg(0x8080,0x03);
					ov3640_write_reg(0x8081,0x02);
					ov3640_write_reg(0x8082,0x01);
					ov3640_write_reg(0x8083,0xFB);
					ov3640_write_reg(0x8084,0x20);
					ov3640_write_reg(0x8085,0x09);
					ov3640_write_reg(0x8086,0x3F);
					ov3640_write_reg(0x8087,0x75);
					ov3640_write_reg(0x8088,0x26);
					ov3640_write_reg(0x8089,0x00);
					ov3640_write_reg(0x808A,0x12);
					ov3640_write_reg(0x808B,0x06);
					ov3640_write_reg(0x808C,0x5F);
					ov3640_write_reg(0x808D,0x25);
					ov3640_write_reg(0x808E,0x5A);
					ov3640_write_reg(0x808F,0xF5);
					ov3640_write_reg(0x8090,0x5A);
					ov3640_write_reg(0x8091,0xEE);
					ov3640_write_reg(0x8092,0x35);
					ov3640_write_reg(0x8093,0x59);
					ov3640_write_reg(0x8094,0xF5);
					ov3640_write_reg(0x8095,0x59);
					ov3640_write_reg(0x8096,0x05);
					ov3640_write_reg(0x8097,0x26);
					ov3640_write_reg(0x8098,0xE5);
					ov3640_write_reg(0x8099,0x26);
					ov3640_write_reg(0x809A,0xB4);
					ov3640_write_reg(0x809B,0x08);
					ov3640_write_reg(0x809C,0xED);
					ov3640_write_reg(0x809D,0xE5);
					ov3640_write_reg(0x809E,0x5A);
					ov3640_write_reg(0x809F,0xAE);
					ov3640_write_reg(0x80A0,0x59);
					ov3640_write_reg(0x80A1,0x78);
					ov3640_write_reg(0x80A2,0x03);
					ov3640_write_reg(0x80A3,0xCE);
					ov3640_write_reg(0x80A4,0xC3);
					ov3640_write_reg(0x80A5,0x13);
					ov3640_write_reg(0x80A6,0xCE);
					ov3640_write_reg(0x80A7,0x13);
					ov3640_write_reg(0x80A8,0xD8);
					ov3640_write_reg(0x80A9,0xF9);
					ov3640_write_reg(0x80AA,0xF5);
					ov3640_write_reg(0x80AB,0x5A);
					ov3640_write_reg(0x80AC,0x8E);
					ov3640_write_reg(0x80AD,0x59);
					ov3640_write_reg(0x80AE,0xFF);
					ov3640_write_reg(0x80AF,0x7C);
					ov3640_write_reg(0x80B0,0x00);
					ov3640_write_reg(0x80B1,0x7D);
					ov3640_write_reg(0x80B2,0x03);
					ov3640_write_reg(0x80B3,0x12);
					ov3640_write_reg(0x80B4,0x0C);
					ov3640_write_reg(0x80B5,0xC8);
					ov3640_write_reg(0x80B6,0xEF);
					ov3640_write_reg(0x80B7,0x78);
					ov3640_write_reg(0x80B8,0x02);
					ov3640_write_reg(0x80B9,0xCE);
					ov3640_write_reg(0x80BA,0xC3);
					ov3640_write_reg(0x80BB,0x13);
					ov3640_write_reg(0x80BC,0xCE);
					ov3640_write_reg(0x80BD,0x13);
					ov3640_write_reg(0x80BE,0xD8);
					ov3640_write_reg(0x80BF,0xF9);
					ov3640_write_reg(0x80C0,0xF5);
					ov3640_write_reg(0x80C1,0x4E);
					ov3640_write_reg(0x80C2,0x8E);
					ov3640_write_reg(0x80C3,0x4D);
					ov3640_write_reg(0x80C4,0xD2);
					ov3640_write_reg(0x80C5,0x09);
					ov3640_write_reg(0x80C6,0xE5);
					ov3640_write_reg(0x80C7,0x43);
					ov3640_write_reg(0x80C8,0xC3);
					ov3640_write_reg(0x80C9,0x95);
					ov3640_write_reg(0x80CA,0x44);
					ov3640_write_reg(0x80CB,0x50);
					ov3640_write_reg(0x80CC,0x1D);
					ov3640_write_reg(0x80CD,0xE5);
					ov3640_write_reg(0x80CE,0x28);
					ov3640_write_reg(0x80CF,0x95);
					ov3640_write_reg(0x80D0,0x4E);
					ov3640_write_reg(0x80D1,0xE5);
					ov3640_write_reg(0x80D2,0x27);
					ov3640_write_reg(0x80D3,0x95);
					ov3640_write_reg(0x80D4,0x4D);
					ov3640_write_reg(0x80D5,0x40);
					ov3640_write_reg(0x80D6,0x0E);
					ov3640_write_reg(0x80D7,0x12);
					ov3640_write_reg(0x80D8,0x05);
					ov3640_write_reg(0x80D9,0xD8);
					ov3640_write_reg(0x80DA,0x40);
					ov3640_write_reg(0x80DB,0x09);
					ov3640_write_reg(0x80DC,0x12);
					ov3640_write_reg(0x80DD,0x05);
					ov3640_write_reg(0x80DE,0xE2);
					ov3640_write_reg(0x80DF,0x85);
					ov3640_write_reg(0x80E0,0x27);
					ov3640_write_reg(0x80E1,0x4F);
					ov3640_write_reg(0x80E2,0x85);
					ov3640_write_reg(0x80E3,0x28);
					ov3640_write_reg(0x80E4,0x50);
					ov3640_write_reg(0x80E5,0x05);
					ov3640_write_reg(0x80E6,0x43);
					ov3640_write_reg(0x80E7,0x02);
					ov3640_write_reg(0x80E8,0x01);
					ov3640_write_reg(0x80E9,0xFB);
					ov3640_write_reg(0x80EA,0xE5);
					ov3640_write_reg(0x80EB,0x43);
					ov3640_write_reg(0x80EC,0xC3);
					ov3640_write_reg(0x80ED,0x95);
					ov3640_write_reg(0x80EE,0x44);
					ov3640_write_reg(0x80EF,0x50);
					ov3640_write_reg(0x80F0,0x03);
					ov3640_write_reg(0x80F1,0x02);
					ov3640_write_reg(0x80F2,0x01);
					ov3640_write_reg(0x80F3,0xFB);
					ov3640_write_reg(0x80F4,0x12);
					ov3640_write_reg(0x80F5,0x05);
					ov3640_write_reg(0x80F6,0xD8);
					ov3640_write_reg(0x80F7,0x40);
					ov3640_write_reg(0x80F8,0x02);
					ov3640_write_reg(0x80F9,0x80);
					ov3640_write_reg(0x80FA,0x12);
					ov3640_write_reg(0x80FB,0xE5);
					ov3640_write_reg(0x80FC,0x50);
					ov3640_write_reg(0x80FD,0x45);
					ov3640_write_reg(0x80FE,0x4F);
					ov3640_write_reg(0x80FF,0x70);
					ov3640_write_reg(0x8100,0x0F);
					ov3640_write_reg(0x8101,0xE5);
					ov3640_write_reg(0x8102,0x59);
					ov3640_write_reg(0x8103,0xC3);
					ov3640_write_reg(0x8104,0x13);
					ov3640_write_reg(0x8105,0xFE);
					ov3640_write_reg(0x8106,0xE5);
					ov3640_write_reg(0x8107,0x5A);
					ov3640_write_reg(0x8108,0x12);
					ov3640_write_reg(0x8109,0x06);
					ov3640_write_reg(0x810A,0x1C);
					ov3640_write_reg(0x810B,0x40);
					ov3640_write_reg(0x810C,0x03);
					ov3640_write_reg(0x810D,0x12);
					ov3640_write_reg(0x810E,0x05);
					ov3640_write_reg(0x810F,0xE2);
					ov3640_write_reg(0x8110,0x90);
					ov3640_write_reg(0x8111,0x3F);
					ov3640_write_reg(0x8112,0x04);
					ov3640_write_reg(0x8113,0xE5);
					ov3640_write_reg(0x8114,0x43);
					ov3640_write_reg(0x8115,0x02);
					ov3640_write_reg(0x8116,0x01);
					ov3640_write_reg(0x8117,0xED);
					ov3640_write_reg(0x8118,0xE5);
					ov3640_write_reg(0x8119,0x72);
					ov3640_write_reg(0x811A,0x64);
					ov3640_write_reg(0x811B,0x02);
					ov3640_write_reg(0x811C,0x60);
					ov3640_write_reg(0x811D,0x03);
					ov3640_write_reg(0x811E,0x02);
					ov3640_write_reg(0x811F,0x01);
					ov3640_write_reg(0x8120,0xFB);
					ov3640_write_reg(0x8121,0x20);
					ov3640_write_reg(0x8122,0x0A);
					ov3640_write_reg(0x8123,0x33);
					ov3640_write_reg(0x8124,0x85);
					ov3640_write_reg(0x8125,0x6E);
					ov3640_write_reg(0x8126,0x70);
					ov3640_write_reg(0x8127,0x85);
					ov3640_write_reg(0x8128,0x6F);
					ov3640_write_reg(0x8129,0x71);
					ov3640_write_reg(0x812A,0x85);
					ov3640_write_reg(0x812B,0x6C);
					ov3640_write_reg(0x812C,0x6E);
					ov3640_write_reg(0x812D,0x85);
					ov3640_write_reg(0x812E,0x6D);
					ov3640_write_reg(0x812F,0x6F);
					ov3640_write_reg(0x8130,0x85);
					ov3640_write_reg(0x8131,0x6A);
					ov3640_write_reg(0x8132,0x6C);
					ov3640_write_reg(0x8133,0x85);
					ov3640_write_reg(0x8134,0x6B);
					ov3640_write_reg(0x8135,0x6D);
					ov3640_write_reg(0x8136,0x85);
					ov3640_write_reg(0x8137,0x68);
					ov3640_write_reg(0x8138,0x6A);
					ov3640_write_reg(0x8139,0x85);
					ov3640_write_reg(0x813A,0x69);
					ov3640_write_reg(0x813B,0x6B);
					ov3640_write_reg(0x813C,0x85);
					ov3640_write_reg(0x813D,0x66);
					ov3640_write_reg(0x813E,0x68);
					ov3640_write_reg(0x813F,0x85);
					ov3640_write_reg(0x8140,0x67);
					ov3640_write_reg(0x8141,0x69);
					ov3640_write_reg(0x8142,0x85);
					ov3640_write_reg(0x8143,0x64);
					ov3640_write_reg(0x8144,0x66);
					ov3640_write_reg(0x8145,0x85);
					ov3640_write_reg(0x8146,0x65);
					ov3640_write_reg(0x8147,0x67);
					ov3640_write_reg(0x8148,0x85);
					ov3640_write_reg(0x8149,0x62);
					ov3640_write_reg(0x814A,0x64);
					ov3640_write_reg(0x814B,0x85);
					ov3640_write_reg(0x814C,0x63);
					ov3640_write_reg(0x814D,0x65);
					ov3640_write_reg(0x814E,0x85);
					ov3640_write_reg(0x814F,0x27);
					ov3640_write_reg(0x8150,0x62);
					ov3640_write_reg(0x8151,0x85);
					ov3640_write_reg(0x8152,0x28);
					ov3640_write_reg(0x8153,0x63);
					ov3640_write_reg(0x8154,0x02);
					ov3640_write_reg(0x8155,0x01);
					ov3640_write_reg(0x8156,0xFB);
					ov3640_write_reg(0x8157,0x20);
					ov3640_write_reg(0x8158,0x0A);
					ov3640_write_reg(0x8159,0x03);
					ov3640_write_reg(0x815A,0x02);
					ov3640_write_reg(0x815B,0x01);
					ov3640_write_reg(0x815C,0xFB);
					ov3640_write_reg(0x815D,0x20);
					ov3640_write_reg(0x815E,0x09);
					ov3640_write_reg(0x815F,0x36);
					ov3640_write_reg(0x8160,0x75);
					ov3640_write_reg(0x8161,0x5F);
					ov3640_write_reg(0x8162,0x00);
					ov3640_write_reg(0x8163,0x75);
					ov3640_write_reg(0x8164,0x60);
					ov3640_write_reg(0x8165,0x00);
					ov3640_write_reg(0x8166,0x75);
					ov3640_write_reg(0x8167,0x5D);
					ov3640_write_reg(0x8168,0xFF);
					ov3640_write_reg(0x8169,0x75);
					ov3640_write_reg(0x816A,0x5E);
					ov3640_write_reg(0x816B,0xFF);
					ov3640_write_reg(0x816C,0x75);
					ov3640_write_reg(0x816D,0x26);
					ov3640_write_reg(0x816E,0x00);
					ov3640_write_reg(0x816F,0x12);
					ov3640_write_reg(0x8170,0x06);
					ov3640_write_reg(0x8171,0x5F);
					ov3640_write_reg(0x8172,0xFF);
					ov3640_write_reg(0x8173,0xC3);
					ov3640_write_reg(0x8174,0xE5);
					ov3640_write_reg(0x8175,0x60);
					ov3640_write_reg(0x8176,0x9F);
					ov3640_write_reg(0x8177,0xE5);
					ov3640_write_reg(0x8178,0x5F);
					ov3640_write_reg(0x8179,0x9E);
					ov3640_write_reg(0x817A,0x50);
					ov3640_write_reg(0x817B,0x04);
					ov3640_write_reg(0x817C,0x8E);
					ov3640_write_reg(0x817D,0x5F);
					ov3640_write_reg(0x817E,0x8F);
					ov3640_write_reg(0x817F,0x60);
					ov3640_write_reg(0x8180,0xD3);
					ov3640_write_reg(0x8181,0xE5);
					ov3640_write_reg(0x8182,0x5E);
					ov3640_write_reg(0x8183,0x9F);
					ov3640_write_reg(0x8184,0xE5);
					ov3640_write_reg(0x8185,0x5D);
					ov3640_write_reg(0x8186,0x9E);
					ov3640_write_reg(0x8187,0x40);
					ov3640_write_reg(0x8188,0x04);
					ov3640_write_reg(0x8189,0x8E);
					ov3640_write_reg(0x818A,0x5D);
					ov3640_write_reg(0x818B,0x8F);
					ov3640_write_reg(0x818C,0x5E);
					ov3640_write_reg(0x818D,0x05);
					ov3640_write_reg(0x818E,0x26);
					ov3640_write_reg(0x818F,0xE5);
					ov3640_write_reg(0x8190,0x26);
					ov3640_write_reg(0x8191,0xB4);
					ov3640_write_reg(0x8192,0x08);
					ov3640_write_reg(0x8193,0xDB);
					ov3640_write_reg(0x8194,0xD2);
					ov3640_write_reg(0x8195,0x09);
					ov3640_write_reg(0x8196,0xE5);
					ov3640_write_reg(0x8197,0x43);
					ov3640_write_reg(0x8198,0xC3);
					ov3640_write_reg(0x8199,0x95);
					ov3640_write_reg(0x819A,0x44);
					ov3640_write_reg(0x819B,0x50);
					ov3640_write_reg(0x819C,0x1E);
					ov3640_write_reg(0x819D,0xE5);
					ov3640_write_reg(0x819E,0x5F);
					ov3640_write_reg(0x819F,0xC3);
					ov3640_write_reg(0x81A0,0x13);
					ov3640_write_reg(0x81A1,0xFE);
					ov3640_write_reg(0x81A2,0xE5);
					ov3640_write_reg(0x81A3,0x60);
					ov3640_write_reg(0x81A4,0x12);
					ov3640_write_reg(0x81A5,0x06);
					ov3640_write_reg(0x81A6,0x1C);
					ov3640_write_reg(0x81A7,0x40);
					ov3640_write_reg(0x81A8,0x0E);
					ov3640_write_reg(0x81A9,0x12);
					ov3640_write_reg(0x81AA,0x05);
					ov3640_write_reg(0x81AB,0xD8);
					ov3640_write_reg(0x81AC,0x40);
					ov3640_write_reg(0x81AD,0x09);
					ov3640_write_reg(0x81AE,0x12);
					ov3640_write_reg(0x81AF,0x05);
					ov3640_write_reg(0x81B0,0xE2);
					ov3640_write_reg(0x81B1,0x85);
					ov3640_write_reg(0x81B2,0x27);
					ov3640_write_reg(0x81B3,0x4F);
					ov3640_write_reg(0x81B4,0x85);
					ov3640_write_reg(0x81B5,0x28);
					ov3640_write_reg(0x81B6,0x50);
					ov3640_write_reg(0x81B7,0x05);
					ov3640_write_reg(0x81B8,0x43);
					ov3640_write_reg(0x81B9,0x80);
					ov3640_write_reg(0x81BA,0x40);
					ov3640_write_reg(0x81BB,0xE5);
					ov3640_write_reg(0x81BC,0x43);
					ov3640_write_reg(0x81BD,0xC3);
					ov3640_write_reg(0x81BE,0x95);
					ov3640_write_reg(0x81BF,0x44);
					ov3640_write_reg(0x81C0,0x40);
					ov3640_write_reg(0x81C1,0x39);
					ov3640_write_reg(0x81C2,0x12);
					ov3640_write_reg(0x81C3,0x05);
					ov3640_write_reg(0x81C4,0xD8);
					ov3640_write_reg(0x81C5,0x40);
					ov3640_write_reg(0x81C6,0x02);
					ov3640_write_reg(0x81C7,0x80);
					ov3640_write_reg(0x81C8,0x1A);
					ov3640_write_reg(0x81C9,0xE5);
					ov3640_write_reg(0x81CA,0x50);
					ov3640_write_reg(0x81CB,0x45);
					ov3640_write_reg(0x81CC,0x4F);
					ov3640_write_reg(0x81CD,0x70);
					ov3640_write_reg(0x81CE,0x17);
					ov3640_write_reg(0x81CF,0xAE);
					ov3640_write_reg(0x81D0,0x5D);
					ov3640_write_reg(0x81D1,0xAF);
					ov3640_write_reg(0x81D2,0x5E);
					ov3640_write_reg(0x81D3,0xFC);
					ov3640_write_reg(0x81D4,0x7D);
					ov3640_write_reg(0x81D5,0x03);
					ov3640_write_reg(0x81D6,0x12);
					ov3640_write_reg(0x81D7,0x0C);
					ov3640_write_reg(0x81D8,0xC8);
					ov3640_write_reg(0x81D9,0xEE);
					ov3640_write_reg(0x81DA,0xC3);
					ov3640_write_reg(0x81DB,0x13);
					ov3640_write_reg(0x81DC,0xFE);
					ov3640_write_reg(0x81DD,0xEF);
					ov3640_write_reg(0x81DE,0x12);
					ov3640_write_reg(0x81DF,0x06);
					ov3640_write_reg(0x81E0,0x1C);
					ov3640_write_reg(0x81E1,0x40);
					ov3640_write_reg(0x81E2,0x03);
					ov3640_write_reg(0x81E3,0x12);
					ov3640_write_reg(0x81E4,0x05);
					ov3640_write_reg(0x81E5,0xE2);
					ov3640_write_reg(0x81E6,0xE5);
					ov3640_write_reg(0x81E7,0x43);
					ov3640_write_reg(0x81E8,0x44);
					ov3640_write_reg(0x81E9,0x10);
					ov3640_write_reg(0x81EA,0x90);
					ov3640_write_reg(0x81EB,0x3F);
					ov3640_write_reg(0x81EC,0x04);
					ov3640_write_reg(0x81ED,0xF0);
					ov3640_write_reg(0x81EE,0x75);
					ov3640_write_reg(0x81EF,0x4F);
					ov3640_write_reg(0x81F0,0x00);
					ov3640_write_reg(0x81F1,0x75);
					ov3640_write_reg(0x81F2,0x50);
					ov3640_write_reg(0x81F3,0x00);
					ov3640_write_reg(0x81F4,0x75);
					ov3640_write_reg(0x81F5,0x43);
					ov3640_write_reg(0x81F6,0x00);
					ov3640_write_reg(0x81F7,0xC2);
					ov3640_write_reg(0x81F8,0x0A);
					ov3640_write_reg(0x81F9,0xC2);
					ov3640_write_reg(0x81FA,0x09);
					ov3640_write_reg(0x81FB,0x90);
					ov3640_write_reg(0x81FC,0x37);
					ov3640_write_reg(0x81FD,0x08);
					ov3640_write_reg(0x81FE,0x74);
					ov3640_write_reg(0x81FF,0x08);
					ov3640_write_reg(0x8200,0xF0);
					ov3640_write_reg(0x8201,0xD2);
					ov3640_write_reg(0x8202,0x08);
					ov3640_write_reg(0x8203,0x80);
					ov3640_write_reg(0x8204,0x5A);
					ov3640_write_reg(0x8205,0x90);
					ov3640_write_reg(0x8206,0x37);
					ov3640_write_reg(0x8207,0x08);
					ov3640_write_reg(0x8208,0xE0);
					ov3640_write_reg(0x8209,0x30);
					ov3640_write_reg(0x820A,0xE6);
					ov3640_write_reg(0x820B,0x5A);
					ov3640_write_reg(0x820C,0x30);
					ov3640_write_reg(0x820D,0x0A);
					ov3640_write_reg(0x820E,0x07);
					ov3640_write_reg(0x820F,0x90);
					ov3640_write_reg(0x8210,0x30);
					ov3640_write_reg(0x8211,0xB4);
					ov3640_write_reg(0x8212,0xE0);
					ov3640_write_reg(0x8213,0x44);
					ov3640_write_reg(0x8214,0x08);
					ov3640_write_reg(0x8215,0xF0);
					ov3640_write_reg(0x8216,0x90);
					ov3640_write_reg(0x8217,0x38);
					ov3640_write_reg(0x8218,0x02);
					ov3640_write_reg(0x8219,0xE0);
					ov3640_write_reg(0x821A,0xF5);
					ov3640_write_reg(0x821B,0x25);
					ov3640_write_reg(0x821C,0x30);
					ov3640_write_reg(0x821D,0xE3);
					ov3640_write_reg(0x821E,0x06);
					ov3640_write_reg(0x821F,0xA3);
					ov3640_write_reg(0x8220,0x74);
					ov3640_write_reg(0x8221,0xD9);
					ov3640_write_reg(0x8222,0xF0);
					ov3640_write_reg(0x8223,0x80);
					ov3640_write_reg(0x8224,0x03);
					ov3640_write_reg(0x8225,0x90);
					ov3640_write_reg(0x8226,0x38);
					ov3640_write_reg(0x8227,0x03);
					ov3640_write_reg(0x8228,0xE5);
					ov3640_write_reg(0x8229,0x45);
					ov3640_write_reg(0x822A,0xF0);
					ov3640_write_reg(0x822B,0xE5);
					ov3640_write_reg(0x822C,0x51);
					ov3640_write_reg(0x822D,0xF0);
					ov3640_write_reg(0x822E,0xE5);
					ov3640_write_reg(0x822F,0x53);
					ov3640_write_reg(0x8230,0xF0);
					ov3640_write_reg(0x8231,0xE5);
					ov3640_write_reg(0x8232,0x55);
					ov3640_write_reg(0x8233,0xF0);
					ov3640_write_reg(0x8234,0xE5);
					ov3640_write_reg(0x8235,0x57);
					ov3640_write_reg(0x8236,0xF0);
					ov3640_write_reg(0x8237,0xE5);
					ov3640_write_reg(0x8238,0x52);
					ov3640_write_reg(0x8239,0xF0);
					ov3640_write_reg(0x823A,0xE5);
					ov3640_write_reg(0x823B,0x54);
					ov3640_write_reg(0x823C,0xF0);
					ov3640_write_reg(0x823D,0xE5);
					ov3640_write_reg(0x823E,0x56);
					ov3640_write_reg(0x823F,0xF0);
					ov3640_write_reg(0x8240,0xE5);
					ov3640_write_reg(0x8241,0x58);
					ov3640_write_reg(0x8242,0xF0);
					ov3640_write_reg(0x8243,0xE5);
					ov3640_write_reg(0x8244,0x61);
					ov3640_write_reg(0x8245,0xF0);
					ov3640_write_reg(0x8246,0xE5);
					ov3640_write_reg(0x8247,0x5B);
					ov3640_write_reg(0x8248,0xF0);
					ov3640_write_reg(0x8249,0xE5);
					ov3640_write_reg(0x824A,0x5C);
					ov3640_write_reg(0x824B,0xF0);
					ov3640_write_reg(0x824C,0x74);
					ov3640_write_reg(0x824D,0x88);
					ov3640_write_reg(0x824E,0xF0);
					ov3640_write_reg(0x824F,0xF0);
					ov3640_write_reg(0x8250,0x75);
					ov3640_write_reg(0x8251,0x61);
					ov3640_write_reg(0x8252,0x00);
					ov3640_write_reg(0x8253,0x90);
					ov3640_write_reg(0x8254,0x38);
					ov3640_write_reg(0x8255,0x02);
					ov3640_write_reg(0x8256,0x74);
					ov3640_write_reg(0x8257,0x02);
					ov3640_write_reg(0x8258,0xF0);
					ov3640_write_reg(0x8259,0x90);
					ov3640_write_reg(0x825A,0x37);
					ov3640_write_reg(0x825B,0x08);
					ov3640_write_reg(0x825C,0x74);
					ov3640_write_reg(0x825D,0x40);
					ov3640_write_reg(0x825E,0xF0);
					ov3640_write_reg(0x825F,0x90);
					ov3640_write_reg(0x8260,0x30);
					ov3640_write_reg(0x8261,0xB4);
					ov3640_write_reg(0x8262,0xE0);
					ov3640_write_reg(0x8263,0x54);
					ov3640_write_reg(0x8264,0xF7);
					ov3640_write_reg(0x8265,0xF0);
					ov3640_write_reg(0x8266,0xD0);
					ov3640_write_reg(0x8267,0x07);
					ov3640_write_reg(0x8268,0xD0);
					ov3640_write_reg(0x8269,0x06);
					ov3640_write_reg(0x826A,0xD0);
					ov3640_write_reg(0x826B,0x05);
					ov3640_write_reg(0x826C,0xD0);
					ov3640_write_reg(0x826D,0x04);
					ov3640_write_reg(0x826E,0xD0);
					ov3640_write_reg(0x826F,0x00);
					ov3640_write_reg(0x8270,0xD0);
					ov3640_write_reg(0x8271,0xD0);
					ov3640_write_reg(0x8272,0xD0);
					ov3640_write_reg(0x8273,0x82);
					ov3640_write_reg(0x8274,0xD0);
					ov3640_write_reg(0x8275,0x83);
					ov3640_write_reg(0x8276,0xD0);
					ov3640_write_reg(0x8277,0xF0);
					ov3640_write_reg(0x8278,0xD0);
					ov3640_write_reg(0x8279,0xE0);
					ov3640_write_reg(0x827A,0x32);
					ov3640_write_reg(0x827B,0xE5);
					ov3640_write_reg(0x827C,0x2F);
					ov3640_write_reg(0x827D,0x14);
					ov3640_write_reg(0x827E,0x60);
					ov3640_write_reg(0x827F,0x57);
					ov3640_write_reg(0x8280,0x14);
					ov3640_write_reg(0x8281,0x70);
					ov3640_write_reg(0x8282,0x03);
					ov3640_write_reg(0x8283,0x02);
					ov3640_write_reg(0x8284,0x03);
					ov3640_write_reg(0x8285,0x27);
					ov3640_write_reg(0x8286,0x14);
					ov3640_write_reg(0x8287,0x70);
					ov3640_write_reg(0x8288,0x03);
					ov3640_write_reg(0x8289,0x02);
					ov3640_write_reg(0x828A,0x03);
					ov3640_write_reg(0x828B,0x69);
					ov3640_write_reg(0x828C,0x14);
					ov3640_write_reg(0x828D,0x70);
					ov3640_write_reg(0x828E,0x03);
					ov3640_write_reg(0x828F,0x02);
					ov3640_write_reg(0x8290,0x03);
					ov3640_write_reg(0x8291,0xD8);
					ov3640_write_reg(0x8292,0x24);
					ov3640_write_reg(0x8293,0x04);
					ov3640_write_reg(0x8294,0x60);
					ov3640_write_reg(0x8295,0x03);
					ov3640_write_reg(0x8296,0x02);
					ov3640_write_reg(0x8297,0x03);
					ov3640_write_reg(0x8298,0xEF);
					ov3640_write_reg(0x8299,0xE4);
					ov3640_write_reg(0x829A,0xFD);
					ov3640_write_reg(0x829B,0xFF);
					ov3640_write_reg(0x829C,0x12);
					ov3640_write_reg(0x829D,0x0B);
					ov3640_write_reg(0x829E,0x2C);
					ov3640_write_reg(0x829F,0x8E);
					ov3640_write_reg(0x82A0,0x30);
					ov3640_write_reg(0x82A1,0x8F);
					ov3640_write_reg(0x82A2,0x31);
					ov3640_write_reg(0x82A3,0x0D);
					ov3640_write_reg(0x82A4,0xE4);
					ov3640_write_reg(0x82A5,0xFF);
					ov3640_write_reg(0x82A6,0x12);
					ov3640_write_reg(0x82A7,0x0B);
					ov3640_write_reg(0x82A8,0x2C);
					ov3640_write_reg(0x82A9,0x8E);
					ov3640_write_reg(0x82AA,0x34);
					ov3640_write_reg(0x82AB,0x8F);
					ov3640_write_reg(0x82AC,0x35);
					ov3640_write_reg(0x82AD,0x12);
					ov3640_write_reg(0x82AE,0x05);
					ov3640_write_reg(0x82AF,0xAE);
					ov3640_write_reg(0x82B0,0x50);
					ov3640_write_reg(0x82B1,0x08);
					ov3640_write_reg(0x82B2,0x75);
					ov3640_write_reg(0x82B3,0x2E);
					ov3640_write_reg(0x82B4,0x01);
					ov3640_write_reg(0x82B5,0x75);
					ov3640_write_reg(0x82B6,0x2F);
					ov3640_write_reg(0x82B7,0x01);
					ov3640_write_reg(0x82B8,0x80);
					ov3640_write_reg(0x82B9,0x06);
					ov3640_write_reg(0x82BA,0x75);
					ov3640_write_reg(0x82BB,0x2E);
					ov3640_write_reg(0x82BC,0xFF);
					ov3640_write_reg(0x82BD,0x75);
					ov3640_write_reg(0x82BE,0x2F);
					ov3640_write_reg(0x82BF,0x03);
					ov3640_write_reg(0x82C0,0x12);
					ov3640_write_reg(0x82C1,0x03);
					ov3640_write_reg(0x82C2,0xF8);
					ov3640_write_reg(0x82C3,0x90);
					ov3640_write_reg(0x82C4,0x33);
					ov3640_write_reg(0x82C5,0xB3);
					ov3640_write_reg(0x82C6,0x74);
					ov3640_write_reg(0x82C7,0x80);
					ov3640_write_reg(0x82C8,0xF0);
					ov3640_write_reg(0x82C9,0xA3);
					ov3640_write_reg(0x82CA,0x74);
					ov3640_write_reg(0x82CB,0x2A);
					ov3640_write_reg(0x82CC,0xF0);
					ov3640_write_reg(0x82CD,0xA3);
					ov3640_write_reg(0x82CE,0x74);
					ov3640_write_reg(0x82CF,0x14);
					ov3640_write_reg(0x82D0,0xF0);
					ov3640_write_reg(0x82D1,0xA3);
					ov3640_write_reg(0x82D2,0xE4);
					ov3640_write_reg(0x82D3,0xF0);
					ov3640_write_reg(0x82D4,0x02);
					ov3640_write_reg(0x82D5,0x03);
					ov3640_write_reg(0x82D6,0xEF);
					ov3640_write_reg(0x82D7,0x12);
					ov3640_write_reg(0x82D8,0x04);
					ov3640_write_reg(0x82D9,0x44);
					ov3640_write_reg(0x82DA,0xC0);
					ov3640_write_reg(0x82DB,0x06);
					ov3640_write_reg(0x82DC,0xC0);
					ov3640_write_reg(0x82DD,0x07);
					ov3640_write_reg(0x82DE,0x12);
					ov3640_write_reg(0x82DF,0x04);
					ov3640_write_reg(0x82E0,0x88);
					ov3640_write_reg(0x82E1,0xD0);
					ov3640_write_reg(0x82E2,0x05);
					ov3640_write_reg(0x82E3,0xD0);
					ov3640_write_reg(0x82E4,0x04);
					ov3640_write_reg(0x82E5,0x12);
					ov3640_write_reg(0x82E6,0x06);
					ov3640_write_reg(0x82E7,0x10);
					ov3640_write_reg(0x82E8,0x40);
					ov3640_write_reg(0x82E9,0x05);
					ov3640_write_reg(0x82EA,0x12);
					ov3640_write_reg(0x82EB,0x05);
					ov3640_write_reg(0x82EC,0xF6);
					ov3640_write_reg(0x82ED,0x80);
					ov3640_write_reg(0x82EE,0x03);
					ov3640_write_reg(0x82EF,0x12);
					ov3640_write_reg(0x82F0,0x06);
					ov3640_write_reg(0x82F1,0x03);
					ov3640_write_reg(0x82F2,0x12);
					ov3640_write_reg(0x82F3,0x06);
					ov3640_write_reg(0x82F4,0x26);
					ov3640_write_reg(0x82F5,0x40);
					ov3640_write_reg(0x82F6,0x11);
					ov3640_write_reg(0x82F7,0x12);
					ov3640_write_reg(0x82F8,0x05);
					ov3640_write_reg(0x82F9,0xAE);
					ov3640_write_reg(0x82FA,0x50);
					ov3640_write_reg(0x82FB,0x09);
					ov3640_write_reg(0x82FC,0x12);
					ov3640_write_reg(0x82FD,0x03);
					ov3640_write_reg(0x82FE,0xF8);
					ov3640_write_reg(0x82FF,0x75);
					ov3640_write_reg(0x8300,0x2F);
					ov3640_write_reg(0x8301,0x02);
					ov3640_write_reg(0x8302,0x02);
					ov3640_write_reg(0x8303,0x03);
					ov3640_write_reg(0x8304,0xB8);
					ov3640_write_reg(0x8305,0x02);
					ov3640_write_reg(0x8306,0x03);
					ov3640_write_reg(0x8307,0xD3);
					ov3640_write_reg(0x8308,0x75);
					ov3640_write_reg(0x8309,0x2E);
					ov3640_write_reg(0x830A,0xFF);
					ov3640_write_reg(0x830B,0xD3);
					ov3640_write_reg(0x830C,0xE5);
					ov3640_write_reg(0x830D,0x4C);
					ov3640_write_reg(0x830E,0x94);
					ov3640_write_reg(0x830F,0x28);
					ov3640_write_reg(0x8310,0xE5);
					ov3640_write_reg(0x8311,0x4B);
					ov3640_write_reg(0x8312,0x94);
					ov3640_write_reg(0x8313,0x00);
					ov3640_write_reg(0x8314,0xAF);
					ov3640_write_reg(0x8315,0x2E);
					ov3640_write_reg(0x8316,0xEF);
					ov3640_write_reg(0x8317,0x40);
					ov3640_write_reg(0x8318,0x0B);
					ov3640_write_reg(0x8319,0x7D);
					ov3640_write_reg(0x831A,0x50);
					ov3640_write_reg(0x831B,0x12);
					ov3640_write_reg(0x831C,0x04);
					ov3640_write_reg(0x831D,0x67);
					ov3640_write_reg(0x831E,0x75);
					ov3640_write_reg(0x831F,0x2F);
					ov3640_write_reg(0x8320,0x03);
					ov3640_write_reg(0x8321,0x02);
					ov3640_write_reg(0x8322,0x03);
					ov3640_write_reg(0x8323,0xB8);
					ov3640_write_reg(0x8324,0x02);
					ov3640_write_reg(0x8325,0x03);
					ov3640_write_reg(0x8326,0xCE);
					ov3640_write_reg(0x8327,0x12);
					ov3640_write_reg(0x8328,0x04);
					ov3640_write_reg(0x8329,0x44);
					ov3640_write_reg(0x832A,0xC0);
					ov3640_write_reg(0x832B,0x06);
					ov3640_write_reg(0x832C,0xC0);
					ov3640_write_reg(0x832D,0x07);
					ov3640_write_reg(0x832E,0xC3);
					ov3640_write_reg(0x832F,0xE5);
					ov3640_write_reg(0x8330,0x39);
					ov3640_write_reg(0x8331,0x95);
					ov3640_write_reg(0x8332,0x31);
					ov3640_write_reg(0x8333,0xFF);
					ov3640_write_reg(0x8334,0xE5);
					ov3640_write_reg(0x8335,0x38);
					ov3640_write_reg(0x8336,0x95);
					ov3640_write_reg(0x8337,0x30);
					ov3640_write_reg(0x8338,0xFE);
					ov3640_write_reg(0x8339,0x12);
					ov3640_write_reg(0x833A,0x0C);
					ov3640_write_reg(0x833B,0xF7);
					ov3640_write_reg(0x833C,0xD0);
					ov3640_write_reg(0x833D,0x05);
					ov3640_write_reg(0x833E,0xD0);
					ov3640_write_reg(0x833F,0x04);
					ov3640_write_reg(0x8340,0x12);
					ov3640_write_reg(0x8341,0x06);
					ov3640_write_reg(0x8342,0x10);
					ov3640_write_reg(0x8343,0x40);
					ov3640_write_reg(0x8344,0x05);
					ov3640_write_reg(0x8345,0x12);
					ov3640_write_reg(0x8346,0x05);
					ov3640_write_reg(0x8347,0xF6);
					ov3640_write_reg(0x8348,0x80);
					ov3640_write_reg(0x8349,0x03);
					ov3640_write_reg(0x834A,0x12);
					ov3640_write_reg(0x834B,0x06);
					ov3640_write_reg(0x834C,0x03);
					ov3640_write_reg(0x834D,0x12);
					ov3640_write_reg(0x834E,0x06);
					ov3640_write_reg(0x834F,0x26);
					ov3640_write_reg(0x8350,0x40);
					ov3640_write_reg(0x8351,0x0E);
					ov3640_write_reg(0x8352,0x12);
					ov3640_write_reg(0x8353,0x05);
					ov3640_write_reg(0x8354,0xAE);
					ov3640_write_reg(0x8355,0x50);
					ov3640_write_reg(0x8356,0x06);
					ov3640_write_reg(0x8357,0x12);
					ov3640_write_reg(0x8358,0x04);
					ov3640_write_reg(0x8359,0x1E);
					ov3640_write_reg(0x835A,0x02);
					ov3640_write_reg(0x835B,0x03);
					ov3640_write_reg(0x835C,0xB8);
					ov3640_write_reg(0x835D,0x02);
					ov3640_write_reg(0x835E,0x03);
					ov3640_write_reg(0x835F,0xD3);
					ov3640_write_reg(0x8360,0x75);
					ov3640_write_reg(0x8361,0x2E);
					ov3640_write_reg(0x8362,0xFF);
					ov3640_write_reg(0x8363,0xAF);
					ov3640_write_reg(0x8364,0x2E);
					ov3640_write_reg(0x8365,0xEF);
					ov3640_write_reg(0x8366,0x02);
					ov3640_write_reg(0x8367,0x03);
					ov3640_write_reg(0x8368,0xCE);
					ov3640_write_reg(0x8369,0xE4);
					ov3640_write_reg(0x836A,0xFD);
					ov3640_write_reg(0x836B,0xFF);
					ov3640_write_reg(0x836C,0x12);
					ov3640_write_reg(0x836D,0x0B);
					ov3640_write_reg(0x836E,0x2C);
					ov3640_write_reg(0x836F,0x8E);
					ov3640_write_reg(0x8370,0x32);
					ov3640_write_reg(0x8371,0x8F);
					ov3640_write_reg(0x8372,0x33);
					ov3640_write_reg(0x8373,0x0D);
					ov3640_write_reg(0x8374,0xE4);
					ov3640_write_reg(0x8375,0xFF);
					ov3640_write_reg(0x8376,0x12);
					ov3640_write_reg(0x8377,0x0B);
					ov3640_write_reg(0x8378,0x2C);
					ov3640_write_reg(0x8379,0x8E);
					ov3640_write_reg(0x837A,0x36);
					ov3640_write_reg(0x837B,0x8F);
					ov3640_write_reg(0x837C,0x37);
					ov3640_write_reg(0x837D,0xC3);
					ov3640_write_reg(0x837E,0xE5);
					ov3640_write_reg(0x837F,0x37);
					ov3640_write_reg(0x8380,0x95);
					ov3640_write_reg(0x8381,0x35);
					ov3640_write_reg(0x8382,0xFF);
					ov3640_write_reg(0x8383,0xE5);
					ov3640_write_reg(0x8384,0x36);
					ov3640_write_reg(0x8385,0x95);
					ov3640_write_reg(0x8386,0x34);
					ov3640_write_reg(0x8387,0xFE);
					ov3640_write_reg(0x8388,0x12);
					ov3640_write_reg(0x8389,0x0C);
					ov3640_write_reg(0x838A,0xF7);
					ov3640_write_reg(0x838B,0xC0);
					ov3640_write_reg(0x838C,0x06);
					ov3640_write_reg(0x838D,0xC0);
					ov3640_write_reg(0x838E,0x07);
					ov3640_write_reg(0x838F,0x12);
					ov3640_write_reg(0x8390,0x04);
					ov3640_write_reg(0x8391,0x88);
					ov3640_write_reg(0x8392,0xD0);
					ov3640_write_reg(0x8393,0x05);
					ov3640_write_reg(0x8394,0xD0);
					ov3640_write_reg(0x8395,0x04);
					ov3640_write_reg(0x8396,0xC3);
					ov3640_write_reg(0x8397,0x12);
					ov3640_write_reg(0x8398,0x06);
					ov3640_write_reg(0x8399,0x11);
					ov3640_write_reg(0x839A,0x40);
					ov3640_write_reg(0x839B,0x05);
					ov3640_write_reg(0x839C,0x12);
					ov3640_write_reg(0x839D,0x05);
					ov3640_write_reg(0x839E,0xF6);
					ov3640_write_reg(0x839F,0x80);
					ov3640_write_reg(0x83A0,0x03);
					ov3640_write_reg(0x83A1,0x12);
					ov3640_write_reg(0x83A2,0x06);
					ov3640_write_reg(0x83A3,0x03);
					ov3640_write_reg(0x83A4,0xC3);
					ov3640_write_reg(0x83A5,0x12);
					ov3640_write_reg(0x83A6,0x06);
					ov3640_write_reg(0x83A7,0x27);
					ov3640_write_reg(0x83A8,0x40);
					ov3640_write_reg(0x83A9,0x1E);
					ov3640_write_reg(0x83AA,0xD3);
					ov3640_write_reg(0x83AB,0xE5);
					ov3640_write_reg(0x83AC,0x4C);
					ov3640_write_reg(0x83AD,0x94);
					ov3640_write_reg(0x83AE,0x00);
					ov3640_write_reg(0x83AF,0xE5);
					ov3640_write_reg(0x83B0,0x4B);
					ov3640_write_reg(0x83B1,0x94);
					ov3640_write_reg(0x83B2,0x00);
					ov3640_write_reg(0x83B3,0x40);
					ov3640_write_reg(0x83B4,0x11);
					ov3640_write_reg(0x83B5,0x12);
					ov3640_write_reg(0x83B6,0x04);
					ov3640_write_reg(0x83B7,0x1E);
					ov3640_write_reg(0x83B8,0x85);
					ov3640_write_reg(0x83B9,0x32);
					ov3640_write_reg(0x83BA,0x30);
					ov3640_write_reg(0x83BB,0x85);
					ov3640_write_reg(0x83BC,0x33);
					ov3640_write_reg(0x83BD,0x31);
					ov3640_write_reg(0x83BE,0x85);
					ov3640_write_reg(0x83BF,0x36);
					ov3640_write_reg(0x83C0,0x34);
					ov3640_write_reg(0x83C1,0x85);
					ov3640_write_reg(0x83C2,0x37);
					ov3640_write_reg(0x83C3,0x35);
					ov3640_write_reg(0x83C4,0x80);
					ov3640_write_reg(0x83C5,0x29);
					ov3640_write_reg(0x83C6,0x80);
					ov3640_write_reg(0x83C7,0x0B);
					ov3640_write_reg(0x83C8,0x75);
					ov3640_write_reg(0x83C9,0x2E);
					ov3640_write_reg(0x83CA,0x01);
					ov3640_write_reg(0x83CB,0xAF);
					ov3640_write_reg(0x83CC,0x2E);
					ov3640_write_reg(0x83CD,0xEF);
					ov3640_write_reg(0x83CE,0x7D);
					ov3640_write_reg(0x83CF,0x28);
					ov3640_write_reg(0x83D0,0x12);
					ov3640_write_reg(0x83D1,0x04);
					ov3640_write_reg(0x83D2,0x67);
					ov3640_write_reg(0x83D3,0x75);
					ov3640_write_reg(0x83D4,0x2F);
					ov3640_write_reg(0x83D5,0x04);
					ov3640_write_reg(0x83D6,0x80);
					ov3640_write_reg(0x83D7,0x17);
					ov3640_write_reg(0x83D8,0x90);
					ov3640_write_reg(0x83D9,0x33);
					ov3640_write_reg(0x83DA,0xB3);
					ov3640_write_reg(0x83DB,0x12);
					ov3640_write_reg(0x83DC,0x06);
					ov3640_write_reg(0x83DD,0x30);
					ov3640_write_reg(0x83DE,0xE5);
					ov3640_write_reg(0x83DF,0x4C);
					ov3640_write_reg(0x83E0,0x45);
					ov3640_write_reg(0x83E1,0x4B);
					ov3640_write_reg(0x83E2,0x70);
					ov3640_write_reg(0x83E3,0x05);
					ov3640_write_reg(0x83E4,0xFF);
					ov3640_write_reg(0x83E5,0xFE);
					ov3640_write_reg(0x83E6,0x12);
					ov3640_write_reg(0x83E7,0x0B);
					ov3640_write_reg(0x83E8,0x7A);
					ov3640_write_reg(0x83E9,0xE4);
					ov3640_write_reg(0x83EA,0xF5);
					ov3640_write_reg(0x83EB,0x2F);
					ov3640_write_reg(0x83EC,0x75);
					ov3640_write_reg(0x83ED,0x3C);
					ov3640_write_reg(0x83EE,0x04);
					ov3640_write_reg(0x83EF,0x90);
					ov3640_write_reg(0x83F0,0x3F);
					ov3640_write_reg(0x83F1,0x03);
					ov3640_write_reg(0x83F2,0xE0);
					ov3640_write_reg(0x83F3,0x04);
					ov3640_write_reg(0x83F4,0xF0);
					ov3640_write_reg(0x83F5,0xC2);
					ov3640_write_reg(0x83F6,0x08);
					ov3640_write_reg(0x83F7,0x22);
					ov3640_write_reg(0x83F8,0xAF);
					ov3640_write_reg(0x83F9,0x2E);
					ov3640_write_reg(0x83FA,0xEF);
					ov3640_write_reg(0x83FB,0x33);
					ov3640_write_reg(0x83FC,0x95);
					ov3640_write_reg(0x83FD,0xE0);
					ov3640_write_reg(0x83FE,0xFE);
					ov3640_write_reg(0x83FF,0x7C);
					ov3640_write_reg(0x8400,0x00);
					ov3640_write_reg(0x8401,0x7D);
					ov3640_write_reg(0x8402,0x28);
					ov3640_write_reg(0x8403,0x12);
					ov3640_write_reg(0x8404,0x0C);
					ov3640_write_reg(0x8405,0xC8);
					ov3640_write_reg(0x8406,0xEF);
					ov3640_write_reg(0x8407,0x25);
					ov3640_write_reg(0x8408,0x4C);
					ov3640_write_reg(0x8409,0xF5);
					ov3640_write_reg(0x840A,0x4C);
					ov3640_write_reg(0x840B,0xEE);
					ov3640_write_reg(0x840C,0x35);
					ov3640_write_reg(0x840D,0x4B);
					ov3640_write_reg(0x840E,0xF5);
					ov3640_write_reg(0x840F,0x4B);
					ov3640_write_reg(0x8410,0xE5);
					ov3640_write_reg(0x8411,0x4C);
					ov3640_write_reg(0x8412,0x25);
					ov3640_write_reg(0x8413,0x3E);
					ov3640_write_reg(0x8414,0xFF);
					ov3640_write_reg(0x8415,0xE5);
					ov3640_write_reg(0x8416,0x4B);
					ov3640_write_reg(0x8417,0x35);
					ov3640_write_reg(0x8418,0x3D);
					ov3640_write_reg(0x8419,0xFE);
					ov3640_write_reg(0x841A,0x12);
					ov3640_write_reg(0x841B,0x0B);
					ov3640_write_reg(0x841C,0x7A);
					ov3640_write_reg(0x841D,0x22);
					ov3640_write_reg(0x841E,0xAF);
					ov3640_write_reg(0x841F,0x2E);
					ov3640_write_reg(0x8420,0xEF);
					ov3640_write_reg(0x8421,0x33);
					ov3640_write_reg(0x8422,0x95);
					ov3640_write_reg(0x8423,0xE0);
					ov3640_write_reg(0x8424,0xFE);
					ov3640_write_reg(0x8425,0x7C);
					ov3640_write_reg(0x8426,0x00);
					ov3640_write_reg(0x8427,0x7D);
					ov3640_write_reg(0x8428,0x28);
					ov3640_write_reg(0x8429,0x12);
					ov3640_write_reg(0x842A,0x0C);
					ov3640_write_reg(0x842B,0xC8);
					ov3640_write_reg(0x842C,0xEF);
					ov3640_write_reg(0x842D,0x25);
					ov3640_write_reg(0x842E,0x4C);
					ov3640_write_reg(0x842F,0xF5);
					ov3640_write_reg(0x8430,0x4C);
					ov3640_write_reg(0x8431,0xEE);
					ov3640_write_reg(0x8432,0x35);
					ov3640_write_reg(0x8433,0x4B);
					ov3640_write_reg(0x8434,0xF5);
					ov3640_write_reg(0x8435,0x4B);
					ov3640_write_reg(0x8436,0xE5);
					ov3640_write_reg(0x8437,0x4C);
					ov3640_write_reg(0x8438,0x25);
					ov3640_write_reg(0x8439,0x3E);
					ov3640_write_reg(0x843A,0xFF);
					ov3640_write_reg(0x843B,0xE5);
					ov3640_write_reg(0x843C,0x4B);
					ov3640_write_reg(0x843D,0x35);
					ov3640_write_reg(0x843E,0x3D);
					ov3640_write_reg(0x843F,0xFE);
					ov3640_write_reg(0x8440,0x12);
					ov3640_write_reg(0x8441,0x0B);
					ov3640_write_reg(0x8442,0x7A);
					ov3640_write_reg(0x8443,0x22);
					ov3640_write_reg(0x8444,0xE4);
					ov3640_write_reg(0x8445,0xFD);
					ov3640_write_reg(0x8446,0xFF);
					ov3640_write_reg(0x8447,0x12);
					ov3640_write_reg(0x8448,0x0B);
					ov3640_write_reg(0x8449,0x2C);
					ov3640_write_reg(0x844A,0x8E);
					ov3640_write_reg(0x844B,0x32);
					ov3640_write_reg(0x844C,0x8F);
					ov3640_write_reg(0x844D,0x33);
					ov3640_write_reg(0x844E,0x0D);
					ov3640_write_reg(0x844F,0xE4);
					ov3640_write_reg(0x8450,0xFF);
					ov3640_write_reg(0x8451,0x12);
					ov3640_write_reg(0x8452,0x0B);
					ov3640_write_reg(0x8453,0x2C);
					ov3640_write_reg(0x8454,0x8E);
					ov3640_write_reg(0x8455,0x36);
					ov3640_write_reg(0x8456,0x8F);
					ov3640_write_reg(0x8457,0x37);
					ov3640_write_reg(0x8458,0xC3);
					ov3640_write_reg(0x8459,0xE5);
					ov3640_write_reg(0x845A,0x37);
					ov3640_write_reg(0x845B,0x95);
					ov3640_write_reg(0x845C,0x35);
					ov3640_write_reg(0x845D,0xFF);
					ov3640_write_reg(0x845E,0xE5);
					ov3640_write_reg(0x845F,0x36);
					ov3640_write_reg(0x8460,0x95);
					ov3640_write_reg(0x8461,0x34);
					ov3640_write_reg(0x8462,0xFE);
					ov3640_write_reg(0x8463,0x12);
					ov3640_write_reg(0x8464,0x0C);
					ov3640_write_reg(0x8465,0xF7);
					ov3640_write_reg(0x8466,0x22);
					ov3640_write_reg(0x8467,0x33);
					ov3640_write_reg(0x8468,0x95);
					ov3640_write_reg(0x8469,0xE0);
					ov3640_write_reg(0x846A,0xFE);
					ov3640_write_reg(0x846B,0x7C);
					ov3640_write_reg(0x846C,0x00);
					ov3640_write_reg(0x846D,0x12);
					ov3640_write_reg(0x846E,0x0C);
					ov3640_write_reg(0x846F,0xC8);
					ov3640_write_reg(0x8470,0xEF);
					ov3640_write_reg(0x8471,0x25);
					ov3640_write_reg(0x8472,0x4C);
					ov3640_write_reg(0x8473,0xF5);
					ov3640_write_reg(0x8474,0x4C);
					ov3640_write_reg(0x8475,0xEE);
					ov3640_write_reg(0x8476,0x35);
					ov3640_write_reg(0x8477,0x4B);
					ov3640_write_reg(0x8478,0xF5);
					ov3640_write_reg(0x8479,0x4B);
					ov3640_write_reg(0x847A,0xE5);
					ov3640_write_reg(0x847B,0x4C);
					ov3640_write_reg(0x847C,0x25);
					ov3640_write_reg(0x847D,0x3E);
					ov3640_write_reg(0x847E,0xFF);
					ov3640_write_reg(0x847F,0xE5);
					ov3640_write_reg(0x8480,0x4B);
					ov3640_write_reg(0x8481,0x35);
					ov3640_write_reg(0x8482,0x3D);
					ov3640_write_reg(0x8483,0xFE);
					ov3640_write_reg(0x8484,0x12);
					ov3640_write_reg(0x8485,0x0B);
					ov3640_write_reg(0x8486,0x7A);
					ov3640_write_reg(0x8487,0x22);
					ov3640_write_reg(0x8488,0xC3);
					ov3640_write_reg(0x8489,0xE5);
					ov3640_write_reg(0x848A,0x33);
					ov3640_write_reg(0x848B,0x95);
					ov3640_write_reg(0x848C,0x31);
					ov3640_write_reg(0x848D,0xFF);
					ov3640_write_reg(0x848E,0xE5);
					ov3640_write_reg(0x848F,0x32);
					ov3640_write_reg(0x8490,0x95);
					ov3640_write_reg(0x8491,0x30);
					ov3640_write_reg(0x8492,0xFE);
					ov3640_write_reg(0x8493,0x12);
					ov3640_write_reg(0x8494,0x0C);
					ov3640_write_reg(0x8495,0xF7);
					ov3640_write_reg(0x8496,0x22);
					ov3640_write_reg(0x8497,0x90);
					ov3640_write_reg(0x8498,0x3F);
					ov3640_write_reg(0x8499,0x00);
					ov3640_write_reg(0x849A,0xE0);
					ov3640_write_reg(0x849B,0x54);
					ov3640_write_reg(0x849C,0x1F);
					ov3640_write_reg(0x849D,0xFF);
					ov3640_write_reg(0x849E,0x60);
					ov3640_write_reg(0x849F,0x02);
					ov3640_write_reg(0x84A0,0xE4);
					ov3640_write_reg(0x84A1,0xF0);
					ov3640_write_reg(0x84A2,0xEF);
					ov3640_write_reg(0x84A3,0x14);
					ov3640_write_reg(0x84A4,0xB4);
					ov3640_write_reg(0x84A5,0x19);
					ov3640_write_reg(0x84A6,0x00);
					ov3640_write_reg(0x84A7,0x40);
					ov3640_write_reg(0x84A8,0x03);
					ov3640_write_reg(0x84A9,0x02);
					ov3640_write_reg(0x84AA,0x05);
					ov3640_write_reg(0x84AB,0x9B);
					ov3640_write_reg(0x84AC,0x90);
					ov3640_write_reg(0x84AD,0x04);
					ov3640_write_reg(0x84AE,0xBA);
					ov3640_write_reg(0x84AF,0x75);
					ov3640_write_reg(0x84B0,0xF0);
					ov3640_write_reg(0x84B1,0x03);
					ov3640_write_reg(0x84B2,0xA4);
					ov3640_write_reg(0x84B3,0xC5);
					ov3640_write_reg(0x84B4,0x83);
					ov3640_write_reg(0x84B5,0x25);
					ov3640_write_reg(0x84B6,0xF0);
					ov3640_write_reg(0x84B7,0xC5);
					ov3640_write_reg(0x84B8,0x83);
					ov3640_write_reg(0x84B9,0x73);
					ov3640_write_reg(0x84BA,0x02);
					ov3640_write_reg(0x84BB,0x05);
					ov3640_write_reg(0x84BC,0x05);
					ov3640_write_reg(0x84BD,0x02);
					ov3640_write_reg(0x84BE,0x05);
					ov3640_write_reg(0x84BF,0x09);
					ov3640_write_reg(0x84C0,0x02);
					ov3640_write_reg(0x84C1,0x05);
					ov3640_write_reg(0x84C2,0x0E);
					ov3640_write_reg(0x84C3,0x02);
					ov3640_write_reg(0x84C4,0x05);
					ov3640_write_reg(0x84C5,0x12);
					ov3640_write_reg(0x84C6,0x02);
					ov3640_write_reg(0x84C7,0x05);
					ov3640_write_reg(0x84C8,0x17);
					ov3640_write_reg(0x84C9,0x02);
					ov3640_write_reg(0x84CA,0x05);
					ov3640_write_reg(0x84CB,0x26);
					ov3640_write_reg(0x84CC,0x02);
					ov3640_write_reg(0x84CD,0x05);
					ov3640_write_reg(0x84CE,0x2E);
					ov3640_write_reg(0x84CF,0x02);
					ov3640_write_reg(0x84D0,0x05);
					ov3640_write_reg(0x84D1,0x38);
					ov3640_write_reg(0x84D2,0x02);
					ov3640_write_reg(0x84D3,0x05);
					ov3640_write_reg(0x84D4,0x47);
					ov3640_write_reg(0x84D5,0x02);
					ov3640_write_reg(0x84D6,0x05);
					ov3640_write_reg(0x84D7,0x4C);
					ov3640_write_reg(0x84D8,0x02);
					ov3640_write_reg(0x84D9,0x05);
					ov3640_write_reg(0x84DA,0x54);
					ov3640_write_reg(0x84DB,0x02);
					ov3640_write_reg(0x84DC,0x05);
					ov3640_write_reg(0x84DD,0x5C);
					ov3640_write_reg(0x84DE,0x02);
					ov3640_write_reg(0x84DF,0x05);
					ov3640_write_reg(0x84E0,0x9B);
					ov3640_write_reg(0x84E1,0x02);
					ov3640_write_reg(0x84E2,0x05);
					ov3640_write_reg(0x84E3,0x9B);
					ov3640_write_reg(0x84E4,0x02);
					ov3640_write_reg(0x84E5,0x05);
					ov3640_write_reg(0x84E6,0x66);
					ov3640_write_reg(0x84E7,0x02);
					ov3640_write_reg(0x84E8,0x05);
					ov3640_write_reg(0x84E9,0x9B);
					ov3640_write_reg(0x84EA,0x02);
					ov3640_write_reg(0x84EB,0x05);
					ov3640_write_reg(0x84EC,0x9B);
					ov3640_write_reg(0x84ED,0x02);
					ov3640_write_reg(0x84EE,0x05);
					ov3640_write_reg(0x84EF,0x9B);
					ov3640_write_reg(0x84F0,0x02);
					ov3640_write_reg(0x84F1,0x05);
					ov3640_write_reg(0x84F2,0x9B);
					ov3640_write_reg(0x84F3,0x02);
					ov3640_write_reg(0x84F4,0x05);
					ov3640_write_reg(0x84F5,0x71);
					ov3640_write_reg(0x84F6,0x02);
					ov3640_write_reg(0x84F7,0x05);
					ov3640_write_reg(0x84F8,0x9B);
					ov3640_write_reg(0x84F9,0x02);
					ov3640_write_reg(0x84FA,0x05);
					ov3640_write_reg(0x84FB,0x9B);
					ov3640_write_reg(0x84FC,0x02);
					ov3640_write_reg(0x84FD,0x05);
					ov3640_write_reg(0x84FE,0x9B);
					ov3640_write_reg(0x84FF,0x02);
					ov3640_write_reg(0x8500,0x05);
					ov3640_write_reg(0x8501,0x86);
					ov3640_write_reg(0x8502,0x02);
					ov3640_write_reg(0x8503,0x05);
					ov3640_write_reg(0x8504,0x8E);
					ov3640_write_reg(0x8505,0x7F);
					ov3640_write_reg(0x8506,0x01);
					ov3640_write_reg(0x8507,0x80);
					ov3640_write_reg(0x8508,0x02);
					ov3640_write_reg(0x8509,0xE4);
					ov3640_write_reg(0x850A,0xFF);
					ov3640_write_reg(0x850B,0x02);
					ov3640_write_reg(0x850C,0x0C);
					ov3640_write_reg(0x850D,0xDA);
					ov3640_write_reg(0x850E,0xD2);
					ov3640_write_reg(0x850F,0x0F);
					ov3640_write_reg(0x8510,0x80);
					ov3640_write_reg(0x8511,0x02);
					ov3640_write_reg(0x8512,0xC2);
					ov3640_write_reg(0x8513,0x0F);
					ov3640_write_reg(0x8514,0x02);
					ov3640_write_reg(0x8515,0x0C);
					ov3640_write_reg(0x8516,0x76);
					ov3640_write_reg(0x8517,0xC2);
					ov3640_write_reg(0x8518,0x0D);
					ov3640_write_reg(0x8519,0x75);
					ov3640_write_reg(0x851A,0x3C);
					ov3640_write_reg(0x851B,0x01);
					ov3640_write_reg(0x851C,0xC2);
					ov3640_write_reg(0x851D,0x0C);
					ov3640_write_reg(0x851E,0x90);
					ov3640_write_reg(0x851F,0x3F);
					ov3640_write_reg(0x8520,0x02);
					ov3640_write_reg(0x8521,0xE4);
					ov3640_write_reg(0x8522,0xF0);
					ov3640_write_reg(0x8523,0xA3);
					ov3640_write_reg(0x8524,0xF0);
					ov3640_write_reg(0x8525,0x22);
					ov3640_write_reg(0x8526,0xC2);
					ov3640_write_reg(0x8527,0x0D);
					ov3640_write_reg(0x8528,0xE4);
					ov3640_write_reg(0x8529,0xF5);
					ov3640_write_reg(0x852A,0x3C);
					ov3640_write_reg(0x852B,0xD2);
					ov3640_write_reg(0x852C,0x0C);
					ov3640_write_reg(0x852D,0x22);
					ov3640_write_reg(0x852E,0xE4);
					ov3640_write_reg(0x852F,0xF5);
					ov3640_write_reg(0x8530,0x3C);
					ov3640_write_reg(0x8531,0xC2);
					ov3640_write_reg(0x8532,0x0C);
					ov3640_write_reg(0x8533,0xC2);
					ov3640_write_reg(0x8534,0x0B);
					ov3640_write_reg(0x8535,0xD2);
					ov3640_write_reg(0x8536,0x0D);
					ov3640_write_reg(0x8537,0x22);
					ov3640_write_reg(0x8538,0xC2);
					ov3640_write_reg(0x8539,0x0D);
					ov3640_write_reg(0x853A,0xE4);
					ov3640_write_reg(0x853B,0xF5);
					ov3640_write_reg(0x853C,0x3C);
					ov3640_write_reg(0x853D,0xC2);
					ov3640_write_reg(0x853E,0x0C);
					ov3640_write_reg(0x853F,0xF5);
					ov3640_write_reg(0x8540,0x72);
					ov3640_write_reg(0x8541,0xF5);
					ov3640_write_reg(0x8542,0x4B);
					ov3640_write_reg(0x8543,0xF5);
					ov3640_write_reg(0x8544,0x4C);
					ov3640_write_reg(0x8545,0x80);
					ov3640_write_reg(0x8546,0x4D);
					ov3640_write_reg(0x8547,0xC2);
					ov3640_write_reg(0x8548,0x0D);
					ov3640_write_reg(0x8549,0xD2);
					ov3640_write_reg(0x854A,0x0B);
					ov3640_write_reg(0x854B,0x22);
					ov3640_write_reg(0x854C,0x12);
					ov3640_write_reg(0x854D,0x06);
					ov3640_write_reg(0x854E,0x53);
					ov3640_write_reg(0x854F,0x75);
					ov3640_write_reg(0x8550,0x72);
					ov3640_write_reg(0x8551,0x01);
					ov3640_write_reg(0x8552,0x80);
					ov3640_write_reg(0x8553,0x0B);
					ov3640_write_reg(0x8554,0x12);
					ov3640_write_reg(0x8555,0x06);
					ov3640_write_reg(0x8556,0x53);
					ov3640_write_reg(0x8557,0x75);
					ov3640_write_reg(0x8558,0x72);
					ov3640_write_reg(0x8559,0x02);
					ov3640_write_reg(0x855A,0x80);
					ov3640_write_reg(0x855B,0x03);
					ov3640_write_reg(0x855C,0xE4);
					ov3640_write_reg(0x855D,0xF5);
					ov3640_write_reg(0x855E,0x72);
					ov3640_write_reg(0x855F,0x90);
					ov3640_write_reg(0x8560,0x3F);
					ov3640_write_reg(0x8561,0x04);
					ov3640_write_reg(0x8562,0xE5);
					ov3640_write_reg(0x8563,0x72);
					ov3640_write_reg(0x8564,0xF0);
					ov3640_write_reg(0x8565,0x22);
					ov3640_write_reg(0x8566,0xD2);
					ov3640_write_reg(0x8567,0x0A);
					ov3640_write_reg(0x8568,0x90);
					ov3640_write_reg(0x8569,0x3F);
					ov3640_write_reg(0x856A,0x01);
					ov3640_write_reg(0x856B,0xE0);
					ov3640_write_reg(0x856C,0x90);
					ov3640_write_reg(0x856D,0x3F);
					ov3640_write_reg(0x856E,0x05);
					ov3640_write_reg(0x856F,0xF0);
					ov3640_write_reg(0x8570,0x22);
					ov3640_write_reg(0x8571,0x90);
					ov3640_write_reg(0x8572,0x3F);
					ov3640_write_reg(0x8573,0x06);
					ov3640_write_reg(0x8574,0xE0);
					ov3640_write_reg(0x8575,0xF5);
					ov3640_write_reg(0x8576,0x46);
					ov3640_write_reg(0x8577,0xE4);
					ov3640_write_reg(0x8578,0xF0);
					ov3640_write_reg(0x8579,0xE5);
					ov3640_write_reg(0x857A,0x46);
					ov3640_write_reg(0x857B,0xD3);
					ov3640_write_reg(0x857C,0x94);
					ov3640_write_reg(0x857D,0x06);
					ov3640_write_reg(0x857E,0x40);
					ov3640_write_reg(0x857F,0x03);
					ov3640_write_reg(0x8580,0x75);
					ov3640_write_reg(0x8581,0x46);
					ov3640_write_reg(0x8582,0x06);
					ov3640_write_reg(0x8583,0xD2);
					ov3640_write_reg(0x8584,0x0E);
					ov3640_write_reg(0x8585,0x22);
					ov3640_write_reg(0x8586,0x75);
					ov3640_write_reg(0x8587,0x4B);
					ov3640_write_reg(0x8588,0x02);
					ov3640_write_reg(0x8589,0x75);
					ov3640_write_reg(0x858A,0x4C);
					ov3640_write_reg(0x858B,0x58);
					ov3640_write_reg(0x858C,0x80);
					ov3640_write_reg(0x858D,0x06);
					ov3640_write_reg(0x858E,0x85);
					ov3640_write_reg(0x858F,0x3D);
					ov3640_write_reg(0x8590,0x4B);
					ov3640_write_reg(0x8591,0x85);
					ov3640_write_reg(0x8592,0x3E);
					ov3640_write_reg(0x8593,0x4C);
					ov3640_write_reg(0x8594,0xAF);
					ov3640_write_reg(0x8595,0x4C);
					ov3640_write_reg(0x8596,0xAE);
					ov3640_write_reg(0x8597,0x4B);
					ov3640_write_reg(0x8598,0x12);
					ov3640_write_reg(0x8599,0x0B);
					ov3640_write_reg(0x859A,0x7A);
					ov3640_write_reg(0x859B,0x22);
					ov3640_write_reg(0x859C,0xE5);
					ov3640_write_reg(0x859D,0x46);
					ov3640_write_reg(0x859E,0x24);
					ov3640_write_reg(0x859F,0x09);
					ov3640_write_reg(0x85A0,0xFF);
					ov3640_write_reg(0x85A1,0xE4);
					ov3640_write_reg(0x85A2,0x33);
					ov3640_write_reg(0x85A3,0xFE);
					ov3640_write_reg(0x85A4,0x12);
					ov3640_write_reg(0x85A5,0x0C);
					ov3640_write_reg(0x85A6,0xC8);
					ov3640_write_reg(0x85A7,0xEE);
					ov3640_write_reg(0x85A8,0xC4);
					ov3640_write_reg(0x85A9,0xF8);
					ov3640_write_reg(0x85AA,0x54);
					ov3640_write_reg(0x85AB,0xF0);
					ov3640_write_reg(0x85AC,0xC8);
					ov3640_write_reg(0x85AD,0x22);
					ov3640_write_reg(0x85AE,0xE5);
					ov3640_write_reg(0x85AF,0x4C);
					ov3640_write_reg(0x85B0,0x25);
					ov3640_write_reg(0x85B1,0x3E);
					ov3640_write_reg(0x85B2,0xCF);
					ov3640_write_reg(0x85B3,0xE5);
					ov3640_write_reg(0x85B4,0x4B);
					ov3640_write_reg(0x85B5,0x35);
					ov3640_write_reg(0x85B6,0x3D);
					ov3640_write_reg(0x85B7,0xCF);
					ov3640_write_reg(0x85B8,0x24);
					ov3640_write_reg(0x85B9,0x28);
					ov3640_write_reg(0x85BA,0xCF);
					ov3640_write_reg(0x85BB,0x34);
					ov3640_write_reg(0x85BC,0x00);
					ov3640_write_reg(0x85BD,0xFE);
					ov3640_write_reg(0x85BE,0xC3);
					ov3640_write_reg(0x85BF,0xEF);
					ov3640_write_reg(0x85C0,0x94);
					ov3640_write_reg(0x85C1,0x58);
					ov3640_write_reg(0x85C2,0xEE);
					ov3640_write_reg(0x85C3,0x94);
					ov3640_write_reg(0x85C4,0x02);
					ov3640_write_reg(0x85C5,0x22);
					ov3640_write_reg(0x85C6,0xC2);
					ov3640_write_reg(0x85C7,0x00);
					ov3640_write_reg(0x85C8,0x90);
					ov3640_write_reg(0x85C9,0x30);
					ov3640_write_reg(0x85CA,0xB4);
					ov3640_write_reg(0x85CB,0xE5);
					ov3640_write_reg(0x85CC,0x20);
					ov3640_write_reg(0x85CD,0xF0);
					ov3640_write_reg(0x85CE,0x22);
					ov3640_write_reg(0x85CF,0x90);
					ov3640_write_reg(0x85D0,0x3A);
					ov3640_write_reg(0x85D1,0x00);
					ov3640_write_reg(0x85D2,0xF0);
					ov3640_write_reg(0x85D3,0x90);
					ov3640_write_reg(0x85D4,0x3A);
					ov3640_write_reg(0x85D5,0x03);
					ov3640_write_reg(0x85D6,0xE0);
					ov3640_write_reg(0x85D7,0x22);
					ov3640_write_reg(0x85D8,0xD3);
					ov3640_write_reg(0x85D9,0xE5);
					ov3640_write_reg(0x85DA,0x28);
					ov3640_write_reg(0x85DB,0x95);
					ov3640_write_reg(0x85DC,0x50);
					ov3640_write_reg(0x85DD,0xE5);
					ov3640_write_reg(0x85DE,0x27);
					ov3640_write_reg(0x85DF,0x95);
					ov3640_write_reg(0x85E0,0x4F);
					ov3640_write_reg(0x85E1,0x22);
					ov3640_write_reg(0x85E2,0x85);
					ov3640_write_reg(0x85E3,0x45);
					ov3640_write_reg(0x85E4,0x61);
					ov3640_write_reg(0x85E5,0x90);
					ov3640_write_reg(0x85E6,0x3F);
					ov3640_write_reg(0x85E7,0x07);
					ov3640_write_reg(0x85E8,0xE5);
					ov3640_write_reg(0x85E9,0x61);
					ov3640_write_reg(0x85EA,0xF0);
					ov3640_write_reg(0x85EB,0x22);
					ov3640_write_reg(0x85EC,0xC3);
					ov3640_write_reg(0x85ED,0x74);
					ov3640_write_reg(0x85EE,0x07);
					ov3640_write_reg(0x85EF,0x95);
					ov3640_write_reg(0x85F0,0x46);
					ov3640_write_reg(0x85F1,0xFF);
					ov3640_write_reg(0x85F2,0xE4);
					ov3640_write_reg(0x85F3,0x94);
					ov3640_write_reg(0x85F4,0x00);
					ov3640_write_reg(0x85F5,0x22);
					ov3640_write_reg(0x85F6,0x85);
					ov3640_write_reg(0x85F7,0x32);
					ov3640_write_reg(0x85F8,0x38);
					ov3640_write_reg(0x85F9,0x85);
					ov3640_write_reg(0x85FA,0x33);
					ov3640_write_reg(0x85FB,0x39);
					ov3640_write_reg(0x85FC,0x85);
					ov3640_write_reg(0x85FD,0x30);
					ov3640_write_reg(0x85FE,0x3A);
					ov3640_write_reg(0x85FF,0x85);
					ov3640_write_reg(0x8600,0x31);
					ov3640_write_reg(0x8601,0x3B);
					ov3640_write_reg(0x8602,0x22);
					ov3640_write_reg(0x8603,0x85);
					ov3640_write_reg(0x8604,0x36);
					ov3640_write_reg(0x8605,0x38);
					ov3640_write_reg(0x8606,0x85);
					ov3640_write_reg(0x8607,0x37);
					ov3640_write_reg(0x8608,0x39);
					ov3640_write_reg(0x8609,0x85);
					ov3640_write_reg(0x860A,0x34);
					ov3640_write_reg(0x860B,0x3A);
					ov3640_write_reg(0x860C,0x85);
					ov3640_write_reg(0x860D,0x35);
					ov3640_write_reg(0x860E,0x3B);
					ov3640_write_reg(0x860F,0x22);
					ov3640_write_reg(0x8610,0xD3);
					ov3640_write_reg(0x8611,0xEF);
					ov3640_write_reg(0x8612,0x9D);
					ov3640_write_reg(0x8613,0xEC);
					ov3640_write_reg(0x8614,0x64);
					ov3640_write_reg(0x8615,0x80);
					ov3640_write_reg(0x8616,0xF8);
					ov3640_write_reg(0x8617,0xEE);
					ov3640_write_reg(0x8618,0x64);
					ov3640_write_reg(0x8619,0x80);
					ov3640_write_reg(0x861A,0x98);
					ov3640_write_reg(0x861B,0x22);
					ov3640_write_reg(0x861C,0x13);
					ov3640_write_reg(0x861D,0xFF);
					ov3640_write_reg(0x861E,0xD3);
					ov3640_write_reg(0x861F,0xE5);
					ov3640_write_reg(0x8620,0x28);
					ov3640_write_reg(0x8621,0x9F);
					ov3640_write_reg(0x8622,0xE5);
					ov3640_write_reg(0x8623,0x27);
					ov3640_write_reg(0x8624,0x9E);
					ov3640_write_reg(0x8625,0x22);
					ov3640_write_reg(0x8626,0xD3);
					ov3640_write_reg(0x8627,0xE5);
					ov3640_write_reg(0x8628,0x39);
					ov3640_write_reg(0x8629,0x95);
					ov3640_write_reg(0x862A,0x3B);
					ov3640_write_reg(0x862B,0xE5);
					ov3640_write_reg(0x862C,0x38);
					ov3640_write_reg(0x862D,0x95);
					ov3640_write_reg(0x862E,0x3A);
					ov3640_write_reg(0x862F,0x22);
					ov3640_write_reg(0x8630,0x74);
					ov3640_write_reg(0x8631,0xFF);
					ov3640_write_reg(0x8632,0xF0);
					ov3640_write_reg(0x8633,0xA3);
					ov3640_write_reg(0x8634,0x74);
					ov3640_write_reg(0x8635,0x80);
					ov3640_write_reg(0x8636,0xF0);
					ov3640_write_reg(0x8637,0xA3);
					ov3640_write_reg(0x8638,0xF0);
					ov3640_write_reg(0x8639,0xA3);
					ov3640_write_reg(0x863A,0x74);
					ov3640_write_reg(0x863B,0x01);
					ov3640_write_reg(0x863C,0xF0);
					ov3640_write_reg(0x863D,0x22);
					ov3640_write_reg(0x863E,0xFB);
					ov3640_write_reg(0x863F,0xEF);
					ov3640_write_reg(0x8640,0x75);
					ov3640_write_reg(0x8641,0xF0);
					ov3640_write_reg(0x8642,0x08);
					ov3640_write_reg(0x8643,0xA4);
					ov3640_write_reg(0x8644,0xFE);
					ov3640_write_reg(0x8645,0x22);
					ov3640_write_reg(0x8646,0x54);
					ov3640_write_reg(0x8647,0x07);
					ov3640_write_reg(0x8648,0xC4);
					ov3640_write_reg(0x8649,0xF8);
					ov3640_write_reg(0x864A,0x54);
					ov3640_write_reg(0x864B,0xF0);
					ov3640_write_reg(0x864C,0xC8);
					ov3640_write_reg(0x864D,0xE4);
					ov3640_write_reg(0x864E,0xC4);
					ov3640_write_reg(0x864F,0x54);
					ov3640_write_reg(0x8650,0x0F);
					ov3640_write_reg(0x8651,0x48);
					ov3640_write_reg(0x8652,0x22);
					ov3640_write_reg(0x8653,0xE4);
					ov3640_write_reg(0x8654,0xF5);
					ov3640_write_reg(0x8655,0x4F);
					ov3640_write_reg(0x8656,0xF5);
					ov3640_write_reg(0x8657,0x50);
					ov3640_write_reg(0x8658,0xF5);
					ov3640_write_reg(0x8659,0x43);
					ov3640_write_reg(0x865A,0xC2);
					ov3640_write_reg(0x865B,0x09);
					ov3640_write_reg(0x865C,0xC2);
					ov3640_write_reg(0x865D,0x0A);
					ov3640_write_reg(0x865E,0x22);
					ov3640_write_reg(0x865F,0xE5);
					ov3640_write_reg(0x8660,0x26);
					ov3640_write_reg(0x8661,0x25);
					ov3640_write_reg(0x8662,0xE0);
					ov3640_write_reg(0x8663,0x24);
					ov3640_write_reg(0x8664,0x62);
					ov3640_write_reg(0x8665,0xF8);
					ov3640_write_reg(0x8666,0xE6);
					ov3640_write_reg(0x8667,0xFE);
					ov3640_write_reg(0x8668,0x08);
					ov3640_write_reg(0x8669,0xE6);
					ov3640_write_reg(0x866A,0x22);
					ov3640_write_reg(0x866B,0xFE);
					ov3640_write_reg(0x866C,0xA3);
					ov3640_write_reg(0x866D,0xE0);
					ov3640_write_reg(0x866E,0xFD);
					ov3640_write_reg(0x866F,0xEE);
					ov3640_write_reg(0x8670,0xF5);
					ov3640_write_reg(0x8671,0x08);
					ov3640_write_reg(0x8672,0xED);
					ov3640_write_reg(0x8673,0xF5);
					ov3640_write_reg(0x8674,0x09);
					ov3640_write_reg(0x8675,0x22);
					ov3640_write_reg(0x8676,0xD3);
					ov3640_write_reg(0x8677,0xE5);
					ov3640_write_reg(0x8678,0x0B);
					ov3640_write_reg(0x8679,0x94);
					ov3640_write_reg(0x867A,0x40);
					ov3640_write_reg(0x867B,0xE5);
					ov3640_write_reg(0x867C,0x0A);
					ov3640_write_reg(0x867D,0x94);
					ov3640_write_reg(0x867E,0x00);
					ov3640_write_reg(0x867F,0x22);
					ov3640_write_reg(0x8680,0x90);
					ov3640_write_reg(0x8681,0x33);
					ov3640_write_reg(0x8682,0x5F);
					ov3640_write_reg(0x8683,0xE0);
					ov3640_write_reg(0x8684,0x54);
					ov3640_write_reg(0x8685,0x0F);
					ov3640_write_reg(0x8686,0x12);
					ov3640_write_reg(0x8687,0x06);
					ov3640_write_reg(0x8688,0x6B);
					ov3640_write_reg(0x8689,0x90);
					ov3640_write_reg(0x868A,0x33);
					ov3640_write_reg(0x868B,0x5F);
					ov3640_write_reg(0x868C,0xE0);
					ov3640_write_reg(0x868D,0x54);
					ov3640_write_reg(0x868E,0x70);
					ov3640_write_reg(0x868F,0x75);
					ov3640_write_reg(0x8690,0xF0);
					ov3640_write_reg(0x8691,0x10);
					ov3640_write_reg(0x8692,0xA4);
					ov3640_write_reg(0x8693,0xFF);
					ov3640_write_reg(0x8694,0x90);
					ov3640_write_reg(0x8695,0x33);
					ov3640_write_reg(0x8696,0x61);
					ov3640_write_reg(0x8697,0xE0);
					ov3640_write_reg(0x8698,0xFD);
					ov3640_write_reg(0x8699,0xE5);
					ov3640_write_reg(0x869A,0xF0);
					ov3640_write_reg(0x869B,0xF5);
					ov3640_write_reg(0x869C,0x0A);
					ov3640_write_reg(0x869D,0xEF);
					ov3640_write_reg(0x869E,0x4D);
					ov3640_write_reg(0x869F,0xF5);
					ov3640_write_reg(0x86A0,0x0B);
					ov3640_write_reg(0x86A1,0xE5);
					ov3640_write_reg(0x86A2,0x4A);
					ov3640_write_reg(0x86A3,0xB5);
					ov3640_write_reg(0x86A4,0x09);
					ov3640_write_reg(0x86A5,0x11);
					ov3640_write_reg(0x86A6,0xE5);
					ov3640_write_reg(0x86A7,0x49);
					ov3640_write_reg(0x86A8,0xB5);
					ov3640_write_reg(0x86A9,0x08);
					ov3640_write_reg(0x86AA,0x0C);
					ov3640_write_reg(0x86AB,0xE5);
					ov3640_write_reg(0x86AC,0x42);
					ov3640_write_reg(0x86AD,0x65);
					ov3640_write_reg(0x86AE,0x0B);
					ov3640_write_reg(0x86AF,0x70);
					ov3640_write_reg(0x86B0,0x04);
					ov3640_write_reg(0x86B1,0xE5);
					ov3640_write_reg(0x86B2,0x41);
					ov3640_write_reg(0x86B3,0x65);
					ov3640_write_reg(0x86B4,0x0A);
					ov3640_write_reg(0x86B5,0x60);
					ov3640_write_reg(0x86B6,0x19);
					ov3640_write_reg(0x86B7,0x85);
					ov3640_write_reg(0x86B8,0x08);
					ov3640_write_reg(0x86B9,0x49);
					ov3640_write_reg(0x86BA,0x85);
					ov3640_write_reg(0x86BB,0x09);
					ov3640_write_reg(0x86BC,0x4A);
					ov3640_write_reg(0x86BD,0x85);
					ov3640_write_reg(0x86BE,0x0A);
					ov3640_write_reg(0x86BF,0x41);
					ov3640_write_reg(0x86C0,0x85);
					ov3640_write_reg(0x86C1,0x0B);
					ov3640_write_reg(0x86C2,0x42);
					ov3640_write_reg(0x86C3,0xE4);
					ov3640_write_reg(0x86C4,0xFB);
					ov3640_write_reg(0x86C5,0xAD);
					ov3640_write_reg(0x86C6,0x0B);
					ov3640_write_reg(0x86C7,0xAC);
					ov3640_write_reg(0x86C8,0x0A);
					ov3640_write_reg(0x86C9,0xAF);
					ov3640_write_reg(0x86CA,0x09);
					ov3640_write_reg(0x86CB,0xAE);
					ov3640_write_reg(0x86CC,0x08);
					ov3640_write_reg(0x86CD,0x12);
					ov3640_write_reg(0x86CE,0x08);
					ov3640_write_reg(0x86CF,0xEF);
					ov3640_write_reg(0x86D0,0x90);
					ov3640_write_reg(0x86D1,0x33);
					ov3640_write_reg(0x86D2,0x02);
					ov3640_write_reg(0x86D3,0xE0);
					ov3640_write_reg(0x86D4,0x20);
					ov3640_write_reg(0x86D5,0xE5);
					ov3640_write_reg(0x86D6,0x03);
					ov3640_write_reg(0x86D7,0x12);
					ov3640_write_reg(0x86D8,0x07);
					ov3640_write_reg(0x86D9,0x2B);
					ov3640_write_reg(0x86DA,0x90);
					ov3640_write_reg(0x86DB,0x33);
					ov3640_write_reg(0x86DC,0x02);
					ov3640_write_reg(0x86DD,0xE0);
					ov3640_write_reg(0x86DE,0x30);
					ov3640_write_reg(0x86DF,0xE5);
					ov3640_write_reg(0x86E0,0x2C);
					ov3640_write_reg(0x86E1,0x90);
					ov3640_write_reg(0x86E2,0x30);
					ov3640_write_reg(0x86E3,0x88);
					ov3640_write_reg(0x86E4,0xE0);
					ov3640_write_reg(0x86E5,0x12);
					ov3640_write_reg(0x86E6,0x06);
					ov3640_write_reg(0x86E7,0x6B);
					ov3640_write_reg(0x86E8,0xA3);
					ov3640_write_reg(0x86E9,0xE0);
					ov3640_write_reg(0x86EA,0xFE);
					ov3640_write_reg(0x86EB,0xA3);
					ov3640_write_reg(0x86EC,0xE0);
					ov3640_write_reg(0x86ED,0xFD);
					ov3640_write_reg(0x86EE,0xEE);
					ov3640_write_reg(0x86EF,0xF5);
					ov3640_write_reg(0x86F0,0x0A);
					ov3640_write_reg(0x86F1,0xED);
					ov3640_write_reg(0x86F2,0xF5);
					ov3640_write_reg(0x86F3,0x0B);
					ov3640_write_reg(0x86F4,0xE5);
					ov3640_write_reg(0x86F5,0x48);
					ov3640_write_reg(0x86F6,0xB5);
					ov3640_write_reg(0x86F7,0x09);
					ov3640_write_reg(0x86F8,0x11);
					ov3640_write_reg(0x86F9,0xE5);
					ov3640_write_reg(0x86FA,0x47);
					ov3640_write_reg(0x86FB,0xB5);
					ov3640_write_reg(0x86FC,0x08);
					ov3640_write_reg(0x86FD,0x0C);
					ov3640_write_reg(0x86FE,0xE5);
					ov3640_write_reg(0x86FF,0x40);
					ov3640_write_reg(0x8700,0x65);
					ov3640_write_reg(0x8701,0x0B);
					ov3640_write_reg(0x8702,0x70);
					ov3640_write_reg(0x8703,0x04);
					ov3640_write_reg(0x8704,0xE5);
					ov3640_write_reg(0x8705,0x3F);
					ov3640_write_reg(0x8706,0x65);
					ov3640_write_reg(0x8707,0x0A);
					ov3640_write_reg(0x8708,0x60);
					ov3640_write_reg(0x8709,0x03);
					ov3640_write_reg(0x870A,0x12);
					ov3640_write_reg(0x870B,0x07);
					ov3640_write_reg(0x870C,0x2B);
					ov3640_write_reg(0x870D,0x30);
					ov3640_write_reg(0x870E,0x0E);
					ov3640_write_reg(0x870F,0x1A);
					ov3640_write_reg(0x8710,0xE4);
					ov3640_write_reg(0x8711,0xFB);
					ov3640_write_reg(0x8712,0xAD);
					ov3640_write_reg(0x8713,0x42);
					ov3640_write_reg(0x8714,0xAC);
					ov3640_write_reg(0x8715,0x41);
					ov3640_write_reg(0x8716,0xAF);
					ov3640_write_reg(0x8717,0x4A);
					ov3640_write_reg(0x8718,0xAE);
					ov3640_write_reg(0x8719,0x49);
					ov3640_write_reg(0x871A,0x12);
					ov3640_write_reg(0x871B,0x08);
					ov3640_write_reg(0x871C,0xEF);
					ov3640_write_reg(0x871D,0xAD);
					ov3640_write_reg(0x871E,0x40);
					ov3640_write_reg(0x871F,0xAC);
					ov3640_write_reg(0x8720,0x3F);
					ov3640_write_reg(0x8721,0xAF);
					ov3640_write_reg(0x8722,0x48);
					ov3640_write_reg(0x8723,0xAE);
					ov3640_write_reg(0x8724,0x47);
					ov3640_write_reg(0x8725,0x12);
					ov3640_write_reg(0x8726,0x09);
					ov3640_write_reg(0x8727,0x6D);
					ov3640_write_reg(0x8728,0xC2);
					ov3640_write_reg(0x8729,0x0E);
					ov3640_write_reg(0x872A,0x22);
					ov3640_write_reg(0x872B,0x85);
					ov3640_write_reg(0x872C,0x08);
					ov3640_write_reg(0x872D,0x47);
					ov3640_write_reg(0x872E,0x85);
					ov3640_write_reg(0x872F,0x09);
					ov3640_write_reg(0x8730,0x48);
					ov3640_write_reg(0x8731,0x85);
					ov3640_write_reg(0x8732,0x0A);
					ov3640_write_reg(0x8733,0x3F);
					ov3640_write_reg(0x8734,0x85);
					ov3640_write_reg(0x8735,0x0B);
					ov3640_write_reg(0x8736,0x40);
					ov3640_write_reg(0x8737,0xAD);
					ov3640_write_reg(0x8738,0x40);
					ov3640_write_reg(0x8739,0xAC);
					ov3640_write_reg(0x873A,0x3F);
					ov3640_write_reg(0x873B,0xAF);
					ov3640_write_reg(0x873C,0x48);
					ov3640_write_reg(0x873D,0xAE);
					ov3640_write_reg(0x873E,0x47);
					ov3640_write_reg(0x873F,0x12);
					ov3640_write_reg(0x8740,0x09);
					ov3640_write_reg(0x8741,0x6D);
					ov3640_write_reg(0x8742,0x22);
					ov3640_write_reg(0x8743,0xE5);
					ov3640_write_reg(0x8744,0x24);
					ov3640_write_reg(0x8745,0x70);
					ov3640_write_reg(0x8746,0x0A);
					ov3640_write_reg(0x8747,0xF5);
					ov3640_write_reg(0x8748,0x3D);
					ov3640_write_reg(0x8749,0xF5);
					ov3640_write_reg(0x874A,0x3E);
					ov3640_write_reg(0x874B,0x12);
					ov3640_write_reg(0x874C,0x0C);
					ov3640_write_reg(0x874D,0xEA);
					ov3640_write_reg(0x874E,0x05);
					ov3640_write_reg(0x874F,0x24);
					ov3640_write_reg(0x8750,0x22);
					ov3640_write_reg(0x8751,0xE5);
					ov3640_write_reg(0x8752,0x24);
					ov3640_write_reg(0x8753,0xC3);
					ov3640_write_reg(0x8754,0x94);
					ov3640_write_reg(0x8755,0x01);
					ov3640_write_reg(0x8756,0x50);
					ov3640_write_reg(0x8757,0x03);
					ov3640_write_reg(0x8758,0x05);
					ov3640_write_reg(0x8759,0x24);
					ov3640_write_reg(0x875A,0x22);
					ov3640_write_reg(0x875B,0xE5);
					ov3640_write_reg(0x875C,0x24);
					ov3640_write_reg(0x875D,0xB4);
					ov3640_write_reg(0x875E,0x01);
					ov3640_write_reg(0x875F,0x1A);
					ov3640_write_reg(0x8760,0xE4);
					ov3640_write_reg(0x8761,0xFD);
					ov3640_write_reg(0x8762,0xFF);
					ov3640_write_reg(0x8763,0x12);
					ov3640_write_reg(0x8764,0x0B);
					ov3640_write_reg(0x8765,0x2C);
					ov3640_write_reg(0x8766,0x8E);
					ov3640_write_reg(0x8767,0x22);
					ov3640_write_reg(0x8768,0x8F);
					ov3640_write_reg(0x8769,0x23);
					ov3640_write_reg(0x876A,0x75);
					ov3640_write_reg(0x876B,0x3D);
					ov3640_write_reg(0x876C,0x00);
					ov3640_write_reg(0x876D,0x75);
					ov3640_write_reg(0x876E,0x3E);
					ov3640_write_reg(0x876F,0x0A);
					ov3640_write_reg(0x8770,0xAF);
					ov3640_write_reg(0x8771,0x3E);
					ov3640_write_reg(0x8772,0xAE);
					ov3640_write_reg(0x8773,0x3D);
					ov3640_write_reg(0x8774,0x12);
					ov3640_write_reg(0x8775,0x0B);
					ov3640_write_reg(0x8776,0x7A);
					ov3640_write_reg(0x8777,0x05);
					ov3640_write_reg(0x8778,0x24);
					ov3640_write_reg(0x8779,0x22);
					ov3640_write_reg(0x877A,0xE4);
					ov3640_write_reg(0x877B,0xFD);
					ov3640_write_reg(0x877C,0xFF);
					ov3640_write_reg(0x877D,0x12);
					ov3640_write_reg(0x877E,0x0B);
					ov3640_write_reg(0x877F,0x2C);
					ov3640_write_reg(0x8780,0xC3);
					ov3640_write_reg(0x8781,0xEF);
					ov3640_write_reg(0x8782,0x95);
					ov3640_write_reg(0x8783,0x23);
					ov3640_write_reg(0x8784,0xFF);
					ov3640_write_reg(0x8785,0xEE);
					ov3640_write_reg(0x8786,0x95);
					ov3640_write_reg(0x8787,0x22);
					ov3640_write_reg(0x8788,0xFE);
					ov3640_write_reg(0x8789,0x12);
					ov3640_write_reg(0x878A,0x0C);
					ov3640_write_reg(0x878B,0xF7);
					ov3640_write_reg(0x878C,0xD3);
					ov3640_write_reg(0x878D,0xEF);
					ov3640_write_reg(0x878E,0x94);
					ov3640_write_reg(0x878F,0x20);
					ov3640_write_reg(0x8790,0xEE);
					ov3640_write_reg(0x8791,0x64);
					ov3640_write_reg(0x8792,0x80);
					ov3640_write_reg(0x8793,0x94);
					ov3640_write_reg(0x8794,0x80);
					ov3640_write_reg(0x8795,0x40);
					ov3640_write_reg(0x8796,0x15);
					ov3640_write_reg(0x8797,0xC2);
					ov3640_write_reg(0x8798,0x0B);
					ov3640_write_reg(0x8799,0xE4);
					ov3640_write_reg(0x879A,0xF5);
					ov3640_write_reg(0x879B,0x24);
					ov3640_write_reg(0x879C,0x74);
					ov3640_write_reg(0x879D,0xF6);
					ov3640_write_reg(0x879E,0x25);
					ov3640_write_reg(0x879F,0x3E);
					ov3640_write_reg(0x87A0,0xF5);
					ov3640_write_reg(0x87A1,0x3E);
					ov3640_write_reg(0x87A2,0x74);
					ov3640_write_reg(0x87A3,0xFF);
					ov3640_write_reg(0x87A4,0x35);
					ov3640_write_reg(0x87A5,0x3D);
					ov3640_write_reg(0x87A6,0xF5);
					ov3640_write_reg(0x87A7,0x3D);
					ov3640_write_reg(0x87A8,0xE4);
					ov3640_write_reg(0x87A9,0xFF);
					ov3640_write_reg(0x87AA,0x80);
					ov3640_write_reg(0x87AB,0x1F);
					ov3640_write_reg(0x87AC,0xC3);
					ov3640_write_reg(0x87AD,0xE5);
					ov3640_write_reg(0x87AE,0x3E);
					ov3640_write_reg(0x87AF,0x94);
					ov3640_write_reg(0x87B0,0x96);
					ov3640_write_reg(0x87B1,0xE5);
					ov3640_write_reg(0x87B2,0x3D);
					ov3640_write_reg(0x87B3,0x94);
					ov3640_write_reg(0x87B4,0x00);
					ov3640_write_reg(0x87B5,0x50);
					ov3640_write_reg(0x87B6,0x18);
					ov3640_write_reg(0x87B7,0x74);
					ov3640_write_reg(0x87B8,0x0A);
					ov3640_write_reg(0x87B9,0x25);
					ov3640_write_reg(0x87BA,0x3E);
					ov3640_write_reg(0x87BB,0xF5);
					ov3640_write_reg(0x87BC,0x3E);
					ov3640_write_reg(0x87BD,0xE4);
					ov3640_write_reg(0x87BE,0x35);
					ov3640_write_reg(0x87BF,0x3D);
					ov3640_write_reg(0x87C0,0xF5);
					ov3640_write_reg(0x87C1,0x3D);
					ov3640_write_reg(0x87C2,0xE5);
					ov3640_write_reg(0x87C3,0x3E);
					ov3640_write_reg(0x87C4,0x24);
					ov3640_write_reg(0x87C5,0xFF);
					ov3640_write_reg(0x87C6,0xFF);
					ov3640_write_reg(0x87C7,0xE5);
					ov3640_write_reg(0x87C8,0x3D);
					ov3640_write_reg(0x87C9,0x34);
					ov3640_write_reg(0x87CA,0xFF);
					ov3640_write_reg(0x87CB,0xFE);
					ov3640_write_reg(0x87CC,0x02);
					ov3640_write_reg(0x87CD,0x0B);
					ov3640_write_reg(0x87CE,0x7A);
					ov3640_write_reg(0x87CF,0xC2);
					ov3640_write_reg(0x87D0,0x0B);
					ov3640_write_reg(0x87D1,0xE4);
					ov3640_write_reg(0x87D2,0xF5);
					ov3640_write_reg(0x87D3,0x24);
					ov3640_write_reg(0x87D4,0xFF);
					ov3640_write_reg(0x87D5,0xFE);
					ov3640_write_reg(0x87D6,0x12);
					ov3640_write_reg(0x87D7,0x0B);
					ov3640_write_reg(0x87D8,0x7A);
					ov3640_write_reg(0x87D9,0x75);
					ov3640_write_reg(0x87DA,0x3D);
					ov3640_write_reg(0x87DB,0x00);
					ov3640_write_reg(0x87DC,0x75);
					ov3640_write_reg(0x87DD,0x3E);
					ov3640_write_reg(0x87DE,0xC8);
					ov3640_write_reg(0x87DF,0x22);
					ov3640_write_reg(0x87E0,0x78);
					ov3640_write_reg(0x87E1,0x7F);
					ov3640_write_reg(0x87E2,0xE4);
					ov3640_write_reg(0x87E3,0xF6);
					ov3640_write_reg(0x87E4,0xD8);
					ov3640_write_reg(0x87E5,0xFD);
					ov3640_write_reg(0x87E6,0x75);
					ov3640_write_reg(0x87E7,0x81);
					ov3640_write_reg(0x87E8,0x72);
					ov3640_write_reg(0x87E9,0x02);
					ov3640_write_reg(0x87EA,0x08);
					ov3640_write_reg(0x87EB,0x27);
					ov3640_write_reg(0x87EC,0x02);
					ov3640_write_reg(0x87ED,0x0B);
					ov3640_write_reg(0x87EE,0xEF);
					ov3640_write_reg(0x87EF,0xE4);
					ov3640_write_reg(0x87F0,0x93);
					ov3640_write_reg(0x87F1,0xA3);
					ov3640_write_reg(0x87F2,0xF8);
					ov3640_write_reg(0x87F3,0xE4);
					ov3640_write_reg(0x87F4,0x93);
					ov3640_write_reg(0x87F5,0xA3);
					ov3640_write_reg(0x87F6,0x40);
					ov3640_write_reg(0x87F7,0x03);
					ov3640_write_reg(0x87F8,0xF6);
					ov3640_write_reg(0x87F9,0x80);
					ov3640_write_reg(0x87FA,0x01);
					ov3640_write_reg(0x87FB,0xF2);
					ov3640_write_reg(0x87FC,0x08);
					ov3640_write_reg(0x87FD,0xDF);
					ov3640_write_reg(0x87FE,0xF4);
					ov3640_write_reg(0x87FF,0x80);
					ov3640_write_reg(0x8800,0x29);
					ov3640_write_reg(0x8801,0xE4);
					ov3640_write_reg(0x8802,0x93);
					ov3640_write_reg(0x8803,0xA3);
					ov3640_write_reg(0x8804,0xF8);
					ov3640_write_reg(0x8805,0x54);
					ov3640_write_reg(0x8806,0x07);
					ov3640_write_reg(0x8807,0x24);
					ov3640_write_reg(0x8808,0x0C);
					ov3640_write_reg(0x8809,0xC8);
					ov3640_write_reg(0x880A,0xC3);
					ov3640_write_reg(0x880B,0x33);
					ov3640_write_reg(0x880C,0xC4);
					ov3640_write_reg(0x880D,0x54);
					ov3640_write_reg(0x880E,0x0F);
					ov3640_write_reg(0x880F,0x44);
					ov3640_write_reg(0x8810,0x20);
					ov3640_write_reg(0x8811,0xC8);
					ov3640_write_reg(0x8812,0x83);
					ov3640_write_reg(0x8813,0x40);
					ov3640_write_reg(0x8814,0x04);
					ov3640_write_reg(0x8815,0xF4);
					ov3640_write_reg(0x8816,0x56);
					ov3640_write_reg(0x8817,0x80);
					ov3640_write_reg(0x8818,0x01);
					ov3640_write_reg(0x8819,0x46);
					ov3640_write_reg(0x881A,0xF6);
					ov3640_write_reg(0x881B,0xDF);
					ov3640_write_reg(0x881C,0xE4);
					ov3640_write_reg(0x881D,0x80);
					ov3640_write_reg(0x881E,0x0B);
					ov3640_write_reg(0x881F,0x01);
					ov3640_write_reg(0x8820,0x02);
					ov3640_write_reg(0x8821,0x04);
					ov3640_write_reg(0x8822,0x08);
					ov3640_write_reg(0x8823,0x10);
					ov3640_write_reg(0x8824,0x20);
					ov3640_write_reg(0x8825,0x40);
					ov3640_write_reg(0x8826,0x80);
					ov3640_write_reg(0x8827,0x90);
					ov3640_write_reg(0x8828,0x0B);
					ov3640_write_reg(0x8829,0xB9);
					ov3640_write_reg(0x882A,0xE4);
					ov3640_write_reg(0x882B,0x7E);
					ov3640_write_reg(0x882C,0x01);
					ov3640_write_reg(0x882D,0x93);
					ov3640_write_reg(0x882E,0x60);
					ov3640_write_reg(0x882F,0xBC);
					ov3640_write_reg(0x8830,0xA3);
					ov3640_write_reg(0x8831,0xFF);
					ov3640_write_reg(0x8832,0x54);
					ov3640_write_reg(0x8833,0x3F);
					ov3640_write_reg(0x8834,0x30);
					ov3640_write_reg(0x8835,0xE5);
					ov3640_write_reg(0x8836,0x09);
					ov3640_write_reg(0x8837,0x54);
					ov3640_write_reg(0x8838,0x1F);
					ov3640_write_reg(0x8839,0xFE);
					ov3640_write_reg(0x883A,0xE4);
					ov3640_write_reg(0x883B,0x93);
					ov3640_write_reg(0x883C,0xA3);
					ov3640_write_reg(0x883D,0x60);
					ov3640_write_reg(0x883E,0x01);
					ov3640_write_reg(0x883F,0x0E);
					ov3640_write_reg(0x8840,0xCF);
					ov3640_write_reg(0x8841,0x54);
					ov3640_write_reg(0x8842,0xC0);
					ov3640_write_reg(0x8843,0x25);
					ov3640_write_reg(0x8844,0xE0);
					ov3640_write_reg(0x8845,0x60);
					ov3640_write_reg(0x8846,0xA8);
					ov3640_write_reg(0x8847,0x40);
					ov3640_write_reg(0x8848,0xB8);
					ov3640_write_reg(0x8849,0xE4);
					ov3640_write_reg(0x884A,0x93);
					ov3640_write_reg(0x884B,0xA3);
					ov3640_write_reg(0x884C,0xFA);
					ov3640_write_reg(0x884D,0xE4);
					ov3640_write_reg(0x884E,0x93);
					ov3640_write_reg(0x884F,0xA3);
					ov3640_write_reg(0x8850,0xF8);
					ov3640_write_reg(0x8851,0xE4);
					ov3640_write_reg(0x8852,0x93);
					ov3640_write_reg(0x8853,0xA3);
					ov3640_write_reg(0x8854,0xC8);
					ov3640_write_reg(0x8855,0xC5);
					ov3640_write_reg(0x8856,0x82);
					ov3640_write_reg(0x8857,0xC8);
					ov3640_write_reg(0x8858,0xCA);
					ov3640_write_reg(0x8859,0xC5);
					ov3640_write_reg(0x885A,0x83);
					ov3640_write_reg(0x885B,0xCA);
					ov3640_write_reg(0x885C,0xF0);
					ov3640_write_reg(0x885D,0xA3);
					ov3640_write_reg(0x885E,0xC8);
					ov3640_write_reg(0x885F,0xC5);
					ov3640_write_reg(0x8860,0x82);
					ov3640_write_reg(0x8861,0xC8);
					ov3640_write_reg(0x8862,0xCA);
					ov3640_write_reg(0x8863,0xC5);
					ov3640_write_reg(0x8864,0x83);
					ov3640_write_reg(0x8865,0xCA);
					ov3640_write_reg(0x8866,0xDF);
					ov3640_write_reg(0x8867,0xE9);
					ov3640_write_reg(0x8868,0xDE);
					ov3640_write_reg(0x8869,0xE7);
					ov3640_write_reg(0x886A,0x80);
					ov3640_write_reg(0x886B,0xBE);
					ov3640_write_reg(0x886C,0xC2);
					ov3640_write_reg(0x886D,0x8C);
					ov3640_write_reg(0x886E,0x75);
					ov3640_write_reg(0x886F,0x89);
					ov3640_write_reg(0x8870,0x03);
					ov3640_write_reg(0x8871,0x90);
					ov3640_write_reg(0x8872,0x31);
					ov3640_write_reg(0x8873,0x00);
					ov3640_write_reg(0x8874,0xE0);
					ov3640_write_reg(0x8875,0x54);
					ov3640_write_reg(0x8876,0xFE);
					ov3640_write_reg(0x8877,0xF0);
					ov3640_write_reg(0x8878,0xE0);
					ov3640_write_reg(0x8879,0x54);
					ov3640_write_reg(0x887A,0xFD);
					ov3640_write_reg(0x887B,0xF0);
					ov3640_write_reg(0x887C,0xA3);
					ov3640_write_reg(0x887D,0xE4);
					ov3640_write_reg(0x887E,0xF0);
					ov3640_write_reg(0x887F,0x90);
					ov3640_write_reg(0x8880,0x33);
					ov3640_write_reg(0x8881,0xB0);
					ov3640_write_reg(0x8882,0xF0);
					ov3640_write_reg(0x8883,0xA3);
					ov3640_write_reg(0x8884,0x04);
					ov3640_write_reg(0x8885,0xF0);
					ov3640_write_reg(0x8886,0xA3);
					ov3640_write_reg(0x8887,0xF0);
					ov3640_write_reg(0x8888,0xA3);
					ov3640_write_reg(0x8889,0x12);
					ov3640_write_reg(0x888A,0x06);
					ov3640_write_reg(0x888B,0x30);
					ov3640_write_reg(0x888C,0x90);
					ov3640_write_reg(0x888D,0x33);
					ov3640_write_reg(0x888E,0x00);
					ov3640_write_reg(0x888F,0x74);
					ov3640_write_reg(0x8890,0x13);
					ov3640_write_reg(0x8891,0xF0);
					ov3640_write_reg(0x8892,0x90);
					ov3640_write_reg(0x8893,0x30);
					ov3640_write_reg(0x8894,0xB2);
					ov3640_write_reg(0x8895,0xE0);
					ov3640_write_reg(0x8896,0x44);
					ov3640_write_reg(0x8897,0x18);
					ov3640_write_reg(0x8898,0xF0);
					ov3640_write_reg(0x8899,0x90);
					ov3640_write_reg(0x889A,0x30);
					ov3640_write_reg(0x889B,0xB0);
					ov3640_write_reg(0x889C,0xE0);
					ov3640_write_reg(0x889D,0x44);
					ov3640_write_reg(0x889E,0x03);
					ov3640_write_reg(0x889F,0xF0);
					ov3640_write_reg(0x88A0,0xA3);
					ov3640_write_reg(0x88A1,0xE0);
					ov3640_write_reg(0x88A2,0x44);
					ov3640_write_reg(0x88A3,0xC0);
					ov3640_write_reg(0x88A4,0xF0);
					ov3640_write_reg(0x88A5,0x90);
					ov3640_write_reg(0x88A6,0x30);
					ov3640_write_reg(0x88A7,0xB4);
					ov3640_write_reg(0x88A8,0xE0);
					ov3640_write_reg(0x88A9,0x44);
					ov3640_write_reg(0x88AA,0x0F);
					ov3640_write_reg(0x88AB,0xF0);
					ov3640_write_reg(0x88AC,0xE0);
					ov3640_write_reg(0x88AD,0x54);
					ov3640_write_reg(0x88AE,0xF7);
					ov3640_write_reg(0x88AF,0xF0);
					ov3640_write_reg(0x88B0,0xE0);
					ov3640_write_reg(0x88B1,0xF5);
					ov3640_write_reg(0x88B2,0x20);
					ov3640_write_reg(0x88B3,0x90);
					ov3640_write_reg(0x88B4,0x39);
					ov3640_write_reg(0x88B5,0x01);
					ov3640_write_reg(0x88B6,0x74);
					ov3640_write_reg(0x88B7,0x35);
					ov3640_write_reg(0x88B8,0xF0);
					ov3640_write_reg(0x88B9,0x90);
					ov3640_write_reg(0x88BA,0x39);
					ov3640_write_reg(0x88BB,0x00);
					ov3640_write_reg(0x88BC,0x74);
					ov3640_write_reg(0x88BD,0x20);
					ov3640_write_reg(0x88BE,0xF0);
					ov3640_write_reg(0x88BF,0x90);
					ov3640_write_reg(0x88C0,0x30);
					ov3640_write_reg(0x88C1,0x0E);
					ov3640_write_reg(0x88C2,0x74);
					ov3640_write_reg(0x88C3,0x36);
					ov3640_write_reg(0x88C4,0xF0);
					ov3640_write_reg(0x88C5,0x90);
					ov3640_write_reg(0x88C6,0x30);
					ov3640_write_reg(0x88C7,0x11);
					ov3640_write_reg(0x88C8,0xE4);
					ov3640_write_reg(0x88C9,0xF0);
					ov3640_write_reg(0x88CA,0x90);
					ov3640_write_reg(0x88CB,0x30);
					ov3640_write_reg(0x88CC,0x14);
					ov3640_write_reg(0x88CD,0x74);
					ov3640_write_reg(0x88CE,0x04);
					ov3640_write_reg(0x88CF,0xF0);
					ov3640_write_reg(0x88D0,0x90);
					ov3640_write_reg(0x88D1,0x30);
					ov3640_write_reg(0x88D2,0x2D);
					ov3640_write_reg(0x88D3,0xE4);
					ov3640_write_reg(0x88D4,0xF0);
					ov3640_write_reg(0x88D5,0xA3);
					ov3640_write_reg(0x88D6,0xF0);
					ov3640_write_reg(0x88D7,0x90);
					ov3640_write_reg(0x88D8,0x37);
					ov3640_write_reg(0x88D9,0x00);
					ov3640_write_reg(0x88DA,0xE0);
					ov3640_write_reg(0x88DB,0x54);
					ov3640_write_reg(0x88DC,0xF7);
					ov3640_write_reg(0x88DD,0xF0);
					ov3640_write_reg(0x88DE,0xE0);
					ov3640_write_reg(0x88DF,0x54);
					ov3640_write_reg(0x88E0,0xBF);
					ov3640_write_reg(0x88E1,0xF0);
					ov3640_write_reg(0x88E2,0x90);
					ov3640_write_reg(0x88E3,0x35);
					ov3640_write_reg(0x88E4,0x08);
					ov3640_write_reg(0x88E5,0x74);
					ov3640_write_reg(0x88E6,0x07);
					ov3640_write_reg(0x88E7,0xF0);
					ov3640_write_reg(0x88E8,0x75);
					ov3640_write_reg(0x88E9,0xB8);
					ov3640_write_reg(0x88EA,0x01);
					ov3640_write_reg(0x88EB,0x75);
					ov3640_write_reg(0x88EC,0xA8);
					ov3640_write_reg(0x88ED,0x81);
					ov3640_write_reg(0x88EE,0x22);
					ov3640_write_reg(0x88EF,0x8E);
					ov3640_write_reg(0x88F0,0x0C);
					ov3640_write_reg(0x88F1,0x8F);
					ov3640_write_reg(0x88F2,0x0D);
					ov3640_write_reg(0x88F3,0x8C);
					ov3640_write_reg(0x88F4,0x0E);
					ov3640_write_reg(0x88F5,0x8D);
					ov3640_write_reg(0x88F6,0x0F);
					ov3640_write_reg(0x88F7,0xEB);
					ov3640_write_reg(0x88F8,0xD3);
					ov3640_write_reg(0x88F9,0x94);
					ov3640_write_reg(0x88FA,0x03);
					ov3640_write_reg(0x88FB,0x40);
					ov3640_write_reg(0x88FC,0x02);
					ov3640_write_reg(0x88FD,0xE4);
					ov3640_write_reg(0x88FE,0xFB);
					ov3640_write_reg(0x88FF,0xE5);
					ov3640_write_reg(0x8900,0x0F);
					ov3640_write_reg(0x8901,0xAE);
					ov3640_write_reg(0x8902,0x0E);
					ov3640_write_reg(0x8903,0x78);
					ov3640_write_reg(0x8904,0x03);
					ov3640_write_reg(0x8905,0xCE);
					ov3640_write_reg(0x8906,0xC3);
					ov3640_write_reg(0x8907,0x13);
					ov3640_write_reg(0x8908,0xCE);
					ov3640_write_reg(0x8909,0x13);
					ov3640_write_reg(0x890A,0xD8);
					ov3640_write_reg(0x890B,0xF9);
					ov3640_write_reg(0x890C,0xFB);
					ov3640_write_reg(0x890D,0xAA);
					ov3640_write_reg(0x890E,0x06);
					ov3640_write_reg(0x890F,0x12);
					ov3640_write_reg(0x8910,0x05);
					ov3640_write_reg(0x8911,0xEC);
					ov3640_write_reg(0x8912,0xFE);
					ov3640_write_reg(0x8913,0xAD);
					ov3640_write_reg(0x8914,0x03);
					ov3640_write_reg(0x8915,0xAC);
					ov3640_write_reg(0x8916,0x02);
					ov3640_write_reg(0x8917,0x12);
					ov3640_write_reg(0x8918,0x05);
					ov3640_write_reg(0x8919,0xA4);
					ov3640_write_reg(0x891A,0xEF);
					ov3640_write_reg(0x891B,0xC4);
					ov3640_write_reg(0x891C,0x54);
					ov3640_write_reg(0x891D,0x0F);
					ov3640_write_reg(0x891E,0x48);
					ov3640_write_reg(0x891F,0xF9);
					ov3640_write_reg(0x8920,0x12);
					ov3640_write_reg(0x8921,0x05);
					ov3640_write_reg(0x8922,0x9C);
					ov3640_write_reg(0x8923,0xEF);
					ov3640_write_reg(0x8924,0xC4);
					ov3640_write_reg(0x8925,0x54);
					ov3640_write_reg(0x8926,0x0F);
					ov3640_write_reg(0x8927,0x48);
					ov3640_write_reg(0x8928,0xFB);
					ov3640_write_reg(0x8929,0xE5);
					ov3640_write_reg(0x892A,0x0D);
					ov3640_write_reg(0x892B,0xAE);
					ov3640_write_reg(0x892C,0x0C);
					ov3640_write_reg(0x892D,0x78);
					ov3640_write_reg(0x892E,0x05);
					ov3640_write_reg(0x892F,0xCE);
					ov3640_write_reg(0x8930,0xC3);
					ov3640_write_reg(0x8931,0x13);
					ov3640_write_reg(0x8932,0xCE);
					ov3640_write_reg(0x8933,0x13);
					ov3640_write_reg(0x8934,0xD8);
					ov3640_write_reg(0x8935,0xF9);
					ov3640_write_reg(0x8936,0xFD);
					ov3640_write_reg(0x8937,0xAC);
					ov3640_write_reg(0x8938,0x06);
					ov3640_write_reg(0x8939,0x12);
					ov3640_write_reg(0x893A,0x05);
					ov3640_write_reg(0x893B,0xEC);
					ov3640_write_reg(0x893C,0x12);
					ov3640_write_reg(0x893D,0x05);
					ov3640_write_reg(0x893E,0xA3);
					ov3640_write_reg(0x893F,0xEF);
					ov3640_write_reg(0x8940,0xC4);
					ov3640_write_reg(0x8941,0x54);
					ov3640_write_reg(0x8942,0x0F);
					ov3640_write_reg(0x8943,0x48);
					ov3640_write_reg(0x8944,0xFA);
					ov3640_write_reg(0x8945,0xE5);
					ov3640_write_reg(0x8946,0x0D);
					ov3640_write_reg(0x8947,0xAE);
					ov3640_write_reg(0x8948,0x0C);
					ov3640_write_reg(0x8949,0x78);
					ov3640_write_reg(0x894A,0x05);
					ov3640_write_reg(0x894B,0xCE);
					ov3640_write_reg(0x894C,0xC3);
					ov3640_write_reg(0x894D,0x13);
					ov3640_write_reg(0x894E,0xCE);
					ov3640_write_reg(0x894F,0x13);
					ov3640_write_reg(0x8950,0xD8);
					ov3640_write_reg(0x8951,0xF9);
					ov3640_write_reg(0x8952,0xFD);
					ov3640_write_reg(0x8953,0xAC);
					ov3640_write_reg(0x8954,0x06);
					ov3640_write_reg(0x8955,0x12);
					ov3640_write_reg(0x8956,0x05);
					ov3640_write_reg(0x8957,0x9C);
					ov3640_write_reg(0x8958,0xEF);
					ov3640_write_reg(0x8959,0xC4);
					ov3640_write_reg(0x895A,0x54);
					ov3640_write_reg(0x895B,0x0F);
					ov3640_write_reg(0x895C,0x48);
					ov3640_write_reg(0x895D,0xFF);
					ov3640_write_reg(0x895E,0x90);
					ov3640_write_reg(0x895F,0x39);
					ov3640_write_reg(0x8960,0x0A);
					ov3640_write_reg(0x8961,0xEA);
					ov3640_write_reg(0x8962,0xF0);
					ov3640_write_reg(0x8963,0xA3);
					ov3640_write_reg(0x8964,0xE9);
					ov3640_write_reg(0x8965,0xF0);
					ov3640_write_reg(0x8966,0xA3);
					ov3640_write_reg(0x8967,0xEF);
					ov3640_write_reg(0x8968,0xF0);
					ov3640_write_reg(0x8969,0xA3);
					ov3640_write_reg(0x896A,0xEB);
					ov3640_write_reg(0x896B,0xF0);
					ov3640_write_reg(0x896C,0x22);
					ov3640_write_reg(0x896D,0xAB);
					ov3640_write_reg(0x896E,0x05);
					ov3640_write_reg(0x896F,0xAA);
					ov3640_write_reg(0x8970,0x04);
					ov3640_write_reg(0x8971,0x8F);
					ov3640_write_reg(0x8972,0x82);
					ov3640_write_reg(0x8973,0x8E);
					ov3640_write_reg(0x8974,0x83);
					ov3640_write_reg(0x8975,0x12);
					ov3640_write_reg(0x8976,0x05);
					ov3640_write_reg(0x8977,0xEC);
					ov3640_write_reg(0x8978,0xFE);
					ov3640_write_reg(0x8979,0xAD);
					ov3640_write_reg(0x897A,0x82);
					ov3640_write_reg(0x897B,0xAC);
					ov3640_write_reg(0x897C,0x83);
					ov3640_write_reg(0x897D,0x12);
					ov3640_write_reg(0x897E,0x05);
					ov3640_write_reg(0x897F,0xA4);
					ov3640_write_reg(0x8980,0x68);
					ov3640_write_reg(0x8981,0xF5);
					ov3640_write_reg(0x8982,0x0C);
					ov3640_write_reg(0x8983,0xEF);
					ov3640_write_reg(0x8984,0xC4);
					ov3640_write_reg(0x8985,0x54);
					ov3640_write_reg(0x8986,0x0F);
					ov3640_write_reg(0x8987,0x48);
					ov3640_write_reg(0x8988,0xF5);
					ov3640_write_reg(0x8989,0x0D);
					ov3640_write_reg(0x898A,0x12);
					ov3640_write_reg(0x898B,0x05);
					ov3640_write_reg(0x898C,0x9C);
					ov3640_write_reg(0x898D,0x68);
					ov3640_write_reg(0x898E,0xF5);
					ov3640_write_reg(0x898F,0x10);
					ov3640_write_reg(0x8990,0xEF);
					ov3640_write_reg(0x8991,0xC4);
					ov3640_write_reg(0x8992,0x54);
					ov3640_write_reg(0x8993,0x0F);
					ov3640_write_reg(0x8994,0x48);
					ov3640_write_reg(0x8995,0xF5);
					ov3640_write_reg(0x8996,0x11);
					ov3640_write_reg(0x8997,0x12);
					ov3640_write_reg(0x8998,0x05);
					ov3640_write_reg(0x8999,0xEC);
					ov3640_write_reg(0x899A,0xFE);
					ov3640_write_reg(0x899B,0xAD);
					ov3640_write_reg(0x899C,0x03);
					ov3640_write_reg(0x899D,0xAC);
					ov3640_write_reg(0x899E,0x02);
					ov3640_write_reg(0x899F,0x12);
					ov3640_write_reg(0x89A0,0x05);
					ov3640_write_reg(0x89A1,0xA4);
					ov3640_write_reg(0x89A2,0x68);
					ov3640_write_reg(0x89A3,0xF5);
					ov3640_write_reg(0x89A4,0x0E);
					ov3640_write_reg(0x89A5,0xEF);
					ov3640_write_reg(0x89A6,0xC4);
					ov3640_write_reg(0x89A7,0x54);
					ov3640_write_reg(0x89A8,0x0F);
					ov3640_write_reg(0x89A9,0x48);
					ov3640_write_reg(0x89AA,0xF5);
					ov3640_write_reg(0x89AB,0x0F);
					ov3640_write_reg(0x89AC,0x12);
					ov3640_write_reg(0x89AD,0x05);
					ov3640_write_reg(0x89AE,0x9C);
					ov3640_write_reg(0x89AF,0x68);
					ov3640_write_reg(0x89B0,0xFE);
					ov3640_write_reg(0x89B1,0xEF);
					ov3640_write_reg(0x89B2,0xC4);
					ov3640_write_reg(0x89B3,0x54);
					ov3640_write_reg(0x89B4,0x0F);
					ov3640_write_reg(0x89B5,0x48);
					ov3640_write_reg(0x89B6,0xFD);
					ov3640_write_reg(0x89B7,0xAC);
					ov3640_write_reg(0x89B8,0x06);
					ov3640_write_reg(0x89B9,0xE5);
					ov3640_write_reg(0x89BA,0x0C);
					ov3640_write_reg(0x89BB,0x54);
					ov3640_write_reg(0x89BC,0x0F);
					ov3640_write_reg(0x89BD,0xFB);
					ov3640_write_reg(0x89BE,0xE5);
					ov3640_write_reg(0x89BF,0x0E);
					ov3640_write_reg(0x89C0,0x12);
					ov3640_write_reg(0x89C1,0x06);
					ov3640_write_reg(0x89C2,0x46);
					ov3640_write_reg(0x89C3,0x4B);
					ov3640_write_reg(0x89C4,0xFB);
					ov3640_write_reg(0x89C5,0xE5);
					ov3640_write_reg(0x89C6,0x10);
					ov3640_write_reg(0x89C7,0x54);
					ov3640_write_reg(0x89C8,0x0F);
					ov3640_write_reg(0x89C9,0xFA);
					ov3640_write_reg(0x89CA,0xEC);
					ov3640_write_reg(0x89CB,0x12);
					ov3640_write_reg(0x89CC,0x06);
					ov3640_write_reg(0x89CD,0x46);
					ov3640_write_reg(0x89CE,0x4A);
					ov3640_write_reg(0x89CF,0xFF);
					ov3640_write_reg(0x89D0,0x90);
					ov3640_write_reg(0x89D1,0x33);
					ov3640_write_reg(0x89D2,0xAA);
					ov3640_write_reg(0x89D3,0xEB);
					ov3640_write_reg(0x89D4,0xF0);
					ov3640_write_reg(0x89D5,0xE5);
					ov3640_write_reg(0x89D6,0x0D);
					ov3640_write_reg(0x89D7,0xA3);
					ov3640_write_reg(0x89D8,0xF0);
					ov3640_write_reg(0x89D9,0xE5);
					ov3640_write_reg(0x89DA,0x0F);
					ov3640_write_reg(0x89DB,0xA3);
					ov3640_write_reg(0x89DC,0xF0);
					ov3640_write_reg(0x89DD,0xA3);
					ov3640_write_reg(0x89DE,0xEF);
					ov3640_write_reg(0x89DF,0xF0);
					ov3640_write_reg(0x89E0,0xE5);
					ov3640_write_reg(0x89E1,0x11);
					ov3640_write_reg(0x89E2,0xA3);
					ov3640_write_reg(0x89E3,0xF0);
					ov3640_write_reg(0x89E4,0xAF);
					ov3640_write_reg(0x89E5,0x05);
					ov3640_write_reg(0x89E6,0xEF);
					ov3640_write_reg(0x89E7,0xA3);
					ov3640_write_reg(0x89E8,0xF0);
					ov3640_write_reg(0x89E9,0x22);
					ov3640_write_reg(0x89EA,0x90);
					ov3640_write_reg(0x89EB,0x3F);
					ov3640_write_reg(0x89EC,0x05);
					ov3640_write_reg(0x89ED,0xE0);
					ov3640_write_reg(0x89EE,0x54);
					ov3640_write_reg(0x89EF,0xE0);
					ov3640_write_reg(0x89F0,0xF5);
					ov3640_write_reg(0x89F1,0x08);
					ov3640_write_reg(0x89F2,0xE0);
					ov3640_write_reg(0x89F3,0x54);
					ov3640_write_reg(0x89F4,0x1F);
					ov3640_write_reg(0x89F5,0xF0);
					ov3640_write_reg(0x89F6,0xE5);
					ov3640_write_reg(0x89F7,0x08);
					ov3640_write_reg(0x89F8,0xB4);
					ov3640_write_reg(0x89F9,0x80);
					ov3640_write_reg(0x89FA,0x1D);
					ov3640_write_reg(0x89FB,0xC3);
					ov3640_write_reg(0x89FC,0xE5);
					ov3640_write_reg(0x89FD,0x4C);
					ov3640_write_reg(0x89FE,0x94);
					ov3640_write_reg(0x89FF,0xFF);
					ov3640_write_reg(0x8A00,0xE5);
					ov3640_write_reg(0x8A01,0x4B);
					ov3640_write_reg(0x8A02,0x94);
					ov3640_write_reg(0x8A03,0x03);
					ov3640_write_reg(0x8A04,0x40);
					ov3640_write_reg(0x8A05,0x08);
					ov3640_write_reg(0x8A06,0x75);
					ov3640_write_reg(0x8A07,0x4B);
					ov3640_write_reg(0x8A08,0x03);
					ov3640_write_reg(0x8A09,0x75);
					ov3640_write_reg(0x8A0A,0x4C);
					ov3640_write_reg(0x8A0B,0xFF);
					ov3640_write_reg(0x8A0C,0x80);
					ov3640_write_reg(0x8A0D,0x4F);
					ov3640_write_reg(0x8A0E,0x05);
					ov3640_write_reg(0x8A0F,0x4C);
					ov3640_write_reg(0x8A10,0xE5);
					ov3640_write_reg(0x8A11,0x4C);
					ov3640_write_reg(0x8A12,0x70);
					ov3640_write_reg(0x8A13,0x02);
					ov3640_write_reg(0x8A14,0x05);
					ov3640_write_reg(0x8A15,0x4B);
					ov3640_write_reg(0x8A16,0x80);
					ov3640_write_reg(0x8A17,0x45);
					ov3640_write_reg(0x8A18,0xE5);
					ov3640_write_reg(0x8A19,0x08);
					ov3640_write_reg(0x8A1A,0xB4);
					ov3640_write_reg(0x8A1B,0x40);
					ov3640_write_reg(0x8A1C,0x16);
					ov3640_write_reg(0x8A1D,0xE5);
					ov3640_write_reg(0x8A1E,0x4C);
					ov3640_write_reg(0x8A1F,0x45);
					ov3640_write_reg(0x8A20,0x4B);
					ov3640_write_reg(0x8A21,0x70);
					ov3640_write_reg(0x8A22,0x06);
					ov3640_write_reg(0x8A23,0xF5);
					ov3640_write_reg(0x8A24,0x4B);
					ov3640_write_reg(0x8A25,0xF5);
					ov3640_write_reg(0x8A26,0x4C);
					ov3640_write_reg(0x8A27,0x80);
					ov3640_write_reg(0x8A28,0x08);
					ov3640_write_reg(0x8A29,0xE5);
					ov3640_write_reg(0x8A2A,0x4C);
					ov3640_write_reg(0x8A2B,0x15);
					ov3640_write_reg(0x8A2C,0x4C);
					ov3640_write_reg(0x8A2D,0x70);
					ov3640_write_reg(0x8A2E,0x02);
					ov3640_write_reg(0x8A2F,0x15);
					ov3640_write_reg(0x8A30,0x4B);
					ov3640_write_reg(0x8A31,0x80);
					ov3640_write_reg(0x8A32,0x2A);
					ov3640_write_reg(0x8A33,0xE5);
					ov3640_write_reg(0x8A34,0x08);
					ov3640_write_reg(0x8A35,0x64);
					ov3640_write_reg(0x8A36,0x20);
					ov3640_write_reg(0x8A37,0x70);
					ov3640_write_reg(0x8A38,0x2B);
					ov3640_write_reg(0x8A39,0x90);
					ov3640_write_reg(0x8A3A,0x3F);
					ov3640_write_reg(0x8A3B,0x05);
					ov3640_write_reg(0x8A3C,0xE0);
					ov3640_write_reg(0x8A3D,0x54);
					ov3640_write_reg(0x8A3E,0x03);
					ov3640_write_reg(0x8A3F,0xFE);
					ov3640_write_reg(0x8A40,0xA3);
					ov3640_write_reg(0x8A41,0xE0);
					ov3640_write_reg(0x8A42,0x7C);
					ov3640_write_reg(0x8A43,0x00);
					ov3640_write_reg(0x8A44,0x24);
					ov3640_write_reg(0x8A45,0x00);
					ov3640_write_reg(0x8A46,0xF5);
					ov3640_write_reg(0x8A47,0x4C);
					ov3640_write_reg(0x8A48,0xEC);
					ov3640_write_reg(0x8A49,0x3E);
					ov3640_write_reg(0x8A4A,0xF5);
					ov3640_write_reg(0x8A4B,0x4B);
					ov3640_write_reg(0x8A4C,0xD3);
					ov3640_write_reg(0x8A4D,0xE5);
					ov3640_write_reg(0x8A4E,0x4C);
					ov3640_write_reg(0x8A4F,0x94);
					ov3640_write_reg(0x8A50,0xFF);
					ov3640_write_reg(0x8A51,0xE5);
					ov3640_write_reg(0x8A52,0x4B);
					ov3640_write_reg(0x8A53,0x94);
					ov3640_write_reg(0x8A54,0x03);
					ov3640_write_reg(0x8A55,0x40);
					ov3640_write_reg(0x8A56,0x06);
					ov3640_write_reg(0x8A57,0x75);
					ov3640_write_reg(0x8A58,0x4B);
					ov3640_write_reg(0x8A59,0x03);
					ov3640_write_reg(0x8A5A,0x75);
					ov3640_write_reg(0x8A5B,0x4C);
					ov3640_write_reg(0x8A5C,0xFF);
					ov3640_write_reg(0x8A5D,0xAF);
					ov3640_write_reg(0x8A5E,0x4C);
					ov3640_write_reg(0x8A5F,0xAE);
					ov3640_write_reg(0x8A60,0x4B);
					ov3640_write_reg(0x8A61,0x12);
					ov3640_write_reg(0x8A62,0x0B);
					ov3640_write_reg(0x8A63,0x7A);
					ov3640_write_reg(0x8A64,0x22);
					ov3640_write_reg(0x8A65,0xE5);
					ov3640_write_reg(0x8A66,0x3C);
					ov3640_write_reg(0x8A67,0xD3);
					ov3640_write_reg(0x8A68,0x94);
					ov3640_write_reg(0x8A69,0x02);
					ov3640_write_reg(0x8A6A,0x40);
					ov3640_write_reg(0x8A6B,0x03);
					ov3640_write_reg(0x8A6C,0x15);
					ov3640_write_reg(0x8A6D,0x3C);
					ov3640_write_reg(0x8A6E,0x22);
					ov3640_write_reg(0x8A6F,0xE5);
					ov3640_write_reg(0x8A70,0x3C);
					ov3640_write_reg(0x8A71,0xB4);
					ov3640_write_reg(0x8A72,0x02);
					ov3640_write_reg(0x8A73,0x0D);
					ov3640_write_reg(0x8A74,0xE4);
					ov3640_write_reg(0x8A75,0xF5);
					ov3640_write_reg(0x8A76,0x3C);
					ov3640_write_reg(0x8A77,0xFD);
					ov3640_write_reg(0x8A78,0xFF);
					ov3640_write_reg(0x8A79,0x12);
					ov3640_write_reg(0x8A7A,0x0B);
					ov3640_write_reg(0x8A7B,0x2C);
					ov3640_write_reg(0x8A7C,0x8E);
					ov3640_write_reg(0x8A7D,0x2B);
					ov3640_write_reg(0x8A7E,0x8F);
					ov3640_write_reg(0x8A7F,0x2C);
					ov3640_write_reg(0x8A80,0x22);
					ov3640_write_reg(0x8A81,0xE4);
					ov3640_write_reg(0x8A82,0xFD);
					ov3640_write_reg(0x8A83,0xFF);
					ov3640_write_reg(0x8A84,0x12);
					ov3640_write_reg(0x8A85,0x0B);
					ov3640_write_reg(0x8A86,0x2C);
					ov3640_write_reg(0x8A87,0x8E);
					ov3640_write_reg(0x8A88,0x08);
					ov3640_write_reg(0x8A89,0x8F);
					ov3640_write_reg(0x8A8A,0x09);
					ov3640_write_reg(0x8A8B,0xC3);
					ov3640_write_reg(0x8A8C,0xE5);
					ov3640_write_reg(0x8A8D,0x09);
					ov3640_write_reg(0x8A8E,0x95);
					ov3640_write_reg(0x8A8F,0x2C);
					ov3640_write_reg(0x8A90,0xFF);
					ov3640_write_reg(0x8A91,0xE5);
					ov3640_write_reg(0x8A92,0x08);
					ov3640_write_reg(0x8A93,0x95);
					ov3640_write_reg(0x8A94,0x2B);
					ov3640_write_reg(0x8A95,0xFE);
					ov3640_write_reg(0x8A96,0x12);
					ov3640_write_reg(0x8A97,0x0C);
					ov3640_write_reg(0x8A98,0xF7);
					ov3640_write_reg(0x8A99,0x8E);
					ov3640_write_reg(0x8A9A,0x0A);
					ov3640_write_reg(0x8A9B,0x8F);
					ov3640_write_reg(0x8A9C,0x0B);
					ov3640_write_reg(0x8A9D,0xE5);
					ov3640_write_reg(0x8A9E,0x29);
					ov3640_write_reg(0x8A9F,0xD3);
					ov3640_write_reg(0x8AA0,0x94);
					ov3640_write_reg(0x8AA1,0x02);
					ov3640_write_reg(0x8AA2,0x40);
					ov3640_write_reg(0x8AA3,0x28);
					ov3640_write_reg(0x8AA4,0x12);
					ov3640_write_reg(0x8AA5,0x06);
					ov3640_write_reg(0x8AA6,0x76);
					ov3640_write_reg(0x8AA7,0x50);
					ov3640_write_reg(0x8AA8,0x05);
					ov3640_write_reg(0x8AA9,0x12);
					ov3640_write_reg(0x8AAA,0x0C);
					ov3640_write_reg(0x8AAB,0xB6);
					ov3640_write_reg(0x8AAC,0x50);
					ov3640_write_reg(0x8AAD,0x0A);
					ov3640_write_reg(0x8AAE,0x85);
					ov3640_write_reg(0x8AAF,0x08);
					ov3640_write_reg(0x8AB0,0x2B);
					ov3640_write_reg(0x8AB1,0x85);
					ov3640_write_reg(0x8AB2,0x09);
					ov3640_write_reg(0x8AB3,0x2C);
					ov3640_write_reg(0x8AB4,0xE4);
					ov3640_write_reg(0x8AB5,0xF5);
					ov3640_write_reg(0x8AB6,0x2A);
					ov3640_write_reg(0x8AB7,0x22);
					ov3640_write_reg(0x8AB8,0x05);
					ov3640_write_reg(0x8AB9,0x2A);
					ov3640_write_reg(0x8ABA,0xE5);
					ov3640_write_reg(0x8ABB,0x2A);
					ov3640_write_reg(0x8ABC,0xD3);
					ov3640_write_reg(0x8ABD,0x94);
					ov3640_write_reg(0x8ABE,0x02);
					ov3640_write_reg(0x8ABF,0x40);
					ov3640_write_reg(0x8AC0,0x1B);
					ov3640_write_reg(0x8AC1,0xE4);
					ov3640_write_reg(0x8AC2,0xF5);
					ov3640_write_reg(0x8AC3,0x29);
					ov3640_write_reg(0x8AC4,0xF5);
					ov3640_write_reg(0x8AC5,0x2A);
					ov3640_write_reg(0x8AC6,0x75);
					ov3640_write_reg(0x8AC7,0x3C);
					ov3640_write_reg(0x8AC8,0x01);
					ov3640_write_reg(0x8AC9,0x02);
					ov3640_write_reg(0x8ACA,0x02);
					ov3640_write_reg(0x8ACB,0x7B);
					ov3640_write_reg(0x8ACC,0x12);
					ov3640_write_reg(0x8ACD,0x06);
					ov3640_write_reg(0x8ACE,0x76);
					ov3640_write_reg(0x8ACF,0x50);
					ov3640_write_reg(0x8AD0,0x05);
					ov3640_write_reg(0x8AD1,0x12);
					ov3640_write_reg(0x8AD2,0x0C);
					ov3640_write_reg(0x8AD3,0xB6);
					ov3640_write_reg(0x8AD4,0x50);
					ov3640_write_reg(0x8AD5,0x03);
					ov3640_write_reg(0x8AD6,0x05);
					ov3640_write_reg(0x8AD7,0x29);
					ov3640_write_reg(0x8AD8,0x22);
					ov3640_write_reg(0x8AD9,0xE4);
					ov3640_write_reg(0x8ADA,0xF5);
					ov3640_write_reg(0x8ADB,0x29);
					ov3640_write_reg(0x8ADC,0x22);
					ov3640_write_reg(0x8ADD,0x7D);
					ov3640_write_reg(0x8ADE,0x08);
					ov3640_write_reg(0x8ADF,0xEF);
					ov3640_write_reg(0x8AE0,0x33);
					ov3640_write_reg(0x8AE1,0x92);
					ov3640_write_reg(0x8AE2,0x01);
					ov3640_write_reg(0x8AE3,0x12);
					ov3640_write_reg(0x8AE4,0x05);
					ov3640_write_reg(0x8AE5,0xC8);
					ov3640_write_reg(0x8AE6,0xEF);
					ov3640_write_reg(0x8AE7,0x25);
					ov3640_write_reg(0x8AE8,0xE0);
					ov3640_write_reg(0x8AE9,0xFF);
					ov3640_write_reg(0x8AEA,0xD2);
					ov3640_write_reg(0x8AEB,0x00);
					ov3640_write_reg(0x8AEC,0xE5);
					ov3640_write_reg(0x8AED,0x20);
					ov3640_write_reg(0x8AEE,0xF0);
					ov3640_write_reg(0x8AEF,0x7E);
					ov3640_write_reg(0x8AF0,0x01);
					ov3640_write_reg(0x8AF1,0xAC);
					ov3640_write_reg(0x8AF2,0x06);
					ov3640_write_reg(0x8AF3,0x1E);
					ov3640_write_reg(0x8AF4,0xEC);
					ov3640_write_reg(0x8AF5,0x70);
					ov3640_write_reg(0x8AF6,0xFA);
					ov3640_write_reg(0x8AF7,0x12);
					ov3640_write_reg(0x8AF8,0x05);
					ov3640_write_reg(0x8AF9,0xC6);
					ov3640_write_reg(0x8AFA,0xDD);
					ov3640_write_reg(0x8AFB,0xE3);
					ov3640_write_reg(0x8AFC,0x90);
					ov3640_write_reg(0x8AFD,0x30);
					ov3640_write_reg(0x8AFE,0xB1);
					ov3640_write_reg(0x8AFF,0xE0);
					ov3640_write_reg(0x8B00,0x54);
					ov3640_write_reg(0x8B01,0x7F);
					ov3640_write_reg(0x8B02,0xF0);
					ov3640_write_reg(0x8B03,0xD2);
					ov3640_write_reg(0x8B04,0x00);
					ov3640_write_reg(0x8B05,0x12);
					ov3640_write_reg(0x8B06,0x05);
					ov3640_write_reg(0x8B07,0xC8);
					ov3640_write_reg(0x8B08,0x7E);
					ov3640_write_reg(0x8B09,0x01);
					ov3640_write_reg(0x8B0A,0xAF);
					ov3640_write_reg(0x8B0B,0x06);
					ov3640_write_reg(0x8B0C,0x1E);
					ov3640_write_reg(0x8B0D,0xEF);
					ov3640_write_reg(0x8B0E,0x70);
					ov3640_write_reg(0x8B0F,0xFA);
					ov3640_write_reg(0x8B10,0x90);
					ov3640_write_reg(0x8B11,0x30);
					ov3640_write_reg(0x8B12,0xB5);
					ov3640_write_reg(0x8B13,0xE0);
					ov3640_write_reg(0x8B14,0x54);
					ov3640_write_reg(0x8B15,0x02);
					ov3640_write_reg(0x8B16,0xF5);
					ov3640_write_reg(0x8B17,0x10);
					ov3640_write_reg(0x8B18,0x12);
					ov3640_write_reg(0x8B19,0x05);
					ov3640_write_reg(0x8B1A,0xC6);
					ov3640_write_reg(0x8B1B,0x90);
					ov3640_write_reg(0x8B1C,0x30);
					ov3640_write_reg(0x8B1D,0xB1);
					ov3640_write_reg(0x8B1E,0xE0);
					ov3640_write_reg(0x8B1F,0x44);
					ov3640_write_reg(0x8B20,0x80);
					ov3640_write_reg(0x8B21,0xF0);
					ov3640_write_reg(0x8B22,0x7E);
					ov3640_write_reg(0x8B23,0x01);
					ov3640_write_reg(0x8B24,0xAF);
					ov3640_write_reg(0x8B25,0x06);
					ov3640_write_reg(0x8B26,0x1E);
					ov3640_write_reg(0x8B27,0xEF);
					ov3640_write_reg(0x8B28,0x70);
					ov3640_write_reg(0x8B29,0xFA);
					ov3640_write_reg(0x8B2A,0xD3);
					ov3640_write_reg(0x8B2B,0x22);
					ov3640_write_reg(0x8B2C,0xED);
					ov3640_write_reg(0x8B2D,0x70);
					ov3640_write_reg(0x8B2E,0x1E);
					ov3640_write_reg(0x8B2F,0x12);
					ov3640_write_reg(0x8B30,0x06);
					ov3640_write_reg(0x8B31,0x3F);
					ov3640_write_reg(0x8B32,0x24);
					ov3640_write_reg(0x8B33,0x80);
					ov3640_write_reg(0x8B34,0x12);
					ov3640_write_reg(0x8B35,0x05);
					ov3640_write_reg(0x8B36,0xCF);
					ov3640_write_reg(0x8B37,0xF5);
					ov3640_write_reg(0x8B38,0x0C);
					ov3640_write_reg(0x8B39,0xEE);
					ov3640_write_reg(0x8B3A,0x24);
					ov3640_write_reg(0x8B3B,0x81);
					ov3640_write_reg(0x8B3C,0x12);
					ov3640_write_reg(0x8B3D,0x05);
					ov3640_write_reg(0x8B3E,0xCF);
					ov3640_write_reg(0x8B3F,0x12);
					ov3640_write_reg(0x8B40,0x06);
					ov3640_write_reg(0x8B41,0x3E);
					ov3640_write_reg(0x8B42,0x24);
					ov3640_write_reg(0x8B43,0x82);
					ov3640_write_reg(0x8B44,0x12);
					ov3640_write_reg(0x8B45,0x05);
					ov3640_write_reg(0x8B46,0xCF);
					ov3640_write_reg(0x8B47,0xFC);
					ov3640_write_reg(0x8B48,0xEE);
					ov3640_write_reg(0x8B49,0x24);
					ov3640_write_reg(0x8B4A,0x83);
					ov3640_write_reg(0x8B4B,0x80);
					ov3640_write_reg(0x8B4C,0x21);
					ov3640_write_reg(0x8B4D,0xED);
					ov3640_write_reg(0x8B4E,0x64);
					ov3640_write_reg(0x8B4F,0x01);
					ov3640_write_reg(0x8B50,0x70);
					ov3640_write_reg(0x8B51,0x1F);
					ov3640_write_reg(0x8B52,0x12);
					ov3640_write_reg(0x8B53,0x06);
					ov3640_write_reg(0x8B54,0x3F);
					ov3640_write_reg(0x8B55,0x24);
					ov3640_write_reg(0x8B56,0x84);
					ov3640_write_reg(0x8B57,0x12);
					ov3640_write_reg(0x8B58,0x05);
					ov3640_write_reg(0x8B59,0xCF);
					ov3640_write_reg(0x8B5A,0xF5);
					ov3640_write_reg(0x8B5B,0x0C);
					ov3640_write_reg(0x8B5C,0xEE);
					ov3640_write_reg(0x8B5D,0x24);
					ov3640_write_reg(0x8B5E,0x85);
					ov3640_write_reg(0x8B5F,0x12);
					ov3640_write_reg(0x8B60,0x05);
					ov3640_write_reg(0x8B61,0xCF);
					ov3640_write_reg(0x8B62,0x12);
					ov3640_write_reg(0x8B63,0x06);
					ov3640_write_reg(0x8B64,0x3E);
					ov3640_write_reg(0x8B65,0x24);
					ov3640_write_reg(0x8B66,0x86);
					ov3640_write_reg(0x8B67,0x12);
					ov3640_write_reg(0x8B68,0x05);
					ov3640_write_reg(0x8B69,0xCF);
					ov3640_write_reg(0x8B6A,0xFC);
					ov3640_write_reg(0x8B6B,0xEE);
					ov3640_write_reg(0x8B6C,0x24);
					ov3640_write_reg(0x8B6D,0x87);
					ov3640_write_reg(0x8B6E,0x12);
					ov3640_write_reg(0x8B6F,0x05);
					ov3640_write_reg(0x8B70,0xCF);
					ov3640_write_reg(0x8B71,0xEC);
					ov3640_write_reg(0x8B72,0xFE);
					ov3640_write_reg(0x8B73,0xEB);
					ov3640_write_reg(0x8B74,0xF5);
					ov3640_write_reg(0x8B75,0x82);
					ov3640_write_reg(0x8B76,0xE5);
					ov3640_write_reg(0x8B77,0x82);
					ov3640_write_reg(0x8B78,0xFF);
					ov3640_write_reg(0x8B79,0x22);
					ov3640_write_reg(0x8B7A,0x8E);
					ov3640_write_reg(0x8B7B,0x0C);
					ov3640_write_reg(0x8B7C,0x8F);
					ov3640_write_reg(0x8B7D,0x0D);
					ov3640_write_reg(0x8B7E,0xE5);
					ov3640_write_reg(0x8B7F,0x0C);
					ov3640_write_reg(0x8B80,0x54);
					ov3640_write_reg(0x8B81,0x03);
					ov3640_write_reg(0x8B82,0xFC);
					ov3640_write_reg(0x8B83,0xAD);
					ov3640_write_reg(0x8B84,0x0D);
					ov3640_write_reg(0x8B85,0xED);
					ov3640_write_reg(0x8B86,0xC4);
					ov3640_write_reg(0x8B87,0xF8);
					ov3640_write_reg(0x8B88,0x54);
					ov3640_write_reg(0x8B89,0x0F);
					ov3640_write_reg(0x8B8A,0xC8);
					ov3640_write_reg(0x8B8B,0x68);
					ov3640_write_reg(0x8B8C,0xFF);
					ov3640_write_reg(0x8B8D,0xEC);
					ov3640_write_reg(0x8B8E,0xC4);
					ov3640_write_reg(0x8B8F,0x54);
					ov3640_write_reg(0x8B90,0xF0);
					ov3640_write_reg(0x8B91,0x48);
					ov3640_write_reg(0x8B92,0xAB);
					ov3640_write_reg(0x8B93,0x07);
					ov3640_write_reg(0x8B94,0xFA);
					ov3640_write_reg(0x8B95,0xEC);
					ov3640_write_reg(0x8B96,0x90);
					ov3640_write_reg(0x8B97,0x3F);
					ov3640_write_reg(0x8B98,0x05);
					ov3640_write_reg(0x8B99,0xF0);
					ov3640_write_reg(0x8B9A,0xA3);
					ov3640_write_reg(0x8B9B,0xE5);
					ov3640_write_reg(0x8B9C,0x0D);
					ov3640_write_reg(0x8B9D,0xF0);
					ov3640_write_reg(0x8B9E,0x45);
					ov3640_write_reg(0x8B9F,0x0C);
					ov3640_write_reg(0x8BA0,0x70);
					ov3640_write_reg(0x8BA1,0x03);
					ov3640_write_reg(0x8BA2,0x7A);
					ov3640_write_reg(0x8BA3,0x80);
					ov3640_write_reg(0x8BA4,0xFB);
					ov3640_write_reg(0x8BA5,0x43);
					ov3640_write_reg(0x8BA6,0x03);
					ov3640_write_reg(0x8BA7,0x0F);
					ov3640_write_reg(0x8BA8,0xAF);
					ov3640_write_reg(0x8BA9,0x03);
					ov3640_write_reg(0x8BAA,0xAE);
					ov3640_write_reg(0x8BAB,0x02);
					ov3640_write_reg(0x8BAC,0x12);
					ov3640_write_reg(0x8BAD,0x0C);
					ov3640_write_reg(0x8BAE,0x22);
					ov3640_write_reg(0x8BAF,0xE5);
					ov3640_write_reg(0x8BB0,0x0C);
					ov3640_write_reg(0x8BB1,0x54);
					ov3640_write_reg(0x8BB2,0x03);
					ov3640_write_reg(0x8BB3,0xF5);
					ov3640_write_reg(0x8BB4,0x5B);
					ov3640_write_reg(0x8BB5,0x85);
					ov3640_write_reg(0x8BB6,0x0D);
					ov3640_write_reg(0x8BB7,0x5C);
					ov3640_write_reg(0x8BB8,0x22);
					ov3640_write_reg(0x8BB9,0x02);
					ov3640_write_reg(0x8BBA,0x3D);
					ov3640_write_reg(0x8BBB,0x00);
					ov3640_write_reg(0x8BBC,0x96);
					ov3640_write_reg(0x8BBD,0x01);
					ov3640_write_reg(0x8BBE,0x3C);
					ov3640_write_reg(0x8BBF,0x00);
					ov3640_write_reg(0x8BC0,0x01);
					ov3640_write_reg(0x8BC1,0x72);
					ov3640_write_reg(0x8BC2,0x00);
					ov3640_write_reg(0x8BC3,0x01);
					ov3640_write_reg(0x8BC4,0x46);
					ov3640_write_reg(0x8BC5,0x01);
					ov3640_write_reg(0x8BC6,0x02);
					ov3640_write_reg(0x8BC7,0x49);
					ov3640_write_reg(0x8BC8,0x00);
					ov3640_write_reg(0x8BC9,0x00);
					ov3640_write_reg(0x8BCA,0x02);
					ov3640_write_reg(0x8BCB,0x41);
					ov3640_write_reg(0x8BCC,0x00);
					ov3640_write_reg(0x8BCD,0x00);
					ov3640_write_reg(0x8BCE,0x02);
					ov3640_write_reg(0x8BCF,0x47);
					ov3640_write_reg(0x8BD0,0x00);
					ov3640_write_reg(0x8BD1,0x00);
					ov3640_write_reg(0x8BD2,0x02);
					ov3640_write_reg(0x8BD3,0x3F);
					ov3640_write_reg(0x8BD4,0x00);
					ov3640_write_reg(0x8BD5,0x00);
					ov3640_write_reg(0x8BD6,0x01);
					ov3640_write_reg(0x8BD7,0x43);
					ov3640_write_reg(0x8BD8,0x00);
					ov3640_write_reg(0x8BD9,0x01);
					ov3640_write_reg(0x8BDA,0x61);
					ov3640_write_reg(0x8BDB,0x00);
					ov3640_write_reg(0x8BDC,0x01);
					ov3640_write_reg(0x8BDD,0x45);
					ov3640_write_reg(0x8BDE,0x00);
					ov3640_write_reg(0x8BDF,0x02);
					ov3640_write_reg(0x8BE0,0x4F);
					ov3640_write_reg(0x8BE1,0x00);
					ov3640_write_reg(0x8BE2,0x00);
					ov3640_write_reg(0x8BE3,0xC1);
					ov3640_write_reg(0x8BE4,0x0D);
					ov3640_write_reg(0x8BE5,0xC1);
					ov3640_write_reg(0x8BE6,0x0A);
					ov3640_write_reg(0x8BE7,0xC1);
					ov3640_write_reg(0x8BE8,0x09);
					ov3640_write_reg(0x8BE9,0xC1);
					ov3640_write_reg(0x8BEA,0x0E);
					ov3640_write_reg(0x8BEB,0x01);
					ov3640_write_reg(0x8BEC,0x44);
					ov3640_write_reg(0x8BED,0x07);
					ov3640_write_reg(0x8BEE,0x00);
					ov3640_write_reg(0x8BEF,0x12);
					ov3640_write_reg(0x8BF0,0x08);
					ov3640_write_reg(0x8BF1,0x6C);
					ov3640_write_reg(0x8BF2,0x12);
					ov3640_write_reg(0x8BF3,0x0C);
					ov3640_write_reg(0x8BF4,0xEA);
					ov3640_write_reg(0x8BF5,0x12);
					ov3640_write_reg(0x8BF6,0x06);
					ov3640_write_reg(0x8BF7,0x80);
					ov3640_write_reg(0x8BF8,0x12);
					ov3640_write_reg(0x8BF9,0x04);
					ov3640_write_reg(0x8BFA,0x97);
					ov3640_write_reg(0x8BFB,0x30);
					ov3640_write_reg(0x8BFC,0x08);
					ov3640_write_reg(0x8BFD,0xF7);
					ov3640_write_reg(0x8BFE,0xC2);
					ov3640_write_reg(0x8BFF,0x08);
					ov3640_write_reg(0x8C00,0x30);
					ov3640_write_reg(0x8C01,0x0B);
					ov3640_write_reg(0x8C02,0x05);
					ov3640_write_reg(0x8C03,0x12);
					ov3640_write_reg(0x8C04,0x07);
					ov3640_write_reg(0x8C05,0x43);
					ov3640_write_reg(0x8C06,0x80);
					ov3640_write_reg(0x8C07,0xED);
					ov3640_write_reg(0x8C08,0xE5);
					ov3640_write_reg(0x8C09,0x3C);
					ov3640_write_reg(0x8C0A,0xB4);
					ov3640_write_reg(0x8C0B,0x01);
					ov3640_write_reg(0x8C0C,0x05);
					ov3640_write_reg(0x8C0D,0x12);
					ov3640_write_reg(0x8C0E,0x02);
					ov3640_write_reg(0x8C0F,0x7B);
					ov3640_write_reg(0x8C10,0x80);
					ov3640_write_reg(0x8C11,0xE3);
					ov3640_write_reg(0x8C12,0x30);
					ov3640_write_reg(0x8C13,0x0C);
					ov3640_write_reg(0x8C14,0x05);
					ov3640_write_reg(0x8C15,0x12);
					ov3640_write_reg(0x8C16,0x0A);
					ov3640_write_reg(0x8C17,0x65);
					ov3640_write_reg(0x8C18,0x80);
					ov3640_write_reg(0x8C19,0xDB);
					ov3640_write_reg(0x8C1A,0x30);
					ov3640_write_reg(0x8C1B,0x0D);
					ov3640_write_reg(0x8C1C,0xD8);
					ov3640_write_reg(0x8C1D,0x12);
					ov3640_write_reg(0x8C1E,0x09);
					ov3640_write_reg(0x8C1F,0xEA);
					ov3640_write_reg(0x8C20,0x80);
					ov3640_write_reg(0x8C21,0xD3);
					ov3640_write_reg(0x8C22,0x8E);
					ov3640_write_reg(0x8C23,0x0E);
					ov3640_write_reg(0x8C24,0x8F);
					ov3640_write_reg(0x8C25,0x0F);
					ov3640_write_reg(0x8C26,0x12);
					ov3640_write_reg(0x8C27,0x0C);
					ov3640_write_reg(0x8C28,0x96);
					ov3640_write_reg(0x8C29,0x7F);
					ov3640_write_reg(0x8C2A,0x18);
					ov3640_write_reg(0x8C2B,0x12);
					ov3640_write_reg(0x8C2C,0x0A);
					ov3640_write_reg(0x8C2D,0xDD);
					ov3640_write_reg(0x8C2E,0x40);
					ov3640_write_reg(0x8C2F,0x02);
					ov3640_write_reg(0x8C30,0x80);
					ov3640_write_reg(0x8C31,0x13);
					ov3640_write_reg(0x8C32,0xE5);
					ov3640_write_reg(0x8C33,0x0E);
					ov3640_write_reg(0x8C34,0xFF);
					ov3640_write_reg(0x8C35,0x12);
					ov3640_write_reg(0x8C36,0x0A);
					ov3640_write_reg(0x8C37,0xDD);
					ov3640_write_reg(0x8C38,0x40);
					ov3640_write_reg(0x8C39,0x02);
					ov3640_write_reg(0x8C3A,0x80);
					ov3640_write_reg(0x8C3B,0x09);
					ov3640_write_reg(0x8C3C,0xAF);
					ov3640_write_reg(0x8C3D,0x0F);
					ov3640_write_reg(0x8C3E,0xE5);
					ov3640_write_reg(0x8C3F,0x0F);
					ov3640_write_reg(0x8C40,0x12);
					ov3640_write_reg(0x8C41,0x0A);
					ov3640_write_reg(0x8C42,0xDD);
					ov3640_write_reg(0x8C43,0x40);
					ov3640_write_reg(0x8C44,0x05);
					ov3640_write_reg(0x8C45,0x12);
					ov3640_write_reg(0x8C46,0x0C);
					ov3640_write_reg(0x8C47,0x4E);
					ov3640_write_reg(0x8C48,0x80);
					ov3640_write_reg(0x8C49,0xDC);
					ov3640_write_reg(0x8C4A,0x12);
					ov3640_write_reg(0x8C4B,0x0C);
					ov3640_write_reg(0x8C4C,0x4E);
					ov3640_write_reg(0x8C4D,0x22);
					ov3640_write_reg(0x8C4E,0xC2);
					ov3640_write_reg(0x8C4F,0x01);
					ov3640_write_reg(0x8C50,0x12);
					ov3640_write_reg(0x8C51,0x05);
					ov3640_write_reg(0x8C52,0xC8);
					ov3640_write_reg(0x8C53,0x7F);
					ov3640_write_reg(0x8C54,0x01);
					ov3640_write_reg(0x8C55,0xAE);
					ov3640_write_reg(0x8C56,0x07);
					ov3640_write_reg(0x8C57,0x1F);
					ov3640_write_reg(0x8C58,0xEE);
					ov3640_write_reg(0x8C59,0x70);
					ov3640_write_reg(0x8C5A,0xFA);
					ov3640_write_reg(0x8C5B,0xD2);
					ov3640_write_reg(0x8C5C,0x00);
					ov3640_write_reg(0x8C5D,0x12);
					ov3640_write_reg(0x8C5E,0x05);
					ov3640_write_reg(0x8C5F,0xC8);
					ov3640_write_reg(0x8C60,0x7F);
					ov3640_write_reg(0x8C61,0x01);
					ov3640_write_reg(0x8C62,0xAE);
					ov3640_write_reg(0x8C63,0x07);
					ov3640_write_reg(0x8C64,0x1F);
					ov3640_write_reg(0x8C65,0xEE);
					ov3640_write_reg(0x8C66,0x70);
					ov3640_write_reg(0x8C67,0xFA);
					ov3640_write_reg(0x8C68,0xD2);
					ov3640_write_reg(0x8C69,0x01);
					ov3640_write_reg(0x8C6A,0x12);
					ov3640_write_reg(0x8C6B,0x05);
					ov3640_write_reg(0x8C6C,0xC8);
					ov3640_write_reg(0x8C6D,0x7F);
					ov3640_write_reg(0x8C6E,0x01);
					ov3640_write_reg(0x8C6F,0xAE);
					ov3640_write_reg(0x8C70,0x07);
					ov3640_write_reg(0x8C71,0x1F);
					ov3640_write_reg(0x8C72,0xEE);
					ov3640_write_reg(0x8C73,0x70);
					ov3640_write_reg(0x8C74,0xFA);
					ov3640_write_reg(0x8C75,0x22);
					ov3640_write_reg(0x8C76,0x90);
					ov3640_write_reg(0x8C77,0x30);
					ov3640_write_reg(0x8C78,0x14);
					ov3640_write_reg(0x8C79,0xE0);
					ov3640_write_reg(0x8C7A,0x30);
					ov3640_write_reg(0x8C7B,0x0F);
					ov3640_write_reg(0x8C7C,0x10);
					ov3640_write_reg(0x8C7D,0x54);
					ov3640_write_reg(0x8C7E,0xF7);
					ov3640_write_reg(0x8C7F,0xF0);
					ov3640_write_reg(0x8C80,0xA3);
					ov3640_write_reg(0x8C81,0xE0);
					ov3640_write_reg(0x8C82,0x54);
					ov3640_write_reg(0x8C83,0xBF);
					ov3640_write_reg(0x8C84,0xF0);
					ov3640_write_reg(0x8C85,0x90);
					ov3640_write_reg(0x8C86,0x30);
					ov3640_write_reg(0x8C87,0x2D);
					ov3640_write_reg(0x8C88,0xE4);
					ov3640_write_reg(0x8C89,0xF0);
					ov3640_write_reg(0x8C8A,0xA3);
					ov3640_write_reg(0x8C8B,0xF0);
					ov3640_write_reg(0x8C8C,0x22);
					ov3640_write_reg(0x8C8D,0x44);
					ov3640_write_reg(0x8C8E,0x08);
					ov3640_write_reg(0x8C8F,0xF0);
					ov3640_write_reg(0x8C90,0xA3);
					ov3640_write_reg(0x8C91,0xE0);
					ov3640_write_reg(0x8C92,0x44);
					ov3640_write_reg(0x8C93,0x40);
					ov3640_write_reg(0x8C94,0xF0);
					ov3640_write_reg(0x8C95,0x22);
					ov3640_write_reg(0x8C96,0xD2);
					ov3640_write_reg(0x8C97,0x01);
					ov3640_write_reg(0x8C98,0xD2);
					ov3640_write_reg(0x8C99,0x00);
					ov3640_write_reg(0x8C9A,0x12);
					ov3640_write_reg(0x8C9B,0x05);
					ov3640_write_reg(0x8C9C,0xC8);
					ov3640_write_reg(0x8C9D,0x7F);
					ov3640_write_reg(0x8C9E,0x02);
					ov3640_write_reg(0x8C9F,0xAE);
					ov3640_write_reg(0x8CA0,0x07);
					ov3640_write_reg(0x8CA1,0x1F);
					ov3640_write_reg(0x8CA2,0xEE);
					ov3640_write_reg(0x8CA3,0x70);
					ov3640_write_reg(0x8CA4,0xFA);
					ov3640_write_reg(0x8CA5,0xC2);
					ov3640_write_reg(0x8CA6,0x01);
					ov3640_write_reg(0x8CA7,0x12);
					ov3640_write_reg(0x8CA8,0x05);
					ov3640_write_reg(0x8CA9,0xC8);
					ov3640_write_reg(0x8CAA,0x7F);
					ov3640_write_reg(0x8CAB,0x01);
					ov3640_write_reg(0x8CAC,0xAE);
					ov3640_write_reg(0x8CAD,0x07);
					ov3640_write_reg(0x8CAE,0x1F);
					ov3640_write_reg(0x8CAF,0xEE);
					ov3640_write_reg(0x8CB0,0x70);
					ov3640_write_reg(0x8CB1,0xFA);
					ov3640_write_reg(0x8CB2,0x12);
					ov3640_write_reg(0x8CB3,0x05);
					ov3640_write_reg(0x8CB4,0xC6);
					ov3640_write_reg(0x8CB5,0x22);
					ov3640_write_reg(0x8CB6,0x90);
					ov3640_write_reg(0x8CB7,0x30);
					ov3640_write_reg(0x8CB8,0x1B);
					ov3640_write_reg(0x8CB9,0xE0);
					ov3640_write_reg(0x8CBA,0xFF);
					ov3640_write_reg(0x8CBB,0x65);
					ov3640_write_reg(0x8CBC,0x2D);
					ov3640_write_reg(0x8CBD,0x70);
					ov3640_write_reg(0x8CBE,0x01);
					ov3640_write_reg(0x8CBF,0xE4);
					ov3640_write_reg(0x8CC0,0x60);
					ov3640_write_reg(0x8CC1,0x04);
					ov3640_write_reg(0x8CC2,0x8F);
					ov3640_write_reg(0x8CC3,0x2D);
					ov3640_write_reg(0x8CC4,0xD3);
					ov3640_write_reg(0x8CC5,0x22);
					ov3640_write_reg(0x8CC6,0xC3);
					ov3640_write_reg(0x8CC7,0x22);
					ov3640_write_reg(0x8CC8,0xEF);
					ov3640_write_reg(0x8CC9,0x8D);
					ov3640_write_reg(0x8CCA,0xF0);
					ov3640_write_reg(0x8CCB,0xA4);
					ov3640_write_reg(0x8CCC,0xA8);
					ov3640_write_reg(0x8CCD,0xF0);
					ov3640_write_reg(0x8CCE,0xCF);
					ov3640_write_reg(0x8CCF,0x8C);
					ov3640_write_reg(0x8CD0,0xF0);
					ov3640_write_reg(0x8CD1,0xA4);
					ov3640_write_reg(0x8CD2,0x28);
					ov3640_write_reg(0x8CD3,0xCE);
					ov3640_write_reg(0x8CD4,0x8D);
					ov3640_write_reg(0x8CD5,0xF0);
					ov3640_write_reg(0x8CD6,0xA4);
					ov3640_write_reg(0x8CD7,0x2E);
					ov3640_write_reg(0x8CD8,0xFE);
					ov3640_write_reg(0x8CD9,0x22);
					ov3640_write_reg(0x8CDA,0xEF);
					ov3640_write_reg(0x8CDB,0x90);
					ov3640_write_reg(0x8CDC,0x33);
					ov3640_write_reg(0x8CDD,0x00);
					ov3640_write_reg(0x8CDE,0x60);
					ov3640_write_reg(0x8CDF,0x05);
					ov3640_write_reg(0x8CE0,0xE0);
					ov3640_write_reg(0x8CE1,0x44);
					ov3640_write_reg(0x8CE2,0x40);
					ov3640_write_reg(0x8CE3,0xF0);
					ov3640_write_reg(0x8CE4,0x22);
					ov3640_write_reg(0x8CE5,0xE0);
					ov3640_write_reg(0x8CE6,0x54);
					ov3640_write_reg(0x8CE7,0xBF);
					ov3640_write_reg(0x8CE8,0xF0);
					ov3640_write_reg(0x8CE9,0x22);
					ov3640_write_reg(0x8CEA,0x85);
					ov3640_write_reg(0x8CEB,0x3D);
					ov3640_write_reg(0x8CEC,0x4B);
					ov3640_write_reg(0x8CED,0x85);
					ov3640_write_reg(0x8CEE,0x3E);
					ov3640_write_reg(0x8CEF,0x4C);
					ov3640_write_reg(0x8CF0,0xAF);
					ov3640_write_reg(0x8CF1,0x4C);
					ov3640_write_reg(0x8CF2,0xAE);
					ov3640_write_reg(0x8CF3,0x4B);
					ov3640_write_reg(0x8CF4,0x02);
					ov3640_write_reg(0x8CF5,0x0B);
					ov3640_write_reg(0x8CF6,0x7A);
					ov3640_write_reg(0x8CF7,0xEE);
					ov3640_write_reg(0x8CF8,0x30);
					ov3640_write_reg(0x8CF9,0xE7);
					ov3640_write_reg(0x8CFA,0x07);
					ov3640_write_reg(0x8CFB,0xC3);
					ov3640_write_reg(0x8CFC,0xE4);
					ov3640_write_reg(0x8CFD,0x9F);
					ov3640_write_reg(0x8CFE,0xFF);
					ov3640_write_reg(0x8CFF,0xE4);
					ov3640_write_reg(0x8D00,0x9E);
					ov3640_write_reg(0x8D01,0xFE);
					ov3640_write_reg(0x8D02,0x22);
					ov3640_write_reg(0x3104,0x00);
					mdelay(100);
/*
 * V4L2_SENS_ANTISHAKE_ENABLE
 */					ov3640_write_reg(0x3f00,0x0A);
					ov3640_write_reg(0x3f00,0x0F);
				}break;
			}
		}break;
	}
	return SUCCESS;
}

/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	: SENS_OV3640_14
 *  Name	:	ov3640_af_firmware_dump
 *  Parameter1	:	cam_data *cam	- Base address of camera structure pointer
 *  Returns	:	int		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative value be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *
 *  Description	: 	Auto focus firmware register dump
 *  Comments	:  	Before performing autofocus related operations -Auto focus firmware dump should be 
 *  			applied
 ************************************************************************************************************/

int ov3640_af_firmware_dump(cam_data *cam)
{
	ov3640_write_reg(0x308c,0x00);
	ov3640_write_reg(0x3104,0x02);
	ov3640_write_reg(0x3105,0xff);
	ov3640_write_reg(0x3106,0x00);
	ov3640_write_reg(0x3107,0xff);
	ov3640_write_reg(0x8000,0x02);
	ov3640_write_reg(0x8001,0x07);
	ov3640_write_reg(0x8002,0x74);
	ov3640_write_reg(0x8003,0x02);
	ov3640_write_reg(0x8004,0x08);
	ov3640_write_reg(0x8005,0x00);
	ov3640_write_reg(0x8006,0x85);
	ov3640_write_reg(0x8007,0x3C);
	ov3640_write_reg(0x8008,0x27);
	ov3640_write_reg(0x8009,0x85);
	ov3640_write_reg(0x800A,0x3D);
	ov3640_write_reg(0x800B,0x28);
	ov3640_write_reg(0x800C,0x85);
	ov3640_write_reg(0x800D,0x3E);
	ov3640_write_reg(0x800E,0x2B);
	ov3640_write_reg(0x800F,0x85);
	ov3640_write_reg(0x8010,0x3F);
	ov3640_write_reg(0x8011,0x2C);
	ov3640_write_reg(0x8012,0xE5);
	ov3640_write_reg(0x8013,0x24);
	ov3640_write_reg(0x8014,0x14);
	ov3640_write_reg(0x8015,0x70);
	ov3640_write_reg(0x8016,0x03);
	ov3640_write_reg(0x8017,0x02);
	ov3640_write_reg(0x8018,0x00);
	ov3640_write_reg(0x8019,0xA7);
	ov3640_write_reg(0x801A,0x14);
	ov3640_write_reg(0x801B,0x70);
	ov3640_write_reg(0x801C,0x03);
	ov3640_write_reg(0x801D,0x02);
	ov3640_write_reg(0x801E,0x01);
	ov3640_write_reg(0x801F,0x45);
	ov3640_write_reg(0x8020,0x14);
	ov3640_write_reg(0x8021,0x70);
	ov3640_write_reg(0x8022,0x03);
	ov3640_write_reg(0x8023,0x02);
	ov3640_write_reg(0x8024,0x01);
	ov3640_write_reg(0x8025,0xEC);
	ov3640_write_reg(0x8026,0x24);
	ov3640_write_reg(0x8027,0x03);
	ov3640_write_reg(0x8028,0x60);
	ov3640_write_reg(0x8029,0x03);
	ov3640_write_reg(0x802A,0x02);
	ov3640_write_reg(0x802B,0x02);
	ov3640_write_reg(0x802C,0x42);
	ov3640_write_reg(0x802D,0xE5);
	ov3640_write_reg(0x802E,0x48);
	ov3640_write_reg(0x802F,0x45);
	ov3640_write_reg(0x8030,0x47);
	ov3640_write_reg(0x8031,0x70);
	ov3640_write_reg(0x8032,0x12);
	ov3640_write_reg(0x8033,0x85);
	ov3640_write_reg(0x8034,0x27);
	ov3640_write_reg(0x8035,0x25);
	ov3640_write_reg(0x8036,0x85);
	ov3640_write_reg(0x8037,0x28);
	ov3640_write_reg(0x8038,0x26);
	ov3640_write_reg(0x8039,0x85);
	ov3640_write_reg(0x803A,0x2B);
	ov3640_write_reg(0x803B,0x29);
	ov3640_write_reg(0x803C,0x85);
	ov3640_write_reg(0x803D,0x2C);
	ov3640_write_reg(0x803E,0x2A);
	ov3640_write_reg(0x803F,0xF5);
	ov3640_write_reg(0x8040,0x22);
	ov3640_write_reg(0x8041,0xF5);
	ov3640_write_reg(0x8042,0x23);
	ov3640_write_reg(0x8043,0x80);
	ov3640_write_reg(0x8044,0x1D);
	ov3640_write_reg(0x8045,0xC3);
	ov3640_write_reg(0x8046,0xE5);
	ov3640_write_reg(0x8047,0x2C);
	ov3640_write_reg(0x8048,0x95);
	ov3640_write_reg(0x8049,0x2A);
	ov3640_write_reg(0x804A,0xE5);
	ov3640_write_reg(0x804B,0x2B);
	ov3640_write_reg(0x804C,0x95);
	ov3640_write_reg(0x804D,0x29);
	ov3640_write_reg(0x804E,0x40);
	ov3640_write_reg(0x804F,0x12);
	ov3640_write_reg(0x8050,0x85);
	ov3640_write_reg(0x8051,0x27);
	ov3640_write_reg(0x8052,0x25);
	ov3640_write_reg(0x8053,0x85);
	ov3640_write_reg(0x8054,0x28);
	ov3640_write_reg(0x8055,0x26);
	ov3640_write_reg(0x8056,0x85);
	ov3640_write_reg(0x8057,0x2B);
	ov3640_write_reg(0x8058,0x29);
	ov3640_write_reg(0x8059,0x85);
	ov3640_write_reg(0x805A,0x2C);
	ov3640_write_reg(0x805B,0x2A);
	ov3640_write_reg(0x805C,0x85);
	ov3640_write_reg(0x805D,0x47);
	ov3640_write_reg(0x805E,0x22);
	ov3640_write_reg(0x805F,0x85);
	ov3640_write_reg(0x8060,0x48);
	ov3640_write_reg(0x8061,0x23);
	ov3640_write_reg(0x8062,0xE5);
	ov3640_write_reg(0x8063,0x48);
	ov3640_write_reg(0x8064,0x45);
	ov3640_write_reg(0x8065,0x47);
	ov3640_write_reg(0x8066,0x70);
	ov3640_write_reg(0x8067,0x08);
	ov3640_write_reg(0x8068,0x85);
	ov3640_write_reg(0x8069,0x35);
	ov3640_write_reg(0x806A,0x47);
	ov3640_write_reg(0x806B,0x85);
	ov3640_write_reg(0x806C,0x36);
	ov3640_write_reg(0x806D,0x48);
	ov3640_write_reg(0x806E,0x80);
	ov3640_write_reg(0x806F,0x1A);
	ov3640_write_reg(0x8070,0xC3);
	ov3640_write_reg(0x8071,0xE5);
	ov3640_write_reg(0x8072,0x48);
	ov3640_write_reg(0x8073,0x95);
	ov3640_write_reg(0x8074,0x4A);
	ov3640_write_reg(0x8075,0xE5);
	ov3640_write_reg(0x8076,0x47);
	ov3640_write_reg(0x8077,0x95);
	ov3640_write_reg(0x8078,0x49);
	ov3640_write_reg(0x8079,0x50);
	ov3640_write_reg(0x807A,0x04);
	ov3640_write_reg(0x807B,0xE5);
	ov3640_write_reg(0x807C,0x3B);
	ov3640_write_reg(0x807D,0x80);
	ov3640_write_reg(0x807E,0x02);
	ov3640_write_reg(0x807F,0xE5);
	ov3640_write_reg(0x8080,0x4C);
	ov3640_write_reg(0x8081,0x25);
	ov3640_write_reg(0x8082,0x48);
	ov3640_write_reg(0x8083,0xF5);
	ov3640_write_reg(0x8084,0x48);
	ov3640_write_reg(0x8085,0xE4);
	ov3640_write_reg(0x8086,0x35);
	ov3640_write_reg(0x8087,0x47);
	ov3640_write_reg(0x8088,0xF5);
	ov3640_write_reg(0x8089,0x47);
	ov3640_write_reg(0x808A,0x85);
	ov3640_write_reg(0x808B,0x47);
	ov3640_write_reg(0x808C,0x13);
	ov3640_write_reg(0x808D,0x85);
	ov3640_write_reg(0x808E,0x48);
	ov3640_write_reg(0x808F,0x14);
	ov3640_write_reg(0x8090,0x12);
	ov3640_write_reg(0x8091,0x0B);
	ov3640_write_reg(0x8092,0x86);
	ov3640_write_reg(0x8093,0xD3);
	ov3640_write_reg(0x8094,0xE5);
	ov3640_write_reg(0x8095,0x48);
	ov3640_write_reg(0x8096,0x95);
	ov3640_write_reg(0x8097,0x4A);
	ov3640_write_reg(0x8098,0xE5);
	ov3640_write_reg(0x8099,0x47);
	ov3640_write_reg(0x809A,0x95);
	ov3640_write_reg(0x809B,0x49);
	ov3640_write_reg(0x809C,0x50);
	ov3640_write_reg(0x809D,0x03);
	ov3640_write_reg(0x809E,0x02);
	ov3640_write_reg(0x809F,0x02);
	ov3640_write_reg(0x80A0,0x42);
	ov3640_write_reg(0x80A1,0x75);
	ov3640_write_reg(0x80A2,0x24);
	ov3640_write_reg(0x80A3,0x01);
	ov3640_write_reg(0x80A4,0x02);
	ov3640_write_reg(0x80A5,0x02);
	ov3640_write_reg(0x80A6,0x42);
	ov3640_write_reg(0x80A7,0xC3);
	ov3640_write_reg(0x80A8,0xE5);
	ov3640_write_reg(0x80A9,0x2C);
	ov3640_write_reg(0x80AA,0x95);
	ov3640_write_reg(0x80AB,0x2A);
	ov3640_write_reg(0x80AC,0xFF);
	ov3640_write_reg(0x80AD,0xE5);
	ov3640_write_reg(0x80AE,0x2B);
	ov3640_write_reg(0x80AF,0x95);
	ov3640_write_reg(0x80B0,0x29);
	ov3640_write_reg(0x80B1,0xFE);
	ov3640_write_reg(0x80B2,0x12);
	ov3640_write_reg(0x80B3,0x0D);
	ov3640_write_reg(0x80B4,0x27);
	ov3640_write_reg(0x80B5,0xC0);
	ov3640_write_reg(0x80B6,0x06);
	ov3640_write_reg(0x80B7,0xC0);
	ov3640_write_reg(0x80B8,0x07);
	ov3640_write_reg(0x80B9,0xC3);
	ov3640_write_reg(0x80BA,0xE5);
	ov3640_write_reg(0x80BB,0x28);
	ov3640_write_reg(0x80BC,0x95);
	ov3640_write_reg(0x80BD,0x26);
	ov3640_write_reg(0x80BE,0xFF);
	ov3640_write_reg(0x80BF,0xE5);
	ov3640_write_reg(0x80C0,0x27);
	ov3640_write_reg(0x80C1,0x95);
	ov3640_write_reg(0x80C2,0x25);
	ov3640_write_reg(0x80C3,0xFE);
	ov3640_write_reg(0x80C4,0x12);
	ov3640_write_reg(0x80C5,0x0D);
	ov3640_write_reg(0x80C6,0x27);
	ov3640_write_reg(0x80C7,0xD0);
	ov3640_write_reg(0x80C8,0x05);
	ov3640_write_reg(0x80C9,0xD0);
	ov3640_write_reg(0x80CA,0x04);
	ov3640_write_reg(0x80CB,0xD3);
	ov3640_write_reg(0x80CC,0xEF);
	ov3640_write_reg(0x80CD,0x9D);
	ov3640_write_reg(0x80CE,0xEC);
	ov3640_write_reg(0x80CF,0x64);
	ov3640_write_reg(0x80D0,0x80);
	ov3640_write_reg(0x80D1,0xF8);
	ov3640_write_reg(0x80D2,0xEE);
	ov3640_write_reg(0x80D3,0x64);
	ov3640_write_reg(0x80D4,0x80);
	ov3640_write_reg(0x80D5,0x98);
	ov3640_write_reg(0x80D6,0x40);
	ov3640_write_reg(0x80D7,0x0E);
	ov3640_write_reg(0x80D8,0x85);
	ov3640_write_reg(0x80D9,0x27);
	ov3640_write_reg(0x80DA,0x2D);
	ov3640_write_reg(0x80DB,0x85);
	ov3640_write_reg(0x80DC,0x28);
	ov3640_write_reg(0x80DD,0x2E);
	ov3640_write_reg(0x80DE,0x85);
	ov3640_write_reg(0x80DF,0x25);
	ov3640_write_reg(0x80E0,0x2F);
	ov3640_write_reg(0x80E1,0x85);
	ov3640_write_reg(0x80E2,0x26);
	ov3640_write_reg(0x80E3,0x30);
	ov3640_write_reg(0x80E4,0x80);
	ov3640_write_reg(0x80E5,0x0C);
	ov3640_write_reg(0x80E6,0x85);
	ov3640_write_reg(0x80E7,0x2B);
	ov3640_write_reg(0x80E8,0x2D);
	ov3640_write_reg(0x80E9,0x85);
	ov3640_write_reg(0x80EA,0x2C);
	ov3640_write_reg(0x80EB,0x2E);
	ov3640_write_reg(0x80EC,0x85);
	ov3640_write_reg(0x80ED,0x29);
	ov3640_write_reg(0x80EE,0x2F);
	ov3640_write_reg(0x80EF,0x85);
	ov3640_write_reg(0x80F0,0x2A);
	ov3640_write_reg(0x80F1,0x30);
	ov3640_write_reg(0x80F2,0xC3);
	ov3640_write_reg(0x80F3,0xE5);
	ov3640_write_reg(0x80F4,0x2E);
	ov3640_write_reg(0x80F5,0x95);
	ov3640_write_reg(0x80F6,0x30);
	ov3640_write_reg(0x80F7,0xE5);
	ov3640_write_reg(0x80F8,0x2D);
	ov3640_write_reg(0x80F9,0x95);
	ov3640_write_reg(0x80FA,0x2F);
	ov3640_write_reg(0x80FB,0x40);
	ov3640_write_reg(0x80FC,0x30);
	ov3640_write_reg(0x80FD,0xAF);
	ov3640_write_reg(0x80FE,0x4C);
	ov3640_write_reg(0x80FF,0x7E);
	ov3640_write_reg(0x8100,0x00);
	ov3640_write_reg(0x8101,0xE5);
	ov3640_write_reg(0x8102,0x48);
	ov3640_write_reg(0x8103,0x2F);
	ov3640_write_reg(0x8104,0xFD);
	ov3640_write_reg(0x8105,0xEE);
	ov3640_write_reg(0x8106,0x35);
	ov3640_write_reg(0x8107,0x47);
	ov3640_write_reg(0x8108,0xFC);
	ov3640_write_reg(0x8109,0xC3);
	ov3640_write_reg(0x810A,0xED);
	ov3640_write_reg(0x810B,0x95);
	ov3640_write_reg(0x810C,0x4E);
	ov3640_write_reg(0x810D,0xEC);
	ov3640_write_reg(0x810E,0x95);
	ov3640_write_reg(0x810F,0x4D);
	ov3640_write_reg(0x8110,0x50);
	ov3640_write_reg(0x8111,0x18);
	ov3640_write_reg(0x8112,0xEF);
	ov3640_write_reg(0x8113,0x25);
	ov3640_write_reg(0x8114,0x48);
	ov3640_write_reg(0x8115,0xF5);
	ov3640_write_reg(0x8116,0x48);
	ov3640_write_reg(0x8117,0xEE);
	ov3640_write_reg(0x8118,0x35);
	ov3640_write_reg(0x8119,0x47);
	ov3640_write_reg(0x811A,0xF5);
	ov3640_write_reg(0x811B,0x47);
	ov3640_write_reg(0x811C,0xF5);
	ov3640_write_reg(0x811D,0x13);
	ov3640_write_reg(0x811E,0x85);
	ov3640_write_reg(0x811F,0x48);
	ov3640_write_reg(0x8120,0x14);
	ov3640_write_reg(0x8121,0x12);
	ov3640_write_reg(0x8122,0x0B);
	ov3640_write_reg(0x8123,0x86);
	ov3640_write_reg(0x8124,0x75);
	ov3640_write_reg(0x8125,0x24);
	ov3640_write_reg(0x8126,0x02);
	ov3640_write_reg(0x8127,0x02);
	ov3640_write_reg(0x8128,0x01);
	ov3640_write_reg(0x8129,0xC2);
	ov3640_write_reg(0x812A,0x02);
	ov3640_write_reg(0x812B,0x01);
	ov3640_write_reg(0x812C,0xD0);
	ov3640_write_reg(0x812D,0x85);
	ov3640_write_reg(0x812E,0x47);
	ov3640_write_reg(0x812F,0x0D);
	ov3640_write_reg(0x8130,0x85);
	ov3640_write_reg(0x8131,0x48);
	ov3640_write_reg(0x8132,0x0E);
	ov3640_write_reg(0x8133,0x85);
	ov3640_write_reg(0x8134,0x22);
	ov3640_write_reg(0x8135,0x0F);
	ov3640_write_reg(0x8136,0x85);
	ov3640_write_reg(0x8137,0x23);
	ov3640_write_reg(0x8138,0x10);
	ov3640_write_reg(0x8139,0x12);
	ov3640_write_reg(0x813A,0x0B);
	ov3640_write_reg(0x813B,0x41);
	ov3640_write_reg(0x813C,0x85);
	ov3640_write_reg(0x813D,0x22);
	ov3640_write_reg(0x813E,0x47);
	ov3640_write_reg(0x813F,0x85);
	ov3640_write_reg(0x8140,0x23);
	ov3640_write_reg(0x8141,0x48);
	ov3640_write_reg(0x8142,0x02);
	ov3640_write_reg(0x8143,0x01);
	ov3640_write_reg(0x8144,0xE7);
	ov3640_write_reg(0x8145,0xC3);
	ov3640_write_reg(0x8146,0xE5);
	ov3640_write_reg(0x8147,0x2C);
	ov3640_write_reg(0x8148,0x95);
	ov3640_write_reg(0x8149,0x2A);
	ov3640_write_reg(0x814A,0xFF);
	ov3640_write_reg(0x814B,0xE5);
	ov3640_write_reg(0x814C,0x2B);
	ov3640_write_reg(0x814D,0x95);
	ov3640_write_reg(0x814E,0x29);
	ov3640_write_reg(0x814F,0xFE);
	ov3640_write_reg(0x8150,0x12);
	ov3640_write_reg(0x8151,0x0D);
	ov3640_write_reg(0x8152,0x27);
	ov3640_write_reg(0x8153,0xC0);
	ov3640_write_reg(0x8154,0x06);
	ov3640_write_reg(0x8155,0xC0);
	ov3640_write_reg(0x8156,0x07);
	ov3640_write_reg(0x8157,0xC3);
	ov3640_write_reg(0x8158,0xE5);
	ov3640_write_reg(0x8159,0x28);
	ov3640_write_reg(0x815A,0x95);
	ov3640_write_reg(0x815B,0x26);
	ov3640_write_reg(0x815C,0xFF);
	ov3640_write_reg(0x815D,0xE5);
	ov3640_write_reg(0x815E,0x27);
	ov3640_write_reg(0x815F,0x95);
	ov3640_write_reg(0x8160,0x25);
	ov3640_write_reg(0x8161,0xFE);
	ov3640_write_reg(0x8162,0x12);
	ov3640_write_reg(0x8163,0x0D);
	ov3640_write_reg(0x8164,0x27);
	ov3640_write_reg(0x8165,0xD0);
	ov3640_write_reg(0x8166,0x05);
	ov3640_write_reg(0x8167,0xD0);
	ov3640_write_reg(0x8168,0x04);
	ov3640_write_reg(0x8169,0xD3);
	ov3640_write_reg(0x816A,0xEF);
	ov3640_write_reg(0x816B,0x9D);
	ov3640_write_reg(0x816C,0xEC);
	ov3640_write_reg(0x816D,0x64);
	ov3640_write_reg(0x816E,0x80);
	ov3640_write_reg(0x816F,0xF8);
	ov3640_write_reg(0x8170,0xEE);
	ov3640_write_reg(0x8171,0x64);
	ov3640_write_reg(0x8172,0x80);
	ov3640_write_reg(0x8173,0x98);
	ov3640_write_reg(0x8174,0x40);
	ov3640_write_reg(0x8175,0x0E);
	ov3640_write_reg(0x8176,0x85);
	ov3640_write_reg(0x8177,0x27);
	ov3640_write_reg(0x8178,0x2D);
	ov3640_write_reg(0x8179,0x85);
	ov3640_write_reg(0x817A,0x28);
	ov3640_write_reg(0x817B,0x2E);
	ov3640_write_reg(0x817C,0x85);
	ov3640_write_reg(0x817D,0x25);
	ov3640_write_reg(0x817E,0x2F);
	ov3640_write_reg(0x817F,0x85);
	ov3640_write_reg(0x8180,0x26);
	ov3640_write_reg(0x8181,0x30);
	ov3640_write_reg(0x8182,0x80);
	ov3640_write_reg(0x8183,0x0C);
	ov3640_write_reg(0x8184,0x85);
	ov3640_write_reg(0x8185,0x2B);
	ov3640_write_reg(0x8186,0x2D);
	ov3640_write_reg(0x8187,0x85);
	ov3640_write_reg(0x8188,0x2C);
	ov3640_write_reg(0x8189,0x2E);
	ov3640_write_reg(0x818A,0x85);
	ov3640_write_reg(0x818B,0x29);
	ov3640_write_reg(0x818C,0x2F);
	ov3640_write_reg(0x818D,0x85);
	ov3640_write_reg(0x818E,0x2A);
	ov3640_write_reg(0x818F,0x30);
	ov3640_write_reg(0x8190,0xC3);
	ov3640_write_reg(0x8191,0xE5);
	ov3640_write_reg(0x8192,0x2E);
	ov3640_write_reg(0x8193,0x95);
	ov3640_write_reg(0x8194,0x30);
	ov3640_write_reg(0x8195,0xE5);
	ov3640_write_reg(0x8196,0x2D);
	ov3640_write_reg(0x8197,0x95);
	ov3640_write_reg(0x8198,0x2F);
	ov3640_write_reg(0x8199,0x40);
	ov3640_write_reg(0x819A,0x37);
	ov3640_write_reg(0x819B,0xAF);
	ov3640_write_reg(0x819C,0x4C);
	ov3640_write_reg(0x819D,0x7E);
	ov3640_write_reg(0x819E,0x00);
	ov3640_write_reg(0x819F,0xE5);
	ov3640_write_reg(0x81A0,0x48);
	ov3640_write_reg(0x81A1,0x2F);
	ov3640_write_reg(0x81A2,0xFD);
	ov3640_write_reg(0x81A3,0xEE);
	ov3640_write_reg(0x81A4,0x35);
	ov3640_write_reg(0x81A5,0x47);
	ov3640_write_reg(0x81A6,0xFC);
	ov3640_write_reg(0x81A7,0xC3);
	ov3640_write_reg(0x81A8,0xED);
	ov3640_write_reg(0x81A9,0x95);
	ov3640_write_reg(0x81AA,0x4E);
	ov3640_write_reg(0x81AB,0xEC);
	ov3640_write_reg(0x81AC,0x95);
	ov3640_write_reg(0x81AD,0x4D);
	ov3640_write_reg(0x81AE,0x50);
	ov3640_write_reg(0x81AF,0x20);
	ov3640_write_reg(0x81B0,0xEF);
	ov3640_write_reg(0x81B1,0x25);
	ov3640_write_reg(0x81B2,0x48);
	ov3640_write_reg(0x81B3,0xF5);
	ov3640_write_reg(0x81B4,0x48);
	ov3640_write_reg(0x81B5,0xEE);
	ov3640_write_reg(0x81B6,0x35);
	ov3640_write_reg(0x81B7,0x47);
	ov3640_write_reg(0x81B8,0xF5);
	ov3640_write_reg(0x81B9,0x47);
	ov3640_write_reg(0x81BA,0xF5);
	ov3640_write_reg(0x81BB,0x13);
	ov3640_write_reg(0x81BC,0x85);
	ov3640_write_reg(0x81BD,0x48);
	ov3640_write_reg(0x81BE,0x14);
	ov3640_write_reg(0x81BF,0x12);
	ov3640_write_reg(0x81C0,0x0B);
	ov3640_write_reg(0x81C1,0x86);
	ov3640_write_reg(0x81C2,0x85);
	ov3640_write_reg(0x81C3,0x27);
	ov3640_write_reg(0x81C4,0x25);
	ov3640_write_reg(0x81C5,0x85);
	ov3640_write_reg(0x81C6,0x28);
	ov3640_write_reg(0x81C7,0x26);
	ov3640_write_reg(0x81C8,0x85);
	ov3640_write_reg(0x81C9,0x2B);
	ov3640_write_reg(0x81CA,0x29);
	ov3640_write_reg(0x81CB,0x85);
	ov3640_write_reg(0x81CC,0x2C);
	ov3640_write_reg(0x81CD,0x2A);
	ov3640_write_reg(0x81CE,0x80);
	ov3640_write_reg(0x81CF,0x72);
	ov3640_write_reg(0x81D0,0x80);
	ov3640_write_reg(0x81D1,0x15);
	ov3640_write_reg(0x81D2,0xC3);
	ov3640_write_reg(0x81D3,0xE5);
	ov3640_write_reg(0x81D4,0x48);
	ov3640_write_reg(0x81D5,0x95);
	ov3640_write_reg(0x81D6,0x4C);
	ov3640_write_reg(0x81D7,0xF5);
	ov3640_write_reg(0x81D8,0x48);
	ov3640_write_reg(0x81D9,0xE5);
	ov3640_write_reg(0x81DA,0x47);
	ov3640_write_reg(0x81DB,0x94);
	ov3640_write_reg(0x81DC,0x00);
	ov3640_write_reg(0x81DD,0xF5);
	ov3640_write_reg(0x81DE,0x47);
	ov3640_write_reg(0x81DF,0xF5);
	ov3640_write_reg(0x81E0,0x13);
	ov3640_write_reg(0x81E1,0x85);
	ov3640_write_reg(0x81E2,0x48);
	ov3640_write_reg(0x81E3,0x14);
	ov3640_write_reg(0x81E4,0x12);
	ov3640_write_reg(0x81E5,0x0B);
	ov3640_write_reg(0x81E6,0x86);
	ov3640_write_reg(0x81E7,0x75);
	ov3640_write_reg(0x81E8,0x24);
	ov3640_write_reg(0x81E9,0x03);
	ov3640_write_reg(0x81EA,0x80);
	ov3640_write_reg(0x81EB,0x56);
	ov3640_write_reg(0x81EC,0xE4);
	ov3640_write_reg(0x81ED,0xF5);
	ov3640_write_reg(0x81EE,0x24);
	ov3640_write_reg(0x81EF,0xC3);
	ov3640_write_reg(0x81F0,0xE5);
	ov3640_write_reg(0x81F1,0x42);
	ov3640_write_reg(0x81F2,0x95);
	ov3640_write_reg(0x81F3,0x30);
	ov3640_write_reg(0x81F4,0xE5);
	ov3640_write_reg(0x81F5,0x41);
	ov3640_write_reg(0x81F6,0x95);
	ov3640_write_reg(0x81F7,0x2F);
	ov3640_write_reg(0x81F8,0x50);
	ov3640_write_reg(0x81F9,0x23);
	ov3640_write_reg(0x81FA,0xE5);
	ov3640_write_reg(0x81FB,0x40);
	ov3640_write_reg(0x81FC,0x54);
	ov3640_write_reg(0x81FD,0x0C);
	ov3640_write_reg(0x81FE,0xFF);
	ov3640_write_reg(0x81FF,0xBF);
	ov3640_write_reg(0x8200,0x04);
	ov3640_write_reg(0x8201,0x05);
	ov3640_write_reg(0x8202,0x75);
	ov3640_write_reg(0x8203,0x40);
	ov3640_write_reg(0x8204,0x46);
	ov3640_write_reg(0x8205,0x80);
	ov3640_write_reg(0x8206,0x32);
	ov3640_write_reg(0x8207,0xEF);
	ov3640_write_reg(0x8208,0x64);
	ov3640_write_reg(0x8209,0x08);
	ov3640_write_reg(0x820A,0x70);
	ov3640_write_reg(0x820B,0x2D);
	ov3640_write_reg(0x820C,0x75);
	ov3640_write_reg(0x820D,0x40);
	ov3640_write_reg(0x820E,0x4A);
	ov3640_write_reg(0x820F,0x85);
	ov3640_write_reg(0x8210,0x3C);
	ov3640_write_reg(0x8211,0x43);
	ov3640_write_reg(0x8212,0x85);
	ov3640_write_reg(0x8213,0x3D);
	ov3640_write_reg(0x8214,0x44);
	ov3640_write_reg(0x8215,0x85);
	ov3640_write_reg(0x8216,0x3E);
	ov3640_write_reg(0x8217,0x45);
	ov3640_write_reg(0x8218,0x85);
	ov3640_write_reg(0x8219,0x3F);
	ov3640_write_reg(0x821A,0x46);
	ov3640_write_reg(0x821B,0x80);
	ov3640_write_reg(0x821C,0x1C);
	ov3640_write_reg(0x821D,0xE5);
	ov3640_write_reg(0x821E,0x40);
	ov3640_write_reg(0x821F,0x54);
	ov3640_write_reg(0x8220,0x0C);
	ov3640_write_reg(0x8221,0xFF);
	ov3640_write_reg(0x8222,0xBF);
	ov3640_write_reg(0x8223,0x04);
	ov3640_write_reg(0x8224,0x05);
	ov3640_write_reg(0x8225,0x75);
	ov3640_write_reg(0x8226,0x40);
	ov3640_write_reg(0x8227,0xC6);
	ov3640_write_reg(0x8228,0x80);
	ov3640_write_reg(0x8229,0x0F);
	ov3640_write_reg(0x822A,0xBF);
	ov3640_write_reg(0x822B,0x08);
	ov3640_write_reg(0x822C,0x0C);
	ov3640_write_reg(0x822D,0x75);
	ov3640_write_reg(0x822E,0x40);
	ov3640_write_reg(0x822F,0xCA);
	ov3640_write_reg(0x8230,0xE4);
	ov3640_write_reg(0x8231,0xF5);
	ov3640_write_reg(0x8232,0x43);
	ov3640_write_reg(0x8233,0xF5);
	ov3640_write_reg(0x8234,0x44);
	ov3640_write_reg(0x8235,0xF5);
	ov3640_write_reg(0x8236,0x45);
	ov3640_write_reg(0x8237,0xF5);
	ov3640_write_reg(0x8238,0x46);
	ov3640_write_reg(0x8239,0x12);
	ov3640_write_reg(0x823A,0x0A);
	ov3640_write_reg(0x823B,0x7D);
	ov3640_write_reg(0x823C,0x90);
	ov3640_write_reg(0x823D,0x3F);
	ov3640_write_reg(0x823E,0x01);
	ov3640_write_reg(0x823F,0xE5);
	ov3640_write_reg(0x8240,0x40);
	ov3640_write_reg(0x8241,0xF0);
	ov3640_write_reg(0x8242,0xC2);
	ov3640_write_reg(0x8243,0x09);
	ov3640_write_reg(0x8244,0x22);
	ov3640_write_reg(0x8245,0xE5);
	ov3640_write_reg(0x8246,0x4B);
	ov3640_write_reg(0x8247,0x70);
	ov3640_write_reg(0x8248,0x03);
	ov3640_write_reg(0x8249,0x02);
	ov3640_write_reg(0x824A,0x03);
	ov3640_write_reg(0x824B,0x7A);
	ov3640_write_reg(0x824C,0xC2);
	ov3640_write_reg(0x824D,0xAF);
	ov3640_write_reg(0x824E,0x85);
	ov3640_write_reg(0x824F,0x4B);
	ov3640_write_reg(0x8250,0x0C);
	ov3640_write_reg(0x8251,0xE4);
	ov3640_write_reg(0x8252,0xF5);
	ov3640_write_reg(0x8253,0x4B);
	ov3640_write_reg(0x8254,0xD2);
	ov3640_write_reg(0x8255,0xAF);
	ov3640_write_reg(0x8256,0xE5);
	ov3640_write_reg(0x8257,0x0C);
	ov3640_write_reg(0x8258,0x12);
	ov3640_write_reg(0x8259,0x0C);
	ov3640_write_reg(0x825A,0x48);
	ov3640_write_reg(0x825B,0x02);
	ov3640_write_reg(0x825C,0x92);
	ov3640_write_reg(0x825D,0x00);
	ov3640_write_reg(0x825E,0x02);
	ov3640_write_reg(0x825F,0xA3);
	ov3640_write_reg(0x8260,0x01);
	ov3640_write_reg(0x8261,0x02);
	ov3640_write_reg(0x8262,0xAE);
	ov3640_write_reg(0x8263,0x02);
	ov3640_write_reg(0x8264,0x02);
	ov3640_write_reg(0x8265,0xB9);
	ov3640_write_reg(0x8266,0x03);
	ov3640_write_reg(0x8267,0x02);
	ov3640_write_reg(0x8268,0xCC);
	ov3640_write_reg(0x8269,0x04);
	ov3640_write_reg(0x826A,0x02);
	ov3640_write_reg(0x826B,0xE3);
	ov3640_write_reg(0x826C,0x05);
	ov3640_write_reg(0x826D,0x02);
	ov3640_write_reg(0x826E,0xF6);
	ov3640_write_reg(0x826F,0x06);
	ov3640_write_reg(0x8270,0x03);
	ov3640_write_reg(0x8271,0x0F);
	ov3640_write_reg(0x8272,0x07);
	ov3640_write_reg(0x8273,0x03);
	ov3640_write_reg(0x8274,0x2C);
	ov3640_write_reg(0x8275,0x08);
	ov3640_write_reg(0x8276,0x03);
	ov3640_write_reg(0x8277,0x4B);
	ov3640_write_reg(0x8278,0x09);
	ov3640_write_reg(0x8279,0x03);
	ov3640_write_reg(0x827A,0x50);
	ov3640_write_reg(0x827B,0x10);
	ov3640_write_reg(0x827C,0x03);
	ov3640_write_reg(0x827D,0x50);
	ov3640_write_reg(0x827E,0x11);
	ov3640_write_reg(0x827F,0x03);
	ov3640_write_reg(0x8280,0x50);
	ov3640_write_reg(0x8281,0x12);
	ov3640_write_reg(0x8282,0x03);
	ov3640_write_reg(0x8283,0x50);
	ov3640_write_reg(0x8284,0x13);
	ov3640_write_reg(0x8285,0x03);
	ov3640_write_reg(0x8286,0x50);
	ov3640_write_reg(0x8287,0x14);
	ov3640_write_reg(0x8288,0x03);
	ov3640_write_reg(0x8289,0x50);
	ov3640_write_reg(0x828A,0x15);
	ov3640_write_reg(0x828B,0x03);
	ov3640_write_reg(0x828C,0x60);
	ov3640_write_reg(0x828D,0x20);
	ov3640_write_reg(0x828E,0x00);
	ov3640_write_reg(0x828F,0x00);
	ov3640_write_reg(0x8290,0x03);
	ov3640_write_reg(0x8291,0x74);
	ov3640_write_reg(0x8292,0xE5);
	ov3640_write_reg(0x8293,0x4F);
	ov3640_write_reg(0x8294,0x70);
	ov3640_write_reg(0x8295,0x03);
	ov3640_write_reg(0x8296,0x02);
	ov3640_write_reg(0x8297,0x03);
	ov3640_write_reg(0x8298,0x74);
	ov3640_write_reg(0x8299,0xE5);
	ov3640_write_reg(0x829A,0x40);
	ov3640_write_reg(0x829B,0x60);
	ov3640_write_reg(0x829C,0x03);
	ov3640_write_reg(0x829D,0x02);
	ov3640_write_reg(0x829E,0x03);
	ov3640_write_reg(0x829F,0x74);
	ov3640_write_reg(0x82A0,0x02);
	ov3640_write_reg(0x82A1,0x03);
	ov3640_write_reg(0x82A2,0x27);
	ov3640_write_reg(0x82A3,0xD2);
	ov3640_write_reg(0x82A4,0x08);
	ov3640_write_reg(0x82A5,0x75);
	ov3640_write_reg(0x82A6,0x0E);
	ov3640_write_reg(0x82A7,0x01);
	ov3640_write_reg(0x82A8,0x12);
	ov3640_write_reg(0x82A9,0x0D);
	ov3640_write_reg(0x82AA,0x13);
	ov3640_write_reg(0x82AB,0x02);
	ov3640_write_reg(0x82AC,0x03);
	ov3640_write_reg(0x82AD,0x74);
	ov3640_write_reg(0x82AE,0xE4);
	ov3640_write_reg(0x82AF,0xF5);
	ov3640_write_reg(0x82B0,0x0E);
	ov3640_write_reg(0x82B1,0x12);
	ov3640_write_reg(0x82B2,0x0D);
	ov3640_write_reg(0x82B3,0x13);
	ov3640_write_reg(0x82B4,0xC2);
	ov3640_write_reg(0x82B5,0x08);
	ov3640_write_reg(0x82B6,0x02);
	ov3640_write_reg(0x82B7,0x03);
	ov3640_write_reg(0x82B8,0x74);
	ov3640_write_reg(0x82B9,0xE5);
	ov3640_write_reg(0x82BA,0x40);
	ov3640_write_reg(0x82BB,0x60);
	ov3640_write_reg(0x82BC,0x03);
	ov3640_write_reg(0x82BD,0x02);
	ov3640_write_reg(0x82BE,0x03);
	ov3640_write_reg(0x82BF,0x74);
	ov3640_write_reg(0x82C0,0xE5);
	ov3640_write_reg(0x82C1,0x4F);
	ov3640_write_reg(0x82C2,0x60);
	ov3640_write_reg(0x82C3,0x03);
	ov3640_write_reg(0x82C4,0x02);
	ov3640_write_reg(0x82C5,0x03);
	ov3640_write_reg(0x82C6,0x74);
	ov3640_write_reg(0x82C7,0x75);
	ov3640_write_reg(0x82C8,0x40);
	ov3640_write_reg(0x82C9,0x65);
	ov3640_write_reg(0x82CA,0x80);
	ov3640_write_reg(0x82CB,0x77);
	ov3640_write_reg(0x82CC,0xE5);
	ov3640_write_reg(0x82CD,0x40);
	ov3640_write_reg(0x82CE,0x60);
	ov3640_write_reg(0x82CF,0x03);
	ov3640_write_reg(0x82D0,0x02);
	ov3640_write_reg(0x82D1,0x03);
	ov3640_write_reg(0x82D2,0x74);
	ov3640_write_reg(0x82D3,0xE5);
	ov3640_write_reg(0x82D4,0x4F);
	ov3640_write_reg(0x82D5,0x60);
	ov3640_write_reg(0x82D6,0x03);
	ov3640_write_reg(0x82D7,0x02);
	ov3640_write_reg(0x82D8,0x03);
	ov3640_write_reg(0x82D9,0x74);
	ov3640_write_reg(0x82DA,0x75);
	ov3640_write_reg(0x82DB,0x40);
	ov3640_write_reg(0x82DC,0x4A);
	ov3640_write_reg(0x82DD,0x75);
	ov3640_write_reg(0x82DE,0x4F);
	ov3640_write_reg(0x82DF,0x01);
	ov3640_write_reg(0x82E0,0x02);
	ov3640_write_reg(0x82E1,0x03);
	ov3640_write_reg(0x82E2,0x74);
	ov3640_write_reg(0x82E3,0xE5);
	ov3640_write_reg(0x82E4,0x40);
	ov3640_write_reg(0x82E5,0x60);
	ov3640_write_reg(0x82E6,0x03);
	ov3640_write_reg(0x82E7,0x02);
	ov3640_write_reg(0x82E8,0x03);
	ov3640_write_reg(0x82E9,0x74);
	ov3640_write_reg(0x82EA,0xE5);
	ov3640_write_reg(0x82EB,0x4F);
	ov3640_write_reg(0x82EC,0x60);
	ov3640_write_reg(0x82ED,0x03);
	ov3640_write_reg(0x82EE,0x02);
	ov3640_write_reg(0x82EF,0x03);
	ov3640_write_reg(0x82F0,0x74);
	ov3640_write_reg(0x82F1,0x75);
	ov3640_write_reg(0x82F2,0x40);
	ov3640_write_reg(0x82F3,0x4E);
	ov3640_write_reg(0x82F4,0x80);
	ov3640_write_reg(0x82F5,0x4D);
	ov3640_write_reg(0x82F6,0xE5);
	ov3640_write_reg(0x82F7,0x40);
	ov3640_write_reg(0x82F8,0xB4);
	ov3640_write_reg(0x82F9,0x46);
	ov3640_write_reg(0x82FA,0x09);
	ov3640_write_reg(0x82FB,0x75);
	ov3640_write_reg(0x82FC,0x40);
	ov3640_write_reg(0x82FD,0x47);
	ov3640_write_reg(0x82FE,0x85);
	ov3640_write_reg(0x82FF,0x40);
	ov3640_write_reg(0x8300,0x0D);
	ov3640_write_reg(0x8301,0x12);
	ov3640_write_reg(0x8302,0x0A);
	ov3640_write_reg(0x8303,0x80);
	ov3640_write_reg(0x8304,0xE5);
	ov3640_write_reg(0x8305,0x40);
	ov3640_write_reg(0x8306,0x64);
	ov3640_write_reg(0x8307,0x4A);
	ov3640_write_reg(0x8308,0x70);
	ov3640_write_reg(0x8309,0x6A);
	ov3640_write_reg(0x830A,0x75);
	ov3640_write_reg(0x830B,0x40);
	ov3640_write_reg(0x830C,0x4B);
	ov3640_write_reg(0x830D,0x80);
	ov3640_write_reg(0x830E,0x34);
	ov3640_write_reg(0x830F,0xE5);
	ov3640_write_reg(0x8310,0x40);
	ov3640_write_reg(0x8311,0x64);
	ov3640_write_reg(0x8312,0x4B);
	ov3640_write_reg(0x8313,0x70);
	ov3640_write_reg(0x8314,0x5F);
	ov3640_write_reg(0x8315,0x85);
	ov3640_write_reg(0x8316,0x47);
	ov3640_write_reg(0x8317,0x0D);
	ov3640_write_reg(0x8318,0x85);
	ov3640_write_reg(0x8319,0x48);
	ov3640_write_reg(0x831A,0x0E);
	ov3640_write_reg(0x831B,0xF5);
	ov3640_write_reg(0x831C,0x0F);
	ov3640_write_reg(0x831D,0xF5);
	ov3640_write_reg(0x831E,0x10);
	ov3640_write_reg(0x831F,0x12);
	ov3640_write_reg(0x8320,0x0B);
	ov3640_write_reg(0x8321,0x41);
	ov3640_write_reg(0x8322,0xE4);
	ov3640_write_reg(0x8323,0xF5);
	ov3640_write_reg(0x8324,0x47);
	ov3640_write_reg(0x8325,0xF5);
	ov3640_write_reg(0x8326,0x48);
	ov3640_write_reg(0x8327,0x75);
	ov3640_write_reg(0x8328,0x40);
	ov3640_write_reg(0x8329,0x69);
	ov3640_write_reg(0x832A,0x80);
	ov3640_write_reg(0x832B,0x17);
	ov3640_write_reg(0x832C,0xE4);
	ov3640_write_reg(0x832D,0xF5);
	ov3640_write_reg(0x832E,0x40);
	ov3640_write_reg(0x832F,0xF5);
	ov3640_write_reg(0x8330,0x4F);
	ov3640_write_reg(0x8331,0x85);
	ov3640_write_reg(0x8332,0x47);
	ov3640_write_reg(0x8333,0x0D);
	ov3640_write_reg(0x8334,0x85);
	ov3640_write_reg(0x8335,0x48);
	ov3640_write_reg(0x8336,0x0E);
	ov3640_write_reg(0x8337,0xF5);
	ov3640_write_reg(0x8338,0x0F);
	ov3640_write_reg(0x8339,0xF5);
	ov3640_write_reg(0x833A,0x10);
	ov3640_write_reg(0x833B,0x12);
	ov3640_write_reg(0x833C,0x0B);
	ov3640_write_reg(0x833D,0x41);
	ov3640_write_reg(0x833E,0xE4);
	ov3640_write_reg(0x833F,0xF5);
	ov3640_write_reg(0x8340,0x47);
	ov3640_write_reg(0x8341,0xF5);
	ov3640_write_reg(0x8342,0x48);
	ov3640_write_reg(0x8343,0x85);
	ov3640_write_reg(0x8344,0x40);
	ov3640_write_reg(0x8345,0x0D);
	ov3640_write_reg(0x8346,0x12);
	ov3640_write_reg(0x8347,0x0A);
	ov3640_write_reg(0x8348,0x80);
	ov3640_write_reg(0x8349,0x80);
	ov3640_write_reg(0x834A,0x29);
	ov3640_write_reg(0x834B,0x12);
	ov3640_write_reg(0x834C,0x06);
	ov3640_write_reg(0x834D,0xD6);
	ov3640_write_reg(0x834E,0x80);
	ov3640_write_reg(0x834F,0x24);
	ov3640_write_reg(0x8350,0xE5);
	ov3640_write_reg(0x8351,0x4F);
	ov3640_write_reg(0x8352,0x70);
	ov3640_write_reg(0x8353,0x20);
	ov3640_write_reg(0x8354,0xE5);
	ov3640_write_reg(0x8355,0x40);
	ov3640_write_reg(0x8356,0x70);
	ov3640_write_reg(0x8357,0x1C);
	ov3640_write_reg(0x8358,0x85);
	ov3640_write_reg(0x8359,0x0C);
	ov3640_write_reg(0x835A,0x0D);
	ov3640_write_reg(0x835B,0x12);
	ov3640_write_reg(0x835C,0x05);
	ov3640_write_reg(0x835D,0x7E);
	ov3640_write_reg(0x835E,0x80);
	ov3640_write_reg(0x835F,0x14);
	ov3640_write_reg(0x8360,0xE5);
	ov3640_write_reg(0x8361,0x3C);
	ov3640_write_reg(0x8362,0x90);
	ov3640_write_reg(0x8363,0x3F);
	ov3640_write_reg(0x8364,0x02);
	ov3640_write_reg(0x8365,0xF0);
	ov3640_write_reg(0x8366,0xA3);
	ov3640_write_reg(0x8367,0xE5);
	ov3640_write_reg(0x8368,0x3D);
	ov3640_write_reg(0x8369,0xF0);
	ov3640_write_reg(0x836A,0xE5);
	ov3640_write_reg(0x836B,0x3E);
	ov3640_write_reg(0x836C,0xA3);
	ov3640_write_reg(0x836D,0xF0);
	ov3640_write_reg(0x836E,0x90);
	ov3640_write_reg(0x836F,0x3F);
	ov3640_write_reg(0x8370,0x07);
	ov3640_write_reg(0x8371,0xE5);
	ov3640_write_reg(0x8372,0x3F);
	ov3640_write_reg(0x8373,0xF0);
	ov3640_write_reg(0x8374,0x90);
	ov3640_write_reg(0x8375,0x3F);
	ov3640_write_reg(0x8376,0x01);
	ov3640_write_reg(0x8377,0xE5);
	ov3640_write_reg(0x8378,0x40);
	ov3640_write_reg(0x8379,0xF0);
	ov3640_write_reg(0x837A,0x22);
	ov3640_write_reg(0x837B,0xE5);
	ov3640_write_reg(0x837C,0x15);
	ov3640_write_reg(0x837D,0xD3);
	ov3640_write_reg(0x837E,0x94);
	ov3640_write_reg(0x837F,0x04);
	ov3640_write_reg(0x8380,0x40);
	ov3640_write_reg(0x8381,0x03);
	ov3640_write_reg(0x8382,0xE4);
	ov3640_write_reg(0x8383,0xF5);
	ov3640_write_reg(0x8384,0x15);
	ov3640_write_reg(0x8385,0xE5);
	ov3640_write_reg(0x8386,0x15);
	ov3640_write_reg(0x8387,0x25);
	ov3640_write_reg(0x8388,0xE0);
	ov3640_write_reg(0x8389,0x25);
	ov3640_write_reg(0x838A,0xE0);
	ov3640_write_reg(0x838B,0xF5);
	ov3640_write_reg(0x838C,0x15);
	ov3640_write_reg(0x838D,0xE5);
	ov3640_write_reg(0x838E,0x12);
	ov3640_write_reg(0x838F,0xAE);
	ov3640_write_reg(0x8390,0x11);
	ov3640_write_reg(0x8391,0x78);
	ov3640_write_reg(0x8392,0x05);
	ov3640_write_reg(0x8393,0xCE);
	ov3640_write_reg(0x8394,0xC3);
	ov3640_write_reg(0x8395,0x13);
	ov3640_write_reg(0x8396,0xCE);
	ov3640_write_reg(0x8397,0x13);
	ov3640_write_reg(0x8398,0xD8);
	ov3640_write_reg(0x8399,0xF9);
	ov3640_write_reg(0x839A,0xFB);
	ov3640_write_reg(0x839B,0xAA);
	ov3640_write_reg(0x839C,0x06);
	ov3640_write_reg(0x839D,0x25);
	ov3640_write_reg(0x839E,0xE0);
	ov3640_write_reg(0x839F,0xFF);
	ov3640_write_reg(0x83A0,0xEA);
	ov3640_write_reg(0x83A1,0x33);
	ov3640_write_reg(0x83A2,0xFE);
	ov3640_write_reg(0x83A3,0xEF);
	ov3640_write_reg(0x83A4,0x78);
	ov3640_write_reg(0x83A5,0x03);
	ov3640_write_reg(0x83A6,0xCE);
	ov3640_write_reg(0x83A7,0xC3);
	ov3640_write_reg(0x83A8,0x13);
	ov3640_write_reg(0x83A9,0xCE);
	ov3640_write_reg(0x83AA,0x13);
	ov3640_write_reg(0x83AB,0xD8);
	ov3640_write_reg(0x83AC,0xF9);
	ov3640_write_reg(0x83AD,0xF5);
	ov3640_write_reg(0x83AE,0x1C);
	ov3640_write_reg(0x83AF,0xE5);
	ov3640_write_reg(0x83B0,0x14);
	ov3640_write_reg(0x83B1,0xAE);
	ov3640_write_reg(0x83B2,0x13);
	ov3640_write_reg(0x83B3,0x78);
	ov3640_write_reg(0x83B4,0x03);
	ov3640_write_reg(0x83B5,0xCE);
	ov3640_write_reg(0x83B6,0xC3);
	ov3640_write_reg(0x83B7,0x13);
	ov3640_write_reg(0x83B8,0xCE);
	ov3640_write_reg(0x83B9,0x13);
	ov3640_write_reg(0x83BA,0xD8);
	ov3640_write_reg(0x83BB,0xF9);
	ov3640_write_reg(0x83BC,0x25);
	ov3640_write_reg(0x83BD,0xE0);
	ov3640_write_reg(0x83BE,0xFF);
	ov3640_write_reg(0x83BF,0xEE);
	ov3640_write_reg(0x83C0,0x33);
	ov3640_write_reg(0x83C1,0xFE);
	ov3640_write_reg(0x83C2,0xEF);
	ov3640_write_reg(0x83C3,0x78);
	ov3640_write_reg(0x83C4,0x03);
	ov3640_write_reg(0x83C5,0xCE);
	ov3640_write_reg(0x83C6,0xC3);
	ov3640_write_reg(0x83C7,0x13);
	ov3640_write_reg(0x83C8,0xCE);
	ov3640_write_reg(0x83C9,0x13);
	ov3640_write_reg(0x83CA,0xD8);
	ov3640_write_reg(0x83CB,0xF9);
	ov3640_write_reg(0x83CC,0xF9);
	ov3640_write_reg(0x83CD,0x7C);
	ov3640_write_reg(0x83CE,0x00);
	ov3640_write_reg(0x83CF,0x7D);
	ov3640_write_reg(0x83D0,0x06);
	ov3640_write_reg(0x83D1,0xAF);
	ov3640_write_reg(0x83D2,0x03);
	ov3640_write_reg(0x83D3,0xAE);
	ov3640_write_reg(0x83D4,0x02);
	ov3640_write_reg(0x83D5,0x12);
	ov3640_write_reg(0x83D6,0x0C);
	ov3640_write_reg(0x83D7,0x36);
	ov3640_write_reg(0x83D8,0xEF);
	ov3640_write_reg(0x83D9,0x78);
	ov3640_write_reg(0x83DA,0x03);
	ov3640_write_reg(0x83DB,0xCE);
	ov3640_write_reg(0x83DC,0xC3);
	ov3640_write_reg(0x83DD,0x13);
	ov3640_write_reg(0x83DE,0xCE);
	ov3640_write_reg(0x83DF,0x13);
	ov3640_write_reg(0x83E0,0xD8);
	ov3640_write_reg(0x83E1,0xF9);
	ov3640_write_reg(0x83E2,0xFB);
	ov3640_write_reg(0x83E3,0xE5);
	ov3640_write_reg(0x83E4,0x14);
	ov3640_write_reg(0x83E5,0xAE);
	ov3640_write_reg(0x83E6,0x13);
	ov3640_write_reg(0x83E7,0x78);
	ov3640_write_reg(0x83E8,0x03);
	ov3640_write_reg(0x83E9,0xCE);
	ov3640_write_reg(0x83EA,0xC3);
	ov3640_write_reg(0x83EB,0x13);
	ov3640_write_reg(0x83EC,0xCE);
	ov3640_write_reg(0x83ED,0x13);
	ov3640_write_reg(0x83EE,0xD8);
	ov3640_write_reg(0x83EF,0xF9);
	ov3640_write_reg(0x83F0,0xFF);
	ov3640_write_reg(0x83F1,0x7C);
	ov3640_write_reg(0x83F2,0x00);
	ov3640_write_reg(0x83F3,0x7D);
	ov3640_write_reg(0x83F4,0x06);
	ov3640_write_reg(0x83F5,0x12);
	ov3640_write_reg(0x83F6,0x0C);
	ov3640_write_reg(0x83F7,0x36);
	ov3640_write_reg(0x83F8,0xEF);
	ov3640_write_reg(0x83F9,0x78);
	ov3640_write_reg(0x83FA,0x03);
	ov3640_write_reg(0x83FB,0xCE);
	ov3640_write_reg(0x83FC,0xC3);
	ov3640_write_reg(0x83FD,0x13);
	ov3640_write_reg(0x83FE,0xCE);
	ov3640_write_reg(0x83FF,0x13);
	ov3640_write_reg(0x8400,0xD8);
	ov3640_write_reg(0x8401,0xF9);
	ov3640_write_reg(0x8402,0xFD);
	ov3640_write_reg(0x8403,0xE5);
	ov3640_write_reg(0x8404,0x1C);
	ov3640_write_reg(0x8405,0x75);
	ov3640_write_reg(0x8406,0xF0);
	ov3640_write_reg(0x8407,0x20);
	ov3640_write_reg(0x8408,0xA4);
	ov3640_write_reg(0x8409,0x85);
	ov3640_write_reg(0x840A,0xF0);
	ov3640_write_reg(0x840B,0x16);
	ov3640_write_reg(0x840C,0xF5);
	ov3640_write_reg(0x840D,0x17);
	ov3640_write_reg(0x840E,0xE9);
	ov3640_write_reg(0x840F,0x75);
	ov3640_write_reg(0x8410,0xF0);
	ov3640_write_reg(0x8411,0x08);
	ov3640_write_reg(0x8412,0xA4);
	ov3640_write_reg(0x8413,0x85);
	ov3640_write_reg(0x8414,0xF0);
	ov3640_write_reg(0x8415,0x18);
	ov3640_write_reg(0x8416,0xF5);
	ov3640_write_reg(0x8417,0x19);
	ov3640_write_reg(0x8418,0xEB);
	ov3640_write_reg(0x8419,0x75);
	ov3640_write_reg(0x841A,0xF0);
	ov3640_write_reg(0x841B,0x20);
	ov3640_write_reg(0x841C,0xA4);
	ov3640_write_reg(0x841D,0x85);
	ov3640_write_reg(0x841E,0xF0);
	ov3640_write_reg(0x841F,0x1A);
	ov3640_write_reg(0x8420,0xF5);
	ov3640_write_reg(0x8421,0x1B);
	ov3640_write_reg(0x8422,0xAF);
	ov3640_write_reg(0x8423,0x05);
	ov3640_write_reg(0x8424,0xEF);
	ov3640_write_reg(0x8425,0x75);
	ov3640_write_reg(0x8426,0xF0);
	ov3640_write_reg(0x8427,0x08);
	ov3640_write_reg(0x8428,0xA4);
	ov3640_write_reg(0x8429,0xFD);
	ov3640_write_reg(0x842A,0xAC);
	ov3640_write_reg(0x842B,0xF0);
	ov3640_write_reg(0x842C,0xE5);
	ov3640_write_reg(0x842D,0x16);
	ov3640_write_reg(0x842E,0x54);
	ov3640_write_reg(0x842F,0x0F);
	ov3640_write_reg(0x8430,0xFB);
	ov3640_write_reg(0x8431,0xE5);
	ov3640_write_reg(0x8432,0x18);
	ov3640_write_reg(0x8433,0x54);
	ov3640_write_reg(0x8434,0x07);
	ov3640_write_reg(0x8435,0xC4);
	ov3640_write_reg(0x8436,0xF8);
	ov3640_write_reg(0x8437,0x54);
	ov3640_write_reg(0x8438,0xF0);
	ov3640_write_reg(0x8439,0xC8);
	ov3640_write_reg(0x843A,0xE4);
	ov3640_write_reg(0x843B,0xC4);
	ov3640_write_reg(0x843C,0x54);
	ov3640_write_reg(0x843D,0x0F);
	ov3640_write_reg(0x843E,0x48);
	ov3640_write_reg(0x843F,0x2B);
	ov3640_write_reg(0x8440,0xFB);
	ov3640_write_reg(0x8441,0xE5);
	ov3640_write_reg(0x8442,0x1A);
	ov3640_write_reg(0x8443,0x54);
	ov3640_write_reg(0x8444,0x0F);
	ov3640_write_reg(0x8445,0xFA);
	ov3640_write_reg(0x8446,0xEC);
	ov3640_write_reg(0x8447,0x54);
	ov3640_write_reg(0x8448,0x07);
	ov3640_write_reg(0x8449,0xC4);
	ov3640_write_reg(0x844A,0xF8);
	ov3640_write_reg(0x844B,0x54);
	ov3640_write_reg(0x844C,0xF0);
	ov3640_write_reg(0x844D,0xC8);
	ov3640_write_reg(0x844E,0xE4);
	ov3640_write_reg(0x844F,0xC4);
	ov3640_write_reg(0x8450,0x54);
	ov3640_write_reg(0x8451,0x0F);
	ov3640_write_reg(0x8452,0x48);
	ov3640_write_reg(0x8453,0x2A);
	ov3640_write_reg(0x8454,0xFF);
	ov3640_write_reg(0x8455,0x90);
	ov3640_write_reg(0x8456,0x33);
	ov3640_write_reg(0x8457,0x5F);
	ov3640_write_reg(0x8458,0xE0);
	ov3640_write_reg(0x8459,0x90);
	ov3640_write_reg(0x845A,0x39);
	ov3640_write_reg(0x845B,0x0A);
	ov3640_write_reg(0x845C,0xB4);
	ov3640_write_reg(0x845D,0x68);
	ov3640_write_reg(0x845E,0x11);
	ov3640_write_reg(0x845F,0x74);
	ov3640_write_reg(0x8460,0x18);
	ov3640_write_reg(0x8461,0xF0);
	ov3640_write_reg(0x8462,0xA3);
	ov3640_write_reg(0x8463,0x74);
	ov3640_write_reg(0x8464,0x48);
	ov3640_write_reg(0x8465,0xF0);
	ov3640_write_reg(0x8466,0xA3);
	ov3640_write_reg(0x8467,0x74);
	ov3640_write_reg(0x8468,0x28);
	ov3640_write_reg(0x8469,0xF0);
	ov3640_write_reg(0x846A,0xA3);
	ov3640_write_reg(0x846B,0x74);
	ov3640_write_reg(0x846C,0x78);
	ov3640_write_reg(0x846D,0xF0);
	ov3640_write_reg(0x846E,0x80);
	ov3640_write_reg(0x846F,0x0F);
	ov3640_write_reg(0x8470,0x74);
	ov3640_write_reg(0x8471,0x0C);
	ov3640_write_reg(0x8472,0xF0);
	ov3640_write_reg(0x8473,0xA3);
	ov3640_write_reg(0x8474,0x74);
	ov3640_write_reg(0x8475,0x24);
	ov3640_write_reg(0x8476,0xF0);
	ov3640_write_reg(0x8477,0xA3);
	ov3640_write_reg(0x8478,0x74);
	ov3640_write_reg(0x8479,0x14);
	ov3640_write_reg(0x847A,0xF0);
	ov3640_write_reg(0x847B,0xA3);
	ov3640_write_reg(0x847C,0x74);
	ov3640_write_reg(0x847D,0x3C);
	ov3640_write_reg(0x847E,0xF0);
	ov3640_write_reg(0x847F,0x90);
	ov3640_write_reg(0x8480,0x33);
	ov3640_write_reg(0x8481,0xAA);
	ov3640_write_reg(0x8482,0xEB);
	ov3640_write_reg(0x8483,0xF0);
	ov3640_write_reg(0x8484,0xE5);
	ov3640_write_reg(0x8485,0x17);
	ov3640_write_reg(0x8486,0xA3);
	ov3640_write_reg(0x8487,0xF0);
	ov3640_write_reg(0x8488,0xE5);
	ov3640_write_reg(0x8489,0x19);
	ov3640_write_reg(0x848A,0xA3);
	ov3640_write_reg(0x848B,0xF0);
	ov3640_write_reg(0x848C,0xA3);
	ov3640_write_reg(0x848D,0xEF);
	ov3640_write_reg(0x848E,0xF0);
	ov3640_write_reg(0x848F,0xE5);
	ov3640_write_reg(0x8490,0x1B);
	ov3640_write_reg(0x8491,0xA3);
	ov3640_write_reg(0x8492,0xF0);
	ov3640_write_reg(0x8493,0xED);
	ov3640_write_reg(0x8494,0xA3);
	ov3640_write_reg(0x8495,0xF0);
	ov3640_write_reg(0x8496,0x22);
	ov3640_write_reg(0x8497,0x90);
	ov3640_write_reg(0x8498,0x3F);
	ov3640_write_reg(0x8499,0x05);
	ov3640_write_reg(0x849A,0xE0);
	ov3640_write_reg(0x849B,0xF5);
	ov3640_write_reg(0x849C,0x0C);
	ov3640_write_reg(0x849D,0x54);
	ov3640_write_reg(0x849E,0x03);
	ov3640_write_reg(0x849F,0x75);
	ov3640_write_reg(0x84A0,0x0D);
	ov3640_write_reg(0x84A1,0x00);
	ov3640_write_reg(0x84A2,0xF5);
	ov3640_write_reg(0x84A3,0x0E);
	ov3640_write_reg(0x84A4,0x75);
	ov3640_write_reg(0x84A5,0x0E);
	ov3640_write_reg(0x84A6,0x00);
	ov3640_write_reg(0x84A7,0xF5);
	ov3640_write_reg(0x84A8,0x0D);
	ov3640_write_reg(0x84A9,0xA3);
	ov3640_write_reg(0x84AA,0xE0);
	ov3640_write_reg(0x84AB,0x25);
	ov3640_write_reg(0x84AC,0x0E);
	ov3640_write_reg(0x84AD,0xF5);
	ov3640_write_reg(0x84AE,0x0E);
	ov3640_write_reg(0x84AF,0xE4);
	ov3640_write_reg(0x84B0,0x35);
	ov3640_write_reg(0x84B1,0x0D);
	ov3640_write_reg(0x84B2,0xF5);
	ov3640_write_reg(0x84B3,0x0D);
	ov3640_write_reg(0x84B4,0x53);
	ov3640_write_reg(0x84B5,0x0C);
	ov3640_write_reg(0x84B6,0xE0);
	ov3640_write_reg(0x84B7,0xE5);
	ov3640_write_reg(0x84B8,0x0C);
	ov3640_write_reg(0x84B9,0x64);
	ov3640_write_reg(0x84BA,0x20);
	ov3640_write_reg(0x84BB,0x70);
	ov3640_write_reg(0x84BC,0x03);
	ov3640_write_reg(0x84BD,0x02);
	ov3640_write_reg(0x84BE,0x05);
	ov3640_write_reg(0x84BF,0x51);
	ov3640_write_reg(0x84C0,0xE5);
	ov3640_write_reg(0x84C1,0x0C);
	ov3640_write_reg(0x84C2,0xB4);
	ov3640_write_reg(0x84C3,0x80);
	ov3640_write_reg(0x84C4,0x49);
	ov3640_write_reg(0x84C5,0xE5);
	ov3640_write_reg(0x84C6,0x48);
	ov3640_write_reg(0x84C7,0x25);
	ov3640_write_reg(0x84C8,0x0E);
	ov3640_write_reg(0x84C9,0xF5);
	ov3640_write_reg(0x84CA,0x0E);
	ov3640_write_reg(0x84CB,0xE5);
	ov3640_write_reg(0x84CC,0x47);
	ov3640_write_reg(0x84CD,0x35);
	ov3640_write_reg(0x84CE,0x0D);
	ov3640_write_reg(0x84CF,0xF5);
	ov3640_write_reg(0x84D0,0x0D);
	ov3640_write_reg(0x84D1,0xD3);
	ov3640_write_reg(0x84D2,0xE5);
	ov3640_write_reg(0x84D3,0x0E);
	ov3640_write_reg(0x84D4,0x95);
	ov3640_write_reg(0x84D5,0x4E);
	ov3640_write_reg(0x84D6,0xE5);
	ov3640_write_reg(0x84D7,0x0D);
	ov3640_write_reg(0x84D8,0x95);
	ov3640_write_reg(0x84D9,0x4D);
	ov3640_write_reg(0x84DA,0x40);
	ov3640_write_reg(0x84DB,0x06);
	ov3640_write_reg(0x84DC,0x85);
	ov3640_write_reg(0x84DD,0x4D);
	ov3640_write_reg(0x84DE,0x0D);
	ov3640_write_reg(0x84DF,0x85);
	ov3640_write_reg(0x84E0,0x4E);
	ov3640_write_reg(0x84E1,0x0E);
	ov3640_write_reg(0x84E2,0xE5);
	ov3640_write_reg(0x84E3,0x48);
	ov3640_write_reg(0x84E4,0x65);
	ov3640_write_reg(0x84E5,0x0E);
	ov3640_write_reg(0x84E6,0x70);
	ov3640_write_reg(0x84E7,0x04);
	ov3640_write_reg(0x84E8,0xE5);
	ov3640_write_reg(0x84E9,0x47);
	ov3640_write_reg(0x84EA,0x65);
	ov3640_write_reg(0x84EB,0x0D);
	ov3640_write_reg(0x84EC,0x60);
	ov3640_write_reg(0x84ED,0x20);
	ov3640_write_reg(0x84EE,0xD3);
	ov3640_write_reg(0x84EF,0xE5);
	ov3640_write_reg(0x84F0,0x0E);
	ov3640_write_reg(0x84F1,0x95);
	ov3640_write_reg(0x84F2,0x4E);
	ov3640_write_reg(0x84F3,0xE5);
	ov3640_write_reg(0x84F4,0x0D);
	ov3640_write_reg(0x84F5,0x95);
	ov3640_write_reg(0x84F6,0x4D);
	ov3640_write_reg(0x84F7,0x40);
	ov3640_write_reg(0x84F8,0x06);
	ov3640_write_reg(0x84F9,0x85);
	ov3640_write_reg(0x84FA,0x4D);
	ov3640_write_reg(0x84FB,0x0D);
	ov3640_write_reg(0x84FC,0x85);
	ov3640_write_reg(0x84FD,0x4E);
	ov3640_write_reg(0x84FE,0x0E);
	ov3640_write_reg(0x84FF,0x85);
	ov3640_write_reg(0x8500,0x0D);
	ov3640_write_reg(0x8501,0x13);
	ov3640_write_reg(0x8502,0x85);
	ov3640_write_reg(0x8503,0x0E);
	ov3640_write_reg(0x8504,0x14);
	ov3640_write_reg(0x8505,0x12);
	ov3640_write_reg(0x8506,0x0B);
	ov3640_write_reg(0x8507,0x86);
	ov3640_write_reg(0x8508,0x85);
	ov3640_write_reg(0x8509,0x0D);
	ov3640_write_reg(0x850A,0x47);
	ov3640_write_reg(0x850B,0x85);
	ov3640_write_reg(0x850C,0x0E);
	ov3640_write_reg(0x850D,0x48);
	ov3640_write_reg(0x850E,0xE5);
	ov3640_write_reg(0x850F,0x0C);
	ov3640_write_reg(0x8510,0x64);
	ov3640_write_reg(0x8511,0x40);
	ov3640_write_reg(0x8512,0x70);
	ov3640_write_reg(0x8513,0x69);
	ov3640_write_reg(0x8514,0xD3);
	ov3640_write_reg(0x8515,0xE5);
	ov3640_write_reg(0x8516,0x48);
	ov3640_write_reg(0x8517,0x95);
	ov3640_write_reg(0x8518,0x4A);
	ov3640_write_reg(0x8519,0xE5);
	ov3640_write_reg(0x851A,0x47);
	ov3640_write_reg(0x851B,0x95);
	ov3640_write_reg(0x851C,0x49);
	ov3640_write_reg(0x851D,0x40);
	ov3640_write_reg(0x851E,0x0E);
	ov3640_write_reg(0x851F,0xE5);
	ov3640_write_reg(0x8520,0x48);
	ov3640_write_reg(0x8521,0x95);
	ov3640_write_reg(0x8522,0x0E);
	ov3640_write_reg(0x8523,0xF5);
	ov3640_write_reg(0x8524,0x0E);
	ov3640_write_reg(0x8525,0xE5);
	ov3640_write_reg(0x8526,0x47);
	ov3640_write_reg(0x8527,0x95);
	ov3640_write_reg(0x8528,0x0D);
	ov3640_write_reg(0x8529,0xF5);
	ov3640_write_reg(0x852A,0x0D);
	ov3640_write_reg(0x852B,0x80);
	ov3640_write_reg(0x852C,0x05);
	ov3640_write_reg(0x852D,0xE4);
	ov3640_write_reg(0x852E,0xF5);
	ov3640_write_reg(0x852F,0x0D);
	ov3640_write_reg(0x8530,0xF5);
	ov3640_write_reg(0x8531,0x0E);
	ov3640_write_reg(0x8532,0xE5);
	ov3640_write_reg(0x8533,0x48);
	ov3640_write_reg(0x8534,0x65);
	ov3640_write_reg(0x8535,0x0E);
	ov3640_write_reg(0x8536,0x70);
	ov3640_write_reg(0x8537,0x04);
	ov3640_write_reg(0x8538,0xE5);
	ov3640_write_reg(0x8539,0x47);
	ov3640_write_reg(0x853A,0x65);
	ov3640_write_reg(0x853B,0x0D);
	ov3640_write_reg(0x853C,0x60);
	ov3640_write_reg(0x853D,0x3F);
	ov3640_write_reg(0x853E,0xD3);
	ov3640_write_reg(0x853F,0xE5);
	ov3640_write_reg(0x8540,0x0E);
	ov3640_write_reg(0x8541,0x95);
	ov3640_write_reg(0x8542,0x4E);
	ov3640_write_reg(0x8543,0xE5);
	ov3640_write_reg(0x8544,0x0D);
	ov3640_write_reg(0x8545,0x95);
	ov3640_write_reg(0x8546,0x4D);
	ov3640_write_reg(0x8547,0x40);
	ov3640_write_reg(0x8548,0x25);
	ov3640_write_reg(0x8549,0x85);
	ov3640_write_reg(0x854A,0x4D);
	ov3640_write_reg(0x854B,0x0D);
	ov3640_write_reg(0x854C,0x85);
	ov3640_write_reg(0x854D,0x4E);
	ov3640_write_reg(0x854E,0x0E);
	ov3640_write_reg(0x854F,0x80);
	ov3640_write_reg(0x8550,0x1D);
	ov3640_write_reg(0x8551,0xE5);
	ov3640_write_reg(0x8552,0x48);
	ov3640_write_reg(0x8553,0x65);
	ov3640_write_reg(0x8554,0x0E);
	ov3640_write_reg(0x8555,0x70);
	ov3640_write_reg(0x8556,0x04);
	ov3640_write_reg(0x8557,0xE5);
	ov3640_write_reg(0x8558,0x47);
	ov3640_write_reg(0x8559,0x65);
	ov3640_write_reg(0x855A,0x0D);
	ov3640_write_reg(0x855B,0x60);
	ov3640_write_reg(0x855C,0x20);
	ov3640_write_reg(0x855D,0xD3);
	ov3640_write_reg(0x855E,0xE5);
	ov3640_write_reg(0x855F,0x0E);
	ov3640_write_reg(0x8560,0x95);
	ov3640_write_reg(0x8561,0x4E);
	ov3640_write_reg(0x8562,0xE5);
	ov3640_write_reg(0x8563,0x0D);
	ov3640_write_reg(0x8564,0x95);
	ov3640_write_reg(0x8565,0x4D);
	ov3640_write_reg(0x8566,0x40);
	ov3640_write_reg(0x8567,0x06);
	ov3640_write_reg(0x8568,0x85);
	ov3640_write_reg(0x8569,0x4D);
	ov3640_write_reg(0x856A,0x0D);
	ov3640_write_reg(0x856B,0x85);
	ov3640_write_reg(0x856C,0x4E);
	ov3640_write_reg(0x856D,0x0E);
	ov3640_write_reg(0x856E,0x85);
	ov3640_write_reg(0x856F,0x0D);
	ov3640_write_reg(0x8570,0x13);
	ov3640_write_reg(0x8571,0x85);
	ov3640_write_reg(0x8572,0x0E);
	ov3640_write_reg(0x8573,0x14);
	ov3640_write_reg(0x8574,0x12);
	ov3640_write_reg(0x8575,0x0B);
	ov3640_write_reg(0x8576,0x86);
	ov3640_write_reg(0x8577,0x85);
	ov3640_write_reg(0x8578,0x0D);
	ov3640_write_reg(0x8579,0x47);
	ov3640_write_reg(0x857A,0x85);
	ov3640_write_reg(0x857B,0x0E);
	ov3640_write_reg(0x857C,0x48);
	ov3640_write_reg(0x857D,0x22);
	ov3640_write_reg(0x857E,0xE5);
	ov3640_write_reg(0x857F,0x0D);
	ov3640_write_reg(0x8580,0x30);
	ov3640_write_reg(0x8581,0xE7);
	ov3640_write_reg(0x8582,0x70);
	ov3640_write_reg(0x8583,0x54);
	ov3640_write_reg(0x8584,0x7F);
	ov3640_write_reg(0x8585,0xF5);
	ov3640_write_reg(0x8586,0x3B);
	ov3640_write_reg(0x8587,0x90);
	ov3640_write_reg(0x8588,0x3F);
	ov3640_write_reg(0x8589,0x01);
	ov3640_write_reg(0x858A,0xE0);
	ov3640_write_reg(0x858B,0xF5);
	ov3640_write_reg(0x858C,0x4C);
	ov3640_write_reg(0x858D,0xA3);
	ov3640_write_reg(0x858E,0xE0);
	ov3640_write_reg(0x858F,0x75);
	ov3640_write_reg(0x8590,0x35);
	ov3640_write_reg(0x8591,0x00);
	ov3640_write_reg(0x8592,0xF5);
	ov3640_write_reg(0x8593,0x36);
	ov3640_write_reg(0x8594,0xA3);
	ov3640_write_reg(0x8595,0xE0);
	ov3640_write_reg(0x8596,0x75);
	ov3640_write_reg(0x8597,0x49);
	ov3640_write_reg(0x8598,0x00);
	ov3640_write_reg(0x8599,0xF5);
	ov3640_write_reg(0x859A,0x4A);
	ov3640_write_reg(0x859B,0xA3);
	ov3640_write_reg(0x859C,0xE0);
	ov3640_write_reg(0x859D,0x75);
	ov3640_write_reg(0x859E,0x4D);
	ov3640_write_reg(0x859F,0x00);
	ov3640_write_reg(0x85A0,0xF5);
	ov3640_write_reg(0x85A1,0x4E);
	ov3640_write_reg(0x85A2,0x75);
	ov3640_write_reg(0x85A3,0x4E);
	ov3640_write_reg(0x85A4,0x00);
	ov3640_write_reg(0x85A5,0xF5);
	ov3640_write_reg(0x85A6,0x4D);
	ov3640_write_reg(0x85A7,0xA3);
	ov3640_write_reg(0x85A8,0xE0);
	ov3640_write_reg(0x85A9,0x25);
	ov3640_write_reg(0x85AA,0x4E);
	ov3640_write_reg(0x85AB,0xF5);
	ov3640_write_reg(0x85AC,0x4E);
	ov3640_write_reg(0x85AD,0xE4);
	ov3640_write_reg(0x85AE,0x35);
	ov3640_write_reg(0x85AF,0x4D);
	ov3640_write_reg(0x85B0,0xF5);
	ov3640_write_reg(0x85B1,0x4D);
	ov3640_write_reg(0x85B2,0xA3);
	ov3640_write_reg(0x85B3,0xE0);
	ov3640_write_reg(0x85B4,0x75);
	ov3640_write_reg(0x85B5,0x41);
	ov3640_write_reg(0x85B6,0x00);
	ov3640_write_reg(0x85B7,0xF5);
	ov3640_write_reg(0x85B8,0x42);
	ov3640_write_reg(0x85B9,0x75);
	ov3640_write_reg(0x85BA,0x42);
	ov3640_write_reg(0x85BB,0x00);
	ov3640_write_reg(0x85BC,0xF5);
	ov3640_write_reg(0x85BD,0x41);
	ov3640_write_reg(0x85BE,0xA3);
	ov3640_write_reg(0x85BF,0xE0);
	ov3640_write_reg(0x85C0,0x25);
	ov3640_write_reg(0x85C1,0x42);
	ov3640_write_reg(0x85C2,0xF5);
	ov3640_write_reg(0x85C3,0x42);
	ov3640_write_reg(0x85C4,0xE4);
	ov3640_write_reg(0x85C5,0x35);
	ov3640_write_reg(0x85C6,0x41);
	ov3640_write_reg(0x85C7,0xF5);
	ov3640_write_reg(0x85C8,0x41);
	ov3640_write_reg(0x85C9,0xE5);
	ov3640_write_reg(0x85CA,0x36);
	ov3640_write_reg(0x85CB,0x25);
	ov3640_write_reg(0x85CC,0xE0);
	ov3640_write_reg(0x85CD,0xF5);
	ov3640_write_reg(0x85CE,0x36);
	ov3640_write_reg(0x85CF,0xE5);
	ov3640_write_reg(0x85D0,0x35);
	ov3640_write_reg(0x85D1,0x33);
	ov3640_write_reg(0x85D2,0xF5);
	ov3640_write_reg(0x85D3,0x35);
	ov3640_write_reg(0x85D4,0xE5);
	ov3640_write_reg(0x85D5,0x4A);
	ov3640_write_reg(0x85D6,0x25);
	ov3640_write_reg(0x85D7,0xE0);
	ov3640_write_reg(0x85D8,0xF5);
	ov3640_write_reg(0x85D9,0x4A);
	ov3640_write_reg(0x85DA,0xE5);
	ov3640_write_reg(0x85DB,0x49);
	ov3640_write_reg(0x85DC,0x33);
	ov3640_write_reg(0x85DD,0xF5);
	ov3640_write_reg(0x85DE,0x49);
	ov3640_write_reg(0x85DF,0x90);
	ov3640_write_reg(0x85E0,0x3F);
	ov3640_write_reg(0x85E1,0x00);
	ov3640_write_reg(0x85E2,0xE4);
	ov3640_write_reg(0x85E3,0xF0);
	ov3640_write_reg(0x85E4,0xA3);
	ov3640_write_reg(0x85E5,0xF0);
	ov3640_write_reg(0x85E6,0xA3);
	ov3640_write_reg(0x85E7,0xF0);
	ov3640_write_reg(0x85E8,0xA3);
	ov3640_write_reg(0x85E9,0xF0);
	ov3640_write_reg(0x85EA,0xA3);
	ov3640_write_reg(0x85EB,0xF0);
	ov3640_write_reg(0x85EC,0xA3);
	ov3640_write_reg(0x85ED,0xF0);
	ov3640_write_reg(0x85EE,0xA3);
	ov3640_write_reg(0x85EF,0xF0);
	ov3640_write_reg(0x85F0,0xA3);
	ov3640_write_reg(0x85F1,0xF0);
	ov3640_write_reg(0x85F2,0x22);
	ov3640_write_reg(0x85F3,0x90);
	ov3640_write_reg(0x85F4,0x3F);
	ov3640_write_reg(0x85F5,0x02);
	ov3640_write_reg(0x85F6,0xE0);
	ov3640_write_reg(0x85F7,0xFF);
	ov3640_write_reg(0x85F8,0x7E);
	ov3640_write_reg(0x85F9,0x00);
	ov3640_write_reg(0x85FA,0x7F);
	ov3640_write_reg(0x85FB,0x00);
	ov3640_write_reg(0x85FC,0xFE);
	ov3640_write_reg(0x85FD,0xA3);
	ov3640_write_reg(0x85FE,0xE0);
	ov3640_write_reg(0x85FF,0x2F);
	ov3640_write_reg(0x8600,0xFF);
	ov3640_write_reg(0x8601,0xE4);
	ov3640_write_reg(0x8602,0x3E);
	ov3640_write_reg(0x8603,0xFE);
	ov3640_write_reg(0x8604,0xE5);
	ov3640_write_reg(0x8605,0x0D);
	ov3640_write_reg(0x8606,0x24);
	ov3640_write_reg(0x8607,0xEF);
	ov3640_write_reg(0x8608,0x60);
	ov3640_write_reg(0x8609,0x13);
	ov3640_write_reg(0x860A,0x14);
	ov3640_write_reg(0x860B,0x60);
	ov3640_write_reg(0x860C,0x13);
	ov3640_write_reg(0x860D,0x14);
	ov3640_write_reg(0x860E,0x60);
	ov3640_write_reg(0x860F,0x15);
	ov3640_write_reg(0x8610,0x14);
	ov3640_write_reg(0x8611,0x60);
	ov3640_write_reg(0x8612,0x17);
	ov3640_write_reg(0x8613,0x14);
	ov3640_write_reg(0x8614,0x60);
	ov3640_write_reg(0x8615,0x19);
	ov3640_write_reg(0x8616,0x24);
	ov3640_write_reg(0x8617,0x05);
	ov3640_write_reg(0x8618,0x70);
	ov3640_write_reg(0x8619,0x19);
	ov3640_write_reg(0x861A,0x8F);
	ov3640_write_reg(0x861B,0x3B);
	ov3640_write_reg(0x861C,0x22);
	ov3640_write_reg(0x861D,0x8F);
	ov3640_write_reg(0x861E,0x4C);
	ov3640_write_reg(0x861F,0x22);
	ov3640_write_reg(0x8620,0x8E);
	ov3640_write_reg(0x8621,0x35);
	ov3640_write_reg(0x8622,0x8F);
	ov3640_write_reg(0x8623,0x36);
	ov3640_write_reg(0x8624,0x22);
	ov3640_write_reg(0x8625,0x8E);
	ov3640_write_reg(0x8626,0x49);
	ov3640_write_reg(0x8627,0x8F);
	ov3640_write_reg(0x8628,0x4A);
	ov3640_write_reg(0x8629,0x22);
	ov3640_write_reg(0x862A,0x8E);
	ov3640_write_reg(0x862B,0x4D);
	ov3640_write_reg(0x862C,0x8F);
	ov3640_write_reg(0x862D,0x4E);
	ov3640_write_reg(0x862E,0x22);
	ov3640_write_reg(0x862F,0x8E);
	ov3640_write_reg(0x8630,0x41);
	ov3640_write_reg(0x8631,0x8F);
	ov3640_write_reg(0x8632,0x42);
	ov3640_write_reg(0x8633,0x22);
	ov3640_write_reg(0x8634,0xE5);
	ov3640_write_reg(0x8635,0x12);
	ov3640_write_reg(0x8636,0x25);
	ov3640_write_reg(0x8637,0xE0);
	ov3640_write_reg(0x8638,0xFF);
	ov3640_write_reg(0x8639,0xE5);
	ov3640_write_reg(0x863A,0x11);
	ov3640_write_reg(0x863B,0x33);
	ov3640_write_reg(0x863C,0xFE);
	ov3640_write_reg(0x863D,0xEF);
	ov3640_write_reg(0x863E,0x78);
	ov3640_write_reg(0x863F,0x03);
	ov3640_write_reg(0x8640,0xCE);
	ov3640_write_reg(0x8641,0xC3);
	ov3640_write_reg(0x8642,0x13);
	ov3640_write_reg(0x8643,0xCE);
	ov3640_write_reg(0x8644,0x13);
	ov3640_write_reg(0x8645,0xD8);
	ov3640_write_reg(0x8646,0xF9);
	ov3640_write_reg(0x8647,0xF5);
	ov3640_write_reg(0x8648,0x16);
	ov3640_write_reg(0x8649,0x8E);
	ov3640_write_reg(0x864A,0x15);
	ov3640_write_reg(0x864B,0xE5);
	ov3640_write_reg(0x864C,0x14);
	ov3640_write_reg(0x864D,0x25);
	ov3640_write_reg(0x864E,0xE0);
	ov3640_write_reg(0x864F,0xFF);
	ov3640_write_reg(0x8650,0xE5);
	ov3640_write_reg(0x8651,0x13);
	ov3640_write_reg(0x8652,0x33);
	ov3640_write_reg(0x8653,0xFE);
	ov3640_write_reg(0x8654,0xEF);
	ov3640_write_reg(0x8655,0x78);
	ov3640_write_reg(0x8656,0x03);
	ov3640_write_reg(0x8657,0xCE);
	ov3640_write_reg(0x8658,0xC3);
	ov3640_write_reg(0x8659,0x13);
	ov3640_write_reg(0x865A,0xCE);
	ov3640_write_reg(0x865B,0x13);
	ov3640_write_reg(0x865C,0xD8);
	ov3640_write_reg(0x865D,0xF9);
	ov3640_write_reg(0x865E,0xF5);
	ov3640_write_reg(0x865F,0x18);
	ov3640_write_reg(0x8660,0x8E);
	ov3640_write_reg(0x8661,0x17);
	ov3640_write_reg(0x8662,0xAE);
	ov3640_write_reg(0x8663,0x11);
	ov3640_write_reg(0x8664,0xAF);
	ov3640_write_reg(0x8665,0x12);
	ov3640_write_reg(0x8666,0x7C);
	ov3640_write_reg(0x8667,0x00);
	ov3640_write_reg(0x8668,0x7D);
	ov3640_write_reg(0x8669,0x06);
	ov3640_write_reg(0x866A,0x12);
	ov3640_write_reg(0x866B,0x0C);
	ov3640_write_reg(0x866C,0x36);
	ov3640_write_reg(0x866D,0xEF);
	ov3640_write_reg(0x866E,0x78);
	ov3640_write_reg(0x866F,0x03);
	ov3640_write_reg(0x8670,0xCE);
	ov3640_write_reg(0x8671,0xC3);
	ov3640_write_reg(0x8672,0x13);
	ov3640_write_reg(0x8673,0xCE);
	ov3640_write_reg(0x8674,0x13);
	ov3640_write_reg(0x8675,0xD8);
	ov3640_write_reg(0x8676,0xF9);
	ov3640_write_reg(0x8677,0xF5);
	ov3640_write_reg(0x8678,0x1A);
	ov3640_write_reg(0x8679,0x8E);
	ov3640_write_reg(0x867A,0x19);
	ov3640_write_reg(0x867B,0xAE);
	ov3640_write_reg(0x867C,0x13);
	ov3640_write_reg(0x867D,0xAF);
	ov3640_write_reg(0x867E,0x14);
	ov3640_write_reg(0x867F,0x7C);
	ov3640_write_reg(0x8680,0x00);
	ov3640_write_reg(0x8681,0x7D);
	ov3640_write_reg(0x8682,0x06);
	ov3640_write_reg(0x8683,0x12);
	ov3640_write_reg(0x8684,0x0C);
	ov3640_write_reg(0x8685,0x36);
	ov3640_write_reg(0x8686,0xEF);
	ov3640_write_reg(0x8687,0x78);
	ov3640_write_reg(0x8688,0x03);
	ov3640_write_reg(0x8689,0xCE);
	ov3640_write_reg(0x868A,0xC3);
	ov3640_write_reg(0x868B,0x13);
	ov3640_write_reg(0x868C,0xCE);
	ov3640_write_reg(0x868D,0x13);
	ov3640_write_reg(0x868E,0xD8);
	ov3640_write_reg(0x868F,0xF9);
	ov3640_write_reg(0x8690,0xFD);
	ov3640_write_reg(0x8691,0xAC);
	ov3640_write_reg(0x8692,0x06);
	ov3640_write_reg(0x8693,0xE5);
	ov3640_write_reg(0x8694,0x15);
	ov3640_write_reg(0x8695,0x54);
	ov3640_write_reg(0x8696,0x0F);
	ov3640_write_reg(0x8697,0xFB);
	ov3640_write_reg(0x8698,0xE5);
	ov3640_write_reg(0x8699,0x17);
	ov3640_write_reg(0x869A,0x54);
	ov3640_write_reg(0x869B,0x07);
	ov3640_write_reg(0x869C,0xC4);
	ov3640_write_reg(0x869D,0xF8);
	ov3640_write_reg(0x869E,0x54);
	ov3640_write_reg(0x869F,0xF0);
	ov3640_write_reg(0x86A0,0xC8);
	ov3640_write_reg(0x86A1,0xE4);
	ov3640_write_reg(0x86A2,0xC4);
	ov3640_write_reg(0x86A3,0x54);
	ov3640_write_reg(0x86A4,0x0F);
	ov3640_write_reg(0x86A5,0x48);
	ov3640_write_reg(0x86A6,0x2B);
	ov3640_write_reg(0x86A7,0xFB);
	ov3640_write_reg(0x86A8,0xE5);
	ov3640_write_reg(0x86A9,0x19);
	ov3640_write_reg(0x86AA,0x54);
	ov3640_write_reg(0x86AB,0x0F);
	ov3640_write_reg(0x86AC,0xFA);
	ov3640_write_reg(0x86AD,0xEC);
	ov3640_write_reg(0x86AE,0x54);
	ov3640_write_reg(0x86AF,0x07);
	ov3640_write_reg(0x86B0,0xC4);
	ov3640_write_reg(0x86B1,0xF8);
	ov3640_write_reg(0x86B2,0x54);
	ov3640_write_reg(0x86B3,0xF0);
	ov3640_write_reg(0x86B4,0xC8);
	ov3640_write_reg(0x86B5,0xE4);
	ov3640_write_reg(0x86B6,0xC4);
	ov3640_write_reg(0x86B7,0x54);
	ov3640_write_reg(0x86B8,0x0F);
	ov3640_write_reg(0x86B9,0x48);
	ov3640_write_reg(0x86BA,0x2A);
	ov3640_write_reg(0x86BB,0xFF);
	ov3640_write_reg(0x86BC,0x90);
	ov3640_write_reg(0x86BD,0x33);
	ov3640_write_reg(0x86BE,0xAA);
	ov3640_write_reg(0x86BF,0xEB);
	ov3640_write_reg(0x86C0,0xF0);
	ov3640_write_reg(0x86C1,0xE5);
	ov3640_write_reg(0x86C2,0x16);
	ov3640_write_reg(0x86C3,0xA3);
	ov3640_write_reg(0x86C4,0xF0);
	ov3640_write_reg(0x86C5,0xE5);
	ov3640_write_reg(0x86C6,0x18);
	ov3640_write_reg(0x86C7,0xA3);
	ov3640_write_reg(0x86C8,0xF0);
	ov3640_write_reg(0x86C9,0xA3);
	ov3640_write_reg(0x86CA,0xEF);
	ov3640_write_reg(0x86CB,0xF0);
	ov3640_write_reg(0x86CC,0xE5);
	ov3640_write_reg(0x86CD,0x1A);
	ov3640_write_reg(0x86CE,0xA3);
	ov3640_write_reg(0x86CF,0xF0);
	ov3640_write_reg(0x86D0,0xAF);
	ov3640_write_reg(0x86D1,0x05);
	ov3640_write_reg(0x86D2,0xEF);
	ov3640_write_reg(0x86D3,0xA3);
	ov3640_write_reg(0x86D4,0xF0);
	ov3640_write_reg(0x86D5,0x22);
	ov3640_write_reg(0x86D6,0x90);
	ov3640_write_reg(0x86D7,0x33);
	ov3640_write_reg(0x86D8,0x62);
	ov3640_write_reg(0x86D9,0xE0);
	ov3640_write_reg(0x86DA,0x54);
	ov3640_write_reg(0x86DB,0x0F);
	ov3640_write_reg(0x86DC,0xFE);
	ov3640_write_reg(0x86DD,0xA3);
	ov3640_write_reg(0x86DE,0xE0);
	ov3640_write_reg(0x86DF,0x7C);
	ov3640_write_reg(0x86E0,0x00);
	ov3640_write_reg(0x86E1,0x24);
	ov3640_write_reg(0x86E2,0x00);
	ov3640_write_reg(0x86E3,0xF5);
	ov3640_write_reg(0x86E4,0x0E);
	ov3640_write_reg(0x86E5,0xEC);
	ov3640_write_reg(0x86E6,0x3E);
	ov3640_write_reg(0x86E7,0xF5);
	ov3640_write_reg(0x86E8,0x0D);
	ov3640_write_reg(0x86E9,0x90);
	ov3640_write_reg(0x86EA,0x33);
	ov3640_write_reg(0x86EB,0x62);
	ov3640_write_reg(0x86EC,0xE0);
	ov3640_write_reg(0x86ED,0x54);
	ov3640_write_reg(0x86EE,0x70);
	ov3640_write_reg(0x86EF,0x75);
	ov3640_write_reg(0x86F0,0xF0);
	ov3640_write_reg(0x86F1,0x10);
	ov3640_write_reg(0x86F2,0xA4);
	ov3640_write_reg(0x86F3,0xFF);
	ov3640_write_reg(0x86F4,0xAE);
	ov3640_write_reg(0x86F5,0xF0);
	ov3640_write_reg(0x86F6,0x90);
	ov3640_write_reg(0x86F7,0x33);
	ov3640_write_reg(0x86F8,0x64);
	ov3640_write_reg(0x86F9,0xE0);
	ov3640_write_reg(0x86FA,0x2F);
	ov3640_write_reg(0x86FB,0xF5);
	ov3640_write_reg(0x86FC,0x10);
	ov3640_write_reg(0x86FD,0xEC);
	ov3640_write_reg(0x86FE,0x3E);
	ov3640_write_reg(0x86FF,0xF5);
	ov3640_write_reg(0x8700,0x0F);
	ov3640_write_reg(0x8701,0x85);
	ov3640_write_reg(0x8702,0x0D);
	ov3640_write_reg(0x8703,0x51);
	ov3640_write_reg(0x8704,0x85);
	ov3640_write_reg(0x8705,0x0E);
	ov3640_write_reg(0x8706,0x52);
	ov3640_write_reg(0x8707,0xF5);
	ov3640_write_reg(0x8708,0x53);
	ov3640_write_reg(0x8709,0x85);
	ov3640_write_reg(0x870A,0x10);
	ov3640_write_reg(0x870B,0x54);
	ov3640_write_reg(0x870C,0x85);
	ov3640_write_reg(0x870D,0x0D);
	ov3640_write_reg(0x870E,0x11);
	ov3640_write_reg(0x870F,0x85);
	ov3640_write_reg(0x8710,0x0E);
	ov3640_write_reg(0x8711,0x12);
	ov3640_write_reg(0x8712,0xF5);
	ov3640_write_reg(0x8713,0x13);
	ov3640_write_reg(0x8714,0x85);
	ov3640_write_reg(0x8715,0x10);
	ov3640_write_reg(0x8716,0x14);
	ov3640_write_reg(0x8717,0xE4);
	ov3640_write_reg(0x8718,0xF5);
	ov3640_write_reg(0x8719,0x15);
	ov3640_write_reg(0x871A,0x12);
	ov3640_write_reg(0x871B,0x03);
	ov3640_write_reg(0x871C,0x7B);
	ov3640_write_reg(0x871D,0x90);
	ov3640_write_reg(0x871E,0x33);
	ov3640_write_reg(0x871F,0x65);
	ov3640_write_reg(0x8720,0xE0);
	ov3640_write_reg(0x8721,0x30);
	ov3640_write_reg(0x8722,0xE3);
	ov3640_write_reg(0x8723,0x35);
	ov3640_write_reg(0x8724,0x90);
	ov3640_write_reg(0x8725,0x33);
	ov3640_write_reg(0x8726,0xA4);
	ov3640_write_reg(0x8727,0xE0);
	ov3640_write_reg(0x8728,0x54);
	ov3640_write_reg(0x8729,0x0F);
	ov3640_write_reg(0x872A,0xFC);
	ov3640_write_reg(0x872B,0xA3);
	ov3640_write_reg(0x872C,0xE0);
	ov3640_write_reg(0x872D,0x75);
	ov3640_write_reg(0x872E,0xF0);
	ov3640_write_reg(0x872F,0x04);
	ov3640_write_reg(0x8730,0xA4);
	ov3640_write_reg(0x8731,0xAE);
	ov3640_write_reg(0x8732,0xF0);
	ov3640_write_reg(0x8733,0x24);
	ov3640_write_reg(0x8734,0x00);
	ov3640_write_reg(0x8735,0xF5);
	ov3640_write_reg(0x8736,0x0E);
	ov3640_write_reg(0x8737,0xEE);
	ov3640_write_reg(0x8738,0x3C);
	ov3640_write_reg(0x8739,0xF5);
	ov3640_write_reg(0x873A,0x0D);
	ov3640_write_reg(0x873B,0x90);
	ov3640_write_reg(0x873C,0x33);
	ov3640_write_reg(0x873D,0xA4);
	ov3640_write_reg(0x873E,0xE0);
	ov3640_write_reg(0x873F,0x54);
	ov3640_write_reg(0x8740,0x70);
	ov3640_write_reg(0x8741,0x75);
	ov3640_write_reg(0x8742,0xF0);
	ov3640_write_reg(0x8743,0x10);
	ov3640_write_reg(0x8744,0xA4);
	ov3640_write_reg(0x8745,0xFD);
	ov3640_write_reg(0x8746,0xAC);
	ov3640_write_reg(0x8747,0xF0);
	ov3640_write_reg(0x8748,0x90);
	ov3640_write_reg(0x8749,0x33);
	ov3640_write_reg(0x874A,0xA6);
	ov3640_write_reg(0x874B,0xE0);
	ov3640_write_reg(0x874C,0x75);
	ov3640_write_reg(0x874D,0xF0);
	ov3640_write_reg(0x874E,0x04);
	ov3640_write_reg(0x874F,0xA4);
	ov3640_write_reg(0x8750,0xAE);
	ov3640_write_reg(0x8751,0xF0);
	ov3640_write_reg(0x8752,0x2D);
	ov3640_write_reg(0x8753,0xF5);
	ov3640_write_reg(0x8754,0x10);
	ov3640_write_reg(0x8755,0xEE);
	ov3640_write_reg(0x8756,0x3C);
	ov3640_write_reg(0x8757,0xF5);
	ov3640_write_reg(0x8758,0x0F);
	ov3640_write_reg(0x8759,0x85);
	ov3640_write_reg(0x875A,0x0D);
	ov3640_write_reg(0x875B,0x55);
	ov3640_write_reg(0x875C,0x85);
	ov3640_write_reg(0x875D,0x0E);
	ov3640_write_reg(0x875E,0x56);
	ov3640_write_reg(0x875F,0x85);
	ov3640_write_reg(0x8760,0x0F);
	ov3640_write_reg(0x8761,0x57);
	ov3640_write_reg(0x8762,0x85);
	ov3640_write_reg(0x8763,0x10);
	ov3640_write_reg(0x8764,0x58);
	ov3640_write_reg(0x8765,0x85);
	ov3640_write_reg(0x8766,0x0D);
	ov3640_write_reg(0x8767,0x11);
	ov3640_write_reg(0x8768,0x85);
	ov3640_write_reg(0x8769,0x0E);
	ov3640_write_reg(0x876A,0x12);
	ov3640_write_reg(0x876B,0x85);
	ov3640_write_reg(0x876C,0x0F);
	ov3640_write_reg(0x876D,0x13);
	ov3640_write_reg(0x876E,0x85);
	ov3640_write_reg(0x876F,0x10);
	ov3640_write_reg(0x8770,0x14);
	ov3640_write_reg(0x8771,0x02);
	ov3640_write_reg(0x8772,0x06);
	ov3640_write_reg(0x8773,0x34);
	ov3640_write_reg(0x8774,0x78);
	ov3640_write_reg(0x8775,0x7F);
	ov3640_write_reg(0x8776,0xE4);
	ov3640_write_reg(0x8777,0xF6);
	ov3640_write_reg(0x8778,0xD8);
	ov3640_write_reg(0x8779,0xFD);
	ov3640_write_reg(0x877A,0x75);
	ov3640_write_reg(0x877B,0x81);
	ov3640_write_reg(0x877C,0x58);
	ov3640_write_reg(0x877D,0x02);
	ov3640_write_reg(0x877E,0x07);
	ov3640_write_reg(0x877F,0xBB);
	ov3640_write_reg(0x8780,0x02);
	ov3640_write_reg(0x8781,0x0B);
	ov3640_write_reg(0x8782,0xFE);
	ov3640_write_reg(0x8783,0xE4);
	ov3640_write_reg(0x8784,0x93);
	ov3640_write_reg(0x8785,0xA3);
	ov3640_write_reg(0x8786,0xF8);
	ov3640_write_reg(0x8787,0xE4);
	ov3640_write_reg(0x8788,0x93);
	ov3640_write_reg(0x8789,0xA3);
	ov3640_write_reg(0x878A,0x40);
	ov3640_write_reg(0x878B,0x03);
	ov3640_write_reg(0x878C,0xF6);
	ov3640_write_reg(0x878D,0x80);
	ov3640_write_reg(0x878E,0x01);
	ov3640_write_reg(0x878F,0xF2);
	ov3640_write_reg(0x8790,0x08);
	ov3640_write_reg(0x8791,0xDF);
	ov3640_write_reg(0x8792,0xF4);
	ov3640_write_reg(0x8793,0x80);
	ov3640_write_reg(0x8794,0x29);
	ov3640_write_reg(0x8795,0xE4);
	ov3640_write_reg(0x8796,0x93);
	ov3640_write_reg(0x8797,0xA3);
	ov3640_write_reg(0x8798,0xF8);
	ov3640_write_reg(0x8799,0x54);
	ov3640_write_reg(0x879A,0x07);
	ov3640_write_reg(0x879B,0x24);
	ov3640_write_reg(0x879C,0x0C);
	ov3640_write_reg(0x879D,0xC8);
	ov3640_write_reg(0x879E,0xC3);
	ov3640_write_reg(0x879F,0x33);
	ov3640_write_reg(0x87A0,0xC4);
	ov3640_write_reg(0x87A1,0x54);
	ov3640_write_reg(0x87A2,0x0F);
	ov3640_write_reg(0x87A3,0x44);
	ov3640_write_reg(0x87A4,0x20);
	ov3640_write_reg(0x87A5,0xC8);
	ov3640_write_reg(0x87A6,0x83);
	ov3640_write_reg(0x87A7,0x40);
	ov3640_write_reg(0x87A8,0x04);
	ov3640_write_reg(0x87A9,0xF4);
	ov3640_write_reg(0x87AA,0x56);
	ov3640_write_reg(0x87AB,0x80);
	ov3640_write_reg(0x87AC,0x01);
	ov3640_write_reg(0x87AD,0x46);
	ov3640_write_reg(0x87AE,0xF6);
	ov3640_write_reg(0x87AF,0xDF);
	ov3640_write_reg(0x87B0,0xE4);
	ov3640_write_reg(0x87B1,0x80);
	ov3640_write_reg(0x87B2,0x0B);
	ov3640_write_reg(0x87B3,0x01);
	ov3640_write_reg(0x87B4,0x02);
	ov3640_write_reg(0x87B5,0x04);
	ov3640_write_reg(0x87B6,0x08);
	ov3640_write_reg(0x87B7,0x10);
	ov3640_write_reg(0x87B8,0x20);
	ov3640_write_reg(0x87B9,0x40);
	ov3640_write_reg(0x87BA,0x80);
	ov3640_write_reg(0x87BB,0x90);
	ov3640_write_reg(0x87BC,0x0D);
	ov3640_write_reg(0x87BD,0x39);
	ov3640_write_reg(0x87BE,0xE4);
	ov3640_write_reg(0x87BF,0x7E);
	ov3640_write_reg(0x87C0,0x01);
	ov3640_write_reg(0x87C1,0x93);
	ov3640_write_reg(0x87C2,0x60);
	ov3640_write_reg(0x87C3,0xBC);
	ov3640_write_reg(0x87C4,0xA3);
	ov3640_write_reg(0x87C5,0xFF);
	ov3640_write_reg(0x87C6,0x54);
	ov3640_write_reg(0x87C7,0x3F);
	ov3640_write_reg(0x87C8,0x30);
	ov3640_write_reg(0x87C9,0xE5);
	ov3640_write_reg(0x87CA,0x09);
	ov3640_write_reg(0x87CB,0x54);
	ov3640_write_reg(0x87CC,0x1F);
	ov3640_write_reg(0x87CD,0xFE);
	ov3640_write_reg(0x87CE,0xE4);
	ov3640_write_reg(0x87CF,0x93);
	ov3640_write_reg(0x87D0,0xA3);
	ov3640_write_reg(0x87D1,0x60);
	ov3640_write_reg(0x87D2,0x01);
	ov3640_write_reg(0x87D3,0x0E);
	ov3640_write_reg(0x87D4,0xCF);
	ov3640_write_reg(0x87D5,0x54);
	ov3640_write_reg(0x87D6,0xC0);
	ov3640_write_reg(0x87D7,0x25);
	ov3640_write_reg(0x87D8,0xE0);
	ov3640_write_reg(0x87D9,0x60);
	ov3640_write_reg(0x87DA,0xA8);
	ov3640_write_reg(0x87DB,0x40);
	ov3640_write_reg(0x87DC,0xB8);
	ov3640_write_reg(0x87DD,0xE4);
	ov3640_write_reg(0x87DE,0x93);
	ov3640_write_reg(0x87DF,0xA3);
	ov3640_write_reg(0x87E0,0xFA);
	ov3640_write_reg(0x87E1,0xE4);
	ov3640_write_reg(0x87E2,0x93);
	ov3640_write_reg(0x87E3,0xA3);
	ov3640_write_reg(0x87E4,0xF8);
	ov3640_write_reg(0x87E5,0xE4);
	ov3640_write_reg(0x87E6,0x93);
	ov3640_write_reg(0x87E7,0xA3);
	ov3640_write_reg(0x87E8,0xC8);
	ov3640_write_reg(0x87E9,0xC5);
	ov3640_write_reg(0x87EA,0x82);
	ov3640_write_reg(0x87EB,0xC8);
	ov3640_write_reg(0x87EC,0xCA);
	ov3640_write_reg(0x87ED,0xC5);
	ov3640_write_reg(0x87EE,0x83);
	ov3640_write_reg(0x87EF,0xCA);
	ov3640_write_reg(0x87F0,0xF0);
	ov3640_write_reg(0x87F1,0xA3);
	ov3640_write_reg(0x87F2,0xC8);
	ov3640_write_reg(0x87F3,0xC5);
	ov3640_write_reg(0x87F4,0x82);
	ov3640_write_reg(0x87F5,0xC8);
	ov3640_write_reg(0x87F6,0xCA);
	ov3640_write_reg(0x87F7,0xC5);
	ov3640_write_reg(0x87F8,0x83);
	ov3640_write_reg(0x87F9,0xCA);
	ov3640_write_reg(0x87FA,0xDF);
	ov3640_write_reg(0x87FB,0xE9);
	ov3640_write_reg(0x87FC,0xDE);
	ov3640_write_reg(0x87FD,0xE7);
	ov3640_write_reg(0x87FE,0x80);
	ov3640_write_reg(0x87FF,0xBE);
	ov3640_write_reg(0x8800,0xC0);
	ov3640_write_reg(0x8801,0xE0);
	ov3640_write_reg(0x8802,0xC0);
	ov3640_write_reg(0x8803,0xF0);
	ov3640_write_reg(0x8804,0xC0);
	ov3640_write_reg(0x8805,0x83);
	ov3640_write_reg(0x8806,0xC0);
	ov3640_write_reg(0x8807,0x82);
	ov3640_write_reg(0x8808,0xC0);
	ov3640_write_reg(0x8809,0xD0);
	ov3640_write_reg(0x880A,0x75);
	ov3640_write_reg(0x880B,0xD0);
	ov3640_write_reg(0x880C,0x00);
	ov3640_write_reg(0x880D,0xC0);
	ov3640_write_reg(0x880E,0x00);
	ov3640_write_reg(0x880F,0xC0);
	ov3640_write_reg(0x8810,0x01);
	ov3640_write_reg(0x8811,0xC0);
	ov3640_write_reg(0x8812,0x02);
	ov3640_write_reg(0x8813,0xC0);
	ov3640_write_reg(0x8814,0x03);
	ov3640_write_reg(0x8815,0xC0);
	ov3640_write_reg(0x8816,0x04);
	ov3640_write_reg(0x8817,0xC0);
	ov3640_write_reg(0x8818,0x05);
	ov3640_write_reg(0x8819,0xC0);
	ov3640_write_reg(0x881A,0x06);
	ov3640_write_reg(0x881B,0xC0);
	ov3640_write_reg(0x881C,0x07);
	ov3640_write_reg(0x881D,0x90);
	ov3640_write_reg(0x881E,0x37);
	ov3640_write_reg(0x881F,0x08);
	ov3640_write_reg(0x8820,0xE0);
	ov3640_write_reg(0x8821,0xF5);
	ov3640_write_reg(0x8822,0x08);
	ov3640_write_reg(0x8823,0xE5);
	ov3640_write_reg(0x8824,0x08);
	ov3640_write_reg(0x8825,0x30);
	ov3640_write_reg(0x8826,0xE3);
	ov3640_write_reg(0x8827,0x28);
	ov3640_write_reg(0x8828,0x85);
	ov3640_write_reg(0x8829,0x3C);
	ov3640_write_reg(0x882A,0x37);
	ov3640_write_reg(0x882B,0x85);
	ov3640_write_reg(0x882C,0x3D);
	ov3640_write_reg(0x882D,0x38);
	ov3640_write_reg(0x882E,0x85);
	ov3640_write_reg(0x882F,0x3E);
	ov3640_write_reg(0x8830,0x39);
	ov3640_write_reg(0x8831,0x85);
	ov3640_write_reg(0x8832,0x3F);
	ov3640_write_reg(0x8833,0x3A);
	ov3640_write_reg(0x8834,0x75);
	ov3640_write_reg(0x8835,0x09);
	ov3640_write_reg(0x8836,0x00);
	ov3640_write_reg(0x8837,0x75);
	ov3640_write_reg(0x8838,0x0A);
	ov3640_write_reg(0x8839,0x00);
	ov3640_write_reg(0x883A,0x12);
	ov3640_write_reg(0x883B,0x08);
	ov3640_write_reg(0x883C,0x89);
	ov3640_write_reg(0x883D,0x8E);
	ov3640_write_reg(0x883E,0x3C);
	ov3640_write_reg(0x883F,0x8F);
	ov3640_write_reg(0x8840,0x3D);
	ov3640_write_reg(0x8841,0x75);
	ov3640_write_reg(0x8842,0x09);
	ov3640_write_reg(0x8843,0x00);
	ov3640_write_reg(0x8844,0x75);
	ov3640_write_reg(0x8845,0x0A);
	ov3640_write_reg(0x8846,0x01);
	ov3640_write_reg(0x8847,0x12);
	ov3640_write_reg(0x8848,0x08);
	ov3640_write_reg(0x8849,0x89);
	ov3640_write_reg(0x884A,0x8E);
	ov3640_write_reg(0x884B,0x3E);
	ov3640_write_reg(0x884C,0x8F);
	ov3640_write_reg(0x884D,0x3F);
	ov3640_write_reg(0x884E,0xD2);
	ov3640_write_reg(0x884F,0x09);
	ov3640_write_reg(0x8850,0xE5);
	ov3640_write_reg(0x8851,0x08);
	ov3640_write_reg(0x8852,0x30);
	ov3640_write_reg(0x8853,0xE1);
	ov3640_write_reg(0x8854,0x08);
	ov3640_write_reg(0x8855,0x90);
	ov3640_write_reg(0x8856,0x3F);
	ov3640_write_reg(0x8857,0x00);
	ov3640_write_reg(0x8858,0xE0);
	ov3640_write_reg(0x8859,0xF5);
	ov3640_write_reg(0x885A,0x4B);
	ov3640_write_reg(0x885B,0xE4);
	ov3640_write_reg(0x885C,0xF0);
	ov3640_write_reg(0x885D,0xE5);
	ov3640_write_reg(0x885E,0x08);
	ov3640_write_reg(0x885F,0x30);
	ov3640_write_reg(0x8860,0xE0);
	ov3640_write_reg(0x8861,0x06);
	ov3640_write_reg(0x8862,0x90);
	ov3640_write_reg(0x8863,0x3F);
	ov3640_write_reg(0x8864,0x01);
	ov3640_write_reg(0x8865,0xE5);
	ov3640_write_reg(0x8866,0x40);
	ov3640_write_reg(0x8867,0xF0);
	ov3640_write_reg(0x8868,0x90);
	ov3640_write_reg(0x8869,0x37);
	ov3640_write_reg(0x886A,0x08);
	ov3640_write_reg(0x886B,0xE5);
	ov3640_write_reg(0x886C,0x08);
	ov3640_write_reg(0x886D,0xF0);
	ov3640_write_reg(0x886E,0xD0);
	ov3640_write_reg(0x886F,0x07);
	ov3640_write_reg(0x8870,0xD0);
	ov3640_write_reg(0x8871,0x06);
	ov3640_write_reg(0x8872,0xD0);
	ov3640_write_reg(0x8873,0x05);
	ov3640_write_reg(0x8874,0xD0);
	ov3640_write_reg(0x8875,0x04);
	ov3640_write_reg(0x8876,0xD0);
	ov3640_write_reg(0x8877,0x03);
	ov3640_write_reg(0x8878,0xD0);
	ov3640_write_reg(0x8879,0x02);
	ov3640_write_reg(0x887A,0xD0);
	ov3640_write_reg(0x887B,0x01);
	ov3640_write_reg(0x887C,0xD0);
	ov3640_write_reg(0x887D,0x00);
	ov3640_write_reg(0x887E,0xD0);
	ov3640_write_reg(0x887F,0xD0);
	ov3640_write_reg(0x8880,0xD0);
	ov3640_write_reg(0x8881,0x82);
	ov3640_write_reg(0x8882,0xD0);
	ov3640_write_reg(0x8883,0x83);
	ov3640_write_reg(0x8884,0xD0);
	ov3640_write_reg(0x8885,0xF0);
	ov3640_write_reg(0x8886,0xD0);
	ov3640_write_reg(0x8887,0xE0);
	ov3640_write_reg(0x8888,0x32);
	ov3640_write_reg(0x8889,0xE5);
	ov3640_write_reg(0x888A,0x0A);
	ov3640_write_reg(0x888B,0x70);
	ov3640_write_reg(0x888C,0x36);
	ov3640_write_reg(0x888D,0xE5);
	ov3640_write_reg(0x888E,0x09);
	ov3640_write_reg(0x888F,0x75);
	ov3640_write_reg(0x8890,0xF0);
	ov3640_write_reg(0x8891,0x08);
	ov3640_write_reg(0x8892,0xA4);
	ov3640_write_reg(0x8893,0xFF);
	ov3640_write_reg(0x8894,0x24);
	ov3640_write_reg(0x8895,0x80);
	ov3640_write_reg(0x8896,0x90);
	ov3640_write_reg(0x8897,0x3A);
	ov3640_write_reg(0x8898,0x00);
	ov3640_write_reg(0x8899,0xF0);
	ov3640_write_reg(0x889A,0x90);
	ov3640_write_reg(0x889B,0x3A);
	ov3640_write_reg(0x889C,0x03);
	ov3640_write_reg(0x889D,0xE0);
	ov3640_write_reg(0x889E,0xF5);
	ov3640_write_reg(0x889F,0x0B);
	ov3640_write_reg(0x88A0,0xEF);
	ov3640_write_reg(0x88A1,0x24);
	ov3640_write_reg(0x88A2,0x81);
	ov3640_write_reg(0x88A3,0x90);
	ov3640_write_reg(0x88A4,0x3A);
	ov3640_write_reg(0x88A5,0x00);
	ov3640_write_reg(0x88A6,0xF0);
	ov3640_write_reg(0x88A7,0x90);
	ov3640_write_reg(0x88A8,0x3A);
	ov3640_write_reg(0x88A9,0x03);
	ov3640_write_reg(0x88AA,0xE0);
	ov3640_write_reg(0x88AB,0xFC);
	ov3640_write_reg(0x88AC,0xE5);
	ov3640_write_reg(0x88AD,0x09);
	ov3640_write_reg(0x88AE,0x75);
	ov3640_write_reg(0x88AF,0xF0);
	ov3640_write_reg(0x88B0,0x08);
	ov3640_write_reg(0x88B1,0xA4);
	ov3640_write_reg(0x88B2,0xFF);
	ov3640_write_reg(0x88B3,0x24);
	ov3640_write_reg(0x88B4,0x82);
	ov3640_write_reg(0x88B5,0x90);
	ov3640_write_reg(0x88B6,0x3A);
	ov3640_write_reg(0x88B7,0x00);
	ov3640_write_reg(0x88B8,0xF0);
	ov3640_write_reg(0x88B9,0x90);
	ov3640_write_reg(0x88BA,0x3A);
	ov3640_write_reg(0x88BB,0x03);
	ov3640_write_reg(0x88BC,0xE0);
	ov3640_write_reg(0x88BD,0xFD);
	ov3640_write_reg(0x88BE,0xEF);
	ov3640_write_reg(0x88BF,0x24);
	ov3640_write_reg(0x88C0,0x83);
	ov3640_write_reg(0x88C1,0x80);
	ov3640_write_reg(0x88C2,0x3A);
	ov3640_write_reg(0x88C3,0xE5);
	ov3640_write_reg(0x88C4,0x0A);
	ov3640_write_reg(0x88C5,0x64);
	ov3640_write_reg(0x88C6,0x01);
	ov3640_write_reg(0x88C7,0x70);
	ov3640_write_reg(0x88C8,0x3C);
	ov3640_write_reg(0x88C9,0xE5);
	ov3640_write_reg(0x88CA,0x09);
	ov3640_write_reg(0x88CB,0x75);
	ov3640_write_reg(0x88CC,0xF0);
	ov3640_write_reg(0x88CD,0x08);
	ov3640_write_reg(0x88CE,0xA4);
	ov3640_write_reg(0x88CF,0xFF);
	ov3640_write_reg(0x88D0,0x24);
	ov3640_write_reg(0x88D1,0x84);
	ov3640_write_reg(0x88D2,0x90);
	ov3640_write_reg(0x88D3,0x3A);
	ov3640_write_reg(0x88D4,0x00);
	ov3640_write_reg(0x88D5,0xF0);
	ov3640_write_reg(0x88D6,0x90);
	ov3640_write_reg(0x88D7,0x3A);
	ov3640_write_reg(0x88D8,0x03);
	ov3640_write_reg(0x88D9,0xE0);
	ov3640_write_reg(0x88DA,0xF5);
	ov3640_write_reg(0x88DB,0x0B);
	ov3640_write_reg(0x88DC,0xEF);
	ov3640_write_reg(0x88DD,0x24);
	ov3640_write_reg(0x88DE,0x85);
	ov3640_write_reg(0x88DF,0x90);
	ov3640_write_reg(0x88E0,0x3A);
	ov3640_write_reg(0x88E1,0x00);
	ov3640_write_reg(0x88E2,0xF0);
	ov3640_write_reg(0x88E3,0x90);
	ov3640_write_reg(0x88E4,0x3A);
	ov3640_write_reg(0x88E5,0x03);
	ov3640_write_reg(0x88E6,0xE0);
	ov3640_write_reg(0x88E7,0xFC);
	ov3640_write_reg(0x88E8,0xE5);
	ov3640_write_reg(0x88E9,0x09);
	ov3640_write_reg(0x88EA,0x75);
	ov3640_write_reg(0x88EB,0xF0);
	ov3640_write_reg(0x88EC,0x08);
	ov3640_write_reg(0x88ED,0xA4);
	ov3640_write_reg(0x88EE,0xFF);
	ov3640_write_reg(0x88EF,0x24);
	ov3640_write_reg(0x88F0,0x86);
	ov3640_write_reg(0x88F1,0x90);
	ov3640_write_reg(0x88F2,0x3A);
	ov3640_write_reg(0x88F3,0x00);
	ov3640_write_reg(0x88F4,0xF0);
	ov3640_write_reg(0x88F5,0x90);
	ov3640_write_reg(0x88F6,0x3A);
	ov3640_write_reg(0x88F7,0x03);
	ov3640_write_reg(0x88F8,0xE0);
	ov3640_write_reg(0x88F9,0xFD);
	ov3640_write_reg(0x88FA,0xEF);
	ov3640_write_reg(0x88FB,0x24);
	ov3640_write_reg(0x88FC,0x87);
	ov3640_write_reg(0x88FD,0x90);
	ov3640_write_reg(0x88FE,0x3A);
	ov3640_write_reg(0x88FF,0x00);
	ov3640_write_reg(0x8900,0xF0);
	ov3640_write_reg(0x8901,0x90);
	ov3640_write_reg(0x8902,0x3A);
	ov3640_write_reg(0x8903,0x03);
	ov3640_write_reg(0x8904,0xE0);
	ov3640_write_reg(0x8905,0xED);
	ov3640_write_reg(0x8906,0xFE);
	ov3640_write_reg(0x8907,0xEC);
	ov3640_write_reg(0x8908,0xFB);
	ov3640_write_reg(0x8909,0xEB);
	ov3640_write_reg(0x890A,0xFF);
	ov3640_write_reg(0x890B,0x22);
	ov3640_write_reg(0x890C,0x85);
	ov3640_write_reg(0x890D,0x3C);
	ov3640_write_reg(0x890E,0x33);
	ov3640_write_reg(0x890F,0x85);
	ov3640_write_reg(0x8910,0x3D);
	ov3640_write_reg(0x8911,0x34);
	ov3640_write_reg(0x8912,0xE5);
	ov3640_write_reg(0x8913,0x31);
	ov3640_write_reg(0x8914,0xD3);
	ov3640_write_reg(0x8915,0x94);
	ov3640_write_reg(0x8916,0x02);
	ov3640_write_reg(0x8917,0x40);
	ov3640_write_reg(0x8918,0x4F);
	ov3640_write_reg(0x8919,0xE5);
	ov3640_write_reg(0x891A,0x3D);
	ov3640_write_reg(0x891B,0x95);
	ov3640_write_reg(0x891C,0x34);
	ov3640_write_reg(0x891D,0xFF);
	ov3640_write_reg(0x891E,0xE5);
	ov3640_write_reg(0x891F,0x3C);
	ov3640_write_reg(0x8920,0x95);
	ov3640_write_reg(0x8921,0x33);
	ov3640_write_reg(0x8922,0xFE);
	ov3640_write_reg(0x8923,0x12);
	ov3640_write_reg(0x8924,0x0D);
	ov3640_write_reg(0x8925,0x27);
	ov3640_write_reg(0x8926,0xD3);
	ov3640_write_reg(0x8927,0xEF);
	ov3640_write_reg(0x8928,0x94);
	ov3640_write_reg(0x8929,0x40);
	ov3640_write_reg(0x892A,0xEE);
	ov3640_write_reg(0x892B,0x64);
	ov3640_write_reg(0x892C,0x80);
	ov3640_write_reg(0x892D,0x94);
	ov3640_write_reg(0x892E,0x80);
	ov3640_write_reg(0x892F,0x50);
	ov3640_write_reg(0x8930,0x05);
	ov3640_write_reg(0x8931,0x12);
	ov3640_write_reg(0x8932,0x0D);
	ov3640_write_reg(0x8933,0x4A);
	ov3640_write_reg(0x8934,0x50);
	ov3640_write_reg(0x8935,0x0A);
	ov3640_write_reg(0x8936,0x85);
	ov3640_write_reg(0x8937,0x3C);
	ov3640_write_reg(0x8938,0x33);
	ov3640_write_reg(0x8939,0x85);
	ov3640_write_reg(0x893A,0x3D);
	ov3640_write_reg(0x893B,0x34);
	ov3640_write_reg(0x893C,0xE4);
	ov3640_write_reg(0x893D,0xF5);
	ov3640_write_reg(0x893E,0x32);
	ov3640_write_reg(0x893F,0x22);
	ov3640_write_reg(0x8940,0x05);
	ov3640_write_reg(0x8941,0x32);
	ov3640_write_reg(0x8942,0xE5);
	ov3640_write_reg(0x8943,0x32);
	ov3640_write_reg(0x8944,0xD3);
	ov3640_write_reg(0x8945,0x94);
	ov3640_write_reg(0x8946,0x02);
	ov3640_write_reg(0x8947,0x40);
	ov3640_write_reg(0x8948,0x43);
	ov3640_write_reg(0x8949,0xE4);
	ov3640_write_reg(0x894A,0xF5);
	ov3640_write_reg(0x894B,0x31);
	ov3640_write_reg(0x894C,0xF5);
	ov3640_write_reg(0x894D,0x32);
	ov3640_write_reg(0x894E,0x75);
	ov3640_write_reg(0x894F,0x40);
	ov3640_write_reg(0x8950,0x69);
	ov3640_write_reg(0x8951,0xF5);
	ov3640_write_reg(0x8952,0x47);
	ov3640_write_reg(0x8953,0xF5);
	ov3640_write_reg(0x8954,0x48);
	ov3640_write_reg(0x8955,0x85);
	ov3640_write_reg(0x8956,0x47);
	ov3640_write_reg(0x8957,0x13);
	ov3640_write_reg(0x8958,0x85);
	ov3640_write_reg(0x8959,0x48);
	ov3640_write_reg(0x895A,0x14);
	ov3640_write_reg(0x895B,0x12);
	ov3640_write_reg(0x895C,0x0B);
	ov3640_write_reg(0x895D,0x86);
	ov3640_write_reg(0x895E,0x12);
	ov3640_write_reg(0x895F,0x0A);
	ov3640_write_reg(0x8960,0x7D);
	ov3640_write_reg(0x8961,0x90);
	ov3640_write_reg(0x8962,0x3F);
	ov3640_write_reg(0x8963,0x01);
	ov3640_write_reg(0x8964,0xE5);
	ov3640_write_reg(0x8965,0x40);
	ov3640_write_reg(0x8966,0xF0);
	ov3640_write_reg(0x8967,0x22);
	ov3640_write_reg(0x8968,0xC3);
	ov3640_write_reg(0x8969,0xE5);
	ov3640_write_reg(0x896A,0x3D);
	ov3640_write_reg(0x896B,0x95);
	ov3640_write_reg(0x896C,0x44);
	ov3640_write_reg(0x896D,0xFF);
	ov3640_write_reg(0x896E,0xE5);
	ov3640_write_reg(0x896F,0x3C);
	ov3640_write_reg(0x8970,0x95);
	ov3640_write_reg(0x8971,0x43);
	ov3640_write_reg(0x8972,0xFE);
	ov3640_write_reg(0x8973,0x12);
	ov3640_write_reg(0x8974,0x0D);
	ov3640_write_reg(0x8975,0x27);
	ov3640_write_reg(0x8976,0xD3);
	ov3640_write_reg(0x8977,0xEF);
	ov3640_write_reg(0x8978,0x94);
	ov3640_write_reg(0x8979,0x40);
	ov3640_write_reg(0x897A,0xEE);
	ov3640_write_reg(0x897B,0x64);
	ov3640_write_reg(0x897C,0x80);
	ov3640_write_reg(0x897D,0x94);
	ov3640_write_reg(0x897E,0x80);
	ov3640_write_reg(0x897F,0x50);
	ov3640_write_reg(0x8980,0x05);
	ov3640_write_reg(0x8981,0x12);
	ov3640_write_reg(0x8982,0x0D);
	ov3640_write_reg(0x8983,0x4A);
	ov3640_write_reg(0x8984,0x50);
	ov3640_write_reg(0x8985,0x03);
	ov3640_write_reg(0x8986,0x05);
	ov3640_write_reg(0x8987,0x31);
	ov3640_write_reg(0x8988,0x22);
	ov3640_write_reg(0x8989,0xE4);
	ov3640_write_reg(0x898A,0xF5);
	ov3640_write_reg(0x898B,0x31);
	ov3640_write_reg(0x898C,0x22);
	ov3640_write_reg(0x898D,0x7E);
	ov3640_write_reg(0x898E,0x08);
	ov3640_write_reg(0x898F,0xE5);
	ov3640_write_reg(0x8990,0x18);
	ov3640_write_reg(0x8991,0x33);
	ov3640_write_reg(0x8992,0x92);
	ov3640_write_reg(0x8993,0x01);
	ov3640_write_reg(0x8994,0x90);
	ov3640_write_reg(0x8995,0x30);
	ov3640_write_reg(0x8996,0xB4);
	ov3640_write_reg(0x8997,0xE5);
	ov3640_write_reg(0x8998,0x20);
	ov3640_write_reg(0x8999,0xF0);
	ov3640_write_reg(0x899A,0x7F);
	ov3640_write_reg(0x899B,0x0A);
	ov3640_write_reg(0x899C,0xAD);
	ov3640_write_reg(0x899D,0x07);
	ov3640_write_reg(0x899E,0x1F);
	ov3640_write_reg(0x899F,0xED);
	ov3640_write_reg(0x89A0,0x70);
	ov3640_write_reg(0x89A1,0xFA);
	ov3640_write_reg(0x89A2,0xE5);
	ov3640_write_reg(0x89A3,0x18);
	ov3640_write_reg(0x89A4,0x25);
	ov3640_write_reg(0x89A5,0xE0);
	ov3640_write_reg(0x89A6,0xF5);
	ov3640_write_reg(0x89A7,0x18);
	ov3640_write_reg(0x89A8,0xD2);
	ov3640_write_reg(0x89A9,0x00);
	ov3640_write_reg(0x89AA,0x90);
	ov3640_write_reg(0x89AB,0x30);
	ov3640_write_reg(0x89AC,0xB4);
	ov3640_write_reg(0x89AD,0xE5);
	ov3640_write_reg(0x89AE,0x20);
	ov3640_write_reg(0x89AF,0xF0);
	ov3640_write_reg(0x89B0,0x7F);
	ov3640_write_reg(0x89B1,0x0A);
	ov3640_write_reg(0x89B2,0xAD);
	ov3640_write_reg(0x89B3,0x07);
	ov3640_write_reg(0x89B4,0x1F);
	ov3640_write_reg(0x89B5,0xED);
	ov3640_write_reg(0x89B6,0x70);
	ov3640_write_reg(0x89B7,0xFA);
	ov3640_write_reg(0x89B8,0xC2);
	ov3640_write_reg(0x89B9,0x00);
	ov3640_write_reg(0x89BA,0x90);
	ov3640_write_reg(0x89BB,0x30);
	ov3640_write_reg(0x89BC,0xB4);
	ov3640_write_reg(0x89BD,0xE5);
	ov3640_write_reg(0x89BE,0x20);
	ov3640_write_reg(0x89BF,0xF0);
	ov3640_write_reg(0x89C0,0xDE);
	ov3640_write_reg(0x89C1,0xCD);
	ov3640_write_reg(0x89C2,0x90);
	ov3640_write_reg(0x89C3,0x30);
	ov3640_write_reg(0x89C4,0xB1);
	ov3640_write_reg(0x89C5,0xE0);
	ov3640_write_reg(0x89C6,0x54);
	ov3640_write_reg(0x89C7,0x7F);
	ov3640_write_reg(0x89C8,0xF0);
	ov3640_write_reg(0x89C9,0x7F);
	ov3640_write_reg(0x89CA,0x05);
	ov3640_write_reg(0x89CB,0xAE);
	ov3640_write_reg(0x89CC,0x07);
	ov3640_write_reg(0x89CD,0x1F);
	ov3640_write_reg(0x89CE,0xEE);
	ov3640_write_reg(0x89CF,0x70);
	ov3640_write_reg(0x89D0,0xFA);
	ov3640_write_reg(0x89D1,0xD2);
	ov3640_write_reg(0x89D2,0x00);
	ov3640_write_reg(0x89D3,0x90);
	ov3640_write_reg(0x89D4,0x30);
	ov3640_write_reg(0x89D5,0xB4);
	ov3640_write_reg(0x89D6,0xE5);
	ov3640_write_reg(0x89D7,0x20);
	ov3640_write_reg(0x89D8,0xF0);
	ov3640_write_reg(0x89D9,0x7F);
	ov3640_write_reg(0x89DA,0x05);
	ov3640_write_reg(0x89DB,0xAE);
	ov3640_write_reg(0x89DC,0x07);
	ov3640_write_reg(0x89DD,0x1F);
	ov3640_write_reg(0x89DE,0xEE);
	ov3640_write_reg(0x89DF,0x70);
	ov3640_write_reg(0x89E0,0xFA);
	ov3640_write_reg(0x89E1,0x90);
	ov3640_write_reg(0x89E2,0x30);
	ov3640_write_reg(0x89E3,0xB5);
	ov3640_write_reg(0x89E4,0xE0);
	ov3640_write_reg(0x89E5,0x54);
	ov3640_write_reg(0x89E6,0x02);
	ov3640_write_reg(0x89E7,0xFE);
	ov3640_write_reg(0x89E8,0xC2);
	ov3640_write_reg(0x89E9,0x00);
	ov3640_write_reg(0x89EA,0x90);
	ov3640_write_reg(0x89EB,0x30);
	ov3640_write_reg(0x89EC,0xB4);
	ov3640_write_reg(0x89ED,0xE5);
	ov3640_write_reg(0x89EE,0x20);
	ov3640_write_reg(0x89EF,0xF0);
	ov3640_write_reg(0x89F0,0x90);
	ov3640_write_reg(0x89F1,0x30);
	ov3640_write_reg(0x89F2,0xB1);
	ov3640_write_reg(0x89F3,0xE0);
	ov3640_write_reg(0x89F4,0x44);
	ov3640_write_reg(0x89F5,0x80);
	ov3640_write_reg(0x89F6,0xF0);
	ov3640_write_reg(0x89F7,0x7F);
	ov3640_write_reg(0x89F8,0x05);
	ov3640_write_reg(0x89F9,0xAD);
	ov3640_write_reg(0x89FA,0x07);
	ov3640_write_reg(0x89FB,0x1F);
	ov3640_write_reg(0x89FC,0xED);
	ov3640_write_reg(0x89FD,0x70);
	ov3640_write_reg(0x89FE,0xFA);
	ov3640_write_reg(0x89FF,0xBE);
	ov3640_write_reg(0x8A00,0x02);
	ov3640_write_reg(0x8A01,0x02);
	ov3640_write_reg(0x8A02,0xC3);
	ov3640_write_reg(0x8A03,0x22);
	ov3640_write_reg(0x8A04,0xD3);
	ov3640_write_reg(0x8A05,0x22);
	ov3640_write_reg(0x8A06,0xC2);
	ov3640_write_reg(0x8A07,0x8C);
	ov3640_write_reg(0x8A08,0x75);
	ov3640_write_reg(0x8A09,0x89);
	ov3640_write_reg(0x8A0A,0x03);
	ov3640_write_reg(0x8A0B,0xE4);
	ov3640_write_reg(0x8A0C,0xF5);
	ov3640_write_reg(0x8A0D,0xA8);
	ov3640_write_reg(0x8A0E,0x90);
	ov3640_write_reg(0x8A0F,0x31);
	ov3640_write_reg(0x8A10,0x00);
	ov3640_write_reg(0x8A11,0xE0);
	ov3640_write_reg(0x8A12,0x54);
	ov3640_write_reg(0x8A13,0xFE);
	ov3640_write_reg(0x8A14,0xF0);
	ov3640_write_reg(0x8A15,0xE0);
	ov3640_write_reg(0x8A16,0x54);
	ov3640_write_reg(0x8A17,0xFD);
	ov3640_write_reg(0x8A18,0xF0);
	ov3640_write_reg(0x8A19,0xA3);
	ov3640_write_reg(0x8A1A,0xE4);
	ov3640_write_reg(0x8A1B,0xF0);
	ov3640_write_reg(0x8A1C,0x90);
	ov3640_write_reg(0x8A1D,0x33);
	ov3640_write_reg(0x8A1E,0xB0);
	ov3640_write_reg(0x8A1F,0xF0);
	ov3640_write_reg(0x8A20,0xA3);
	ov3640_write_reg(0x8A21,0x04);
	ov3640_write_reg(0x8A22,0xF0);
	ov3640_write_reg(0x8A23,0xA3);
	ov3640_write_reg(0x8A24,0xF0);
	ov3640_write_reg(0x8A25,0x90);
	ov3640_write_reg(0x8A26,0x33);
	ov3640_write_reg(0x8A27,0x00);
	ov3640_write_reg(0x8A28,0xE0);
	ov3640_write_reg(0x8A29,0x44);
	ov3640_write_reg(0x8A2A,0x02);
	ov3640_write_reg(0x8A2B,0xF0);
	ov3640_write_reg(0x8A2C,0xE0);
	ov3640_write_reg(0x8A2D,0x54);
	ov3640_write_reg(0x8A2E,0xBF);
	ov3640_write_reg(0x8A2F,0xF0);
	ov3640_write_reg(0x8A30,0xD2);
	ov3640_write_reg(0x8A31,0x08);
	ov3640_write_reg(0x8A32,0x12);
	ov3640_write_reg(0x8A33,0x0C);
	ov3640_write_reg(0x8A34,0xD6);
	ov3640_write_reg(0x8A35,0x90);
	ov3640_write_reg(0x8A36,0x30);
	ov3640_write_reg(0x8A37,0xB2);
	ov3640_write_reg(0x8A38,0xE0);
	ov3640_write_reg(0x8A39,0x44);
	ov3640_write_reg(0x8A3A,0x10);
	ov3640_write_reg(0x8A3B,0xF0);
	ov3640_write_reg(0x8A3C,0x90);
	ov3640_write_reg(0x8A3D,0x30);
	ov3640_write_reg(0x8A3E,0xB4);
	ov3640_write_reg(0x8A3F,0xE0);
	ov3640_write_reg(0x8A40,0xF5);
	ov3640_write_reg(0x8A41,0x20);
	ov3640_write_reg(0x8A42,0x90);
	ov3640_write_reg(0x8A43,0x39);
	ov3640_write_reg(0x8A44,0x01);
	ov3640_write_reg(0x8A45,0x74);
	ov3640_write_reg(0x8A46,0x35);
	ov3640_write_reg(0x8A47,0xF0);
	ov3640_write_reg(0x8A48,0x90);
	ov3640_write_reg(0x8A49,0x39);
	ov3640_write_reg(0x8A4A,0x00);
	ov3640_write_reg(0x8A4B,0x74);
	ov3640_write_reg(0x8A4C,0x20);
	ov3640_write_reg(0x8A4D,0xF0);
	ov3640_write_reg(0x8A4E,0x90);
	ov3640_write_reg(0x8A4F,0x37);
	ov3640_write_reg(0x8A50,0x00);
	ov3640_write_reg(0x8A51,0x74);
	ov3640_write_reg(0x8A52,0xFF);
	ov3640_write_reg(0x8A53,0xF0);
	ov3640_write_reg(0x8A54,0xA3);
	ov3640_write_reg(0x8A55,0xF0);
	ov3640_write_reg(0x8A56,0x90);
	ov3640_write_reg(0x8A57,0x37);
	ov3640_write_reg(0x8A58,0x00);
	ov3640_write_reg(0x8A59,0xE0);
	ov3640_write_reg(0x8A5A,0x54);
	ov3640_write_reg(0x8A5B,0xF7);
	ov3640_write_reg(0x8A5C,0xF0);
	ov3640_write_reg(0x8A5D,0x90);
	ov3640_write_reg(0x8A5E,0x31);
	ov3640_write_reg(0x8A5F,0x0F);
	ov3640_write_reg(0x8A60,0x74);
	ov3640_write_reg(0x8A61,0x3F);
	ov3640_write_reg(0x8A62,0xF0);
	ov3640_write_reg(0x8A63,0xA3);
	ov3640_write_reg(0x8A64,0xE4);
	ov3640_write_reg(0x8A65,0xF0);
	ov3640_write_reg(0x8A66,0xA3);
	ov3640_write_reg(0x8A67,0x74);
	ov3640_write_reg(0x8A68,0x3F);
	ov3640_write_reg(0x8A69,0xF0);
	ov3640_write_reg(0x8A6A,0xA3);
	ov3640_write_reg(0x8A6B,0x74);
	ov3640_write_reg(0x8A6C,0x01);
	ov3640_write_reg(0x8A6D,0xF0);
	ov3640_write_reg(0x8A6E,0x90);
	ov3640_write_reg(0x8A6F,0x37);
	ov3640_write_reg(0x8A70,0x00);
	ov3640_write_reg(0x8A71,0xE0);
	ov3640_write_reg(0x8A72,0x54);
	ov3640_write_reg(0x8A73,0xFD);
	ov3640_write_reg(0x8A74,0xF0);
	ov3640_write_reg(0x8A75,0xE0);
	ov3640_write_reg(0x8A76,0x54);
	ov3640_write_reg(0x8A77,0xFE);
	ov3640_write_reg(0x8A78,0xF0);
	ov3640_write_reg(0x8A79,0x75);
	ov3640_write_reg(0x8A7A,0xA8);
	ov3640_write_reg(0x8A7B,0x01);
	ov3640_write_reg(0x8A7C,0x22);
	ov3640_write_reg(0x8A7D,0x85);
	ov3640_write_reg(0x8A7E,0x40);
	ov3640_write_reg(0x8A7F,0x0D);
	ov3640_write_reg(0x8A80,0xE5);
	ov3640_write_reg(0x8A81,0x0D);
	ov3640_write_reg(0x8A82,0x12);
	ov3640_write_reg(0x8A83,0x0C);
	ov3640_write_reg(0x8A84,0x48);
	ov3640_write_reg(0x8A85,0x0A);
	ov3640_write_reg(0x8A86,0xAA);
	ov3640_write_reg(0x8A87,0x00);
	ov3640_write_reg(0x8A88,0x0A);
	ov3640_write_reg(0x8A89,0xAC);
	ov3640_write_reg(0x8A8A,0x46);
	ov3640_write_reg(0x8A8B,0x0A);
	ov3640_write_reg(0x8A8C,0xAA);
	ov3640_write_reg(0x8A8D,0x47);
	ov3640_write_reg(0x8A8E,0x0A);
	ov3640_write_reg(0x8A8F,0xAC);
	ov3640_write_reg(0x8A90,0x4A);
	ov3640_write_reg(0x8A91,0x0A);
	ov3640_write_reg(0x8A92,0xAA);
	ov3640_write_reg(0x8A93,0x4B);
	ov3640_write_reg(0x8A94,0x0A);
	ov3640_write_reg(0x8A95,0xAA);
	ov3640_write_reg(0x8A96,0x4E);
	ov3640_write_reg(0x8A97,0x0A);
	ov3640_write_reg(0x8A98,0xC7);
	ov3640_write_reg(0x8A99,0x65);
	ov3640_write_reg(0x8A9A,0x0A);
	ov3640_write_reg(0x8A9B,0xC7);
	ov3640_write_reg(0x8A9C,0x69);
	ov3640_write_reg(0x8A9D,0x0A);
	ov3640_write_reg(0x8A9E,0xAA);
	ov3640_write_reg(0x8A9F,0x80);
	ov3640_write_reg(0x8AA0,0x0A);
	ov3640_write_reg(0x8AA1,0xB8);
	ov3640_write_reg(0x8AA2,0xC6);
	ov3640_write_reg(0x8AA3,0x0A);
	ov3640_write_reg(0x8AA4,0xB8);
	ov3640_write_reg(0x8AA5,0xCA);
	ov3640_write_reg(0x8AA6,0x00);
	ov3640_write_reg(0x8AA7,0x00);
	ov3640_write_reg(0x8AA8,0x0A);
	ov3640_write_reg(0x8AA9,0xAA);
	ov3640_write_reg(0x8AAA,0x80);
	ov3640_write_reg(0x8AAB,0x30);
	ov3640_write_reg(0x8AAC,0x90);
	ov3640_write_reg(0x8AAD,0x33);
	ov3640_write_reg(0x8AAE,0xB3);
	ov3640_write_reg(0x8AAF,0xE4);
	ov3640_write_reg(0x8AB0,0xF0);
	ov3640_write_reg(0x8AB1,0xA3);
	ov3640_write_reg(0x8AB2,0xF0);
	ov3640_write_reg(0x8AB3,0xA3);
	ov3640_write_reg(0x8AB4,0xF0);
	ov3640_write_reg(0x8AB5,0xA3);
	ov3640_write_reg(0x8AB6,0x80);
	ov3640_write_reg(0x8AB7,0x1E);
	ov3640_write_reg(0x8AB8,0x90);
	ov3640_write_reg(0x8AB9,0x33);
	ov3640_write_reg(0x8ABA,0xB3);
	ov3640_write_reg(0x8ABB,0xE4);
	ov3640_write_reg(0x8ABC,0xF0);
	ov3640_write_reg(0x8ABD,0xA3);
	ov3640_write_reg(0x8ABE,0xF0);
	ov3640_write_reg(0x8ABF,0xA3);
	ov3640_write_reg(0x8AC0,0x74);
	ov3640_write_reg(0x8AC1,0xFF);
	ov3640_write_reg(0x8AC2,0xF0);
	ov3640_write_reg(0x8AC3,0xA3);
	ov3640_write_reg(0x8AC4,0xE4);
	ov3640_write_reg(0x8AC5,0x80);
	ov3640_write_reg(0x8AC6,0x0F);
	ov3640_write_reg(0x8AC7,0x90);
	ov3640_write_reg(0x8AC8,0x33);
	ov3640_write_reg(0x8AC9,0xB3);
	ov3640_write_reg(0x8ACA,0x74);
	ov3640_write_reg(0x8ACB,0xFF);
	ov3640_write_reg(0x8ACC,0xF0);
	ov3640_write_reg(0x8ACD,0xA3);
	ov3640_write_reg(0x8ACE,0x74);
	ov3640_write_reg(0x8ACF,0x80);
	ov3640_write_reg(0x8AD0,0xF0);
	ov3640_write_reg(0x8AD1,0xA3);
	ov3640_write_reg(0x8AD2,0xF0);
	ov3640_write_reg(0x8AD3,0xA3);
	ov3640_write_reg(0x8AD4,0x74);
	ov3640_write_reg(0x8AD5,0xFF);
	ov3640_write_reg(0x8AD6,0xF0);
	ov3640_write_reg(0x8AD7,0x75);
	ov3640_write_reg(0x8AD8,0x0E);
	ov3640_write_reg(0x8AD9,0x01);
	ov3640_write_reg(0x8ADA,0x80);
	ov3640_write_reg(0x8ADB,0x03);
	ov3640_write_reg(0x8ADC,0xE4);
	ov3640_write_reg(0x8ADD,0xF5);
	ov3640_write_reg(0x8ADE,0x0E);
	ov3640_write_reg(0x8ADF,0x12);
	ov3640_write_reg(0x8AE0,0x0D);
	ov3640_write_reg(0x8AE1,0x13);
	ov3640_write_reg(0x8AE2,0x22);
	ov3640_write_reg(0x8AE3,0xE4);
	ov3640_write_reg(0x8AE4,0xF5);
	ov3640_write_reg(0x8AE5,0x4F);
	ov3640_write_reg(0x8AE6,0x75);
	ov3640_write_reg(0x8AE7,0x40);
	ov3640_write_reg(0x8AE8,0x80);
	ov3640_write_reg(0x8AE9,0x75);
	ov3640_write_reg(0x8AEA,0x3B);
	ov3640_write_reg(0x8AEB,0x32);
	ov3640_write_reg(0x8AEC,0x75);
	ov3640_write_reg(0x8AED,0x4C);
	ov3640_write_reg(0x8AEE,0x1E);
	ov3640_write_reg(0x8AEF,0xF5);
	ov3640_write_reg(0x8AF0,0x35);
	ov3640_write_reg(0x8AF1,0x75);
	ov3640_write_reg(0x8AF2,0x36);
	ov3640_write_reg(0x8AF3,0xC8);
	ov3640_write_reg(0x8AF4,0x75);
	ov3640_write_reg(0x8AF5,0x49);
	ov3640_write_reg(0x8AF6,0x01);
	ov3640_write_reg(0x8AF7,0x75);
	ov3640_write_reg(0x8AF8,0x4A);
	ov3640_write_reg(0x8AF9,0x5E);
	ov3640_write_reg(0x8AFA,0x75);
	ov3640_write_reg(0x8AFB,0x4D);
	ov3640_write_reg(0x8AFC,0x03);
	ov3640_write_reg(0x8AFD,0x75);
	ov3640_write_reg(0x8AFE,0x4E);
	ov3640_write_reg(0x8AFF,0x20);
	ov3640_write_reg(0x8B00,0xF5);
	ov3640_write_reg(0x8B01,0x41);
	ov3640_write_reg(0x8B02,0x75);
	ov3640_write_reg(0x8B03,0x42);
	ov3640_write_reg(0x8B04,0x28);
	ov3640_write_reg(0x8B05,0x90);
	ov3640_write_reg(0x8B06,0x3F);
	ov3640_write_reg(0x8B07,0x00);
	ov3640_write_reg(0x8B08,0xE0);
	ov3640_write_reg(0x8B09,0x30);
	ov3640_write_reg(0x8B0A,0xE7);
	ov3640_write_reg(0x8B0B,0x06);
	ov3640_write_reg(0x8B0C,0xE0);
	ov3640_write_reg(0x8B0D,0xF5);
	ov3640_write_reg(0x8B0E,0x0D);
	ov3640_write_reg(0x8B0F,0x12);
	ov3640_write_reg(0x8B10,0x05);
	ov3640_write_reg(0x8B11,0x7E);
	ov3640_write_reg(0x8B12,0xE4);
	ov3640_write_reg(0x8B13,0xF5);
	ov3640_write_reg(0x8B14,0x4B);
	ov3640_write_reg(0x8B15,0x90);
	ov3640_write_reg(0x8B16,0x3F);
	ov3640_write_reg(0x8B17,0x01);
	ov3640_write_reg(0x8B18,0xE5);
	ov3640_write_reg(0x8B19,0x40);
	ov3640_write_reg(0x8B1A,0xF0);
	ov3640_write_reg(0x8B1B,0xE4);
	ov3640_write_reg(0x8B1C,0xF5);
	ov3640_write_reg(0x8B1D,0x47);
	ov3640_write_reg(0x8B1E,0xF5);
	ov3640_write_reg(0x8B1F,0x48);
	ov3640_write_reg(0x8B20,0xF5);
	ov3640_write_reg(0x8B21,0x4F);
	ov3640_write_reg(0x8B22,0x85);
	ov3640_write_reg(0x8B23,0x47);
	ov3640_write_reg(0x8B24,0x0D);
	ov3640_write_reg(0x8B25,0x85);
	ov3640_write_reg(0x8B26,0x48);
	ov3640_write_reg(0x8B27,0x0E);
	ov3640_write_reg(0x8B28,0xF5);
	ov3640_write_reg(0x8B29,0x0F);
	ov3640_write_reg(0x8B2A,0xF5);
	ov3640_write_reg(0x8B2B,0x10);
	ov3640_write_reg(0x8B2C,0x12);
	ov3640_write_reg(0x8B2D,0x0B);
	ov3640_write_reg(0x8B2E,0x41);
	ov3640_write_reg(0x8B2F,0x50);
	ov3640_write_reg(0x8B30,0x07);
	ov3640_write_reg(0x8B31,0xE4);
	ov3640_write_reg(0x8B32,0xF5);
	ov3640_write_reg(0x8B33,0x40);
	ov3640_write_reg(0x8B34,0xD2);
	ov3640_write_reg(0x8B35,0xAF);
	ov3640_write_reg(0x8B36,0x80);
	ov3640_write_reg(0x8B37,0x02);
	ov3640_write_reg(0x8B38,0xC2);
	ov3640_write_reg(0x8B39,0xAF);
	ov3640_write_reg(0x8B3A,0x90);
	ov3640_write_reg(0x8B3B,0x3F);
	ov3640_write_reg(0x8B3C,0x01);
	ov3640_write_reg(0x8B3D,0xE5);
	ov3640_write_reg(0x8B3E,0x40);
	ov3640_write_reg(0x8B3F,0xF0);
	ov3640_write_reg(0x8B40,0x22);
	ov3640_write_reg(0x8B41,0x85);
	ov3640_write_reg(0x8B42,0x0D);
	ov3640_write_reg(0x8B43,0x11);
	ov3640_write_reg(0x8B44,0x85);
	ov3640_write_reg(0x8B45,0x0E);
	ov3640_write_reg(0x8B46,0x12);
	ov3640_write_reg(0x8B47,0xE5);
	ov3640_write_reg(0x8B48,0x10);
	ov3640_write_reg(0x8B49,0x24);
	ov3640_write_reg(0x8B4A,0x32);
	ov3640_write_reg(0x8B4B,0xFF);
	ov3640_write_reg(0x8B4C,0xE4);
	ov3640_write_reg(0x8B4D,0x35);
	ov3640_write_reg(0x8B4E,0x0F);
	ov3640_write_reg(0x8B4F,0xFE);
	ov3640_write_reg(0x8B50,0xD3);
	ov3640_write_reg(0x8B51,0xE5);
	ov3640_write_reg(0x8B52,0x12);
	ov3640_write_reg(0x8B53,0x9F);
	ov3640_write_reg(0x8B54,0xE5);
	ov3640_write_reg(0x8B55,0x11);
	ov3640_write_reg(0x8B56,0x9E);
	ov3640_write_reg(0x8B57,0x40);
	ov3640_write_reg(0x8B58,0x1F);
	ov3640_write_reg(0x8B59,0x74);
	ov3640_write_reg(0x8B5A,0xE2);
	ov3640_write_reg(0x8B5B,0x25);
	ov3640_write_reg(0x8B5C,0x12);
	ov3640_write_reg(0x8B5D,0xF5);
	ov3640_write_reg(0x8B5E,0x12);
	ov3640_write_reg(0x8B5F,0x74);
	ov3640_write_reg(0x8B60,0xFF);
	ov3640_write_reg(0x8B61,0x35);
	ov3640_write_reg(0x8B62,0x11);
	ov3640_write_reg(0x8B63,0xF5);
	ov3640_write_reg(0x8B64,0x11);
	ov3640_write_reg(0x8B65,0xF5);
	ov3640_write_reg(0x8B66,0x13);
	ov3640_write_reg(0x8B67,0x85);
	ov3640_write_reg(0x8B68,0x12);
	ov3640_write_reg(0x8B69,0x14);
	ov3640_write_reg(0x8B6A,0x12);
	ov3640_write_reg(0x8B6B,0x0B);
	ov3640_write_reg(0x8B6C,0x86);
	ov3640_write_reg(0x8B6D,0x40);
	ov3640_write_reg(0x8B6E,0x01);
	ov3640_write_reg(0x8B6F,0x22);
	ov3640_write_reg(0x8B70,0x75);
	ov3640_write_reg(0x8B71,0x13);
	ov3640_write_reg(0x8B72,0x02);
	ov3640_write_reg(0x8B73,0x12);
	ov3640_write_reg(0x8B74,0x0C);
	ov3640_write_reg(0x8B75,0xF9);
	ov3640_write_reg(0x8B76,0x80);
	ov3640_write_reg(0x8B77,0xCF);
	ov3640_write_reg(0x8B78,0x85);
	ov3640_write_reg(0x8B79,0x0F);
	ov3640_write_reg(0x8B7A,0x13);
	ov3640_write_reg(0x8B7B,0x85);
	ov3640_write_reg(0x8B7C,0x10);
	ov3640_write_reg(0x8B7D,0x14);
	ov3640_write_reg(0x8B7E,0x12);
	ov3640_write_reg(0x8B7F,0x0B);
	ov3640_write_reg(0x8B80,0x86);
	ov3640_write_reg(0x8B81,0x40);
	ov3640_write_reg(0x8B82,0x01);
	ov3640_write_reg(0x8B83,0x22);
	ov3640_write_reg(0x8B84,0xD3);
	ov3640_write_reg(0x8B85,0x22);
	ov3640_write_reg(0x8B86,0xE5);
	ov3640_write_reg(0x8B87,0x13);
	ov3640_write_reg(0x8B88,0x54);
	ov3640_write_reg(0x8B89,0x03);
	ov3640_write_reg(0x8B8A,0xFC);
	ov3640_write_reg(0x8B8B,0xAD);
	ov3640_write_reg(0x8B8C,0x14);
	ov3640_write_reg(0x8B8D,0xED);
	ov3640_write_reg(0x8B8E,0xC4);
	ov3640_write_reg(0x8B8F,0xF8);
	ov3640_write_reg(0x8B90,0x54);
	ov3640_write_reg(0x8B91,0x0F);
	ov3640_write_reg(0x8B92,0xC8);
	ov3640_write_reg(0x8B93,0x68);
	ov3640_write_reg(0x8B94,0xFF);
	ov3640_write_reg(0x8B95,0xEC);
	ov3640_write_reg(0x8B96,0xC4);
	ov3640_write_reg(0x8B97,0x54);
	ov3640_write_reg(0x8B98,0xF0);
	ov3640_write_reg(0x8B99,0x48);
	ov3640_write_reg(0x8B9A,0xAB);
	ov3640_write_reg(0x8B9B,0x07);
	ov3640_write_reg(0x8B9C,0xFA);
	ov3640_write_reg(0x8B9D,0x43);
	ov3640_write_reg(0x8B9E,0x03);
	ov3640_write_reg(0x8B9F,0x0D);
	ov3640_write_reg(0x8BA0,0xEC);
	ov3640_write_reg(0x8BA1,0x90);
	ov3640_write_reg(0x8BA2,0x3F);
	ov3640_write_reg(0x8BA3,0x05);
	ov3640_write_reg(0x8BA4,0xF0);
	ov3640_write_reg(0x8BA5,0xA3);
	ov3640_write_reg(0x8BA6,0xE5);
	ov3640_write_reg(0x8BA7,0x14);
	ov3640_write_reg(0x8BA8,0xF0);
	ov3640_write_reg(0x8BA9,0x45);
	ov3640_write_reg(0x8BAA,0x13);
	ov3640_write_reg(0x8BAB,0x70);
	ov3640_write_reg(0x8BAC,0x03);
	ov3640_write_reg(0x8BAD,0x7A);
	ov3640_write_reg(0x8BAE,0x80);
	ov3640_write_reg(0x8BAF,0xFB);
	ov3640_write_reg(0x8BB0,0x8A);
	ov3640_write_reg(0x8BB1,0x15);
	ov3640_write_reg(0x8BB2,0x8B);
	ov3640_write_reg(0x8BB3,0x16);
	ov3640_write_reg(0x8BB4,0x12);
	ov3640_write_reg(0x8BB5,0x0B);
	ov3640_write_reg(0x8BB6,0xC5);
	ov3640_write_reg(0x8BB7,0x40);
	ov3640_write_reg(0x8BB8,0x01);
	ov3640_write_reg(0x8BB9,0x22);
	ov3640_write_reg(0x8BBA,0xE5);
	ov3640_write_reg(0x8BBB,0x13);
	ov3640_write_reg(0x8BBC,0x54);
	ov3640_write_reg(0x8BBD,0x03);
	ov3640_write_reg(0x8BBE,0xF5);
	ov3640_write_reg(0x8BBF,0x1D);
	ov3640_write_reg(0x8BC0,0x85);
	ov3640_write_reg(0x8BC1,0x14);
	ov3640_write_reg(0x8BC2,0x1E);
	ov3640_write_reg(0x8BC3,0xD3);
	ov3640_write_reg(0x8BC4,0x22);
	ov3640_write_reg(0x8BC5,0xE4);
	ov3640_write_reg(0x8BC6,0xF5);
	ov3640_write_reg(0x8BC7,0x17);
	ov3640_write_reg(0x8BC8,0x12);
	ov3640_write_reg(0x8BC9,0x0C);
	ov3640_write_reg(0x8BCA,0x6E);
	ov3640_write_reg(0x8BCB,0x75);
	ov3640_write_reg(0x8BCC,0x18);
	ov3640_write_reg(0x8BCD,0x18);
	ov3640_write_reg(0x8BCE,0x12);
	ov3640_write_reg(0x8BCF,0x09);
	ov3640_write_reg(0x8BD0,0x8D);
	ov3640_write_reg(0x8BD1,0x40);
	ov3640_write_reg(0x8BD2,0x02);
	ov3640_write_reg(0x8BD3,0x80);
	ov3640_write_reg(0x8BD4,0x14);
	ov3640_write_reg(0x8BD5,0xE5);
	ov3640_write_reg(0x8BD6,0x15);
	ov3640_write_reg(0x8BD7,0xF5);
	ov3640_write_reg(0x8BD8,0x18);
	ov3640_write_reg(0x8BD9,0x12);
	ov3640_write_reg(0x8BDA,0x09);
	ov3640_write_reg(0x8BDB,0x8D);
	ov3640_write_reg(0x8BDC,0x40);
	ov3640_write_reg(0x8BDD,0x02);
	ov3640_write_reg(0x8BDE,0x80);
	ov3640_write_reg(0x8BDF,0x09);
	ov3640_write_reg(0x8BE0,0xE5);
	ov3640_write_reg(0x8BE1,0x16);
	ov3640_write_reg(0x8BE2,0xF5);
	ov3640_write_reg(0x8BE3,0x18);
	ov3640_write_reg(0x8BE4,0x12);
	ov3640_write_reg(0x8BE5,0x09);
	ov3640_write_reg(0x8BE6,0x8D);
	ov3640_write_reg(0x8BE7,0x40);
	ov3640_write_reg(0x8BE8,0x05);
	ov3640_write_reg(0x8BE9,0x12);
	ov3640_write_reg(0x8BEA,0x0C);
	ov3640_write_reg(0x8BEB,0xA3);
	ov3640_write_reg(0x8BEC,0x80);
	ov3640_write_reg(0x8BED,0x05);
	ov3640_write_reg(0x8BEE,0x12);
	ov3640_write_reg(0x8BEF,0x0C);
	ov3640_write_reg(0x8BF0,0xA3);
	ov3640_write_reg(0x8BF1,0xD3);
	ov3640_write_reg(0x8BF2,0x22);
	ov3640_write_reg(0x8BF3,0x05);
	ov3640_write_reg(0x8BF4,0x17);
	ov3640_write_reg(0x8BF5,0xE5);
	ov3640_write_reg(0x8BF6,0x17);
	ov3640_write_reg(0x8BF7,0xC3);
	ov3640_write_reg(0x8BF8,0x94);
	ov3640_write_reg(0x8BF9,0x0A);
	ov3640_write_reg(0x8BFA,0x40);
	ov3640_write_reg(0x8BFB,0xCC);
	ov3640_write_reg(0x8BFC,0xC3);
	ov3640_write_reg(0x8BFD,0x22);
	ov3640_write_reg(0x8BFE,0x12);
	ov3640_write_reg(0x8BFF,0x0A);
	ov3640_write_reg(0x8C00,0x06);
	ov3640_write_reg(0x8C01,0x12);
	ov3640_write_reg(0x8C02,0x0A);
	ov3640_write_reg(0x8C03,0xE3);
	ov3640_write_reg(0x8C04,0x12);
	ov3640_write_reg(0x8C05,0x06);
	ov3640_write_reg(0x8C06,0xD6);
	ov3640_write_reg(0x8C07,0x12);
	ov3640_write_reg(0x8C08,0x02);
	ov3640_write_reg(0x8C09,0x45);
	ov3640_write_reg(0x8C0A,0x30);
	ov3640_write_reg(0x8C0B,0x09);
	ov3640_write_reg(0x8C0C,0xFA);
	ov3640_write_reg(0x8C0D,0xE5);
	ov3640_write_reg(0x8C0E,0x40);
	ov3640_write_reg(0x8C0F,0x54);
	ov3640_write_reg(0x8C10,0x03);
	ov3640_write_reg(0x8C11,0xFF);
	ov3640_write_reg(0x8C12,0xBF);
	ov3640_write_reg(0x8C13,0x01);
	ov3640_write_reg(0x8C14,0x05);
	ov3640_write_reg(0x8C15,0x12);
	ov3640_write_reg(0x8C16,0x00);
	ov3640_write_reg(0x8C17,0x06);
	ov3640_write_reg(0x8C18,0x80);
	ov3640_write_reg(0x8C19,0x18);
	ov3640_write_reg(0x8C1A,0xE5);
	ov3640_write_reg(0x8C1B,0x40);
	ov3640_write_reg(0x8C1C,0x64);
	ov3640_write_reg(0x8C1D,0x4A);
	ov3640_write_reg(0x8C1E,0x60);
	ov3640_write_reg(0x8C1F,0x05);
	ov3640_write_reg(0x8C20,0xE5);
	ov3640_write_reg(0x8C21,0x40);
	ov3640_write_reg(0x8C22,0xB4);
	ov3640_write_reg(0x8C23,0xCA);
	ov3640_write_reg(0x8C24,0x05);
	ov3640_write_reg(0x8C25,0x12);
	ov3640_write_reg(0x8C26,0x09);
	ov3640_write_reg(0x8C27,0x0C);
	ov3640_write_reg(0x8C28,0x80);
	ov3640_write_reg(0x8C29,0x08);
	ov3640_write_reg(0x8C2A,0xE5);
	ov3640_write_reg(0x8C2B,0x40);
	ov3640_write_reg(0x8C2C,0xB4);
	ov3640_write_reg(0x8C2D,0x4E);
	ov3640_write_reg(0x8C2E,0x03);
	ov3640_write_reg(0x8C2F,0x12);
	ov3640_write_reg(0x8C30,0x04);
	ov3640_write_reg(0x8C31,0x97);
	ov3640_write_reg(0x8C32,0xC2);
	ov3640_write_reg(0x8C33,0x09);
	ov3640_write_reg(0x8C34,0x80);
	ov3640_write_reg(0x8C35,0xD1);
	ov3640_write_reg(0x8C36,0xEF);
	ov3640_write_reg(0x8C37,0x8D);
	ov3640_write_reg(0x8C38,0xF0);
	ov3640_write_reg(0x8C39,0xA4);
	ov3640_write_reg(0x8C3A,0xA8);
	ov3640_write_reg(0x8C3B,0xF0);
	ov3640_write_reg(0x8C3C,0xCF);
	ov3640_write_reg(0x8C3D,0x8C);
	ov3640_write_reg(0x8C3E,0xF0);
	ov3640_write_reg(0x8C3F,0xA4);
	ov3640_write_reg(0x8C40,0x28);
	ov3640_write_reg(0x8C41,0xCE);
	ov3640_write_reg(0x8C42,0x8D);
	ov3640_write_reg(0x8C43,0xF0);
	ov3640_write_reg(0x8C44,0xA4);
	ov3640_write_reg(0x8C45,0x2E);
	ov3640_write_reg(0x8C46,0xFE);
	ov3640_write_reg(0x8C47,0x22);
	ov3640_write_reg(0x8C48,0xD0);
	ov3640_write_reg(0x8C49,0x83);
	ov3640_write_reg(0x8C4A,0xD0);
	ov3640_write_reg(0x8C4B,0x82);
	ov3640_write_reg(0x8C4C,0xF8);
	ov3640_write_reg(0x8C4D,0xE4);
	ov3640_write_reg(0x8C4E,0x93);
	ov3640_write_reg(0x8C4F,0x70);
	ov3640_write_reg(0x8C50,0x12);
	ov3640_write_reg(0x8C51,0x74);
	ov3640_write_reg(0x8C52,0x01);
	ov3640_write_reg(0x8C53,0x93);
	ov3640_write_reg(0x8C54,0x70);
	ov3640_write_reg(0x8C55,0x0D);
	ov3640_write_reg(0x8C56,0xA3);
	ov3640_write_reg(0x8C57,0xA3);
	ov3640_write_reg(0x8C58,0x93);
	ov3640_write_reg(0x8C59,0xF8);
	ov3640_write_reg(0x8C5A,0x74);
	ov3640_write_reg(0x8C5B,0x01);
	ov3640_write_reg(0x8C5C,0x93);
	ov3640_write_reg(0x8C5D,0xF5);
	ov3640_write_reg(0x8C5E,0x82);
	ov3640_write_reg(0x8C5F,0x88);
	ov3640_write_reg(0x8C60,0x83);
	ov3640_write_reg(0x8C61,0xE4);
	ov3640_write_reg(0x8C62,0x73);
	ov3640_write_reg(0x8C63,0x74);
	ov3640_write_reg(0x8C64,0x02);
	ov3640_write_reg(0x8C65,0x93);
	ov3640_write_reg(0x8C66,0x68);
	ov3640_write_reg(0x8C67,0x60);
	ov3640_write_reg(0x8C68,0xEF);
	ov3640_write_reg(0x8C69,0xA3);
	ov3640_write_reg(0x8C6A,0xA3);
	ov3640_write_reg(0x8C6B,0xA3);
	ov3640_write_reg(0x8C6C,0x80);
	ov3640_write_reg(0x8C6D,0xDF);
	ov3640_write_reg(0x8C6E,0xC2);
	ov3640_write_reg(0x8C6F,0xAF);
	ov3640_write_reg(0x8C70,0xD2);
	ov3640_write_reg(0x8C71,0x01);
	ov3640_write_reg(0x8C72,0xD2);
	ov3640_write_reg(0x8C73,0x00);
	ov3640_write_reg(0x8C74,0x90);
	ov3640_write_reg(0x8C75,0x30);
	ov3640_write_reg(0x8C76,0xB4);
	ov3640_write_reg(0x8C77,0xE5);
	ov3640_write_reg(0x8C78,0x20);
	ov3640_write_reg(0x8C79,0xF0);
	ov3640_write_reg(0x8C7A,0x7F);
	ov3640_write_reg(0x8C7B,0x0A);
	ov3640_write_reg(0x8C7C,0xAE);
	ov3640_write_reg(0x8C7D,0x07);
	ov3640_write_reg(0x8C7E,0x1F);
	ov3640_write_reg(0x8C7F,0xEE);
	ov3640_write_reg(0x8C80,0x70);
	ov3640_write_reg(0x8C81,0xFA);
	ov3640_write_reg(0x8C82,0xC2);
	ov3640_write_reg(0x8C83,0x01);
	ov3640_write_reg(0x8C84,0x90);
	ov3640_write_reg(0x8C85,0x30);
	ov3640_write_reg(0x8C86,0xB4);
	ov3640_write_reg(0x8C87,0xE5);
	ov3640_write_reg(0x8C88,0x20);
	ov3640_write_reg(0x8C89,0xF0);
	ov3640_write_reg(0x8C8A,0x7F);
	ov3640_write_reg(0x8C8B,0x05);
	ov3640_write_reg(0x8C8C,0xAE);
	ov3640_write_reg(0x8C8D,0x07);
	ov3640_write_reg(0x8C8E,0x1F);
	ov3640_write_reg(0x8C8F,0xEE);
	ov3640_write_reg(0x8C90,0x70);
	ov3640_write_reg(0x8C91,0xFA);
	ov3640_write_reg(0x8C92,0xC2);
	ov3640_write_reg(0x8C93,0x00);
	ov3640_write_reg(0x8C94,0x90);
	ov3640_write_reg(0x8C95,0x30);
	ov3640_write_reg(0x8C96,0xB4);
	ov3640_write_reg(0x8C97,0xE5);
	ov3640_write_reg(0x8C98,0x20);
	ov3640_write_reg(0x8C99,0xF0);
	ov3640_write_reg(0x8C9A,0x7F);
	ov3640_write_reg(0x8C9B,0x05);
	ov3640_write_reg(0x8C9C,0xAE);
	ov3640_write_reg(0x8C9D,0x07);
	ov3640_write_reg(0x8C9E,0x1F);
	ov3640_write_reg(0x8C9F,0xEE);
	ov3640_write_reg(0x8CA0,0x70);
	ov3640_write_reg(0x8CA1,0xFA);
	ov3640_write_reg(0x8CA2,0x22);
	ov3640_write_reg(0x8CA3,0xC2);
	ov3640_write_reg(0x8CA4,0x01);
	ov3640_write_reg(0x8CA5,0x90);
	ov3640_write_reg(0x8CA6,0x30);
	ov3640_write_reg(0x8CA7,0xB4);
	ov3640_write_reg(0x8CA8,0xE5);
	ov3640_write_reg(0x8CA9,0x20);
	ov3640_write_reg(0x8CAA,0xF0);
	ov3640_write_reg(0x8CAB,0x7F);
	ov3640_write_reg(0x8CAC,0x05);
	ov3640_write_reg(0x8CAD,0xAE);
	ov3640_write_reg(0x8CAE,0x07);
	ov3640_write_reg(0x8CAF,0x1F);
	ov3640_write_reg(0x8CB0,0xEE);
	ov3640_write_reg(0x8CB1,0x70);
	ov3640_write_reg(0x8CB2,0xFA);
	ov3640_write_reg(0x8CB3,0xD2);
	ov3640_write_reg(0x8CB4,0x00);
	ov3640_write_reg(0x8CB5,0x90);
	ov3640_write_reg(0x8CB6,0x30);
	ov3640_write_reg(0x8CB7,0xB4);
	ov3640_write_reg(0x8CB8,0xE5);
	ov3640_write_reg(0x8CB9,0x20);
	ov3640_write_reg(0x8CBA,0xF0);
	ov3640_write_reg(0x8CBB,0x7F);
	ov3640_write_reg(0x8CBC,0x05);
	ov3640_write_reg(0x8CBD,0xAE);
	ov3640_write_reg(0x8CBE,0x07);
	ov3640_write_reg(0x8CBF,0x1F);
	ov3640_write_reg(0x8CC0,0xEE);
	ov3640_write_reg(0x8CC1,0x70);
	ov3640_write_reg(0x8CC2,0xFA);
	ov3640_write_reg(0x8CC3,0xD2);
	ov3640_write_reg(0x8CC4,0x01);
	ov3640_write_reg(0x8CC5,0x90);
	ov3640_write_reg(0x8CC6,0x30);
	ov3640_write_reg(0x8CC7,0xB4);
	ov3640_write_reg(0x8CC8,0xE5);
	ov3640_write_reg(0x8CC9,0x20);
	ov3640_write_reg(0x8CCA,0xF0);
	ov3640_write_reg(0x8CCB,0xD2);
	ov3640_write_reg(0x8CCC,0xAF);
	ov3640_write_reg(0x8CCD,0x7F);
	ov3640_write_reg(0x8CCE,0x05);
	ov3640_write_reg(0x8CCF,0xAE);
	ov3640_write_reg(0x8CD0,0x07);
	ov3640_write_reg(0x8CD1,0x1F);
	ov3640_write_reg(0x8CD2,0xEE);
	ov3640_write_reg(0x8CD3,0x70);
	ov3640_write_reg(0x8CD4,0xFA);
	ov3640_write_reg(0x8CD5,0x22);
	ov3640_write_reg(0x8CD6,0x90);
	ov3640_write_reg(0x8CD7,0x30);
	ov3640_write_reg(0x8CD8,0xB2);
	ov3640_write_reg(0x8CD9,0xE0);
	ov3640_write_reg(0x8CDA,0x44);
	ov3640_write_reg(0x8CDB,0x18);
	ov3640_write_reg(0x8CDC,0xF0);
	ov3640_write_reg(0x8CDD,0x90);
	ov3640_write_reg(0x8CDE,0x30);
	ov3640_write_reg(0x8CDF,0xB0);
	ov3640_write_reg(0x8CE0,0xE0);
	ov3640_write_reg(0x8CE1,0x44);
	ov3640_write_reg(0x8CE2,0x03);
	ov3640_write_reg(0x8CE3,0xF0);
	ov3640_write_reg(0x8CE4,0xA3);
	ov3640_write_reg(0x8CE5,0xE0);
	ov3640_write_reg(0x8CE6,0x44);
	ov3640_write_reg(0x8CE7,0xC0);
	ov3640_write_reg(0x8CE8,0xF0);
	ov3640_write_reg(0x8CE9,0x90);
	ov3640_write_reg(0x8CEA,0x30);
	ov3640_write_reg(0x8CEB,0xB4);
	ov3640_write_reg(0x8CEC,0xE0);
	ov3640_write_reg(0x8CED,0x44);
	ov3640_write_reg(0x8CEE,0x0F);
	ov3640_write_reg(0x8CEF,0xF0);
	ov3640_write_reg(0x8CF0,0xE0);
	ov3640_write_reg(0x8CF1,0x54);
	ov3640_write_reg(0x8CF2,0xF7);
	ov3640_write_reg(0x8CF3,0xF0);
	ov3640_write_reg(0x8CF4,0xE0);
	ov3640_write_reg(0x8CF5,0x44);
	ov3640_write_reg(0x8CF6,0x04);
	ov3640_write_reg(0x8CF7,0xF0);
	ov3640_write_reg(0x8CF8,0x22);
	ov3640_write_reg(0x8CF9,0xE4);
	ov3640_write_reg(0x8CFA,0xFF);
	ov3640_write_reg(0x8CFB,0xEF);
	ov3640_write_reg(0x8CFC,0xC3);
	ov3640_write_reg(0x8CFD,0x95);
	ov3640_write_reg(0x8CFE,0x13);
	ov3640_write_reg(0x8CFF,0x50);
	ov3640_write_reg(0x8D00,0x11);
	ov3640_write_reg(0x8D01,0x7D);
	ov3640_write_reg(0x8D02,0x82);
	ov3640_write_reg(0x8D03,0x7C);
	ov3640_write_reg(0x8D04,0x00);
	ov3640_write_reg(0x8D05,0xED);
	ov3640_write_reg(0x8D06,0x1D);
	ov3640_write_reg(0x8D07,0xAA);
	ov3640_write_reg(0x8D08,0x04);
	ov3640_write_reg(0x8D09,0x70);
	ov3640_write_reg(0x8D0A,0x01);
	ov3640_write_reg(0x8D0B,0x1C);
	ov3640_write_reg(0x8D0C,0x4A);
	ov3640_write_reg(0x8D0D,0x70);
	ov3640_write_reg(0x8D0E,0xF6);
	ov3640_write_reg(0x8D0F,0x0F);
	ov3640_write_reg(0x8D10,0x80);
	ov3640_write_reg(0x8D11,0xE9);
	ov3640_write_reg(0x8D12,0x22);
	ov3640_write_reg(0x8D13,0x30);
	ov3640_write_reg(0x8D14,0x08);
	ov3640_write_reg(0x8D15,0x10);
	ov3640_write_reg(0x8D16,0xE5);
	ov3640_write_reg(0x8D17,0x0E);
	ov3640_write_reg(0x8D18,0x90);
	ov3640_write_reg(0x8D19,0x33);
	ov3640_write_reg(0x8D1A,0x00);
	ov3640_write_reg(0x8D1B,0x60);
	ov3640_write_reg(0x8D1C,0x05);
	ov3640_write_reg(0x8D1D,0xE0);
	ov3640_write_reg(0x8D1E,0x44);
	ov3640_write_reg(0x8D1F,0x40);
	ov3640_write_reg(0x8D20,0xF0);
	ov3640_write_reg(0x8D21,0x22);
	ov3640_write_reg(0x8D22,0xE0);
	ov3640_write_reg(0x8D23,0x54);
	ov3640_write_reg(0x8D24,0xBF);
	ov3640_write_reg(0x8D25,0xF0);
	ov3640_write_reg(0x8D26,0x22);
	ov3640_write_reg(0x8D27,0xC3);
	ov3640_write_reg(0x8D28,0xEE);
	ov3640_write_reg(0x8D29,0x64);
	ov3640_write_reg(0x8D2A,0x80);
	ov3640_write_reg(0x8D2B,0x94);
	ov3640_write_reg(0x8D2C,0x80);
	ov3640_write_reg(0x8D2D,0x40);
	ov3640_write_reg(0x8D2E,0x02);
	ov3640_write_reg(0x8D2F,0x80);
	ov3640_write_reg(0x8D30,0x07);
	ov3640_write_reg(0x8D31,0xC3);
	ov3640_write_reg(0x8D32,0xE4);
	ov3640_write_reg(0x8D33,0x9F);
	ov3640_write_reg(0x8D34,0xFF);
	ov3640_write_reg(0x8D35,0xE4);
	ov3640_write_reg(0x8D36,0x9E);
	ov3640_write_reg(0x8D37,0xFE);
	ov3640_write_reg(0x8D38,0x22);
	ov3640_write_reg(0x8D39,0x01);
	ov3640_write_reg(0x8D3A,0x50);
	ov3640_write_reg(0x8D3B,0x00);
	ov3640_write_reg(0x8D3C,0x01);
	ov3640_write_reg(0x8D3D,0x24);
	ov3640_write_reg(0x8D3E,0x00);
	ov3640_write_reg(0x8D3F,0x01);
	ov3640_write_reg(0x8D40,0x31);
	ov3640_write_reg(0x8D41,0x00);
	ov3640_write_reg(0x8D42,0x01);
	ov3640_write_reg(0x8D43,0x32);
	ov3640_write_reg(0x8D44,0x00);
	ov3640_write_reg(0x8D45,0x02);
	ov3640_write_reg(0x8D46,0x33);
	ov3640_write_reg(0x8D47,0x00);
	ov3640_write_reg(0x8D48,0x00);
	ov3640_write_reg(0x8D49,0x00);
	ov3640_write_reg(0x8D4A,0x90);
	ov3640_write_reg(0x8D4B,0x30);
	ov3640_write_reg(0x8D4C,0x1B);
	ov3640_write_reg(0x8D4D,0xE0);
	ov3640_write_reg(0x8D4E,0xFF);
	ov3640_write_reg(0x8D4F,0x65);
	ov3640_write_reg(0x8D50,0x50);
	ov3640_write_reg(0x8D51,0x60);
	ov3640_write_reg(0x8D52,0x04);
	ov3640_write_reg(0x8D53,0x8F);
	ov3640_write_reg(0x8D54,0x50);
	ov3640_write_reg(0x8D55,0xD3);
	ov3640_write_reg(0x8D56,0x22);
	ov3640_write_reg(0x8D57,0xC3);
	ov3640_write_reg(0x8D58,0x22);
	ov3640_write_reg(0x3104,0x00);

	return SUCCESS;
}
/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	: 
 *  Name	:	ov3640_frame_interval_support
 *  Parameter1	:	cam_data *cam	- Base address of camera structure pointer 
 *  Returns	:	int		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative value be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *
 *  Description	: 	Control the frame rate based on the user request 
 *  Comments	:  	
 ************************************************************************************************************/
int ov3640_frame_interval_support(cam_data *cam)
{
	switch(cam->cam_sensor.cmd_to_sensor)
	{
		case GET_DATA_FRM_SENSOR:
		{
			unsigned int frame_interval_based_on_mode	= DISABLE;
			unsigned int usr_width	= cam->cam_sensor.frame_interval_frm_user->width;
			unsigned int usr_height	= cam->cam_sensor.frame_interval_frm_user->height;
			unsigned int pixel_format	= cam->cam_sensor.frame_interval_frm_user->pixel_format;

			for(	frame_interval_based_on_mode	= DISABLE	;				\
				frame_interval_based_on_mode	< cam->cam_sensor.total_frm_interval_support;	\
				frame_interval_based_on_mode++)
			{
				if(	(usr_width <= cam->cam_sensor						\
						.frm_interval_support[frame_interval_based_on_mode].width)	&&
					(usr_height <= cam->cam_sensor						\
						.frm_interval_support[frame_interval_based_on_mode].height))
				{
					break;
				}
			}

			if(frame_interval_based_on_mode	>=cam->cam_sensor.total_frm_interval_support)
			{
				TRACE_ERR_AND_RET(-EINVAL);
			}

			memcpy(	cam->cam_sensor.frame_interval_frm_user,					\
				&cam->cam_sensor.frm_interval_support[frame_interval_based_on_mode],		\
				sizeof(struct v4l2_frmivalenum));
			cam->cam_sensor.frame_interval_frm_user->width		= usr_width;
			cam->cam_sensor.frame_interval_frm_user->height		= usr_height;
			cam->cam_sensor.frame_interval_frm_user->pixel_format	= pixel_format;
		}break;

		case SET_DATA_TO_SENSOR:
		{
		}break;

		case QUERY_DATA_FRM_SENSOR:
		{
		}break;
	}
	return SUCCESS;
}

/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	: 
 *  Name	:	ov3640_format_support
 *  Parameter1	:	cam_data *cam	- Base address of camera structure pointer 
 *  Returns	:	int		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative value be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *
 *  Description	: 	Control the frame rate based on the user request 
 *  Comments	:  	
 ************************************************************************************************************/

int ov3640_format_support(cam_data *cam)
{
	unsigned int pix_fmt_count	= DISABLE;
	switch(cam->cam_sensor.cmd_to_sensor)
	{
		case GET_DATA_FRM_SENSOR:
		{
			unsigned int pixel_format	= cam->cam_sensor.fmt_frm_user->pixel_format;
			if(cam->cam_sensor.fmt_frm_user->index	>= cam->cam_sensor.total_frms_support)
			{
				TRACE_ERR_AND_RET(-EINVAL);
			}

			for(	pix_fmt_count	= DISABLE;					\
				pix_fmt_count < cam->cam_sensor.total_frms_support;		\
				pix_fmt_count++)
			{
				if(cam->cam_sensor.fmt_frm_user->pixel_format == 		\
						cam->cam_sensor.formats[pix_fmt_count].pixelformat)
				{
					break;
				}
			}

			/*
			 * Check for pixel format support. If the pixel format is not
			 * supported! return the format is error value as Invalid data
			 */

			if(pix_fmt_count	>= (cam->cam_sensor.total_frms_support))
			{

				TRACE_ERR_AND_RET(-EINVAL);
			}

			memcpy(	cam->cam_sensor.fmt_frm_user,					\
				&cam->cam_sensor.frms[cam->cam_sensor.fmt_frm_user->index],	\
				sizeof(struct v4l2_frmsizeenum));
			cam->cam_sensor.fmt_frm_user->pixel_format	= pixel_format;
		}break;

		case SET_DATA_TO_SENSOR:
		{
		}break;

		case QUERY_DATA_FRM_SENSOR:
		{
		}break;
	}
	return SUCCESS;
}

/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	: 
 *  Name	:	ov3640_frame_rate_ctrl
 *  Parameter1	:	cam_data *cam	- Base address of camera structure pointer 
 *  Returns	:	int		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative value be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *
 *  Description	: 	Control the frame rate based on the user request 
 *  Comments	:  	
 ************************************************************************************************************/

int ov3640_frame_rate_ctrl(cam_data *cam)
{

	/*
	 * Sensor Will take mclk from input ranges from 6Mhz t0 27 Mhz (V3640_COB_USA.pdf)
	 */
#if 0
	unsigned int clk_set		= DISABLE;
#endif
	UINT8 regval_3011	= DISABLE;
	unsigned int fps		= DISABLE;
	unsigned int fps_need		= DISABLE;

	if(cam->cam_sensor.s_parm.type	!= V4L2_BUF_TYPE_VIDEO_CAPTURE)
	{
		TRACE_ERR_AND_RET(-EINVAL);
	}

	ov3640_read_reg(0x3011,&regval_3011);

	switch(cam->cam_sensor.cmd_to_sensor)
	{
		case GET_DATA_FRM_SENSOR:
		{
			if(	(cam->cam_sensor.fmt.fmt.pix.width < MODE_XGA_WIDTH) && 	\
			(cam->cam_sensor.fmt.fmt.pix.height < MODE_XGA_HEIGHT))
			{
				fps		= 30 / (regval_3011 +1);
			}else
			{
				fps		= 7 / (regval_3011 +1);
			}
			cam->cam_sensor.s_parm.parm.capture.timeperframe.denominator	= fps;
			cam->cam_sensor.s_parm.parm.capture.timeperframe.numerator	= 1;
		}break;

		case SET_DATA_TO_SENSOR:
		{
			if(	(cam->cam_sensor.fmt.fmt.pix.width < MODE_XGA_WIDTH) && 	\
			(cam->cam_sensor.fmt.fmt.pix.height < MODE_XGA_HEIGHT))
			{
				fps		= 30 / (regval_3011 +1);
				fps_need	= (cam->cam_sensor.s_parm.parm.capture.timeperframe.denominator/	\
						cam->cam_sensor.s_parm.parm.capture.timeperframe.numerator);

				if(fps_need	 > 30)
				{
					fps_need	= 30;
				}	
				regval_3011	= (30 / fps_need) -1;
			}else
			{
				fps		= 7 / (regval_3011 +1);
				fps_need	= (cam->cam_sensor.s_parm.parm.capture.timeperframe.denominator/	\
							cam->cam_sensor.s_parm.parm.capture.timeperframe.numerator);
				if(fps_need	 > 7)
				{
					fps_need	= 7;
				}
				regval_3011	= (7 / fps_need) -1;
			}

			ov3640_write_reg(0x3011,regval_3011);
		}break;

		case QUERY_DATA_FRM_SENSOR:
		{
		}break;
	}
/*
 * TODO :
 * 	Fine tune the Mclk to acheive more accurate frame rate from the sensor
 */

#if 0
	if(cam->modify_mclk_to_sensor)
	{
		ret_val	= cam->modify_mclk_to_sensor(cam,xclk,&clk_set);
		if(CHECK_IN_FAIL_LIMIT(ret_val))
		{
			TRACE_ERR_AND_RET(FAIL);		
		}
	}
#endif

	return SUCCESS;
}
/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	: SENS_OV3640_15
 *  Name	:	ov3640_sens_strobe
 *  Parameter1	:	cam_data *cam	- Base address of camera structure pointer 
 *  Returns	:	int		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative value be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *
 *  Description	: 	External flash light strobe signal control be enabled (or) disabled here 
 *  Comments	:  	
 ************************************************************************************************************/
int ov3640_sens_strobe(cam_data *cam)
{
	if((cam->ctrl.value) && (cam->cam_sensor.sens_strobe_en))
	{
		ov3640_write_reg(0x307A ,0x8F);	
	}else
	{
		ov3640_write_reg(0x307A ,0x0F);	
	}

	return SUCCESS;
}

/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	: SENS_OV3640_16
 *  Name	:	ov3640_focus
 *  Parameter1	:	cam_data *cam	- Base address of camera structure pointer 
 *  
 *  Returns	:	int		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative value be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *
 *  Description	: 	Autofocus related feature available here
 *  Comments	:  	Ov3640 truly module firmware supports
 *  			1. Manual focus
 *  			2. Absolute focus
 *  			3. Relative focus
 *  			4. Automatic continous focus
 *  			5. Single Auto focus
 ************************************************************************************************************/
int ov3640_focus(cam_data *cam)
{
	af_status reg_data;
	UINT8 reg_value;
	switch(cam->cam_sensor.cmd_to_sensor)
	{
		case GET_DATA_FRM_SENSOR:
		{
			switch(cam->ctrl.id)
			{
				case V4L2_CID_FOCUS_ABSOLUTE:
				case V4L2_CID_FOCUS_RELATIVE:
				{
					ov3640_read_reg(0x3f01,&reg_data.reg_data);
					if(reg_data.focus.mode != MODE_STEP_MODE)
					{
						TRACE_ERR_AND_RET(FAIL);
					}
					ov3640_read_reg(0x3f05,&reg_value);				
					cam->ctrl.value	= (0x03 & reg_value) << 8;

					ov3640_read_reg(0x3f06,&reg_value);
					cam->ctrl.value|= (0xFF & reg_value);
				}break;

				case V4L2_CID_FOCUS_AUTO:
				{
					ov3640_read_reg(0x3f01,&reg_data.reg_data);
					if(reg_data.focus.mode == MODE_CONTINOUS_FOCUS)
					{
						cam->ctrl.value = reg_data.focus.mode_step;
					}else
					{
						cam->ctrl.value = DISABLE;
					}
				}break;

				case V4L2_SENS_TRIG_FOCUS:
				{
					ov3640_read_reg(0x3f01,&reg_data.reg_data);
					if(reg_data.focus.mode == MODE_SINGLE_FOCUS)
					{
						cam->ctrl.value = reg_data.focus.mode_step;
					}else
					{
						cam->ctrl.value = DISABLE;
					}
				}break;
				default:
				{
					TRACE_ERR_AND_RET(-EINVAL);	
				}	
			}		
		}break;

		case SET_DATA_TO_SENSOR:
		{
			ov3640_write_reg(0x3f00,0x09);

			switch(cam->ctrl.id)
			{
				case V4L2_CID_FOCUS_ABSOLUTE:
				{
					ov3640_read_reg(0x3f01,&reg_data.reg_data);
					if(reg_data.focus.mode != MODE_STEP_MODE)
					{
						ov3640_write_reg(0x3f00,0x08);
						ov3640_write_reg(0x3f00,0x05);
					}
					ov3640_write_reg(0x3f05,STEP_ABSOLUTE | (0x3 & ((cam->ctrl.value) >> 8)));
					ov3640_write_reg(0x3f06,(0xFF & cam->ctrl.value));
				}break;

				case V4L2_CID_FOCUS_RELATIVE:
				{
					ov3640_read_reg(0x3f01,&reg_data.reg_data);
					if(reg_data.focus.mode != MODE_STEP_MODE)
					{
						ov3640_write_reg(0x3f00,0x08);
						ov3640_write_reg(0x3f00,0x05);
					}
					if(cam->ctrl.value > 0)
					{
						ov3640_write_reg(0x3f05,STEP_FORWARD | (0x3 & ((cam->ctrl.value) >> 8)));
						ov3640_write_reg(0x3f06,(0xFF & cam->ctrl.value));
					}else
					{
						cam->ctrl.value = -cam->ctrl.value;
						ov3640_write_reg(0x3f05,STEP_BACKWARD | (0x3 & ((cam->ctrl.value) >> 8)));
						ov3640_write_reg(0x3f06,(0xFF & cam->ctrl.value));
					}	
				}break;
				case V4L2_CID_FOCUS_AUTO:
				{
					ov3640_write_reg(0x3f00,0x08);
					ov3640_write_reg(0x3f00,0x04);
				}break;
				case V4L2_SENS_TRIG_FOCUS:
				{
					ov3640_write_reg(0x3f00,0x08);
					ov3640_write_reg(0x3f00,0x03);
				}break;
		
				case V4L2_SENS_FCS_OLAY:
				{
					if(cam->ctrl.value)
					{
						ov3640_write_reg(0x3f00,0x01);
					}else
					{
						ov3640_write_reg(0x3f00,0x02);
					}

				}break;
			
				case V4L2_SENS_FOCUS_DISABLE:
				{
					ov3640_write_reg(0x3f00,0x08);					
				}break;			
			}		
		}break;

		case QUERY_DATA_FRM_SENSOR:
		{
			switch(cam->ctrl.id)
			{
				case V4L2_CID_FOCUS_ABSOLUTE:
				{
					cam->cam_sensor.qctrl.id	= V4L2_CID_FOCUS_ABSOLUTE;
					cam->cam_sensor.qctrl.type	= V4L2_CTRL_TYPE_INTEGER;
					strncpy(cam->cam_sensor.qctrl.name,"Manual focus",strlen("Manual focus"));
					cam->cam_sensor.qctrl.minimum = 0;
					cam->cam_sensor.qctrl.maximum = 1023;
					cam->cam_sensor.qctrl.step = 1;
					cam->cam_sensor.qctrl.default_value = 0;
					cam->cam_sensor.qctrl.flags = V4L2_CTRL_FLAG_SLIDER;
				}break;

				case V4L2_CID_FOCUS_RELATIVE:
				{
					cam->cam_sensor.qctrl.id	= V4L2_CID_FOCUS_RELATIVE;
					cam->cam_sensor.qctrl.type	= V4L2_CTRL_TYPE_INTEGER;
					strncpy(cam->cam_sensor.qctrl.name,"Relative Manual focus",	\
							strlen("Relative Manual focus"));
					cam->cam_sensor.qctrl.minimum = -1023;
					cam->cam_sensor.qctrl.maximum = 1023;
					cam->cam_sensor.qctrl.step = 1;
					cam->cam_sensor.qctrl.default_value = 0;
					cam->cam_sensor.qctrl.flags = V4L2_CTRL_FLAG_SLIDER;
				}break;

				case V4L2_CID_FOCUS_AUTO:
				{
					cam->cam_sensor.qctrl.id	= V4L2_CID_FOCUS_AUTO;
					cam->cam_sensor.qctrl.type	= V4L2_CTRL_TYPE_BOOLEAN;
					strncpy(cam->cam_sensor.qctrl.name,"Autofocus",strlen("Autofocus"));
					cam->cam_sensor.qctrl.minimum = 0;
					cam->cam_sensor.qctrl.maximum = 1;
					cam->cam_sensor.qctrl.step = 1;
					cam->cam_sensor.qctrl.default_value = 0;
				}break;

				case V4L2_SENS_TRIG_FOCUS:
				{
					cam->cam_sensor.qctrl.id	= V4L2_SENS_TRIG_FOCUS;
					cam->cam_sensor.qctrl.type	= V4L2_CTRL_TYPE_BOOLEAN;
					strncpy(cam->cam_sensor.qctrl.name,"Single Auto focus",	\
							strlen("Single Auto focus"));
					cam->cam_sensor.qctrl.minimum = 0;
					cam->cam_sensor.qctrl.maximum = 1;
					cam->cam_sensor.qctrl.step = 1;
					cam->cam_sensor.qctrl.default_value = 0;
				}break;

				case V4L2_SENS_FCS_OLAY:
				{
					cam->cam_sensor.qctrl.id	= V4L2_SENS_FCS_OLAY;
					cam->cam_sensor.qctrl.type	= V4L2_CTRL_TYPE_BOOLEAN;
					strncpy(cam->cam_sensor.qctrl.name,"Focus Overlay",strlen("Focus Overlay"));
					cam->cam_sensor.qctrl.minimum = 0;
					cam->cam_sensor.qctrl.maximum = 1;
					cam->cam_sensor.qctrl.step = 1;
					cam->cam_sensor.qctrl.default_value = 0;
				}break;

				case V4L2_SENS_FOCUS_DISABLE:
				{
					cam->cam_sensor.qctrl.id	= V4L2_SENS_FOCUS_DISABLE;
					cam->cam_sensor.qctrl.type	= V4L2_CTRL_TYPE_BOOLEAN;
					strncpy(cam->cam_sensor.qctrl.name,"Focus complete",strlen("Focus complete"));
					cam->cam_sensor.qctrl.minimum = 0;
					cam->cam_sensor.qctrl.maximum = 1;
					cam->cam_sensor.qctrl.step = 1;
					cam->cam_sensor.qctrl.default_value = 0;
				}break;
			}			
		}break;

		default:
		{
			TRACE_ERR_AND_RET(-EINVAL);	
		}
	}
	return SUCCESS;
}
/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	: SENS_OV3640_17
 *  Name	:	ov3640_i2c_client_xfer
 *  Parameter1	:	INT32 addr	- Slave address (7-bit) address
 *  Parameter2	:	PINT8 reg	- Ov3640 Register address base address
 *  Parameter3	:	PINT8 buf	- Ov3640 Register data base address
 *  Parameter4	:	INT32 num	- Number of data need to read/write in i2c transation
 *  Parameter5	:	INT32 tran_flag	- 0- Write,1-read
 *
 *  Returns	:	int		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative value be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *
 *  Description	: 	Perform read/write data through i2c bus
 *  Comments	:  	
 ************************************************************************************************************/

int ov3640_i2c_client_xfer(	INT32 addr, PINT8 reg, PINT8 buf, INT32 num,	\
				INT32 tran_flag)
{
	struct i2c_msg msg[2];
	int ret_val;
	INT32 ret;
	cam_data *cam	= NULL;
	UINT8 reg_addr_data[3];

	ret_val	= v4l2_base_struct(&cam,GET_ADDRESS);
	if(CHECK_IN_FAIL_LIMIT(ret_val))
	{
		printk(KERN_ERR "Failed to get the camera base pointer \n");
		TRACE_ERR_AND_RET(FAIL);		
	}

	if(cam->cam_sensor.client == NULL)
	{
		TRACE_ERR_AND_RET(FAIL);		
	}
/*
 * FIXME:
 * 	
 * 	I2C Write:
 *	 	In i2c msg[0] "address part in write is success" but if we put data in msg [1] 
 * 		that is not properly sent to device.
 *
 * 		so in the msg[0] part itself the data also sent here.
 *
 * 	I2CRead:
 * 		But in read No problem is found and working fine
 */
	if(tran_flag & I2C_FLAG_READ)
	{
		msg[0].addr	= addr;
		msg[0].len	= 2;
		msg[0].buf	= reg;
		msg[0].flags	= tran_flag;
		msg[0].flags	&= ~I2C_M_RD;

		msg[1].addr	= addr;
		msg[1].len	= num;
		msg[1].buf	= buf;
		msg[1].flags	= tran_flag;

		if (tran_flag & I2C_FLAG_READ)
		{
			msg[1].flags |= I2C_M_RD;
		}else
		{
			msg[1].flags &= ~I2C_M_RD;
		}

		if (cam->cam_sensor.client->adapter == NULL)
		{
			printk("%s:adapter error\n", __func__);
			return -1;
		}

		ret = i2c_transfer(cam->cam_sensor.client->adapter, msg, 2);
		if (ret >= 0)
		{
			/* printk("%s:i2c transfer num:%d\n", __func__, ret); */
			return SUCCESS;
		}
	}else
	{
		reg_addr_data[0]	= reg[0];
		reg_addr_data[1]	= reg[1];
		reg_addr_data[2]	= buf[0];

		msg[0].addr	= addr;
		msg[0].len	= 3;
		msg[0].buf	= reg_addr_data;
		msg[0].flags	= tran_flag;
		msg[0].flags	&= ~I2C_M_RD;

		ret = i2c_transfer(cam->cam_sensor.client->adapter, msg, 1);
		if (ret >= 0)
		{
			/* printk("%s:i2c transfer num:%d\n", __func__, ret); */
			return SUCCESS;
		}
	}
	printk("%s:i2c transfer error:%d\n", __func__, ret);
	TRACE_ERR_AND_RET(FAIL);
}

/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	: SENS_OV3640_18	
 *  Name	:	ov3640_write_reg
 *  Parameter1	:	unsigned int reg_address	- Ov3640 register address
 *  Parameter2	:	UINT8 reg_data		- Ov3640 register data
 *  Returns	:	int		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative value be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *
 *  Description	: 	This function write the data in the mentioned register address of ov3640 	
 *  Comments	:  	
 ************************************************************************************************************/
int ov3640_write_reg(unsigned int reg_address, unsigned char reg_data)
{
	int i, ret_val;
	unsigned char reg_addr[2];
	unsigned char reg_data_aw;

	reg_addr[0] = 0xFF & (reg_address >> 8);
	reg_addr[1] = 0xFF & reg_address;
	
	for (i = 0; i < 3; i++) {
		ret_val	= ov3640_i2c_client_xfer(OV3640_I2C_ADDRESS, reg_addr, &reg_data, 1, 0);

		if (CHECK_IN_FAIL_LIMIT(ret_val))
			return I2C_WRITE_FAIL;

		udelay(100);

		/* don't know why these are special */
		if (reg_address == 0x3f00 || reg_address == 0x3012) {
			break;
		}

		/* else do a read check */
		ret_val	= ov3640_read_reg(reg_address, &reg_data_aw);
			
		if(CHECK_IN_FAIL_LIMIT(ret_val))
			return I2C_WRITE_FAIL;

		if (reg_data == reg_data_aw)
			break;
		
		udelay(100);
	}
	
	return i < 3 ? I2C_WRITE_SUCCESS : I2C_WRITE_FAIL;
}

/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	: SENS_OV3640_19	
 *  Name	:	ov3640_read_reg
 *  Parameter1	:	unsigned int reg_address	- Ov3640 register address
 *  Parameter2	:	unsigne char *reg_data		- Ov3640 register data
 *  Returns	:	int		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative value be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *
 *  Description	: 	This function read the data in the mentioned register address of ov3640
 *  Comments	:  	
 ************************************************************************************************************/
int ov3640_read_reg(unsigned int reg_address, unsigned char *reg_data)
{
	unsigned char reg_addr[2];

	reg_addr[0] = 0xFF & (reg_address >> 8);
	reg_addr[1] = 0xFF & reg_address;

	if (ov3640_i2c_client_xfer(OV3640_I2C_ADDRESS, reg_addr, reg_data, 1, 1) < 0) {
		printk("%s:read reg error: reg=%x, val=%x\n",__func__,
			reg_address, *reg_data);
		return -1;
	}

	printk(KERN_DEBUG "read : addr=%x, val=%x",reg_address, *reg_data);
	udelay(100);

	return I2C_WRITE_SUCCESS;
}

/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	:	
 *  Name	:	ov3640_probe
 *  Parameter1	:	struct i2c_client *client
 *  Parameter2	:	const struct i2c_device_id *id
 *  Returns	:	LINT32	- On sucess returns 0
 *  				- On Failure a negative number be returned
 *
 *  Description	: 	Configure the gpio levels for ov3640 driver
 *  Comments	:  	
 ************************************************************************************************************/
static INT32 __init ov3640_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
#define OV3640_RESET_GPIO	98
#define OV3640_STANDBY_GPIO	167

	cam_data *cam	= NULL;
	int ret_val;

	if (i2c_get_clientdata(client))
	{
		TRACE_ERR_AND_RET(FAIL);
	}

	ret_val	= v4l2_base_struct(&cam,GET_ADDRESS);
	if(CHECK_IN_FAIL_LIMIT(ret_val))
	{
		printk(KERN_ERR "Failed to register the camera device\n");
		goto exit;
	}
	
/*
 * 	set the client data 
 */
	cam->cam_sensor.client =	client;

/*
 * Make sure the mclk clock is enabled 
 */

/*
 * Configure the gpio levels
 */

	gpio_request(OV3640_RESET_GPIO,"ov3640");
	gpio_request(OV3640_STANDBY_GPIO,"ov3640");

	gpio_direction_output(OV3640_RESET_GPIO, true);
	gpio_direction_output(OV3640_STANDBY_GPIO, true);
	/* Turn ON Omnivision sensor */
	gpio_set_value(OV3640_RESET_GPIO, ENABLE);
	gpio_set_value(OV3640_STANDBY_GPIO, DISABLE);
	udelay(100);

	/* RESET Omnivision sensor */
	gpio_set_value(OV3640_RESET_GPIO, DISABLE);
	udelay(100);
	gpio_set_value(OV3640_RESET_GPIO, ENABLE);

/*
 *	TODO: Description for udelay(100)
 *	 We faced poweron time delay with ov5642 on 15APR2010.
 *	 So we hard coded 100 micro second delay on ov3640 also 
 *	 to be on the Safer side.
 *
 *	 But this can be done better (If reading the register failed then put the
 *	 delay and read again in the probing sequence only).
 */
	udelay(100);

	return SUCCESS;
	exit:
	{
		TRACE_ERR_AND_RET(-ENODEV);
	}	
}
/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	:	
 *  Name	:	ov3640_remove
 *  Parameter1	:	struct i2c_client *client
 *  Returns	:	LINT32	- On sucess returns 0
 *  				- On Failure a negative number be returned
 *
 *  Description	: 	remove routine of ov3640 i2c driver
 *  Comments	:  	
 ************************************************************************************************************/

static INT32 __exit ov3640_remove(struct i2c_client *client)
{
	if (!client->adapter)
	{
		/* our client isn't attached */
		TRACE_ERR_AND_RET(-ENODEV);
	}	

	i2c_set_clientdata(client, NULL);
	return SUCCESS;
}

/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	:	
 *  Name	:	ov3640_init	
 *  Parameter1	:	cam_data *cam	- Base address of camera structure pointer
 *  Returns	:	int		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative value be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *
 *  Description	: 	ov3640 init part of code done here
 *  Comments	:  	
 ************************************************************************************************************/

#define OV3640_DRIVER_NAME	"ov3640"
/*
 * i2c driver init
 */
	static const struct i2c_device_id ov3640_id[] =			\
	{
		{ OV3640_DRIVER_NAME, 0 },
		{ },
	};
	MODULE_DEVICE_TABLE(i2c_0, ov3640_id);

int ov3640_init(cam_data *cam)
{
	int  ret_val;
	unsigned int	index			= DISABLE;
	unsigned int	fmt_index		= DISABLE;
	unsigned int	frame_rate_index	= DISABLE;
	
	cam->cam_sensor.i2c_driver.driver.name	= OV3640_DRIVER_NAME;
	cam->cam_sensor.i2c_driver.driver.owner	= THIS_MODULE;
	cam->cam_sensor.i2c_driver.probe	= ov3640_probe;
	cam->cam_sensor.i2c_driver.remove	= __exit_p(ov3640_remove);
	cam->cam_sensor.i2c_driver.id_table	= ov3640_id;



	if(i2c_add_driver(&cam->cam_sensor.i2c_driver))
	{
		TRACE_ERR_AND_RET(FAIL);
	}

	if(cam->cam_sensor.find_device)
	{
		ret_val	= cam->cam_sensor.find_device(cam);
		if(CHECK_IN_FAIL_LIMIT(ret_val))
		{
			ov3640_exit(cam);
			TRACE_ERR_AND_RET(FAIL);
		}
	}

/*
 * init the sensor capability
 */
	

	cam->cam_sensor.formats[index].index		= index;
	memcpy(	cam->cam_sensor.formats[index].description,	\
		"RGB565",					\
		sizeof(cam->cam_sensor.formats[index].description));

	cam->cam_sensor.formats[index].pixelformat	= V4L2_PIX_FMT_RGB565;
	cam->cam_sensor.formats[index].type		= V4L2_BUF_TYPE_VIDEO_CAPTURE;
	index++;

	cam->cam_sensor.formats[index].index		= index;
	memcpy(	cam->cam_sensor.formats[index].description,	\
		"UYVY, packed",					\
		sizeof(cam->cam_sensor.formats[index].description));
	cam->cam_sensor.formats[index].pixelformat	= V4L2_PIX_FMT_UYVY;
	cam->cam_sensor.formats[index].type		= V4L2_BUF_TYPE_VIDEO_CAPTURE;
	index++;

	cam->cam_sensor.formats[index].index		= index;
	memcpy(	cam->cam_sensor.formats[index].description,	\
		"YUYV, packed",					\
		sizeof(cam->cam_sensor.formats[index].description));
	cam->cam_sensor.formats[index].pixelformat	= V4L2_PIX_FMT_YUYV;
	cam->cam_sensor.formats[index].type		= V4L2_BUF_TYPE_VIDEO_CAPTURE;
	index++;

	cam->cam_sensor.formats[index].index		= index;
	memcpy(	cam->cam_sensor.formats[index].description,	\
		"BA81, BGBG",					\
		sizeof(cam->cam_sensor.formats[index].description));
	cam->cam_sensor.formats[index].pixelformat	= V4L2_PIX_FMT_SBGGR8;
	cam->cam_sensor.formats[index].type		= V4L2_BUF_TYPE_VIDEO_CAPTURE;
	index++;

	cam->cam_sensor.formats[index].index		= index;
	memcpy(	cam->cam_sensor.formats[index].description,	\
		"YUV444, packed",					\
		sizeof(cam->cam_sensor.formats[index].description));
	cam->cam_sensor.formats[index].pixelformat	= V4L2_PIX_FMT_YUV444;
	cam->cam_sensor.formats[index].type		= V4L2_BUF_TYPE_VIDEO_CAPTURE;
	index++;

#if 0	
	cam->cam_sensor.formats[index].index		= index;
	memcpy(	cam->cam_sensor.formats[index].description,	\
		"YUV420, packed",					\
		sizeof(cam->cam_sensor.formats[index].description));
	cam->cam_sensor.formats[index].pixelformat	= V4L2_PIX_FMT_YUV420;
	cam->cam_sensor.formats[index].type		= V4L2_BUF_TYPE_VIDEO_CAPTURE;
	index++;
#endif

	cam->cam_sensor.formats[index].index		= index;
	memcpy(	cam->cam_sensor.formats[index].description,	\
		"RGB555",					\
		sizeof(cam->cam_sensor.formats[index].description));

	cam->cam_sensor.formats[index].pixelformat	= V4L2_PIX_FMT_RGB555;
	cam->cam_sensor.formats[index].type		= V4L2_BUF_TYPE_VIDEO_CAPTURE;
	index++;

	cam->cam_sensor.formats[index].index		= index;
	memcpy(	cam->cam_sensor.formats[index].description,	\
		"BGR888",					\
		sizeof(cam->cam_sensor.formats[index].description));

	cam->cam_sensor.formats[index].pixelformat	= V4L2_PIX_FMT_BGR32;
	cam->cam_sensor.formats[index].type		= V4L2_BUF_TYPE_VIDEO_CAPTURE;
	index++;

	cam->cam_sensor.totol_fmt_desc	= index;

/*
 * init the sensor capable formats
 */
	cam->cam_sensor.frms[fmt_index].index			= fmt_index;
//	cam->cam_sensor.frms[fmt_index].pixel_format		= All pixel formates supported;
	cam->cam_sensor.frms[fmt_index].type			= V4L2_FRMSIZE_TYPE_STEPWISE;

	cam->cam_sensor.frms[fmt_index].stepwise.min_width	= MIN_OV3640_WIDTH;
	cam->cam_sensor.frms[fmt_index].stepwise.max_width	= MAX_OV3640_WIDTH;//FRM_CRPT_OV3640_WIDTH;
	cam->cam_sensor.frms[fmt_index].stepwise.step_width	= 32;
	cam->cam_sensor.frms[fmt_index].stepwise.min_height	= MAX_OV3640_HEIGHT;//MIN_OV3640_HEIGHT;
	cam->cam_sensor.frms[fmt_index].stepwise.max_height	= FRM_CRPT_OV3640_HEIGHT;
	cam->cam_sensor.frms[fmt_index].stepwise.step_height	= 32;
	fmt_index++;

#if 0
	cam->cam_sensor.frms[fmt_index].index			= fmt_index;
//	cam->cam_sensor.frms[fmt_index].pixel_format		= All pixel formates supported;
	cam->cam_sensor.frms[fmt_index].type			= V4L2_FRMSIZE_TYPE_DISCRETE;

	cam->cam_sensor.frms[fmt_index].discrete.width		= MAX_OV3640_WIDTH;
	cam->cam_sensor.frms[fmt_index].discrete.height		= MAX_OV3640_HEIGHT;
	fmt_index++;
#endif
	cam->cam_sensor.total_frms_support	= fmt_index;

/*
 * initialize the frame interval capability of the sensor
 */
	cam->cam_sensor.frm_interval_support[frame_rate_index].index			= frame_rate_index;
//	cam->cam_sensor.frm_interval_support[frame_rate_index].pixel_format		= Support all formats;
	cam->cam_sensor.frm_interval_support[frame_rate_index].width			= MODE_XGA_WIDTH;
	cam->cam_sensor.frm_interval_support[frame_rate_index].height			= MODE_XGA_HEIGHT;
	cam->cam_sensor.frm_interval_support[frame_rate_index].type			= V4L2_FRMSIZE_TYPE_STEPWISE;
	cam->cam_sensor.frm_interval_support[frame_rate_index].stepwise.min.numerator	= 1;
	cam->cam_sensor.frm_interval_support[frame_rate_index].stepwise.min.denominator	= 1;
	cam->cam_sensor.frm_interval_support[frame_rate_index].stepwise.max.numerator	= 1;
	cam->cam_sensor.frm_interval_support[frame_rate_index].stepwise.max.denominator	= SENS_MAX_FPS;
	cam->cam_sensor.frm_interval_support[frame_rate_index].stepwise.step.numerator	= 1;
	cam->cam_sensor.frm_interval_support[frame_rate_index].stepwise.step.denominator= 1;
	frame_rate_index++;

	cam->cam_sensor.frm_interval_support[frame_rate_index].index			= frame_rate_index;
//	cam->cam_sensor.frm_interval_support[frame_rate_index].pixel_format		= Support all formats;
	cam->cam_sensor.frm_interval_support[frame_rate_index].width			= MAX_OV3640_WIDTH;
	cam->cam_sensor.frm_interval_support[frame_rate_index].height			= MAX_OV3640_HEIGHT;
	cam->cam_sensor.frm_interval_support[frame_rate_index].type			= V4L2_FRMSIZE_TYPE_STEPWISE;
	cam->cam_sensor.frm_interval_support[frame_rate_index].stepwise.min.numerator	= 1;
	cam->cam_sensor.frm_interval_support[frame_rate_index].stepwise.min.denominator	= 1;
	cam->cam_sensor.frm_interval_support[frame_rate_index].stepwise.max.numerator	= 1;
	cam->cam_sensor.frm_interval_support[frame_rate_index].stepwise.max.denominator	= 7;
	cam->cam_sensor.frm_interval_support[frame_rate_index].stepwise.step.numerator	= 1;
	cam->cam_sensor.frm_interval_support[frame_rate_index].stepwise.step.denominator= 1;
	frame_rate_index++;

	cam->cam_sensor.total_frm_interval_support	= frame_rate_index;

/*
 * configure the sensor
 */
	ret_val	= ov3640_init_config(cam);
	if(CHECK_IN_FAIL_LIMIT(ret_val))
	{
		TRACE_ERR_AND_RET(FAIL);
	}

/*
 * Dump autofocus firmware the sensor
 */

	if(cam->cam_sensor.auto_focus_init)
	{
		ret_val	= cam->cam_sensor.auto_focus_init(cam);
		if(CHECK_IN_FAIL_LIMIT(ret_val))
		{	
			TRACE_ERR_AND_RET(FAIL);
		}
	}

	cam->capture.s_parm.parm.capture.timeperframe.denominator	= 	\
	cam->cam_sensor.s_parm.parm.capture.timeperframe.denominator 	= 30;
	cam->capture.s_parm.parm.capture.timeperframe.numerator		=	\
	cam->cam_sensor.s_parm.parm.capture.timeperframe.numerator	= 1;

	return SUCCESS;
}
/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	:	
 *  Name	:	ov3640_detect_device
 *  Parameter1	:	cam_data *cam	- Base address of camera structure pointer
 *  Returns	:	int		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative value be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *
 *  Description	: 	
 *  Comments	:  	
 ************************************************************************************************************/

int ov3640_detect_device(cam_data *cam)
{
	int ret_val;
	UINT8 reg_data_aw	= 0x00;

	ret_val	= ov3640_read_reg(0x300a,&reg_data_aw);
	if(CHECK_IN_FAIL_LIMIT(ret_val))
	{
		TRACE_ERR_AND_RET(FAIL);
	}	

	if(reg_data_aw != OV3640_DEVICE_ID)
	{
		TRACE_ERR_AND_RET(FAIL);
	}else
	{
		printk(KERN_INFO "\nov3640 found: product id is 0x%02X \n",reg_data_aw);
	}

	return SUCCESS;
}
/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	:	
 *  Name	:	ov3640_exit
 *  Parameter1	:	cam_data *cam	- Base address of camera structure pointer
 *  Returns	:	int		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative value be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *
 *  Description	: 	
 *  Comments	:  	
 ************************************************************************************************************/

int ov3640_exit(cam_data *cam)
{
	i2c_del_driver(&cam->cam_sensor.i2c_driver);
	memset(&cam->cam_sensor,0x00,sizeof(struct camera_sensor));
	return SUCCESS;
}

/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	:	
 *  Name	:	ov3640_reset_config
 *  Parameter1	:	cam_data *cam	- Base address of camera structure pointer
 *  Returns	:	int		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative value be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *
 *  Description	: 	
 *  Comments	:  	
 ************************************************************************************************************/
int ov3640_reset_config(cam_data *cam)
{
	return SUCCESS;
	
}
/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	:	
 *  Name	:	chk_pix_format_support
 *  Parameter1	:	cam_data *cam	- Base address of camera structure pointer
 *  Returns	:	int		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative value be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *
 *  Description	: 	
 *  Comments	:  	
 ************************************************************************************************************/

int chk_pix_format_support(cam_data *cam)
{
	switch(cam->cam_sensor.fmt.fmt.pix.pixelformat)	
	{
		case V4L2_PIX_FMT_UYVY:
		case V4L2_PIX_FMT_YUYV:
		case V4L2_PIX_FMT_RGB565:
		case V4L2_PIX_FMT_RGB555:
		{
			cam->cam_sensor.fmt.fmt.pix.bytesperline	= cam->cam_sensor.fmt.fmt.pix.width * 2;

			cam->cam_sensor.fmt.fmt.pix.sizeimage		= cam->cam_sensor.fmt.fmt.pix.bytesperline *	\
									cam->cam_sensor.fmt.fmt.pix.height;
		}break;
#if 0		
		case V4L2_PIX_FMT_YUV420:
		{
			cam->cam_sensor.fmt.fmt.pix.bytesperline	= cam->cam_sensor.fmt.fmt.pix.width * 2;

			cam->cam_sensor.fmt.fmt.pix.sizeimage		= cam->cam_sensor.fmt.fmt.pix.bytesperline *	\
									cam->cam_sensor.fmt.fmt.pix.height *3/4;

		}break;
#endif
		case V4L2_PIX_FMT_YUV444:
		case V4L2_PIX_FMT_BGR32:
		{
			cam->cam_sensor.fmt.fmt.pix.bytesperline	= cam->cam_sensor.fmt.fmt.pix.width * 3;
			cam->cam_sensor.fmt.fmt.pix.sizeimage		= cam->cam_sensor.fmt.fmt.pix.bytesperline *	\
									cam->cam_sensor.fmt.fmt.pix.height;
		}break;

		case V4L2_PIX_FMT_SBGGR8:
		{
			cam->cam_sensor.fmt.fmt.pix.bytesperline	= cam->cam_sensor.fmt.fmt.pix.width;

			cam->cam_sensor.fmt.fmt.pix.sizeimage		= cam->cam_sensor.fmt.fmt.pix.bytesperline *	\
									cam->cam_sensor.fmt.fmt.pix.height;
			
		}break;
		default:
		{
			printk(KERN_INFO "chk_pix_format_support Searching for %c%c%c%c\n",				\
							(INT8)(0xFF&(cam->cam_sensor.fmt.fmt.pix.pixelformat)),	\
							(INT8)(0xFF&(cam->cam_sensor.fmt.fmt.pix.pixelformat>>8)),	\
							(INT8)(0xFF&(cam->cam_sensor.fmt.fmt.pix.pixelformat>>16)),	\
							(INT8)(0xFF&(cam->cam_sensor.fmt.fmt.pix.pixelformat>>24)));

			TRACE_ERR_AND_RET(FAIL);
		}
	}
	return SUCCESS;
}

/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	:	
 *  Name	:	ov3640_query_formats
 *  Parameter1	:	cam_data *cam	- Base address of camera structure pointer
 *  Returns	:	int		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative value be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *
 *  Description	: 	
 *  Comments	:  	
 ************************************************************************************************************/

int ov3640_query_formats(cam_data *cam)
{
	switch(cam->cam_sensor.qfmt.type)
	{
		case V4L2_BUF_TYPE_VIDEO_CAPTURE:
		{
			if(	(cam->cam_sensor.qfmt.fmt.pix.width > MAX_OV3640_WIDTH)		|| 	\
				(cam->cam_sensor.qfmt.fmt.pix.width < MIN_OV3640_WIDTH)		||	\
				(cam->cam_sensor.qfmt.fmt.pix.height > MAX_OV3640_HEIGHT)	||	\
				(cam->cam_sensor.qfmt.fmt.pix.height < MIN_OV3640_HEIGHT)
			)
			{
					TRACE_ERR_AND_RET(FAIL);
			}

#if 0
/*
 * FIXME:
 * 	From sensor uxga frame corruoption is happening,
 * 	So we fixed in the driver to exclude the problemmatic dimension.
 */
				(((cam->cam_sensor.qfmt.fmt.pix.width > FRM_CRPT_OV3640_WIDTH)	||  	\
				(cam->cam_sensor.qfmt.fmt.pix.height > FRM_CRPT_OV3640_HEIGHT))	&&	\
				((cam->cam_sensor.qfmt.fmt.pix.width < MAX_OV3640_WIDTH)		||	\
				(cam->cam_sensor.qfmt.fmt.pix.height < MAX_OV3640_HEIGHT))))
			{
				TRACE_ERR_AND_RET(FAIL);					
			}
#endif
			switch(cam->cam_sensor.qfmt.fmt.pix.pixelformat)	
			{
				case V4L2_PIX_FMT_UYVY:
				case V4L2_PIX_FMT_YUYV:
				case V4L2_PIX_FMT_RGB565:
				case V4L2_PIX_FMT_SBGGR8:
				{
					break;
				}
		
				default:
				{
					printk(KERN_INFO "chk_pix_format_support Searching for %c%c%c%c\n",		\
							(INT8)(0xFF&(cam->cam_sensor.qfmt.fmt.pix.pixelformat)),	\
							(INT8)(0xFF&(cam->cam_sensor.qfmt.fmt.pix.pixelformat>>8)),	\
							(INT8)(0xFF&(cam->cam_sensor.qfmt.fmt.pix.pixelformat>>16)),	\
							(INT8)(0xFF&(cam->cam_sensor.qfmt.fmt.pix.pixelformat>>24)));

					TRACE_ERR_AND_RET(FAIL);
				}
			}
		}break;
		default:
		{
			printk(KERN_DEBUG "Unsupported format type : %x \n",cam->cam_sensor.qfmt.type);
			TRACE_ERR_AND_RET(FAIL);
		}
	}
	return SUCCESS;
}

/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	:	
 *  Name	:	ov3640_fix_supported_formats
 *  Parameter1	:	cam_data *cam	- Base address of camera structure pointer
 *  Returns	:	int		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative value be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *
 *  Description	: 	
 *  Comments	:  	
 ************************************************************************************************************/

int ov3640_fix_supported_formats(cam_data *cam)
{
	int ret_val;

	switch(cam->cam_sensor.fmt.type)
	{
		case V4L2_BUF_TYPE_VIDEO_CAPTURE:
		{
/*
 * FIXME:
 * 	From sensor uxga frame corruoption is happening,
 * 	So we fixed in the driver to exclude the problemmatic dimension.
 */
			if(												\
				(((cam->cam_sensor.fmt.fmt.pix.width > FRM_CRPT_OV3640_WIDTH)		||  		\
				(cam->cam_sensor.fmt.fmt.pix.height > FRM_CRPT_OV3640_HEIGHT))		&&		\
				((cam->cam_sensor.fmt.fmt.pix.width < MAX_OV3640_WIDTH)	||				\
				(cam->cam_sensor.fmt.fmt.pix.height < MAX_OV3640_HEIGHT))))
			{
				cam->cam_sensor.fmt.fmt.pix.width	= MAX_OV3640_WIDTH;
				cam->cam_sensor.fmt.fmt.pix.height	= MAX_OV3640_HEIGHT;
//				TRACE_ERR_AND_RET(FAIL);
			}
/*
 * Fixing the sensor frame supported limits
 */
			if(cam->cam_sensor.fmt.fmt.pix.width	> MAX_OV3640_WIDTH)
			{
				cam->cam_sensor.fmt.fmt.pix.width	= MAX_OV3640_WIDTH;
			}else if(cam->cam_sensor.fmt.fmt.pix.width < MIN_OV3640_WIDTH)
			{
				cam->cam_sensor.fmt.fmt.pix.width	= MIN_OV3640_WIDTH;
			}
			
			if(cam->cam_sensor.fmt.fmt.pix.height > MAX_OV3640_HEIGHT)
			{
				cam->cam_sensor.fmt.fmt.pix.height	= MAX_OV3640_HEIGHT;
			}else if(cam->cam_sensor.fmt.fmt.pix.height < MIN_OV3640_HEIGHT)
			{
				cam->cam_sensor.fmt.fmt.pix.height	= MIN_OV3640_HEIGHT;
			}

			ret_val	= chk_pix_format_support(cam);
			if(CHECK_IN_FAIL_LIMIT(ret_val))
			{
				TRACE_ERR_AND_RET(FAIL);					
			}
			return SUCCESS;
		}break;
#if 0
		case V4L2_BUF_TYPE_VIDEO_OVERLAY:
		{
			
		}break;
#endif		
		default:
		{
			printk(KERN_DEBUG "Unsupported format type : %x \n",cam->cam_sensor.fmt.type);
			TRACE_ERR_AND_RET(FAIL);					

		}
	}

	return SUCCESS;
}
/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	:	
 *  Name	:	register_sensor_bus
 *  Parameter1	:	cam_data *cam	- Base address of camera structure pointer
 *  Returns	:	int		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative value be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *
 *  Description	: 	
 *  Comments	:  	
 ************************************************************************************************************/
int register_sensor_bus(cam_data *cam)
{
	if(cam == NULL)
	{
		TRACE_ERR_AND_RET(FAIL);
	}

	cam->cam_sensor.init			= ov3640_init;
	cam->cam_sensor.exit			= ov3640_exit;
	cam->cam_sensor.find_device		= ov3640_detect_device;

	cam->cam_sensor.reset			= ov3640_reset_config;
	cam->cam_sensor.config_dim		= ov3640_change_dim_config;
	cam->cam_sensor.brightness		= ov3640_brightness;			
	cam->cam_sensor.contrast		= ov3640_contrast;
	cam->cam_sensor.saturation		= ov3640_saturation;
	cam->cam_sensor.hue			= NULL;
	cam->cam_sensor.whitebalance		= ov3640_white_balance;
	cam->cam_sensor.colour_balance		= NULL;
	cam->cam_sensor.exposure		= ov3640_exposure;
	cam->cam_sensor.gain			= NULL;
	cam->cam_sensor.v_flip			= ov3640_vertical_flip;
	cam->cam_sensor.h_mirror		= ov3640_horizontal_mirror;
	cam->cam_sensor.sharpness		= ov3640_sharpness;
	cam->cam_sensor.sens_strobe		= ov3640_sens_strobe;
	cam->cam_sensor.auto_focus_init		= ov3640_af_firmware_dump;
	cam->cam_sensor.focus			= ov3640_focus;
	cam->cam_sensor.effects			= ov3640_effects;
	cam->cam_sensor.antishake		= ov3640_antishake_firmware_ctrl;
	cam->cam_sensor.frame_rate_ctrl		= ov3640_frame_rate_ctrl;
	cam->cam_sensor.supported_formats	= ov3640_format_support;
	cam->cam_sensor.frame_interval		= ov3640_frame_interval_support;

	cam->cam_sensor.crop			= ov3640_crop;
	cam->cam_sensor.fix_fmt_support		= ov3640_fix_supported_formats;
	cam->cam_sensor.qfmt_support		= ov3640_query_formats;


	return SUCCESS;
}
