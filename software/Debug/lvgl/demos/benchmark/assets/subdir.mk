################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/demos/benchmark/assets/img_benchmark_cogwheel_alpha256.c \
../lvgl/demos/benchmark/assets/img_benchmark_cogwheel_argb.c \
../lvgl/demos/benchmark/assets/img_benchmark_cogwheel_indexed16.c \
../lvgl/demos/benchmark/assets/img_benchmark_cogwheel_rgb.c \
../lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_12_compr_az.c.c \
../lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_16_compr_az.c.c \
../lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_28_compr_az.c.c 

OBJS += \
./lvgl/demos/benchmark/assets/img_benchmark_cogwheel_alpha256.o \
./lvgl/demos/benchmark/assets/img_benchmark_cogwheel_argb.o \
./lvgl/demos/benchmark/assets/img_benchmark_cogwheel_indexed16.o \
./lvgl/demos/benchmark/assets/img_benchmark_cogwheel_rgb.o \
./lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_12_compr_az.c.o \
./lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_16_compr_az.c.o \
./lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_28_compr_az.c.o 

C_DEPS += \
./lvgl/demos/benchmark/assets/img_benchmark_cogwheel_alpha256.d \
./lvgl/demos/benchmark/assets/img_benchmark_cogwheel_argb.d \
./lvgl/demos/benchmark/assets/img_benchmark_cogwheel_indexed16.d \
./lvgl/demos/benchmark/assets/img_benchmark_cogwheel_rgb.d \
./lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_12_compr_az.c.d \
./lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_16_compr_az.c.d \
./lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_28_compr_az.c.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/demos/benchmark/assets/%.o lvgl/demos/benchmark/assets/%.su lvgl/demos/benchmark/assets/%.cyclo: ../lvgl/demos/benchmark/assets/%.c lvgl/demos/benchmark/assets/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H723xx -c -I../Core/Inc -I"C:/Users/Viktor/Desktop/labaratorni/Projects/Metal_Detector/software/lvgl/src" -I"C:/Users/Viktor/Desktop/labaratorni/Projects/Metal_Detector/software/lvgl" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-demos-2f-benchmark-2f-assets

clean-lvgl-2f-demos-2f-benchmark-2f-assets:
	-$(RM) ./lvgl/demos/benchmark/assets/img_benchmark_cogwheel_alpha256.cyclo ./lvgl/demos/benchmark/assets/img_benchmark_cogwheel_alpha256.d ./lvgl/demos/benchmark/assets/img_benchmark_cogwheel_alpha256.o ./lvgl/demos/benchmark/assets/img_benchmark_cogwheel_alpha256.su ./lvgl/demos/benchmark/assets/img_benchmark_cogwheel_argb.cyclo ./lvgl/demos/benchmark/assets/img_benchmark_cogwheel_argb.d ./lvgl/demos/benchmark/assets/img_benchmark_cogwheel_argb.o ./lvgl/demos/benchmark/assets/img_benchmark_cogwheel_argb.su ./lvgl/demos/benchmark/assets/img_benchmark_cogwheel_indexed16.cyclo ./lvgl/demos/benchmark/assets/img_benchmark_cogwheel_indexed16.d ./lvgl/demos/benchmark/assets/img_benchmark_cogwheel_indexed16.o ./lvgl/demos/benchmark/assets/img_benchmark_cogwheel_indexed16.su ./lvgl/demos/benchmark/assets/img_benchmark_cogwheel_rgb.cyclo ./lvgl/demos/benchmark/assets/img_benchmark_cogwheel_rgb.d ./lvgl/demos/benchmark/assets/img_benchmark_cogwheel_rgb.o ./lvgl/demos/benchmark/assets/img_benchmark_cogwheel_rgb.su ./lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_12_compr_az.c.cyclo ./lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_12_compr_az.c.d ./lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_12_compr_az.c.o ./lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_12_compr_az.c.su ./lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_16_compr_az.c.cyclo ./lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_16_compr_az.c.d ./lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_16_compr_az.c.o ./lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_16_compr_az.c.su ./lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_28_compr_az.c.cyclo ./lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_28_compr_az.c.d ./lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_28_compr_az.c.o ./lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_28_compr_az.c.su

.PHONY: clean-lvgl-2f-demos-2f-benchmark-2f-assets

