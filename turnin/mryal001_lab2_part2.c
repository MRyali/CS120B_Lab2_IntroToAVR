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
	DDRC = 0xFF; //configure ports C's 8 pins as outputs
	PORTC = 0x00;

	unsigned char tempA = 0x00; //temp value for A
	unsigned char cntavail = 0x00; //temp val for available spaces count
    /* Insert your solution below */
    while (1) {
	tempA = PINA & 0x0F;
	if (tempA == 0x07 || tempA == 0x0B || tempA == 0x0D || tempA == 0x0E) { //1 available
		cntavail = 1;
	}
	else if (tempA == 0x03 || tempA == 0x05 || tempA == 0x06 || tempA == 0x09 || tempA == 0x0A || tempA == 0x0C) { //2 available tears
		cntavail = 2;
	}
	else if (tempA == 0x01 || tempA == 0x02 || tempA == 0x04 || tempA == 0x08) { //3 available tears
		cntavail = 3;
	}
	else if (tempA == 0x0F) { //0 available
		cntavail = 0;
	}
	else { //4 available
		cntavail = 4;
	}
	PORTC = cntavail; //set output
    }
    return 1;
}
