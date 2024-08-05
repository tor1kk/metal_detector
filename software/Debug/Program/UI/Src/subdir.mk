################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Program/UI/Src/ui.c \
../Program/UI/Src/ui_callbacks.c 

OBJS += \
./Program/UI/Src/ui.o \
./Program/UI/Src/ui_callbacks.o 

C_DEPS += \
./Program/UI/Src/ui.d \
./Program/UI/Src/ui_callbacks.d 


# Each subdirectory must supply rules for building sources it contributes
Program/UI/Src/%.o Program/UI/Src/%.su Program/UI/Src/%.cyclo: ../Program/UI/Src/%.c Program/UI/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H723xx -DARM_MATH_CM7 -c -I"C:/Users/Viktor/Desktop/labaratorni/Projects/MetalDetector/software/Program/SignalsProcessing/Inc" -I"C:/Users/Viktor/Desktop/labaratorni/Projects/MetalDetector/software/Program/UI/Inc" -I"C:/Users/Viktor/Desktop/labaratorni/Projects/MetalDetector/software/Drivers/CMSIS-DSP/Inc" -I"C:/Users/Viktor/Desktop/labaratorni/Projects/MetalDetector/software/Program/Tasks/Inc" -I"C:/Users/Viktor/Desktop/labaratorni/Projects/MetalDetector/software/Program/UI" -I"C:/Users/Viktor/Desktop/labaratorni/Projects/MetalDetector/software/Program/Display/Inc" -I../Core/Inc -I"C:/Users/Viktor/Desktop/labaratorni/Projects/MetalDetector/software/lvgl/src" -I"C:/Users/Viktor/Desktop/labaratorni/Projects/MetalDetector/software/lvgl" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/ST/ARM/DSP/Inc -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Program-2f-UI-2f-Src

clean-Program-2f-UI-2f-Src:
	-$(RM) ./Program/UI/Src/ui.cyclo ./Program/UI/Src/ui.d ./Program/UI/Src/ui.o ./Program/UI/Src/ui.su ./Program/UI/Src/ui_callbacks.cyclo ./Program/UI/Src/ui_callbacks.d ./Program/UI/Src/ui_callbacks.o ./Program/UI/Src/ui_callbacks.su

.PHONY: clean-Program-2f-UI-2f-Src

