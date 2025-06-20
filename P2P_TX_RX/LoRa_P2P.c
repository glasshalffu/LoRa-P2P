#include <msp430.h>
// #include <string.h>
// #include <stdlib.h>
#include "LoRa_P2P.h"

// volatile char incoming_msg[512];
// volatile char RXdone = 'N';

// struct RF_parameters 
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
// };

void AT_send(char *cmd)
{
    unsigned int i = 0;
    // RXdone = 'N';
    // memset(incoming_msg, '\0', sizeof(char)*512);
    while (cmd[i]) 
    {
        while (UCA0STAT & UCBUSY); // Wait if UART is busy
        UCA0TXBUF = cmd[i];    // Send character
        i++;
    }
    // while(RXdone == 'N');
}

// char *make_RFCFG(RF_parameters *parms)
// {
//     char *base_cmd = "AT+TEST=RFCFG";
//     char *RFCFG = NULL;
//     size_t total_char = 0;

//     if (parms != NULL) {
//         if (parms->freq != NULL) total_char += strlen(parms->freq);
//         if (parms->sf != NULL) total_char += strlen(parms->sf);
//         if (parms->bw != NULL) total_char += strlen(parms->bw);
//         if (parms->txpr != NULL) total_char += strlen(parms->txpr);
//         if (parms->rxpr != NULL) total_char += strlen(parms->rxpr);
//         if (parms->pow != NULL) total_char += strlen(parms->pow);
//         if (parms->crc != NULL) total_char += strlen(parms->crc);
//         if (parms->iq != NULL) total_char += strlen(parms->iq);
//         if (parms->pnet != NULL) total_char += strlen(parms->pnet);
//     }

//     total_char += strlen(base_cmd);
//     total_char += 12;

//     RFCFG = malloc(total_char);
//     RFCFG[0] = '\0';

//     strcat(RFCFG, base_cmd);
//     strcat(RFCFG, ',');
//     strcat(RFCFG, parms->freq);
//     strcat(RFCFG, ',');
//     strcat(RFCFG, parms->sf);
//     strcat(RFCFG, ',');
//     strcat(RFCFG, parms->bw);
//     strcat(RFCFG, ',');
//     strcat(RFCFG, parms->txpr);
//     strcat(RFCFG, ',');
//     strcat(RFCFG, parms->rxpr);
//     strcat(RFCFG, ',');
//     strcat(RFCFG, parms->pow);
//     strcat(RFCFG, ',');
//     strcat(RFCFG, parms->crc);
//     strcat(RFCFG, ',');
//     strcat(RFCFG, parms->iq);
//     strcat(RFCFG, ',');
//     strcat(RFCFG, parms->pnet);

//     RFCFG[total_char - 3] = '\r';
//     RFCFG[total_char - 2] = '\n';
//     RFCFG[total_char - 1] = '\0';

//     return RFCFG;
// }

// void check_local_stat()
// {
//     AT_send("AT+VDD\r\n");
//     while(RXdone == 'N');

//     AT_send("AT+TEMP\r\n");
//     while(RXdone == 'N');
    
// }

// void setup_TX(char *cmd)
// {
//     AT_send("AT+MODE=TEST\r\n");
//     while(RXdone == 'N');
//     AT_send(cmd);
//     while(RXdone == 'N');
// }

void reset()
{
    P2OUT &= ~BIT0;
    __delay_cycles(100000);
    P2OUT |= BIT0;
}

