/*
 * timer.h
 *
 * Created: 10/25/2022 6:08:30 PM
 *  Author: FADY
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include <math.h>
#include "../../Utilities/registers.h"
#include "../../Utilities/Bit_manipulation.h"

extern uint8_t initFlag;	// flag to indicate if any interruption happened so it skips the timer wait loop and set extern for the usage in different files


/*	Function Prototypes	*/

void TIMER_init(void);					// timer initialization function configurations 
void TIMER_delay(uint32_t delayTimer);	// timer delay function and called when specific delay required

#endif /* TIMER_H_ */