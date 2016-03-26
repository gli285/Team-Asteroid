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
    int i;

    /* Initialize values contained in the packet */

    //Address from EEPROM
    G_Packet.address = /* EEPROM.read(2) | */ (EEPROM.read(3) << 8);
    G_Packet.uptime_ms = 0;
    G_Packet.n = 0;
    G_Packet.bmp085_temp_decic = 0;
    G_Packet.bmp085_press_pa = 0;
    G_Packet.humidity_centi_pct = 0;

    /* Clear data with arrays */
    for(i = 0; i < 4; i++)
    {
        G_Packet.batt_mv[i] = 0;
        G_Packet.panel_mv[i] = 0;
        G_Packet.apogee_w_m2[i] = 0;
    }
}

void Packet_Construct()
{
    /* Set schema */
    G_Packet.schema = 86;

    /* Index Variable */
    int n = G_Packet.n;

    /* Variables to hold Sensor Readings */
    unsigned long uptime;

    /* Update data */
    uptime = millis();

    /* Overflow */
    //G_Packet.overflow_num += chk_overflow(uptime, G_Packet.uptime_ms);

    /* Save uptime */
    G_Packet.uptime_ms = uptime;

    /* Sensor data */
    /* Hard Coded packet test */
    G_Packet.batt_mv[n] = 1; 
    G_Packet.panel_mv[n] = 2;
    G_Packet.bmp085_press_pa = 10;
    G_Packet.bmp085_temp_decic = 20;
    G_Packet.humidity_centi_pct = 30;
    G_Packet.apogee_w_m2[n] = 40;

/* 
    G_Packet.batt_mv[n] = BatterymV;
    G_Packet.panel_mv[n] = PanelmV;
    G_Packet.bmp085_press_pa = Sensors_samplePressurepa();
    G_Packet.bmp085_temp_decic = Sensors_sampleTemperaturedecic();
    G_Packet.humidity_centi_pct = Sensors_sampleHumiditypct();
    G_Packet.apogee_w_m2[n] = Sensors_sampleSolarIrrmV();
*/
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
    //ZBTxStatusResponse txStatus = ZBTxStatusResponse();

    /* Packet to be transmitted */
    uint8_t payload[MAX_SIZE];

    /* Clear the payload */
    memset(payload, '\0', sizeof(payload));

    /* Get length of packet */
    len = sizeof(G_Packet);

    /* ********** DEBUG ********* */
    //Serial.println(F("BIN Length is: "));
    //Serial.print(len);

    /* Transfer information into payload */
    memcpy(payload, &G_Packet, len);

    ZBTxRequest zbTx = ZBTxRequest(addr64, payload, len);
    xbee.send(zbTx);
}

