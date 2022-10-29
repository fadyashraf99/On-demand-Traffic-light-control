/*
 * app.c
 *
 * Created: 10/25/2022 6:04:26 PM
 *  Author: FADY
 */ 

#include "app.h"

/*	declared parameters	*/
uint8_t mode = NORMAL_MODE, yellowFlag = 0, intFlagIn = 0;
uint8_t initFlag = 0;	// flag to indicate if any interruption happened so it skips the timer wait loop

//this function takes void and return void
//it contains all initialization functions that will be used in the project
//it will be used only 1 time
void APP_init(void)
{
	LED_init();
	BUTTON_init();
	TIMER_init();
	INT0_init();
}

//this function takes void and return void
//it contains how the program works and assemble all the functions
void APP_start(void)
{
	while(1)
	{
		if (mode == NORMAL_MODE)	//	for no pedestrian button press
		{
			/*	first state	*/
			LED_on(PEDESTRIAN_RED_LED_PORT, PEDESTRIAN_RED_LED_PIN);
			LED_on(CAR_GREEN_LED_PORT, CAR_GREEN_LED_PIN);
			TIMER_delay(5000);
			if (intFlagIn)	//if interrupt happened this will reset the program to its first state
			{
				intFlagIn = 0;
				continue;
			}
			
			/*	second state	*/
			for (int i=0; i<10; i++)	//loop to blink LED for 5 seconds as delay is 0.5 seconds for 10 times to change state faster ans keep the total delay time
			{
				yellowFlag = 1;
				LED_blink(CAR_YELLOW_LED_PORT, CAR_YELLOW_LED_PIN, 500);
				if (intFlagIn)	//if interrupt happened this will reset the flag of yellow LED 
				{
					yellowFlag = 0;
					break;
				}
			}
			if (intFlagIn)	//if interrupt happened this will reset the program to its first state
			{
				intFlagIn = 0;
				continue;
			}
			yellowFlag = 0;	//flag that indicate that the loop of yellow blink is finished
			
			/*	third state	*/
			LED_off(CAR_GREEN_LED_PORT, CAR_GREEN_LED_PIN);
			LED_off(CAR_YELLOW_LED_PORT, CAR_YELLOW_LED_PIN);
			LED_on(CAR_RED_LED_PORT, CAR_RED_LED_PIN);
			TIMER_delay(5000);
			if (intFlagIn)
			{
				intFlagIn = 0;
				continue;
			}
			/*	fourth state	*/
			for (int i=0; i<10; i++)
			{
				yellowFlag = 1;
				LED_blink(CAR_YELLOW_LED_PORT, CAR_YELLOW_LED_PIN, 500);
				if (intFlagIn)
				{
					yellowFlag = 0;
					break;
				}
			}
			if (intFlagIn)
			{
				intFlagIn = 0;
				continue;
			}
			yellowFlag = 0;
			LED_off(CAR_YELLOW_LED_PORT, CAR_YELLOW_LED_PIN);
			LED_off(CAR_RED_LED_PORT, CAR_RED_LED_PIN);
		}
		
		
		else if (mode == PEDESTRIAN_MODE)	//for pedestrian mode after pressing the button
		{
			/*	initial state	*/
			LED_off(CAR_YELLOW_LED_PORT, CAR_YELLOW_LED_PIN);
			if (LED_read(CAR_RED_LED_PORT, CAR_RED_LED_PIN))	//checks which state the interrupt occurs which will be when the CARs red LED is on
			{
				/*	first state	*/
				LED_off(PEDESTRIAN_RED_LED_PORT, PEDESTRIAN_RED_LED_PIN);
				LED_on(CAR_RED_LED_PORT, CAR_RED_LED_PIN);
				LED_on(PEDESTRIAN_GREEN_LED_PORT, PEDESTRIAN_GREEN_LED_PIN);
				TIMER_delay(5000);
			}
			else if (LED_read(CAR_GREEN_LED_PORT, CAR_GREEN_LED_PIN) || yellowFlag)	//checks which state the interrupt occur which will be when the CARs green LED is on or when yellow light blink
			{
				/*	first state	*/
				LED_off(CAR_YELLOW_LED_PORT, CAR_YELLOW_LED_PIN);
				for (int i=0; i<10; i++)	//loop to blink 2 LED for 5 seconds as delay is 0.5 seconds for 10 times to change state faster ans keep the total delay time
				{
					LED_blink_both(500);
				}
				/*	second state	*/
				LED_off(PEDESTRIAN_RED_LED_PORT, PEDESTRIAN_RED_LED_PIN);
				LED_off(CAR_GREEN_LED_PORT, CAR_GREEN_LED_PIN);
				LED_off(CAR_YELLOW_LED_PORT, CAR_YELLOW_LED_PIN);
				LED_off(PEDESTRIAN_YELLOW_LED_PORT, PEDESTRIAN_YELLOW_LED_PIN);
				LED_on(CAR_RED_LED_PORT, CAR_RED_LED_PIN);
				LED_on(PEDESTRIAN_GREEN_LED_PORT, PEDESTRIAN_GREEN_LED_PIN);
				TIMER_delay(5000);
			}
			/*	last state	*/
			LED_on(CAR_RED_LED_PORT, CAR_RED_LED_PIN);
			LED_on(PEDESTRIAN_GREEN_LED_PORT, PEDESTRIAN_GREEN_LED_PIN);
			for (int i=0; i<10; i++)	//loop to blink 2 LED for 5 seconds as delay is 0.5 seconds for 10 times to change state faster ans keep the total delay time
			{
				LED_blink_both(500);
			}
			LED_off(CAR_RED_LED_PORT, CAR_RED_LED_PIN);
			LED_off(PEDESTRIAN_GREEN_LED_PORT, PEDESTRIAN_GREEN_LED_PIN);
			LED_off(CAR_YELLOW_LED_PORT, CAR_YELLOW_LED_PIN);
			LED_off(PEDESTRIAN_YELLOW_LED_PORT, PEDESTRIAN_YELLOW_LED_PIN);
			initFlag = 1;			//set flag in program to indicate that there is an interrupt happened
			intFlagIn = 1;			//set flag in timer to indicate that there is an interrupt happened
			mode = NORMAL_MODE;
			return;	//to exit from loop and exit the interrupt and return to the main program
		}
	}
}

ISR(EXT_INT_0)	//when the button is pressed
{
	mode = PEDESTRIAN_MODE;	//set different mode
	APP_start();			//go to function with pedestrian mode activated
}