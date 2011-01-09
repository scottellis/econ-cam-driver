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
#include "ov3640_firmware.h"

static int ov3640_init_config(cam_data *cam)
{
	ov3640_write_reg(0x3012, 0x80);
	ov3640_write_reg(0x304d, 0x45);
	ov3640_write_reg(0x30a7, 0x5e);
	ov3640_write_reg(0x3087, 0x16);
	ov3640_write_reg(0x309C, 0x1a);
	ov3640_write_reg(0x30a2, 0xe4);
	ov3640_write_reg(0x30aa, 0x42);
	ov3640_write_reg(0x30b0, 0xff);
	ov3640_write_reg(0x30b1, 0xff);
	ov3640_write_reg(0x30b2, 0x10);

	ov3640_write_reg(0x300e, 0x32);
	ov3640_write_reg(0x300f, 0x21);
	ov3640_write_reg(0x3010, 0x20);
	ov3640_write_reg(0x3011, 0x04);
	ov3640_write_reg(0x304c, 0x82);
	ov3640_write_reg(0x30d7, 0x10);

	ov3640_write_reg(0x30d9, 0x0d);
	ov3640_write_reg(0x30db, 0x08);
	ov3640_write_reg(0x3016, 0x82);

	ov3640_write_reg(0x3018, 0x38);
	ov3640_write_reg(0x3019, 0x30);
	ov3640_write_reg(0x301a, 0x61);
	ov3640_write_reg(0x307d, 0x00);
	ov3640_write_reg(0x3087, 0x02);
	ov3640_write_reg(0x3082, 0x20);

	ov3640_write_reg(0x3015, 0x12);
	ov3640_write_reg(0x3014, 0x0c);
	ov3640_write_reg(0x3013, 0xf7);

	ov3640_write_reg(0x303c, 0x08);
	ov3640_write_reg(0x303d, 0x18);
	ov3640_write_reg(0x303e, 0x06);
	ov3640_write_reg(0x303F, 0x0c);
	ov3640_write_reg(0x3030, 0x62);	
	ov3640_write_reg(0x3031, 0x26);
	ov3640_write_reg(0x3032, 0xe6);
	ov3640_write_reg(0x3033, 0x6e);
	ov3640_write_reg(0x3034, 0xea);
	ov3640_write_reg(0x3035, 0xae);
	ov3640_write_reg(0x3036, 0xa6);
	ov3640_write_reg(0x3037, 0x6a);

	ov3640_write_reg(0x3104, 0x02);
	ov3640_write_reg(0x3105, 0xfd);
	ov3640_write_reg(0x3106, 0x00);
	ov3640_write_reg(0x3107, 0xff);

	ov3640_write_reg(0x3300, 0x13);
	ov3640_write_reg(0x3301, 0xde);

	ov3640_write_reg(0x3302, 0xcf);

	ov3640_write_reg(0x3312, 0x26);
	ov3640_write_reg(0x3314, 0x42);
	ov3640_write_reg(0x3313, 0x2b);
	ov3640_write_reg(0x3315, 0x42);
	ov3640_write_reg(0x3310, 0xd0);
	ov3640_write_reg(0x3311, 0xbd);
	ov3640_write_reg(0x330c, 0x18);
	ov3640_write_reg(0x330d, 0x18);
	ov3640_write_reg(0x330e, 0x56);
	ov3640_write_reg(0x330f, 0x5c);
	ov3640_write_reg(0x330b, 0x1c);
	ov3640_write_reg(0x3306, 0x5c);
	ov3640_write_reg(0x3307, 0x11);

	ov3640_write_reg(0x336a, 0x52);
	ov3640_write_reg(0x3370, 0x44);
	ov3640_write_reg(0x3376, 0x40);
	ov3640_write_reg(0x3300, 0x13);

	ov3640_write_reg(0x30b8, 0x20);
	ov3640_write_reg(0x30b9, 0x17);
	ov3640_write_reg(0x30ba, 0x04);
	ov3640_write_reg(0x30bb, 0x08);

	ov3640_write_reg(0x3500, 0x00);
	ov3640_write_reg(0x3507, 0x06);
	ov3640_write_reg(0x350a, 0x4f);
	ov3640_write_reg(0x3610, 0x60);

	ov3640_write_reg(0x3100, 0x32);
	ov3640_write_reg(0x363d, 0x60);

	ov3640_write_reg(0x3301, 0xde);
	ov3640_write_reg(0x3304, 0x00);
	ov3640_write_reg(0x3400, 0x00);
	ov3640_write_reg(0x3404, 0x00);
	ov3640_write_reg(0x3600, 0xc0);

	ov3640_write_reg(0x304c, 0x81);
	ov3640_write_reg(0x3011, 0x04);

	ov3640_write_reg(0x335f, 0x68);
	ov3640_write_reg(0x3360, 0x18);
	ov3640_write_reg(0x3361, 0x0c);
	ov3640_write_reg(0x3362, 0x46);
	ov3640_write_reg(0x3363, 0x48);
	ov3640_write_reg(0x3364, 0xb4);

	ov3640_write_reg(0x3012, 0x00);
	ov3640_write_reg(0x3020, 0x01);
	ov3640_write_reg(0x3021, 0x1d);
	ov3640_write_reg(0x3022, 0x00);
	ov3640_write_reg(0x3023, 0x0a);
	ov3640_write_reg(0x3024, 0x08);
	ov3640_write_reg(0x3025, 0x18);
	ov3640_write_reg(0x3026, 0x06);
	ov3640_write_reg(0x3027, 0x0c);
	ov3640_write_reg(0x302a, 0x06);
	ov3640_write_reg(0x302b, 0x20);
	ov3640_write_reg(0x3075, 0x44);
	ov3640_write_reg(0x300d, 0x00);
	ov3640_write_reg(0x30d7, 0x10);
	ov3640_write_reg(0x3069, 0x44);
	ov3640_write_reg(0x303e, 0x01);
	ov3640_write_reg(0x303f, 0x80);

	ov3640_write_reg(0x3302, 0xef);
	ov3640_write_reg(0x335f, 0x68);
	ov3640_write_reg(0x3360, 0x18);
	ov3640_write_reg(0x3361, 0x0c);

	ov3640_write_reg(0x3404, 0x02);
	ov3640_write_reg(0x3100, 0x02);

	return 0;
}


