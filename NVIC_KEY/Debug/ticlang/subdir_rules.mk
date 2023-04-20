################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
ticlang/%.o: ../ticlang/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"E:/ti/ccs1230/ccs/tools/compiler/ti-cgt-armllvm_2.1.3.LTS/bin/tiarmclang.exe" -c -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O2 -I"E:/Users/Administrator/workspace_v12/NVIC_KEY" -I"E:/Users/Administrator/workspace_v12/NVIC_KEY/Debug" -I"C:/ti/mspm0_sdk_1_00_00_04/source/third_party/CMSIS/Core/Include" -I"C:/ti/mspm0_sdk_1_00_00_04/source" -D__MSPM0L1306__ -gdwarf-3 -MMD -MP -MF"ticlang/$(basename $(<F)).d_raw" -MT"$(@)" -I"E:/Users/Administrator/workspace_v12/NVIC_KEY/Debug/syscfg"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


