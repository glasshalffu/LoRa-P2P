#include <msp430.h>
#include "sys_setup.h"
// #include <ds18b20.h>
// #include <HAL_MSP430.h>

void init_sys(void)
{
    WDTCTL = WDTPW | WDTHOLD;
    init_gpio();
    init_clock();
    init_uart();
    // ds18b20_init_pins();
    // DS18B20_PORT_OUT |= DS18B20_POWER_PIN;
    do
    {
        // Clear OSC fault flag
        IFG1 &= ~OFIFG;
        // 50us delay
        __delay_cycles(50);
    } while (IFG1 & OFIFG);

    IFG2 &= ~(UCA0RXIFG);
    IE2 |= UCA0RXIE;
    __bis_SR_register(GIE);
}

void init_gpio(void)
{
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
    P2DIR = BIT0 | BIT1 | BIT2 | BIT3 | BIT4 | BIT5 | BIT6 | BIT7;

    /* Port 2 Resistor Enable Register */
    P2REN = BIT0;

    /* Port 2 Interrupt Edge Select Register */
    P2IES = 0;

    /* Port 2 Interrupt Flag Register */
    P2IFG = 0;
}

void init_clock(void)
{
    BCSCTL2 = SELM_0 | DIVM_0 | DIVS_0;

    if (CALBC1_1MHZ != 0xFF) {
        DCOCTL = 0x00;
        BCSCTL1 = CALBC1_1MHZ;      /* Set DCO to 1MHz */
        DCOCTL = CALDCO_1MHZ;
    }

    BCSCTL1 |= XT2OFF | DIVA_0;
    BCSCTL3 = XT2S_0 | LFXT1S_2 | XCAP_1;
}

void init_uart(void)
{
    /* Disable USCI */
    UCA0CTL1 |= UCSWRST;

    UCA0CTL1 = UCSSEL_2 | UCSWRST;
    UCA0MCTL = UCBRF_0 | UCBRS_1;
    /* Baud rate control register 0 */
    UCA0BR0 = 104;
    /* Enable USCI */
    UCA0CTL1 &= ~UCSWRST;
}