/*
 *  Description	: 	Configure the mode of streaming (QXGA (or) XGA) based on the Image dimension  
 *  			request given by driver.
 *
 *
 * Comments	:  	Ov3640 supports two modes XGA and QXGA 
 *
 *  			In XGA mode upto maximum of 30 fps be acheived.
 *  			In QXGA mode upto maximum of 15 fps be acheived.
 */
static int configure_dimension_change(cam_data *cam)
{
	static int width,height,old_logic_case;
	unsigned int logic_case;

	if ((cam->cam_sensor.fmt.fmt.pix.width <= MODE_XGA_WIDTH) &&
		(cam->cam_sensor.fmt.fmt.pix.height <= MODE_XGA_HEIGHT))
		logic_case = 1;
	else
		logic_case	= 2;


	if (old_logic_case == logic_case) {
		return SUCCESS;
	}
	else {
		old_logic_case = logic_case;
		width = cam->cam_sensor.fmt.fmt.pix.width;
		height = cam->cam_sensor.fmt.fmt.pix.height;
	}
	
	switch (logic_case) {
	case 1:
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

	case 2:
	default:
		ov3640_write_reg(0x3100, 0x32);
		ov3640_write_reg(0x363d, 0x60);

		ov3640_write_reg(0x3301, 0xde);
		ov3640_write_reg(0x3304, 0x00);
		ov3640_write_reg(0x3400, 0x00);
		ov3640_write_reg(0x3404, 0x00);
		ov3640_write_reg(0x3600, 0xc0);

		ov3640_write_reg(0x304c, 0x81);
		ov3640_write_reg(0x3011, 0x01);

		ov3640_write_reg(0x335f, 0x68);
		ov3640_write_reg(0x3360, 0x18);
		ov3640_write_reg(0x3361, 0x0c);
		ov3640_write_reg(0x3362, 0x46);
		ov3640_write_reg(0x3363, 0x48);
		ov3640_write_reg(0x3364, 0xb4);

		ov3640_write_reg(0x3012, 0x00);
		ov3640_write_reg(0x3020, 0x01);
		ov3640_write_reg(0x3021, 0x1d);
		ov3640_write_reg(0x3022, 0x00);
		ov3640_write_reg(0x3023, 0x0a);
		ov3640_write_reg(0x3024, 0x08);
		ov3640_write_reg(0x3025, 0x18);
		ov3640_write_reg(0x3026, 0x06);
		ov3640_write_reg(0x3027, 0x0c);
		ov3640_write_reg(0x302a, 0x06);
		ov3640_write_reg(0x302b, 0x20);
		ov3640_write_reg(0x3075, 0x44);
		ov3640_write_reg(0x300d, 0x00);
		ov3640_write_reg(0x30d7, 0x10);
		ov3640_write_reg(0x3069, 0x44);
		ov3640_write_reg(0x303e, 0x01);
		ov3640_write_reg(0x303f, 0x80);

		ov3640_write_reg(0x3302, 0xef);
		ov3640_write_reg(0x335f, 0x68);
		ov3640_write_reg(0x3360, 0x18);
		ov3640_write_reg(0x3361, 0x0c);

		ov3640_write_reg(0x3404, 0x02);
		ov3640_write_reg(0x3100, 0x02);
		break;
	}

	ov3640_write_reg(0x3100, 0x02);

	/* colour bar */
 	/* ov3640_write_reg(0x3300, 0x08); */

	return 0;
}

 /*
 *  Description	: 	Configure the image width and height to the sensor
 *
 *  Comments	:  	Based on the driver request, changing the pixelformat also be performed here.
 *  			Note:
 *  				bfw_count be added for intel pxa based processor to overcome the loss of 
 *  				first line
 */
