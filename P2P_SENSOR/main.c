#include <msp430.h>
#include "LoRa_P2P.h"
#include "sys_setup.h"


int main(void)
{
    init_sys();
    init_p2p();
    P1OUT |= LED1;
    get_id();

    while(1){
        if (!wait_packet("627007C6")){
            generate_response("627007C6");
        }
    }
}
