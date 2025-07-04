#include <msp430.h>
#include <stdlib.h>
#include "LoRa_P2P.h"
#include "sys_setup.h"

int main(void)
{
    unsigned char sensor_connection;
    
    init_sys();
    init_p2p();
    P1OUT |= LED1;
    get_id();

    while(1){

        send_packet("6270000C", "txt", " CHECK COMMUNICATION");
        if (check_response("6270000C")){
            send_packet(" FROM 6270000C: ", "txt", decoded_message);
            free(decoded_message);
            sensor_connection = 1;
        }
        else{
            send_packet(" CAN NOT REACH 6270000C", "txt", "");
            sensor_connection = 0;
        }

        __delay_cycles(2000000);

        while(sensor_connection){
            send_packet("6270000C", "txt", " READ SENSOR");
            if (check_response("6270000C")){
                send_packet(" FROM 6270000C: ", "txt", decoded_message);
                free(decoded_message);
            }
            else{
                send_packet(" CAN NOT REACH 6270000C", "txt", "");
                sensor_connection = 0;
            }
            __delay_cycles(2000000);
        }      
    }
}
