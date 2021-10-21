################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../device/system_MIMXRT1021.c 

OBJS += \
./device/system_MIMXRT1021.o 

C_DEPS += \
./device/system_MIMXRT1021.d 


# Each subdirectory must supply rules for building sources it contributes
device/%.o: ../device/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_MIMXRT1021DAG5A -DCPU_MIMXRT1021DAG5A_cm7 -DXIP_BOOT_HEADER_DCD_ENABLE=1 -DSKIP_SYSCLK_INIT -DDATA_SECTION_IS_CACHEABLE=1 -DSDK_DEBUGCONSOLE=1 -DXIP_EXTERNAL_FLASH=1 -DXIP_BOOT_HEADER_ENABLE=1 -DPRINTF_FLOAT_ENABLE=0 -DSCANF_FLOAT_ENABLE=0 -DPRINTF_ADVANCED_ENABLE=0 -DSCANF_ADVANCED_ENABLE=0 -DCR_INTEGER_PRINTF -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\Users\Issac\Documents\MCUXpressoIDE_11.3.1_5262\workspace\evkmimxrt1020_hello_world\board" -I"C:\Users\Issac\Documents\MCUXpressoIDE_11.3.1_5262\workspace\evkmimxrt1020_hello_world\source" -I"C:\Users\Issac\Documents\MCUXpressoIDE_11.3.1_5262\workspace\evkmimxrt1020_hello_world\utilities" -I"C:\Users\Issac\Documents\MCUXpressoIDE_11.3.1_5262\workspace\evkmimxrt1020_hello_world\drivers" -I"C:\Users\Issac\Documents\MCUXpressoIDE_11.3.1_5262\workspace\evkmimxrt1020_hello_world\device" -I"C:\Users\Issac\Documents\MCUXpressoIDE_11.3.1_5262\workspace\evkmimxrt1020_hello_world\component\uart" -I"C:\Users\Issac\Documents\MCUXpressoIDE_11.3.1_5262\workspace\evkmimxrt1020_hello_world\component\lists" -I"C:\Users\Issac\Documents\MCUXpressoIDE_11.3.1_5262\workspace\evkmimxrt1020_hello_world\xip" -I"C:\Users\Issac\Documents\MCUXpressoIDE_11.3.1_5262\workspace\evkmimxrt1020_hello_world\CMSIS" -O0 -fno-common -g3 -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m7 -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

