################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/Components/cs43l22/cs43l22.c 

OBJS += \
./Drivers/BSP/Components/cs43l22/cs43l22.o 

C_DEPS += \
./Drivers/BSP/Components/cs43l22/cs43l22.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/Components/cs43l22/%.o Drivers/BSP/Components/cs43l22/%.su Drivers/BSP/Components/cs43l22/%.cyclo: ../Drivers/BSP/Components/cs43l22/%.c Drivers/BSP/Components/cs43l22/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/21522/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/BSP/STM32F429I-Discovery" -I"C:/Users/21522/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/STM32F4xx_HAL_Driver/Src" -I"C:/Users/21522/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/STM32F4xx_HAL_Driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-Components-2f-cs43l22

clean-Drivers-2f-BSP-2f-Components-2f-cs43l22:
	-$(RM) ./Drivers/BSP/Components/cs43l22/cs43l22.cyclo ./Drivers/BSP/Components/cs43l22/cs43l22.d ./Drivers/BSP/Components/cs43l22/cs43l22.o ./Drivers/BSP/Components/cs43l22/cs43l22.su

.PHONY: clean-Drivers-2f-BSP-2f-Components-2f-cs43l22
