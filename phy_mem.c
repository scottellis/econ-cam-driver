/**********************************************************************************************************
 *   Copyright (C) 2007 by e-con Systems.                                                                 *
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

#include <linux/types.h>

#include "inc_header.h"

#define GET_MEM_NODE				0x01
#define SET_MEM_NODE				0x02


static DEFINE_MUTEX(phy_memory_mutex);
static u32 phy_addr_start;
static u32 phy_addr_end;
static u32 phy_mem_res;

static void get_mem_node(struct dma_memory **phy_mem, u8 cond)
{
	switch (cond) {
	case GET_MEM_NODE:
		if (phy_mem_res)
			*phy_mem = (struct dma_memory *) phy_mem_res;
		
		break;
	
	case SET_MEM_NODE:
		phy_mem_res = (u32) *phy_mem;
		break;
	}
}

static int list_all_phy_struct(void)
{
	struct dma_memory *phy_mem = NULL;

	get_mem_node(&phy_mem, GET_MEM_NODE);

	printk("\n\n\nMemstart                    Memend" \
		"           Virtual address       Size\n");

	while (phy_mem) {
		printk("0x%x                  0x%x" \
			"        0x%x         0x%x          0x%x  0x%x\n",
			(u32)phy_mem->address_start,
			(u32)phy_mem->address_end,
			(u32)phy_mem->virtual_address,
			(u32)phy_mem->size,
			(u32)phy_mem,
			(u32)phy_mem->next);

		phy_mem	= phy_mem->next;
	}

	return 0;
}

int get_free_phy_mem(u32 size, u32 *phy_addr, u32 *vir_addr)
{
	u32 addr_start = phy_addr_start;
	u32 addr_end = phy_addr_end;
	u32 mem_fnode_st;
	u8 mem_fnode_flag = 0;
	struct dma_memory *phy_mem = NULL;
	struct dma_memory *phy_mem_next	= NULL;
	struct dma_memory *phy_new;
	u32 case_link;

	mutex_lock(&phy_memory_mutex);

	get_mem_node(&phy_mem, GET_MEM_NODE);
		
	if (addr_start & 0xFFF)
		addr_start = addr_start + (0x1000 - (addr_start & 0xFFF));
	
	if (phy_mem) {
		mem_fnode_st = phy_mem->address_start - 1;

		if (mem_fnode_st > addr_start && 
					(mem_fnode_st - addr_start) > size)
			mem_fnode_flag = 1;
	}

	if (!mem_fnode_flag) {
		while (phy_mem) {
			phy_mem_next = phy_mem->next;
			addr_start = phy_mem->address_end + 1;
	
			if (phy_mem_next)
				addr_end = phy_mem_next->address_start;
			else
				addr_end = phy_addr_end;

			if (addr_start & 0xFFF)
				addr_start = addr_start + 
						(0x1000 - (addr_start & 0xFFF));

			if (addr_end > addr_start && 
					(addr_end - addr_start) > size) {
				break;
			} 
			else if (phy_mem_next) {
				phy_mem	= phy_mem_next;
			} 
			else {
				list_all_phy_struct();
				mutex_unlock(&phy_memory_mutex);
				return -ENOMEM;
			}
		}
	}

	if (mem_fnode_flag) {	
		case_link = 4;
	}
	else if (phy_mem) {
		if (phy_mem->next)
			case_link = 1;
		else
			case_link = 2;
	}
	else {
		case_link = 3;
	}

	phy_new	= kmalloc(sizeof(struct dma_memory), GFP_KERNEL);

	if (phy_new == NULL) {
		mutex_unlock(&phy_memory_mutex);
		return -ENOMEM;
	}

	memset(phy_new, 0x00, sizeof(struct dma_memory));

	switch (case_link) {
	case 4:
		phy_mem->back = phy_new;
		phy_new->back = NULL;
		phy_new->next = phy_mem;
		get_mem_node(&phy_new, SET_MEM_NODE);
		break;
	case 3:
		phy_mem	= phy_new;
		phy_mem->next = NULL;
		phy_mem->back = NULL;
		get_mem_node(&phy_mem, SET_MEM_NODE);
		break;
	case 2:
		phy_new->next = NULL;
		phy_new->back = phy_mem;
		phy_mem->next = phy_new;
		break;
	case 1:
		phy_new->next = phy_mem->next;
		phy_new->back = phy_mem;
		phy_mem->next->back = phy_new;
		phy_mem->next = phy_new;
		break;
	}

	phy_new->address_start = addr_start;
	phy_new->address_end = phy_new->address_start + size - 1;
	phy_new->size = size;
	phy_new->virtual_address = (u32) ioremap(addr_start, size);

	if (vir_addr)
		*vir_addr = phy_new->virtual_address;

	if (phy_addr)
		*phy_addr = phy_new->address_start;

	mutex_unlock(&phy_memory_mutex);

	return 0;
}

int free_phy_mem(u32 phy_addr)
{
	struct dma_memory *phy_mem = NULL;
	struct dma_memory *phy_mem_last	= NULL;
	
	mutex_lock(&phy_memory_mutex);

	get_mem_node(&phy_mem, GET_MEM_NODE);
	
	while (phy_mem) {
		if (phy_addr == phy_mem->address_start) 
			break;

		phy_mem	= phy_mem->next;
	}

	if (phy_mem) {
		if (phy_mem->next) {
			phy_mem->next->back = phy_mem->back;
			phy_mem_last = phy_mem->next;
		}

		if (phy_mem->back) {
			phy_mem->back->next = phy_mem->next;
			iounmap((void *)phy_mem->virtual_address);
			kfree(phy_mem);
		}
		else {
			get_mem_node(&phy_mem,GET_MEM_NODE);
			iounmap((PINT0)phy_mem->virtual_address);
			kfree(phy_mem);

			if (phy_mem_last) {
				phy_mem	= phy_mem_last;
				get_mem_node(&phy_mem, SET_MEM_NODE);			
			}
			else {
				phy_mem	= NULL;			
				get_mem_node(&phy_mem, SET_MEM_NODE);
			}
		}
	}
	else {
		return -ENOMEM;
	}
	
	mutex_unlock(&phy_memory_mutex);

	return 0;
}

int init_phy_mem()
{
	u32 phys_end_kernel;

	if (!phy_addr_start && !phy_addr_end) {
		phy_addr_start = PHY_MEM_START;
		phy_addr_end = PHY_MEM_END;
	}

	phys_end_kernel = (u32) virt_to_phys((void *)PAGE_OFFSET) 
				+ (num_physpages << PAGE_SHIFT);

	if (phys_end_kernel > phy_addr_start) {
		printk(KERN_INFO "\n");
		printk(KERN_INFO "Memory overlap detected between camera " \
				"reserved memory and kernel memory\n");
		printk(KERN_INFO "phy_addr_start  0x%x \n", phy_addr_start);
		printk(KERN_INFO "phy_addr_end    0x%x \n", phy_addr_end);
		printk(KERN_INFO "phys_end_kernel 0x%x \n", phys_end_kernel);
		printk(KERN_INFO "\n");

#ifndef CONFIG_ALLOW_DRIVER_PHY_MEMORY_OVERLAP
		return -1;
#endif
	}

	printk(KERN_INFO "Using Reserved memory for " MODULE_NAME "\n");
	printk(KERN_INFO "From Start address - 0x%08x \n", phy_addr_start);
	printk(KERN_INFO "To End address - 0x%08x \n", phy_addr_end);

	return 0;
}

module_param(phy_addr_start, int, 0444);
module_param(phy_addr_end, int, 0444);
