/**********************************************************************************************************
 *   Copyright (C) 2009 by e-con Systems .                                                                *
 *   www.e-consystems.com                                                                                 *
 *                                                                                                        *
 *   This file is licensed under the terms of the GNU General Public License                              *
 *   version 2. This program is licensed "as is" without any warranty of any                              *
 *   kind, whether express or implied.                                                                    *
 *                                                                                                        *
 *                                                                                                        *
 *   PROJECT	           :          Error code management                                               *
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
 *
 *
 *
 *==========================================================================================================
 */

/*
 * Header file inclution part
 */

#include "inc_header.h"

#ifdef CONFIG_DRIVER
	#define printf(x...) printk(KERN_DEBUG x)	
#endif	
/******************************************************************************
 *  				 Function 
 *				
 *  Name	:	trace_error
 *  Author	:	E-consystems
 *  Parameter1	:	UINT32 - Error number
 *  Returns	:	NONE
 *  Description	:	error from various device are classified into groups and 
 *  			debugged over here 
 *  Comments	:  				 	
 ******************************************************************************/
#define TEP(file_name,function_name,line_no,Error_number,Error_number_in_string,Reason_in_string) 			\
															\
	case Error_number:												\
	{														\
		printf(KERN_ALERT "-------------------------------------------------------------------------------\n");	\
		printf(KERN_ALERT "ERROR!\n");										\
		printf(KERN_ALERT "From            : %s\n",MODULE_NAME);						\
		printf(KERN_ALERT "File            : %s\n",file_name);							\
		printf(KERN_ALERT "Function        : %s\n",function_name);						\
		printf(KERN_ALERT "Line number     : %u\n",line_no);							\
		printf(KERN_ALERT "Error name      : %s\n",Error_number_in_string);					\
		printf(KERN_ALERT "Error number Dec: %lld Hex: 0x%X \n",(INT64)Error_number,(INT32)Error_number);	\
		printf(KERN_ALERT "Reason          : %s\n",Reason_in_string);						\
		printf(KERN_ALERT "------------------------------------------------------------------------------\n");	\
		break;													\
	}	

#define TEP_DEFAULT(file_name,function_name,line_no,Error_number_in_string,Reason_in_string) 				\
															\
	default :													\
	{														\
		printf(KERN_ALERT "------------------------------------------------------------------------------\n");	\
		printf(KERN_ALERT "ERROR!\n");										\
		printf(KERN_ALERT "From            : %s\n",MODULE_NAME);						\
		printf(KERN_ALERT "File            : %s\n",file_name);							\
		printf(KERN_ALERT "Function        : %s\n",function_name);						\
		printf(KERN_ALERT "Line number     : %u\n",line_no);							\
		printf(KERN_ALERT "Reason          : %s\n",Reason_in_string);						\
		printf(KERN_ALERT "------------------------------------------------------------------------------\n");	\
		break;													\
	}

/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	:	
 *
 *  Name	:	trace_error 
 *  Parameter1	:	PINT8 file_name 
 *  Parameter2	:	PINT8 function_name 
 *  Parameter3	:	UINT32 line_no
 *  Parameter4	:	UINT32 Error_num
 *  
 *  Returns	:	FNRESLT_NONE
 *  Description	: 	
 *  Comments	:  	Based on the error Number, Debug prints will be called.
 ************************************************************************************************************/
