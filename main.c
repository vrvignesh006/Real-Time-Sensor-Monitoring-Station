#include <LPC21xx.H>
   #include "header.h"
   #define LED (1<<17)
   extern unsigned int flag1;
   unsigned int temp1=0,temp3=0;
   unsigned int temp2=0;
	 int main()
   {
  		 uart0_init(9600);
  adc_init();
  timer0_init();
  config_vect_timer0();
   IODIR1=LED;
  IOSET1=LED;
PINSEL0&=~((3<<10)|(3<<12));  
  IODIR0&=~((1<<5)|(1<<6));    
	 uart0_tx_string("\r\nTEMPERATURE:");	 
  while(1)
  {
  if(flag1)
  {
  if(flag1==1)
  {
   
		temp1= temperature_sensor();
  }
  if(temp1>=30)
  {
  uart0_tx_string("\r\nTEMPERATURE:");
  uart0_tx_float(temp1);
  uart0_tx_string("c\r\n");
  IOCLR1=LED;
  uart0_tx_string("LED:ON STATE\r\n");
  uart0_tx_string("BUZZER ON\r\n");
 }
  else
  {
  uart0_tx_string("TEMPERATURE:");
  uart0_tx_float(temp1);
  uart0_tx_string("c\r\n");
  IOSET1=LED;
  uart0_tx_string("LED:OFF STATE\r\n");
  uart0_tx_string("BUZZER OFF\r\n");
  }
 
  if(flag1==2)
  {
  temp2=potentiometer_sensor();
  }
  uart0_tx_string("POT VOLT:");
  uart0_tx_integer(temp2);
  uart0_tx_string("%\r\n");


if(flag1==3)
  {
  temp3=LDR_sensor();
  }
 
 
 
  uart0_tx_string("LIGHT:");
  uart0_tx_integer(temp3);
  uart0_tx_string("%\r\n");
 
  FLAME_sensor();
  vibrator_sensor();
  }
  }
  }
 
