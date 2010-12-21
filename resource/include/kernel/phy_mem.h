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

#define GET_MEM_NODE				0x01
#define SET_MEM_NODE				0x02

#define ENABLE					0x1
#define DISABLE					0x0

struct dma_memory
{
	struct dma_memory *next;

	UINT32 size;

	UINT32 virtual_address;
	UINT32 address_start;

	UINT32 address_end;

	struct dma_memory *back;
};

#endif
