################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/draw/vg_lite/lv_draw_buf_vg_lite.c \
../lvgl/src/draw/vg_lite/lv_draw_vg_lite.c \
../lvgl/src/draw/vg_lite/lv_draw_vg_lite_arc.c \
../lvgl/src/draw/vg_lite/lv_draw_vg_lite_border.c \
../lvgl/src/draw/vg_lite/lv_draw_vg_lite_box_shadow.c \
../lvgl/src/draw/vg_lite/lv_draw_vg_lite_fill.c \
../lvgl/src/draw/vg_lite/lv_draw_vg_lite_img.c \
../lvgl/src/draw/vg_lite/lv_draw_vg_lite_label.c \
../lvgl/src/draw/vg_lite/lv_draw_vg_lite_layer.c \
../lvgl/src/draw/vg_lite/lv_draw_vg_lite_line.c \
../lvgl/src/draw/vg_lite/lv_draw_vg_lite_mask_rect.c \
../lvgl/src/draw/vg_lite/lv_draw_vg_lite_triangle.c \
../lvgl/src/draw/vg_lite/lv_draw_vg_lite_vector.c \
../lvgl/src/draw/vg_lite/lv_vg_lite_decoder.c \
../lvgl/src/draw/vg_lite/lv_vg_lite_grad.c \
../lvgl/src/draw/vg_lite/lv_vg_lite_math.c \
../lvgl/src/draw/vg_lite/lv_vg_lite_path.c \
../lvgl/src/draw/vg_lite/lv_vg_lite_pending.c \
../lvgl/src/draw/vg_lite/lv_vg_lite_utils.c 

OBJS += \
./lvgl/src/draw/vg_lite/lv_draw_buf_vg_lite.o \
./lvgl/src/draw/vg_lite/lv_draw_vg_lite.o \
./lvgl/src/draw/vg_lite/lv_draw_vg_lite_arc.o \
./lvgl/src/draw/vg_lite/lv_draw_vg_lite_border.o \
./lvgl/src/draw/vg_lite/lv_draw_vg_lite_box_shadow.o \
./lvgl/src/draw/vg_lite/lv_draw_vg_lite_fill.o \
./lvgl/src/draw/vg_lite/lv_draw_vg_lite_img.o \
./lvgl/src/draw/vg_lite/lv_draw_vg_lite_label.o \
./lvgl/src/draw/vg_lite/lv_draw_vg_lite_layer.o \
./lvgl/src/draw/vg_lite/lv_draw_vg_lite_line.o \
./lvgl/src/draw/vg_lite/lv_draw_vg_lite_mask_rect.o \
./lvgl/src/draw/vg_lite/lv_draw_vg_lite_triangle.o \
./lvgl/src/draw/vg_lite/lv_draw_vg_lite_vector.o \
./lvgl/src/draw/vg_lite/lv_vg_lite_decoder.o \
./lvgl/src/draw/vg_lite/lv_vg_lite_grad.o \
./lvgl/src/draw/vg_lite/lv_vg_lite_math.o \
./lvgl/src/draw/vg_lite/lv_vg_lite_path.o \
./lvgl/src/draw/vg_lite/lv_vg_lite_pending.o \
./lvgl/src/draw/vg_lite/lv_vg_lite_utils.o 

