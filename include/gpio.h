#ifndef GPIO_H
#define GPIO_H

void gpio_init();
int read_switches();
int read_buttons();
void write_leds(int value);
void write_hex(int value);

#endif
