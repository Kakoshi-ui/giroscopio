/*
 * giroscopio_2023_II.c
 *
 * Created: 5/12/2023 6:22:56 AM
 * Author : axel9
 */ 
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>
#include "mpu_6050.h"

int main(void){
	
	init_MPU6050();
	i2c_test_conection();
  
}