C_DEPS += \
./lvgl/src/draw/vg_lite/lv_draw_buf_vg_lite.d \
./lvgl/src/draw/vg_lite/lv_draw_vg_lite.d \
./lvgl/src/draw/vg_lite/lv_draw_vg_lite_arc.d \
./lvgl/src/draw/vg_lite/lv_draw_vg_lite_border.d \
./lvgl/src/draw/vg_lite/lv_draw_vg_lite_box_shadow.d \
./lvgl/src/draw/vg_lite/lv_draw_vg_lite_fill.d \
./lvgl/src/draw/vg_lite/lv_draw_vg_lite_img.d \
./lvgl/src/draw/vg_lite/lv_draw_vg_lite_label.d \
./lvgl/src/draw/vg_lite/lv_draw_vg_lite_layer.d \
./lvgl/src/draw/vg_lite/lv_draw_vg_lite_line.d \
./lvgl/src/draw/vg_lite/lv_draw_vg_lite_mask_rect.d \
./lvgl/src/draw/vg_lite/lv_draw_vg_lite_triangle.d \
./lvgl/src/draw/vg_lite/lv_draw_vg_lite_vector.d \
./lvgl/src/draw/vg_lite/lv_vg_lite_decoder.d \
./lvgl/src/draw/vg_lite/lv_vg_lite_grad.d \
./lvgl/src/draw/vg_lite/lv_vg_lite_math.d \
./lvgl/src/draw/vg_lite/lv_vg_lite_path.d \
./lvgl/src/draw/vg_lite/lv_vg_lite_pending.d \
./lvgl/src/draw/vg_lite/lv_vg_lite_utils.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/draw/vg_lite/%.o lvgl/src/draw/vg_lite/%.su lvgl/src/draw/vg_lite/%.cyclo: ../lvgl/src/draw/vg_lite/%.c lvgl/src/draw/vg_lite/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H723xx -DARM_MATH_CM7 -c -I"C:/Users/Viktor/Desktop/labaratorni/Projects/MetalDetector/software/Program/SignalsProcessing/Inc" -I"C:/Users/Viktor/Desktop/labaratorni/Projects/MetalDetector/software/Program/UI/Inc" -I"C:/Users/Viktor/Desktop/labaratorni/Projects/MetalDetector/software/Drivers/CMSIS-DSP/Inc" -I"C:/Users/Viktor/Desktop/labaratorni/Projects/MetalDetector/software/Program/Tasks/Inc" -I"C:/Users/Viktor/Desktop/labaratorni/Projects/MetalDetector/software/Program/UI" -I"C:/Users/Viktor/Desktop/labaratorni/Projects/MetalDetector/software/Program/Display/Inc" -I../Core/Inc -I"C:/Users/Viktor/Desktop/labaratorni/Projects/MetalDetector/software/lvgl/src" -I"C:/Users/Viktor/Desktop/labaratorni/Projects/MetalDetector/software/lvgl" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/ST/ARM/DSP/Inc -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-src-2f-draw-2f-vg_lite

