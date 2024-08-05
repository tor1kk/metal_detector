################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/demos/multilang/lv_demo_multilang.c 

OBJS += \
./lvgl/demos/multilang/lv_demo_multilang.o 

C_DEPS += \
./lvgl/demos/multilang/lv_demo_multilang.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/demos/multilang/%.o lvgl/demos/multilang/%.su lvgl/demos/multilang/%.cyclo: ../lvgl/demos/multilang/%.c lvgl/demos/multilang/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H723xx -c -I../Core/Inc -I"C:/Users/Viktor/Desktop/labaratorni/Projects/Metal_Detector/software/lvgl/src" -I"C:/Users/Viktor/Desktop/labaratorni/Projects/Metal_Detector/software/lvgl" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-demos-2f-multilang

clean-lvgl-2f-demos-2f-multilang:
	-$(RM) ./lvgl/demos/multilang/lv_demo_multilang.cyclo ./lvgl/demos/multilang/lv_demo_multilang.d ./lvgl/demos/multilang/lv_demo_multilang.o ./lvgl/demos/multilang/lv_demo_multilang.su

.PHONY: clean-lvgl-2f-demos-2f-multilang

