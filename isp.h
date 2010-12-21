/**********************************************************************************************************
 *   Copyright (C) 2007 by e-con Systems.                                                                 *
 *   www.e-consystems.com                                                                                 *
 *                                                                                                        *
 *   This file is licensed under the terms of the GNU General Public License                              *
 *   version 2. This program is licensed "as is" without any warranty of any                              *
 *   kind, whether express or implied.                                                                    *
 *                                                                                                        *
 *                                                                                                        *
 *   PROJECT	           :        OMAP Camera development                                               *
 *   MODULE NAME           :        OV3640                                                                *
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
 * Values for the isp structure members
 */
#define ISPM_ISP_CTRL_MEM_ORDER_MSB_LSB			3
#define ISPM_ISP_CTRL_MEM_ORDER_LSB_MSB			2

#define ISP_CCDC_CCDC_SYNC_MODE_IMPMOD_RAW_DATA		0
#define ISP_CCDC_CCDC_SYNC_MODE_IMPMOD_YUV_16BIT	1

#define ISPM_ISP_CTRL_SYNC_DETECT_HS_FALL		0
#define ISPM_ISP_CTRL_SYNC_DETECT_HS_RISE		1
#define ISPM_ISP_CTRL_SYNC_DETECT_VS_FALL		2
#define ISPM_ISP_CTRL_SYNC_DETECT_VS_RISE		3

#define ISPM_ISP_CTRL_BIT_SHIFT_CAMEXT13_0_CAM13_0	0
#define ISPM_ISP_CTRL_BIT_SHIFT_CAMEXT13_2_CAM11_0	1
#define ISPM_ISP_CTRL_BIT_SHIFT_CAMEXT13_4_CAM9_0	2
#define ISPM_ISP_CTRL_BIT_SHIFT_CAMEXT13_6_CAM7_0	3

/*
 * structure definition
 */

#define MAP_ISP_REGION			0x2000	
#define BADDR_ISP			0x480BC000
#define BADDR_ISP_CBUFF			0x480BC100
#define BADDR_ISP_CCDC			0x480BC600
#define BADDR_ISP_HIST			0x480BCA00
#define BADDR_ISP_H3A			0x480BCC00
#define BADDR_ISP_PREVIEW		0x480BCE00
#define BADDR_ISP_RESIZER		0x480BD000
#define BADDR_ISP_SBL			0x480BD200
#define BADDR_ISP_SBL_END		0x480BD300

struct isp_irq
{
	UVINT32 reserved0				:8;
	UVINT32 ccdc_vd0_irq				:1;
	UVINT32 ccdc_vd1_irq				:1;
	UVINT32 ccdc_vd2_irq				:1;
	UVINT32 ccdc_err_irq				:1;
	UVINT32 h3a_af_done_irq				:1;
	UVINT32 h3a_awb_done_irq			:1;
	UVINT32 reserved1				:2;
	UVINT32 hist_done_irq				:1;
	UVINT32 ccdc_lsc_done				:1;
	UVINT32 ccdc_lsc_prefectch_completed		:1;
	UVINT32 ccdc_lsc_prefectch_error		:1;
	UVINT32 prv_done_irq				:1;
	UVINT32 cbuff_irq				:1;
	UVINT32 reserved2				:2;
	UVINT32 rsz_done_irq				:1;
	UVINT32 ovf_irq					:1;
	UVINT32 reserved3				:2;
	UVINT32 mmu_err_irq				:1;
	UVINT32 ocp_err_irq				:1;
	UVINT32 sec_err_irq				:1;
	UVINT32 hs_vs_irq				:1;					
};

/*
 * Module Name Base address (hex) Size
 * ISP            0x480B C000          512 bytes
 * ISP_CBUFF      0x480B C100          256 bytes
 * ISP_CCDC       0x480B C600          512 bytes
 * ISP_HIST       0x480B CA00          512 bytes
 * ISP_H3A        0x480B CC00          512 bytes
 * ISP_PREVIEW    0x480B CE00          512 bytes
 * ISP_RESIZER    0x480B D000          512 bytes
 * ISP_SBL        0x480B D200          512 bytes
 */

