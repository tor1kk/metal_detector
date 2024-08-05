################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/demos/multilang/assets/fonts/font_multilang_large.c \
../lvgl/demos/multilang/assets/fonts/font_multilang_small.c 

OBJS += \
./lvgl/demos/multilang/assets/fonts/font_multilang_large.o \
./lvgl/demos/multilang/assets/fonts/font_multilang_small.o 

C_DEPS += \
./lvgl/demos/multilang/assets/fonts/font_multilang_large.d \
./lvgl/demos/multilang/assets/fonts/font_multilang_small.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/demos/multilang/assets/fonts/%.o lvgl/demos/multilang/assets/fonts/%.su lvgl/demos/multilang/assets/fonts/%.cyclo: ../lvgl/demos/multilang/assets/fonts/%.c lvgl/demos/multilang/assets/fonts/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H723xx -c -I../Core/Inc -I"C:/Users/Viktor/Desktop/labaratorni/Projects/Metal_Detector/software/lvgl/src" -I"C:/Users/Viktor/Desktop/labaratorni/Projects/Metal_Detector/software/lvgl" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-demos-2f-multilang-2f-assets-2f-fonts

clean-lvgl-2f-demos-2f-multilang-2f-assets-2f-fonts:
	-$(RM) ./lvgl/demos/multilang/assets/fonts/font_multilang_large.cyclo ./lvgl/demos/multilang/assets/fonts/font_multilang_large.d ./lvgl/demos/multilang/assets/fonts/font_multilang_large.o ./lvgl/demos/multilang/assets/fonts/font_multilang_large.su ./lvgl/demos/multilang/assets/fonts/font_multilang_small.cyclo ./lvgl/demos/multilang/assets/fonts/font_multilang_small.d ./lvgl/demos/multilang/assets/fonts/font_multilang_small.o ./lvgl/demos/multilang/assets/fonts/font_multilang_small.su

.PHONY: clean-lvgl-2f-demos-2f-multilang-2f-assets-2f-fonts

