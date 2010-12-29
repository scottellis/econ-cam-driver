 econ-cam-driver
=============

This is a forked driver for the e-con Systems e-CAM32_OMAP_GSTIX board for
Gumstix Overo.

There is a forked console program for testing this same driver here

https://github.com/scottellis/econ-cam-test

I am trying to simplify the driver as well as learn a little about the omap3
isp controller and the linux v4l2 framework.

There is a patch and a kernel recipe for building with OE. 
Kernel linux-omap3-2.6.34r91 is all I've tested. 

I assume no CMEM. If you add something like this to your command line args 
in u-boot you should be fine with most overos.

mem=250M@0x80000000

For the overo tides with 512M it can be

mem=506M@0x80000000


There are some problems with the driver. 

A bad one right now is having to load/unload/load the driver before I can
get good pictures. I must have introduced this. Probably some initialization.
It will get fixed soon.

And I still have a lot of cleanup planned, so use at your own discretion.




