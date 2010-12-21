/**********************************************************************************************************
 *   Copyright (C) 2007 by e-con Systems.                                                                 *
 *   www.e-consystems.com                                                                                 *
 *                                                                                                        *
 *   This file is licensed under the terms of the GNU General Public License                              *
 *   version 2. This program is licensed "as is" without any warranty of any                              *
 *   kind, whether express or implied.                                                                    *
 *                                                                                                        *
 *                                                                                                        *
 *   PROJECT	           :      Gendral Header file incluton                                            *
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
 * Custom header file
 */
#include "typedef.h"


/*
 * Application Part Header 
 */


#ifdef CONFIG_APPLICATION
/*
 * Standard Header file
 */

	#ifdef HAVE_CONFIG_H
		#include <config.h>
	#endif

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <fcntl.h>
	#include <termios.h>
	#include <unistd.h>

	#include <sys/types.h>
	#include <sys/stat.h>
	#include <sys/time.h>
	#include <sys/ioctl.h>
	#include <sys/mman.h>

/*
 * include custom header file
 */
	#ifdef HAVE_IOCTL_DEF 
		#include "ioctls_def.h"
	#endif
#endif

/*
 * Driver Part Header file 
 */
#ifdef CONFIG_DRIVER
	#include <linux/init.h>
	#include <linux/module.h>
	#include <linux/kernel.h> 		// printk() 
	#include <linux/slab.h> 		// kmalloc() 
	#include <linux/fs.h> 			// everything\ldots{} 
	#include <linux/errno.h> 		// error codes 
	#include <linux/types.h> 		// size_t 
	#include <linux/proc_fs.h>
	#include <linux/fcntl.h>		// O_ACCMODE 
	#include <linux/ioport.h>
	#include <asm/system.h>			// cli(), *_flags 
	#include <asm/uaccess.h>		// copy_from/to_user 
	#include <asm/io.h>			// inb, outb 
	#include <linux/interrupt.h>
	#include <linux/types.h>
	#include <asm/types.h>
	#include <linux/delay.h>		// for udelay()
	#include <asm/delay.h>
	#include <linux/unistd.h>
	#include <linux/device.h>
	#include <asm/dma.h>
	#include <linux/version.h>
	#include <linux/i2c.h>
	#include <linux/platform_device.h>
	#include <linux/clk.h>
	#include <linux/page-flags.h>
	#include<linux/mm.h>

	#ifdef USE_KERNEL_MEMORY_MANAGE
		#include "phy_mem.h"
	#endif

	#ifdef USE_KERNEL_THREAD
		#include <linux/kthread.h>
		#include <linux/mutex.h>
	#endif

	#ifdef KERNEL_ARM_PXA270
		#include <asm/arch/pxa-regs.h>
		#include <asm/arch/irqs.h>
		#include <asm-arm/arch-pxa/dma.h>
		#include <asm-arm/page.h>

		#ifdef CONFIG_KERNEL_2_6_15_2
			#include <linux/config.h>
		#else
			#include <linux/autoconf.h>
		#endif

	#endif

	#ifdef KERNEL_ARM_OMAP
		#ifdef KERNEL_ARM_OMAP3530
		#endif
	#endif

	#ifdef KERNEL_ARM_IMX31
		#ifdef CONFIG_KERNEL_2_6_19_2
		#endif

		#ifdef CONFIG_KERNEL_2_6_22
			#include <asm/arch/mx31_pins.h>
			
			#ifndef __MACH_MX31_IOMUX_H__
				#define __MACH_MX31_IOMUX_H__
			#endif
			#include <asm/arch/mxc_i2c.h>
			#include <asm/arch/pmic_power.h>
			
		#endif
	#endif
#endif

/*
 * boot loader part header file
 */
#if defined(CONFIG_BOOT_LOADER)
	#if defined(CONFIG_BOOT_UBOOT_1_1_3)
		#include <common.h>
		#include <command.h>
		#include <asm/io.h>
		#include <asm/arch/hardware.h> 
		#include <asm/sizes.h>
		#include <malloc.h>

	#endif
#endif

/*
 * custom definition here
 */
#define OUT
#define IN

#define DISABLE		0x0
#define ENABLE		0x1


/*
 * include custom header file
 */
#include "error.h"

#ifdef CONFIG_USE_MEMORY_MONITOR
	#include "memory_monitor.h"

	#define malloc(alloc_size) 									\
			wrapper_memory_api((UPINT8)__FUNCTION__,__LINE__,				\
			NULL,alloc_size,1,MALLOC_MEMORY)

	#define calloc(alloc_size,alloc_block) 								\
			wrapper_memory_api((UPINT8)__FUNCTION__,__LINE__,				\
			NULL,alloc_size,alloc_block,CALLOC_MEMORY);

	#define realloc(ptr,alloc_size) 								\
			wrapper_memory_api((UPINT8)__FUNCTION__,__LINE__,				\
			(UDPINT32)&ptr,alloc_size,1,REALLOC_MEMORY);

	#define free(address) 										\
			wrapper_memory_api((UPINT8)__FUNCTION__,__LINE__,				\
			(UDPINT32)&address,0,0,FREE_MEMORY);
#endif

#include "fn_res_protype.h"

#if defined(CONFIG_RETURN_APPLICATION_DEBUG)
	#define return  										\
	{												\
		TRACE_ERROR(ret_val);									\
		#if defined(CONFIG_APPLICATION_TRACE)							\
		{											\
		}											\
		#endif											\
	}return	
#endif

#define ENABLED			0x01
#define DISABLED		0x00

#define SET_ADDRESS 		0x01
#define GET_ADDRESS 		0x02
#define MAKE_ADDRESS_INVALID	0x04
#define CREATE_ADDRESS		0x08
