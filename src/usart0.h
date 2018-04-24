/*
 * usart0.h
 *
 * Created: 2018-02-20 20:08:06
 *  Author: Filip Nilsson
 */ 


#ifndef UART_H_
#define UART_H_

void usart0_init(void);
void usart0_transmit(unsigned char data);
char usart0_receive(void);


#endif /* UART_H_ */