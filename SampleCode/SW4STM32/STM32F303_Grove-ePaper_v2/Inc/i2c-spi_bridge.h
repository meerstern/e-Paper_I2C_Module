/*
Description:
This is a example code for Sandbox Electronics' I2C to SPI bridge module.
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



#include "stm32f3xx_hal.h"
#include "i2c.h"


#define SC18IS602_ADDRESS SC18IS602_ADDRESS_000
#define SC18IS602_I2C_TIMEOUT		0xFFF

//Device Address

#define     SC18IS602_ADDRESS_000     (0X50)
#define     SC18IS602_ADDRESS_001     (0X52)
#define     SC18IS602_ADDRESS_010     (0X54)
#define     SC18IS602_ADDRESS_011     (0X56)
#define     SC18IS602_ADDRESS_100     (0X58)
#define     SC18IS602_ADDRESS_101     (0X5A)
#define     SC18IS602_ADDRESS_110     (0X5C)
#define     SC18IS602_ADDRESS_111     (0X5E)

//Clock Divider
#define     SC18IS602_CLOCK_1843K     (0X00)
#define     SC18IS602_CLOCK_461K      (0X01)
#define     SC18IS602_CLOCK_115K      (0X02)
#define     SC18IS602_CLOCK_58K       (0X03)

#define     SC18IS602_SPI_MODE0       (0x00)
#define     SC18IS602_SPI_MODE1       (0x01)
#define     SC18IS602_SPI_MODE2       (0x02)
#define     SC18IS602_SPI_MODE3       (0x03)

#define     SC18IS602_SS_0   		 (0X00)
#define     SC18IS602_SS_1  		 (0X01)
#define     SC18IS602_SS_2   		 (0X02)
#define     SC18IS602_SS_3   		 (0X03)


#define 	SC18IS602_CONFIG_REG		0xF0
#define 	SC18IS602_IOWRITE_REG		0xF4
#define 	SC18IS602_IOREAD_REG		0xF5
#define 	SC18IS602_IOENABLE_REG		0xF6
#define 	SC18IS602_IODIRECTION_REG	0xF7














void SC18IS602_InitDevice();
void SC18IS602_PinMode(uint8_t pin, uint8_t io);
void SC18IS602_DigitalWrite(uint8_t pin, uint8_t val);
uint8_t SC18IS602_digitalRead(uint8_t pin);
void SC18IS602_SSEnable(uint8_t pin);
void SC18IS602_GPIO_Enable(uint8_t pin);
void SC18IS602_Transfer(uint8_t *data, uint8_t len );
void SC18IS602_WriteReg(uint8_t reg, uint8_t *data, uint8_t len );
void SC18IS602_WriteBytes(uint8_t adr, uint8_t *data, uint8_t len );
void SC18IS602_ReadReg(uint8_t reg, uint8_t *data, uint8_t len );
void SC18IS602_ReadBytes(uint8_t adr, uint8_t *data, uint8_t len );



