/**********************************************************************************************************
 *   Copyright (C) 2007 by e-con Systems .                                                                *
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
 * 	CONTROL_PADCONF_CAM_HS[15:0]     0x4800 210C   cam_hs  		       gpio_94  hw_dbg0  safe_mode
 * 	CONTROL_PADCONF_CAM_HS[31:16]    0x4800 210C   cam_vs   	       gpio_95  hw_dbg1  safe_mode
 * 	CONTROL_PADCONF_CAM_XCLKA[15:0]  0x4800 2110   cam_xclka	       gpio_96           safe_mode
 * 	CONTROL_PADCONF_CAM_XCLKA[31:16] 0x4800 2110   cam_pclk                gpio_97  hw_dbg2  safe_mode
 * 	CONTROL_PADCONF_CAM_FLD[15:0]    0x4800 2114   cam_fld  cam_global_res gpio_98  hw_dbg3  safe_mode
 * 	CONTROL_PADCONF_CAM_FLD[31:16]   0x4800 2114   cam_d0      csi2_dx2    gpio_99           safe_mode
 * 	CONTROL_PADCONF_CAM_D1[15:0]     0x4800 2118   cam_d1      csi2_dy2    gpio_100          safe_mode
 * 	CONTROL_PADCONF_CAM_D1[31:16]    0x4800 2118   cam_d2                  gpio_101 hw_dbg4  safe_mode
 * 	CONTROL_PADCONF_CAM_D3[15:0]     0x4800 211C   cam_d3                  gpio_102 hw_dbg5  safe_mode
 * 	CONTROL_PADCONF_CAM_D3[31:16]    0x4800 211C   cam_d4                  gpio_103 hw_dbg6  safe_mode
 * 	CONTROL_PADCONF_CAM_D5[15:0]     0x4800 2120   cam_d5                  gpio_104 hw_dbg7  safe_mode
 * 	CONTROL_PADCONF_CAM_D5[31:16]    0x4800 2120   cam_d6                  gpio_105          safe_mode
 * 	CONTROL_PADCONF_CAM_D7[15:0]     0x4800 2124   cam_d7                  gpio_106          safe_mode
 * 	CONTROL_PADCONF_CAM_D7[31:16]    0x4800 2124   cam_d8                  gpio_107          safe_mode
 * 	CONTROL_PADCONF_CAM_D9[15:0]     0x4800 2128   cam_d9                  gpio_108          safe_mode
 * 	CONTROL_PADCONF_CAM_D9[31:16]    0x4800 2128  cam_d10                  gpio_109 hw_dbg8  safe_mode
 * 	CONTROL_PADCONF_CAM_D11[15:0]    0x4800 212C  cam_d11                  gpio_110 hw_dbg9  safe_mode
 * 	CONTROL_PADCONF_CAM_D11[31:16]   0x4800 212C cam_xclkb                 gpio_111          safe_mode
 * 	CONTROL_PADCONF_CAM_WEN[15:0]    0x4800 2130  cam_wen     cam_shutter  gpio_167 hw_dbg10 safe_mode
 * 	CONTROL_PADCONF_CAM_WEN[31:16]   0x4800 2130 cam_strobe                gpio_126 hw_dbg11
 */

#define REG_CONTROL_PADCONF_CAM_HS 		0x4800210C

#define REG_CONTROL_PADCONF_CAM_WEN		0x48002130
#define REG_CONTROL_PADCONF_I2C1_SDA		0x480021BC
#define REG_CONTROL_PADCONF_I2C2_SDA		0x480021C0

/*
 * =============================================================================================================
 * 					I2C LINES
 * =============================================================================================================
 *
 *	CONTROL_PADCONF_I2C2_SDA[31:16] 0x4800 21C0  i2c3_scl                  gpio_184          safe_mode
 *	CONTROL_PADCONF_I2C3_SDA[15:0]  0x4800 21C4  i2c3_sda                  gpio_185          safe_mode
 * =============================================================================================================
 */

