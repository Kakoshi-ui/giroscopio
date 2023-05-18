/*
 * mpu_6050.h
 *
 * Created: 5/12/2023 6:26:21 AM
 *  Author: axel9
 */ 
#include "mpu6050_registers.h"

#ifndef MPU_6050_H_
#define MPU_6050_H_

void init_MPU6050(void);
void mpu_command(uint8_t command, uint8_t data);
int8_t mpu_read(uint8_t regAddr);
void i2c_test_conection(void);


#endif /* MPU_6050_H_ */