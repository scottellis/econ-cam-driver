 econ-cam-driver
=============

This is a fork of the e-con Systems driver for the e-CAM32_OMAP_GSTIX 
board for Gumstix Overos.

There is a related forked console program for testing this driver here

https://github.com/scottellis/econ-cam-test

I am trying to simplify the driver (flattening the src tree, converting to
linux kernel coding style, removing unused code) and in the process learn a 
little about the omap3 isp controller and the linux v4l2 framework from a 
driver perspective.

There is a patch and a kernel recipe for building with OE. 
Kernel linux-omap3-2.6.34r91 is the only kernel tested. 

I assume no CMEM. If you add something like this to your command line args 
in u-boot you should be fine with most overos.

mem=250M@0x80000000

For the overo tides with 512M it can be

mem=506M@0x80000000

but you will ll have to modify inc_header.h before building for tides.

With those mem= lines you do not have to provide any module parameters when
you load it the driver. The driver name is unchanged - v4l2_driver.ko

root@overo:~# insmod v4l2_driver.ko

There are some problems with the driver. 

A bad one right now is sometimes having to load/unload/load the driver before 
I can get good pictures. I must have introduced this. Probably some 
initialization getting missed. It will get fixed soon.

Once it does start working, it seems to work pretty good. I have only been
testing snapshots though, no streaming tests yet.

And I still have a lot of cleanup planned, so use at your own discretion.


