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

#include "typedef.h"
#include "error.h"

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


	#ifdef KERNEL_ARM_OMAP
		#ifdef KERNEL_ARM_OMAP3530
		#endif
	#endif

#endif


/*
 * custom definition here
 */
#define OUT
#define IN

#define DISABLE		0x0
#define ENABLE		0x1

#define ENABLED			0x01
#define DISABLED		0x00

#define SET_ADDRESS 		0x01
#define GET_ADDRESS 		0x02
#define MAKE_ADDRESS_INVALID	0x04
#define CREATE_ADDRESS		0x08
