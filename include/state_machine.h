#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

typedef enum {
    IDLE,
    CONFIG,
    ARMED,
    ALARM_ACTIVE
} system_state_t;

void handle_state(system_state_t *state);

#endif
