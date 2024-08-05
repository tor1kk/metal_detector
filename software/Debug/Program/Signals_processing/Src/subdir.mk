################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Program/Signals_processing/Src/signal.c 

OBJS += \
./Program/Signals_processing/Src/signal.o 

C_DEPS += \
./Program/Signals_processing/Src/signal.d 


# Each subdirectory must supply rules for building sources it contributes
Program/Signals_processing/Src/%.o Program/Signals_processing/Src/%.su Program/Signals_processing/Src/%.cyclo: ../Program/Signals_processing/Src/%.c Program/Signals_processing/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H723xx -DARM_MATH_CM7 -c -I"C:/Users/Viktor/Desktop/labaratorni/Projects/Metal_Detector/software/Drivers/CMSIS-DSP/Inc" -I"C:/Users/Viktor/Desktop/labaratorni/Projects/Metal_Detector/software/Program/Display/Inc" -I"C:/Users/Viktor/Desktop/labaratorni/Projects/Metal_Detector/software/Program/Signals_processing/Inc" -I../Core/Inc -I"C:/Users/Viktor/Desktop/labaratorni/Projects/Metal_Detector/software/lvgl/src" -I"C:/Users/Viktor/Desktop/labaratorni/Projects/Metal_Detector/software/lvgl" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/ST/ARM/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Program-2f-Signals_processing-2f-Src

clean-Program-2f-Signals_processing-2f-Src:
	-$(RM) ./Program/Signals_processing/Src/signal.cyclo ./Program/Signals_processing/Src/signal.d ./Program/Signals_processing/Src/signal.o ./Program/Signals_processing/Src/signal.su

.PHONY: clean-Program-2f-Signals_processing-2f-Src

