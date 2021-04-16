/*Name: Debouncing.c
 *Authors: Alexis Zamora Cartagena A01066789; Alexandra Morales A01066851
 *Description: The objective of this homeworks is to learn how to use implement debouncing in HW and SW
 *Description:  as well as the use of 7 Segment displays
*/

//TODO[Task1]: Write in the LCD the first name and student ID

// FirstName1                     StudentID1
// FirstName2                     StudentID2

//TODO[Task2]: Matrix Keyboard 2x2


//B00 - LED_RED   B01 - LED_GREEN

//B10 - LED_BLUE  B11 - ALL_LEDS

// SW debouncing

//[CODE][Task3] Integration LCD + Matrix

// BB@AAAAAAAAAAAAAAAAAA
// AAAAAAAAAAAAAAAAAAAAA

	//B00 - Move cursor to the right

	//B01 - Increment Value +1

//B10 - Move cursor to the left

//B11 - Decrement Value -1

Use SW/HW debouncing  (I suggest SW debouncing)
Action for button pressed is set until button is released


#include <stdbool.h>
#include "MKL25Z4.h"


//LEDs definition
//RED LED
#define RED_LED_BIT 	18
#define RED_LED_PCR 	PORTB->PCR[RED_LED_BIT]
#define RED_LED_GPIO	GPIOB

//BLUE LED
#define BLUE_LED_BIT 	1
#define BLUE_LED_PCR 	PORTD->PCR[BLUE_LED_BIT]
#define BLUE_LED_GPIO	GPIOD

//Button0 definition(PTA 1)
#define BUTTON0_BIT 	1
#define BUTTON0_GPIO 	GPIOA
#define BUTTON0_PCR 	PORTA->PCR[BUTTON0_BIT]

//Button1 definition(PTA 2)
#define BUTTON1_BIT 	2
#define BUTTON1_GPIO 	GPIOA
#define BUTTON1_PCR 	PORTA->PCR[BUTTON1_BIT]

//LEDs state

#define	RED_LED		GPIOB->PDOR
#define BLUE_LED	GPIOD->PDOR

//LEDs state
#define RED_LED_STATE	RED_LED_GPIO->PDIR | (1<<RED_LED_BIT) //Encendido
#define	BLUE_LED_STATE	BLUE_LED_GPIO->PDIR | (1<<BLUE_LED_BIT)

//BUTTONs state
#define BUTTON0_STATE	BUTTON0_GPIO->PDIR ^ (1<<BUTTON0_BIT) //Se presiona
#define	BUTTON1_STATE	BUTTON1_GPIO->PDIR ^ (1<<BUTTON1_BIT)


//Task 2: 7 SEGMENT DISPLAY COMMON CATHODE


#define ZERO  	0x3F
#define ONE 	0x06
#define TWO 	0x5B
#define THREE	0x4F
#define FOUR	0x66
#define FIVE 	0x6D
#define SIX 	0x7D
#define SEVEN	0x07
#define EIGHT	0x7F
#define NINE 	0x6F


//TASK 3


//Button0 definition(PTA 1)
#define BUTTON0_BIT 	1
#define BUTTON0_GPIO 	GPIOA
#define BUTTON0_PCR 	PORTA->PCR[BUTTON0_BIT]

//Button1 definition(PTA 2)
#define BUTTON1_BIT 	2
#define BUTTON1_GPIO 	GPIOA
#define BUTTON1_PCR 	PORTA->PCR[BUTTON1_BIT]

//Button2 definition(PTA12)
#define BUTTON2_BIT 	12
#define BUTTON2_GPIO 	GPIOA
#define BUTTON2_PCR 	PORTA->PCR[BUTTON2_BIT]

//BUTTONs state
#define BUTTON0_STATE	BUTTON0_GPIO->PDIR ^ (1<<BUTTON0_BIT) //Se presiona
#define	BUTTON1_STATE	BUTTON1_GPIO->PDIR ^ (1<<BUTTON1_BIT)
#define	BUTTON2_STATE	BUTTON2_GPIO->PDIR ^ (1<<BUTTON2_BIT)



void delayMs(int n);

 int debounceButton(int state)
 { int stateNow=BUTTON0_STATE;
 	if (state != stateNow){
 		delayMs(225);
 		stateNow=BUTTON0_STATE;
 	}
 	return stateNow;

 	}


void task1(void){

	if((debounceButton(BUTTON0_STATE)) & (1<<BUTTON0_BIT)){
		RED_LED ^= (1<<RED_LED_BIT) ;
	}

	if((BUTTON1_STATE) & (1<<BUTTON1_BIT)){
			BLUE_LED ^= (1<<BLUE_LED_BIT) ;
		}
}


void task2(){

		
    	
}


void task3(void){

	    }

}

int main (void) {
  //Setup


	//TASK 1
    //ENABLE CLOCK FOR PORTS A(INPUTS 0 & 1), B(RED  LEDs), D(BLUE LED & INPUT 2)
	SIM->SCGC5 |= SIM_SCGC5_PORTB(1) | SIM_SCGC5_PORTA(1) | SIM_SCGC5_PORTD(1);

    //Setting ports as GPIO
	RED_LED_PCR = PORT_PCR_MUX(1);
	BLUE_LED_PCR = PORT_PCR_MUX(1);
    BUTTON0_PCR = PORT_PCR_MUX(1) | PORT_PCR_PE(1) | PORT_PCR_PS(1);
    BUTTON1_PCR = PORT_PCR_MUX(1) | PORT_PCR_PE(1) | PORT_PCR_PS(1);
    BUTTON2_PCR = PORT_PCR_MUX(1) | PORT_PCR_PE(1) | PORT_PCR_PS(1);


    //Setting GPIO type
    GPIOB->PDDR |= (1<<RED_LED_BIT);
    GPIOD->PDDR |= (1<<BLUE_LED_BIT);
    GPIOB->PDOR |= (1<<RED_LED_BIT);
	GPIOD->PDOR |= (1<<BLUE_LED_BIT);
    BUTTON0_GPIO->PDDR &= ~(1<<BUTTON0_BIT);
    BUTTON1_GPIO->PDDR &= ~(1<<BUTTON1_BIT);
    BUTTON2_GPIO->PDDR &= ~(1<<BUTTON2_BIT);


    //TASK 2 //TASK 3
	//SIM->SCGC5 |= SIM_SCGC5_PORTD(1);

	PORTD->PCR[0]= 0x100;
	PORTD->PCR[1]= 0x100;
	PORTD->PCR[2]= 0x100;
	PORTD->PCR[3]= 0x100;
	PORTD->PCR[4]= 0x100;
	PORTD->PCR[5]= 0x100;
	PORTD->PCR[6]= 0x100;



    while(1){

	//task1();
    	//task2();
    	//task3();

    	}

}


void delayMs(int n) {
    int i;
    int j;
    for(i = 0 ; i < n; i++)
        for (j = 0; j < 7000; j++) {}
}

