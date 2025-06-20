#ifndef LORA_P2P_H
#define LORA_P2P_H

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

void AT_send(char *message);
// char *make_RFCFG(RF_parameters *parms);
// void check_local_stat();
// void setup_TX(char *cmd);
void reset();


#endif
