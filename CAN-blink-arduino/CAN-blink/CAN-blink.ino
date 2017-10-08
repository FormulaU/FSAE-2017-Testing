//#define receive_CAN 0
#define transmit_CAN 0
#ifdef transmit_CAN//-------------TRANSMITTER -------------------

#include <FlexCAN.h>
#include <kinetis_flexcan.h>
CAN_message_t msgOn;
CAN_message_t msgOff;

void setup() {
  Can0.begin();
  Serial.begin(9600);

  msgOn.len = 1;
  msgOn.id = 1;
  msgOn.buf[0]= 1;

  msgOff.len = 1;
  msgOff.id = 1;
  msgOff.buf[0]= 0;
}

void loop() {
  Can0.write(msgOn);
  delay(500);
  Can0.write(msgOff);
  delay(500);
}
#endif
#ifdef receive_CAN//-------------RECEIVER -------------------

#include <FlexCAN.h>
CAN_message_t rxmsg;

void setup() {
  Can0.begin();
  pinMode(LED_BUILTIN,OUTPUT);    // LED
  Serial.begin(9600);
}

void loop() {
  if (Can0.read(rxmsg)){
    digitalWrite(LED_BUILTIN, rxmsg.buf[0]); //blink LED
    Serial.println(1);
  }
  delay(10);
}
#endif
