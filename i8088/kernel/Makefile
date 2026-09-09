# Toolchain
CC = gcc -m32
AS = gcc -m32
LD = gcc -m32

# Compiler and Linker flags
CFLAGS  = -Di8088 -g -fno-pie -ffreestanding -std=c89 -O2 -Wall -Wextra -Wpedantic -Wformat=2 -Wno-unused-parameter -Wshadow -Wwrite-strings -Wstrict-prototypes -Wold-style-definition -Wredundant-decls -Wnested-externs -Wmissing-include-dirs -Wjump-misses-init -Wlogical-op -Wmissing-prototypes -Wdeclaration-after-statement

ASFLAGS = -g -c -fno-pie -ffreestanding -nostdlib

LDFLAGS = -T linker.ld -nostdlib -z -noexecstack -ffreestanding

# Object files
OBJS = boot.o clock.o floppy.o main.o memory.o printer.o proc.o system.o table.o tty.o wini.o

# Define the default target at the very top
all: MyNIX.bin

#Link
MyNIX.bin: $(OBJS)
	$(LD) $(LDFLAGS) -o MyNIX.bin $(OBJS)

# Boot file
boot.o: boot.s
	$(AS) $(ASFLAGS) -c boot.s -o boot.o

#Source files
clock.o: clock.c
	$(CC) $(CFLAGS) -c clock.c -o clock.o

floppy.o: floppy.c
	$(CC) $(CFLAGS) -c floppy.c -o floppy.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

memory.o: memory.c
	$(CC) $(CFLAGS) -c memory.c -o memory.o

printer.o: printer.c
	$(CC) $(CFLAGS) -c printer.c -o printer.o

proc.o: proc.c
	$(CC) $(CFLAGS) -c proc.c -o proc.o

system.o: system.c
	$(CC) $(CFLAGS) -c system.c -o system.o

table.o: table.c
	$(CC) $(CFLAGS) -c table.c -o table.o

tty.o: tty.c
	$(CC) $(CFLAGS) -c tty.c -o tty.o

wini.o: wini.c
	$(CC) $(CFLAGS) -c wini.c -o wini.o
