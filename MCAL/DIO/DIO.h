/*
 * DIO.h
 *
 * Created: 9/3/2021 12:04:59 PM
 *  Author: user
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "../../Atmega32A_registers.h"
#include "../../Macros.h"
/*
* [Function name]:DIO_init_Pin
* [Function description]:Used to initialize a specific pin on the port as input or output
* [Function Parameters]: Port -> to determine port , bit -> to determine pin on the port , direction -> to determine pin as input or output
*/
void DIO_init_Pin(uint8 Port,uint8 bit,uint8 direction);
/*
* [Function name]:DIO_init
* [Function description]:Used to initialize the port as input or output
* [Function Parameters]: Port -> to determine port , direction -> to determine Port as input or output
*/
void DIO_init(uint8 port,uint8 direction);
/*
* [Function name]:DIO_read
* [Function description]:Used to read value on the port 
* [Function Parameters]: Port -> to determine port , data -> pointer to store data in the port on it
*/
void DIO_read(uint8 Port,uint8 *data);
/*
* [Function name]:DIO_write_Pin
* [Function description]:Used to write data on specific pin on the port
* [Function Parameters]: Port -> to determine port , bit -> to determine pin on the port, data -> data to write on pin
*/
void DIO_write_Pin(uint8 Port,uint8 bit,uint8 data);
/*
* [Function name]:DIO_write
* [Function description]:Used to write value on the port
* [Function Parameters]: Port -> to determine port , data -> data to be writen in the port
*/
void DIO_write(uint8 Port,uint8 data);



#endif /* DIO_H_ */