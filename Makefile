# Makefile for the econ camera module

DRIVERNAME=v4l2_driver

ifneq ($(KERNELRELEASE),)
	obj-m += $(DRIVERNAME).o
	$(DRIVERNAME)-objs :=	init_module.o \
				isp.o \
				sens_ov3640.o \
				v4l2_driver_base.o \
				omap_camera_interface.o \
				omap_v4l2_fops_base.o \
				omap_v4l2_ioctl_fops.o \
				exit_module.o \
				error.o \
				phy_mem.o \
				ov3640_firmware.o

else
    PWD := $(shell pwd)

default:
ifeq ($(strip $(KERNELDIR)),)
	$(error "KERNELDIR is undefined!")
else
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules 
endif


install:
	sudo cp $(DRIVERNAME).ko /exports/overo/home/root

clean:
	rm -rf *~ *.ko *.o *.mod.c modules.order Module.symvers .${DRIVERNAME}* .*.cmd .tmp_versions

endif


