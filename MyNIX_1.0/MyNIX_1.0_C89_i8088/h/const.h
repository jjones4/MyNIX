/* Copyright (C) 1987 by Prentice-Hall, Inc.  Permission is hereby granted to
 * private individuals and educational institutions to modify and
 * redistribute the binary and source programs of this system to other
 * private individuals and educational institutions for educational and
 * research purposes.  For corporate or commercial use, permission from
 * Prentice-Hall is required.  In general, such permission will be granted,
 * subject to a few conditions.
 */

/*
 * Directory h contains files defining constants, types, and macros needed  in
 * more than one of the following independent parts (programs) of MINIX:
 *  1. Kernel
 *  2. Memory Manager
 *  3. File System
 *  4. Init
 *
 * Tanenbaum, Andrew S. 1987. Operating Systems: Design and Implementation.
 * Englewood Cliffs, NJ: Prentice-Hall.
 * Sections 2.6.1 - 2.6.2
 */

#define EXTERN		extern	/* used in *.h files */
#define PRIVATE		static	/* PRIVATE x limits the scope of x */

