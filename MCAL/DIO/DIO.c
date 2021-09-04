/*
* DIO.c
*
* Created: 9/3/2021 12:05:13 PM
*  Author: user
*/
#include "DIO.h"
void DIO_init_Pin(uint8 Port,uint8 bit,uint8 direction)
{
	
	if(Port==0)
	{
		if(direction==1)
		SET_BIT(PortA_DDR,bit);
		else if(direction==0)
		CLEAR_BIT(PortA_DDR,bit);
	}
	else if (Port==1)
	{
		if(direction==1)
		SET_BIT(PortB_DDR,bit);
		else if(direction==0)
		CLEAR_BIT(PortB_DDR,bit);
	}
	else if (Port==2)
	{
		if(direction==1)
		SET_BIT(PortC_DDR,bit);
		else if(direction==0)
		CLEAR_BIT(PortC_DDR,bit);
	}
	else if (Port==3)
	{
		if(direction==1)
		SET_BIT(PortD_DDR,bit);
		else if(direction==0)
		CLEAR_BIT(PortD_DDR,bit);
	}
}
void DIO_init(uint8 port,uint8 direction)
{
		switch(port)
		{
			case 0: PortA_DDR=direction;
			break;
			case 1: PortB_DDR=direction;
			break;
			case 2: PortC_DDR=direction;
			break;
			case 3: PortD_DDR=direction;
			break;
		}
	
}
void DIO_read(uint8 Port,uint8 *data)
{
	switch(Port)
	{
		case 0: *data=PortA_Pin;
		break;
		case 1: *data=PortB_Pin;
		break;
		case 2: *data=PortC_Pin;
		break;
		case 3: *data=PortD_Pin;
		break;
	}
}
void DIO_write_Pin(uint8 Port,uint8 bit,uint8 data)
{
	if(Port==0)
	{
		if(data==1)
		SET_BIT(PortA_Data,bit);
		else if(data==0)
		CLEAR_BIT(PortA_Data,bit);
	}
	else if (Port==1)
	{
		if(data==1)
		SET_BIT(PortB_Data,bit);
		else if(data==0)
		CLEAR_BIT(PortB_Data,bit);
	}
	else if (Port==2)
	{
		if(data==1)
		SET_BIT(PortC_DDR,bit);
		else if(data==0)
		CLEAR_BIT(PortC_DDR,bit);
	}
	else if (Port==3)
	{
		if(data==1)
		SET_BIT(PortD_Data,bit);
		else if(data==0)
		CLEAR_BIT(PortD_Data,bit);
	}
}
void DIO_write(uint8 Port,uint8 data)
{
	switch(Port)
	{
		case 0: PortA_Data=data;
		break;
		case 1: PortB_Data=data;
		break;
		case 2: PortC_Data=data;
		break;
		case 3: PortD_Data=data;
		break;
	}
}