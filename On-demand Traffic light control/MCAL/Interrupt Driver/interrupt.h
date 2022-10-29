/*
 * interrupt_.h
 *
 * Created: 10/25/2022 6:07:47 PM
 *  Author: FADY
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include "../../Utilities/registers.h"
#include "../../Utilities/Bit_manipulation.h"

/*	External Interrupt Request 0	*/
#define EXT_INT_0		__vector_1

/*	Set Global Interrupts, Set the I-bit in status register to 1 	*/
#define sei() __asm__ __volatile__ ("sei" ::: "memory")
/*	Clear Global Interrupts, Set the I-bit in status register to 0 	*/
#define cli() __asm__ __volatile__ ("cli" ::: "memory")

/* Macro defines the ISR */
#define ISR(INT_VECT)void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void)


/*	Functions Prototypes	*/
void INT0_init(void);	// interrupt initialization function configurations 

#endif /* INTERRUPT_H_ */