################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/draw/sdl/lv_draw_sdl.c 

OBJS += \
./lvgl/src/draw/sdl/lv_draw_sdl.o 

C_DEPS += \
./lvgl/src/draw/sdl/lv_draw_sdl.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/draw/sdl/%.o lvgl/src/draw/sdl/%.su lvgl/src/draw/sdl/%.cyclo: ../lvgl/src/draw/sdl/%.c lvgl/src/draw/sdl/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H723xx -DARM_MATH_CM7 -c -I"C:/Users/Viktor/Desktop/labaratorni/Projects/MetalDetector/software/Program/SignalsProcessing/Inc" -I"C:/Users/Viktor/Desktop/labaratorni/Projects/MetalDetector/software/Program/UI/Inc" -I"C:/Users/Viktor/Desktop/labaratorni/Projects/MetalDetector/software/Drivers/CMSIS-DSP/Inc" -I"C:/Users/Viktor/Desktop/labaratorni/Projects/MetalDetector/software/Program/Tasks/Inc" -I"C:/Users/Viktor/Desktop/labaratorni/Projects/MetalDetector/software/Program/UI" -I"C:/Users/Viktor/Desktop/labaratorni/Projects/MetalDetector/software/Program/Display/Inc" -I../Core/Inc -I"C:/Users/Viktor/Desktop/labaratorni/Projects/MetalDetector/software/lvgl/src" -I"C:/Users/Viktor/Desktop/labaratorni/Projects/MetalDetector/software/lvgl" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/ST/ARM/DSP/Inc -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-src-2f-draw-2f-sdl

clean-lvgl-2f-src-2f-draw-2f-sdl:
	-$(RM) ./lvgl/src/draw/sdl/lv_draw_sdl.cyclo ./lvgl/src/draw/sdl/lv_draw_sdl.d ./lvgl/src/draw/sdl/lv_draw_sdl.o ./lvgl/src/draw/sdl/lv_draw_sdl.su

.PHONY: clean-lvgl-2f-src-2f-draw-2f-sdl

