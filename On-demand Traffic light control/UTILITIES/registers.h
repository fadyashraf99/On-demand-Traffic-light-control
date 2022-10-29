/*
 * registers.h
 *
 * Created: 10/25/2022 6:02:38 PM
 *  Author: FADY
 */ 

#ifndef REGISTERS_H_
#define REGISTERS_H_

#include "types.h"

/*	all required registers for the project	*/

/*	Status Register	*/
#define SREG *((volatile uint8_t*)0x5F) //Status Register

/*	DIO Registers	*/
//PORTA registers
#define PORTA *((volatile uint8_t*)0x3B) //8-bit register
#define DDRA *((volatile uint8_t*)0x3A) //8-bit register
#define PINA *((volatile uint8_t*)0x39) //8-bit register

//PORTB registers
#define PORTB *((volatile uint8_t*)0x38) //8-bit register
#define DDRB *((volatile uint8_t*)0x37) //8-bit register
#define PINB *((volatile uint8_t*)0x36) //8-bit register

//PORTC registers
#define PORTC *((volatile uint8_t*)0x35) //8-bit register
#define DDRC *((volatile uint8_t*)0x34) //8-bit register
#define PINC *((volatile uint8_t*)0x33) //8-bit register

//PORTD registers
#define PORTD *((volatile uint8_t*)0x32) //8-bit register
#define DDRD *((volatile uint8_t*)0x31) //8-bit register
#define PIND *((volatile uint8_t*)0x30) //8-bit register


/*	Timer Registers	*/
#define TIFR *((volatile uint8_t*)0x58) //Timer Interrupt Flag Register – TIFR
#define TIMSK *((volatile uint8_t*)0x59) //Timer Interrupt Mask Register – TIMSK
#define ASSR *((volatile uint8_t*)0x42) //Asynchronous Status Register – ASSR
#define SFIOR *((volatile uint8_t*)0x50) //Special Function IO Register – SFIOR

/*	Timer-0 Registers	*/
#define TCCR0 *((volatile uint8_t*)0x53) //Timer0 Control Register – TCCR0
#define TCNT0 *((volatile uint8_t*)0x52) //Timer0 data register (initial value)(counter that increment) – TCNT0
#define OCR0 *((volatile uint8_t*)0x5C) //Output Compare Register – OCR0


/*	External Interrupt	*/
#define MCUCR *((volatile uint8_t*)0x55) //MCU Control Register (for int0 and int1) – MCUCR
#define MCUCSR *((volatile uint8_t*)0x54) //MCU Control and Status Register (for int2) – MCUCSR
#define GICR *((volatile uint8_t*)0x5B) //General Interrupt Control Register (enable external interrupts) – GICR
#define GIFR *((volatile uint8_t*)0x5A) //General Interrupt Flag Register – GIFR

#endif /* REGISTERS_H_ */