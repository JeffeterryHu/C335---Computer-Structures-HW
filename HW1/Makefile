CC = arm-none-eabi-gcc
AS = arm-none-eabi-as
CFLAGS = -g
LDFLAGS =
AS =

HW1.elf: test.o t1.o
	$(CC) -g -mcpu=cortex-m0 -mthumb --specs=rdimon.specs -lc -lrdimon test.o t1.o -o HW1.elf

test.o: test.c t1.s
	$(CC) -g -c -O1 -mcpu=cortex-m0 -mthumb test.c t1.s

t1.o: t1.s
	$(AS) -g -mcpu=cortex-m0 -mthumb t1.s -o t1.o

test: HW1.elf
	qemu-system-arm -machine versatilepb -cpu cortex-m3 -nographic \
		-monitor null -serial null \
		-semihosting -kernel HW1.elf

clean:
	rm test.o t1.o HW1.elf

