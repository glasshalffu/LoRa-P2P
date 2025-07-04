#ifndef LORA_P2P_H
#define LORA_P2P_H

#define BUFFER_SIZE 256
#define LED1 0x01
#define LED2 0x40

extern volatile unsigned char message[BUFFER_SIZE];
extern volatile unsigned char rxdone;
extern char *decoded_message;

void send_at(const char *cmd, const char* response);
void init_p2p(void);
void get_id(void);
void send_packet(const char *target_id, const char *data_type, const char *data);
unsigned char check_response(const char *target_id);
char *hex_to_string (void);
unsigned char wait_packet(const char *target_id);
void generate_response(const char *target_id);
void get_temp (char* temp_str);
void hard_reset(void);

#endif
