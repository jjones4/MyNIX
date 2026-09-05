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

PUBLIC void ready(register struct proc *rp)
{

}
