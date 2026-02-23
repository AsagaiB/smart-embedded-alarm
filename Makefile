CC = arm-linux-gnueabihf-gcc
CFLAGS = -Wall -O2 -Iinclude

SRC = src/main.c src/gpio.c src/audio.c src/state_machine.c src/fpga_interface.c
OUT = alarm_app

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)
