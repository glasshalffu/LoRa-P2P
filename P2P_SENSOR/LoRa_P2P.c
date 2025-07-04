#include <msp430.h>
#include <string.h>
#include <stdlib.h>
#include "LoRa_P2P.h"
#include "ds18b20.h"


volatile unsigned char message[BUFFER_SIZE];
volatile unsigned char rxdone;
unsigned char local_id[9];
char *decoded_message;


void send_at(const char *cmd, const char *response)
{
    const char *ptr = cmd;
    rxdone = 0;

    while(*ptr){
        while (UCA0STAT & UCBUSY); // Wait if UART is busy
        UCA0TXBUF = *ptr++;    // Send character
    }
 
    IE2 |= UCA0RXIE;
    while(!rxdone){};
    __delay_cycles(300000);

    if(strstr((const char*)message, response) == NULL){
        P1OUT &= ~LED1;
        while(1){
            P1OUT ^= LED2;
            __delay_cycles(500000);
        }
    }

}

void init_p2p(void)
{
    send_at("AT+MODE=TEST\r\n", "TEST");
    send_at("AT+TEST=RFCFG,868,SF7,125,12,15,14,ON,OFF,OFF\r\n", "RFCFG");
}

void get_id(void)
{
    const char *ptr = (const char *)message;
    unsigned short idx = 0;

    send_at("AT+ID=DevAddr\r\n", "DevAddr");
    while (*ptr != ','){
        ptr++;
    }

    while (*ptr != '\n'){
        if (*ptr != ' ' && *ptr != ':' && *ptr != ','){
            local_id[idx] = *ptr;
            idx++;
        }
        ptr++;
    }

    local_id[8] = '\0';
}

void send_packet(const char *target_id, const char *data_type, const char *data)
{
    memset((void *)message, '\0', sizeof(message));

    if (!strcmp(data_type, "txt")){
        strcpy((char*)message, "AT+TEST=TXLRSTR, \"");
        strcat((char*)message, target_id);
        strcat((char*)message, (const char*)local_id);
        strcat((char*)message, data);
        strcat((char*)message, "\"\r\n");
        P1OUT ^= LED1;
        __delay_cycles(15000);
        P1OUT ^= LED1;
        send_at((const char*)message, "DONE");
        memset((void *)message, '\0', sizeof(message));
    }
    else if (!strcmp(data_type, "hex")){
        strcpy((char*)message, "AT+TEST=TXLRPKT, \"");
        strcat((char*)message, target_id);
        strcat((char*)message, (const char*)local_id);
        strcat((char*)message, data);
        strcat((char*)message, "\"\r\n");
        P1OUT ^= LED1;
        __delay_cycles(15000);
        P1OUT ^= LED1;
        send_at((const char*)message, "DONE");
        memset((void *)message, '\0', sizeof(message));
    }
    else{
        P1OUT &= ~LED1;
        while(1){
            P1OUT ^= LED2;
            __delay_cycles(500000);
        }
    }

}

unsigned char check_response(const char *target_id)
{
    send_at("AT+TEST=RXLRPKT\r\n", "RX");
    __delay_cycles(900000);
    decoded_message = hex_to_string();
    if ((strstr((const char*)message, (const char*)local_id) != NULL &&  
    strstr((const char*)message, target_id) != NULL) ||
    (strstr((const char*)decoded_message, (const char*)local_id) != NULL &&
    strstr((const char*)decoded_message, target_id) != NULL))
    {
        P1OUT ^= LED1;
        __delay_cycles(15000);
        P1OUT ^= LED1;
        return 1;
    }
    else{
        free(decoded_message);
        return 0;
    }
}

char *hex_to_string (void)
{
    const char *ptr = (const char *)message;
    while (*ptr != '\"'){
        ptr++;
        if (*ptr == '\r'){
            return NULL;
        }
    }
    ptr += 1;
    unsigned short len = strlen(ptr) - 3;
    char *new_string = malloc(len / 2 + 1);
    unsigned short idx = 0;

    while (*ptr != '\"'){
        unsigned char byte_str[3] = {*ptr, *(ptr + 1), '\0'};
        new_string[idx] = (char)strtol((const char*)byte_str, NULL, 16);
        idx++;
        ptr += 2;
    }
    new_string[len / 2] = '\0';
    return &new_string[0];
}

