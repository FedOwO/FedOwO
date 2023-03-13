all: run

# Built only the needed files
kernel.bin: kernel-entry.o kernel.o
	/usr/bin/i386elfgcc/bin/i386-elf-ld -o ./src/kernel/kernel.bin -Ttext 0x1000 ./src/kernel/kernel-entry.o ./src/kernel/kernel.o --oformat binary

kernel-entry.o: 
	nasm ./src/kernel/kernel-entry.asm -f elf -o ./src/kernel/kernel-entry.o

kernel.o:
	/usr/bin/i386elfgcc/bin/i386-elf-gcc -ffreestanding -c ./src/kernel/kernel.c -o ./src/kernel/kernel.o

boot.bin: 
	nasm ./src/boot-sector/boot.asm -f bin -o ./src/boot-sector/boot.bin

os-image.bin: boot.bin kernel.bin
	cat ./src/boot-sector/boot.bin > ./src/kernel/kernel.bin

run: os-image.bin
	qemu-system-i386 -fda os-image.bin

clean:
	find . -name "*.bin" -o -name *.o -o -name *.dis