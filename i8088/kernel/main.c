/* This file contains the main program of MINIX.  The routine main()
 * initializes the system and starts the ball rolling by setting up the proc
 * table, interrupt vectors, and scheduling each task to run to initialize
 * itself.
 * 
 * The entries into this file are:
 *   main:		MINIX main program
 *   unexpected_int:	called when an interrupt to an unused vector < 16 occurs
 *   trap:		called when an unexpected trap to a vector >= 16 occurs
 *   panic:		abort MINIX due to a fatal error
 */

#include "../h/const.h"
#include "../h/type.h"
#include "../h/callnr.h"
#include "../h/com.h"
#include "../h/error.h"
#include "const.h"
#include "type.h"
#include "glo.h"
#include "proc.h"

#define SAFETY             8	/* margin of safety for stack overflow (ints)*/
#define VERY_BIG       39328	/* must be bigger than kernel size (clicks) */
#define BASE            1536	/* address where MINIX starts in memory */
#define SIZES              8	/* sizes array has 8 entries */
#define CPU_TY1       0xFFFF	/* BIOS segment that tells CPU type */
#define CPU_TY2       0x000E	/* BIOS offset that tells CPU type */
#define PC_AT           0xFC	/* IBM code for PC-AT (in BIOS at 0xFFFFE) */

/*============================================================================*
 *                                   main                                     *
 *============================================================================*/
PUBLIC int main(void)
{
    /*Start the ball rolling. */
    
    register struct proc *rp;
    register int t;

    /* Set up proc table entry for user processes.  Be very careful about
   * sp, since the 3 words prior to it will be clobbered when the kernel pushes
   * pc, cs, and psw onto the USER's stack when starting the user the first
   * time.  This means that with initial sp = 0x10, user programs must leave 
   * the words at 0x000A, 0x000C, and 0x000E free.
   */

    for (rp = &proc[0]; rp <= &proc[NR_TASKS + LOW_USER]; rp++) {
        for (t = 0; t < NR_REGS; t++) rp->p_reg[t] = 0100 * t;  /* DEBUG */
        t = rp - proc - NR_TASKS;                               /* task number */
        rp->p_sp = (rp < &proc[NR_TASKS] ? t_stack[NR_TASKS + t + 1].stk : INIT_SP);
        rp->p_splimit = rp->p_sp;
        if (rp->p_splimit != INIT_SP)
            rp->p_splimit -= (TASK_STACK_BYTES - SAFETY) / sizeof(int);        
    }

    return 0;
}
