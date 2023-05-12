/*
 * oled_i2c.c
 *
 * Created: 4/28/2023 4:10:34 PM
 *  Author: axel9
 */ 
#include <avr/io.h>
#include <util/delay.h>
#include "oled_i2c.h"
#include "i2c.h"

char columna_1[2] = {0,128};
char columna_2[2] = {0,128};
	
void oled_command(uint8_t command){
	
	i2c_start();									//Inicia la comunicaci�n I2C
	i2c_write(SSD1306_ADDR << 1 | SSD1306_WRITE);	//Establece comunicaci�n con la direcci�n del SSD1306 en modo de escritura R/W#=0
													//(Pag. 20 SSD1306)
	i2c_write(0x00);								//Env�a el byte de comando para configurar el display C0=0|D/C#
	i2c_write(command);								//Env�a el byte de comandos de control
	i2c_stop();										//Detiene la comunicaci�n I2C
	
}

void oled_data(uint8_t data){
	
	i2c_start();									//Inicia la comunicaci�n I2C
	i2c_write(SSD1306_ADDR << 1 | SSD1306_WRITE);	//Escribe sobre la direcci�n del SSD1306 en modo de escritura de datos
	i2c_write(0x40);								//Env�a el byte de comando para que el SSD1306 reconozca que se env�an datos
	i2c_write(data);								//Env�a el dato para mostrar
	i2c_stop();										//Detiene la comunicaci�n I2C
	
}

void init_i2c_oled(void){

	init_i2c_oled();
	//Ajuste del contraste ajuste entre m�s grande sea el valor m�s aumenta el contraste
	oled_command(SET_CONTRAST);						
	oled_command(0xCF);
	
	//Display OFF, sleep mode
	oled_command(SET_DISPLAY_OFF);					
	
	//Selecci�n del reloj
	//La frecuencia del reloj se mantiene en Reset todo el tiempo
	oled_command(SET_DISPLAY_CLOCK);				
	oled_command(0x80);								
	
	//Rango del multiplexor (64 solamente)
	oled_command(SET_MUX_RATIO);					
	oled_command(64-1);			
	
	//Offset del display (sin offset)
	oled_command(SET_DISPLAYOFFSET);
	oled_command(0x00);
	
	//Linea de inicio: 0-63
	oled_command(SET_START_LINE);
	
	//?????? valores 14-15
	oled_command(SET_CHARGEPUMP);
	oled_command(0x14);
	
	//Modo de la GDDRAM
	oled_command(SET_MEMORY);
	oled_command(0x00);
	
	//
	oled_command(SET_PRECHARGE);
	oled_command(0xCF);
	oled_command();
}

