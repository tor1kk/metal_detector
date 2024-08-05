################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/demos/scroll/lv_demo_scroll.c 

OBJS += \
./lvgl/demos/scroll/lv_demo_scroll.o 

C_DEPS += \
./lvgl/demos/scroll/lv_demo_scroll.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/demos/scroll/%.o lvgl/demos/scroll/%.su lvgl/demos/scroll/%.cyclo: ../lvgl/demos/scroll/%.c lvgl/demos/scroll/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H723xx -c -I../Core/Inc -I"C:/Users/Viktor/Desktop/labaratorni/Projects/Metal_Detector/software/lvgl/src" -I"C:/Users/Viktor/Desktop/labaratorni/Projects/Metal_Detector/software/lvgl" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-demos-2f-scroll

clean-lvgl-2f-demos-2f-scroll:
	-$(RM) ./lvgl/demos/scroll/lv_demo_scroll.cyclo ./lvgl/demos/scroll/lv_demo_scroll.d ./lvgl/demos/scroll/lv_demo_scroll.o ./lvgl/demos/scroll/lv_demo_scroll.su

.PHONY: clean-lvgl-2f-demos-2f-scroll

