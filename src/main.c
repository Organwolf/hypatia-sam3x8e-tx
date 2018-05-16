/**
 * Authors: Aron Polner & Filip Nilsson
 */
#include <asf.h>
#include "usart0.h"
#include "conf_tc.h"
#include "pinmapper.h"
#include "uart.h"
#include "uartfunctions.h"


extern uint8_t finalXYCoordinates[2] = {120,65};
extern int recieve_flag = 1;

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
	
	while(1){
		//New coordinate incoming from the uart && And the previous coordinate has been sent to the master
		if ((read_char() == 'V')&&(recieve_flag==1)){
			tc_stop(TC0,0); //no interrupt when receiving new position
			uint8_t tempXYCoordinates[2] = {0}; //receive 6 chars 3x and 3y
			for(int i = 0; i < 2; i++){
				while(!uart_receiver_ready()){ //wait until ready
				}
				tempXYCoordinates[i] = uart_receive_char();
			}
			
			for(int i = 0; i < 2; i++){
				finalXYCoordinates[i] = tempXYCoordinates[i];
			}
			recieve_flag=0;
			tc_start(TC0,0);
		
		}
	}
}