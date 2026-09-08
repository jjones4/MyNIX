# Target kernel name
TARGET = MyNIX.bin

# Toolchain
CC = gcc -m32
AS = gcc -m32
LD = gcc -m32 

# Compiler and Linker flags
CFLAGS  = -Di8088 -g -fno-pie -ffreestanding -std=c89 -O2 -Wall -Wextra -Wpedantic -Wformat=2 -Wno-unused-parameter -Wshadow -Wwrite-strings -Wstrict-prototypes -Wold-style-definition -Wredundant-decls -Wnested-externs -Wmissing-include-dirs -Wjump-misses-init -Wlogical-op -Wmissing-prototypes -Wdeclaration-after-statement
ASFLAGS = -g -fno-pie -ffreestanding -std=c89 -O2 -Wall -Wextra -Wpedantic -Wformat=2 -Wno-unused-parameter -Wshadow -Wwrite-strings -Wstrict-prototypes -Wold-style-definition -Wredundant-decls -Wnested-externs -Wmissing-include-dirs -Wjump-misses-init -Wlogical-op -Wmissing-prototypes -Wdeclaration-after-statement -c
LDFLAGS = -T linker.ld -nostdlib -z -noexecstack -ffreestanding

# Source files
C_SRCS   = proc.c table.c clock.c system.c tty.c wini.c floppy.c memory.c printer.c  main.c 
ASM_SRCS = boot.s

# Object files (automatically maps .c and .s to .o)
OBJS = $(ASM_SRCS:.s=.o) $(C_SRCS:.c=.o)

# Default rule
all: $(TARGET)

# Link the kernel
$(TARGET): $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $(OBJS)

# Compile C files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Assemble Assembly files
%.o: %.s
	$(AS) $(ASFLAGS) $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean

