#include "pico/stdlib.h"
#include <stdio.h>
#include "hardware/uart.h"
#include <stdint.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/uart.h"


#define BAUD_RATE 9600
#define DATA_BITS 8
#define STOP_BITS 1
#define PARITY UART_PARITY_NONE


#define UART_TX_PIN 0
#define UART_RX_PIN 1


void send_message(unsigned char *message, int len)
{
	int i;
	
	for (i=0; i<len; i++)
	{
		printf("%c", message[i]);

		uart_putc(uart0, message[i]);
	}
}

int main() {

	stdio_init_all();
	uart_init(uart0, BAUD_RATE);
	gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
	gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);
	uart_set_format(uart0, DATA_BITS, STOP_BITS, PARITY);

	unsigned char message[] = {'$','P','M','T','K','1','0','4','*','3','7','\r','\n'};

	int length = sizeof(message)/sizeof(message[0]);

	send_message(message, length);

	while (1) {
		if (uart_is_readable(uart0)) {
			char c = uart_getc(uart0);
			printf("%c", c);	
		}


	}

	
}