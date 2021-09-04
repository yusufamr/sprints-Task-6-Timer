/*
 * Timer.h
 *
 * Created: 9/4/2021 12:20:08 PM
 *  Author: user
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#include "../../Atmega32A_registers.h"
#include "../../TypeDefs.h"
#include "../../Macros.h"
/**** Enums,Macros & structs ********/
#define NULL_PTR  ((void*)0)
/*[enum name]: TimerMode
 * [enum description ]: responsible for determine mode of timer (normal or compare or PWM)
 */
typedef enum{
	timer02NormalMode=00,/*normal mode of timer 0 or 2*/
	timer02PWMMode=01,/*PWM mode of timer 0 or 2*/
	timer02CompareMode=10, /*compare mode of timer 0 or 2*/
	timer1NormalMode=0000,/*normal mode of timer 1*/
	timer1CompareMode=0100/*compare mode of timer 1*/
}WaveGenerationMode;
/*[enum name]: CompOutputMode
 * [enum description ]: responsible for determine mode of output for normal or compare mode
 */
typedef enum{
	timer0Normal=00,/* oc0 disabled*/
	timer0Toggle=01,/*Toggle OC0 on compare match*/
	timer0Clear=10,/*Clear OC0 on compare match*/
	timer0Set=11/*Set OC0 on compare match*/
}CompOutputMode;
/*[enum name]: TimerClock
 * [enum description ]: responsible for determine clock of timer
 */
typedef enum{
	disableClock=000,/*no clock*/
	noPrescale=001,/*CLKi/o/(1)*/
	prescale8=010,/*CLKi/o/(8)*/
	timer0Prescale64=011,/*CLKi/o/(64) for timer0*/
	timer0Prescale256=100,/*CLKi/o/(256)for timer 0*/
	timer0Prescale1024=101,/*CLKi/o/(1024) for timer0*/
	timer2Prescale32=011,/*CLKi/o/(32) for timer2*/
	timer2Prescale64=100,/*CLKi/o/(64) for timer2*/
	timer2Prescale128=101,/*CLKi/o/(128) for timer2*/
	timer2Prescale256=110,/*CLKi/o/(256) for timer2*/
	timer2Prescale1024=111,/*CLKi/o/(1024) for timer2*/

}TimerClock;
/*[enum name]: EnableCompOrOverFlow
 * [enum description ]: responsible for enable compare or overflow interrupt
 */
typedef enum{
	timer02EnableCompareInt=10,/* enable compare interrupt for timer 0 or 2 */
	timer02EnableOverflowInt=01,/* enable Overflow interrupt for timer 0 or 2*/
	timer1EnableCompareIntA=0100,
	timer1EnableCompareIntB=0010,
	timer1EnableOverflowInt=0001,
}EnableCompOrOverFlow;
/*[enum name]: EnableTimer
 * [enum description ]: responsible for determine which timer we will use
 */
typedef enum{
	timer0=0,
	timer1=1,
	timer2=2
}EnableTimer;
/*[struct name]: TimerConfig
 * [struct description ]: responsible for determine configurations of timer
 */
typedef struct{
	WaveGenerationMode s_waveGenerationMode;
	CompOutputMode s_compOutputMode;
	TimerClock s_timerClock;
	EnableCompOrOverFlow s_enableCompOrOverFlow;
	EnableTimer s_enableTimer;
	uint16 s_CompareCounter;
}TimerConfig;
/****** functions *******/
/*
* [Function name]:Timer_init
* [Function description]:responsible for initialize Timer you choose  
* [Function Parameters]:timerConfig -> determine timer you choose and timer mode
*/
void Timer_init(TimerConfig *timerConfig);
/*
* [Function name]:Timer0_setCallBack
* [Function description]:responsible for set Function used when interrupt happen
* [Function Parameters]:funcPtr -> function set to isr
*/
void Timer0_setCallBack(void(*funcPtr)(void));
/*
* [Function name]:Timer1_setCallBack
* [Function description]:responsible for set Function used when interrupt happen
* [Function Parameters]:funcPtr -> function set to isr
*/
void Timer1_setCallBack(void(*funcPtr)(void));
/*
* [Function name]:Timer2_setCallBack
* [Function description]:responsible for set Function used when interrupt happen
* [Function Parameters]:funcPtr -> function set to isr
*/
void Timer2_setCallBack(void(*funcPtr)(void));




#endif /* TIMER_H_ */