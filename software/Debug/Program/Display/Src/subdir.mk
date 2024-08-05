################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Program/Display/Src/display.c \
../Program/Display/Src/ili9341.c \
../Program/Display/Src/xpt2046.c 

OBJS += \
./Program/Display/Src/display.o \
./Program/Display/Src/ili9341.o \
./Program/Display/Src/xpt2046.o 

C_DEPS += \
./Program/Display/Src/display.d \
./Program/Display/Src/ili9341.d \
./Program/Display/Src/xpt2046.d 


# Each subdirectory must supply rules for building sources it contributes
Program/Display/Src/%.o Program/Display/Src/%.su Program/Display/Src/%.cyclo: ../Program/Display/Src/%.c Program/Display/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H723xx -DARM_MATH_CM7 -c -I"C:/Users/Viktor/Desktop/labaratorni/Projects/MetalDetector/software/Program/SignalsProcessing/Inc" -I"C:/Users/Viktor/Desktop/labaratorni/Projects/MetalDetector/software/Program/UI/Inc" -I"C:/Users/Viktor/Desktop/labaratorni/Projects/MetalDetector/software/Drivers/CMSIS-DSP/Inc" -I"C:/Users/Viktor/Desktop/labaratorni/Projects/MetalDetector/software/Program/Tasks/Inc" -I"C:/Users/Viktor/Desktop/labaratorni/Projects/MetalDetector/software/Program/UI" -I"C:/Users/Viktor/Desktop/labaratorni/Projects/MetalDetector/software/Program/Display/Inc" -I../Core/Inc -I"C:/Users/Viktor/Desktop/labaratorni/Projects/MetalDetector/software/lvgl/src" -I"C:/Users/Viktor/Desktop/labaratorni/Projects/MetalDetector/software/lvgl" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/ST/ARM/DSP/Inc -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Program-2f-Display-2f-Src

clean-Program-2f-Display-2f-Src:
	-$(RM) ./Program/Display/Src/display.cyclo ./Program/Display/Src/display.d ./Program/Display/Src/display.o ./Program/Display/Src/display.su ./Program/Display/Src/ili9341.cyclo ./Program/Display/Src/ili9341.d ./Program/Display/Src/ili9341.o ./Program/Display/Src/ili9341.su ./Program/Display/Src/xpt2046.cyclo ./Program/Display/Src/xpt2046.d ./Program/Display/Src/xpt2046.o ./Program/Display/Src/xpt2046.su

.PHONY: clean-Program-2f-Display-2f-Src