unsigned char wait_packet(const char *target_id)
{
    send_at("AT+TEST=RXLRPKT\r\n", "RX");
    while (((strstr((const char*)message, target_id) == NULL) || 
    (strstr((const char*)message, (const char*)local_id) == NULL)) &&
    (strstr((const char*)message, "\"\r\n") == NULL));
    IE2 &= ~UCA0RXIE;
    P1OUT ^= LED1;
    __delay_cycles(15000);
    P1OUT ^= LED1;
    decoded_message = hex_to_string();
    if ((strstr((const char*)decoded_message, target_id) == NULL) || 
    (strstr((const char*)decoded_message, (const char*)local_id) == NULL)){
        free(decoded_message);
        return 1;
    }
    else{
        return 0;
    }
}

void generate_response(const char *target_id)
{   
    __delay_cycles(200000);
    if (strstr(decoded_message, "CHECK COMMUNICATION") != NULL && 
    strstr(decoded_message, "FROM") == NULL){
        free(decoded_message);
        send_packet(target_id, "txt", " OK");
    }
    else if (strstr(decoded_message, "READ SENSOR") != NULL && 
    strstr(decoded_message, "FROM") == NULL) {
        free(decoded_message);
        char temp_str[10] = {'\0'};
        char response[20] = {'\0'};
        get_temp(temp_str);
        strcat(response, " TEMP(Celsius) = ");
        strcat(response, temp_str);
        send_packet(target_id, "txt", response);
    }
    else{
        free(decoded_message);
        memset((void *)message, '\0', sizeof(message));

    }
}

void get_temp (char* temp_str)
{
    uint16_t raw = ds18b20_get_temp();
    int16_t raw_signed = (int16_t)raw;  // Handle negative temperatures
    int32_t hundredths;

    // Apply rounding during conversion to hundredths of a degree
    if (raw_signed >= 0) {
        hundredths = ((int32_t)raw_signed * 25 + 2) / 4;  // Positive rounding
    } else {
        hundredths = ((int32_t)raw_signed * 25 - 2) / 4;  // Negative rounding
    }

    char *p = temp_str;

    // Handle negative values
    if (hundredths < 0) {
        *p++ = '-';
        hundredths = -hundredths;
    }

    // Extract integer and fractional parts
    uint32_t value = (uint32_t)hundredths;
    uint32_t integer_part = value / 100;
    uint32_t fractional_part = value % 100;

    // Format integer part (1-3 digits)
    if (integer_part >= 100) {
        *p++ = '0' + integer_part / 100;
        integer_part %= 100;
        *p++ = '0' + integer_part / 10;
        *p++ = '0' + integer_part % 10;
    } else if (integer_part >= 10) {
        *p++ = '0' + integer_part / 10;
        *p++ = '0' + integer_part % 10;
    } else {
        *p++ = '0' + integer_part;
    }

    // Add decimal point and fractional part (always 2 digits)
    *p++ = '.';
    *p++ = '0' + fractional_part / 10;   // Tenths digit
    *p++ = '0' + fractional_part % 10;   // Hundredths digit
    *p = '\0';  // Null-terminate the string
}

void hard_reset()
{
    P2OUT &= ~BIT7;
    __delay_cycles(100000);
    P2OUT |= BIT7;
    __delay_cycles(3000000);
}

#pragma vector=USCIAB0RX_VECTOR
__interrupt void USCI0RX_ISR_HOOK(void)
{
    static unsigned short idx = 0;

    message[idx] = UCA0RXBUF;
    ++idx;

    if (UCA0RXBUF == 0x0A){
        rxdone = 1;
        message[idx] = '\0';
        idx = 0;
    }

    IFG2 &= ~UCA0RXIFG;
}
