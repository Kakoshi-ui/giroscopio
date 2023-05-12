/*
 * oled_i2c.h
 *
 * Created: 4/28/2023 4:10:47 PM
 *  Author: axel9
 */ 

#ifndef OLED_I2C_H_
#define OLED_I2C_H_

#define SSD1306_ADDR	0x3C	/*Dirección del dispositivo
								 *SSD1306 Desplazado una posicion a la izquierda 0x78
								 *SSD1306 Desplazado una posicion a la izquierda con el ultimo bit en 1 es 0x79*/
#define SSD1306_WRITE	0x00
#define SSD1306_READ	0x01

//Comandos fundamentles de control
#define SET_CONTRAST		0x81
#define ENTIRE_DISPLAY_OFF	0xA4
#define ENTIRE_DISPLAY_ON	0xA5
#define NORMAL_DISPLAY		0xA6
#define INVERT_DISPLAY		0xA7
#define SET_DISPLAY_OFF		0xAE
#define SET_DISPLAY_ON		0xAF

#define SET_DISPLAYOFFSET	0xD3
#define SET_COMMON_PINS		0xDA

//Dimensiones de la pantalla OLED
#define SSD1306_LCDWIDTH	128
#define SSD1306_LCDLHEIGHT	64

//Configuración del Hardware
#define SEGMENT_ADDR_0		0xA0
#define SEGMENT_ADDR_128	0xA1
#define SET_MUX_RATIO		0xA8
#define DISPLAY_OFFSET		0xD3
#define	COM_PINS_HARD_CONF	0xDA
#define SET_START_LINE		0x40	//0x40-0x7F

//Set Memory
#define SET_MEMORY			0x20
#define SET_COLUMN_ADDRESS	0x21

//Timing and Driving Scheme
#define SET_DISPLAY_CLOCK	0xD5
#define SET_PRECHARGE		0xD9
#define SET_CHARGEPUMP		0xD8
#define NO_OPERATION		0xE3


void oled_command(uint8_t command);
void oled_data(uint8_t data);
void init_i2c_oled(void);




#endif /* OLED_I2C_H_ */