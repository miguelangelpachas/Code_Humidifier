################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/driver/MT_display_7_segmentos.c \
../Core/driver/MT_ntc.c \
../Core/driver/MT_rtd.c \
../Core/driver/mt_debounce.c 

OBJS += \
./Core/driver/MT_display_7_segmentos.o \
./Core/driver/MT_ntc.o \
./Core/driver/MT_rtd.o \
./Core/driver/mt_debounce.o 

C_DEPS += \
./Core/driver/MT_display_7_segmentos.d \
./Core/driver/MT_ntc.d \
./Core/driver/MT_rtd.d \
./Core/driver/mt_debounce.d 


# Each subdirectory must supply rules for building sources it contributes
Core/driver/MT_display_7_segmentos.o: ../Core/driver/MT_display_7_segmentos.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Projects/vent_humidifier_ws/vent_humidifier_ws/Code_Humidifier/vent_humidifier_ws/vent_humidifier/Core/app" -I"C:/Projects/vent_humidifier_ws/vent_humidifier_ws/Code_Humidifier/vent_humidifier_ws/vent_humidifier/Core/driver" -I"C:/Projects/vent_humidifier_ws/vent_humidifier_ws/Code_Humidifier/vent_humidifier_ws/vent_humidifier/Core/lib" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/driver/MT_display_7_segmentos.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/driver/MT_ntc.o: ../Core/driver/MT_ntc.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Projects/vent_humidifier_ws/vent_humidifier_ws/Code_Humidifier/vent_humidifier_ws/vent_humidifier/Core/app" -I"C:/Projects/vent_humidifier_ws/vent_humidifier_ws/Code_Humidifier/vent_humidifier_ws/vent_humidifier/Core/driver" -I"C:/Projects/vent_humidifier_ws/vent_humidifier_ws/Code_Humidifier/vent_humidifier_ws/vent_humidifier/Core/lib" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/driver/MT_ntc.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/driver/MT_rtd.o: ../Core/driver/MT_rtd.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Projects/vent_humidifier_ws/vent_humidifier_ws/Code_Humidifier/vent_humidifier_ws/vent_humidifier/Core/app" -I"C:/Projects/vent_humidifier_ws/vent_humidifier_ws/Code_Humidifier/vent_humidifier_ws/vent_humidifier/Core/driver" -I"C:/Projects/vent_humidifier_ws/vent_humidifier_ws/Code_Humidifier/vent_humidifier_ws/vent_humidifier/Core/lib" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/driver/MT_rtd.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/driver/mt_debounce.o: ../Core/driver/mt_debounce.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Projects/vent_humidifier_ws/vent_humidifier_ws/Code_Humidifier/vent_humidifier_ws/vent_humidifier/Core/app" -I"C:/Projects/vent_humidifier_ws/vent_humidifier_ws/Code_Humidifier/vent_humidifier_ws/vent_humidifier/Core/driver" -I"C:/Projects/vent_humidifier_ws/vent_humidifier_ws/Code_Humidifier/vent_humidifier_ws/vent_humidifier/Core/lib" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/driver/mt_debounce.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

