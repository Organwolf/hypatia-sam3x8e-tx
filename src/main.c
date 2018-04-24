/**
 * Authors: Aron Polner & Filip Nilsson
 */
#include <asf.h>
#include "consoleFunctions.h"
#include "usart0.h"
#include "conf_tc.h"

int main (void)
{
	/* Insert system clock initialization code here (sysclk_init()). */
	sysclk_init();
	board_init();
	usart0_init();
	configureConsole();
	configure_tc();
	
	
	while(1){
		//do nothing
	}

	/* Insert application code here, after the board has been initialized. */
}
