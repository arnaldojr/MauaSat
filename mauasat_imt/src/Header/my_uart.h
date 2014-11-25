#ifndef MY_UART.H
#define MY_UART.H

/************************************************************************/
/* INCLUDES                                                             */
/************************************************************************/

#include <uart.h>
#include <serial.h>
#include <stdio_serial.h>

/************************************************************************/
/* DEFINES                                                              */
/************************************************************************/

#define CONSOLE_UART_IRQn           UART0_IRQn
#define console_uart_irq_handler    UART0_Handler

#define CONF_UART			 UART0
#define CONF_UART_BAUDRATE   115200
#define CONF_UART_PARITY     UART_MR_PAR_NO

#define FRASE_DE_LOG "-- UART -- "BOARD_NAME" -- Compiled: "__DATE__" "__TIME__ " \n\n\rAGUARDANDO SINAL DE ENVIO.\r\n"
#define LOG_0 "-- MauaSat - Instituto Maua de Tecnologia - Escola de Engenharia Maua --"
#define LOG_1 "LOG 01 - Aguardando Comando"
#define LOG_2 "LOG 02 - Two Wire Send and Receive Test"
#define LOG_3 "LOG 03 - System Ok"
#define LOG_4 "LOG 04 - Two Wire Send Fail"
#define LOG_5 "LOG 05 - Two Wire Receive Fail"

/************************************************************************/
/* PROTOTIPAGEM                                                         */
/************************************************************************/

const usart_serial_options_t uart_serial_options = {
	.baudrate = CONF_UART_BAUDRATE,
	.paritytype = CONF_UART_PARITY
};

Inicia_UART(){
	sysclk_enable_peripheral_clock(CONSOLE_UART_ID);
	stdio_serial_init(UART0, &uart_serial_options);
}

#endif //MY_UART