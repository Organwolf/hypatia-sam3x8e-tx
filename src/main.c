/**
 * Authors: Aron Polner & Filip Nilsson
 */
#include <asf.h>
#include "usart0.h"
#include "conf_tc.h"
#include "consoleFunctions.h"

int main (void)
{
	sysclk_init();
	board_init();
	usart0_init();
	ioport_init();
	configure_tc();
	configureConsole();
	
	while(1){
		//do nothing
	}
}
