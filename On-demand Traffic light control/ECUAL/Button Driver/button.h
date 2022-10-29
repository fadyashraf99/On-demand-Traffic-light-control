/*
 * button.h
 *
 * Created: 10/25/2022 6:06:25 PM
 *  Author: FADY
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO Driver/dio.h"

/*	button defined names	*/
#define EXTERNAL_INT0_BUTTON_PORT	PORT_D
#define EXTERNAL_INT0_BUTTON_PIN	PIN2

#define TEST_BUTTON_PORT			PORT_D
#define TEST_BUTTON_PIN				PIN2

//button state macros
#define LOW		0
#define HIGH	1

/*	button function prototypes	*/
void BUTTON_init(void);		// button initialization function configurations 

/*	button test functions	*/
void BUTTON_init_test(void);

#endif /* BUTTON_H_ */