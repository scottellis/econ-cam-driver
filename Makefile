v4l2_driver-objs	:=	init_module.o isp.o omap_hwr_base.o sens_ov3640.o  v4l2_driver_base.o 		\
				omap_camera_interface.o omap_v4l2_fops_base.o  isp.o omap_v4l2_ioctl_fops.o	\
				i2c.o exit_module.o 						\
				resource/src/error.o resource/src/kernel/phy_mem.o

obj-m			+=v4l2_driver.o

#KERNEL_PATH=<add_kernel_path_here>
#CROSS_COMPILE=<add_cross_compile_path_here>
KERNEL_PATH=/media/500_P1/kernel
CROSS_COMPILE=/media/500_p4/open_embedded/overo-oe/tmp/cross/armv7a/bin/arm-angstrom-linux-gnueabi-

########################################################################################################
#
#	omap3 gumstix board configuration 
#
########################################################################################################
omap:
	make -C $(KERNEL_PATH) M=$(PWD) ARCH=arm CROSS_COMPILE=$(CROSS_COMPILE) modules
clean:
	make -C $(KERNEL_PATH) M=$(PWD) ARCH=arm CROSS_COMPILE=$(CROSS_COMPILE) clean

