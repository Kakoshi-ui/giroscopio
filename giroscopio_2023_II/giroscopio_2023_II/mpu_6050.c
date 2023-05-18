/*
 * mpu_6050.c
 *
 * Created: 5/12/2023 6:26:05 AM
 *  Author: axel9
 * La base de la configuraci�n de este proyecto, toma como referencia los archivos fuente y 
 * la configuraci�n del proyecto hecho por Davide Girone:
 * http://davidegironi.blogspot.com/2013/02/avr-atmega-mpu6050-gyroscope-and.html
 */ 

#include <stdlib.h>
#include <string.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <math.h>
#include "mpu_6050.h"
#include "i2c.h"

volatile uint8_t buffer[12];

/*** Funci�n para enviar datos de comandos al MPU6050
 *** command: Pide la direcci�n del registro a modificar
 *** data: Pide el valor del registro que se va a modificar
 ***/ 
void mpu_command(uint8_t command, uint8_t data){
	
	// Condici�n de inicio
	i2c_start();	
	
	// Env�a la direcci�n slave del MPU6050 para reconocer la comunicaci�n entre ellos
	i2c_write(MPU6050_ADDR << 1 | MPU6050_WRITE);
	// Env�a la direcci�n del registro a escribir en el MPU6050
	i2c_write(command);
	// Env�a los valores del registro sobre el cual se va a escribir
	i2c_write(data);
	
	// Condici�n de paro
	i2c_stop();
}

/*** Funci�n para leer los datos del MPU6050, verificar la forma de env�o de datos por parte del MPU6050
 *** Dado que los registros de Giroscopio y Aceler�metro son de 16 bits es importante verificar la captura de los datos recibidos
 ***/
int8_t mpu_read(uint8_t regAddr){
	
	volatile int8_t data_read = 0;
	
	i2c_start();
	
	i2c_write(MPU6050_ADDR << 1 | MPU6050_WRITE);
	i2c_write(regAddr);
	
	i2c_start();
	i2c_write(MPU6050_ADDR << 1 | MPU6050_READ);
	data_read = i2c_read_Nak();
	
	i2c_stop();
	
	return data_read;
}

/* Funci�n de lectura de m�s de un byte
 * La funci�n que sigue a continuaci�n, es creada con el fin de leer m�s de un byte de datos provenientes
 * del MPU6050, dado que el m�dulo es capaz de generar registros de 16 bits, es necesario guardarlos en 
 * registros de 16 bits, aunque solo se puedan transmitir y leer 8bits
 */
int8_t mpu_readBytes(int8_t address, int8_t length, int8_t *data){
	
	uint8_t temp_addr = address;
	
	if(length > 0){
		i2c_start();
		i2c_write(MPU6050_ADDR << 1 | MPU6050_WRITE);
		i2c_write(address);
		
		i2c_start();
		i2c_write(MPU6050_ADDR << 1 | MPU6050_READ);
		
		for (int i=0; i<length;i++){
			if (i == length-1){
				data[i]=i2c_read_Nak();
			}
			else{
				data[i]=i2c_read_Ack();
			}
		}
		i2c_stop()
	}
}

/*** Prueba de conectividad del MPU por I2C
 *** Usando el registro WHO_AM_I, solicita el valor en dicho registro
 *** y luego lo compara con la direcci�n que se tiene del periferico
 *** si ambas coinciden se enciende el led del MCU
 ***/
void i2c_test_conection(void){
	
	uint8_t mpu_who_ami = 0;
	DDRB &= 0 << PB5;
	mpu_who_ami=mpu_read(MPU_WHO_AM_I);
	
	if ((MPU6050_ADDR & mpu_who_ami) == 0x68){
		PORTB |= 1 << PB5;
	}
	else{
		PORTB &= 0 <<PB5;
	}
}

//*** RECORDAR!!!, el MPU6050 inicia la comunicaci�n I2C
//*** Funci�n de inicializaci�n del MPU6050
//*** Configura los par�metros de funcionamiento de este y establece la rutina de inicio descrita en
//*** la hoja de datos t�cnicos
void init_MPU6050(void){
	
	i2c_init();										//Inicia la comunicaci�n I2C
	
	_delay_us(10);									//*** Tiempo de espera hasta que se complete el proceso de inicio del MPU6050,
													//*** el tiempo establecido se describe en el Datasheet del MPU6050
	_delay_ms(100);									//***
	
	mpu_command(MPU_PWR_MGMT_1, 0x00 << SLEEP);		//Deshabilita el modo sleep
	
	mpu_command(MPU_PWR_MGMT_1, 0x01 << CLKSEL);	//Selecciona el reloj interno del MPU6050
	
	mpu_command(MPU_CONFIG, 0x03 << DLPF_CFG);		//Configura la frecuencia del filtro pasa bajas digital interno
	
	mpu_command(MPU_SMPLRT_DIV, 0x04);				//Configura el factor de preescaler del reloj interno del m�dulo
	
	mpu_command(MPU_GYRO_CONFIG, 0x03 << FS_SEL);	//***Selecciona la frecuencia de muestreo tanto del giroscopio
	mpu_command(MPU_ACCEL_CONFIG, 0x03 << AFS_SEL);	//***como del aceler�metro
}

void read_rawData(int16_t* gx, int16_t* gy, int16_t gz, int16_t* ax, int16_t* ay, int16_t* az){
	
	*gx = mpu_read(MPU_GYRO_XOUT_H);
	
}