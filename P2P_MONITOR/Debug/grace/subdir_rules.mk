################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
grace/%.obj: ../grace/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"D:/ti/ccs2011/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/bin/cl430" -vmsp -O3 --use_hw_mpy=none --include_path="D:/ti/ccs2011/ccs/ccs_base/msp430/include" --include_path="C:/Users/Brady/workspace_ccstheia/P2P RX_TX" --include_path="C:/Users/Brady/workspace_ccstheia/P2P RX_TX/GrLib/grlib" --include_path="C:/Users/Brady/workspace_ccstheia/P2P RX_TX/GrLib/fonts" --include_path="D:/ti/ccs2011/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/include" --advice:power="none" --define=__MSP430G2553__ -g --gcc --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="grace/$(basename $(<F)).d_raw" --obj_directory="grace" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


