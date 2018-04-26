/**
 * Authors: Aron Polner & Filip Nilsson
 */
#include <asf.h>
#include "usart0.h"
#include "conf_tc.h"
#include "consoleFunctions.h"

int main (void)
{
	/* Insert system clock initialization code here (sysclk_init()). */
	sysclk_init();
	board_init();
	usart0_init();
	ioport_init();
	configure_tc();
	configureConsole();

	//usart0_transmit(hammingData);
	
	while(1){
		//do nothing
	}

	/* Insert application code here, after the board has been initialized. */
}
