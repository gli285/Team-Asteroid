/* transmit.cpp */

#include "transmit.h"

void Packet_Clear()
{
    /* Variables used for indexes */
    int i, j, k;

    /* Initialize values contained in the packet */

    //Address from EEPROM
    G_Packet.address = EEPROM.read(2) | (EEPROM.read(3) << 8);
    G_Packet.uptime_ms = 0;
    G_Packet.n = 0;
    G_Packet.bmp085_temp_decic = 0;
    G_Packet.bmp085_press_pa = 0;
    G_Packet.humidity_centi_pct = 0;

    /* Clear data with arrays */
    for(i = 0; i < 60; i++)
    {
        j = i/4;

        G_Packet.batt_mv[j] = 0;
        G_Packet.panel_mv[j] = 0;

        G_Packet.apogee_w_m2[i] = 0;
    }
}

void Packet_Construct()
{
    /* Index Variable */
    int n = G_Packet.n;

    /* Variables to hold Sensor Readings */
    long BatterymV = 0;
    long Pressurepa = 0;
    long Humiditypct = 0; 
    long PanelmV = 0;
    long SolarIrrmV = 0;
    long Tempdecic = 0;
    unsigned long uptime;

    /* Update data */
    uptime = millis();

    /* Overflow */
    //G_Packet.overflow_num += chk_overflow(uptime, G_Packet.uptime_ms);

    /* Save uptime */
    G_Packet.uptime_ms = uptime;

    /* Sensor data */
    G_Packet.batt_mv[n/4] = BatterymV;
    G_Packet.panel_mv[n/4] = PanelmV;
    G_Packet.bmp085_press_pa = Pressurepa;
    G_Packet.bmp085_temp_decic = Tempdecic;
    G_Packet.humidity_centi_pct = Humiditypct;
    G_Packet.apogee_w_m2[n] = SolarIrrmV;

    G_Packet.n += 1;
}

void Packet_Transmit()
{
    /* Create Xbee object */
    XBee xbee = XBee();

    /* Variable to contain length */
    int len = 0;

    /* Obtain address of receiving end */
    XBeeAddress64 addr64 = XBeeAddress64(0,0);

    /* Packet to be transmitted */
    uint8_t payload[MAX_SIZE];

    /* Clear the payload */
    memset(payload, '/0', sizeof(payload));

    /* Get length of packet */
    len = sizeof(G_Packet);

    /* ********** DEBUG ********* */
    Serial.println(F("BIN Length is: "));
    Serial.print(len);

    /* Transfer information into payload */
    memcpy(payload, &G_Packet, len);

    ZBTxRequest zbTx = ZBTxRequest(addr64, payload, len);
    xbee.send(zbTx);
}

