#include<lpc21xx.h>
void uart0_init(unsigned int baud);
void uart0_tx(unsigned int data);
unsigned char uart0_rx(void);
void uart0_tx_string(char *ptr);
void uart0_tx_integer(int num);
void uart0_tx_float(float adc_val);
   void timer0_init(void);
    void timer0_handler(void)__irq;
	 void config_vect_timer0(void);
	 void adc_init(void);
	 unsigned int adc_read(unsigned int ch_num);
	    void FLAME_sensor(void);
			void adc_init(void);
			int temperature_sensor(void);
			 int potentiometer_sensor(void);
			   int LDR_sensor(void);
				 void vibrator_sensor(void);