static int ov3640_change_dim_config(cam_data *cam)
{
	static int old_width, old_height;
	unsigned int width, height, bfw_count = 2;
	int ret_val;

	unsigned char y_start = 2;
	unsigned char x_start = 4;
#if 0 
	static int focus_box	= ENABLE;
	if(focus_box == ENABLE)
	{
		ov3640_write_reg(0x3F00, 0x04);
		ov3640_write_reg(0x3F00, 0x01);
		focus_box = DISABLE;
	}else
	{
		ov3640_write_reg(0x3F00, 0x02);
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

	if (configure_dimension_change(cam) < 0)
		return -1;
	
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
	
	return 0;
}

static int ov3640_crop(cam_data *cam)
{
	switch (cam->cam_sensor.cmd_to_sensor) {
	case GET_DATA_FRM_SENSOR:
		cam->cam_sensor.cropcap.bounds.top = DISABLE;
		cam->cam_sensor.cropcap.bounds.left = DISABLE;
		cam->cam_sensor.cropcap.bounds.width = MAX_OV3640_WIDTH;
		cam->cam_sensor.cropcap.bounds.height = MAX_OV3640_HEIGHT;
		cam->cam_sensor.cropcap.defrect = cam->cam_sensor.cropcap.bounds;
		cam->cam_sensor.cropcap.pixelaspect.numerator = 1;
		cam->cam_sensor.cropcap.pixelaspect.denominator = 1;
		break;
	
	case SET_DATA_TO_SENSOR:
		break;
	
	case QUERY_DATA_FRM_SENSOR:
		break;		
	}

	return 0;
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
static int ov3640_brightness(cam_data *cam)
{
	/*
	 * Value must be in the range of 
	 * -0x30  0x0  0x30
	 *  -48   0   +48
	 */
	unsigned char reg_value;

	printk(KERN_DEBUG "Brightness Value is %d\n", cam->ctrl.value);

	switch (cam->cam_sensor.cmd_to_sensor) {
	case GET_DATA_FRM_SENSOR:
		ov3640_read_reg(0x3354,&reg_value);

		if (reg_value == 0x08) {
			ov3640_read_reg(0x335e,&reg_value);
			cam->ctrl.value	= -reg_value;
		}
		else {
			ov3640_read_reg(0x335e,&reg_value);
			cam->ctrl.value	= reg_value;
		}
		
		if (cam->ctrl.value > 48)
			cam->ctrl.value = 48;
		else if (cam->ctrl.value < -48)
			cam->ctrl.value = -48;
		
		break;

	case SET_DATA_TO_SENSOR:
		if (cam->ctrl.value >= 0) {
			ov3640_write_reg(0x335e,0xFF & cam->ctrl.value);
			ov3640_write_reg(0x3355,0x04);
			ov3640_write_reg(0x3354,0x01);
		}
		else {
			ov3640_write_reg(0x335e,0xFF & -cam->ctrl.value);
			ov3640_write_reg(0x3355,0x04);
			ov3640_write_reg(0x3354,0x08);
		}

		break;

	case QUERY_DATA_FRM_SENSOR:
		cam->cam_sensor.qctrl.id = V4L2_CID_BRIGHTNESS;
		cam->cam_sensor.qctrl.type = V4L2_CTRL_TYPE_INTEGER;
		strncpy(cam->cam_sensor.qctrl.name, "Brightness", strlen("Brightness"));
		cam->cam_sensor.qctrl.minimum = -48;
		cam->cam_sensor.qctrl.maximum = 48;
		cam->cam_sensor.qctrl.step = 1;
		cam->cam_sensor.qctrl.default_value = 0;
		cam->cam_sensor.qctrl.flags = V4L2_CTRL_FLAG_SLIDER;
		break;

	default:
		return -EINVAL;	
	}

	return 0;
}

/*
 *  Description	: 	Histogram based exposure algorithm to increase the exposure of the image
 *  Comments	:  	In ov3640 sensor Average based and Histogram based algorithm be available
 */  			
static int ov3640_exposure(cam_data *cam)
{
	/*
	 * Histogram-based Algorithm
	 * Value must be in the range of 
	 * 0x38 - 0x88
	 *  -40 - +40
	 */
	unsigned char reg_value;

	printk(KERN_DEBUG "ov3640_exposure %d\n",cam->ctrl.value);

	switch (cam->cam_sensor.cmd_to_sensor) {
	case GET_DATA_FRM_SENSOR:
		ov3640_read_reg(0x3018, &reg_value);
		cam->ctrl.value	= reg_value -0x80;
		
		if (cam->ctrl.value > 40)
			cam->ctrl.value = 40;
		else if (cam->ctrl.value < -40)
			cam->ctrl.value = -40;
		
		break;

	case SET_DATA_TO_SENSOR:
		if (cam->ctrl.value >= -40 && cam->ctrl.value <= 40) {
			ov3640_write_reg(0x3018, 0x80 + cam->ctrl.value );
			ov3640_write_reg(0x3019, 0x60 + cam->ctrl.value );
		}
		else {
			ov3640_write_reg(0x3018, 0x80);
			ov3640_write_reg(0x3019, 0x60);
		}

		break;

	case QUERY_DATA_FRM_SENSOR:
		cam->cam_sensor.qctrl.id = V4L2_CID_EXPOSURE;
		cam->cam_sensor.qctrl.type = V4L2_CTRL_TYPE_INTEGER;
		strncpy(cam->cam_sensor.qctrl.name, "Exposure", strlen("Exposure"));
		cam->cam_sensor.qctrl.minimum = -40;
		cam->cam_sensor.qctrl.maximum = 40;
		cam->cam_sensor.qctrl.step = 1;
		cam->cam_sensor.qctrl.default_value = 0;
		cam->cam_sensor.qctrl.flags = V4L2_CTRL_FLAG_SLIDER;
		break;

	default:
		return -EINVAL;		
	}

	return 0;
}

static int ov3640_sharpness(cam_data *cam)
{
	unsigned char reg;

	/* 
	 * Value must be in the range of 
	 * 0x42 0x45 0x48
 	*  -3   0   +3
 	*/

	printk(KERN_DEBUG "ov3640_sharpness %d\n",cam->ctrl.value);

	switch(cam->cam_sensor.cmd_to_sensor) {
	case GET_DATA_FRM_SENSOR:
		ov3640_read_reg(0x332d, &reg);
		cam->ctrl.value = reg - 0x45;

		if (cam->ctrl.value > 3)
			cam->ctrl.value = 3;
		else if (cam->ctrl.value < -3) 
			cam->ctrl.value = -3;

		break;

	case SET_DATA_TO_SENSOR:
		if (cam->ctrl.value >= -3 && cam->ctrl.value <= 3) {
			ov3640_write_reg(0x332d, 0x45 + (cam->ctrl.value));
			ov3640_write_reg(0x332f, 0x03);
		}
		else {
			ov3640_write_reg(0x332d, 0x60);
			ov3640_write_reg(0x332f, 0x03);
		}
		
		break;

	case QUERY_DATA_FRM_SENSOR:
		cam->cam_sensor.qctrl.id = V4L2_CID_SHARPNESS;
		cam->cam_sensor.qctrl.type = V4L2_CTRL_TYPE_INTEGER;
		strncpy(cam->cam_sensor.qctrl.name, "sharpness", 
			strlen("sharpness"));
		cam->cam_sensor.qctrl.minimum = -3;
		cam->cam_sensor.qctrl.maximum = 3;
		cam->cam_sensor.qctrl.step = 1;
		cam->cam_sensor.qctrl.default_value = 0;
		cam->cam_sensor.qctrl.flags = V4L2_CTRL_FLAG_SLIDER;
		break;

	default:
		return -EINVAL;	
	}

	return 0;
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
			unsigned char reg_value;
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
			unsigned char reg_value;
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
 *  Parameter1	:	int value	- Temperature of the source.
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

int planckian_locus_lookuptable(int value)
{
	typedef struct _aw_temp_gain_adj
	{
		unsigned int temp;
		unsigned char r;
		unsigned char g;
		unsigned char b;
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
	unsigned char reg_value;
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
	unsigned char reg_value;
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
	unsigned char reg;
	struct ov3640_firmware *as;
	int i, size;

	switch (cam->cam_sensor.cmd_to_sensor) {	
	case GET_DATA_FRM_SENSOR:
		if (cam->ctrl.id == V4L2_SENS_ANTISHAKE_STATUS) {
			ov3640_read_reg(0x3f07, &reg);
			cam->ctrl.value	= reg;
		}

		break;

	case SET_DATA_TO_SENSOR:
		if (cam->ctrl.id == V4L2_SENS_ANTISHAKE) {
			as = get_antishake_firmware(&size);

			if (!as)
				return -1;

			for (i = 0; i < size; i++) 
				ov3640_write_reg(as[i].reg, as[i].value);

			mdelay(100);

			/* V4L2_SENS_ANTISHAKE_ENABLE */
			ov3640_write_reg(0x3f00,0x0A);
			ov3640_write_reg(0x3f00,0x0F);
		}

		break;
	}

	return 0;
}

 /*
 *  Description	: Auto focus firmware register dump
 *  Comments	: Before performing autofocus related operations - Auto focus 
 *		  firmware dump should be applied
*/
static int ov3640_af_firmware_dump(cam_data *cam)
{
	struct ov3640_firmware *af;
	int i, size;

	af = get_autofocus_firmware(&size);

	if (!af)
		return -1;

	for (i = 0; i < size; i++)
		ov3640_write_reg(af[i].reg, af[i].value);

	return 0;
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
	unsigned char regval_3011	= DISABLE;
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
		ov3640_write_reg(0x307A, 0x8F);	
	}else
	{
		ov3640_write_reg(0x307A, 0x0F);	
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
	unsigned char reg_value;
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
 *  Parameter1	:	int addr	- Slave address (7-bit) address
 *  Parameter2	:	char *reg	- Ov3640 Register address base address
 *  Parameter3	:	char *buf	- Ov3640 Register data base address
 *  Parameter4	:	int num	- Number of data need to read/write in i2c transation
 *  Parameter5	:	int tran_flag	- 0- Write,1-read
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

int ov3640_i2c_client_xfer(int addr, char *reg, char *buf, int num, int tran_flag)
{
	struct i2c_msg msg[2];
	int ret_val;
	int ret;
	cam_data *cam = NULL;
	unsigned char reg_addr_data[3];

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
 *  Parameter2	:	unsigned char reg_data		- Ov3640 register data
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
static int ov3640_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
#define OV3640_RESET_GPIO	98
#define OV3640_STANDBY_GPIO	167

	cam_data *cam;

	if (i2c_get_clientdata(client) < 0)
		return -ENODEV;

	if (v4l2_base_struct(&cam, GET_ADDRESS) < 0) {
		printk(KERN_ERR "Failed to register the camera device\n");
		return -ENODEV;
	}
	
	cam->cam_sensor.client = client;

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

	return 0;

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

static int ov3640_remove(struct i2c_client *client)
{
	if (client->adapter) 
		i2c_set_clientdata(client, NULL);

	return 0;
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
static const struct i2c_device_id ov3640_id[] =	{
	{ OV3640_DRIVER_NAME, 0 },
	{ },
};
MODULE_DEVICE_TABLE(i2c_0, ov3640_id);

int ov3640_init(cam_data *cam)
{
	int  ret_val;
	unsigned int index = 0;
	unsigned int fmt_index = 0;
	unsigned int frame_rate_index = 0;
	
	cam->cam_sensor.i2c_driver.driver.name	= OV3640_DRIVER_NAME;
	cam->cam_sensor.i2c_driver.driver.owner	= THIS_MODULE;
	cam->cam_sensor.i2c_driver.probe = ov3640_probe;
	cam->cam_sensor.i2c_driver.remove = __exit_p(ov3640_remove);
	cam->cam_sensor.i2c_driver.id_table = ov3640_id;


	if (i2c_add_driver(&cam->cam_sensor.i2c_driver) < 0)
		return -1;

	if (cam->cam_sensor.find_device) {
		if (cam->cam_sensor.find_device(cam) < 0) {
			ov3640_exit(cam);
			return -1;
		}
	}

	/*
	 * init the sensor capability
	 */
	
	cam->cam_sensor.formats[index].index = index;
	strcpy(cam->cam_sensor.formats[index].description, "RGB565");
	cam->cam_sensor.formats[index].pixelformat = V4L2_PIX_FMT_RGB565;
	cam->cam_sensor.formats[index].type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	index++;


	cam->cam_sensor.formats[index].index = index;
	strcpy(cam->cam_sensor.formats[index].description, "UYVY, packed");
	cam->cam_sensor.formats[index].pixelformat = V4L2_PIX_FMT_UYVY;
	cam->cam_sensor.formats[index].type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	index++;


	cam->cam_sensor.formats[index].index = index;
	strcpy(cam->cam_sensor.formats[index].description, "YUYV, packed");
	cam->cam_sensor.formats[index].pixelformat = V4L2_PIX_FMT_YUYV;
	cam->cam_sensor.formats[index].type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	index++;


	cam->cam_sensor.formats[index].index = index;
	strcpy(cam->cam_sensor.formats[index].description, "BA81, BGBG");
	cam->cam_sensor.formats[index].pixelformat = V4L2_PIX_FMT_SBGGR8;
	cam->cam_sensor.formats[index].type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	index++;


	cam->cam_sensor.formats[index].index = index;
	strcpy(cam->cam_sensor.formats[index].description, "YUV444, packed");
	cam->cam_sensor.formats[index].pixelformat = V4L2_PIX_FMT_YUV444;
	cam->cam_sensor.formats[index].type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
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

	cam->cam_sensor.formats[index].index = index;
	strcpy(cam->cam_sensor.formats[index].description, "RGB555");
	cam->cam_sensor.formats[index].pixelformat = V4L2_PIX_FMT_RGB555;
	cam->cam_sensor.formats[index].type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	index++;


	cam->cam_sensor.formats[index].index = index;
	strcpy(cam->cam_sensor.formats[index].description, "BGR888");
	cam->cam_sensor.formats[index].pixelformat = V4L2_PIX_FMT_BGR32;
	cam->cam_sensor.formats[index].type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
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

	cam->cam_sensor.total_frm_interval_support = frame_rate_index;

	/*
	 * configure the sensor
	 */
	ret_val	= ov3640_init_config(cam);
	if (CHECK_IN_FAIL_LIMIT(ret_val))
		TRACE_ERR_AND_RET(FAIL);

	/*
	 * Dump autofocus firmware the sensor
	 */
	if (cam->cam_sensor.auto_focus_init) {
		ret_val	= cam->cam_sensor.auto_focus_init(cam);

		if (CHECK_IN_FAIL_LIMIT(ret_val))
			TRACE_ERR_AND_RET(FAIL);
	}

	cam->capture.s_parm.parm.capture.timeperframe.denominator = 30;
	cam->cam_sensor.s_parm.parm.capture.timeperframe.denominator = 30;
	cam->capture.s_parm.parm.capture.timeperframe.numerator	= 1;
	cam->cam_sensor.s_parm.parm.capture.timeperframe.numerator = 1;

	return SUCCESS;
}

int ov3640_detect_device(cam_data *cam)
{
	unsigned char reg = 0x00;

	if (ov3640_read_reg(0x300a, &reg) < 0)
		return -1;

	if (reg != OV3640_DEVICE_ID) {
		printk(KERN_ERR "OV3640 camera not found: 0x%02X\n", reg);
		return -1;
	}

	printk(KERN_INFO "OV3640 found: product id is 0x%02X\n", reg);

	return 0;
}

int ov3640_exit(cam_data *cam)
{
	i2c_del_driver(&cam->cam_sensor.i2c_driver);
	memset(&cam->cam_sensor, 0x00, sizeof(struct camera_sensor));
	return 0;
}

int ov3640_reset_config(cam_data *cam)
{
	return 0;	
}

int chk_pix_format_support(cam_data *cam)
{
	struct v4l2_pix_format *pf;
	
	pf = &cam->cam_sensor.fmt.fmt.pix;

	switch (pf->pixelformat) {
	case V4L2_PIX_FMT_UYVY:
	case V4L2_PIX_FMT_YUYV:
	case V4L2_PIX_FMT_RGB565:
	case V4L2_PIX_FMT_RGB555:
		pf->bytesperline = pf->width * 2;
		pf->sizeimage = pf->bytesperline * pf->height;
		break;

#if 0		
	case V4L2_PIX_FMT_YUV420:
		pf->bytesperline = pf->width * 2;
		pf->sizeimage = (pf->bytesperline * pf->height * 3) / 4;
		break;
#endif

	case V4L2_PIX_FMT_YUV444:
	case V4L2_PIX_FMT_BGR32:
		pf->bytesperline = pf->width * 3;
		pf->sizeimage = pf->bytesperline * pf->height;
		break;

	case V4L2_PIX_FMT_SBGGR8:
		pf->bytesperline = pf->width;
		pf->sizeimage = pf->bytesperline * pf->height;
		break;
		
	default:
		printk(KERN_INFO "chk_pix_format_support Searching for %c%c%c%c\n",
			(char)(0xFF & pf->pixelformat),
			(char)(0xFF & (pf->pixelformat >> 8)),
			(char)(0xFF & (pf->pixelformat >> 16)),
			(char)(0xFF & (pf->pixelformat >> 24)));
			return -1;
	}

	

	return 0;
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
							(char)(0xFF&(cam->cam_sensor.qfmt.fmt.pix.pixelformat)),	\
							(char)(0xFF&(cam->cam_sensor.qfmt.fmt.pix.pixelformat>>8)),	\
							(char)(0xFF&(cam->cam_sensor.qfmt.fmt.pix.pixelformat>>16)),	\
							(char)(0xFF&(cam->cam_sensor.qfmt.fmt.pix.pixelformat>>24)));

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
	int width, height;

	switch(cam->cam_sensor.fmt.type) {
	case V4L2_BUF_TYPE_VIDEO_CAPTURE:
		/*
		 * FIXME:
		 * 	From sensor uxga frame corruoption is happening,
		 * 	So we fixed in the driver to exclude the problemmatic dimension.
		 */
		width = cam->cam_sensor.fmt.fmt.pix.width;
		height = cam->cam_sensor.fmt.fmt.pix.height;

		if ((width > FRM_CRPT_OV3640_WIDTH || height > FRM_CRPT_OV3640_HEIGHT)
			 && (width < MAX_OV3640_WIDTH || height < MAX_OV3640_HEIGHT)) {
			width = MAX_OV3640_WIDTH;
			height = MAX_OV3640_HEIGHT;
		}
		else {
			if (width > MAX_OV3640_WIDTH)
				width = MAX_OV3640_WIDTH;
			else if (width < MIN_OV3640_WIDTH)
				width = MIN_OV3640_WIDTH;
			
			if (height > MAX_OV3640_HEIGHT)
				height = MAX_OV3640_HEIGHT;
			else if (height < MIN_OV3640_HEIGHT)
				height = MIN_OV3640_HEIGHT;
		}

		cam->cam_sensor.fmt.fmt.pix.width = width;
		cam->cam_sensor.fmt.fmt.pix.height = height;
		
		ret_val	= chk_pix_format_support(cam);

		if(CHECK_IN_FAIL_LIMIT(ret_val))
			TRACE_ERR_AND_RET(FAIL);					

		break;

	default:
		printk(KERN_DEBUG "Unsupported format type : %x\n", cam->cam_sensor.fmt.type);
		TRACE_ERR_AND_RET(FAIL);					
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
	if (!cam) 
		return -1;

	cam->cam_sensor.init = ov3640_init;
	cam->cam_sensor.exit = ov3640_exit;
	cam->cam_sensor.find_device = ov3640_detect_device;
	cam->cam_sensor.reset = ov3640_reset_config;
	cam->cam_sensor.config_dim = ov3640_change_dim_config;
	cam->cam_sensor.brightness = ov3640_brightness;			
	cam->cam_sensor.contrast = ov3640_contrast;
	cam->cam_sensor.saturation = ov3640_saturation;
	cam->cam_sensor.hue = NULL;
	cam->cam_sensor.whitebalance = ov3640_white_balance;
	cam->cam_sensor.colour_balance = NULL;
	cam->cam_sensor.exposure = ov3640_exposure;
	cam->cam_sensor.gain = NULL;
	cam->cam_sensor.v_flip = ov3640_vertical_flip;
	cam->cam_sensor.h_mirror = ov3640_horizontal_mirror;
	cam->cam_sensor.sharpness = ov3640_sharpness;
	cam->cam_sensor.sens_strobe = ov3640_sens_strobe;
	cam->cam_sensor.auto_focus_init = ov3640_af_firmware_dump;
	cam->cam_sensor.focus = ov3640_focus;
	cam->cam_sensor.effects	= ov3640_effects;
	cam->cam_sensor.antishake = ov3640_antishake_firmware_ctrl;
	cam->cam_sensor.frame_rate_ctrl = ov3640_frame_rate_ctrl;
	cam->cam_sensor.supported_formats = ov3640_format_support;
	cam->cam_sensor.frame_interval = ov3640_frame_interval_support;
	cam->cam_sensor.crop = ov3640_crop;
	cam->cam_sensor.fix_fmt_support = ov3640_fix_supported_formats;
	cam->cam_sensor.qfmt_support = ov3640_query_formats;

	return 0;
}
