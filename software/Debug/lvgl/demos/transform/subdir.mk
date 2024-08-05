################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/demos/transform/lv_demo_transform.c 

OBJS += \
./lvgl/demos/transform/lv_demo_transform.o 

C_DEPS += \
./lvgl/demos/transform/lv_demo_transform.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/demos/transform/%.o lvgl/demos/transform/%.su lvgl/demos/transform/%.cyclo: ../lvgl/demos/transform/%.c lvgl/demos/transform/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H723xx -c -I../Core/Inc -I"C:/Users/Viktor/Desktop/labaratorni/Projects/Metal_Detector/software/lvgl/src" -I"C:/Users/Viktor/Desktop/labaratorni/Projects/Metal_Detector/software/lvgl" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-demos-2f-transform

clean-lvgl-2f-demos-2f-transform:
	-$(RM) ./lvgl/demos/transform/lv_demo_transform.cyclo ./lvgl/demos/transform/lv_demo_transform.d ./lvgl/demos/transform/lv_demo_transform.o ./lvgl/demos/transform/lv_demo_transform.su

.PHONY: clean-lvgl-2f-demos-2f-transform

