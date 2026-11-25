#include <LPC21xx.H>
 #include "header.h"
 volatile unsigned int flag1=0,c=0;
   void timer0_init()
  {
  T0TC=0;
  T0PC=0;
  T0TCR=0x02;
  T0PR=15000-1;
  T0MR0=1000;
  T0MCR=3;
  T0IR=0XFF;
 
  T0TCR=1;
 }
  void timer0_handler()__irq
  {
 flag1=1;
  c++;
  if(c==3)
  flag1=1;
  if(c==6)
  flag1=2;
  if(c==9)
  flag1=3;
  if(c>10)
  c=0;
  T0IR=1;
  VICVectAddr=0;
  }
  void config_vect_timer0()
  {
  VICIntSelect=0;
  VICVectAddr0=(unsigned int)timer0_handler;
  VICVectCntl0=1<<5|4;
  VICIntEnable=1<<4;
  }
