/*
 * lab2_3.1.c
 *
 * Created: 2018/9/19 13:32:42
 * Author : Lenovo
 */ 

#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include "uart.h"
float volt = 0.0;

int main(void)
{
    uart_init();

	PORTC |= (1 << PORTC0);
	
	ADMUX |= (1 << REFS0);                                            //reference 5V
	ADCSRA |= (1 << ADEN) | (1 << ADATE);                             //enable ADC
	ADCSRA |= (1 << ADPS0) | (1 << ADPS1) | (1 << ADPS2);             //factor 128      
	ADCSRA |= (1 << ADSC);                                           //Start conversion
	ADCSRB &= ~((1 << ADTS0)|(1 << ADTS1)|(1 << ADTS2));             //free-running mode
    while (1) 
    {
		volt = (ADC * 5.0) / 1024.0;
		printf("The voltage on photoresistor is %.2f V\n", volt);
    }
}


