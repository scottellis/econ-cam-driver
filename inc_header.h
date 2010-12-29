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
 * 128 MB Gumstix u-boot arg: mem=122M@0x80000000
 * # Start Addr    Size    Description
 * # -------------------------------------------
 * # 0x80000000    122 MB   Linux
 * # 0x87A00000      6 MB   e-con camera
 *
 * 256 MB Gumstix u-boot arg: mem=250M@0x80000000
 * # Start Addr    Size    Description
 * # -------------------------------------------
 * # 0x80000000   250 MB   Linux
 * # 0x8FA00000     6 MB   e-con camera
 *
 * 512 MB Gumstix u-boot arg: mem=506M@0x80000000
 * # Start Addr    Size    Description
 * # -------------------------------------------
 * # 0x80000000   506 MB   Linux
 * # 0x9FA00000     6 MB   e-con camera
 *
 * I haven't tried a CODEC SERVER yet, so I'll defer these until later.
 *
 * 128 MB Gumstix with CMEM/CODEC SERVER
 * # Start Addr    Size    Description
 * # -------------------------------------------
 * # 0x80000000    93 MB   Linux
 * # 0x85D00000     6 MB   e-con camera
 * # 0x86300000    16 MB   CMEM
 * # 0x87300000    13 MB   CODEC SERVER
 *
 */

#define CONFIG_RAM_SIZE_IN_MB	256
/* #define CONFIG_CMEM_DRIVER_AVAILABLE */
#define CONFIG_ALLOW_DRIVER_PHY_MEMORY_OVERLAP

#define PHY_MEM_ALLOC_IN_MB 	6

#if (CONFIG_RAM_SIZE_IN_MB == 128)

	#if defined(CONFIG_CMEM_DRIVER_AVAILABLE)
		#define PHY_MEM_END		0x862FFFFF	
	#else
		#define PHY_MEM_END		0x87FFFFFF
	#endif
	
#elif (CONFIG_RAM_SIZE_IN_MB == 256)

	#if defined(CONFIG_CMEM_DRIVER_AVAILABLE)
		#define PHY_MEM_END		0x862FFFFF
	#else
		#define PHY_MEM_END		0x8FFFFFFF
	#endif

#elif (CONFIG_RAME_SIZE_IN_MB == 512)

	#if defined(CONFIG_CMEM_DRIVER_AVAILABLE)
		#define PHY_MEM_END		0x862FFFFF
	#else
		#define PHY_MEM_END		0x9FFFFFFF
	#endif

#endif

#define PHY_MEM_START	(PHY_MEM_END - ((PHY_MEM_ALLOC_IN_MB * 1024 * 1024)-1))

#define STILL_IMAGE_CAPTURE_FRAME_NUMBER	3


#define MODULE_NAME	"V4l2 driver module"
#define VERSION_NO	"5.0"


#define USE_KERNEL_THREAD
#define USE_KERNEL_MEMORY_MANAGE
#define CONFIG_KERNEL_ERR_INCLUDED


