/*
 * Led.c
 *
 * Created: 9/3/2021 1:44:42 PM
 *  Author: user
 */ 
#include "Led.h"
void Led_init(uint8 Port,uint8 bit)
{
	DIO_init_Pin(Port,bit,1);/* make pin as output */
}
void Led_set(uint8 Port,uint8 bit)
{
	DIO_write_Pin(Port,bit,1);/* write 1 on Pin */
}
void Led_clear(uint8 Port,uint8 bit)
{
	DIO_write_Pin(Port,bit,0);/* clear pin */
}
