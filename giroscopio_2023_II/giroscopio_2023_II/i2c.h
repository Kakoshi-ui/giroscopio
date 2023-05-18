/*
 * i2c.h
 *
 * Created: 6/29/2021 7:00:30 PM
 *  Author: jlb
 */ 


#ifndef I2C_H_
#define I2C_H_

void i2c_init(void);
void i2c_write(uint8_t data);
void i2c_start(void);
void i2c_stop(void);
uint8_t i2c_read(void);
uint8_t i2c_read_Ack(void);
uint8_t i2c_read_Nak(void);

#define TRUE 1
#define FALSE 0

#endif /* I2C_H_ */