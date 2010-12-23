/**********************************************************************************************************
 *   Copyright (C) 2009 by e-con Systems .                                                                *
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
 *
 *
 *==========================================================================================================
 */


#include "inc_header.h"

static u32 g_cam_interface;

static int omap_pin_base_struct(cam_data *cam, UINT8 option)
{
	switch (option) {
	case SET_ADDRESS:
		g_cam_interface = (u32) cam->pin;			
		break;

	case GET_ADDRESS:
		cam->pin = (cam_interface_pin_config*)g_cam_interface;
		break;

	case MAKE_ADDRESS_INVALID:
		if (!cam->pin)
			return -EINVAL;

		iounmap(cam->pin);
		cam->pin = NULL;
		g_cam_interface	= 0;
		break;
	
	case CREATE_ADDRESS:
		cam->pin = ioremap(REG_CONTROL_PADCONF_CAM_HS, 4 * 1024);
		
		if (!cam->pin) {
			printk(KERN_ERR  
				"Unable to remap the pad config registers\n");
			return -ENOMEM;
		}	
		
		break;
	
	default:
		return -EINVAL;
	}

	return 0;
}

/* 
 * Confgure the interface lines between sensor and ccdc unit as camera interface lines 
 */
static int configure_cam_interface(cam_data *cam)
{
	if (!cam->pin)
		return -EINVAL;

	cam->pin->bit_hs_vs.bit.cam_hs.MUXMODE				= DISABLE;
	cam->pin->bit_hs_vs.bit.cam_hs.INPUTENABLE			= ENABLE;
	cam->pin->bit_hs_vs.bit.cam_hs.PULLUDENABLE			= ENABLE;
	cam->pin->bit_hs_vs.bit.cam_hs.PULLTYPESELECT			= ENABLE;

	cam->pin->bit_hs_vs.bit.cam_vs.MUXMODE				= DISABLE;
	cam->pin->bit_hs_vs.bit.cam_vs.INPUTENABLE			= ENABLE;
	cam->pin->bit_hs_vs.bit.cam_vs.PULLUDENABLE			= ENABLE;
	cam->pin->bit_hs_vs.bit.cam_vs.PULLTYPESELECT			= ENABLE;

	cam->pin->bit_xclka_pclk.bit.cam_xclka.MUXMODE			= DISABLE;
	cam->pin->bit_xclka_pclk.bit.cam_xclka.INPUTENABLE		= ENABLE;
	cam->pin->bit_xclka_pclk.bit.cam_xclka.PULLUDENABLE		= DISABLE;
	cam->pin->bit_xclka_pclk.bit.cam_xclka.PULLTYPESELECT		= DISABLE;

	cam->pin->bit_xclka_pclk.bit.cam_pclk.MUXMODE			= DISABLE;
	cam->pin->bit_xclka_pclk.bit.cam_pclk.INPUTENABLE		= ENABLE;
	cam->pin->bit_xclka_pclk.bit.cam_pclk.PULLUDENABLE		= ENABLE;
	cam->pin->bit_xclka_pclk.bit.cam_pclk.PULLTYPESELECT		= ENABLE;

	cam->pin->bit_fld_d0.bit.cam_d0.MUXMODE				= DISABLE;
	cam->pin->bit_fld_d0.bit.cam_d0.INPUTENABLE			= ENABLE;
	cam->pin->bit_fld_d0.bit.cam_d0.PULLUDENABLE			= DISABLE;
	cam->pin->bit_fld_d0.bit.cam_d0.PULLTYPESELECT			= DISABLE;


	cam->pin->bit_d1_d2.bit.cam_d1.MUXMODE				= DISABLE;
	cam->pin->bit_d1_d2.bit.cam_d1.INPUTENABLE			= ENABLE;
	cam->pin->bit_d1_d2.bit.cam_d1.PULLUDENABLE			= DISABLE;
	cam->pin->bit_d1_d2.bit.cam_d1.PULLTYPESELECT			= DISABLE;

	cam->pin->bit_d1_d2.bit.cam_d2.MUXMODE				= DISABLE;
	cam->pin->bit_d1_d2.bit.cam_d2.INPUTENABLE			= ENABLE;
	cam->pin->bit_d1_d2.bit.cam_d2.PULLUDENABLE			= DISABLE;
	cam->pin->bit_d1_d2.bit.cam_d2.PULLTYPESELECT			= DISABLE;

	cam->pin->bit_d3_d4.bit.cam_d3.MUXMODE				= DISABLE;
	cam->pin->bit_d3_d4.bit.cam_d3.INPUTENABLE			= ENABLE;
	cam->pin->bit_d3_d4.bit.cam_d3.PULLUDENABLE			= DISABLE;
	cam->pin->bit_d3_d4.bit.cam_d3.PULLTYPESELECT			= DISABLE;

	cam->pin->bit_d3_d4.bit.cam_d4.MUXMODE				= DISABLE;
	cam->pin->bit_d3_d4.bit.cam_d4.INPUTENABLE			= ENABLE;
	cam->pin->bit_d3_d4.bit.cam_d4.PULLUDENABLE			= DISABLE;
	cam->pin->bit_d3_d4.bit.cam_d4.PULLTYPESELECT			= DISABLE;

	cam->pin->bit_d5_d6.bit.cam_d5.MUXMODE				= DISABLE;
	cam->pin->bit_d5_d6.bit.cam_d5.INPUTENABLE			= ENABLE;
	cam->pin->bit_d5_d6.bit.cam_d5.PULLUDENABLE			= DISABLE;
	cam->pin->bit_d5_d6.bit.cam_d5.PULLTYPESELECT			= DISABLE;

	cam->pin->bit_d5_d6.bit.cam_d6.MUXMODE				= DISABLE;
	cam->pin->bit_d5_d6.bit.cam_d6.INPUTENABLE			= ENABLE;
	cam->pin->bit_d5_d6.bit.cam_d6.PULLUDENABLE			= DISABLE;
	cam->pin->bit_d5_d6.bit.cam_d6.PULLTYPESELECT			= DISABLE;

	cam->pin->bit_d7_d8.bit.cam_d7.MUXMODE				= DISABLE;
	cam->pin->bit_d7_d8.bit.cam_d7.INPUTENABLE			= ENABLE;
	cam->pin->bit_d7_d8.bit.cam_d7.PULLUDENABLE			= DISABLE;
	cam->pin->bit_d7_d8.bit.cam_d7.PULLTYPESELECT			= DISABLE;

	cam->pin->bit_d7_d8.bit.cam_d8.MUXMODE				= DISABLE;
	cam->pin->bit_d7_d8.bit.cam_d8.INPUTENABLE			= ENABLE;
	cam->pin->bit_d7_d8.bit.cam_d8.PULLUDENABLE			= DISABLE;
	cam->pin->bit_d7_d8.bit.cam_d8.PULLTYPESELECT			= DISABLE;

	cam->pin->bit_d9_d10.bit.cam_d9.MUXMODE				= DISABLE;
	cam->pin->bit_d9_d10.bit.cam_d9.INPUTENABLE			= ENABLE;
	cam->pin->bit_d9_d10.bit.cam_d9.PULLUDENABLE			= DISABLE;
	cam->pin->bit_d9_d10.bit.cam_d9.PULLTYPESELECT			= DISABLE;

	cam->pin->bit_d9_d10.bit.cam_d10.MUXMODE			= DISABLE;
	cam->pin->bit_d9_d10.bit.cam_d10.INPUTENABLE			= ENABLE;
	cam->pin->bit_d9_d10.bit.cam_d10.PULLUDENABLE			= DISABLE;
	cam->pin->bit_d9_d10.bit.cam_d10.PULLTYPESELECT			= DISABLE;

	cam->pin->bit_d11_xclkb.bit.cam_d11.MUXMODE			= DISABLE;
	cam->pin->bit_d11_xclkb.bit.cam_d11.INPUTENABLE			= ENABLE;
	cam->pin->bit_d11_xclkb.bit.cam_d11.PULLUDENABLE		= DISABLE;
	cam->pin->bit_d11_xclkb.bit.cam_d11.PULLTYPESELECT		= DISABLE;

	cam->pin->bit_d11_xclkb.bit.cam_xclkb.MUXMODE			= DISABLE;
	cam->pin->bit_d11_xclkb.bit.cam_xclkb.INPUTENABLE		= ENABLE;
	cam->pin->bit_d11_xclkb.bit.cam_xclkb.PULLUDENABLE		= DISABLE;
	cam->pin->bit_d11_xclkb.bit.cam_xclkb.PULLTYPESELECT		= DISABLE;


	cam->pin->bit_i2c2_i2c3.bit.i2c3_scl.MUXMODE			= DISABLE;
	cam->pin->bit_i2c2_i2c3.bit.i2c3_scl.INPUTENABLE		= ENABLE;
	cam->pin->bit_i2c2_i2c3.bit.i2c3_scl.PULLUDENABLE		= ENABLE;
	cam->pin->bit_i2c2_i2c3.bit.i2c3_scl.PULLTYPESELECT		= ENABLE;

	cam->pin->bit_i2c3_hdq_sio.bit.i2c3_sda.MUXMODE			= DISABLE;
	cam->pin->bit_i2c3_hdq_sio.bit.i2c3_sda.INPUTENABLE		= ENABLE;
	cam->pin->bit_i2c3_hdq_sio.bit.i2c3_sda.PULLUDENABLE		= ENABLE;
	cam->pin->bit_i2c3_hdq_sio.bit.i2c3_sda.PULLTYPESELECT		= ENABLE;

	return 0;
}

int init_cam_interface(cam_data *cam)
{
	if (!cam)
		return -EINVAL;	

	if (omap_pin_base_struct(cam, CREATE_ADDRESS)) {
		printk(KERN_ERR "Failed to map the camera interface regs\n");
		return -1;		
	}

	if (omap_pin_base_struct(cam, SET_ADDRESS)) {
		printk(KERN_ERR "Failed to map the camera interface regs\n");
		return -1;
	}

	if (configure_cam_interface(cam)) {
		printk(KERN_ERR "Failed to map the camera interface regs\n");
		return -1;		
	}

	return 0;
}

int exit_cam_interface(cam_data *cam)
{
	if (!cam)
		return -EINVAL;


	if (omap_pin_base_struct(cam, MAKE_ADDRESS_INVALID)) {
		printk(KERN_ERR "Failed to unmap the camera interface regs\n");
		return -1;		
	}

	return 0;
}
