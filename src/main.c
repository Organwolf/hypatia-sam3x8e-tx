/**
 * Authors: Aron Polner & Filip Nilsson
 */
#include <asf.h>
#include "usart0.h"
#include "conf_tc.h"
#include "pinmapper.h"
#include "uart.h"
#include "uartfunctions.h"


extern uint8_t finalXYCoordinates[6] = {0};
//extern int recieve_flag = 1;
#define UART_BAUDRATE	115200

int main (void)
{
	/* Insert system clock initialization code here (sysclk_init()). */
	sysclk_init();
	board_init();
	usart0_init();
	ioport_init();
	uart_config((uint32_t)UART_BAUDRATE);
	configure_tc();
	//usart0_transmit(hammingData);
	
	while(1){
		if (read_char() == 'V'){
			tc_stop(TC0,0); //no interupt when recieving new posisition
			uint8_t tempXYCoordinates[2] = {0}; //recieve 6 chars 3x and 3y
			for(int i = 0; i < 2; i++){
				while(!uart_receiver_ready()){ //wait until ready
				}
				tempXYCoordinates[i] = uart_receive_char();
			}
			
			for(int i = 0; i < 2; i++){
				finalXYCoordinates[i] = tempXYCoordinates[i];
			}
			tc_start(TC0,0);
	}

	/* Insert application code here, after the board has been initialized. */
		}
	}