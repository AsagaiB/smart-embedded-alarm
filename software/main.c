
// main.c
// HPS application to control FPGA LEDs

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdint.h>

#define LW_BRIDGE_BASE 0xFF200000
#define LW_BRIDGE_SPAN 0x00005000
#define LED_BASE       0x00000000
#define SWITCH_BASE    0x00000010

int main() {

    int fd;
    void *virtual_base;
    volatile uint32_t *led_ptr;
    volatile uint32_t *switch_ptr;

    fd = open("/dev/mem", O_RDWR | O_SYNC);
    if (fd < 0) {
        printf("ERROR: could not open /dev/mem\n");
        return 1;
    }

    virtual_base = mmap(NULL, LW_BRIDGE_SPAN,
                        PROT_READ | PROT_WRITE,
                        MAP_SHARED, fd, LW_BRIDGE_BASE);

    if (virtual_base == MAP_FAILED) {
        printf("ERROR: mmap failed\n");
        close(fd);
        return 1;
    }

    led_ptr    = (uint32_t *)(virtual_base + LED_BASE);
    switch_ptr = (uint32_t *)(virtual_base + SWITCH_BASE);

    while (1) {
        *led_ptr = *switch_ptr;
        usleep(100000);
    }

    munmap(virtual_base, LW_BRIDGE_SPAN);
    close(fd);
    return 0;
}
