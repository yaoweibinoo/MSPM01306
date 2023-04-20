################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"E:/ti/ccs1230/ccs/tools/compiler/ti-cgt-armllvm_2.1.3.LTS/bin/tiarmclang.exe" -c -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O2 -I"E:/Users/Administrator/workspace_v12/TIME" -I"E:/Users/Administrator/workspace_v12/TIME/Debug" -I"C:/ti/mspm0_sdk_1_00_00_04/source/third_party/CMSIS/Core/Include" -I"C:/ti/mspm0_sdk_1_00_00_04/source" -D__MSPM0L1306__ -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)" -I"E:/Users/Administrator/workspace_v12/TIME/Debug/syscfg"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

build-1827288031: ../empty.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"C:/ti/sysconfig_1_15_0/sysconfig_cli.bat" -s "C:/ti/mspm0_sdk_1_00_00_04/.metadata/product.json" --script "E:/Users/Administrator/workspace_v12/TIME/empty.syscfg" -o "syscfg" --compiler ticlang
	@echo 'Finished building: "$<"'
	@echo ' '

syscfg/ti_msp_dl_config.c: build-1827288031 ../empty.syscfg
syscfg/ti_msp_dl_config.h: build-1827288031
syscfg/Event.dot: build-1827288031
syscfg/: build-1827288031

syscfg/%.o: ./syscfg/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"E:/ti/ccs1230/ccs/tools/compiler/ti-cgt-armllvm_2.1.3.LTS/bin/tiarmclang.exe" -c -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O2 -I"E:/Users/Administrator/workspace_v12/TIME" -I"E:/Users/Administrator/workspace_v12/TIME/Debug" -I"C:/ti/mspm0_sdk_1_00_00_04/source/third_party/CMSIS/Core/Include" -I"C:/ti/mspm0_sdk_1_00_00_04/source" -D__MSPM0L1306__ -gdwarf-3 -MMD -MP -MF"syscfg/$(basename $(<F)).d_raw" -MT"$(@)" -I"E:/Users/Administrator/workspace_v12/TIME/Debug/syscfg"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


