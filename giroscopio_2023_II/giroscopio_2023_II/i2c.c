/*
 * i2c.c
 *
 * Created: 
 *  Author: jlb
 */ 

/*
 *Libreria de I2C
 *Contiene los métodos para iniciar la interfaz, enviar las condiciones de inicio y para de la interfaz
 *y enviar o leer datos a través de la interfaz I2C
 */

#include <avr/io.h>
#include <util/delay.h>
#include "i2c.h"

void i2c_init(void)
{
	TWSR = ((0 << TWPS1) & (0 << TWPS0)); //Prescaler = 1
	TWBR = 0X14; //Define Bit rate SCL_frec=CPU_frec/(16+2(TWBR)x4^(prescaler))
				//SCL_Frec=(16000000/(16+2(20)(4)))=74Khz
	TWCR = (1<<TWEN); //Activa la interfaz TWI
}

void i2c_start(void)
{
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN); //Genera condición de START
	while((TWCR & (1<<TWINT))==0); //Espera hasta que TWINT=0 (TWI termina su trabajo)
}

void i2c_stop(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO); //Genera condición de STOP
	_delay_ms(1);
}

void i2c_write(uint8_t data)
{
	TWDR = data; //Byte a escribir
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA); //Escritura con reconocimiento (TWEA=1)
	while((TWCR & (1<<TWINT))==0); //Espera hasta que TWINT=0 (TWI termina su trabajo)
}

uint8_t i2c_read(void){
	TWCR = (1<<TWINT)|(1<<TWEN); //Lectura sin reconocimiento (TWEA=0)
	while((TWCR & (1<<TWINT))==0); //Espera hasta que TWINT=0 (TWI termina su trabajo)
	return TWDR; //Regresa el valor leído
}

uint8_t i2c_read_Ack(void)
{
	
	//Comienza el módulo TWI y envía la señal de reconocimiento (acknowledge) tras la recepción
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
	// Espera por el fin de la transmisión
	while( !(TWCR & (1<<TWINT)) );
	// Devuelve los datos recibidos por TWDR
	return TWDR;
}

uint8_t i2c_read_Nak(void){
	//Comienza a recibir, envía la condición de no reconocimiento (Not acknowledgment)
	TWCR = (1<<TWINT) | (1<<TWEN);
	//Espera por el fin de la transmisión
	while( !(TWCR & (1<<TWINT)) );
	//Devuelve los datos recibidos de TWDR
	return TWDR;
}