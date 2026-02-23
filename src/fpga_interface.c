#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdint.h>
#include "fpga_regs.h"

volatile uint32_t *lw_bridge = NULL;

void gpio_init() {
    int fd = open("/dev/mem", O_RDWR | O_SYNC);
    lw_bridge = mmap(NULL, LW_BRIDGE_SPAN,
                     PROT_READ | PROT_WRITE,
                     MAP_SHARED, fd, LW_BRIDGE_BASE);
}
