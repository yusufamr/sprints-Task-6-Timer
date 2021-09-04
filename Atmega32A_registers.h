/*
* Atmega32A_registers.h
*
* Created: 9/3/2021 11:55:45 AM
*  Author: user
*/


#ifndef ATMEGA32A_REGISTERS_H_
#define ATMEGA32A_REGISTERS_H_
#include "TypeDefs.h"
/*************************** DIO*****************************************/
/************************************************************************/

/************************************************************************/
/*							PORTA                                       */
/************************************************************************/
#define PortA_Data (*(volatile uint8 *)(0x3B)) /* Data of Port */
#define PortA_DDR (*(volatile uint8 *)(0x3A)) /* responsible for direction of port */
#define PortA_Pin (*(volatile uint8 *)(0x39)) /* Read data of Port */
/************************************************************************/
/*							PORTB                                       */
/************************************************************************/
#define PortB_Data (*(volatile uint8 *)(0x38)) /* Data of Port */
#define PortB_DDR (*(volatile uint8 *)(0x37))/* responsible for direction of port */
#define PortB_Pin (*(volatile uint8 *)(0x36))/* Read data of Port */
/************************************************************************/
/*							PORTC                                       */
/************************************************************************/
#define PortC_Data (*(volatile uint8 *)(0x35))/* Data of Port */
#define PortC_DDR (*(volatile uint8 *)(0x34))/* responsible for direction of port */
#define PortC_Pin (*(volatile uint8 *)(0x33))/* Read data of Port */
/************************************************************************/
/*							PORTD                                       */
/************************************************************************/
#define PortD_Data (*(volatile uint8 *)(0x32))/* Data of Port */
#define PortD_DDR (*(volatile uint8 *)(0x31))/* responsible for direction of port */
#define PortD_Pin (*(volatile uint8 *)(0x30))/* Read data of Port */
/***************************************************************************/
/**************************************************************************/

/*************************** Timer*****************************************/
/**************************************************************************/
#define TIMSK (*(volatile uint8 *)(0x59))/* Timer Interrupt Mask register*/
#define TOIE0   0
#define OCIE0   1
#define TOIE2   6
#define OCIE2   7
#define TOIE1   2
#define OCIE1B  3
#define OCIE1A  4
#define TICIE1  5
#define TIFR (*(volatile uint8 *)(0x58))/* Timer Interrupt Flag register*/
#define TOV0    0
#define OCF0    1
#define TOV2    6
#define OCF2    7
#define TOV1    2
#define OCF1B   3
#define OCF1A   4
#define ICF1    5
/************************************************************************/
/*	                         Timer 0                                    */
/************************************************************************/
#define OCR0 (*(volatile uint8 *)(0x5C))/*Timer/Counter0 Output Compare Register */
#define TCNT0 (*(volatile uint8 *)(0x52))/*Timer/Counter0 initial value (8 Bits) */
#define TCCR0 (*(volatile uint8 *)(0x53))/*Timer/Counter0 Control Register */
#define CS00    0
#define CS01    1
#define CS02    2
#define WGM01   3
#define COM00   4
#define COM01   5
#define WGM00   6
#define FOC0    7
/************************************************************************/
/*	                         Timer 1                                    */
/************************************************************************/
#define OCR1AH (*(volatile uint8 *)(0x4B))/*Timer/Counter1 Output Compare Register  A High Byte */
#define OCR1AL (*(volatile uint8 *)(0x4A))/*Timer/Counter1 Output Compare Register  A Low Byte  */
#define OCR1BH (*(volatile uint8 *)(0x49))/*Timer/Counter1 Output Compare Register  B High Byte*/
#define OCR1BL (*(volatile uint8 *)(0x48))/*Timer/Counter1 Output Compare Register  B Low Byte*/
#define TCNT1H (*(volatile uint8 *)(0x4D))/*Timer/Counter1 initial value (8 Bits) High Byte*/
#define TCNT1L (*(volatile uint8 *)(0x4C))/*Timer/Counter1 initial value (8 Bits) Low Byte*/
#define TCCR1A (*(volatile uint8 *)(0x4F))/*Timer/Counter1 Control Register A */
#define WGM10   0
#define WGM11   1
#define FOC1B   2
#define FOC1A   3
#define COM1B0  4
#define COM1B1  5
#define COM1A0  6
#define COM1A1  7
#define TCCR1B (*(volatile uint8 *)(0x4E))/*Timer/Counter1 Control Register B */
#define CS10    0
#define CS11    1
#define CS12    2
#define WGM12   3
#define WGM13   4
#define ICES1   6
#define ICNC1   7
#define ICR1H  (*(volatile uint8 *)(0x47))/*Timer/Counter1 – Input Capture Register High Byte*/
#define ICR1L  (*(volatile uint8 *)(0x46))/*Timer/Counter1 – Input Capture Register Low Byte*/
/************************************************************************/
/*	                         Timer 0                                    */
/************************************************************************/
#define OCR2 (*(volatile uint8 *)(0x43))/*Timer/Counter2 Output Compare Register */
#define TCNT2 (*(volatile uint8 *)(0x44))/*Timer/Counter2 initial value (8 Bits) */
#define TCCR2 (*(volatile uint8 *)(0x45))/*Timer/Counter2 Control Register */ 
#define CS20    0
#define CS21    1
#define CS22    2
#define WGM21   3
#define COM20   4
#define COM21   5
#define WGM20   6
#define FOC2    7
/**************************************************************************/
/**************************************************************************/

/*********************************INTTERRUPTS*******************************/
/**************************************************************************/

#define SREG (*(volatile uint8 *)(0x5F))/* Status register which contain Global Interrupt Enable bit*/
#define GICR (*(volatile uint8 *)(0x5B))/* General Interrupt Control register*/
#define IVCE    0
#define IVSEL   1
#define INT2    5
#define INT0    6
#define INT1    7
#define GIFR (*(volatile uint8 *)(0x5A))/* General Interrupt Flag register*/
#define INTF2   5
#define INTF0   6
#define INTF1   7
/**************************************************************************/
/**************************************************************************/
#endif /* ATMEGA32A_REGISTERS_H_ */