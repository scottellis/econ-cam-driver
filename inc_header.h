/**********************************************************************************************************
 *   Copyright (C) 2009 by e-con Systems.                                                                 *
 *   www.e-consystems.com                                                                                 *
 *                                                                                                        *
 *   This file is licensed under the terms of the GNU General Public License                              *
 *   version 2. This program is licensed "as is" without any warranty of any                              *
 *   kind, whether express or implied.                                                                    *
 *                                                                                                        *
 *                                                                                                        *
 *   PROJECT	           :        OMAP Camera development                                               *
 *   MODULE NAME           :                                                                              *
 *   MODULE VERSION        :        VER 3.0                                                               *
 *                                                                                                        *
 *                                                                                                        *
 *                                                                                                        *
 *   Version No	: 000-0001                                                          CODE_REV  : 0.0.1.1   *
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
 * 3.0       Flash support added  
 *==========================================================================================================
 */

/*
 * Modified version:
 * etc/rc5.d/S30gstti-init
 *
 * # Start Addr    Size    Description
 * # -------------------------------------------
 * # 0x80000000    93 MB   Linux
 * # 0x85D00000     6 MB   e-con camera
 * # 0x86300000    16 MB   CMEM
 * # 0x87300000    13 MB   CODEC SERVER
 */

#define CONFIG_RAM_SIZE_IN_MB			256
/* #define CONFIG_CMEM_DRIVER_AVAILABLE */
#define CONFIG_ALLOW_DRIVER_PHY_MEMORY_OVERLAP

#define PHY_MEM_HIGH_ALLOCATE_IN_MB		6

#if (CONFIG_RAM_SIZE_IN_MB == 128)

	#if defined(CONFIG_CMEM_DRIVER_AVAILABLE)
		#define PHY_MEM_END		0x862FFFFF	// start address is 0x85D0_0000  @ 6M
	#else
		#define PHY_MEM_END		0x87FFFFFF
	#endif
	
#elif (CONFIG_RAM_SIZE_IN_MB == 256)

	#if defined(CONFIG_CMEM_DRIVER_AVAILABLE)
		#define PHY_MEM_END		0x862FFFFF	// start address is 0x85D0_0000  @ 6M
	#else
		#define PHY_MEM_END		0x8FFFFFFF
	#endif

#endif

#define PHY_MEM_START				(PHY_MEM_END - ((PHY_MEM_HIGH_ALLOCATE_IN_MB * 1024 * 1024)-1))

#define STILL_IMAGE_CAPTURE_FRAME_NUMBER	3


/*
 * Define the Include header file Macro
 */
#define MODULE_NAME	"V4l2 driver module"
#define VERSION_NO	"5.0"

#define CONFIG_DRIVER
#define USE_KERNEL_THREAD
#define KERNEL_ARM_OMAP
#define KERNEL_ARM_OMAP3530
#define USE_KERNEL_MEMORY_MANAGE
#define CONFIG_KERNEL_ERR_INCLUDED

#include "Headerfile.h"

/*
 * driver specific header files
 */

#include <media/v4l2-dev.h>
#include <mach/gpio.h>
#include <media/v4l2-ioctl.h>

/*
 * Include module specific code here
 */
#include "omap_camera_interface.h"
#include "isp.h"
#include "v4l2_driver_base.h"
#include "omap_v4l2.h"

/*
 * include the sensor file
 */
#undef CONFIG_CTRL_FRAME_RATE_FRM_SENSOR
#include "sens_ov3640.h"

/*
 * include Flash related header file
 */
#undef CONFIG_HAVE_LED_FLASH
#if defined(CONFIG_HAVE_LED_FLASH)
	#include "lm3553_flash.h"
#endif
/*
 * Include function protype here
 */

#include "fn_protype.h"
