/*
 * led.c
 *
 * Created: 10/25/2022 6:05:45 PM
 *  Author: FADY
 */ 

#include "led.h"

//This function takes void and return void and sets LED configuration
//it sets the pin as an output which will be used as an indication in the program
void LED_init(void)
{
	DIO_init(CAR_GREEN_LED_PORT, CAR_GREEN_LED_PIN, OUT);
	DIO_init(CAR_YELLOW_LED_PORT, CAR_YELLOW_LED_PIN, OUT);
	DIO_init(CAR_RED_LED_PORT, CAR_RED_LED_PIN, OUT);
	
	DIO_init(PEDESTRIAN_GREEN_LED_PORT, PEDESTRIAN_GREEN_LED_PIN, OUT);
	DIO_init(PEDESTRIAN_YELLOW_LED_PORT, PEDESTRIAN_YELLOW_LED_PIN, OUT);
	DIO_init(PEDESTRIAN_RED_LED_PORT, PEDESTRIAN_RED_LED_PIN, OUT);
}

//This function takes led port and led pin and return void
//it sets the state to high
void LED_on(uint8_t ledPort, uint8_t ledPin)
{
	DIO_write(ledPort, ledPin, HIGH);
}

//This function takes led port and led pin and return void
//it sets the state to low
void LED_off(uint8_t ledPort, uint8_t ledPin)
{
	DIO_write(ledPort, ledPin, LOW);
}

//This function takes led port and led pin and return void
//it toggles the state of the pin from high to low and vice versa
void LED_toggle(uint8_t ledPort, uint8_t ledPin)
{
	DIO_toggle(ledPort, ledPin);
}

//This function takes led port, led pin and the time required for the delay and return void
//it blinks the pin for specific time
void LED_blink(uint8_t ledPort, uint8_t ledPin, uint32_t delayTime)
{
	DIO_toggle(ledPort, ledPin);
	TIMER_delay(delayTime);
}

//This function takes led port and led pin and return uint8_t
//it reads the state of the led if its high or low
uint8_t LED_read(uint8_t ledPort, uint8_t ledPin)
{
	return DIO_read(ledPort, ledPin);
}

//This function takes the time required for delay
//it blinks 2 specific LEDs for specific time
void LED_blink_both(uint32_t delayTime)
{
	LED_toggle(CAR_YELLOW_LED_PORT, CAR_YELLOW_LED_PIN);
	LED_toggle(PEDESTRIAN_YELLOW_LED_PORT, PEDESTRIAN_YELLOW_LED_PIN);
	TIMER_delay(delayTime);
}


void LED_init_test(void)
{
	DIO_init(TEST_LED1_PORT, TEST_LED1_PIN, OUT);
	DIO_init(TEST_LED2_PORT, TEST_LED2_PIN, OUT);
}