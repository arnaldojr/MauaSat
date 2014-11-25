#include <Header/my_twi.h>

typedef struct pacote_dados {
	//! TWI address/commands to issue to the other chip (node).
	uint8_t endereco[3];
	//! Length of the TWI data address segment (1-3 bytes).
	uint32_t tamanho_endereco;
	//! Command to send
	uint8_t comando_twi;
	//! Where to find the data to be transferred.
	void *buffer;
	//! How many bytes do we want to transfer.
	uint32_t tamanho;
	//! TWI chip address to communicate with.
	uint8_t chip;
} pacote_dados;

typedef struct i2c_opcoes {
	//! MCK for TWI.
	uint32_t master_clk;
	//! The baud rate of the TWI bus.
	uint32_t speed;
	//! The desired address.
	uint8_t chip;
	//! SMBUS mode (set 1 to use SMBUS quick command, otherwise don't).
	uint8_t smbus;
} i2c_opcoes;

i2c_opcoes opc;
pacote_dados pacote_dados_tx, pacote_dados_rx;


/************************************************************************/
/* funções TWI                                                                     */
/************************************************************************/
// Configure the data packet to be transmitted
void Conf_Pacote_Dados_tx ()
{
	pacote_dados_tx.chip			 =	ADDRESS;
	pacote_dados_tx.endereco[0]      =  EEPROM_MEM_ADDR >> 8;
	pacote_dados_tx.endereco[1]      =  EEPROM_MEM_ADDR;
	pacote_dados_tx.tamanho_endereco =  EEPROM_MEM_ADDR_LENGTH;
	pacote_dados_tx.buffer			 =  (uint8_t *) dados_teste;
	pacote_dados_tx.tamanho			 =  TEST_DATA_LENGTH;
	pacote_dados_tx.comando_twi		 =	COMANDO;
}

/** Reception buffer - TWO WIRE */
static uint8_t gs_uc_dados_teste[TEST_DATA_LENGTH] = { 0 };

// Configure the data packet to be received
void Conf_Pacote_Dados_rx()
{
	pacote_dados_rx.chip			 = pacote_dados_tx.chip;
	pacote_dados_rx.endereco[0]      = pacote_dados_tx.endereco[0];
	pacote_dados_rx.endereco[1]      = pacote_dados_tx.endereco[1];
	pacote_dados_rx.tamanho_endereco = pacote_dados_tx.tamanho_endereco;
	pacote_dados_rx.buffer		     = gs_uc_dados_teste;
	pacote_dados_rx.tamanho			 = pacote_dados_tx.tamanho;
	pacote_dados_rx.comando_twi		 = pacote_dados_tx.comando_twi;
}

/** Global timestamp in milliseconds since start of application - TWO WIRE */
volatile uint32_t g_ul_ms_ticks = 0;

void SysTick_Handler(void)
{
	g_ul_ms_ticks++;
}

static void mdelay(uint32_t ul_dly_ticks)
{
	uint32_t ul_cur_ticks;

	ul_cur_ticks = g_ul_ms_ticks;
	while ((g_ul_ms_ticks - ul_cur_ticks) < ul_dly_ticks);
}

//********************************************Conf_TWI*********************************************************				
int Conf_TWI(){
	
	//printf("\nConfigure system tick to get 1ms tick period.\n\n\r");
	if (SysTick_Config(sysclk_get_cpu_hz() / 1000)) {
		printf("-E- Systick configuration error\r"); //Erro na configuração do clock da cpu
	}

// Enable the peripheral clock for TWI
pmc_enable_periph_clk(BOARD_ID_TWI_EEPROM);

// Configure the options of TWI driver
opc.master_clk = sysclk_get_cpu_hz();
opc.speed      = TWI_CLK;
					
}

//********************************************Inicia TWI***************************************************************
int Inicia_TWI(){
	
	if (twi_master_init(TWI2, &opc) != TWI_SUCCESS) {
		printf("-E-\tTWI master initialization failed.\n\r");
	}
}

//********************************************escreve_pacote***********************************************************				
int Escreve_pacote(){		
									
	if (twi_master_write(TWI2, &pacote_dados_tx)!= TWI_SUCCESS){
		printf("- Error -\tTWI master write packet failed.\n\r");
	}
	else{
		printf("Write:\tOK!\n\r");
		printf("Valor escrito: \t%s\n\r", pacote_dados_tx.buffer);
		printf("Endereco escrito: \t%d \tTamanho do endereco: %p\n\r", pacote_dados_tx.endereco, pacote_dados_tx.tamanho_endereco);
		printf(STRING_JUMP_LINE);
	}
										
// Wait at least 10 ms
mdelay(WAIT_TIME);
};
				
//***********************************************limpa_buffer******************************************************************				
int Limpa_buffer(){
	
	int i;
	for(i=0; i<= TEST_DATA_LENGTH; i++)  // limpa todo os bites do buffer
		*(i+gs_uc_dados_teste) = 0 ;		//poderia ser assim tbm = gd_uc_dados_teste[i] = 0;
};	
				
//************************************************le_pacote********************************************************************
int Le_pacote(){
	
	if  (twi_master_read(TWI2, &pacote_dados_rx) != TWI_SUCCESS) {
		printf("- Error -\tTWI master read packet failed.\n\r");
		printf("Valor lido: \t%s\n\r", pacote_dados_rx.buffer);
	}
	else{
		printf("Read:\tOK!\n\r");
		printf("Valor lido: \t%s\n\r", pacote_dados_rx.buffer);
		printf("Endereco lido: \t%p \tTamanho do endereco: %p\n\r", pacote_dados_rx.endereco, pacote_dados_rx.tamanho_endereco);
		printf("\n\r");
	}
};
				
//***************************************Compara pacote com o buffer*************************************************************				
int Compara_pacote_buffer(){
	
	int i;		
	for (i = 0; i < TEST_DATA_LENGTH; i++) {
		if (dados_teste[i] != gs_uc_dados_teste[i]) {
			printf("Data comparison:\tUnmatched!\r");
		}
		else{
			printf("Data comparison:\tMatched!\r");
		}
	}
}
				
				