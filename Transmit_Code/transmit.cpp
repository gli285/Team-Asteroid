/* transmit.cpp */

/* Program Libraries */
#include "transmit.h"

/* External Librarires */
#include <EEPROM.h>
#include <XBee.h>

/* Clear the packet */
void Packet_Clear()
{
    /* Variables used for indexes */
    int i, j, k;

    /* Address from EEPROM */
    G_Packet.address = (EEPROM.read(3) << 8);
    G_Packet.uptime_ms = 0;
    G_Packet.bmp085_temp_decic = 0;
    G_Packet.bmp085_press_pa = 0;
    G_Packet.humidity_centi_pct = 0;

    /* Clear data with arrays */
    for(i = 0; i < 60; i++)
    {
        j = i/10;
        k = i/3;
        
        G_Packet.batt_mv[j] = 0;
        G_Packet.panel_mv[j] = 0;
        G_Packet.apogee_w_m2[k] = 0;
    }
}

void Packet_Construct()
{
    int j, k;
    
    /* Variables to hold Sensor Readings */
    unsigned long uptime;

    /* Update data */
    uptime = millis();

    /* Save uptime */
    G_Packet.uptime_ms = uptime;

    /* Sensor data */
    for(int i = 0; i < 60; i++)
    {
      j = i/10;
      k = i/3;
      
      G_Packet.batt_mv[j] = Sensors_sampleBatterymV();
      G_Packet.panel_mv[j] = Sensors_samplePanelmV(); 
      G_Packet.apogee_w_m2[k] = Sensors_sampleSolarIrrmV();
    }
    G_Packet.humidity_centi_pct = Sensors_sampleHumiditypct();
    G_Packet.bmp085_press_pa = Sensors_samplePressurepa();
    G_Packet.bmp085_temp_decic = Sensors_sampleTemperaturedecic();
    
}

void Packet_Transmit()
{
    /* Create Xbee object */
    XBee xbee = XBee();

    /* Variable to contain length */
    int len = 0;

    /* Obtain address of receiving end */
    XBeeAddress64 addr64 = XBeeAddress64(0x0,0x0);
    ZBTxStatusResponse txStatus = ZBTxStatusResponse();

    /* Packet to be transmitted */
    uint8_t payload[MAX_SIZE];

    /* Clear the payload */
    memset(payload, '\0', sizeof(payload));

    /* Get length of packet */
    len = sizeof(G_Packet);

    /* Transfer information into payload */
    memcpy(payload, &G_Packet, len);

    ZBTxRequest zbTx = ZBTxRequest(addr64, payload, len);
    xbee.send(zbTx);
}

