################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/demos/widgets/lv_demo_widgets.c 

OBJS += \
./lvgl/demos/widgets/lv_demo_widgets.o 

C_DEPS += \
./lvgl/demos/widgets/lv_demo_widgets.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/demos/widgets/%.o lvgl/demos/widgets/%.su lvgl/demos/widgets/%.cyclo: ../lvgl/demos/widgets/%.c lvgl/demos/widgets/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H723xx -c -I../Core/Inc -I"C:/Users/Viktor/Desktop/labaratorni/Projects/Metal_Detector/software/lvgl/src" -I"C:/Users/Viktor/Desktop/labaratorni/Projects/Metal_Detector/software/lvgl" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-demos-2f-widgets

clean-lvgl-2f-demos-2f-widgets:
	-$(RM) ./lvgl/demos/widgets/lv_demo_widgets.cyclo ./lvgl/demos/widgets/lv_demo_widgets.d ./lvgl/demos/widgets/lv_demo_widgets.o ./lvgl/demos/widgets/lv_demo_widgets.su

.PHONY: clean-lvgl-2f-demos-2f-widgets

