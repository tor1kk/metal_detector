################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Program/UI/ui.c \
../Program/UI/ui_events.c \
../Program/UI/ui_helpers.c 

OBJS += \
./Program/UI/ui.o \
./Program/UI/ui_events.o \
./Program/UI/ui_helpers.o 

C_DEPS += \
./Program/UI/ui.d \
./Program/UI/ui_events.d \
./Program/UI/ui_helpers.d 


# Each subdirectory must supply rules for building sources it contributes
Program/UI/%.o Program/UI/%.su Program/UI/%.cyclo: ../Program/UI/%.c Program/UI/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H723xx -DARM_MATH_CM7 -c -I"C:/Users/Viktor/Desktop/labaratorni/Projects/Metal_Detector/software/Program/SignalsProcessing/Inc" -I"C:/Users/Viktor/Desktop/labaratorni/Projects/Metal_Detector/software/Drivers/CMSIS-DSP/Inc" -I"C:/Users/Viktor/Desktop/labaratorni/Projects/Metal_Detector/software/Program/Tasks/Inc" -I"C:/Users/Viktor/Desktop/labaratorni/Projects/Metal_Detector/software/Program/UI" -I"C:/Users/Viktor/Desktop/labaratorni/Projects/Metal_Detector/software/Program/Display/Inc" -I../Core/Inc -I"C:/Users/Viktor/Desktop/labaratorni/Projects/Metal_Detector/software/lvgl/src" -I"C:/Users/Viktor/Desktop/labaratorni/Projects/Metal_Detector/software/lvgl" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/ST/ARM/DSP/Inc -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Program-2f-UI

clean-Program-2f-UI:
	-$(RM) ./Program/UI/ui.cyclo ./Program/UI/ui.d ./Program/UI/ui.o ./Program/UI/ui.su ./Program/UI/ui_events.cyclo ./Program/UI/ui_events.d ./Program/UI/ui_events.o ./Program/UI/ui_events.su ./Program/UI/ui_helpers.cyclo ./Program/UI/ui_helpers.d ./Program/UI/ui_helpers.o ./Program/UI/ui_helpers.su

.PHONY: clean-Program-2f-UI

