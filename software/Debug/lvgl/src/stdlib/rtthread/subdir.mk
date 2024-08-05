################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/stdlib/rtthread/lv_mem_core_rtthread.c \
../lvgl/src/stdlib/rtthread/lv_sprintf_rtthread.c \
../lvgl/src/stdlib/rtthread/lv_string_rtthread.c 

OBJS += \
./lvgl/src/stdlib/rtthread/lv_mem_core_rtthread.o \
./lvgl/src/stdlib/rtthread/lv_sprintf_rtthread.o \
./lvgl/src/stdlib/rtthread/lv_string_rtthread.o 

C_DEPS += \
./lvgl/src/stdlib/rtthread/lv_mem_core_rtthread.d \
./lvgl/src/stdlib/rtthread/lv_sprintf_rtthread.d \
./lvgl/src/stdlib/rtthread/lv_string_rtthread.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/stdlib/rtthread/%.o lvgl/src/stdlib/rtthread/%.su lvgl/src/stdlib/rtthread/%.cyclo: ../lvgl/src/stdlib/rtthread/%.c lvgl/src/stdlib/rtthread/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H723xx -DARM_MATH_CM7 -c -I"C:/Users/Viktor/Desktop/labaratorni/Projects/MetalDetector/software/Program/SignalsProcessing/Inc" -I"C:/Users/Viktor/Desktop/labaratorni/Projects/MetalDetector/software/Program/UI/Inc" -I"C:/Users/Viktor/Desktop/labaratorni/Projects/MetalDetector/software/Drivers/CMSIS-DSP/Inc" -I"C:/Users/Viktor/Desktop/labaratorni/Projects/MetalDetector/software/Program/Tasks/Inc" -I"C:/Users/Viktor/Desktop/labaratorni/Projects/MetalDetector/software/Program/UI" -I"C:/Users/Viktor/Desktop/labaratorni/Projects/MetalDetector/software/Program/Display/Inc" -I../Core/Inc -I"C:/Users/Viktor/Desktop/labaratorni/Projects/MetalDetector/software/lvgl/src" -I"C:/Users/Viktor/Desktop/labaratorni/Projects/MetalDetector/software/lvgl" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/ST/ARM/DSP/Inc -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-src-2f-stdlib-2f-rtthread

clean-lvgl-2f-src-2f-stdlib-2f-rtthread:
	-$(RM) ./lvgl/src/stdlib/rtthread/lv_mem_core_rtthread.cyclo ./lvgl/src/stdlib/rtthread/lv_mem_core_rtthread.d ./lvgl/src/stdlib/rtthread/lv_mem_core_rtthread.o ./lvgl/src/stdlib/rtthread/lv_mem_core_rtthread.su ./lvgl/src/stdlib/rtthread/lv_sprintf_rtthread.cyclo ./lvgl/src/stdlib/rtthread/lv_sprintf_rtthread.d ./lvgl/src/stdlib/rtthread/lv_sprintf_rtthread.o ./lvgl/src/stdlib/rtthread/lv_sprintf_rtthread.su ./lvgl/src/stdlib/rtthread/lv_string_rtthread.cyclo ./lvgl/src/stdlib/rtthread/lv_string_rtthread.d ./lvgl/src/stdlib/rtthread/lv_string_rtthread.o ./lvgl/src/stdlib/rtthread/lv_string_rtthread.su

.PHONY: clean-lvgl-2f-src-2f-stdlib-2f-rtthread

