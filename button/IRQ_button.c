#include "button.h"
#include "lpc17xx.h"
#include "../led/led.h"
#define wait 10000

extern unsigned int rnd,delay;

void EINT0_IRQHandler (void)	  
{
	if(delay>=wait){ //debouncing
		if(rnd%2==0)
			LPC_GPIO2->FIOPIN |= 0x8; //led8
		else
			LPC_GPIO2->FIOPIN |= 0x4; //led9
		
		if(((LPC_GPIO2->FIOPIN & 0xFF)==0xA8)||((LPC_GPIO2->FIOPIN & 0xFF)==0x54))
			LPC_GPIO2->FIOPIN |= 0x1; //led10
		else
			LPC_GPIO2->FIOPIN |= 0x2; //led11
		delay=0;
	}
  LPC_SC->EXTINT |= (1 << 0);     //clear pending interrupt       
}


void EINT1_IRQHandler (void)	  
{
  if(delay>=wait){ //debouncing
		all_LED_off();
		if(rnd%2==0){
			LPC_GPIO2->FIOPIN |= 0x80; //led4
		}else{
			LPC_GPIO2->FIOPIN |= 0x40; //led5
		}
		delay=0;		
	}	
	LPC_SC->EXTINT |= (1 << 1);     // clear pending interrupt         
}

void EINT2_IRQHandler (void)	  
{
	if(delay>=wait){ //debouncing
		if(rnd%2==0){
			LPC_GPIO2->FIOPIN |= 0x20; //led6
		}else{
			LPC_GPIO2->FIOPIN |= 0x10; //led7
		}
		delay=0;
	}
  LPC_SC->EXTINT |= (1 << 2);     // clear pending interrupt           
}
