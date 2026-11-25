#include"header.h"
void uart0_init(unsigned int baud)
{
unsigned int result=0,pclk;
if(VPBDIV==0)
pclk=15000000;
else if(VPBDIV==1)
pclk=60000000;
else if(VPBDIV==2)
pclk=30000000;
result=pclk/(16*baud);
PINSEL0|=0X05;
U0LCR=0X83;
U0DLL=result&0xff;
U0DLM=(result>>8)&0xff;
U0LCR=0X03;
}
#define THRE ((U0LSR>>5)&1)
void uart0_tx(unsigned int data)
{
   U0THR=data;
	while(THRE==0);
}
#define RDR (U0LSR&1)
unsigned char uart0_rx(void)
{
 while(RDR==0);
	return U0RBR;
}
void uart0_tx_string(char *ptr)
{
while(*ptr!=0)
{
	uart0_tx(*ptr);
     ptr++;
}
}
void uart0_tx_integer(int num)
{
char a[20];
	int i=0;
	if(num==0)
	{
		uart0_tx('0');
	  return;
	}
	if(num<0)
	{
	uart0_tx('-');
	num=-num;
	}
	while(num>0)
	{
	 a[i]=num%10+48;
		num=num/10;
		i++;
	}
		for(i=i-1;i>=0;i--)
		 uart0_tx(a[i]);
		
	}
void uart0_tx_float(float adc_val)
  {
  int num;
  if(adc_val<0)
  {
  adc_val=-adc_val;
  uart0_tx('-');
  }
  if(adc_val==0)
  {
  uart0_tx_string("0.0");
  return;
  }
  num=adc_val;
  uart0_tx_integer(num);
  uart0_tx('.');
  num=(adc_val-num)*1000000;
  uart0_tx_integer(num);
  }
