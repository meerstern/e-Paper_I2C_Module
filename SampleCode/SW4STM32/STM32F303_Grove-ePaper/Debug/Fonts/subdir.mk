################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Fonts/font12.c \
../Fonts/font16.c \
../Fonts/font20.c \
../Fonts/font24.c \
../Fonts/font8.c 

OBJS += \
./Fonts/font12.o \
./Fonts/font16.o \
./Fonts/font20.o \
./Fonts/font24.o \
./Fonts/font8.o 

C_DEPS += \
./Fonts/font12.d \
./Fonts/font16.d \
./Fonts/font20.d \
./Fonts/font24.d \
./Fonts/font8.d 


# Each subdirectory must supply rules for building sources it contributes
Fonts/%.o: ../Fonts/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F303x8 -I"D:/30_ARM_WS/workspace/STM32F303_Grove-ePaper/Inc" -I"D:/30_ARM_WS/workspace/STM32F303_Grove-ePaper/Fonts" -I"D:/30_ARM_WS/workspace/STM32F303_Grove-ePaper/Drivers/STM32F3xx_HAL_Driver/Inc" -I"D:/30_ARM_WS/workspace/STM32F303_Grove-ePaper/Drivers/STM32F3xx_HAL_Driver/Inc/Legacy" -I"D:/30_ARM_WS/workspace/STM32F303_Grove-ePaper/Drivers/CMSIS/Device/ST/STM32F3xx/Include" -I"D:/30_ARM_WS/workspace/STM32F303_Grove-ePaper/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


