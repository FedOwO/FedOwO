CC	=	i386-elf-gcc
LD	=	i386-elf-ld

all: run

# Built only the needed files
kernel.bin: kernel-entry.o kernel.o
	$(LD) -o ./src/kernel/kernel.bin -Ttext 0x1000 ./src/kernel/kernel-entry.o ./src/kernel/kernel.o --oformat binary

kernel-entry.o:
	nasm ./src/kernel/kernel-entry.asm -f elf -o ./src/kernel/kernel-entry.o

kernel.o:
	$(CC) -ffreestanding -c ./src/kernel/kernel.c -o ./src/kernel/kernel.o

boot.bin:
	nasm ./src/boot-sector/boot.asm -f bin -o ./src/boot-sector/boot.bin

os-image.bin: boot.bin kernel.bin
	cat ./src/boot-sector/boot.bin > os-image.bin

run: os-image.bin
	qemu-system-i386 -fda os-image.bin

clean:
	find -name "*.bin" -delete -o -name "*.o" -delete -o -name "*.dis" -delete
