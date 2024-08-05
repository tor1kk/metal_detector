################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_UPPER_SRCS += \
../lvgl/src/draw/sw/blend/neon/lv_blend_neon.S 

OBJS += \
./lvgl/src/draw/sw/blend/neon/lv_blend_neon.o 

S_UPPER_DEPS += \
./lvgl/src/draw/sw/blend/neon/lv_blend_neon.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/draw/sw/blend/neon/%.o: ../lvgl/src/draw/sw/blend/neon/%.S lvgl/src/draw/sw/blend/neon/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m7 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-lvgl-2f-src-2f-draw-2f-sw-2f-blend-2f-neon

clean-lvgl-2f-src-2f-draw-2f-sw-2f-blend-2f-neon:
	-$(RM) ./lvgl/src/draw/sw/blend/neon/lv_blend_neon.d ./lvgl/src/draw/sw/blend/neon/lv_blend_neon.o

.PHONY: clean-lvgl-2f-src-2f-draw-2f-sw-2f-blend-2f-neon

