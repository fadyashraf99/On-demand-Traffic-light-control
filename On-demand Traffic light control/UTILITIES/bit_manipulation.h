/*
 * Bit_Manipulation.h
 *
 * Created: 10/25/2022 6:02:27 PM
 *  Author: FADY
 */ 

#ifndef BIT_MANIPULATION_H_
#define BIT_MANIPULATION_H_

/*	BIT math for easier setting and cleaning of bits in registers	*/

#define SET_BIT(u8Var,BitNo)	u8Var |= (1<<BitNo)
#define CLR_BIT(u8Var,BitNo)	u8Var &= ~(1<<BitNo)
#define TOGGLE_BIT(u8Var,BitNo)	u8Var ^= (1<<BitNo)
#define GET_BIT(u8Var,BitNo)	((u8Var & (1<<BitNo))>>BitNo)

#endif /* BIT_MANIPULATION_H_ */