/* Copyright (C) 1987 by Prentice-Hall, Inc.  Permission is hereby granted to
 * private individuals and educational institutions to modify and
 * redistribute the binary and source programs of this system to other
 * private individuals and educational institutions for educational and
 * research purposes.  For corporate or commercial use, permission from
 * Prentice-Hall is required.  In general, such permission will be granted,
 * subject to a few conditions.
 */

/*
 * Directory h contains files defining constants, types, and macros needed in
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

#define EXTERN		        extern		/* used in *.h files */
#define PRIVATE		        static		/* PRIVATE x limits the scope of x */
#define PUBLIC  		    	    	/* PUBLIC is the opposite of PRIVATE */
#define FORWARD	    	        		/* some compilers require this to be 'static' */

#define TRUE		        1   		/* used for turning integers into Booleans */
#define FALSE		        0	    	/* used for turning integers into Booleans */

#define HZ	    	        60	       	/* clock freq (software settable on IBM-PC) */
#define BLOCK_SIZE	        1024		/* # bytes in a disk block */
#define SUPER_USER	        (uid) 0		/* uid of superuser */

/*
 * Major device number: specifies device type: e.g. floppy, hdd, or terminal
 * Minor device number: identifies a device within a given class
 *
 * Tanenbaum, Andrew S. 1987. Operating Systems: Design and Implementation.
 * Englewood Cliffs, NJ: Prentice-Hall.
 * Section 1.3.2
 */
#define MAJOR		        8	    	/* major device = (dev>>MAJOR) & 0377 */
#define MINOR		        0	    	/* minor device = (dev>>MINOR) & 0377 */

#define NR_TASKS            8           /* number of tasks in the transfer vector */
#define NR_PROCS            16          /* number of slots in proc table */

/* 
 * Segments of a process: text, data, and stack
 *
 * Tanenbaum, Andrew S. 1987. Operating Systems: Design and Implementation.
 * Englewood Cliffs, NJ: Prentice-Hall.
 * Section 1.4.1
 */
#define NR_SEGS             3           /* # segments per process */

#define T                   0           /* proc[i].mem_map[T] is for text */
#define D                   1           /* proc[i].mem_map[D] is for data */
#define S                   2           /* proc[i].mem_map[S] is for stack */

#define MAX_P_LONG          2147483647  /* maximum positive long, i.e. 2^31 - 1 */

/* Memory is allocated in clicks. */
#define CLICK_SIZE          0020        /* unit in which memory is allocated */
#define CLICK_SHIFT         4           /* log2 of CLICK_SIZE */

/* Process numbers of some important processes */
#define MM_PROC_NR          0           /* process number of memory manager */
#define FS_PROC_NR          1           /* process number of file system */
#define INIT_PROC_NR        2           /* init -- the process that goes multiuser */
#define LOW_USER            2           /* first user not part of operating system */

/* Miscellaneous */
#define BYTE                0377        /* mask for 8 bits */
#define TO_USER             0           /* flag telling to copy from fs to user */
#define FROM_USER           1           /* flag telling to copy from user to fs */
#define READING             0           /* copy data to user */
#define WRITING             1           /* copy data from user */
#define ABS                 -999        /* this process means absolute memory */

#define WORD_SIZE           2           /* number of bytes per world */

#define NIL_PTR             (char *) 0  /* generally useful expression */

#define NO_NUM              0x8000      /* used as numerical argument to panic() */
#define MAX_PATH            128         /* max length of path names */

/*
 * Operating system signals a process when (among other reasons):
 *  1. Process' timer expires
 *  2. Process executes illegal instruction (trap detected by hardware)
 *  3. Process tries to use invalid address (trap detected by hardware)
 *
 * Tanenbaum, Andrew S. 1987. Operating Systems: Design and Implementation.
 * Englewood Cliffs, NJ: Prentice-Hall.
 * Section 1.3.1
 */
#define SIG_PUSH_BYTES      8           /* how many bytes pushed by signal */
#define MAX_ISTACK_BYTES    1024        /* maximum initial stack size for EXEC */

/* Device numbers of root (RAM) and boot (fd0) devices */
#define ROOT_DEV (dev_nr)   256         /* major-minor device number of root dev */
#define BOOT_DEV (dev_nr)   512         /* major-minor device number of boot diskette */

/* Flag bits for i_mode in the inode */
#define I_TYPE              0170000     /* this field gives inode type */
#define I_REGULAR           0100000     /* regular file, not dir or special */
#define I_BLOCK_SPECIAL     0060000     /* block special file */
#define I_DIRECTORY         0040000     /* file is a directory */
#define I_CHAR_SPECIAL      0020000     /* character special file */
#define I_SET_UID_BIT       0004000     /* set effective uid on exec */
#define I_SET_GID_BIT       0002000     /* set effective gid on exec */
#define ALL_MODES           0006777     /* all bits for user, group and others */
#define RWX_MODES           0000777     /* mode bits for RWX only */
#define R_BIT               0000004     /* Rwx protection bit */
#define W_BIT               0000002     /* rWx protection bit */
#define X_BIT               0000001     /* rwX protection bit */
#define I_NOT_ALLOC         0000000     /* this inode is free */

