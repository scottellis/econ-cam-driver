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

/*
 * Include Header file
 */

#include "../../../inc_header.h"

/*
 * Global variables
 */
static DEFINE_MUTEX(phy_memory_mutex);
static UINT32 phy_addr_start	= DISABLE;
static UINT32 phy_addr_end	= DISABLE;

/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	:	
 *
 *  Name	:	
 *
 *  Parameter1	:	
 *
 *  Returns	:	FNRESLT
 *  Description	: 	 
 *  Comments	:  				 	
 *
 ************************************************************************************************************/
FNRESLT get_mem_node(struct dma_memory **phy_mem ,UINT8 cond)
{
	static UINT32 phy_mem_res;

	switch(cond)
	{
		case GET_MEM_NODE:
		{
			if(phy_mem == NULL)
			{
				TRACE_ERR_AND_RET(FAIL);
			}
	
			if(phy_mem_res)
			{
				*phy_mem	= (struct dma_memory *)phy_mem_res;
			}
		}break;
	
		case SET_MEM_NODE:
		{
			phy_mem_res = (UINT32)*phy_mem;
		}break;
	}

	return SUCCESS;
}

/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	:	
 *
 *  Name	:	
 *
 *  Parameter1	:	
 *
 *  Returns	:	FNRESLT
 *  Description	: 	 
 *  Comments	:  				 	
 *
 ************************************************************************************************************/
FNRESLT list_all_phy_struct()
{
	struct dma_memory *phy_mem	= NULL;
	struct dma_memory *phy_mem_next	= NULL;
	FNRESLT ret_val;
	UINT32 i;

	ret_val	= get_mem_node(&phy_mem,GET_MEM_NODE);
	if(CHECK_IN_FAIL_LIMIT(ret_val))
	{
		return ret_val;
	}

	printk("\n\n\nMem.no             Memstart                    Memend            Virtual address       Size\n");
	for(i	= 0;phy_mem;i++)
	{
		phy_mem_next = phy_mem->next;
		printk("%d                 0x%x                  0x%x        0x%x         0x%x          0x%x  0x%x\n",	\
			i,(UINT32)phy_mem->address_start,(UINT32)phy_mem->address_end,(UINT32)phy_mem->virtual_address,	\
			(UINT32)phy_mem->size,(UINT32)phy_mem,(UINT32)phy_mem_next);
		phy_mem	= phy_mem_next;
	}

	return SUCCESS;
}
EXPORT_SYMBOL(list_all_phy_struct);

/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	:	
 *
 *  Name	:	
 *
 *  Parameter1	:	
 *
 *  Returns	:	FNRESLT
 *  Description	: 	 
 *  Comments	:  				 	
 *
 ************************************************************************************************************/

FNRESLT get_free_phy_mem(UINT32 size,UPINT32 phy_addr,UPINT32 vir_addr)
{
	UINT32 addr_start		= phy_addr_start;
	UINT32 addr_end			= phy_addr_end;
	UINT32 mem_fnode_st;
	UINT8 mem_fnode_flag		= DISABLE;

	FNRESLT ret_val;

	struct dma_memory *phy_mem	= NULL;
	struct dma_memory *phy_mem_next	= NULL;
	struct dma_memory *phy_new;
	UINT32 case_link;

	mutex_lock(&phy_memory_mutex);
	{

		ret_val	= get_mem_node(&phy_mem,GET_MEM_NODE);
		if(CHECK_IN_FAIL_LIMIT(ret_val))
		{
			{
			}mutex_unlock(&phy_memory_mutex);

			return ret_val;
		}

//-----------------------------------------------------------------------------------------------------
		if(addr_start&0xFFF)
		{
			addr_start	= addr_start + (0x1000 - (addr_start&0xFFF));
		}
//-----------------------------------------------------------------------------------------------------

		if(phy_mem)
		{
			mem_fnode_st		= phy_mem->address_start -1;
			if((mem_fnode_st > addr_start) && ((mem_fnode_st - addr_start) > size))
			{
				mem_fnode_flag = ENABLE;
			}
		}

		for(;(phy_mem != NULL) && (mem_fnode_flag == DISABLE);)
		{
	
			phy_mem_next		= phy_mem->next;
			addr_start		= phy_mem->address_end +1;
		
			if(phy_mem_next)
			{
				addr_end	= phy_mem_next->address_start;
			}else
			{
				addr_end	= phy_addr_end;
			}
//-----------------------------------------------------------------------------------------------------
			if(addr_start&0xFFF)
			{
				addr_start	= addr_start + (0x1000 - (addr_start&0xFFF));
			}
//-----------------------------------------------------------------------------------------------------
			if((addr_end > addr_start) && ((addr_end - addr_start) > size))
			{
				break;
			}else if(phy_mem_next)
			{
				phy_mem		= phy_mem_next;
			}else
			{
				list_all_phy_struct();
				TRACE_ERR_AND_RET(FAIL);
			}
		}

		if(mem_fnode_flag)
		{	
			case_link	= 4;
		}else 
		{
			if(phy_mem)
			{
				if((phy_mem) && (phy_mem->next))
				{
				case_link	= 1;
				}else
				{
					case_link	= 2;
				}

			}else
			{
				case_link	= 3;
			}
		}

		phy_new	= kmalloc(sizeof(struct dma_memory),GFP_KERNEL);		
		if(phy_new == NULL)
		{
			TRACE_ERR_AND_RET(FAIL);
		}
		memset(phy_new,0x00,sizeof(struct dma_memory));
	
		switch(case_link)
		{
			case 4:
			{
				phy_mem->back		= phy_new;
				phy_new->back		= NULL;
				phy_new->next		= phy_mem;
				get_mem_node(&phy_new,SET_MEM_NODE);
			
			}break;
			case 3:
			{
				phy_mem			= phy_new;
				phy_mem->next		= NULL;
				phy_mem->back		= NULL;
				get_mem_node(&phy_mem,SET_MEM_NODE);

				break;
			}
			case 2:
			{
				phy_new->next		= NULL;
				phy_new->back		= phy_mem;
				phy_mem->next		= phy_new;
				break;
			}
			case 1:
			{
				phy_new->next		= phy_mem->next;
				phy_new->back		= phy_mem;
				phy_mem->next->back	= phy_new;
				phy_mem->next		= phy_new;
				break;
			}
		}
	
		phy_new->address_start			= addr_start;
		phy_new->address_end			= phy_new->address_start+size-1;
		phy_new->size				= size;
		phy_new->virtual_address		= (UINT32)ioremap(addr_start,size);

		if(vir_addr)
		{
			*vir_addr			= phy_new->virtual_address;
		}

		if(phy_addr)
		{
			*phy_addr			= phy_new->address_start;
		}
	}mutex_unlock(&phy_memory_mutex);

	return SUCCESS;
}
EXPORT_SYMBOL(get_free_phy_mem);

