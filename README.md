# MyNIX
MINIX 1.0

Currently compiling with no errors or warnings:

gcc -Di8088 -std=c89 -O2 -Wall -Wextra -Wpedantic -Wformat=2 -Wno-unused-parameter -Wshadow -Wwrite-strings -Wstrict-prototypes -Wold-style-definition -Wredundant-decls -Wnested-externs -Wmissing-include-dirs -Wjump-misses-init -Wlogical-op -Wmissing-prototypes -Wdeclaration-after-statement -g main.c table.c -o MyNIX

This project is for learning purposes.

Main goals include:
1. Write MyNIX 1.0 to be C89 compliant.
2. Make MyNIX 1.0 POSIX compliant.
3. Write MyNIX 1.0 for i8088 to begin with.
4. Write MyNIX 1.0 for x86_64.
5. Add documentation to the code as I learn.
6. Boot and use MyNIX with QEMU.
7. Build a toolchain to put MyNIX 1.0 on HDD and SSD devices.
8. Run MyNIX 1.0 on PC.
9. Avoid networking for now, as security is a concern.
10. Use MyNIX as a basic, offline OS for text editing, audio, video, selft-hosting, and tool building.
11. Decide if I want to stick with ACK or build in a different compiler (or both).
12. Ensure MyNIX works with some kind of local backup solution (preferably, saving files to a thumb drive).
13. Implement encryption for sensitive files on the disk and support encryption for removable drives.
14. Add a printer/scanner driver.
15. Add support for PDF files.

Design goals include:
1. Keep the code simpler to support security and ease of reading/writing the code, even if efficiency is decreased.
2. Write maintainable code.
3. Code with the future in mind (new hardware, ease of adapting new features, etc.).
4. Keep portability as a high priority. (Make sure non-portable code is in its own place with other such code, and make sure it is easy to distinguish from portable code.)

The project incorporates educational code from MINIX 1, Andrew S. Tanenbaum.
