################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Inc/gpio.c \
../Inc/interrupt_PA0.c \
../Inc/system_clock.c 

OBJS += \
./Inc/gpio.o \
./Inc/interrupt_PA0.o \
./Inc/system_clock.o 

C_DEPS += \
./Inc/gpio.d \
./Inc/interrupt_PA0.d \
./Inc/system_clock.d 


# Each subdirectory must supply rules for building sources it contributes
Inc/%.o: ../Inc/%.c Inc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"D:/Project STMf103c6/STM32F103C6 GPIO INPUT OUTPUT LIBRARY/Drivers/CMSIS/Core/Include" -I"D:/Project STMf103c6/STM32F103C6 GPIO INPUT OUTPUT LIBRARY/Drivers/CMSIS/Device/ST/STM32F1xx" -I"D:/Project STMf103c6/STM32F103C6 GPIO INPUT OUTPUT LIBRARY/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Inc

clean-Inc:
	-$(RM) ./Inc/gpio.d ./Inc/gpio.o ./Inc/interrupt_PA0.d ./Inc/interrupt_PA0.o ./Inc/system_clock.d ./Inc/system_clock.o

.PHONY: clean-Inc

