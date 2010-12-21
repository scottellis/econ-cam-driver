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


#define OV3640_DEVICE_ID		0x36
/*
 * I2C
 */
#define I2C_FLAG_READ			0x01

#define OV3640_I2C_ADDRESS		0x3C
#define I2C_SLAVE_ADDRESS		OV3640_I2C_ADDRESS

#define FRM_CRPT_OV3640_WIDTH		1280
#define FRM_CRPT_OV3640_HEIGHT		1024

#define MAX_OV3640_WIDTH		2048
#define MAX_OV3640_HEIGHT		1536

#define MIN_OV3640_WIDTH		 160
#define MIN_OV3640_HEIGHT		 120

#define MODE_XGA_WIDTH			1024
#define MODE_XGA_HEIGHT			 768

#define SENS_MAX_FPS			30
/*
 * Auto focus status register
 */
#define STEP_FORWARD			(1 << 7)
#define STEP_BACKWARD			(1 << 6)
#define STEP_ABSOLUTE			(1 << 5)

#define MODE_STEP_INSTRUCTION		0x00
#define MODE_STEP_FOCUSING		0x01
#define MODE_STEP_FOCUSED		0x02
#define MODE_STEP_CAPTURE		0x03

#define MODE_IDLE			0x00
#define MODE_SINGLE_FOCUS		0x01
#define MODE_CONTINOUS_FOCUS		0x02
#define MODE_STEP_MODE			0x03

typedef union _auto_focus_register_status
{
	UINT8 reg_data;
	struct
	{
/*
 * Mode Step
 * 	0 0	- Instruction 
 * 	0 1	- Focusing
 * 	1 0 	- Focused
 * 	1 1	- Capture	 
 */
		UINT8 mode_step	:2;
/*
 * Mode
 * 	0 0 	- Idle Mode
 * 	0 1 	- Single Focus Mode
 * 	1 0 	- Continue Focus Mode
 * 	1 1 	- Step Mode
 */


		UINT8 mode		:2;
		UINT8 RESERVED		:1;
		UINT8 capture_mask	:1;
		UINT8 mode_chg_mask	:1;
/*
 * 	Step State 
 * 	1	- Failed 
 * 	0	- Success
 */
		UINT8 step_state	:1;
	}focus;
}af_status;
