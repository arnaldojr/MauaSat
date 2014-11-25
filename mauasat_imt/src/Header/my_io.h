#ifndef MY_IO.H
#define MY_IO.H

/************************************************************************/
/* INCLUDES                                                             */
/************************************************************************/

#include <ioport.h>
#include <delay.h>

/************************************************************************/
/* DEFINES                                                              */
/************************************************************************/

#define LED_NSEE     PIO_PA16_IDX
#define BOTAO_STRING	 IOPORT_CREATE_PIN(PIOA,2)
#define RX			 PIO_PA9_IDX
#define TX			 PIO_PA10_IDX

/************************************************************************/
/* PROTOTIPAGEM                                                         */
/************************************************************************/

int io_led_pisca(uint32_t tempo);    // funÃ§Ã£o que retorna uma variavel( int)  e tem 1 argumento nesse caso tempo que Ã© uma variavel uint32_t

void Conf_LED ();

void Conf_Botao ();

void Conf_Pinos_UART();		

#endif //MY_IO