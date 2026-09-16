/* For enabling/disabling interrupts and restoring flags */

#ifndef K_INTERRUPTS_H
#define K_INTERRUPTS_H

void lock(void);
void restore(void);

#endif                      /* K_INTERRUPTS_H */
