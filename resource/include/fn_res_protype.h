/**********************************************************************************************************
 *   Copyright (C) 2009 by e-con Systems                                                                  *
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

/*
 * *********************************************************************************************************
 *
 * 			FUNCTION PROTO TYPE USED IN THE RESOURCE PROJECT
 *
 * *********************************************************************************************************
 */

/*
 * common.c
 */

PINT0 map_kernel_space(ULINT32 physaddr, UINT32 size);
INT32 unmap_kernel_space(volatile PINT0 start, size_t length);
FNRESLT printstring(IN UPINT8 string,IN UINT32 string_length);

/*
 * error.c
 */

FNRESLT_NONE trace_error(PINT8 file_name,PINT8 function_name,UINT32 line_no,UINT32 Error_num);

/*
 * memory_monitor.c
 */

PINT0 wrapper_memory_api(UPINT8 function_name,UINT32 lineno,UDPINT32 address,UINT32 size,UINT32 block,UINT32 status);
FNRESLT check_pointer_availability(UPINT32 list_memory,UINT32 count,UPINT32 pointer,UPINT32 current_record);
FNRESLT maintain_log(UPINT8 function_name,UINT32 lineno,UDPINT32 pointer,UINT32 allocation_memory_size,UINT32 block_size,UINT32 status);

#if defined(CONFIG_DRIVER)
/*
 * phy_mem.c
 */
	FNRESLT list_all_phy_struct(INT0);
	FNRESLT free_all_phy_struct(INT0);
	FNRESLT free_phy_mem(UINT32 phy_addr);
	FNRESLT get_free_phy_mem(UINT32 size,UPINT32 phy_addr,UPINT32 vir_addr);
	FNRESLT init_phy_mem(INT0);
	FNRESLT exit_phy_mem(INT0);

#endif