/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	:	
 *
 *  Name	:	
 *
 *  Parameter1	:	INT0
 *
 *  Returns	:	FNRESLT
 *  Description	: 	 
 *  Comments	:  				 	
 *
 ************************************************************************************************************/
FNRESLT get_adress(UPINT32 phy_addr,UPINT32 vir_addr, UPINT32 addr)
{
	FNRESLT ret_val;
	struct dma_memory *phy_mem	= NULL;

	*addr	= DISABLE;

	mutex_lock(&phy_memory_mutex);
	{
		ret_val	= get_mem_node(&phy_mem,GET_MEM_NODE);
		if(CHECK_IN_FAIL_LIMIT(ret_val))
		{
			{
			}mutex_unlock(&phy_memory_mutex);

			return ret_val;
		}

		for(;phy_mem;)
		{
			if(phy_addr)
			{
				if(phy_addr	== (UPINT32)phy_mem->address_start)
				{
					*addr	= phy_mem->virtual_address;
					break;
				}
			}
			if(vir_addr)
			{
				if(vir_addr	== (UPINT32)phy_mem->virtual_address)
				{
					*addr	= phy_mem->address_start;				
					break;
				}
			}

			phy_mem		= phy_mem->next;
		}

		if(*addr	== DISABLE)
		{
			printk(KERN_ERR"\n" KERN_ERR "Memory Invalid : physical memory not allocated from phy_mem\n");
			list_all_phy_struct();
			{
			}mutex_unlock(&phy_memory_mutex);

			TRACE_ERR_AND_RET(FAIL);
		}
	}mutex_unlock(&phy_memory_mutex);

	return SUCCESS;
}
EXPORT_SYMBOL(get_adress);

/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	:	
 *
 *  Name	:	
 *
 *  Parameter1	:	INT0
 *
 *  Returns	:	FNRESLT
 *  Description	: 	 
 *  Comments	:  				 	
 *
 ************************************************************************************************************/

