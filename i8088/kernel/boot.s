# Multiboot 1 Header Constants
.section .data
.set MAGIC,    0x1BADB002       # 'magic number' lets bootloader find the header
.set FLAGS,    0x00000003       # align modules and provide memory map
.set CHECKSUM, -(MAGIC + FLAGS) # checksum to prove we are multiboot

# Declare the multiboot header
.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

# Allocate space for a small stack (16 Kilobytes)
.section .bss
.align 16
stack_bottom:
.skip 16384 # 16 KiB
stack_top:

# The linker looks for '_start' as the entry point
.section .text
.global _start
_start:
    # Set up the stack pointer
    mov $stack_top, %esp

    # Call your C main function
    call main

    # If kernel_main returns, halt the CPU loops forever
_halt:
    cli
    hlt
    jmp _halt

.section .note.GNU-stack,"",@progbits
