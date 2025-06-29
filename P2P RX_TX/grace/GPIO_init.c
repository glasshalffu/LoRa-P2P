/*
 *  This file is automatically generated and does not require a license
 *
 *  ==== WARNING: CHANGES TO THIS GENERATED FILE WILL BE OVERWRITTEN ====
 *
 *  To make changes to the generated code, use the space between existing
 *      "USER CODE START (section: <name>)"
 *  and
 *      "USER CODE END (section: <name>)"
 *  comments, where <name> is a single word identifying the section.
 *  Only these sections will be preserved.
 *
 *  Do not move these sections within this file or change the START and
 *  END comments in any way.
 *  ==== ALL OTHER CHANGES WILL BE OVERWRITTEN WHEN IT IS REGENERATED ====
 *
 *  This file was generated from
 *      D:/ti/grace/grace_2_20_02_32/packages/ti/mcu/msp430/csl/gpio/GPIO_init.xdt
 */
#include <msp430.h>

/* USER CODE START (section: GPIO_init_c_prologue) */
/* User defined includes, defines, global variables and functions */
/* USER CODE END (section: GPIO_init_c_prologue) */

/*
 *  ======== GPIO_graceInit ========
 *  Initialize MSP430 General Purpose Input Output Ports
 *
 *  The GPIO registers should be set in a specific order:
 *     PxOUT
 *     PxSEL or PxSELx
 *     PxDIR
 *     PxREN
 *     PxIES
 *     PxIFG
 *     PxIE
 *
 *     This will ensure that:
 *         - IFG doesn't get set by manipulating the pin function, edge
 *           select, and pull-up/down resistor functionalities (see
 *           Section 8.2.6 of the MSP430 User's manual)
 *         - Glitch-free setup (configuring the OUT register _before_
 *           setting the pin direction)
 *         - Pull-up/pull-down resistor enable with the correct direction
 *           (.up. vs. .down.)
 */
void GPIO_graceInit(void)
{
    /* USER CODE START (section: GPIO_graceInit_prologue) */
    /* User initialization code */
    /* USER CODE END (section: GPIO_graceInit_prologue) */

    /* Port 1 Port Select 2 Register */
    P1SEL2 = BIT1 | BIT2;

    /* Port 1 Output Register */
    P1OUT = 0;

    /* Port 1 Port Select Register */
    P1SEL = BIT1 | BIT2;

    /* Port 1 Direction Register */
    P1DIR = BIT0 | BIT3 | BIT4 | BIT5 | BIT6 | BIT7;

    /* Port 1 Interrupt Edge Select Register */
    P1IES = 0;

    /* Port 1 Interrupt Flag Register */
    P1IFG = 0;

    /* Port 2 Output Register */
    P2OUT = BIT0;

    /* Port 2 Port Select Register */
    P2SEL &= ~(BIT6 | BIT7);

    /* Port 2 Direction Register */
    P2DIR = BIT1 | BIT2 | BIT3 | BIT4 | BIT5 | BIT6 | BIT7;

    /* Port 2 Resistor Enable Register */
    P2REN = BIT0;

    /* Port 2 Interrupt Edge Select Register */
    P2IES = 0;

    /* Port 2 Interrupt Flag Register */
    P2IFG = 0;

    /* Port 3 Output Register */
    P3OUT = 0;

    /* Port 3 Direction Register */
    P3DIR = 0;

    /* USER CODE START (section: GPIO_graceInit_epilogue) */
    /* User code */
    /* USER CODE END (section: GPIO_graceInit_epilogue) */

}
