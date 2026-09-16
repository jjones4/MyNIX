/* This file contains essentially all of the process and message handling.
 * It has two main entry points from the outside:
 *
 *   sys_call:   called when a process or task does SEND, RECEIVE or SENDREC
 *   interrupt:	called by interrupt routines to send a message to task
 *
 * It also has five minor entry points:
 *
 *   ready:	put a process on one of the ready queues so it can be run
 *   unready:	remove a process from the ready queues
 *   sched:	a process has run too long; schedule another one
 *   mini_send:	send a message (used by interrupt signals, etc.)
 *   pick_proc:	pick a process to run (used by system initialization)
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
#include "interrupt.h"

/*===========================================================================*
 *				ready					                                     * 
 *===========================================================================*/

void ready(register struct proc *rp)        /* this process is now runnable */
{
    /* Add 'rp' to the end of one of the queues of runnable processes. Three
     * queues are maintained:
     *   TASK_Q   - (highest priority) for runnable tasks
     *   SERVER_Q - (middle priority) for MM and FS only
     *   USER_Q   - (lowest priority) for user processes
     */

    register int q;                         /* TASK_Q, SERVER_Q, or USER_Q */
    int r;
    
    lock();                                 /* disable interrupts */
    r = (rp - proc) - NR_TASKS;             /* task or proc number */
    q = (r < 0 ? TASK_Q : r < LOW_USER ? SERVER_Q : USER_Q);
    
    /* See if the relevant queue is empty. */
    if (rdy_head[q] == NIL_PROC)
        rdy_head[q] = rp;                   /* add to empty queue  */
    else
        rdy_tail[q]->p_nextready = rp;      /* add to tail of nonempty queue */
    rdy_tail[q] = rp;
    rp->p_nextready = NIL_PROC;
    restore();                               /* restore interrupts to previous state */
}
