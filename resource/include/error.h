/**********************************************************************************************************
 *   Copyright (C) 2007 by e-con Systems.                                                                 *
 *   www.e-consystems.com                                                                                 *
 *                                                                                                        *
 *   This file is licensed under the terms of the GNU General Public License                              *
 *   version 2. This program is licensed "as is" without any warranty of any                              *
 *   kind, whether express or implied.                                                                    *
 *                                                                                                        *
 *                                                                                                        *
 *   PROJECT	           :         Error code management                                                *
 *   MODULE NAME           :                                                                              *
 *   MODULE VERSION        :                                                                              *
 *                                                                                                        *
 *                                                                                                        *
 *                                                                                                        *
 *   Version No	: 000-0001                                                          CODE_REV  : 0.0.0.0   *
 **********************************************************************************************************/

/*
 *==========================================================================================================
 *                                        REVISION HISTORY                                  
 *----------------------------------------------------------------------------------------------------------
 * CODE_REV  REASON FOR MODIFICATION                MODIFIED FUNCTION NAME  	            AUTHOR
 *----------------------------------------------------------------------------------------------------------
 * 0.0.0.0   code development                                                         Ananthapadmanaban
 *
 *
 *==========================================================================================================
 */


/******************************************************************************
 *  			GENDRAL ERROR TYPE DEFINITION
 *				
 *  Author	:	E-consystems
 *
 *
 ******************************************************************************/

#define TRACE_ERROR(ARG1) 											\
{														\
	trace_error(__FILE__,(PINT8)__FUNCTION__,__LINE__,ARG1);						\
}

#define TRACE_ERR_AND_RET(ARG1) 										\
{														\
	trace_error(__FILE__,(PINT8)__FUNCTION__,__LINE__,ARG1);						\
	return ARG1;												\
}

/******************************************************************************
 * 			Device structure register 
 *
 ******************************************************************************/

#define REGISTER_DATA			0x00000001			
#define UNREGISTER_CLEAR_ENTRY		0x00000002
#define GET_REGISTERED_DATA		0x00000003

#define NO_DATA				0x00000000
#define RESET_TIME			0x00000001

#define ERROR_BLOCK			0x00100000

/******************************************************************************
 *  				API RETURN TYPE Definition 
 *				
 *  Author		:	E-consystems
 *
 *  APPLICATION SPECIFIC SUCCESS      RANGE - (0x0000_0000 - 0x3FFF_FFFF)
 *  =========================================================================
 *
 *
 *  DRIVER SPECIFIC SUCCESS BASES     RANGE - (0x4000_0000 - 0x7FFF_FFFF)
 *  =========================================================================
 *  BASIC SUCCESS	:	0x7EE0_0000 - 0x7EEF_FFFF
 *  I2C SUCCESS		:	0x7ED0_0000 - 0x7EDF_FFFF
 *
 *  ----------------------------------------------------------------------------
 *
 *
 *  DRIVER SPECIFIC ERRORS            RANGE - (0x8000_0000 - 0xBFFF_FFFF)
 *  =========================================================================
 *  BASIC ERRORS	:	0x8000_0000 - 0x800F_FFFF
 *  I2C ERROR		:	0x8010_0000 - 0x801F_FFFF
 *  MEMORY ERROR	:	0x8020_0000 - 0x802F_FFFF
 *
 *  APPLICATION SPECIFIC ERRORS BASES:RANGE - (0xC000_0000 - 0xFF7F_FFFF)
 *  =========================================================================
 *  BASIC ERROR 	:	0xC000_0000 - 0xC00F_FFFF
 *  READ ERROR		:	0xC010_0000 - 0xC01F_FFFF 
 *  WRITE ERROR 	:	0xC020_0000 - 0xC02F_FFFF 
 *  memory ERROR	:	0xC030_0000 - 0xC03F_FFFF
 *  Ioctls ERROR	:	0xC040_0000 - 0xC04F_FFFF
 *  =========================================================================
 *
 *
 *  SPECIAL ERROR	:	0xFF80_0000 - 0xFFFF_FFFF
 *
 ******************************************************************************/


enum __error_base_macro
{
	APP_BASE_SUC_START	= 0x00000000,
	APP_BASE_SUC_END	= 0x3FFFFFFF,
	DRI_BASE_SUC_START	= 0x40000000,
	DRI_BASE_SUC_END	= 0x7FFFFFFF,

	DRI_BASE_ERR_START	= 0x80000000,
	DRI_BASIC_ERR		= DRI_BASE_ERR_START,
	DRI_I2C_ERROR		= (DRI_BASIC_ERR + ERROR_BLOCK),
	DRI_MEM_ERROR		= (DRI_I2C_ERROR + ERROR_BLOCK),

	DRI_BASE_ERR_END	= 0xBFFFFFFF,

