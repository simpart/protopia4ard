/**
 * @file ether/dump.c
 * @author simpart
 */
#include <stdio.h>
#include <string.h>
#include "Arduino.h"
#include "pia/com.h"
#include "pia/eth.h"

/*** function ***/
void pia_eth_dump(uint8_t *rcv) {
    uint16_t     type = 0;
    pia_ethhdr_t *eth_hdr;
    char         str[128];
    
    if (NULL == rcv) {
        //printf("parameter is null\n");
        return;
    }
    eth_hdr = (pia_ethhdr_t *) rcv;
    
    Serial.println("Ether Header");
    Serial.println("—————————————————");
    snprintf( 
        (char *) &str[0],
        128,
        "dest mac   : %02x-%02x-%02x-%02x-%02x-%02x",
        eth_hdr->dmac[0],
        eth_hdr->dmac[1],
        eth_hdr->dmac[2],
        eth_hdr->dmac[3],
        eth_hdr->dmac[4],
        eth_hdr->dmac[5]
    );
    Serial.println(str);

    snprintf(
        &str[0],
        128,
        "src mac    : %02x-%02x-%02x-%02x-%02x-%02x",
        eth_hdr->smac[0],
        eth_hdr->smac[1],
        eth_hdr->smac[2],
        eth_hdr->smac[3],
        eth_hdr->smac[4],
        eth_hdr->smac[5]
    );
    Serial.println(str);
    
    memcpy(&type, &eth_hdr->type, sizeof(uint16_t));
    type = pia_ntohs(type);
    snprintf(
        &str[0],
        128,
        "ether type : %u(0x%x)",
        type,
        type
    );
    Serial.println(str);
}
/* end of file */
