/**********************************************************************************************************
 *   Copyright (C) 2007 by e-con Systems .                                                                *
 *   www.e-consystems.com                                                                                 *
 *                                                                                                        *
 *   This file is licensed under the terms of the GNU General Public License                              *
 *   version 2. This program is licensed "as is" without any warranty of any                              *
 *   kind, whether express or implied.                                                                    *
 *                                                                                                        *
 *                                                                                                        *
 *   PROJECT	           :        Memory Management in kernel level                                     *
 *   MODULE NAME           :                                                                              *
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
#ifndef __PHY_MEM_
#define __PHY_MEM_

struct dma_memory {
	struct dma_memory *next;
	UINT32 size;
	UINT32 virtual_address;
	UINT32 address_start;
	UINT32 address_end;
	struct dma_memory *back;
};

int free_phy_mem(u32 phy_addr);
int get_free_phy_mem(u32 size, u32 *phy_addr, u32 *vir_addr);
int init_phy_mem(void);

#endif
