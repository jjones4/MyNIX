# MyNIX

This project is for learning purposes.

My learning path is the following:
1. Add documentation to MyNIX source code as I learn.
2. Make MyNIX C89 compliant as I add and test code.
3. Get MyNIX working on x86 in QEMU by writing the assembly for 32 bit protected mode and compiling with m32 flag.

Status:  

We currently boot in QEMU, and 'MyNIX LN=0917' is displayed on the screen. LN=0917 is the line number in the source code listing up to which the code is working in QEMU from main.c.

Use the following to run MyNIX in QEMU after running make:  
&emsp; qemu-system-i386 -kernel MyNIX.elf

The project incorporates educational code from MINIX 1, Andrew S. Tanenbaum.

Tanenbaum, Andrew S. 1987. Operating Systems: Design and Implementation.  
&emsp; Englewood Cliffs, NJ: Prentice-Hall.