FNRESLT_NONE trace_error(PINT8 file_name, PINT8 function_name, int line_no, int Error_num)
{
	switch(Error_num)
	{
/*
 * Success return Values
 */
		TEP(file_name,function_name,line_no,SUCCESS,"SUCCESS",							\
				"Got a positive feedback from the module just debug lines");
/*
 * Special type of Errors
 */
#if 0
		TEP(file_name,function_name,line_no,-EPERM,"EPERM",							\
				"Operation not permitted ");
#endif

#if defined(CONFIG_KERNEL_ERR_INCLUDED)
		TEP(file_name,function_name,line_no,-ENOENT,"ENOENT",							\
				"No such file or directory ");
		TEP(file_name,function_name,line_no,-ESRCH,"ESRCH",							\
				"No such process");
		TEP(file_name,function_name,line_no,-EINTR,"EINTR",							\
				"Interrupted system call");
		TEP(file_name,function_name,line_no,-EIO,"EIO",								\
				"I/O error");
		TEP(file_name,function_name,line_no,-ENXIO,"ENXIO",							\
				"No such device or address");
		TEP(file_name,function_name,line_no,-E2BIG,"E2BIG",							\
				"Argument list too long");
		TEP(file_name,function_name,line_no,-ENOEXEC,"ENOEXEC",							\
				"Exec format error ");
		TEP(file_name,function_name,line_no,-EBADF,"EBADF",							\
				"Bad file number");
		TEP(file_name,function_name,line_no,-ECHILD,"ECHILD",							\
				"No child processes");
		TEP(file_name,function_name,line_no,-EAGAIN,"EAGAIN",							\
				"Try again");
		TEP(file_name,function_name,line_no,-ENOMEM,"ENOMEM",							\
				"Out of memory");
		TEP(file_name,function_name,line_no,-EACCES,"EACCES",							\
				"Permission denied");
		TEP(file_name,function_name,line_no,-EFAULT,"EFAULT",							\
				"Bad address");
		TEP(file_name,function_name,line_no,-ENOTBLK,"ENOTBLK",							\
				"Block device required");
		TEP(file_name,function_name,line_no,-EBUSY,"EBUSY",							\
				"Device or resource busy");
		TEP(file_name,function_name,line_no,-EEXIST,"EEXIST",							\
				"File exists");
		TEP(file_name,function_name,line_no,-EXDEV,"EXDEV",							\
				"Cross-device link");
		TEP(file_name,function_name,line_no,-ENODEV,"ENODEV",							\
				"No such device");
		TEP(file_name,function_name,line_no,-ENOTDIR,"ENOTDIR",							\
				"Not a directory");
		TEP(file_name,function_name,line_no,-EISDIR,"EISDIR",							\
				"Is a directory");
		TEP(file_name,function_name,line_no,-EINVAL,"EINVAL",							\
				"Invalid argument");
		TEP(file_name,function_name,line_no,-ENFILE,"ENFILE",							\
				"File table overflow");
		TEP(file_name,function_name,line_no,-EMFILE,"EMFILE",							\
				"Too many open files");
		TEP(file_name,function_name,line_no,-ENOTTY,"ENOTTY",							\
				"Not a typewriter");
		TEP(file_name,function_name,line_no,-ETXTBSY,"ETXTBSY",							\
				"Text file busy");
		TEP(file_name,function_name,line_no,-EFBIG,"EFBIG",							\
				"File too large");
		TEP(file_name,function_name,line_no,-ENOSPC,"ENOSPC",							\
				"No space left on device");
		TEP(file_name,function_name,line_no,-ESPIPE,"ESPIPE",							\
				"Illegal seek");
		TEP(file_name,function_name,line_no,-EROFS,"EROFS",							\
				"Read-only file system");
		TEP(file_name,function_name,line_no,-EMLINK,"EMLINK",							\
				"Too many links");
		TEP(file_name,function_name,line_no,-EPIPE,"EPIPE",							\
				"Broken pipe");
		TEP(file_name,function_name,line_no,-EDOM,"EDOM",							\
				"Math argument out of domain of func");
		TEP(file_name,function_name,line_no,-ERANGE,"ERANGE",							\
				"Math result not representable");
#endif
/*
 *
 * BASIC ERROR definition
 */

		TEP(file_name,function_name,line_no,FAIL,"1. PORT_OPEN_ERROR 2. FAIL 3.EPERM",				\
				"1. unknown cause of failure								\
			\n\t\t 2. Failed to open the port may be driver is not properly inserted or file not found	\
			\n\t\t 3. Operation not permitted");

		TEP(file_name,function_name,line_no,PORT_OPEN_FAILURE,"PORT_OPEN_FAILURE",				\
				"Cannot open the port, Driver is not properly inserted or device entry missing");

		TEP(file_name,function_name,line_no,FILE_OPEN_FAILURE,"FILE_OPEN_FAILURE",				\
				"Unable to open the file. Check the file presence");
/*
 * READ ERROR definition
 */

		TEP(file_name,function_name,line_no,LOOSING_BYTES_IN_READ,"LOOSING_BYTES_IN_READ",			\
				"Some other device or thread reading the character form the allocated port ");

		TEP(file_name,function_name,line_no,LESS_NUM_BYTE_READ,"LESS_NUM_BYTE_READ",				\
				"less number of bytes read from the device from the checked one");

		TEP(file_name,function_name,line_no,MORE_NUM_BYTE_READ,"MORE_NUM_BYTE_READ",				\
				"More number of bytes read from the device from the checked one");

		TEP(file_name,function_name,line_no,LESS_NUMBER_BYTE_IN_PORT,"LESS_NUMBER_BYTE_IN_PORT",		\
				"In Port less number of bytes than expected one");
/*
 * WRITE ERROR definition
 */

		TEP(file_name,function_name,line_no,LESS_NUM_BYTE_WRITE,"LESS_NUM_BYTE_WRITE",				\
				"less number of bytes Writted to the device");

		TEP(file_name,function_name,line_no,MORE_NUM_BYTE_WRITE,"MORE_NUM_BYTE_WRITE",				\
				"more number of bytes Writted to the device");

		TEP(file_name,function_name,line_no,FAILED_TO_WRITE_TO_PORT,"FAILED_TO_WRITE_TO_PORT",			\
				"Failed to write to device please try after some time");

/*
 * MEMORY ERROR definition
 */
		TEP(file_name,function_name,line_no,ALLOCATION_MEMORY_FAILED,"ALLOCATION_MEMORY_FAILED",		\
				"Memory needed by the application not available under run time");
		TEP(file_name,function_name,line_no,MEMORY_NOT_VALID,"MEMORY_NOT_VALID",				\
				"Memory wish to access is invalid.. please try with valid memory");


/*
 * IOCTLS ERROR definition
 */
		TEP(file_name,function_name,line_no,DATA_FRM_PORT_NOT_VALID,"DATA_FRM_PORT_NOT_VALID",			\
				"Not a vaid data from the ioctl");

		TEP(file_name,function_name,line_no,IOCTL_GET_DATA_FAILED,"IOCTL_GET_DATA_FAILED",			\
				"Getting data from ioctl failed please check the file descriptor");

/*
 * SPECIAL_APLICATION_ERROR definition
 */

		TEP(file_name,function_name,line_no,CAPTURE_FORMAT_NOT_AVAILABLE,"CAPTURE_FORMAT_NOT_AVAILABLE",	\
				"Zoom value is too high so the output value is more than the available one");

		TEP(file_name,function_name,line_no,MAPPING_FAILED,"MAPPING_FAILED",					\
				"Mapping kernel space area to user space area failed");



/******************************************************************************
 *
 * 		Driver Specific Error code definitions
 *
 ******************************************************************************/


/*
 * I2C definition
 */
		TEP(file_name,function_name,line_no,I2C_INIT_SUCCESS,"I2C_INIT_SUCCESS",				\
				"");

		TEP(file_name,function_name,line_no,I2C_TX_EMPTY_SEND_SUCCESS,"I2C_TX_EMPTY_SEND_SUCCESS",		\
				"");

		TEP(file_name,function_name,line_no,I2C_WRITE_SUCCESS,"I2C_WRITE_SUCCESS",				\
				"");

		TEP(file_name,function_name,line_no,I2C_RX_FULL_SUCCESS,"I2C_RX_FULL_SUCCESS",				\
				"");

		TEP(file_name,function_name,line_no,I2C_READ_SUCCESS,"I2C_READ_SUCCESS",				\
				"");

		TEP(file_name,function_name,line_no,I2C_CAM_READ_REGISTER_SUCCESS,"I2C_CAM_READ_REGISTER_SUCCESS",	\
				"");

		TEP(file_name,function_name,line_no,I2C_PROTO_READ_ID_SUCCESS,"I2C_PROTO_READ_ID_SUCCESS",		\
				"");

		TEP(file_name,function_name,line_no,PAGE_0_REG_ACCESS_SUCCESS,"PAGE_0_REG_ACCESS_SUCCESS",		\
				"");

		TEP(file_name,function_name,line_no,PAGE_1_REG_ACCESS_SUCCESS,"PAGE_1_REG_ACCESS_SUCCESS",		\
				"");

		TEP(file_name,function_name,line_no,PAGE_2_REG_ACCESS_SUCCESS,"PAGE_2_REG_ACCESS_SUCCESS",		\
				"");

		TEP(file_name,function_name,line_no,MT9D111_DUMP_ALL_SUCCESS,"MT9D111_DUMP_ALL_SUCCESS",		\
				"");

		TEP(file_name,function_name,line_no,MT9D111_SOFT_RESET_SUCCESS,"MT9D111_SOFT_RESET_SUCCESS",		\
				"");

		TEP(file_name,function_name,line_no,I2C_INIT_FAIL,"I2C_INIT_FAIL",					\
				"");

		TEP(file_name,function_name,line_no,I2C_TX_EMPTY_SEND_FAIL,"I2C_TX_EMPTY_SEND_FAIL",			\
				"");

		TEP(file_name,function_name,line_no,I2C_WRITE_FAIL,"I2C_WRITE_FAIL",					\
				"");

		TEP(file_name,function_name,line_no,I2C_RX_FULL_FAIL,"I2C_RX_FULL_FAIL",				\
				"");

		TEP(file_name,function_name,line_no,I2C_READ_FAIL,"I2C_READ_FAIL",					\
				"");

		TEP(file_name,function_name,line_no,I2C_CAM_READ_REGISTER_FAIL,"I2C_CAM_READ_REGISTER_FAIL",		\
				"");

		TEP(file_name,function_name,line_no,I2C_PROTO_READ_ID_FAIL,"I2C_PROTO_READ_ID_FAIL",			\
				"");

		TEP(file_name,function_name,line_no,PAGE_0_REG_ACCESS_FAIL,"PAGE_0_REG_ACCESS_FAIL",			\
				"");

		TEP(file_name,function_name,line_no,PAGE_1_REG_ACCESS_FAIL,"PAGE_1_REG_ACCESS_FAIL",			\
				"");

		TEP(file_name,function_name,line_no,PAGE_2_REG_ACCESS_FAIL,"PAGE_2_REG_ACCESS_FAIL",			\
				"");

		TEP(file_name,function_name,line_no,MT9D111_SOFT_RESET_FAIL,"MT9D111_SOFT_RESET_FAIL",			\
				"");

		TEP(file_name,function_name,line_no,CLK_BYPASS_PLL_FAIL,"CLK_BYPASS_PLL_FAIL",				\
				"");

		TEP(file_name,function_name,line_no,MCU_RESET_VALUE_FAIL,"MCU_RESET_VALUE_FAIL",			\
				"");

		TEP(file_name,function_name,line_no,RESET_EN_REG_VALUE_FAIL,"RESET_EN_REG_VALUE_FAIL",			\
				"");

		TEP(file_name,function_name,line_no,RESET_DIS_REG_VALUE_FAIL,"RESET_DIS_REG_VALUE_FAIL",		\
				"");
/*
 * Memory Error definition
 */

		TEP(file_name,function_name,line_no,MEM_KERN_OVERLAP,"MEM_KERN_OVERLAP",				\
				"Kernel memory region is getting overlaped with the reserved memory region");


/*
 *
 * Basic error types
 */

		TEP(file_name,function_name,line_no,DRIVER_MEMORY_NOT_AVAILABLE,"DRIVER_MEMORY_NOT_AVAILABLE",		\
				"Memory size wish to allocate is not available, please increase the memory size");


#if 0


		TEP(file_name,function_name,line_no,,"",								\
				"");

		TEP(file_name,function_name,line_no,,"",								\
				"");

		TEP(file_name,function_name,line_no,,"",								\
				"");
#endif
/*
 * Unknown error 
 */
		TEP_DEFAULT(file_name,function_name,line_no,"UN KNOWN ERROR",						\
				"An unidentified error is happening.. please report to code developer!");
	}
}

