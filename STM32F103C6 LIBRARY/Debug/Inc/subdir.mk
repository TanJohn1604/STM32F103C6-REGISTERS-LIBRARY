################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Inc/adc.c \
../Inc/gpio.c \
../Inc/i2c.c \
../Inc/interrupt_PA0.c \
../Inc/lcd_1602_mode8_4.c \
../Inc/spi.c \
../Inc/string_func.c \
../Inc/system_clock.c \
../Inc/systick_delay.c \
../Inc/systick_interrupt.c \
../Inc/usart.c \
../Inc/usart_rx_interrupt.c 

OBJS += \
./Inc/adc.o \
./Inc/gpio.o \
./Inc/i2c.o \
./Inc/interrupt_PA0.o \
./Inc/lcd_1602_mode8_4.o \
./Inc/spi.o \
./Inc/string_func.o \
./Inc/system_clock.o \
./Inc/systick_delay.o \
./Inc/systick_interrupt.o \
./Inc/usart.o \
./Inc/usart_rx_interrupt.o 

C_DEPS += \
./Inc/adc.d \
./Inc/gpio.d \
./Inc/i2c.d \
./Inc/interrupt_PA0.d \
./Inc/lcd_1602_mode8_4.d \
./Inc/spi.d \
./Inc/string_func.d \
./Inc/system_clock.d \
./Inc/systick_delay.d \
./Inc/systick_interrupt.d \
./Inc/usart.d \
./Inc/usart_rx_interrupt.d 


# Each subdirectory must supply rules for building sources it contributes
Inc/%.o: ../Inc/%.c Inc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"D:/Project STMf103c6/STM32F103C6 LIBRARY/Drivers/CMSIS/Core/Include" -I"D:/Project STMf103c6/STM32F103C6 LIBRARY/Drivers/CMSIS/Device/ST/STM32F1xx" -I"D:/Project STMf103c6/STM32F103C6 LIBRARY/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Inc

clean-Inc:
	-$(RM) ./Inc/adc.d ./Inc/adc.o ./Inc/gpio.d ./Inc/gpio.o ./Inc/i2c.d ./Inc/i2c.o ./Inc/interrupt_PA0.d ./Inc/interrupt_PA0.o ./Inc/lcd_1602_mode8_4.d ./Inc/lcd_1602_mode8_4.o ./Inc/spi.d ./Inc/spi.o ./Inc/string_func.d ./Inc/string_func.o ./Inc/system_clock.d ./Inc/system_clock.o ./Inc/systick_delay.d ./Inc/systick_delay.o ./Inc/systick_interrupt.d ./Inc/systick_interrupt.o ./Inc/usart.d ./Inc/usart.o ./Inc/usart_rx_interrupt.d ./Inc/usart_rx_interrupt.o

.PHONY: clean-Inc

