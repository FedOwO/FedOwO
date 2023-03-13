C_SOURCES	= $(wildcard ./src/kernel/*.c)
HEADERS		= $(wildcard ./src/kernel/*.h)

OBJ = ${C_SOURCES:.c=.o}

CC	=	i386-elf-gcc
LD	=	i386-elf-ld

CFLAGS = -g -ffreestanding -Wall -Wextra -fno-exceptions -m32

all: floppy

# Built only the needed files
os-image.bin: boot.bin kernel.bin
	cat ./src/boot-sector/boot.bin ./src/kernel/kernel.bin > os-image.bin

kernel.bin: kernel-entry.o ${OBJ}
	$(LD) -o ./src/kernel/kernel.bin -Ttext 0x1000 ./src/kernel/kernel-entry.o ./src/kernel/kernel.o --oformat binary

kernel-entry.o:
	nasm ./src/kernel/kernel-entry.asm -f elf -o ./src/kernel/kernel-entry.o

boot.bin:
	nasm ./src/boot-sector/boot.asm -f bin -o ./src/boot-sector/boot.bin

floppy: os-image.bin
	qemu-system-i386 -fda os-image.bin

drive:
	qemu-system-i386 -drive format=raw,file=os-image.bin

clean:
	find -name "*.bin" -delete -o -name "*.o" -delete -o -name "*.dis" -delete

re: clean all

debugkernel:
	ndisasm -b 32 ./src/kernel/kernel.bin

# Generic rules for wildcards
# To make an object, always compile from its .c
%.o: %.c ${HEADERS}
	${CC} ${CFLAGS} -c $< -o $@

%.o: %.asm
	nasm $< -f elf -o $@

%.bin: %.asm
	nasm $< -f bin -o $@
