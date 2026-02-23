#include "state_machine.h"
#include "gpio.h"
#include "audio.h"

extern int read_switches();
extern int read_buttons();

void handle_state(system_state_t *state) {

    int buttons = read_buttons();
    int switches = read_switches();

    switch (*state) {

        case IDLE:
            write_leds(0x00);
            if (buttons & 0x1)
                *state = CONFIG;
            break;

        case CONFIG:
            write_hex(switches);
            if (buttons & 0x2)
                *state = ARMED;
            break;

        case ARMED:
            write_leds(0x01);
            if (switches & 0x1)
                *state = ALARM_ACTIVE;
            break;

        case ALARM_ACTIVE:
            write_leds(0xFF);
            audio_generate_alarm_tone();
            if (buttons & 0x4)
                *state = IDLE;
            break;
    }
}
