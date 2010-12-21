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
 * error.c
 */

void trace_error(char* file_name, char* function_name, u32 line_no, 
		u32 error_no);


#if defined(CONFIG_DRIVER)
/*
 * phy_mem.c
 */
int list_all_phy_struct(void);
int free_all_phy_struct(void);
int free_phy_mem(u32 phy_addr);
int get_free_phy_mem(u32 size, u32 *phy_addr, u32 *vir_addr);
int init_phy_mem(void);
int exit_phy_mem(void);

#endif
