#ifndef MY_TWI.H
#define MY_TWI.H

/************************************************************************/
/* INCLUDES                                                             */
/************************************************************************/

#include <twi.h>
#include <sysclk.h>

/************************************************************************/
/* DEFINES                                                              */
/************************************************************************/

#define STRING_JUMP_LINE    "\n\r"

/** EEPROM Wait Time */
#define WAIT_TIME   10
/** TWI Bus Clock 400kHz */
#define TWI_CLK     400000

#define EEPROM_MEM_ADDR         0
#define EEPROM_MEM_ADDR_LENGTH  2

/** Data to be sent */
#define TEST_DATA_LENGTH  (sizeof(dados_teste)/sizeof(uint8_t))

#define STRING_HEADER "-- TWO WIRE --"BOARD_NAME" -- Compiled: "__DATE__" "__TIME__" --"STRING_JUMP_LINE

/** TWI ID for simulated EEPROM application to use */
#define BOARD_ID_TWI_EEPROM         ID_TWI2
/** TWI Base for simulated TWI EEPROM application to use */
#define BOARD_BASE_TWI_EEPROM       TWI2



/************************************************************************/
/* ENDEREÇOS DOS SLAVES                                                 */
/************************************************************************/ 
#define SLAVE_01        0x40
#define SLAVE_02		0x50
#define SLAVE_03		0x60

/************************************************************************/
/* PROTOTIPAGEM                                                         */
/************************************************************************/

int	 Conf_TWI();

int	 Inicia_TWI();

void Conf_Pacote_Dados_rx();

void Conf_Pacote_Dados_tx ();

int  Escreve_pacote();			

int	 Limpa_buffer();

int	 Le_pacote();		

int	 Compara_pacote_buffer();				
				
/************************************************************************/
/* constantes e variaveis                                               */
/************************************************************************/

// DADOS NA EEPROM
static const uint8_t dados_teste[] = {
	// Conteúdo de memória - MAUASAT 2015 - ARNALDO, OTAVIO E TIAGO
	'M', 'A', 'U', 'A', 'S', 'A', 'T', ' ',
	'2', '0', '1', '5', ' ', '-', ' ', 'A', 'R',
	'N', 'A', 'L', 'D', 'O', ' ', 'O', 'T', 'A', 'V', 'I','O',' ', 'E', ' ', 'T','I','A','G','O'
};

uint32_t ADDRESS;
uint8_t COMANDO;

				
#endif //MY_TWI
