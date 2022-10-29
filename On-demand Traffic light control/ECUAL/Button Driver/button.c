/*
 * button.c
 *
 * Created: 10/25/2022 6:06:32 PM
 *  Author: FADY
 */ 

#include "button.h"

//This function takes void and return void and sets button configuration
//it sets the pin as an input which will be used by the button which will be an external interrupt pin
void BUTTON_init(void) // button is input device
{
	DIO_init(EXTERNAL_INT0_BUTTON_PORT, EXTERNAL_INT0_BUTTON_PIN, IN);
}

void BUTTON_init_test(void)
{
	DIO_init(TEST_BUTTON_PORT, TEST_BUTTON_PIN, IN);
}