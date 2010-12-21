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
 *  MODULE TYPE	:	FUNCTION				MODULE ID	: OMAP_CAM_INTERFACE_01	
 *  Name	:	omap_pin_base_struct
 *  Parameter1	:	cam_data *cam	- Base address of camera structure pointer 
 *  Parameter2	:	UINT8 option	- command to the current function to perfom the mentioned task.
 *  						CREATE_ADDRESS
 *						SET_ADDRESS
 *						GET_ADDRESS
 *						MAKE_ADDRESS_INVALID
 *
 *  Returns	:	FNRESLT		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative error be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *
 *  Description	: 	stores the omap pin base structure pointer
 *  			and returns the base pointer when a request of GET_ADDRESS 
 *  			command be obtained from the calling functions 
 *  Comments	:  	
 ************************************************************************************************************/
FNRESLT omap_pin_base_struct(cam_data *cam,UINT8 option)
{
	static UINT32 g_cam_interface;

	if(cam == NULL)
	{
		TRACE_ERR_AND_RET(MEMORY_NOT_VALID);
	}
	switch(option)
	{
		case SET_ADDRESS:
		{
			g_cam_interface =(UINT32)cam->pin;			
		}break;

		case GET_ADDRESS:
		{
			cam->pin	= (cam_interface_pin_config*)g_cam_interface;
		}break;

		case MAKE_ADDRESS_INVALID:
		{
			if(cam->pin	== NULL)
			{
				TRACE_ERR_AND_RET(FAIL);
			}
			iounmap(cam->pin);
			cam->pin	= NULL;
			g_cam_interface	= DISABLE;
		}break;
		case CREATE_ADDRESS:
		{
			cam->pin	= ioremap(REG_CONTROL_PADCONF_CAM_HS,4*1024);
			if(cam->pin	== NULL)
			{
				printk(KERN_ERR "Unable to remap the padconfig registers\n");
				TRACE_ERR_AND_RET(FAIL);
			}			
		}break;
		default:
		{
			TRACE_ERR_AND_RET(FAIL);
		}
	}
	return SUCCESS;
}

/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	:	OMAP_CAM_INTERFACE_02
 *  Name	:	configure_cam_interface
 *  Parameter1	:	cam_data *cam	- Base address of camera structure pointer
 *  Returns	:	FNRESLT		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative error be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *
 *  Description	:	Confgure the interface lines between sensor and ccdc unit as camera interface lines  	
 *  Comments	:  	
 ************************************************************************************************************/
FNRESLT configure_cam_interface(cam_data *cam)
{
/*
 * Validate the input
 */
	if(cam == NULL || cam->pin == NULL)
	{
		TRACE_ERR_AND_RET(FAIL);
	}
/*
 * perform operation
 */	
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

/*
 * I2C
 */
	cam->pin->bit_i2c2_i2c3.bit.i2c3_scl.MUXMODE			= DISABLE;
	cam->pin->bit_i2c2_i2c3.bit.i2c3_scl.INPUTENABLE		= ENABLE;
	cam->pin->bit_i2c2_i2c3.bit.i2c3_scl.PULLUDENABLE		= ENABLE;
	cam->pin->bit_i2c2_i2c3.bit.i2c3_scl.PULLTYPESELECT		= ENABLE;

	cam->pin->bit_i2c3_hdq_sio.bit.i2c3_sda.MUXMODE			= DISABLE;
	cam->pin->bit_i2c3_hdq_sio.bit.i2c3_sda.INPUTENABLE		= ENABLE;
	cam->pin->bit_i2c3_hdq_sio.bit.i2c3_sda.PULLUDENABLE		= ENABLE;
	cam->pin->bit_i2c3_hdq_sio.bit.i2c3_sda.PULLTYPESELECT		= ENABLE;
	return SUCCESS;
}


/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	: OMAP_CAM_INTERFACE_03
 *  Name	:	init_cam_interface
 *  Parameter1	:	cam_data *cam	- Base address of camera structure pointer
 *  Returns	:	FNRESLT		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative error be returned
 *
 *  					  Note: 
 *  					  	For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *
 *  Description	: 	init the camera interface configuration.
 *  Comments	:  	Each .c code have init and exit functions calling the init_xxx will initlize the 
 *  			the local variables and structure variable in the main structure.
 ************************************************************************************************************/
FNRESLT init_cam_interface(cam_data *cam)
{
	FNRESLT ret_val;
/*
 * Validate the input
 */
	if(cam == NULL)
	{
		TRACE_ERR_AND_RET(FAIL);
	}

	ret_val	= omap_pin_base_struct(cam,CREATE_ADDRESS);
	if(CHECK_IN_FAIL_LIMIT(ret_val))
	{
		printk(KERN_ERR "Failed to map the camera interface registers\n");
		TRACE_ERR_AND_RET(FAIL);		
	}

	ret_val	= omap_pin_base_struct(cam,SET_ADDRESS);
	if(CHECK_IN_FAIL_LIMIT(ret_val))
	{
		printk(KERN_ERR "Failed to map the camera interface registers\n");
		TRACE_ERR_AND_RET(FAIL);		
	}
/*
 * Configured the camera interface
 */
	ret_val	= configure_cam_interface(cam);
	if(CHECK_IN_FAIL_LIMIT(ret_val))
	{
		printk(KERN_ERR "Failed to map the camera interface registers\n");
		TRACE_ERR_AND_RET(FAIL);		
	}

	return SUCCESS;
}

/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	: OMAP_CAM_INTERFACE_04
 *  Name	:	exit_cam_interface
 *  Parameter1	:	INT0
 *  Returns	:	FNRESLT		- On Success Zero (or) positive value be returned to the calling
 *  					  Functions and On error a negative error be returned
 *  					  Note: For more detail about the return values please refer
 *  					  error.c and error.h file available in the current project
 *  Description	: 	exit part of code in the camera interface configuration.
 *  Comments	:  	Each .c code have init and exit functions calling the init_xxx will initlize the 
 *  			the local variables and structure variable in the main structure.
 *  			
 ************************************************************************************************************/
FNRESLT exit_cam_interface(cam_data *cam)
{
	FNRESLT ret_val;
/*
 * Validate the input
 */
	if(cam == NULL)
	{
		TRACE_ERR_AND_RET(FAIL);
	}

	ret_val	= omap_pin_base_struct(cam,MAKE_ADDRESS_INVALID);
	if(CHECK_IN_FAIL_LIMIT(ret_val))
	{
		printk(KERN_ERR "Failed to unmap the camera interface registers\n");
		TRACE_ERR_AND_RET(FAIL);		
	}
	return SUCCESS;
}
