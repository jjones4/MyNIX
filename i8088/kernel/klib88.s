# This file contains a number of assembly code utility routines needed by the
# kernel.  They are:
#
#   phys_copy:	copies data from anywhere to anywhere in memory
#   cp_mess:	copies messages from source to destination
#   port_out:	outputs data on an I/O port
#   port_in:	inputs data from an I/O port
#   lock:	disable interrupts
#   unlock:	enable interrupts
#   restore:	restore interrupts (enable/disabled) as they were before lock()
#   build_sig:	build 4 word structure pushed onto stack for signals
#   csv:	procedure prolog to save the registers
#   cret:	procedure epilog to restore the registers
#   get_chrome:	returns 0 is display is monochrome, 1 if it is color
#   vid_copy:	copy data to video ram (on color display during retrace only)
#   get_byte:	reads a byte from a user program and returns it as value
#   reboot:	reboot for CTRL-ALT-DEL
#   wreboot:	wait for character then reboot 

# The following procedures are defined in this file and called from outside it.
.global lock, restore

# The following external procedure is called in this file.

# Variables and data structures

#*===========================================================================*
#*				lock	                                				     *
#*===========================================================================*
# Disable CPU interrupts.

.type lock, @function

lock:
    pushf                   # save flags on stack
    cli                     # disable interrupts
    pop lockvar             # save flags for possible restoration later
    ret                     # return to caller

#*===========================================================================*
#*				restore					                                     *
#*===========================================================================*
# Restore enable/disable bit to the value it had before last lock.
restore:
	push lockvar		    # push flags as they were before previous lock
	popf			        # restore flags
	ret			            # return to caller

.data

lockvar:        .word 0     # place to stor flags for lock()/restore()
