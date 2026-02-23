#include <stdio.h>
#include <unistd.h>
#include "gpio.h"
#include "audio.h"
#include "state_machine.h"

int main() {

    system_state_t state = IDLE;

    gpio_init();
    audio_init();

    printf("Smart Embedded Alarm System Started\n");

    while (1) {
        handle_state(&state);
        usleep(10000);
    }

    return 0;
}
