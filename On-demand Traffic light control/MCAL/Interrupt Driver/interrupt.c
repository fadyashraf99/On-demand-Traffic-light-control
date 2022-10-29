/*
 * interrupt.c
 *
 * Created: 10/25/2022 6:07:54 PM
 *  Author: FADY
 */ 

#include "interrupt.h"

//this function takes void and return void
//SET global interrupt enable, choose control sense of interrupt and enable external interrupt 0
void INT0_init(void)
{
	//  enable global interrupt
	sei(); // SET_BIT(SREG,7);
	// RISING EDGE
	SET_BIT(MCUCR, 0);
	SET_BIT(MCUCR, 1);
	// enable external interrupt
	SET_BIT(GICR, 6);
}