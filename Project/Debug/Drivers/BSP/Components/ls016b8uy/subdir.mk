################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/Components/ls016b8uy/ls016b8uy.c 

OBJS += \
./Drivers/BSP/Components/ls016b8uy/ls016b8uy.o 

C_DEPS += \
./Drivers/BSP/Components/ls016b8uy/ls016b8uy.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/Components/ls016b8uy/%.o Drivers/BSP/Components/ls016b8uy/%.su Drivers/BSP/Components/ls016b8uy/%.cyclo: ../Drivers/BSP/Components/ls016b8uy/%.c Drivers/BSP/Components/ls016b8uy/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../USB_DEVICE/App -I../USB_DEVICE/Target -I"C:/Users/21522/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/BSP/STM32F429I-Discovery" -IC:/Users/21522/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -IC:/Users/21522/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Middlewares/ST/STM32_USB_Device_Library/Core/Inc -IC:/Users/21522/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -IC:/Users/21522/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -IC:/Users/21522/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Middlewares/Third_Party/FreeRTOS/Source/include -IC:/Users/21522/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/21522/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/21522/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/21522/21522/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-Components-2f-ls016b8uy

clean-Drivers-2f-BSP-2f-Components-2f-ls016b8uy:
	-$(RM) ./Drivers/BSP/Components/ls016b8uy/ls016b8uy.cyclo ./Drivers/BSP/Components/ls016b8uy/ls016b8uy.d ./Drivers/BSP/Components/ls016b8uy/ls016b8uy.o ./Drivers/BSP/Components/ls016b8uy/ls016b8uy.su

.PHONY: clean-Drivers-2f-BSP-2f-Components-2f-ls016b8uy

