#include "stm32f4xx.h"
#include "adc_yapphdr.h"

void main_init( void );

int main(void)
{ 
	struct adc_prv_data pdata;
	struct adc_device_apis *adc_apis;
  unsigned int data ;
	
	main_init();
	adc_apis = adc_device_open();
	adc_init(&pdata,0x00);
	adc_apis->configure_adc_clock(0,&pdata);
	adc_apis->configure_adc_parameters(0,0,0,&pdata);
	adc_apis->config_channel(0,7,12,&pdata);
	while(1)
	{
	adc_apis->adc_conv(1,&data,&pdata);
  }
}

void main_init(void)
{	
	RCC->APB2ENR |= 0x00000100; //ADC Clock enable
	RCC->AHB1ENR |= 0x00000004; //GPIO C Port RCC enable
	GPIOC->MODER |= 0x03000000; //Mode of channel 12 set as Analog
	//GPIOC->OTYPER|= 0x00000000;	//Output type selected as Push pull
	GPIOC->PUPDR |= 0x00000000; //No Pull Up and No Pull Down
	//GPIOC->IDR   |= 0x00001000;	//Input Data Register for channel 12
	//GPIOC->ODR   |= 0x00002000; //Output Data Register for channel 13
}