struct pad_config_value
{
	volatile unsigned short MUXMODE			:3;
	volatile unsigned short PULLUDENABLE		:1;
 	volatile unsigned short PULLTYPESELECT		:1;
	volatile unsigned short RESERVED		:3;
	volatile unsigned short INPUTENABLE		:1;
	volatile unsigned short OFFENABLE		:1;
	volatile unsigned short OFFOUTENABLE		:1;
	volatile unsigned short OFFOUTVALUE		:1;
	volatile unsigned short OFFPULLUDENABLE		:1;
	volatile unsigned short OFFPULLTYPE		:1;
	volatile unsigned short WAKEUPENABLE		:1;
	volatile unsigned short WAKEUPEVENT		:1;
};

typedef struct cam_interface
{
	union
	{
		volatile unsigned int CONTROL_PADCONF_CAM_HS;
		struct
		{
			struct pad_config_value cam_hs;
			struct pad_config_value cam_vs;
		}bit;
	}bit_hs_vs;
	union
	{
		volatile unsigned int CONTROL_PADCONF_CAM_XCLKA;
		struct
		{
			struct pad_config_value cam_xclka;
			struct pad_config_value cam_pclk;
		}bit;
	}bit_xclka_pclk;
	union
	{
		volatile unsigned int CONTROL_PADCONF_CAM_FLD;
		struct
		{
			struct pad_config_value cam_fld;
			struct pad_config_value cam_d0;
		}bit;
	}bit_fld_d0;
	union
	{
		volatile unsigned int CONTROL_PADCONF_CAM_D1;
		struct
		{
			struct pad_config_value cam_d1;
			struct pad_config_value cam_d2;
		}bit;

	}bit_d1_d2;
	union
	{
		volatile unsigned int CONTROL_PADCONF_CAM_D3;
		struct
		{
			struct pad_config_value cam_d3;
			struct pad_config_value cam_d4;
		}bit;

	}bit_d3_d4;
	union
	{
		volatile unsigned int CONTROL_PADCONF_CAM_D5;
		struct
		{
			struct pad_config_value cam_d5;
			struct pad_config_value cam_d6;
		}bit;

	}bit_d5_d6;
	union
	{
		volatile unsigned int CONTROL_PADCONF_CAM_D7;
		struct
		{
			struct pad_config_value cam_d7;
			struct pad_config_value cam_d8;
		}bit;

	}bit_d7_d8;
	union
	{
		volatile unsigned int CONTROL_PADCONF_CAM_D9;
		struct
		{
			struct pad_config_value cam_d9;
			struct pad_config_value cam_d10;
		}bit;

	}bit_d9_d10;
	union
	{
		volatile unsigned int CONTROL_PADCONF_CAM_D11;
		struct
		{
			struct pad_config_value cam_d11;
			struct pad_config_value cam_xclkb;
		}bit;

	}bit_d11_xclkb;

	union
	{
		volatile unsigned int CONTROL_PADCONF_CAM_WEN;
		struct
		{
			struct pad_config_value cam_wen;
			struct pad_config_value cam_strobe;
		}bit;

	}bit_wen_strobe;

	volatile unsigned int	RESERVED[(REG_CONTROL_PADCONF_I2C1_SDA-REG_CONTROL_PADCONF_CAM_WEN)/4];

	union
	{
		volatile unsigned int CONTROL_PADCONF_I2C2_SDA;
		struct
		{
			struct pad_config_value i2c2_sda;
			struct pad_config_value i2c3_scl;
		}bit;

	}bit_i2c2_i2c3;

	union
	{
		volatile unsigned int CONTROL_PADCONF_I2C3_SDA;
		struct
		{
			struct pad_config_value i2c3_sda;
			struct pad_config_value hdq_sio;
		}bit;

	}bit_i2c3_hdq_sio;

} cam_interface_pin_config;

