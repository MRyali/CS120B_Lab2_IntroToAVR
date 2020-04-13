/*	Author: Mayur Ryali
 *  Partner(s) Name: 
 *	Lab Section: 21
 *	Assignment: Lab #2  Exercise #4
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; //configure port A's 8 pins as inputs
	PORTA = 0xFF; 
	
	DDRB = 0x00; //configure ports B's 8 pins as inputs
	PORTB = 0xFF;
	
	DDRC = 0x00; //configure ports C's 8 pins as inputs
	PORTC = 0xFF;
	
	DDRD = 0xFF; //configure port D's 8 pins as inputs
	PORTD = 0x00;

	unsigned char tempA = 0x00; //temp value for A
	unsigned char tempB = 0x00; //temp value for B
	unsigned char tempC = 0x00; //temp value for C
	unsigned char tempD = 0x00;
	unsigned char weightTotal = 0x00; //temp value for total weight
    
    while (1) {
	tempA = PINA;
	tempB = PINB;
	tempC = PINC;
	tempD = 0x00;

	weightTotal = tempA + tempB + tempC;

	if (weightTotal > 140) { //check if total wight exceeds 140
		tempD = tempD | 0x01;	
	}
	if ((tempA - tempC > 80) || (tempA - tempC < -80)) { //check if the difference between A and C is greater than 80
		tempD = tempD | 0x02;
	}

	weightTotal = weightTotal & 0xFC; //keeps the first 6 digits the same and the last two clear

	tempD = tempD + weightTotal; //add the two values together to also include PD1 and PD0

	PORTD = tempD;
    }
    return 1;
}
