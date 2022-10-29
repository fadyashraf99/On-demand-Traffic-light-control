/*
 * app.h
 *
 * Created: 10/25/2022 6:04:15 PM
 *  Author: FADY
 */ 


#ifndef APP_H_
#define APP_H_

/*	all files includes	*/
#include "../ECUAL/LED Driver/led.h"
#include "../ECUAL/Button Driver/button.h"
#include "../MCAL/Timer Driver/timer.h"
#include "../MCAL/Interrupt Driver/interrupt.h"

/*	modes defined names	*/
#define NORMAL_MODE			0
#define PEDESTRIAN_MODE		1

/*	application function prototypes	*/
void APP_init(void);	//application initialization 
void APP_start(void);	//application execution

#endif /* APP_H_ */