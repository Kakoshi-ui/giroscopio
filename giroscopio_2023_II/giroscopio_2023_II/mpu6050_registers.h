/*
 * mpu6050_registers.h
 *
 * Created: 5/14/2023 1:05:39 PM
 *  Author: axel9
 */ 


#ifndef MPU6050_REGISTERS_H_
#define MPU6050_REGISTERS_H_

//Solo se empleará un MPU6050, por lo que no es necesario configurar el pin AD0 para cambiar la dirección
#define MPU6050_ADDR	0x68

//Bit de lectura/escritura
#define MPU6050_WRITE	0
#define MPU6050_READ	1

//Registros de Self-Test(Auto-Prueba)
#define MPU_SELF_TEST_X		0x0D
#define MPU_SELF_TEST_Y		0x0E
#define MPU_SELF_TEST_Z		0x0F
#define MPU_SELF_TEST_A		0x10

//Divisor de rango de pruebas
#define MPU_SMPLRT_DIV		0x19

//Configuraciones: Giroscopio, Acelerómetro
#define MPU_CONFIG			0x1A
#define MPU_GYRO_CONFIG		0x1B
#define MPU_ACCEL_CONFIG	0x1C

//Habilitar FIFO
#define MPU_FIFO_EN			0x23

//I2C Control Maestro
#define MPU_I2C_MST_CTRL	0x24

//I2C Slave 0 Control
#define MPU_I2C_SLV0_ADDR	0x25
#define MPU_I2C_SLV0_REG	0x26
#define MPU_I2C_SLV0_CTRL	0x27

//I2C Save 1 Control
#define MPU_I2C_SLV1_ADDR	0x28
#define MPU_I2C_SLV1_REG	0x29
#define MPU_I2C_SLV1_CTRL	0x2A

//I2C Slave 2 Control
#define MPU_I2C_SLV2_ADDR	0x2B
#define MPU_I2C_SLV2_REG	0x2C
#define MPU_I2C_SLV2_CTRL	0x2D

//I2C Slave 3 Control
#define MPU_I2C_SLV3_ADDR	0x2E
#define MPU_I2C_SLV3_REG	0x2F
#define MPU_I2C_SLV3_CTRL	0x30

//I2C Slave 4 Control
#define MPU_I2C_SLV4_ADDR	0x31
#define MPU_I2C_SLV4_REG	0x32
#define MPU_I2C_SLV4_DO		0x33
#define MPU_I2C_SLV4_CTRL	0x34
#define MPU_I2C_SLV4_DI		0x35

//I2C Master Status
#define MPU_I2C_MST_STATUS	0x36

//Int Pin/Bypass Configuration
#define MPU_INT_PIN_CFG		0x37

//Habilitar Interrupción
#define MPU_INT_ENABLE		0x38

//Estado de la Interrupción
#define MPU_INT_STATUS		0x3A

//Registros de medidas: Los registros de mediciones del acelerómetro, giroscopio y de temperatura
//Entregan mediciones en registros de 16bits por lo que poseen dos registros para la medida

//Medidas del Acelerómetro
#define MPU_ACCEL_XOUT_H	0x3B
#define MPU_ACCEL_XOUT_L	0x3C
#define MPU_ACCEL_YOUT_H	0x3D
#define MPU_ACCEL_YOUT_L	0x3E
#define MPU_ACCEL_ZOUT_H	0x3F
#define MPU_ACCEL_ZOUT_L	0x40

//Medidas de temperatura
#define MPU_TEMP_OUT_H		0x41
#define MPU_TEMP_OUT_L		0x42

//Medidas del Giroscopio
#define MPU_GYRO_XOUT_H		0x43
#define MPU_GYRO_XOUT_L		0x44
#define MPU_GYRO_YOUT_H		0x45
#define MPU_GYRO_YOUT_L		0x46
#define MPU_GYRO_ZOUT_H		0x47
#define MPU_GYRO_ZOUT_L		0x48

//Datos de sensor externo(24 Registros, solo se incluyen 2 temporalmente)
#define MPU_EXT_SENS_DATA_00	0x49
#define MPU_EXT_SENS_DATA_23	0x60

//Salida de datos de SLAVEX
#define MPU_I2C_SLV0_DO		0x63
#define MPU_I2C_SLV1_DO		0x64
#define MPU_I2C_SLV2_DO		0x65
#define MPU_I2C_SLV3_DO		0x66

//Control de delay maestro I2C
#define MPU_I2_MST_DELAY_CTRL	0x67

//Signal Path Reset
#define MPU_SIGNAL_PATH_RESET	0x68

//Control de usuario
#define MPU_USER_CTRL		0x6A

//Manejo de energía
#define MPU_PWR_MGMT_1		0x6B
#define MPU_PWR_MGMT_2		0x6C

//Registro de conteo del FIFO
#define MPU_FIFO_COUNT_H	0x72
#define MPU_FIFO_COUNT_L	0x73

//Lectura/Escritura del FIFO
#define MPU_FIFO_R_W		0x74

//Definición de la dirección del MPU usado
#define MPU_WHO_AM_I		0x75

/*===================================================================================
 *Definición de los bits de registros:
 *
 *==================================================================================
 */

//Bits de Configuración
#define EXT_SYNC_SET		3
#define DLPF_CFG			0

//Bits de Self-Test
#define XA_TEST			5
#define XG_TEST			0
#define YA_TEST			5
#define YG_TEST			0	
#define	ZA_TEST			5
#define ZY_TEST			0

//bits de PWR Management
#define DEVICE_RESET	7
#define SLEEP			6
#define CYCLE			5
#define TEMP_DIS		3
#define CLKSEL			0

//Bits de Gyro_config
#define XG_ST			7
#define YG_ST			6
#define ZG_ST			5
#define FS_SEL			3

//Bits de Accel_Config
#define XA_ST			7
#define YA_ST			6
#define ZA_ST			5
#define AFS_SEL		3


#endif /* MPU6050_REGISTERS_H_ */