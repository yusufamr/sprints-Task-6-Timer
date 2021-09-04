/*
 * Timer.c
 *
 * Created: 9/4/2021 12:19:51 PM
 *  Author: user
 */ 
#include "Timer.h"
static  void(*g_getcallBackTimer0)(void)=NULL_PTR;/* global value for call back function*/
static  void(*g_getcallBackTimer2)(void)=NULL_PTR;/* global value for call back function*/
void __vector_5(void) __attribute__ ((signal,used));
void __vector_6(void) __attribute__ ((signal,used));
void __vector_11(void) __attribute__ ((signal,used));
void __vector_12(void) __attribute__ ((signal,used));

void Timer_init(TimerConfig *timerConfig)
{
	if(timerConfig->s_enableTimer==timer0)
	{ 	/*
		 * enable  Force Output Compare
		 * Waveform Generation Mode is determined by input structure
		 *  Compare Match Output Mode is determined by input structure
		 *   Clock Select is determined by input structure
		 */
		TCCR0=(1<<FOC0)|(((timerConfig->s_waveGenerationMode)&(10))<<WGM01)|(((timerConfig->s_waveGenerationMode)&(01))<<WGM00)
		|(timerConfig->s_compOutputMode<<COM00)|(timerConfig->s_timerClock<<CS00);
		TCNT0=0;/* clear counter register*/
		OCR0=(uint8)(timerConfig->s_CompareCounter);/*used to set value of OCR0 */
		TIMSK|=(timerConfig->s_enableCompOrOverFlow<<TOIE0);/*enable compare interrupt or overflow interrupt */
	}
	
	else if(timerConfig->s_enableTimer==timer2){
		/*
				 * enable  Force Output Compare
				 * Waveform Generation Mode is determined by input structure
				 *  Compare Match Output Mode is determined by input structure
				 *   Clock Select is determined by input structure
				 */
		TCCR2=(1<<FOC2)|((timerConfig->s_waveGenerationMode&(01))<<WGM20)|((timerConfig->s_waveGenerationMode&(10))<<WGM21)|
				(timerConfig->s_compOutputMode<<COM20)|(timerConfig->s_timerClock<<CS20);
		TCNT2=0;/* clear counter register*/
		OCR2=(uint8)(timerConfig->s_CompareCounter);/*used to set value of OCR2*/
		TIMSK|=(timerConfig->s_enableCompOrOverFlow<<TOIE2);/*enable compare interrupt or overflow interrupt */
}

}
/*
 * set call back function for timer 0
 */
void Timer0_setCallBack(void(*funcPtr)(void))
{
	g_getcallBackTimer0=funcPtr;
}
/*
 * ISR for timer 0 in compare mode
 */
void __vector_11(void){
	if(g_getcallBackTimer0!=NULL_PTR){
	g_getcallBackTimer0();}
}
/*
 * ISR for timer 0 in overflow mode
 */
void __vector_12(void){
	if(g_getcallBackTimer0!=NULL_PTR){
		g_getcallBackTimer0();}
}
/***************************************************************************************************************************/
/***************************************************************************************************************************/

/*
 * set call back function for timer 2
 */
void Timer2_setCallBack(void(*funcPtr)(void))
{
	g_getcallBackTimer2=funcPtr;
}
/*
 * ISR for timer 2 in compare mode
 */
void __vector_5(void){
	if(g_getcallBackTimer2!=NULL_PTR){
	g_getcallBackTimer2();}
}
/*
 * ISR for timer 2 in overflow mode
 */
void __vector_6(void){
	if(g_getcallBackTimer2!=NULL_PTR){
		g_getcallBackTimer2();}

}