/*
 * Led.h
 *
 * Created: 9/3/2021 1:44:31 PM
 *  Author: user
 */ 


#ifndef LED_H_
#define LED_H_
#include "../../MCAL/DIO/DIO.h"
/*
* [Function name]:Led_init
* [Function description]:Used to initialize Led on which Port , on which Bit and make it as output
* [Function Parameters]: Port -> to determine port , bit -> to determine pin on the port
*/
void Led_init(uint8 Port,uint8 bit);
/*
* [Function name]:Led_set
* [Function description]:Used to switch on Led 
* [Function Parameters]: Port -> to determine port , bit -> to determine pin on the port
*/
void Led_set(uint8 Port,uint8 bit);
/*
* [Function name]:Led_clear
* [Function description]:Used to switch off Led
* [Function Parameters]: Port -> to determine port , bit -> to determine pin on the port
*/
void Led_clear(uint8 Port,uint8 bit);




#endif /* LED_H_ */