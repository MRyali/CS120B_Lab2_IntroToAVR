/*	Author: Mayur Ryali
 *  Partner(s) Name: 
 *	Lab Section: 21
 *	Assignment: Lab #2  Exercise #1
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
	DDRB = 0xFF; //configure ports B's 8 pins as outputs
	PORTB = 0x00;

	unsigned char tempA = 0x00; //temp value for A
	unsigned char tempB = 0x00; //temp val for B
    /* Insert your solution below */
    while (1) {
	tempA = PINA & 0x03;
	if (tempA == 0x01) { //check if PA1 is 0 and PA0 is 1
		tempB = (tempB & 0xFC) | 0x01; //write PB0 to 1 if true
	}
	else {
		tempB = (tempB & 0xFC) | 0x00; //write PB0 to 0 if false
	}
	PORTB = tempB; //set output
    }
    return 1;
}
