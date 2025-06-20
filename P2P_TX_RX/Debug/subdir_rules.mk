################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
BCSplus_init.obj: D:/ti/grace/P2P/grace/BCSplus_init.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"D:/ti/ccs2011/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/bin/cl430" -vmsp -O3 --use_hw_mpy=none --include_path="D:/ti/ccs2011/ccs/ccs_base/msp430/include" --include_path="C:/Users/Brady/workspace_ccstheia/P2P_TX_RX" --include_path="C:/Users/Brady/workspace_ccstheia/P2P_TX_RX/GrLib/grlib" --include_path="C:/Users/Brady/workspace_ccstheia/P2P_TX_RX/GrLib/fonts" --include_path="D:/ti/ccs2011/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/include" --advice:power="none" --define=__MSP430G2553__ -g --gcc --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

GPIO_init.obj: D:/ti/grace/P2P/grace/GPIO_init.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"D:/ti/ccs2011/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/bin/cl430" -vmsp -O3 --use_hw_mpy=none --include_path="D:/ti/ccs2011/ccs/ccs_base/msp430/include" --include_path="C:/Users/Brady/workspace_ccstheia/P2P_TX_RX" --include_path="C:/Users/Brady/workspace_ccstheia/P2P_TX_RX/GrLib/grlib" --include_path="C:/Users/Brady/workspace_ccstheia/P2P_TX_RX/GrLib/fonts" --include_path="D:/ti/ccs2011/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/include" --advice:power="none" --define=__MSP430G2553__ -g --gcc --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

Grace_init.obj: D:/ti/grace/P2P/grace/Grace_init.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"D:/ti/ccs2011/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/bin/cl430" -vmsp -O3 --use_hw_mpy=none --include_path="D:/ti/ccs2011/ccs/ccs_base/msp430/include" --include_path="C:/Users/Brady/workspace_ccstheia/P2P_TX_RX" --include_path="C:/Users/Brady/workspace_ccstheia/P2P_TX_RX/GrLib/grlib" --include_path="C:/Users/Brady/workspace_ccstheia/P2P_TX_RX/GrLib/fonts" --include_path="D:/ti/ccs2011/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/include" --advice:power="none" --define=__MSP430G2553__ -g --gcc --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

InterruptVectors_init.obj: D:/ti/grace/P2P/grace/InterruptVectors_init.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"D:/ti/ccs2011/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/bin/cl430" -vmsp -O3 --use_hw_mpy=none --include_path="D:/ti/ccs2011/ccs/ccs_base/msp430/include" --include_path="C:/Users/Brady/workspace_ccstheia/P2P_TX_RX" --include_path="C:/Users/Brady/workspace_ccstheia/P2P_TX_RX/GrLib/grlib" --include_path="C:/Users/Brady/workspace_ccstheia/P2P_TX_RX/GrLib/fonts" --include_path="D:/ti/ccs2011/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/include" --advice:power="none" --define=__MSP430G2553__ -g --gcc --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"D:/ti/ccs2011/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/bin/cl430" -vmsp -O3 --use_hw_mpy=none --include_path="D:/ti/ccs2011/ccs/ccs_base/msp430/include" --include_path="C:/Users/Brady/workspace_ccstheia/P2P_TX_RX" --include_path="C:/Users/Brady/workspace_ccstheia/P2P_TX_RX/GrLib/grlib" --include_path="C:/Users/Brady/workspace_ccstheia/P2P_TX_RX/GrLib/fonts" --include_path="D:/ti/ccs2011/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/include" --advice:power="none" --define=__MSP430G2553__ -g --gcc --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

System_init.obj: D:/ti/grace/P2P/grace/System_init.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"D:/ti/ccs2011/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/bin/cl430" -vmsp -O3 --use_hw_mpy=none --include_path="D:/ti/ccs2011/ccs/ccs_base/msp430/include" --include_path="C:/Users/Brady/workspace_ccstheia/P2P_TX_RX" --include_path="C:/Users/Brady/workspace_ccstheia/P2P_TX_RX/GrLib/grlib" --include_path="C:/Users/Brady/workspace_ccstheia/P2P_TX_RX/GrLib/fonts" --include_path="D:/ti/ccs2011/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/include" --advice:power="none" --define=__MSP430G2553__ -g --gcc --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

USCI_A0_init.obj: D:/ti/grace/P2P/grace/USCI_A0_init.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"D:/ti/ccs2011/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/bin/cl430" -vmsp -O3 --use_hw_mpy=none --include_path="D:/ti/ccs2011/ccs/ccs_base/msp430/include" --include_path="C:/Users/Brady/workspace_ccstheia/P2P_TX_RX" --include_path="C:/Users/Brady/workspace_ccstheia/P2P_TX_RX/GrLib/grlib" --include_path="C:/Users/Brady/workspace_ccstheia/P2P_TX_RX/GrLib/fonts" --include_path="D:/ti/ccs2011/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/include" --advice:power="none" --define=__MSP430G2553__ -g --gcc --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

WDTplus_init.obj: D:/ti/grace/P2P/grace/WDTplus_init.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"D:/ti/ccs2011/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/bin/cl430" -vmsp -O3 --use_hw_mpy=none --include_path="D:/ti/ccs2011/ccs/ccs_base/msp430/include" --include_path="C:/Users/Brady/workspace_ccstheia/P2P_TX_RX" --include_path="C:/Users/Brady/workspace_ccstheia/P2P_TX_RX/GrLib/grlib" --include_path="C:/Users/Brady/workspace_ccstheia/P2P_TX_RX/GrLib/fonts" --include_path="D:/ti/ccs2011/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/include" --advice:power="none" --define=__MSP430G2553__ -g --gcc --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