clean-lvgl-2f-src-2f-draw-2f-vg_lite:
	-$(RM) ./lvgl/src/draw/vg_lite/lv_draw_buf_vg_lite.cyclo ./lvgl/src/draw/vg_lite/lv_draw_buf_vg_lite.d ./lvgl/src/draw/vg_lite/lv_draw_buf_vg_lite.o ./lvgl/src/draw/vg_lite/lv_draw_buf_vg_lite.su ./lvgl/src/draw/vg_lite/lv_draw_vg_lite.cyclo ./lvgl/src/draw/vg_lite/lv_draw_vg_lite.d ./lvgl/src/draw/vg_lite/lv_draw_vg_lite.o ./lvgl/src/draw/vg_lite/lv_draw_vg_lite.su ./lvgl/src/draw/vg_lite/lv_draw_vg_lite_arc.cyclo ./lvgl/src/draw/vg_lite/lv_draw_vg_lite_arc.d ./lvgl/src/draw/vg_lite/lv_draw_vg_lite_arc.o ./lvgl/src/draw/vg_lite/lv_draw_vg_lite_arc.su ./lvgl/src/draw/vg_lite/lv_draw_vg_lite_border.cyclo ./lvgl/src/draw/vg_lite/lv_draw_vg_lite_border.d ./lvgl/src/draw/vg_lite/lv_draw_vg_lite_border.o ./lvgl/src/draw/vg_lite/lv_draw_vg_lite_border.su ./lvgl/src/draw/vg_lite/lv_draw_vg_lite_box_shadow.cyclo ./lvgl/src/draw/vg_lite/lv_draw_vg_lite_box_shadow.d ./lvgl/src/draw/vg_lite/lv_draw_vg_lite_box_shadow.o ./lvgl/src/draw/vg_lite/lv_draw_vg_lite_box_shadow.su ./lvgl/src/draw/vg_lite/lv_draw_vg_lite_fill.cyclo ./lvgl/src/draw/vg_lite/lv_draw_vg_lite_fill.d ./lvgl/src/draw/vg_lite/lv_draw_vg_lite_fill.o ./lvgl/src/draw/vg_lite/lv_draw_vg_lite_fill.su ./lvgl/src/draw/vg_lite/lv_draw_vg_lite_img.cyclo ./lvgl/src/draw/vg_lite/lv_draw_vg_lite_img.d ./lvgl/src/draw/vg_lite/lv_draw_vg_lite_img.o ./lvgl/src/draw/vg_lite/lv_draw_vg_lite_img.su ./lvgl/src/draw/vg_lite/lv_draw_vg_lite_label.cyclo ./lvgl/src/draw/vg_lite/lv_draw_vg_lite_label.d ./lvgl/src/draw/vg_lite/lv_draw_vg_lite_label.o ./lvgl/src/draw/vg_lite/lv_draw_vg_lite_label.su ./lvgl/src/draw/vg_lite/lv_draw_vg_lite_layer.cyclo ./lvgl/src/draw/vg_lite/lv_draw_vg_lite_layer.d ./lvgl/src/draw/vg_lite/lv_draw_vg_lite_layer.o ./lvgl/src/draw/vg_lite/lv_draw_vg_lite_layer.su ./lvgl/src/draw/vg_lite/lv_draw_vg_lite_line.cyclo ./lvgl/src/draw/vg_lite/lv_draw_vg_lite_line.d ./lvgl/src/draw/vg_lite/lv_draw_vg_lite_line.o ./lvgl/src/draw/vg_lite/lv_draw_vg_lite_line.su ./lvgl/src/draw/vg_lite/lv_draw_vg_lite_mask_rect.cyclo ./lvgl/src/draw/vg_lite/lv_draw_vg_lite_mask_rect.d ./lvgl/src/draw/vg_lite/lv_draw_vg_lite_mask_rect.o ./lvgl/src/draw/vg_lite/lv_draw_vg_lite_mask_rect.su ./lvgl/src/draw/vg_lite/lv_draw_vg_lite_triangle.cyclo ./lvgl/src/draw/vg_lite/lv_draw_vg_lite_triangle.d ./lvgl/src/draw/vg_lite/lv_draw_vg_lite_triangle.o ./lvgl/src/draw/vg_lite/lv_draw_vg_lite_triangle.su ./lvgl/src/draw/vg_lite/lv_draw_vg_lite_vector.cyclo ./lvgl/src/draw/vg_lite/lv_draw_vg_lite_vector.d ./lvgl/src/draw/vg_lite/lv_draw_vg_lite_vector.o ./lvgl/src/draw/vg_lite/lv_draw_vg_lite_vector.su ./lvgl/src/draw/vg_lite/lv_vg_lite_decoder.cyclo ./lvgl/src/draw/vg_lite/lv_vg_lite_decoder.d ./lvgl/src/draw/vg_lite/lv_vg_lite_decoder.o ./lvgl/src/draw/vg_lite/lv_vg_lite_decoder.su ./lvgl/src/draw/vg_lite/lv_vg_lite_grad.cyclo ./lvgl/src/draw/vg_lite/lv_vg_lite_grad.d ./lvgl/src/draw/vg_lite/lv_vg_lite_grad.o ./lvgl/src/draw/vg_lite/lv_vg_lite_grad.su ./lvgl/src/draw/vg_lite/lv_vg_lite_math.cyclo ./lvgl/src/draw/vg_lite/lv_vg_lite_math.d ./lvgl/src/draw/vg_lite/lv_vg_lite_math.o ./lvgl/src/draw/vg_lite/lv_vg_lite_math.su ./lvgl/src/draw/vg_lite/lv_vg_lite_path.cyclo ./lvgl/src/draw/vg_lite/lv_vg_lite_path.d ./lvgl/src/draw/vg_lite/lv_vg_lite_path.o ./lvgl/src/draw/vg_lite/lv_vg_lite_path.su ./lvgl/src/draw/vg_lite/lv_vg_lite_pending.cyclo ./lvgl/src/draw/vg_lite/lv_vg_lite_pending.d ./lvgl/src/draw/vg_lite/lv_vg_lite_pending.o ./lvgl/src/draw/vg_lite/lv_vg_lite_pending.su ./lvgl/src/draw/vg_lite/lv_vg_lite_utils.cyclo ./lvgl/src/draw/vg_lite/lv_vg_lite_utils.d ./lvgl/src/draw/vg_lite/lv_vg_lite_utils.o ./lvgl/src/draw/vg_lite/lv_vg_lite_utils.su

.PHONY: clean-lvgl-2f-src-2f-draw-2f-vg_lite

