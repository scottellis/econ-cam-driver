/**********************************************************************************************************
 *   Copyright (C) 2007 by e-con Systems                                                                  *
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
 *  Name	:	init_omap_hwr
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
FNRESLT init_omap_hwr(cam_data *cam)
{
	FNRESLT ret_val;
/*
 * Configure the camera interface
 */
	ret_val	= init_cam_interface(cam);
	if(CHECK_IN_FAIL_LIMIT(ret_val))
	{
		return ret_val;
	}
/*
 * Configure the isp registers
 */
	ret_val	= init_cam_isp_ccdc(cam);
	if(CHECK_IN_FAIL_LIMIT(ret_val))
	{
		return ret_val;
	}

	return SUCCESS;
}

/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	:	
 *  Name	:	exit_omap_hwr
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
FNRESLT exit_omap_hwr(cam_data *cam)
{
	FNRESLT ret_val;

/*
 * Free all camera interface
 */
	ret_val	= exit_cam_interface(cam);
	if(CHECK_IN_FAIL_LIMIT(ret_val))
	{
		return ret_val;
	}

/*
 * Free isp registers
 */
	ret_val	= exit_cam_isp_ccdc(cam);
	if(CHECK_IN_FAIL_LIMIT(ret_val))
	{
		return ret_val;
	}

	return SUCCESS;
}

