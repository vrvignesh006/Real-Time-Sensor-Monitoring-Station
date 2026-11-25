#include<lpc21xx.h>
 #include "header.h"
 #define FLAME ((IOPIN0>>5)&1)
   void FLAME_sensor()
   {
   if(FLAME==0)
   {
           uart0_tx_string("FLAME SENSOR : FIRE DETECTED\r\n");
  
  }
  else
  {
          uart0_tx_string("FLAME SENSOR : NO FIRE DETECTED\r\n");
 
  }
  }
	#define VIBR ((IOPIN0>>6)&1)
   void vibrator_sensor()
   {
   if(VIBR==0)
   {
   uart0_tx_string("VBT:ON\r\n");
   }
  else
  {
  uart0_tx_string("VBT:OFF\r\n");
  }
  }
  int potentiometer_sensor()
   {
   unsigned int adc_val2=0,poten_per=0,vout=0;
   adc_val2=adc_read(1);
   vout=(adc_val2*(3.3)*100)/1023;
  poten_per=(vout-0.05)/0.01;
  return poten_per;
 }
  int LDR_sensor()
   {
   int adc_val2,ldr_per;
   adc_val2=adc_read(3);
   ldr_per=(adc_val2*100)/1023;
   return ldr_per;
   }
   int temperature_sensor()
   {
   int temp,
   adc_val2=adc_read(2);
   temp=(adc_val2*100)/1023;
   return temp;
  }
