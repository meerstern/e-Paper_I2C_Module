################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/epd1in54.c \
../Src/epdif.c \
../Src/epdpaint.c \
../Src/gpio.c \
../Src/i2c-spi_bridge.c \
../Src/i2c.c \
../Src/imagedata.c \
../Src/main.c \
../Src/stm32f3xx_hal_msp.c \
../Src/stm32f3xx_it.c \
../Src/system_stm32f3xx.c \
../Src/usart.c 

OBJS += \
./Src/epd1in54.o \
./Src/epdif.o \
./Src/epdpaint.o \
./Src/gpio.o \
./Src/i2c-spi_bridge.o \
./Src/i2c.o \
./Src/imagedata.o \
./Src/main.o \
./Src/stm32f3xx_hal_msp.o \
./Src/stm32f3xx_it.o \
./Src/system_stm32f3xx.o \
./Src/usart.o 

C_DEPS += \
./Src/epd1in54.d \
./Src/epdif.d \
./Src/epdpaint.d \
./Src/gpio.d \
./Src/i2c-spi_bridge.d \
./Src/i2c.d \
./Src/imagedata.d \
./Src/main.d \
./Src/stm32f3xx_hal_msp.d \
./Src/stm32f3xx_it.d \
./Src/system_stm32f3xx.d \
./Src/usart.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F303x8 -I"D:/30_ARM_WS/workspace/STM32F303_Grove-ePaper/Inc" -I"D:/30_ARM_WS/workspace/STM32F303_Grove-ePaper/Fonts" -I"D:/30_ARM_WS/workspace/STM32F303_Grove-ePaper/Drivers/STM32F3xx_HAL_Driver/Inc" -I"D:/30_ARM_WS/workspace/STM32F303_Grove-ePaper/Drivers/STM32F3xx_HAL_Driver/Inc/Legacy" -I"D:/30_ARM_WS/workspace/STM32F303_Grove-ePaper/Drivers/CMSIS/Device/ST/STM32F3xx/Include" -I"D:/30_ARM_WS/workspace/STM32F303_Grove-ePaper/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


