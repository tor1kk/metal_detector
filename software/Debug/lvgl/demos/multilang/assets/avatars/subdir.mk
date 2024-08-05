################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/demos/multilang/assets/avatars/img_multilang_avatar_1.c \
../lvgl/demos/multilang/assets/avatars/img_multilang_avatar_10.c \
../lvgl/demos/multilang/assets/avatars/img_multilang_avatar_11.c \
../lvgl/demos/multilang/assets/avatars/img_multilang_avatar_12.c \
../lvgl/demos/multilang/assets/avatars/img_multilang_avatar_13.c \
../lvgl/demos/multilang/assets/avatars/img_multilang_avatar_14.c \
../lvgl/demos/multilang/assets/avatars/img_multilang_avatar_15.c \
../lvgl/demos/multilang/assets/avatars/img_multilang_avatar_16.c \
../lvgl/demos/multilang/assets/avatars/img_multilang_avatar_17.c \
../lvgl/demos/multilang/assets/avatars/img_multilang_avatar_18.c \
../lvgl/demos/multilang/assets/avatars/img_multilang_avatar_19.c \
../lvgl/demos/multilang/assets/avatars/img_multilang_avatar_2.c \
../lvgl/demos/multilang/assets/avatars/img_multilang_avatar_22.c \
../lvgl/demos/multilang/assets/avatars/img_multilang_avatar_25.c \
../lvgl/demos/multilang/assets/avatars/img_multilang_avatar_3.c \
../lvgl/demos/multilang/assets/avatars/img_multilang_avatar_4.c \
../lvgl/demos/multilang/assets/avatars/img_multilang_avatar_5.c \
../lvgl/demos/multilang/assets/avatars/img_multilang_avatar_6.c \
../lvgl/demos/multilang/assets/avatars/img_multilang_avatar_7.c \
../lvgl/demos/multilang/assets/avatars/img_multilang_avatar_8.c \
../lvgl/demos/multilang/assets/avatars/img_multilang_avatar_9.c 

OBJS += \
./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_1.o \
./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_10.o \
./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_11.o \
./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_12.o \
./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_13.o \
./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_14.o \
./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_15.o \
./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_16.o \
./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_17.o \
./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_18.o \
./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_19.o \
./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_2.o \
./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_22.o \
./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_25.o \
./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_3.o \
./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_4.o \
./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_5.o \
./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_6.o \
./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_7.o \
./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_8.o \
./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_9.o 

C_DEPS += \
./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_1.d \
./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_10.d \
./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_11.d \
./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_12.d \
./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_13.d \
./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_14.d \
./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_15.d \
./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_16.d \
./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_17.d \
./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_18.d \
./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_19.d \
./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_2.d \
./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_22.d \
./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_25.d \
./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_3.d \
./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_4.d \
./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_5.d \
./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_6.d \
./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_7.d \
./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_8.d \
./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_9.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/demos/multilang/assets/avatars/%.o lvgl/demos/multilang/assets/avatars/%.su lvgl/demos/multilang/assets/avatars/%.cyclo: ../lvgl/demos/multilang/assets/avatars/%.c lvgl/demos/multilang/assets/avatars/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H723xx -c -I../Core/Inc -I"C:/Users/Viktor/Desktop/labaratorni/Projects/Metal_Detector/software/lvgl/src" -I"C:/Users/Viktor/Desktop/labaratorni/Projects/Metal_Detector/software/lvgl" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-demos-2f-multilang-2f-assets-2f-avatars

clean-lvgl-2f-demos-2f-multilang-2f-assets-2f-avatars:
	-$(RM) ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_1.cyclo ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_1.d ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_1.o ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_1.su ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_10.cyclo ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_10.d ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_10.o ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_10.su ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_11.cyclo ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_11.d ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_11.o ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_11.su ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_12.cyclo ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_12.d ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_12.o ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_12.su ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_13.cyclo ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_13.d ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_13.o ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_13.su ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_14.cyclo ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_14.d ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_14.o ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_14.su ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_15.cyclo ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_15.d ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_15.o ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_15.su ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_16.cyclo ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_16.d ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_16.o ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_16.su ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_17.cyclo ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_17.d ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_17.o ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_17.su ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_18.cyclo ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_18.d ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_18.o ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_18.su ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_19.cyclo ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_19.d ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_19.o ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_19.su ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_2.cyclo ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_2.d ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_2.o ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_2.su ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_22.cyclo ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_22.d ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_22.o ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_22.su ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_25.cyclo ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_25.d ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_25.o ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_25.su ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_3.cyclo ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_3.d ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_3.o ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_3.su ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_4.cyclo ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_4.d ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_4.o ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_4.su ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_5.cyclo ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_5.d ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_5.o ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_5.su ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_6.cyclo ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_6.d ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_6.o ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_6.su ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_7.cyclo ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_7.d ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_7.o ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_7.su ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_8.cyclo ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_8.d ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_8.o ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_8.su ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_9.cyclo ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_9.d ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_9.o ./lvgl/demos/multilang/assets/avatars/img_multilang_avatar_9.su

.PHONY: clean-lvgl-2f-demos-2f-multilang-2f-assets-2f-avatars

