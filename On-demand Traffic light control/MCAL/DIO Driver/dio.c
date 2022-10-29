/*
 * dio.c
 *
 * Created: 10/25/2022 6:07:10 PM
 *  Author: FADY
 */ 

#include "dio.h"

//this function takes the number of port and pin and how it acts and return void
//it determine if the pin will be input or output
void DIO_init(uint8_t portNumber, uint8_t pinNumber, uint8_t direction)
{
	switch(portNumber)
	{
		case PORT_A:
		if (direction == IN)
		{
			CLR_BIT(DDRA, pinNumber); // input
		}
		else if (direction == OUT)
		{
			SET_BIT(DDRA, pinNumber); // output
		}
		else
		{
			//error handling
		}
		break;

		case PORT_B:
		if (direction == IN)
		{
			CLR_BIT(DDRB, pinNumber); // input
		}
		else if (direction == OUT)
		{
			SET_BIT(DDRB, pinNumber); // output
		}
		else
		{
			//error handling
		}
		break;
		
		case PORT_C:
		if (direction == IN)
		{
			CLR_BIT(DDRC, pinNumber); // input
		}
		else if (direction == OUT)
		{
			SET_BIT(DDRC, pinNumber); // output
		}
		else
		{
			//error handling
		}
		break;
		
		case PORT_D:
		if (direction == IN)
		{
			CLR_BIT(DDRD, pinNumber); // input
		}
		else if (direction == OUT)
		{
			SET_BIT(DDRD, pinNumber); // output
		}
		else
		{
			//error handling
		}
		break;
	}
}

//this function takes the number of port and pin and its state and return void
//it determine if the output pin will be high or low
void DIO_write(uint8_t portNumber, uint8_t pinNumber, uint8_t state)
{
	switch(portNumber)
	{
		case PORT_A:
		if (state == LOW)
		{
			CLR_BIT(PORTA, pinNumber); // write 0
		}
		else if (state == OUT)
		{
			SET_BIT(PORTA, pinNumber); // write 1
		}
		else
		{
			//error handling
		}
		break;

		case PORT_B:
		if (state == LOW)
		{
			CLR_BIT(PORTB, pinNumber); // write 0
		}
		else if (state == OUT)
		{
			SET_BIT(PORTB, pinNumber); // write 1
		}
		else
		{
			//error handling
		}
		break;
		
		case PORT_C:
		if (state == LOW)
		{
			CLR_BIT(PORTC, pinNumber); // write 0
		}
		else if (state == OUT)
		{
			SET_BIT(PORTC, pinNumber); // write 1
		}
		else
		{
			//error handling
		}
		break;
		
		case PORT_D:
		if (state == LOW)
		{
			CLR_BIT(PORTC, pinNumber); // write 0
		}
		else if (state == OUT)
		{
			SET_BIT(PORTC, pinNumber); // write 1
		}
		else
		{
			//error handling
		}
		break;
	}
}

//this function takes the number of port and pin and return void
//it toggles the state of the pin as if it is low it will be high and vice versa
void DIO_toggle(uint8_t portNumber, uint8_t pinNumber)
{
	switch(portNumber)
	{
		case PORT_A:
		TOGGLE_BIT(PORTA,pinNumber); // toggle
		break;

		case PORT_B:
		TOGGLE_BIT(PORTB,pinNumber); // toggle
		break;
		
		case PORT_C:
		TOGGLE_BIT(PORTC,pinNumber); // toggle
		break;
		
		case PORT_D:
		TOGGLE_BIT(PORTD,pinNumber); // toggle
		break;
	}
}

//this function takes the number of port and pin and return uint8_t
//it determine the state of the pin if it is high or low
uint8_t DIO_read(uint8_t portNumber, uint8_t pinNumber)
{
	uint8_t state;
	switch(portNumber)
	{
		case PORT_A:
		state = GET_BIT(PINA, pinNumber); //get state -> read bit
		break;

		case PORT_B:
		state = GET_BIT(PINB, pinNumber); //get state -> read bit
		break;
		
		case PORT_C:
		state = GET_BIT(PINC, pinNumber); //get state -> read bit
		break;
		
		case PORT_D:
		state = GET_BIT(PIND, pinNumber); //get state -> read bit
		break;
		
		default:
		// error handling
		break;
	}
	return state;
}
