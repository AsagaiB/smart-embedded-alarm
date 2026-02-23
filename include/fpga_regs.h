#ifndef FPGA_REGS_H
#define FPGA_REGS_H

#include <stdint.h>

#define LW_BRIDGE_BASE      0xFF200000
#define LW_BRIDGE_SPAN      0x00005000

#define LED_OFFSET          0x0000
#define SWITCH_OFFSET       0x0010
#define BUTTON_OFFSET       0x0020
#define HEX_OFFSET          0x0030
#define AUDIO_FIFO_OFFSET   0x0040

#define AUDIO_WRITE_SPACE_MASK 0x00FF0000

#endif
