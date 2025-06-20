/*
 * ======== Standard MSP430 includes ========
 */
#include <msp430.h>

/*
 * ======== Custom Library includes ========
 */
#include "LoRa_P2P.h"

// #define DEFAULT_RFCFG = {.freq = "866", .sf = "SF12", . bw = "125", .txpr = "12", .rxpr = "15", .pow = "14", .crc = "ON", .iq = "OFF", .pnet = "OFF"}

// typedef struct 
// {
//     char *freq; 
//     char *sf;
//     char *bw;
//     char *txpr;
//     char *rxpr;
//     char *pow;
//     char *crc;
//     char *iq;
//     char *pnet;
// } RF_parameters;

/*
 * ======== Grace related declaration ========
 */
extern void Grace_init(void);

/*
 *  ======== main ========
 */

#define LED2 0x40

int main( void )
{
    Grace_init();                // Activate Grace-generated configuration

    __delay_cycles(3000000);
    AT_send("AT+RESET\r\n");
    __delay_cycles(3000000);
    AT_send("AT+MODE=TEST\r\n");
    __delay_cycles(2000000);
    // AT_send("AT+TEST=?\r\n");
        // __delay_cycles(1000000);
    AT_send("AT+TEST=RFCFG,868,SF12,125,12,15,14,ON,OFF,OFF\r\n");
    __delay_cycles(2000000);



    while(1)
    {
        P1OUT ^= LED2;
        AT_send("AT+TEST=TXLRSTR, \"HiHi!\"\r\n");
        __delay_cycles(500000);
        P1OUT ^= LED2;
        __delay_cycles(1500000);
    }
}
