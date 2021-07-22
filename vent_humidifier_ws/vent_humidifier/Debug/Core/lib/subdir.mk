################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/lib/MT_filters.c \
../Core/lib/fuzzy_controller_basic.c 

OBJS += \
./Core/lib/MT_filters.o \
./Core/lib/fuzzy_controller_basic.o 

C_DEPS += \
./Core/lib/MT_filters.d \
./Core/lib/fuzzy_controller_basic.d 


# Each subdirectory must supply rules for building sources it contributes
Core/lib/MT_filters.o: ../Core/lib/MT_filters.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Projects/vent_humidifier_ws/vent_humidifier_ws/Code_Humidifier/vent_humidifier_ws/vent_humidifier/Core/app" -I"C:/Projects/vent_humidifier_ws/vent_humidifier_ws/Code_Humidifier/vent_humidifier_ws/vent_humidifier/Core/driver" -I"C:/Projects/vent_humidifier_ws/vent_humidifier_ws/Code_Humidifier/vent_humidifier_ws/vent_humidifier/Core/lib" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/MT_filters.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/lib/fuzzy_controller_basic.o: ../Core/lib/fuzzy_controller_basic.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Projects/vent_humidifier_ws/vent_humidifier_ws/Code_Humidifier/vent_humidifier_ws/vent_humidifier/Core/app" -I"C:/Projects/vent_humidifier_ws/vent_humidifier_ws/Code_Humidifier/vent_humidifier_ws/vent_humidifier/Core/driver" -I"C:/Projects/vent_humidifier_ws/vent_humidifier_ws/Code_Humidifier/vent_humidifier_ws/vent_humidifier/Core/lib" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/lib/fuzzy_controller_basic.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

