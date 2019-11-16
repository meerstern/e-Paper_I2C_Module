/*
Description:
This is a example code for Sandbox Electronics' I2C/SPI to UART bridge module.
You can get one of those products on
http://sandboxelectronics.com

Version:
V0.1

Release Date:
2014-02-16

Author:
Tiequan Shao          info@sandboxelectronics.com

Lisence:
CC BY-NC-SA 3.0

Please keep the above information when you use this code in your project.
*/




#include "i2c-spi_bridge.h"
#include "stdbool.h"

uint8_t gpio_reg_enable;
uint8_t gpio_reg_direction;
uint8_t gpio_reg_read;
uint8_t gpio_reg_write;
uint8_t gpio_reg_config;
uint8_t gpio_ss_pin;


/*
 	EPD_CS,		//Output
	EPD_BUSY,	//Input
	EPD_DC,		//Output
	EPD_RST		//Output
 * */
void SC18IS602_InitDevice(){

	gpio_reg_config=0;
	gpio_reg_write=0;
	gpio_reg_read=0x0F;
	gpio_reg_enable=0x0E;
	gpio_reg_direction=0x59;

	SC18IS602_WriteReg(SC18IS602_CONFIG_REG,		&gpio_reg_config,		1);
	//SC18IS602_WriteReg(SC18IS602_IOWRITE_REG,		&gpio_reg_write,		1);
	//SC18IS602_WriteReg(SC18IS602_IOREAD_REG,		&gpio_reg_read,			1);
	SC18IS602_WriteReg(SC18IS602_IOENABLE_REG,		&gpio_reg_enable,		1);
	SC18IS602_WriteReg(SC18IS602_IODIRECTION_REG,	&gpio_reg_direction,	1);

}


void SC18IS602_PinMode(uint8_t pin, uint8_t io){

	gpio_reg_direction &= (((uint8_t)~(0x03))<<(pin<1));
	if (io == 1) {
		gpio_reg_direction |= (0x02<<(pin<<1)); //10 for input
	} else {
		gpio_reg_direction |= (0x01<<(pin<<1)); //01 for output
	}
	SC18IS602_WriteReg(SC18IS602_IODIRECTION_REG, &gpio_reg_direction,1);
}

void SC18IS602_DigitalWrite(uint8_t pin, uint8_t val){

	if ( val==0 ) {
		gpio_reg_write &= (((uint8_t)~(0x01))<<pin);
	} else {
		gpio_reg_write |= (0x01<<pin);
	}

	SC18IS602_WriteReg(SC18IS602_IOWRITE_REG, &gpio_reg_write,1);
}


uint8_t SC18IS602_digitalRead(uint8_t pin){

	SC18IS602_WriteReg(SC18IS602_IOREAD_REG, &gpio_reg_read,1);
	SC18IS602_ReadBytes(1,&gpio_reg_read,1);
	if (gpio_reg_read & (0x01<<pin) ) {
		return 1;
	}

	return 0;
}

void SC18IS602_SSEnable(uint8_t pin){

	gpio_reg_enable &= (uint8_t)(~(0x01<<pin ));
	SC18IS602_WriteReg(SC18IS602_IOENABLE_REG, &gpio_reg_enable,1);
}

void SC18IS602_GPIO_Enable(uint8_t pin){

	gpio_reg_enable |= ( 0x01<<pin );
	SC18IS602_WriteReg(SC18IS602_IOENABLE_REG, &gpio_reg_enable,1);
}


void SC18IS602_Transfer(uint8_t *data, uint8_t len ){

	SC18IS602_WriteBytes(0x01<<gpio_ss_pin,data,len);
	SC18IS602_ReadBytes(1, data,len);

}



void SC18IS602_WriteReg(uint8_t reg, uint8_t *data, uint8_t len ){

	int8_t res;
	res = HAL_I2C_Mem_Write( 	&hi2c1,
								SC18IS602_ADDRESS,
								reg,
								I2C_MEMADD_SIZE_8BIT,
								data,
								len,
								SC18IS602_I2C_TIMEOUT );

}

void SC18IS602_WriteBytes(uint8_t adr, uint8_t *data, uint8_t len ){

	int8_t res;
	res = HAL_I2C_Mem_Write( 	&hi2c1,
								SC18IS602_ADDRESS,
								adr,
								I2C_MEMADD_SIZE_8BIT,
								data,
								len,
								SC18IS602_I2C_TIMEOUT );

}


void SC18IS602_ReadReg(uint8_t reg, uint8_t *data, uint8_t len ){

	int8_t res;
	res = HAL_I2C_Mem_Read( 	&hi2c1,
								SC18IS602_ADDRESS,
								reg,
								I2C_MEMADD_SIZE_8BIT,
								data,
								len,
								SC18IS602_I2C_TIMEOUT );

}

void SC18IS602_ReadBytes(uint8_t adr, uint8_t *data, uint8_t len ){

	int8_t res;
	res = HAL_I2C_Mem_Read( 	&hi2c1,
								SC18IS602_ADDRESS,
								adr,
								I2C_MEMADD_SIZE_8BIT,
								data,
								len,
								SC18IS602_I2C_TIMEOUT );

}

