/***************************************************************************************
 * Project  :
 * Experimental Platform :Raspberry Pi 4B + 4-ch Relay HAT
 * Hardware Connection :Raspberry Pi 4B -> 4-ch Relay HAT in wiringpi number
 *		P25  --> CH1
 *		P24  --> CH2
 *		P23  --> CH3
 *		P22  --> CH4
 * Author		   : Andy Li
 * Web Site		   : www.seengreat.com
***************************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>		
#include <wiringPi.h>

//the following pin definiting use wiringpi
#define PIN_CH1      25
#define PIN_CH2      24
#define PIN_CH3      23
#define PIN_CH4      22

#define STATE_ON     LOW
#define STATE_OFF    HIGH

void relay_control(int ch, int state)
{
	if (ch == 1)
		digitalWrite(PIN_CH1, state);
	else if (ch == 2) 
		digitalWrite(PIN_CH2, state);
	else if (ch == 3)
		digitalWrite(PIN_CH3, state);
	else if (ch == 4) 
		digitalWrite(PIN_CH4, state);
}
 
int main(void)
{
	printf("\r\n-- 4-ch relay demo --\r\n");
	printf("Raspberry Pi 4B\r\n");
    printf("Init gpio for wiringpi\r\n");
    if(wiringPiSetup() < 0)//use wiringpi Pin number
    { 
        printf("wiringPi lib init failed! \r\n");
    } 
    pinMode(PIN_CH1, OUTPUT);
    pinMode(PIN_CH2, OUTPUT);
    pinMode(PIN_CH3, OUTPUT);
    pinMode(PIN_CH4, OUTPUT);

	while(1)
	{		
        printf("ch1 relay on\r\n");
        relay_control(1, STATE_ON);
        delay(1000);
        printf("ch1 relay off\r\n");
        relay_control(1, STATE_OFF);
        printf("ch2 relay on\r\n");
        relay_control(2, STATE_ON);
        delay(1000);
        printf("ch2 relay off\r\n");
        relay_control(2, STATE_OFF);
        printf("ch3 relay on\r\n");
        relay_control(3, STATE_ON);
        delay(1000);
        printf("ch3 relay off\r\n");
        relay_control(3, STATE_OFF);
        printf("ch4 relay on\r\n");
        relay_control(4, STATE_ON);
        delay(1000);
        printf("ch4 relay off\r\n");
        relay_control(4, STATE_OFF);	
	} 
			 
}

