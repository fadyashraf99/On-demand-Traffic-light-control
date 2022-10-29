/*
 * led.h
 *
 * Created: 10/25/2022 6:05:37 PM
 *  Author: FADY
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO Driver/dio.h"
#include "../../MCAL/Timer Driver/timer.h"


/*	LED defined names	*/
#define CAR_GREEN_LED_PORT			PORT_A
#define CAR_GREEN_LED_PIN			PIN0
#define CAR_YELLOW_LED_PORT			PORT_A
#define CAR_YELLOW_LED_PIN			PIN1
#define CAR_RED_LED_PORT			PORT_A
#define CAR_RED_LED_PIN				PIN2

#define PEDESTRIAN_GREEN_LED_PORT	PORT_B
#define PEDESTRIAN_GREEN_LED_PIN	PIN0
#define PEDESTRIAN_YELLOW_LED_PORT	PORT_B
#define PEDESTRIAN_YELLOW_LED_PIN	PIN1
#define PEDESTRIAN_RED_LED_PORT		PORT_B
#define PEDESTRIAN_RED_LED_PIN		PIN2

#define TEST_LED1_PORT				PORT_C
#define TEST_LED1_PIN				PIN0
#define TEST_LED2_PORT				PORT_C
#define TEST_LED2_PIN				PIN1


/*	LED function prototypes	*/
void LED_init(void);								//LED initialization function configurations
void LED_on(uint8_t ledPort, uint8_t ledPin);		//set LED state on
void LED_off(uint8_t ledPort, uint8_t ledPin);		//set LED state off
void LED_toggle(uint8_t ledPort, uint8_t ledPin);	//toggle LED state
void LED_blink(uint8_t ledPort, uint8_t ledPin, uint32_t delayTime);	//blink LED for specific time
uint8_t LED_read(uint8_t ledPort, uint8_t ledPin);	//read state of LED
void LED_blink_both(uint32_t delayTime);			//blink 2 specific LEDs for specific time

/*	LED test functions	*/
void LED_init_test(void);

#endif /* LED_H_ */