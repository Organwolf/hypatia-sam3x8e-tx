/**
 * Authors: Aron Polner & Filip Nilsson
 */
#include <asf.h>
#include "consoleFunctions.h"
#include "usart0.h"
#include "conf_tc.h"
#include "createHamming.h"

int main (void)
{
	/* Insert system clock initialization code here (sysclk_init()). */
	sysclk_init();
	board_init();
	usart0_init();
	ioport_init();
	configure_tc();
	configureConsole();
	
	uint8_t dataBits[4] = {0,1,1,1};
	uint8_t hammingData;
	hammingData = createHammingCode(dataBits);
	//printf("%d",hammingData);
	//usart0_transmit(hammingData);
	
	while(1){
		//do nothing
	}

	/* Insert application code here, after the board has been initialized. */
}
