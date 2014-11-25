#include <Header/my_io.h>

int io_led_pisca(uint32_t tempo)    // funÃ§Ã£o que retorna uma variavel( int)  e tem 1 argumento nesse caso tempo que Ã© uma variavel uint32_t
{
	while (ioport_get_pin_level(BOTAO_STRING) == 1)
	{
		ioport_set_pin_level(LED_NSEE, true);
		delay_ms(tempo);
		ioport_set_pin_level(LED_NSEE, false);
		delay_ms(tempo / 5);
	}
}

void Conf_LED ()
{
	ioport_enable_pin(LED_NSEE);
	ioport_set_pin_dir(LED_NSEE, IOPORT_DIR_OUTPUT);
	ioport_set_pin_level(LED_NSEE, true);  //  LED NSEE ? 1
}

void Conf_Botao ()
{
	ioport_enable_pin(BOTAO_STRING);
	ioport_set_pin_dir(BOTAO_STRING, IOPORT_DIR_INPUT);
}

void Conf_Pinos_UART()
{
	ioport_set_pin_dir(RX, IOPORT_DIR_INPUT);
	ioport_set_pin_dir(TX, IOPORT_DIR_OUTPUT);
}