/*
 * Application.c
 *
 * Created: 9/4/2021 1:56:25 PM
 *  Author: user
 */ 
#include "Application.h"

uint8 i=0;
void App()
{
	/*timer configurations
	  normal mode
	  pre-scalar=1024(Ft=Fcpu/1024)
	  enable timer 0 overflow mode
	  choose timer 0
	*/
	TimerConfig TC = {timer02NormalMode,timer0Normal,timer0Prescale256,00,timer0,255};
	SREG|=(1<<7);/* Enable global interrupts in MC by setting the I-Bit.*/ 
	Led_init(0,0);
	
	Timer_init(&TC);
	while (1)
	{
		/*
		make led toggle each 300 ms
		since each tick take 0.256 ms then 255 take 65 then 5 take 325
		*/
		if(TCNT0==255)
		{
			i++;
			if(i==5)
			{
				Led_set(0,0);
				
			}
			else if (i==10)
			{
				Led_clear(0,0);
				i=0;
			}
		}
	}
}


