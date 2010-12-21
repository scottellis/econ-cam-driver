/**********************************************************************************************************
 *   Copyright (C) 2009 by e-con Systems.                                                                *
 *   www.e-consystems.com                                                                                 *
 *                                                                                                        *
 *   This file is licensed under the terms of the GNU General Public License                              *
 *   version 2. This program is licensed "as is" without any warranty of any                              *
 *   kind, whether express or implied.                                                                    *
 *                                                                                                        *
 *                                                                                                        *
 *   PROJECT	           :        Defined variable types                                                *
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
 *		Char
 */

typedef char			INT8;
typedef unsigned char		UINT8;
typedef signed char		SINT8;

typedef char*			PINT8;
typedef unsigned char*		UPINT8;
typedef signed char*		SPINT8;

typedef char**			DPINT8;
typedef unsigned char**		UDPINT8;
typedef signed char**		SDPINT8;
typedef const char*		CPINT8;

typedef UINT8			BOOL;

/*
 * 		Int
 */
typedef int			INT32;
typedef unsigned int		UINT32;
typedef signed int		SINT32;

typedef int*			PINT32;
typedef unsigned int*		UPINT32;
typedef signed int*		SPINT32;

typedef int**			DPINT32;
typedef unsigned int**		UDPINT32;
typedef signed int**		SDPINT32;

typedef volatile unsigned int	UVINT32;
typedef INT32			FNRESLT;


/*
 *	Long
 */

typedef long			LINT32;
typedef unsigned long		ULINT32;
/*
 *	long long int
 */
typedef long long int		INT64;
typedef long long int*		PINT64;
typedef unsigned long long int	UINT64;
typedef unsigned long long int* UPINT64;

/*
 *		short
 */
typedef short			INT16;
typedef unsigned short		UINT16;
typedef signed short		SINT16;

typedef short*			PINT16;
typedef unsigned short*		UPINT16;
typedef signed short*		SPINT16;

typedef short**			DPINT16;
typedef unsigned short**	UDPINT16;
typedef signed short**		SDPINT16;

typedef volatile unsigned short	UVINT16;


/*
 *		void
 */
typedef void			INT0;
typedef void*			PINT0;
typedef void**			DPINT0;
typedef INT0			FNRESLT_NONE;

typedef unsigned short 		WORD;
typedef unsigned int		DWORD;
typedef int 			LONG;

/*
 * 		float
 */


