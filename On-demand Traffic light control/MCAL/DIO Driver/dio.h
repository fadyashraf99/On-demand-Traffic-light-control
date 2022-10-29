/*
 * dio.h
 *
 * Created: 10/25/2022 6:07:01 PM
 *  Author: FADY
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../../Utilities/registers.h"
#include "../../Utilities/Bit_manipulation.h"

// all driver macros
#define PORT_A	'A'
#define PORT_B	'B'
#define PORT_C	'C'
#define PORT_D	'D'

#define PIN0	0
#define PIN1	1
#define PIN2	2
#define PIN3	3
#define PIN4	4
#define PIN5	5
#define PIN6	6
#define PIN7	7

// direction defines
#define IN	0
#define OUT	1

// values defines
#define LOW		0
#define HIGH	1

// all driver function prototypes
void DIO_init(uint8_t portNumber, uint8_t pinNumber, uint8_t direction); // initialize dio direction
void DIO_write(uint8_t portNumber, uint8_t pinNumber, uint8_t state); // write data to dio
void DIO_toggle(uint8_t portNumber, uint8_t pinNumber); // toggle dio
uint8_t DIO_read(uint8_t portNumber, uint8_t pinNumber); // read dio

#endif /* DIO_H_ */