	APP_BASE_ERR_START	= 0xC0000000,
	APP_BASIC_ERR		= APP_BASE_ERR_START,
	APP_READ_ERR		= (APP_BASIC_ERR	+ ERROR_BLOCK),
	APP_WRITE_ERR		= (APP_READ_ERR		+ ERROR_BLOCK),
	APP_MEMORY_ERR		= (APP_WRITE_ERR	+ ERROR_BLOCK),
	APP_IOCTL_ERR		= (APP_MEMORY_ERR	+ ERROR_BLOCK),
	APP_BASE_ERR_END	= 0xFF7FFFFF,

	SPECIAL_ERROR_START	= 0xFF800000,
	SPECIAL_ERROR_END	= 0xFFFFFFFF,
};

#define CHECK_IN_SUCCESS_LIMIT(x)			((x >= (FNRESLT)APP_BASE_SUC_START) && (x <= (FNRESLT)DRI_BASE_SUC_END))
#define CHECK_IN_FAIL_LIMIT(x)				((x >= (FNRESLT)DRI_BASE_ERR_START ) && (x <= (FNRESLT)SPECIAL_ERROR_END))

enum __error_base
{
/****************************************************************************
 *
 * 		Application Specific SUCCESS code definitions
 *
 ****************************************************************************/

	SUCCESS				= APP_BASE_SUC_START,

/****************************************************************************
 *
 * 		Driver Specific SUCCESS code definitions
 *
 ****************************************************************************/
	I2C_INIT_SUCCESS		= DRI_BASE_SUC_START,
	I2C_TX_EMPTY_SEND_SUCCESS,
	I2C_WRITE_SUCCESS,
	I2C_RX_FULL_SUCCESS,
	I2C_READ_SUCCESS,
	I2C_CAM_READ_REGISTER_SUCCESS,
	I2C_PROTO_READ_ID_SUCCESS,
	PAGE_0_REG_ACCESS_SUCCESS,
	PAGE_1_REG_ACCESS_SUCCESS,
	PAGE_2_REG_ACCESS_SUCCESS,
	MT9D111_DUMP_ALL_SUCCESS,
	MT9D111_SOFT_RESET_SUCCESS,
	I2C_BUS_AVAILABLE,

/****************************************************************************
 *
 * 		Driver Specific Error code definitions
 *
 ****************************************************************************/

/*
 * BASIC ERROR definition
 */
	DRIVER_MEMORY_NOT_AVAILABLE	= DRI_BASIC_ERR,

/*
 * I2C ERROR definition
 */
	I2C_INIT_FAIL			= DRI_I2C_ERROR,
	I2C_TX_EMPTY_SEND_FAIL,
	I2C_WRITE_FAIL,
	I2C_RX_FULL_FAIL,
	I2C_READ_FAIL,
	I2C_CAM_READ_REGISTER_FAIL,
	I2C_PROTO_READ_ID_FAIL,
	PAGE_0_REG_ACCESS_FAIL,
	PAGE_1_REG_ACCESS_FAIL,
	PAGE_2_REG_ACCESS_FAIL,
	MT9D111_SOFT_RESET_FAIL,
	CLK_BYPASS_PLL_FAIL,
	MCU_RESET_VALUE_FAIL,
	RESET_EN_REG_VALUE_FAIL,
	RESET_DIS_REG_VALUE_FAIL,
	I2C_BUS_BUSY,

/*
 * Memory Error definition
 */
	MEM_KERN_OVERLAP		= DRI_MEM_ERROR,
	
/****************************************************************************
 *
 *			Application based error types
 *
 ****************************************************************************/

/*
 * BASIC ERROR definition
 */

	PORT_OPEN_FAILURE		= APP_BASIC_ERR,
	FILE_OPEN_FAILURE,

/*
 * READ ERROR definition
 */

	READ_ERROR			= APP_READ_ERR,
	LOOSING_BYTES_IN_READ,
	LESS_NUM_BYTE_READ,
	MORE_NUM_BYTE_READ,
	LESS_NUMBER_BYTE_IN_PORT,
	READ_FROM_DEVICE_FAIL,

/*
 * WRITE ERROR definition
 */
	WRITE_ERROR			= APP_WRITE_ERR,
	LESS_NUM_BYTE_WRITE,
	MORE_NUM_BYTE_WRITE,
	FAILED_TO_WRITE_TO_PORT,


/*
 * MEMORY ERROR definition
 */
	MEMORY_ERROR			= APP_MEMORY_ERR,
	ALLOCATION_MEMORY_FAILED,
	MEMORY_NOT_VALID,

/*
 * IOCTLS ERROR definition
 */
	IOCTLS_ERROR			= APP_IOCTL_ERR,
	DATA_FRM_PORT_NOT_VALID,
	IOCTL_GET_DATA_FAILED,
	IOCTL_LOGING_DATA_FAILED,

/*
 * Special type of Errors
 */
	CAPTURE_FORMAT_NOT_AVAILABLE	= SPECIAL_ERROR_START,
	MAPPING_FAILED,
	POINTER_NOT_REGISTERED,
	ALLOCATION_MEMORY_FAILED_BASED_POINTER,


	PORT_OPEN_ERROR			= -1,
	FAIL				= -1,

};


