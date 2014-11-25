/************************************************************************/
/*		MauaSat - CubeSat - Escola de Engenharia Mauá                   */
/*																		*/
/* Desenvolvido por:		Otávio Petito								*/
/* FW version:	1.5														*/
/* Data:		11.11.2014												*/
/*																		*/
/************************************************************************/

/************************************************************************/
/* INCLUDES                                                             */
/************************************************************************/

#include "../Header/asf.h"
#include "stdio_serial.h"
#include "conf_board.h"
#include "led.h"
#include "../Header/my_io.h"
#include "../Header/my_uart.h"
#include "../Header/my_twi.h"

int main(void)
{
    SystemInit();
	sysclk_init();
	board_init();
	
	uint32_t teste_botao, tempo;

	/************************************************************************/
	/* Inicialização das variaveis                                          */
	/************************************************************************/
	
	teste_botao = 0;
	tempo = 200;

	
	/************************************************************************/
	/* Término da inicialização das variáveis                               */
	/************************************************************************/
		
	Conf_LED();
	Conf_Botao();		
	Conf_Pinos_UART();	
	Conf_TWI();
	
	Inicia_TWI();
	Inicia_UART();

    //Conf_Pacote_Dados_tx();
	Conf_Pacote_Dados_rx();
	
	printf(FRASE_DE_LOG "\n\r");

		while (1){			
			io_led_pisca(tempo);
			
			//Envio para Slave 01	
			ADDRESS = SLAVE_01;
			COMANDO = 01;
			
			Conf_Pacote_Dados_tx();
			
			printf("Tamanho do vetor: \t%d\n\r", TEST_DATA_LENGTH);
			printf("Conteudo da memoria: \t%s\n\r", dados_teste);
			printf("Endereco para gravacao: \t%p\n\n\r", ADDRESS); // endereço da eeprom
			//printf("Comando: \n\r", COMANDO);
										
			Escreve_pacote();
			Limpa_buffer();
			Le_pacote();
			Compara_pacote_buffer();
				
			printf("\n*********************************************************************\n\r");
			printf(STRING_JUMP_LINE);
			delay_ms(500);
			
			//Envio para Slave 02
//			ADDRESS = SLAVE_02;
//			COMANDO = 01;
//			
//			Conf_Pacote_Dados_tx();
						
//			printf("Tamanho do vetor: \t%d\n\r", TEST_DATA_LENGTH);
//			printf("Conteudo da memoria: \t%s\n\r", dados_teste);
//			printf("Endereco para gravacao: \t%p\n\n\r", ADDRESS); // endereço da eeprom
//			printf("Comando: ", COMANDO);
					
//			Escreve_pacote();
//			Limpa_buffer();
//			Le_pacote();
//			Compara_pacote_buffer();
						
//			printf("\n*********************************************************************\n\r");
//			printf(STRING_JUMP_LINE);
//			delay_ms(500);

			//Envio para Slave 03
//			ADDRESS = SLAVE_03;
//			COMANDO = 01;
			
//			Conf_Pacote_Dados_tx();
			
//			printf("Tamanho do vetor: \t%d\n\r", TEST_DATA_LENGTH);
//			printf("Conteudo da memoria: \t%s\n\r", dados_teste);
//			printf("Endereco para gravacao: \t%p\n\n\r", ADDRESS); // endereço da eeprom
//			printf("Comando: ", COMANDO);
			
//			Escreve_pacote();
//			Limpa_buffer();
//			Le_pacote();
//			Compara_pacote_buffer();
			
			printf("\n*********************************************************************\n\r");
			printf(STRING_JUMP_LINE);
			delay_ms(2000);

		}
			
}