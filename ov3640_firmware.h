/*
 * 
 */

#ifndef OV3640_FIRMWARE_H
#define OV3640_FIRMWARE_H

struct ov3640_firmware {
	unsigned short reg;
	unsigned short value;
};

struct ov3640_firmware *get_autofocus_firmware(int *size);
struct ov3640_firmware *get_antishake_firmware(int *size);

#endif
