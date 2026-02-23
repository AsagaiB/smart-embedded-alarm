#include <stdint.h>
#include "fpga_regs.h"

extern volatile uint32_t *lw_bridge;

void audio_init() {
    // Basic stub for audio initialization
}

static int audio_write_space_available() {
    uint32_t status = *(lw_bridge + (AUDIO_FIFO_OFFSET / 4));
    return (status & AUDIO_WRITE_SPACE_MASK);
}

static void audio_write_sample(int sample) {
    *(lw_bridge + (AUDIO_FIFO_OFFSET / 4)) = sample;
}

void audio_generate_alarm_tone() {
    for (int i = 0; i < 2000; i++) {
        if (audio_write_space_available()) {
            audio_write_sample(3000);
            audio_write_sample(-3000);
        }
    }
}
