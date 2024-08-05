################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/demos/widgets/assets/img_clothes.c \
../lvgl/demos/widgets/assets/img_demo_widgets_avatar.c \
../lvgl/demos/widgets/assets/img_demo_widgets_needle.c \
../lvgl/demos/widgets/assets/img_lvgl_logo.c 

OBJS += \
./lvgl/demos/widgets/assets/img_clothes.o \
./lvgl/demos/widgets/assets/img_demo_widgets_avatar.o \
./lvgl/demos/widgets/assets/img_demo_widgets_needle.o \
./lvgl/demos/widgets/assets/img_lvgl_logo.o 

C_DEPS += \
./lvgl/demos/widgets/assets/img_clothes.d \
./lvgl/demos/widgets/assets/img_demo_widgets_avatar.d \
./lvgl/demos/widgets/assets/img_demo_widgets_needle.d \
./lvgl/demos/widgets/assets/img_lvgl_logo.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/demos/widgets/assets/%.o lvgl/demos/widgets/assets/%.su lvgl/demos/widgets/assets/%.cyclo: ../lvgl/demos/widgets/assets/%.c lvgl/demos/widgets/assets/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H723xx -c -I../Core/Inc -I"C:/Users/Viktor/Desktop/labaratorni/Projects/Metal_Detector/software/lvgl/src" -I"C:/Users/Viktor/Desktop/labaratorni/Projects/Metal_Detector/software/lvgl" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-demos-2f-widgets-2f-assets

clean-lvgl-2f-demos-2f-widgets-2f-assets:
	-$(RM) ./lvgl/demos/widgets/assets/img_clothes.cyclo ./lvgl/demos/widgets/assets/img_clothes.d ./lvgl/demos/widgets/assets/img_clothes.o ./lvgl/demos/widgets/assets/img_clothes.su ./lvgl/demos/widgets/assets/img_demo_widgets_avatar.cyclo ./lvgl/demos/widgets/assets/img_demo_widgets_avatar.d ./lvgl/demos/widgets/assets/img_demo_widgets_avatar.o ./lvgl/demos/widgets/assets/img_demo_widgets_avatar.su ./lvgl/demos/widgets/assets/img_demo_widgets_needle.cyclo ./lvgl/demos/widgets/assets/img_demo_widgets_needle.d ./lvgl/demos/widgets/assets/img_demo_widgets_needle.o ./lvgl/demos/widgets/assets/img_demo_widgets_needle.su ./lvgl/demos/widgets/assets/img_lvgl_logo.cyclo ./lvgl/demos/widgets/assets/img_lvgl_logo.d ./lvgl/demos/widgets/assets/img_lvgl_logo.o ./lvgl/demos/widgets/assets/img_lvgl_logo.su

.PHONY: clean-lvgl-2f-demos-2f-widgets-2f-assets

