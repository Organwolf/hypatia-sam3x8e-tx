/*
 * usart0.c
 *
 * For USART communication the TX1 is used. 
 *
 * Created: 2018-02-20 20:07:46
 *  Author: Filip Nilsson
 */ 
#include "asf.h"
#include "usart0.h"


#define TXEN0 6

#define USART0_BASE_ADDRESS (0x40098000U)
uint32_t *const ptr_USART0_CR = (uint32_t *) (USART0_BASE_ADDRESS + 0x0000U);	//Control register
uint32_t *const ptr_USART0_MR = (uint32_t *) (USART0_BASE_ADDRESS + 0x0004U);	//Mode register
uint32_t *const ptr_USART0_SR = (uint32_t *) (USART0_BASE_ADDRESS + 0x0014U);	//Status register
uint32_t *const ptr_USART0_THR = (uint32_t *) (USART0_BASE_ADDRESS + 0x001CU);	//Transmit holding register
uint32_t *const ptr_USART0_BRGR = (uint32_t *) (USART0_BASE_ADDRESS + 0x0020U);	//Baud-rate generator

volatile uint8_t packetId = 0;
volatile uint8_t packet[8] = {1,2,3,4,5,6};
volatile uint8_t counter=0;
volatile uint8_t sync = 0b01010101;

void usart0_init(void){
	pmc_enable_periph_clk(ID_USART0);
	*ptr_USART0_CR |= (1u<<TXEN0);					//Enable TXEN.
	*ptr_USART0_MR |= (1<<6) | (1<<7);
	*ptr_USART0_MR &= ~((1<<5) | (1<<4));
	//*ptr_USART0_MR |= 0x800;						//no parity, normal mode
	PIOA->PIO_PDR |= (PIO_PA10) | (PIO_PA11);
	*ptr_USART0_BRGR |= (0b1000100010111<<0);		//Set baudrate(1200). CD==0b1000100010111.
}

void usart0_transmit(unsigned char data){
	while(!(*ptr_USART0_SR & (1u<<1)));		//Wait for an empty tx-buffer.
	while(!(*ptr_USART0_SR & (1u<<9)));	
		
	*ptr_USART0_THR = data;
}


void TC0_Handler(void)
{	
	/* Clear status bit to acknowledge interrupt & avoid compiler warning */
	volatile uint32_t ul_dummy;
	ul_dummy = tc_get_status(TC0, 0);
	UNUSED(ul_dummy);
	
	if(counter == 0){
		usart0_transmit(sync);
		counter++;
	}
	else{
		usart0_transmit(packet[counter-1]);
		counter++;
	}	
	if(counter==7){
		counter=0;
	}
}