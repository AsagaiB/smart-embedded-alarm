#include <stdint.h>
#include "fpga_regs.h"

extern volatile uint32_t *lw_bridge;

int read_switches() {
    return *(lw_bridge + (SWITCH_OFFSET / 4));
}

int read_buttons() {
    return *(lw_bridge + (BUTTON_OFFSET / 4));
}

void write_leds(int value) {
    *(lw_bridge + (LED_OFFSET / 4)) = value;
}

void write_hex(int value) {
    *(lw_bridge + (HEX_OFFSET / 4)) = value;
}
