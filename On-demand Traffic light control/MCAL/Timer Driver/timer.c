/*
 * timer.c
 *
 * Created: 10/25/2022 6:08:38 PM
 *  Author: FADY
 */ 

#include "timer.h"

 //This function takes void and return void and sets timer configuration
 //1) setting timer initial value
 //2) mode of operation
 //3) setting timer prescaler
void TIMER_init(void)
{
	// timer set initial value
	TCNT0 = 0;
	//NORMAL MODE
	CLR_BIT(TCCR0, 6);
	CLR_BIT(TCCR0, 3);
	// COMPARE DISCONNECTED
	CLR_BIT(TCCR0, 4);
	CLR_BIT(TCCR0, 5);
	// PRESCALER 1024
	SET_BIT(TCCR0, 0);
	CLR_BIT(TCCR0, 1);
	SET_BIT(TCCR0, 2);
}

//This function takes The required delay time in ms and return void
// calculate tick time and max delay for this timer and check for three cases to calculate timer initial value and no. of over flows needed
void TIMER_delay(uint32_t delayTimer)
{
	uint32_t overflowCounter=0, numberOfOverflows;
	double tMaxDelay ,tTick;
	int initialTimer;
	
	// at Frequency 1MHZ & prescaler 1024
	//T_tick= prescaler/ CPU frequency
	tTick = 1024.0 / 1000.0; // milLi second
	// Tmaxdelay = Ttick * 2^n -> 8-bit timer
	tMaxDelay = tTick * 256; // milli seconds
	
	if(delayTimer<tMaxDelay)
	{
		initialTimer = (tMaxDelay-delayTimer)/tTick;
		numberOfOverflows = 1;
	}
	
	else if(delayTimer == (int)tMaxDelay)
	{
		initialTimer=0;
		numberOfOverflows=1;
	}
	
	else
	{
		numberOfOverflows = ceil((double)delayTimer/tMaxDelay);
		initialTimer = 256 - ((double)delayTimer/tTick)/numberOfOverflows;
	}
	
	// busy waiting for over flow flag
	while (overflowCounter < numberOfOverflows){
		while (( TIFR & (1<<0) )==0 )
		{
			//	 wait for the flag
			if (initFlag)
			{
				break;
			}
		}
		//clear the overflow flag
		SET_BIT(TIFR, 0);
		overflowCounter++;
		if (initFlag)
		{
			initFlag = 0;
			break;
		}
	}
	overflowCounter =0;
}
