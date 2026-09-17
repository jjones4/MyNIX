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

#include <stdint.h>             /* For printing characters */
#include "../h/const.h"
#include "../h/type.h"
#include "../h/callnr.h"
#include "../h/com.h"
#include "../h/error.h"
#include "const.h"
#include "type.h"
#include "glo.h"
#include "proc.h"
#include "interrupt.h"

#define SAFETY          8       /* margin of safety for stack overflow (ints) */

extern int (*task[])(void);

/*============================================================================*
 *                                   main                                     *
 *============================================================================*/

int main(void)
{
    int i;
    register struct proc *rp;
    register int t;

    __volatile__ uint16_t* vga_buffer = (__volatile__ uint16_t*)0xB8000;

    for(i = 0; i < 114; i++)
        vga_buffer[i] = ' ' | (0x0F << 8);

    vga_buffer[114] = 'M' | (0x0F << 8);
    vga_buffer[115] = 'y' | (0x0F << 8);
    vga_buffer[116] = 'N' | (0x0F << 8);
    vga_buffer[117] = 'I' | (0x0F << 8);
    vga_buffer[118] = 'X' | (0x0F << 8);

    for(i = 119; i < 513; i++)
        vga_buffer[i] = ' ' | (0x0F << 8);

    /* Set up proc table entry for user processes.  Be very careful about
     * sp, since the 3 words prior to it will be clobbered when the kernel pushes
     * pc, cs, and psw onto the USER's stack when starting the user the first
     * time.  This means that with initial sp = 0x10, user programs must leave 
     * the words at 0x000A, 0x000C, and 0x000E free.
     */

    lock();
    
    for (rp = &proc[0]; rp <= &proc[NR_TASKS + LOW_USER]; rp++) {
        for (t = 0; t < NR_REGS; t++) rp->p_reg[t] = 0100 * t; /* DEBUG */
        t = rp - proc - NR_TASKS;       /* task number */
        rp->p_sp = (rp < &proc[NR_TASKS] ? t_stack[NR_TASKS + t + 1].stk : INIT_SP);        
        rp->p_splimit = rp->p_sp;
        if (rp->p_splimit != INIT_SP)
            rp->p_splimit -= (TASK_STACK_BYTES - SAFETY) / sizeof(int);
        rp->p_pcpsw.pc = task[t + NR_TASKS];
        if (rp->p_pcpsw.pc != 0 || t >= 0) ready(rp);
        rp->p_pcpsw.psw = INIT_PSW;
        rp->p_flags = 0;
    }

    vga_buffer[513] = 'L' | (0x0F << 8);
    vga_buffer[514] = 'N' | (0x0F << 8);
    vga_buffer[515] = '=' | (0x0F << 8);
    vga_buffer[516] = '0' | (0x0F << 8);
    vga_buffer[517] = '9' | (0x0F << 8);
    vga_buffer[518] = '1' | (0x0F << 8);
    vga_buffer[519] = '7' | (0x0F << 8);

    for(i = 520; i < 801; i++)
        vga_buffer[i] = ' ' | (0x0F << 8);

    return 0;
}
