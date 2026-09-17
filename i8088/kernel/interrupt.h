/* For enabling/disabling interrupts and restoring flags */

#ifndef K_INTERRUPT_H
#define K_INTERRUPT_H

void lock(void);
void restore(void);

#endif                      /* K_INTERRUPT_H */