typedef struct __isp_reg_bit_access
{
	union
	{
/*
 * 
 * Register Name       Type Register   Address     Physical     Section
 *                          Width      Offset     Address
 *                          (Bits)
 * ISP_SYSCONFIG        RW     32    0x0000 0004 0x480B C004 Section 1.6.2.1
 * ISP_SYSSTATUS         R     32    0x0000 0008 0x480B C008 Section 1.6.2.2
 * ISP_IRQ0ENABLE       RW     32    0x0000 000C 0x480B C00C Section 1.6.2.3
 * ISP_IRQ0STATUS       RW     32    0x0000 0010 0x480B C010 Section 1.6.2.4
 * ISP_IRQ1ENABLE       RW     32    0x0000 0014 0x480B C014 Section 1.6.2.5
 * ISP_IRQ1STATUS       RW     32    0x0000 0018 0x480B C018 Section 1.6.2.6
 * TCTRL_GRESET_LENGTH  RW     32    0x0000 0030 0x480B C030 Section 1.6.2.7
 * TCTRL_PSTRB_REPLAY   RW     32    0x0000 0034 0x480B C034 Section 1.6.2.8
 * ISP_CTRL             RW     32    0x0000 0040 0x480B C040 Section 1.6.2.9
 * ISP_SECURE           RW     32    0x0000 0044 0x480B C044 Section 1.6.2.10
 * TCTRL_CTRL           RW     32    0x0000 0050 0x480B C050 Section 1.6.2.11
 * TCTRL_FRAME          RW     32    0x0000 0054 0x480B C054 Section 1.6.2.12
 * TCTRL_PSTRB_DELAY    RW     32    0x0000 0058 0x480B C058 Section 1.6.2.13
 * TCTRL_STRB_DELAY     RW     32    0x0000 005C 0x480B C05C Section 1.6.2.14
 * TCTRL_SHUT_DELAY     RW     32    0x0000 0060 0x480B C060 Section 1.6.2.15
 * TCTRL_PSTRB_LENGTH   RW     32    0x0000 0064 0x480B C064 Section 1.6.2.16
 * TCTRL_STRB_LENGTH    RW     32    0x0000 0068 0x480B C068 Section 1.6.2.17
 * TCTRL_SHUT_LENGTH    RW     32    0x0000 006C 0x480B C06C Section 1.6.2.18
 */

		UVINT32 ISP[((BADDR_ISP_CBUFF-BADDR_ISP)/4)];
		struct
		{	
			UVINT32 ISP_VER;			// 0x0000 0000
			union
			{
				UVINT32 ISP_SYSCONFIG;		// 0x0000 0004
				struct
				{
					UVINT32 auto_idle		:1;
					UVINT32 soft_reset		:1;
					UVINT32 reserved1		:10;
					UVINT32 midle_mode		:2;
				}bit;
			}isp_sysconfig;
			
			union
			{
				UVINT32 ISP_SYSSTATUS;		// 0x0000 0008
				struct
				{
					UVINT32 reset_done		:1;
				}bit;
			}isp_sysstatus;
			
			union
			{
				UVINT32 ISP_IRQ0ENABLE;		// 0x0000 000C
				struct isp_irq bit;
			}isp_irq0enable;

			union 
			{
				UVINT32 ISP_IRQ0STATUS;		// 0x0000 0010
				struct isp_irq bit;

			}isp_irq0status;

			union
			{
				UVINT32 ISP_IRQ1ENABLE;		// 0x0000 0014
				struct isp_irq bit;

			}isp_irq1enable;

			union
			{
				UVINT32 ISP_IRQ1STATUS;		// 0x0000 0018
				struct isp_irq bit;
			}isp_irq1status;

			UVINT32 RESERVED0[5];
			union
			{
				UVINT32 TCTRL_GRESET_LENGTH;	// 0x0000 0030
				struct
				{
					UVINT32 length			:24;
					UVINT32 reserved		:8;
				}bit;
			}tctrl_greset_length;
			UVINT32 TCTRL_PSTRB_REPLAY;		// 0x0000 0034
			UVINT32 RESERVED1[2];
			
			union
			{
				UVINT32 ISP_CTRL;		// 0x0000 0040
				struct
				{
					UVINT32 par_ser_clk_sel		:2;
					UVINT32 par_bridge		:2;
					UVINT32 par_clk_pol		:1;
					UVINT32 reserved0		:1;
					UVINT32 shift			:2;
					UVINT32 ccdc_clk_en		:1;
					UVINT32 cbuff_autogating	:1;
					UVINT32 h3a_clk_en		:1;
					UVINT32 hist_clk_en		:1;
					UVINT32 prv_clk_en		:1;
					UVINT32 rsz_clk_en		:1;
					UVINT32 sync_detect		:2;
					UVINT32 ccdc_ram_en		:1;
					UVINT32 prev_ram_en		:1;
					UVINT32 sbl_rd_ram_en		:1;
					UVINT32 sbl_wr1_ram_en		:1;
					UVINT32 sbl_wr0_ram_en		:1;
					UVINT32 sbl_autoidle		:1;
					UVINT32 reserved1		:6;
					UVINT32 sbl_shared_rportb	:1;
					UVINT32 ccdc_wen_pol		:1;
					UVINT32 jpeg_flush		:1;
					UVINT32 flush			:1;
				}bit;
			}isp_ctrl;

			UVINT32 ISP_SECURE;			// 0x0000 0044
			UVINT32 RESERVED2[2];
			union
			{			
				UVINT32 TCTRL_CTRL;		// 0x0000 0050
				struct
				{
					UVINT32 diva			:5;
					UVINT32 divb			:5;
					UVINT32 divc			:9;
					UVINT32 reserved0		:2;
					UVINT32 shuten			:1;
					UVINT32 pstrben			:1;
					UVINT32 strben			:1;
					UVINT32 shutpol			:1;
					UVINT32 reserved1		:1;
					UVINT32 strbpstrbpol		:1;
					UVINT32 insel			:2;
					UVINT32 greseten		:1;
					UVINT32 gresetpol		:1;
					UVINT32 gresetdir		:1;
				}bit;
			}tctrl_ctrl;
			
			UVINT32 TCTRL_FRAME;			// 0x0000 0054
			UVINT32 TCTRL_PSTRB_DELAY;		// 0x0000 0058
			UVINT32 TCTRL_STRB_DELAY;		// 0x0000 005C
			UVINT32 TCTRL_SHUT_DELAY;		// 0x0000 0060
			UVINT32 TCTRL_PSTRB_LENGTH;		// 0x0000 0064
			UVINT32 TCTRL_STRB_LENGTH;		// 0x0000 0068
			UVINT32 TCTRL_SHUT_LENGTH;		// 0x0000 006C
		}reg;
	}isp_main;

	union
	{
/*
 * CBUFF_SYSCONFIG       RW 32      0x0000 0010             0x480B C110             Section 1.6.3.1
 * CBUFF_SYSSTATUS        R 32      0x0000 0014             0x480B C114             Section 1.6.3.2
 * CBUFF_IRQSTATUS       RW 32      0x0000 0018             0x480B C118             Section 1.6.3.3
 * CBUFF_IRQENABLE       RW 32      0x0000 001C             0x480B C11C             Section 1.6.3.4
 * CBUFFx_CTRL (1)       RW 32      0x0000 0020 + (0x4 * x) 0x480B C120 + (0x4 * x) Section 1.6.3.5
 * CBUFFx_STATUS (1)      R 32      0x0000 0030 + (0x4 * x) 0x480B C130 + (0x4 * x) Section 1.6.3.6
 * CBUFFx_START (1)      RW 32      0x0000 0040 + (0x4 * x) 0x480B C140 + (0x4 * x) Section 1.6.3.7
 * CBUFFx_END (1)        RW 32      0x0000 0050 + (0x4 * x) 0x480B C150 + (0x4 * x) Section 1.6.3.8
 * CBUFFx_WINDOWSIZE (1) RW 32      0x0000 0060 + (0x4 * x) 0x480B C160 + (0x4 * x) Section 1.6.3.9
 * CBUFFx_THRESHOLD (1)  RW 32      0x0000 0070 + (0x4 * x) 0x480B C170 + (0x4 * x) Section 1.6.3.10
 */

		UVINT32 ISP_CBUFF[((BADDR_ISP_CCDC-BADDR_ISP_CBUFF)/4)];
	}isp_cbuff;
	
	union
	{
/*
 * Register Name        Type Register        Address                 Physical            Section
 *                          Width           Offset                 Address
 *                          (Bits)
 * CCDC_PID               R     32         0x0000 0000             0x480B C600        Section 1.6.4.1
 * CCDC_PCR              RW     32         0x0000 0004             0x480B C604        Section 1.6.4.2
 * CCDC_SYN_MODE         RW     32         0x0000 0008             0x480B C608        Section 1.6.4.3
 * CCDC_HD_VD_WID        RW     32         0x0000 000C             0x480B C60C        Section 1.6.4.4
 * CCDC_PIX_LINES        RW     32         0x0000 0010             0x480B C610        Section 1.6.4.5
 * CCDC_HORZ_INFO        RW     32         0x0000 0014             0x480B C614        Section 1.6.4.6
 * CCDC_VERT_START       RW     32         0x0000 0018             0x480B C618        Section 1.6.4.7
 * CCDC_VERT_LINES       RW     32         0x0000 001C             0x480B C61C        Section 1.6.4.8
 * CCDC_CULLING          RW     32         0x0000 0020             0x480B C620        Section 1.6.4.9
 * CCDC_HSIZE_OFF        RW     32         0x0000 0024             0x480B C624        Section 1.6.4.10
 * CCDC_SDOFST           RW     32         0x0000 0028             0x480B C628        Section 1.6.4.11
 * CCDC_SDR_ADDR         RW     32         0x0000 002C             0x480B C62C        Section 1.6.4.12
 * CCDC_CLAMP            RW     32         0x0000 0030             0x480B C630        Section 1.6.4.13
 * CCDC_DCSUB            RW     32         0x0000 0034             0x480B C634        Section 1.6.4.14
 * CCDC_COLPTN           RW     32         0x0000 0038             0x480B C638        Section 1.6.4.15
 * CCDC_BLKCMP           RW     32         0x0000 003C             0x480B C63C        Section 1.6.4.16
 * CCDC_FPC              RW     32         0x0000 0040             0x480B C640        Section 1.6.4.17
 * CCDC_FPC_ADDR         RW     32         0x0000 0044             0x480B C644        Section 1.6.4.18
 * CCDC_VDINT            RW     32         0x0000 0048             0x480B C648        Section 1.6.4.19
 * CCDC_ALAW             RW     32         0x0000 004C             0x480B C64C        Section 1.6.4.20
 * CCDC_REC656IF         RW     32         0x0000 0050             0x480B C650        Section 1.6.4.21
 * CCDC_CFG              RW     32         0x0000 0054             0x480B C654        Section 1.6.4.22
 * CCDC_FMTCFG           RW     32         0x0000 0058             0x480B C658        Section 1.6.4.23
 * CCDC_FMT_HORZ         RW     32         0x0000 005C             0x480B C65C        Section 1.6.4.24
 * CCDC_FMT_VERT         RW     32         0x0000 0060             0x480B C660        Section 1.6.4.25
 * CCDC_FMT_ADDRx(1)     RW     32         0x0000 0064 + (0x4 * x) 0x480B C664 + (0x4 * x) Section 1.6.4.26
 * CCDC_PRGEVEN0         RW     32         0x0000 0084             0x480B C684        Section 1.6.4.27
 * CCDC_PRGEVEN1         RW     32         0x0000 0088             0x480B C688        Section 1.6.4.28
 * CCDC_PRGODD0          RW     32         0x0000 008C             0x480B C68C        Section 1.6.4.29
 * CCDC_PRGODD1          RW     32         0x0000 0090             0x480B C690        Section 1.6.4.30
 * CCDC_VP_OUT           RW     32         0x0000 0094             0x480B C694        Section 1.6.4.31
 * CCDC_LSC_CONFIG       RW     32         0x0000 0098             0x480B C698        Section 1.6.4.32
 * CCDC_LSC_INITIAL      RW     32         0x0000 009C             0x480B C69C        Section 1.6.4.33
 * CCDC_LSC_TABLE_BASE   RW     32         0x0000 00A0             0x480B C6A0        Section 1.6.4.34
 * CCDC_LSC_TABLE_OFFSET RW     32         0x0000 00A4             0x480B C6A4        Section 1.6.4.35
 */

		UVINT32 ISP_CCDC[((BADDR_ISP_HIST-BADDR_ISP_CCDC)/4)];
		struct
		{
			UVINT32 CCDC_PID;			// 0x0000 0000
			union
			{
				UVINT32 CCDC_PCR;		// 0x0000 0004
				struct
				{
					UVINT32 enable				:1;
					UVINT32 busy				:1;
				}bit;
			}ccdc_pcr;

			union
			{
				UVINT32 CCDC_SYN_MODE;		// 0x0000 0008
				struct
				{
					UVINT32 vdhdout				:1;
					UVINT32 fldout				:1;
					UVINT32 vdpol				:1;
					UVINT32 hdpol				:1;
					UVINT32 fldpol				:1;
					UVINT32 exwen				:1;
					UVINT32 datapol				:1;
					UVINT32 fldmode				:1;
					UVINT32 datsiz				:3;
					UVINT32 pack8				:1;
					UVINT32 inpmod				:2;
					UVINT32 lpf				:1;
					UVINT32 fldstat				:1;
					UVINT32 vdhden				:1;
					UVINT32 wen				:1;
					UVINT32 vp2str				:1;
					UVINT32 sdr2rsz				:1;
				}bit;
			}ccdc_syn_mode;

			UVINT32 CCDC_HD_VD_WID;			// 0x0000 000C
			UVINT32 CCDC_PIX_LINES;			// 0x0000 0010

			union
			{
				UVINT32 CCDC_HORZ_INFO;		// 0x0000 0014
				struct
				{
					UVINT32 nph				:15;
					UVINT32 reserved0			:1;
					UVINT32 sph				:15;
					UVINT32 reserved1			:1;
				}bit;
			}ccdc_horz_info;

			union
			{
				UVINT32 CCDC_VERT_START;	// 0x0000 0018
				struct
				{
					UVINT32 slv1				:15;
					UVINT32 reserved0			:1;
					UVINT32 slv0				:15;
					UVINT32 reserved1			:1;
				}bit;
			}ccdc_vert_start;
		
			union
			{
				UVINT32 CCDC_VERT_LINES;	// 0x0000 001C
				struct
				{
					UVINT32 nlv				:15;
				}bit;
			}ccdc_vert_lines;
			UVINT32 CCDC_CULLING;			// 0x0000 0020

			union
			{
				UVINT32 CCDC_HSIZE_OFF;		// 0x0000 0024
				struct
				{
					UVINT32 lnofst				:16;
				}bit;
			}ccdc_hsize_off;

			UVINT32 CCDC_SDOFST;			// 0x0000 0028
			UVINT32 CCDC_SDR_ADDR;			// 0x0000 002C
			UVINT32 CCDC_CLAMP;			// 0x0000 0030
			UVINT32 CCDC_DCSUB;			// 0x0000 0034
			UVINT32 CCDC_COLPTN;			// 0x0000 0038
			UVINT32 CCDC_BLKCMP;			// 0x0000 003C
			UVINT32 CCDC_FPC;			// 0x0000 0040
			UVINT32 CCDC_FPC_ADDR;			// 0x0000 0044

			union
			{
				UVINT32 CCDC_VDINT;		// 0x0000 0048
				struct
				{
					UVINT32 vdint1				:15;
					UVINT32 reserved0			:1;
					UVINT32 vdint0				:15;
				}bit;
			}ccdc_vdint;

			UVINT32 CCDC_ALAW;			// 0x0000 004C
			UVINT32 CCDC_REC656IF;			// 0x0000 0050

			union
			{
				UVINT32 CCDC_CFG;		// 0x0000 0054 
				struct
				{
					UVINT32 reserved0			:5;
					UVINT32 bw565				:1;
					UVINT32 fidmd				:2;
					UVINT32 wenlog				:1;
					UVINT32 reserved1			:2;
					UVINT32 y8pos				:1;
					UVINT32 bswb				:1;
					UVINT32 msbinvi				:1;
					UVINT32 reserved2			:1;
					UVINT32 vdlc				:1;
				}bit;
			}ccdc_cfg;

			UVINT32 CCDC_FMTCFG;			// 0x0000 0058
			UVINT32 CCDC_FMT_HORZ;			// 0x0000 005C
			UVINT32 CCDC_FMT_VERT;			// 0x0000 0060
			UVINT32 CCDC_FMT_ADDRx;			// 0x0000 0064
			UVINT32 CCDC_PRGEVEN0;			// 0x0000 0084
			UVINT32 CCDC_PRGEVEN1;			// 0x0000 0088
			UVINT32 CCDC_PRGODD0;			// 0x0000 008C
			UVINT32 CCDC_PRGODD1;			// 0x0000 0090
			UVINT32 CCDC_VP_OUT;			// 0x0000 0094 
			UVINT32 CCDC_LSC_CONFIG;		// 0x0000 0098
			UVINT32 CCDC_LSC_INITIAL;		// 0x0000 009C
			UVINT32 CCDC_LSC_TABLE_BASE;		// 0x0000 00A0
			UVINT32 CCDC_LSC_TABLE_OFFSET;		// 0x0000 00A4 
		}reg;
	}isp_ccdc;
	
	union
	{
/*
 * Register Name     Type Register        Address                 Physical            Section
 *                        Width           Offset                 Address
 *                       (Bits)
 * HIST_PID            R     32         0x0000 0000             0x480B CA00        Section 1.6.5.1
 * HIST_PCR           RW     32         0x0000 0004             0x480B CA04        Section 1.6.5.2
 * HIST_CNT           RW     32         0x0000 0008             0x480B CA08        Section 1.6.5.3
 * HIST_WB_GAIN       RW     32         0x0000 000C             0x480B CA0C         Section 1.6.5.4
 * HIST_Rn_HORZ (1)   RW     32         0x0000 0010 + (0x8 * x) 0x480B CA10 + (0x8 * x) Section 1.6.5.5
 * HIST_Rn_VERT (1)   RW     32         0x0000 0014 + (0x8 * x) 0x480B CA14 + (0x8 * x) Section 1.6.5.6
 * HIST_ADDR          RW     32         0x0000 0030             0x480B CA30        Section 1.6.5.7
 * HIST_DATA          RW     32         0x0000 0034             0x480B CA34        Section 1.6.5.8
 * HIST_RADD          RW     32         0x0000 0038             0x480B CA38        Section 1.6.5.9
 * HIST_RADD_OFF      RW     32         0x0000 003C             0x480B CA3C         Section 1.6.5.10
 * HIST_H_V_INFO      RW     32         0x0000 0040             0x480B CA40        Section 1.6.5.11
 */

		UVINT32 ISP_HIST[((BADDR_ISP_H3A-BADDR_ISP_HIST)/4)];
		
	}isp_hist;

	union
	{
/*
 * Register Name  Type Register   Address     Physical     Section
 *                    Width      Offset     Address
 *                   (Bits)
 * H3A_PID          R     32    0x0000 0000 0x480B CC00 Section 1.6.6.1
 * H3A_PCR         RW     32    0x0000 0004 0x480B CC04 Section 1.6.6.2
 * H3A_AFPAX1      RW     32    0x0000 0008 0x480B CC08 Section 1.6.6.3
 * H3A_AFPAX2      RW     32    0x0000 000C 0x480B CC0C Section 1.6.6.4
 * H3A_AFPAXSTART  RW     32    0x0000 0010 0x480B CC10 Section 1.6.6.5
 * H3A_AFIIRSH     RW     32    0x0000 0014 0x480B CC14 Section 1.6.6.6
 * H3A_AFBUFST     RW     32    0x0000 0018 0x480B CC18 Section 1.6.6.7
 * H3A_AFCOEF010   RW     32    0x0000 001C 0x480B CC1C Section 1.6.6.8
 * H3A_AFCOEF032   RW     32    0x0000 0020 0x480B CC20 Section 1.6.6.9
 * H3A_AFCOEF054   RW     32    0x0000 0024 0x480B CC24 Section 1.6.6.10
 * H3A_AFCOEF076   RW     32    0x0000 0028 0x480B CC28 Section 1.6.6.11
 * H3A_AFCOEF098   RW     32    0x0000 002C 0x480B CC2C Section 1.6.6.12
 * H3A_AFCOEF0010  RW     32    0x0000 0030 0x480B CC30 Section 1.6.6.13
 * H3A_AFCOEF110   RW     32    0x0000 0034 0x480B CC34 Section 1.6.6.14
 * H3A_AFCOEF132   RW     32    0x0000 0038 0x480B CC38 Section 1.6.6.15
 * H3A_AFCOEF154   RW     32    0x0000 003C 0x480B CC3C Section 1.6.6.16
 * H3A_AFCOEF176   RW     32    0x0000 0040 0x480B CC40 Section 1.6.6.17
 * H3A_AFCOEF198   RW     32    0x0000 0044 0x480B CC44 Section 1.6.6.18
 * H3A_AFCOEF1010  RW     32    0x0000 0048 0x480B CC48 Section 1.6.6.19
 * H3A_AEWWIN1     RW     32    0x0000 004C 0x480B CC4C Section 1.6.6.20
 * H3A_AEWINSTART  RW     32    0x0000 0050 0x480B CC50 Section 1.6.6.21
 * H3A_AEWINBLK    RW     32    0x0000 0054 0x480B CC54 Section 1.6.6.22
 * H3A_AEWSUBWIN   RW     32    0x0000 0058 0x480B CC58 Section 1.6.6.23
 * H3A_AEWBUFST    RW     32    0x0000 005C 0x480B CC5C Section 1.6.6.24
 */

		UVINT32 ISP_H3A[((BADDR_ISP_PREVIEW-BADDR_ISP_H3A)/4)];
		
	}isp_h3a;

	union
	{
/*
 * Register Name  Type Register   Address     Physical     Section
 *                   Width      Offset     Address
 *                  (Bits)
 * PRV_PID           R 32      0x0000 0000             0x480B CE00        Section 1.6.7.1
 * PRV_PCR          RW 32      0x0000 0004             0x480B CE04        Section 1.6.7.2
 * PRV_HORZ_INFO    RW 32      0x0000 0008             0x480B CE08        Section 1.6.7.3
 * PRV_VERT_INFO    RW 32      0x0000 000C             0x480B CE0C        Section 1.6.7.4
 * PRV_RSDR_ADDR    RW 32      0x0000 0010             0x480B CE10        Section 1.6.7.5
 * PRV_RADR_OFFSET  RW 32      0x0000 0014             0x480B CE14        Section 1.6.7.6
 * PRV_DSDR_ADDR    RW 32      0x0000 0018             0x480B CE18        Section 1.6.7.7
 * PRV_DRKF_OFFSET  RW 32      0x0000 001C             0x480B CE1C        Section 1.6.7.8
 * PRV_WSDR_ADDR    RW 32      0x0000 0020             0x480B CE20        Section 1.6.7.9
 * PRV_WADD_OFFSET  RW 32      0x0000 0024             0x480B CE24        Section 1.6.7.10
 * PRV_AVE          RW 32      0x0000 0028             0x480B CE28        Section 1.6.7.11
 * PRV_HMED         RW 32      0x0000 002C             0x480B CE2C        Section 1.6.7.12
 * PRV_NF           RW 32      0x0000 0030             0x480B CE30        Section 1.6.7.13
 * PRV_WB_DGAIN     RW 32      0x0000 0034             0x480B CE34        Section 1.6.7.14
 * PRV_WBGAIN       RW 32      0x0000 0038             0x480B CE38        Section 1.6.7.15
 * PRV_WBSEL        RW 32      0x0000 003C             0x480B CE3C        Section 1.6.7.16
 * PRV_CFA          RW 32      0x0000 0040             0x480B CE40        Section 1.6.7.17
 * PRV_BLKADJOFF    RW 32      0x0000 0044             0x480B CE44        Section 1.6.7.18
 * PRV_RGB_MAT1     RW 32      0x0000 0048             0x480B CE48        Section 1.6.7.19
 * PRV_RGB_MAT2     RW 32      0x0000 004C             0x480B CE4C        Section 1.6.7.20
 * PRV_RGB_MAT3     RW 32      0x0000 0050             0x480B CE50        Section 1.6.7.21
 * PRV_RGB_MAT4     RW 32      0x0000 0054             0x480B CE54        Section 1.6.7.22
 * PRV_RGB_MAT5     RW 32      0x0000 0058             0x480B CE58        Section 1.6.7.23
 * PRV_RGB_OFF1     RW 32      0x0000 005C             0x480B CE5C        Section 1.6.7.24
 * PRV_RGB_OFF2     RW 32      0x0000 0060             0x480B CE60        Section 1.6.7.25
 * PRV_CSC0         RW 32      0x0000 0064             0x480B CE64        Section 1.6.7.26
 * PRV_CSC1         RW 32      0x0000 0068             0x480B CE68        Section 1.6.7.27
 * PRV_CSC2         RW 32      0x0000 006C             0x480B CE6C        Section 1.6.7.28
 * PRV_CSC_OFFSET   RW 32      0x0000 0070             0x480B CE70        Section 1.6.7.29
 * PRV_CNT_BRT      RW 32      0x0000 0074             0x480B CE74        Section 1.6.7.30
 * PRV_CSUP         RW 32      0x0000 0078             0x480B CE78        Section 1.6.7.31
 * PRV_SETUP_YC     RW 32      0x0000 007C             0x480B CE7C        Section 1.6.7.32
 * PRV_SET_TBL_ADDR RW 32      0x0000 0080             0x480B CE80        Section 1.6.7.33
 * PRV_SET_TBL_DATA RW 32      0x0000 0084             0x480B CE84        Section 1.6.7.34
 * PRV_CDC_THRx (1) RW 32      0x0000 0090 + (0x4 * x) 0x480B CE90 + (0x4 * x) Section 1.6.7.35
 */

		UVINT32 ISP_PRV[((BADDR_ISP_RESIZER-BADDR_ISP_PREVIEW)/4)];
		
	}isp_pview;

	union
	{
/*
 * Register Name  Type Register   Address     Physical     Section
 *                   Width      Offset     Address
 *                  (Bits)
 * RSZ_PID         R 32 0x0000 0000 0x480B D000 Section 1.6.8.1
 * RSZ_PCR        RW 32 0x0000 0004 0x480B D004 Section 1.6.8.2
 * RSZ_CNT        RW 32 0x0000 0008 0x480B D008 Section 1.6.8.3
 * RSZ_OUT_SIZE   RW 32 0x0000 000C 0x480B D00C Section 1.6.8.4
 * RSZ_IN_START   RW 32 0x0000 0010 0x480B D010 Section 1.6.8.5
 * RSZ_IN_SIZE    RW 32 0x0000 0014 0x480B D014 Section 1.6.8.6
 * RSZ_SDR_INADD  RW 32 0x0000 0018 0x480B D018 Section 1.6.8.7
 * RSZ_SDR_INOFF  RW 32 0x0000 001C 0x480B D01C Section 1.6.8.8
 * RSZ_SDR_OUTADD RW 32 0x0000 0020 0x480B D020 Section 1.6.8.9
 * RSZ_SDR_OUTOFF RW 32 0x0000 0024 0x480B D024 Section 1.6.8.10
 * RSZ_HFILT10    RW 32 0x0000 0028 0x480B D028 Section 1.6.8.11
 * RSZ_HFILT32    RW 32 0x0000 002C 0x480B D02C Section 1.6.8.12
 * RSZ_HFILT54    RW 32 0x0000 0030 0x480B D030 Section 1.6.8.13
 * RSZ_HFILT76    RW 32 0x0000 0034 0x480B D034 Section 1.6.8.14
 * RSZ_HFILT98    RW 32 0x0000 0038 0x480B D038 Section 1.6.8.15
 * RSZ_HFILT1110  RW 32 0x0000 003C 0x480B D03C Section 1.6.8.16
 * RSZ_HFILT1312  RW 32 0x0000 0040 0x480B D040 Section 1.6.8.17
 * RSZ_HFILT1514  RW 32 0x0000 0044 0x480B D044 Section 1.6.8.18
 * RSZ_HFILT1716  RW 32 0x0000 0048 0x480B D048 Section 1.6.8.19
 * RSZ_HFILT1918  RW 32 0x0000 004C 0x480B D04C Section 1.6.8.20
 * RSZ_HFILT2120  RW 32 0x0000 0050 0x480B D050 Section 1.6.8.21
 * RSZ_HFILT2322  RW 32 0x0000 0054 0x480B D054 Section 1.6.8.22
 * RSZ_HFILT2524  RW 32 0x0000 0058 0x480B D058 Section 1.6.8.23
 * RSZ_HFILT2726  RW 32 0x0000 005C 0x480B D05C Section 1.6.8.24
 * RSZ_HFILT2928  RW 32 0x0000 0060 0x480B D060 Section 1.6.8.25
 * RSZ_HFILT3130  RW 32 0x0000 0064 0x480B D064 Section 1.6.8.26
 * RSZ_VFILT10    RW 32 0x0000 0068 0x480B D068 Section 1.6.8.27
 * RSZ_VFILT32    RW 32 0x0000 006C 0x480B D06C Section 1.6.8.28
 * RSZ_VFILT54    RW 32 0x0000 0070 0x480B D070 Section 1.6.8.29
 * RSZ_VFILT76    RW 32 0x0000 0074 0x480B D074 Section 1.6.8.30
 * RSZ_VFILT98    RW 32 0x0000 0078 0x480B D078 Section 1.6.8.31
 * RSZ_VFILT1110  RW 32 0x0000 007C 0x480B D07C Section 1.6.8.32
 * RSZ_VFILT1312  RW 32 0x0000 0080 0x480B D080 Section 1.6.8.33
 * RSZ_VFILT1514  RW 32 0x0000 0084 0x480B D084 Section 1.6.8.34
 * RSZ_VFILT1716  RW 32 0x0000 0088 0x480B D088 Section 1.6.8.35
 * RSZ_VFILT1918  RW 32 0x0000 008C 0x480B D08C Section 1.6.8.36
 * RSZ_VFILT2120  RW 32 0x0000 0090 0x480B D090 Section 1.6.8.37
 * RSZ_VFILT2322  RW 32 0x0000 0094 0x480B D094 Section 1.6.8.38
 * RSZ_VFILT2524  RW 32 0x0000 0098 0x480B D098 Section 1.6.8.39
 * RSZ_VFILT2726  RW 32 0x0000 009C 0x480B D09C Section 1.6.8.40
 * RSZ_VFILT2928  RW 32 0x0000 00A0 0x480B D0A0 Section 1.6.8.41
 * RSZ_VFILT3130  RW 32 0x0000 00A4 0x480B D0A4 Section 1.6.8.42
 * RSZ_YENH       RW 32 0x0000 00A8 0x480B D0A8 Section 1.6.8.43
 */

		UVINT32 ISP_RSZ[((BADDR_ISP_SBL-BADDR_ISP_RESIZER)/4)];
		
	}isp_rsize;

	union
	{

/*
 * Register Name  Type Register   Address     Physical     Section
 *                   Width      Offset     Address
 *                  (Bits)
 * SBL_PID             R 32 0x0000 0000 0x480B D200 Section 1.6.9.1
 * SBL_PCR            RW 32 0x0000 0004 0x480B D204 Section 1.6.9.2
 * SBL_GLB_REG_0       R 32 0x0000 0008 0x480B D208 Section 1.6.9.3
 * SBL_GLB_REG_1       R 32 0x0000 000C 0x480B D20C Section 1.6.9.4
 * SBL_GLB_REG_2       R 32 0x0000 0010 0x480B D210 Section 1.6.9.5
 * SBL_GLB_REG_3       R 32 0x0000 0014 0x480B D214 Section 1.6.9.6
 * SBL_GLB_REG_4       R 32 0x0000 0018 0x480B D218 Section 1.6.9.7
 * SBL_GLB_REG_5       R 32 0x0000 001C 0x480B D21C Section 1.6.9.8
 * SBL_GLB_REG_6       R 32 0x0000 0020 0x480B D220 Section 1.6.9.9
 * SBL_GLB_REG_7       R 32 0x0000 0024 0x480B D224 Section 1.6.9.10
 * SBL_CCDC_WR_0       R 32 0x0000 0028 0x480B D228 Section 1.6.9.11
 * SBL_CCDC_WR_1       R 32 0x0000 002C 0x480B D22C Section 1.6.9.12
 * SBL_CCDC_WR_2       R 32 0x0000 0030 0x480B D230 Section 1.6.9.13
 * SBL_CCDC_WR_3       R 32 0x0000 0034 0x480B D234 Section 1.6.9.14
 * SBL_CCDC_FP_RD_0    R 32 0x0000 0038 0x480B D238 Section 1.6.9.15
 * SBL_CCDC_FP_RD_1    R 32 0x0000 003C 0x480B D23C Section 1.6.9.16
 * SBL_PRV_RD_0        R 32 0x0000 0040 0x480B D240 Section 1.6.9.17
 * SBL_PRV_RD_1        R 32 0x0000 0044 0x480B D244 Section 1.6.9.18
 * SBL_PRV_RD_2        R 32 0x0000 0048 0x480B D248 Section 1.6.9.19
 * SBL_PRV_RD_3        R 32 0x0000 004C 0x480B D24C Section 1.6.9.20
 * SBL_PRV_WR_0        R 32 0x0000 0050 0x480B D250 Section 1.6.9.21
 * SBL_PRV_WR_1        R 32 0x0000 0054 0x480B D254 Section 1.6.9.22
 * SBL_PRV_WR_2        R 32 0x0000 0058 0x480B D258 Section 1.6.9.23
 * SBL_PRV_WR_3        R 32 0x0000 005C 0x480B D25C Section 1.6.9.24
 * SBL_PRV_DK_RD_0     R 32 0x0000 0060 0x480B D260 Section 1.6.9.25
 * SBL_PRV_DK_RD_1     R 32 0x0000 0064 0x480B D264 Section 1.6.9.26
 * SBL_PRV_DK_RD_2     R 32 0x0000 0068 0x480B D268 Section 1.6.9.27
 * SBL_PRV_DK_RD_3     R 32 0x0000 006C 0x480B D26C Section 1.6.9.28
 * SBL_RSZ_RD_0        R 32 0x0000 0070 0x480B D270 Section 1.6.9.29
 * SBL_RSZ_RD_1        R 32 0x0000 0074 0x480B D274 Section 1.6.9.30
 * SBL_RSZ_RD_2        R 32 0x0000 0078 0x480B D278 Section 1.6.9.31
 * SBL_RSZ_RD_3        R 32 0x0000 007C 0x480B D27C Section 1.6.9.32
 * SBL_RSZ1_WR_0       R 32 0x0000 0080 0x480B D280 Section 1.6.9.33
 * SBL_RSZ1_WR_1       R 32 0x0000 0084 0x480B D284 Section 1.6.9.34
 * SBL_RSZ1_WR_2       R 32 0x0000 0088 0x480B D288 Section 1.6.9.35
 * SBL_RSZ1_WR_3       R 32 0x0000 008C 0x480B D28C Section 1.6.9.36
 * SBL_RSZ2_WR_0       R 32 0x0000 0090 0x480B D290 Section 1.6.9.37
 * SBL_RSZ2_WR_1       R 32 0x0000 0094 0x480B D294 Section 1.6.9.38
 * SBL_RSZ2_WR_2       R 32 0x0000 0098 0x480B D298 Section 1.6.9.39
 * SBL_RSZ2_WR_3       R 32 0x0000 009C 0x480B D29C Section 1.6.9.40
 * SBL_RSZ3_WR_0       R 32 0x0000 00A0 0x480B D2A0 Section 1.6.9.41
 * SBL_RSZ3_WR_1       R 32 0x0000 00A4 0x480B D2A4 Section 1.6.9.42
 * SBL_RSZ3_WR_2       R 32 0x0000 00A8 0x480B D2A8 Section 1.6.9.43
 * SBL_RSZ3_WR_3       R 32 0x0000 00AC 0x480B D2AC Section 1.6.9.44
 * SBL_RSZ4_WR_0       R 32 0x0000 00B0 0x480B D2B0 Section 1.6.9.45
 * SBL_RSZ4_WR_1       R 32 0x0000 00B4 0x480B D2B4 Section 1.6.9.46
 * SBL_RSZ4_WR_2       R 32 0x0000 00B8 0x480B D2B8 Section 1.6.9.47
 * SBL_RSZ4_WR_3       R 32 0x0000 00BC 0x480B D2BC Section 1.6.9.48
 * SBL_HIST_RD_0       R 32 0x0000 00C0 0x480B D2C0 Section 1.6.9.49
 * SBL_HIST_RD_1       R 32 0x0000 00C4 0x480B D2C4 Section 1.6.9.50
 * SBL_H3A_AF_WR_0     R 32 0x0000 00C8 0x480B D2C8 Section 1.6.9.51
 * SBL_H3A_AF_WR_1     R 32 0x0000 00CC 0x480B D2CC Section 1.6.9.52
 * SBL_H3A_AEAWB_WR_0  R 32 0x0000 00D0 0x480B D2D0 Section 1.6.9.53
 * SBL_H3A_AEAWB_WR_1  R 32 0x0000 00D4 0x480B D2D4 Section 1.6.9.54
 * SBL_SDR_REQ_EXP    RW 32 0x0000 00F8 0x480B D2F8 Section 1.6.9.55
 */
		UVINT32 ISP_SBL[((BADDR_ISP_SBL_END-BADDR_ISP_SBL)/4)];
		
	}isp_sbl;

}isp_reg_bit_access;

