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
 * isp.c
 */
irqreturn_t omap34xx_isp_isr(INT32 irq,void *_isp);
int init_cam_isp_ccdc(cam_data *cam);
int exit_cam_isp_ccdc(cam_data *cam);
/* int isp_set_xclk(cam_data *cam,unsigned int xclk, UINT8 xclksel, UPINT32 current_xclk); */
int isp_reset(cam_data *cam);
int isp_configure(cam_data *cam);
int enable_ccdc(cam_data *cam);
int isp_prg_sdram_addr(cam_data *cam);
int program_dummy_isp_sdram_addr(cam_data *cam);
int disable_ccdc(cam_data *cam);

int enable_isp_irq0(cam_data *cam);
int disable_isp_irq0(cam_data *cam);



/*
 * v4l2_driver_base.c
 */
int v4l2_base_struct(cam_data **cam, UINT8 option);
int init_v4l2_base_struct(cam_data *cam);

/*
 * sens_ov3640.c
 */
int ov3640_exit(cam_data *cam);
int sensor_driver_init(cam_data *cam);


/*
 * lm355 flash support.c
 */
int lm3553_exit(cam_data *cam);

/*
 * omap_hwr_base.c
 */
/*
int init_omap_hwr(cam_data *cam);
int exit_omap_hwr(cam_data *cam);
*/
/*
 * omap_camera_interface.c
 */

int init_cam_interface(cam_data *cam);
int exit_cam_interface(cam_data *cam);

/*
 * omap_v4l2_fops_base.c
 */
INT32 omap_v4l2_open(struct file *file);
INT32 omap_v4l2_close(struct file *file);
INT32 omap_v4l2_read(struct file *file, INT8 *buf, size_t count, loff_t * ppos);
INT32 omap_mmap(struct file *file, struct vm_area_struct *vma);
LINT32 omap_v4l2_do_ioctl(struct file *file, unsigned int ioctlnr, void *arg);
LINT32 omap_v4l2_ioctl(struct file *file, unsigned int cmd, unsigned long arg);

/*
 * gendral
 */

/*
 * ov3640.c
 */
int ov3640_write_reg(unsigned int reg_address, unsigned char reg_data);
int ov3640_read_reg(unsigned int reg_address, unsigned char *reg_data);
int register_sensor_bus(cam_data *cam);

/*
 * omap_v4l2_ioctl_fops.c
 */
int omap_v4l2_capability(cam_data *cam, struct v4l2_capability *cap);
int omap_v4l2_s_fmt(cam_data *cam, struct v4l2_format *f);
int omap_v4l2_g_fmt(cam_data *cam, struct v4l2_format *f);
int omap_v4l2_ctrl(cam_data *cam);

int omap_v4l2_req_buf(cam_data *cam, struct v4l2_requestbuffers *req);
int omap_v4l2_query_buf(cam_data *cam, struct v4l2_buffer *buf);
int omap_v4l2_queue_buf(cam_data *cam, struct v4l2_buffer *buf);
int omap_v4l2_dqueue_buf(cam_data *cam, struct v4l2_buffer *buf);
int omap_v4l2_stream_on(cam_data *cam, INT32 *type);
int omap_v4l2_stream_off(cam_data *cam, INT32 *type);
int omap_v4l2_enum_fmt(cam_data *cam, struct v4l2_fmtdesc *fmt);

/*
 * exit_module.c
 */
INT32 isp_remove(struct platform_device *pdev);