FNRESLT free_phy_mem(UINT32 phy_addr)
{
	struct dma_memory *phy_mem	= NULL;
	struct dma_memory *phy_mem_last	= NULL;
	FNRESLT ret_val;

	mutex_lock(&phy_memory_mutex);
	{
		ret_val	= get_mem_node(&phy_mem,GET_MEM_NODE);
		if(CHECK_IN_FAIL_LIMIT(ret_val))
		{
			{
			}mutex_unlock(&phy_memory_mutex);
			
			return ret_val;
		}


		for(;phy_mem;)
		{
			if(phy_addr	== phy_mem->address_start)
			{
				break;
			}else
			{
				phy_mem		= phy_mem->next;
			}
		}
		if(phy_mem)
		{
	
			if(phy_mem->next)
			{
				phy_mem->next->back	= phy_mem->back;
				phy_mem_last		= phy_mem->next;
			}

			if(phy_mem->back)
			{
				phy_mem->back->next	= phy_mem->next;
				iounmap((PINT0)phy_mem->virtual_address);
				kfree(phy_mem);
			}else
			{
			
				ret_val	= get_mem_node(&phy_mem,GET_MEM_NODE);
				if(CHECK_IN_FAIL_LIMIT(ret_val))
				{
					{
					}mutex_unlock(&phy_memory_mutex);
	
					return ret_val;
				}

				iounmap((PINT0)phy_mem->virtual_address);
				kfree(phy_mem);

				if(phy_mem_last)
				{
					phy_mem	= phy_mem_last;
					ret_val	= get_mem_node(&phy_mem,SET_MEM_NODE);
					if(CHECK_IN_FAIL_LIMIT(ret_val))
					{
						{
						}mutex_unlock(&phy_memory_mutex);

						return ret_val;
					}
	
				}else
				{
					phy_mem	= NULL;			
					ret_val	= get_mem_node(&phy_mem,SET_MEM_NODE);
					if(CHECK_IN_FAIL_LIMIT(ret_val))
					{
						{
						}mutex_unlock(&phy_memory_mutex);
						return ret_val;
					}
				}
			}

		}else
		{
			TRACE_ERR_AND_RET(FAIL);
		}
	}mutex_unlock(&phy_memory_mutex);

	return SUCCESS;
}
EXPORT_SYMBOL(free_phy_mem);

/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	:	
 *
 *  Name	:	
 *
 *  Parameter1	:	INT0
 *
 *  Returns	:	FNRESLT
 *  Description	: 	 
 *  Comments	:  				 	
 *
 ************************************************************************************************************/
FNRESLT free_all_phy_struct()
{
	struct dma_memory *phy_mem	= NULL;
	struct dma_memory *phy_mem_next	= NULL;
	FNRESLT ret_val;

	mutex_lock(&phy_memory_mutex);
	{
		ret_val	= get_mem_node(&phy_mem,GET_MEM_NODE);
		if(CHECK_IN_FAIL_LIMIT(ret_val))
		{
			{
			}mutex_unlock(&phy_memory_mutex);
			return ret_val;
		}

		for(;phy_mem;)
		{
			phy_mem_next = phy_mem->next;

			iounmap((PINT0)phy_mem->virtual_address);
			kfree(phy_mem);

			phy_mem	= phy_mem_next;
		}

		phy_mem	= NULL;
		ret_val	= get_mem_node(&phy_mem,SET_MEM_NODE);
		if(CHECK_IN_FAIL_LIMIT(ret_val))
		{
			{
			}mutex_unlock(&phy_memory_mutex);

			return ret_val;
		}
	
	}mutex_unlock(&phy_memory_mutex);


	return SUCCESS;
}
EXPORT_SYMBOL(free_all_phy_struct);

/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	:	
 *
 *  Name	:	
 *
 *  Parameter1	:	
 *
 *  Returns	:	FNRESLT
 *  Description	: 	 
 *  Comments	:  				 	
 *
 ************************************************************************************************************/
FNRESLT init_phy_mem()
{
	UINT32 phys_end_kernel;

	if((phy_addr_start	== DISABLE) && (phy_addr_end == DISABLE))
	{
		phy_addr_start	= PHY_MEM_START;
		phy_addr_end	= PHY_MEM_END;

	}
/*
 * Find the kernel memory range
 */
	phys_end_kernel = (UINT32)virt_to_phys((PINT0)PAGE_OFFSET) +(num_physpages << PAGE_SHIFT);
	if(phys_end_kernel > phy_addr_start)
	{
		printk(KERN_INFO "\n");
		printk(KERN_INFO "Memory overlap detected between camera reserved memory and kernel memory\n");
		printk(KERN_INFO "phy_addr_start  0x%x \n",phy_addr_start);
		printk(KERN_INFO "phy_addr_end    0x%x \n",phy_addr_end);
		printk(KERN_INFO "phys_end_kernel 0x%x \n",phys_end_kernel);
		printk(KERN_INFO "\n");


#ifndef CONFIG_ALLOW_DRIVER_PHY_MEMORY_OVERLAP
		TRACE_ERR_AND_RET(MEM_KERN_OVERLAP);
#endif
	}

	printk(KERN_INFO "Using Reserved memory for " MODULE_NAME "\n");
	printk(KERN_INFO "From Start address - 0x%08x \n",phy_addr_start);
	printk(KERN_INFO "To End address - 0x%08x \n",phy_addr_end);

	return SUCCESS;
}

/************************************************************************************************************
 *  
 *  MODULE TYPE	:	FUNCTION				MODULE ID	:	
 *
 *  Name	:	
 *
 *  Parameter1	:	
 *
 *  Returns	:	FNRESLT
 *  Description	: 	 
 *  Comments	:  				 	
 *
 ************************************************************************************************************/
FNRESLT exit_phy_mem()
{
	FNRESLT ret_val;
	ret_val	= free_all_phy_struct();
	if(CHECK_IN_FAIL_LIMIT(ret_val))
	{
		return FAIL;
	}

	return SUCCESS;
}

module_param(phy_addr_start,int, 0444);
module_param(phy_addr_end,int, 0444);
