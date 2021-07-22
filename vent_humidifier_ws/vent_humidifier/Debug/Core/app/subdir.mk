################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/app/alarm_manager.c \
../Core/app/display_interface.c \
../Core/app/heater_manager.c \
../Core/app/heater_plate_feedback.c \
../Core/app/temperature_controller.c \
../Core/app/temperature_measurement.c \
../Core/app/vent_humidifier.c 

OBJS += \
./Core/app/alarm_manager.o \
./Core/app/display_interface.o \
./Core/app/heater_manager.o \
./Core/app/heater_plate_feedback.o \
./Core/app/temperature_controller.o \
./Core/app/temperature_measurement.o \
./Core/app/vent_humidifier.o 

C_DEPS += \
./Core/app/alarm_manager.d \
./Core/app/display_interface.d \
./Core/app/heater_manager.d \
./Core/app/heater_plate_feedback.d \
./Core/app/temperature_controller.d \
./Core/app/temperature_measurement.d \
./Core/app/vent_humidifier.d 


# Each subdirectory must supply rules for building sources it contributes
Core/app/alarm_manager.o: ../Core/app/alarm_manager.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Projects/vent_humidifier_ws/vent_humidifier_ws/Code_Humidifier/vent_humidifier_ws/vent_humidifier/Core/app" -I"C:/Projects/vent_humidifier_ws/vent_humidifier_ws/Code_Humidifier/vent_humidifier_ws/vent_humidifier/Core/driver" -I"C:/Projects/vent_humidifier_ws/vent_humidifier_ws/Code_Humidifier/vent_humidifier_ws/vent_humidifier/Core/lib" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/app/alarm_manager.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/app/display_interface.o: ../Core/app/display_interface.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Projects/vent_humidifier_ws/vent_humidifier_ws/Code_Humidifier/vent_humidifier_ws/vent_humidifier/Core/app" -I"C:/Projects/vent_humidifier_ws/vent_humidifier_ws/Code_Humidifier/vent_humidifier_ws/vent_humidifier/Core/driver" -I"C:/Projects/vent_humidifier_ws/vent_humidifier_ws/Code_Humidifier/vent_humidifier_ws/vent_humidifier/Core/lib" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/app/display_interface.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/app/heater_manager.o: ../Core/app/heater_manager.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Projects/vent_humidifier_ws/vent_humidifier_ws/Code_Humidifier/vent_humidifier_ws/vent_humidifier/Core/app" -I"C:/Projects/vent_humidifier_ws/vent_humidifier_ws/Code_Humidifier/vent_humidifier_ws/vent_humidifier/Core/driver" -I"C:/Projects/vent_humidifier_ws/vent_humidifier_ws/Code_Humidifier/vent_humidifier_ws/vent_humidifier/Core/lib" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/app/heater_manager.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/app/heater_plate_feedback.o: ../Core/app/heater_plate_feedback.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Projects/vent_humidifier_ws/vent_humidifier_ws/Code_Humidifier/vent_humidifier_ws/vent_humidifier/Core/app" -I"C:/Projects/vent_humidifier_ws/vent_humidifier_ws/Code_Humidifier/vent_humidifier_ws/vent_humidifier/Core/driver" -I"C:/Projects/vent_humidifier_ws/vent_humidifier_ws/Code_Humidifier/vent_humidifier_ws/vent_humidifier/Core/lib" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/app/heater_plate_feedback.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/app/temperature_controller.o: ../Core/app/temperature_controller.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Projects/vent_humidifier_ws/vent_humidifier_ws/Code_Humidifier/vent_humidifier_ws/vent_humidifier/Core/app" -I"C:/Projects/vent_humidifier_ws/vent_humidifier_ws/Code_Humidifier/vent_humidifier_ws/vent_humidifier/Core/driver" -I"C:/Projects/vent_humidifier_ws/vent_humidifier_ws/Code_Humidifier/vent_humidifier_ws/vent_humidifier/Core/lib" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/app/temperature_controller.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/app/temperature_measurement.o: ../Core/app/temperature_measurement.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Projects/vent_humidifier_ws/vent_humidifier_ws/Code_Humidifier/vent_humidifier_ws/vent_humidifier/Core/app" -I"C:/Projects/vent_humidifier_ws/vent_humidifier_ws/Code_Humidifier/vent_humidifier_ws/vent_humidifier/Core/driver" -I"C:/Projects/vent_humidifier_ws/vent_humidifier_ws/Code_Humidifier/vent_humidifier_ws/vent_humidifier/Core/lib" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/app/temperature_measurement.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/app/vent_humidifier.o: ../Core/app/vent_humidifier.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Projects/vent_humidifier_ws/vent_humidifier_ws/Code_Humidifier/vent_humidifier_ws/vent_humidifier/Core/app" -I"C:/Projects/vent_humidifier_ws/vent_humidifier_ws/Code_Humidifier/vent_humidifier_ws/vent_humidifier/Core/driver" -I"C:/Projects/vent_humidifier_ws/vent_humidifier_ws/Code_Humidifier/vent_humidifier_ws/vent_humidifier/Core/lib" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/app/vent_humidifier.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

