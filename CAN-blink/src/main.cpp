#include "WProgram.h"
#include "logger.h"
#include <can_adapter.h>
#include "Blink_CAN_adapter.h"

bool g_is_receiver = false;

int main()
{
  
  //Set up resources:
  initialize_logging(DEBUG);
  initialize_can();
  
  if (g_is_receiver)
    {
      //If we're a receiver, register the Blink_CAN_adapter callback.
      Blink_CAN_adapter adapter;
      adapter.initialize();
      
      register_callback(&Blink_CAN_adapter::Blink_can_callback, &adapter, 400);
  
      //Start the can listener. Blocking call.
      start_listener();
    }
  const int LED = 13;
  //If we aren't a receiver, we're a transmitter.
  pinMode(LED, OUTPUT);
  //Build the stuff in the message that doesn't change (ID, length, etc)
  CAN_message_t msg;
  msg.id = 0;
  msg.len = 1;
  msg.timeout = 10000;
  //Send out CAN messages with alternating 1's and zeros.
  while (true)
    {
      msg.buf[0] = 1;
      digitalWrite(LED, HIGH);
      can_write(msg);
      delay(500);
      msg.buf[0] = 0;
      digitalWrite(LED, LOW);
      can_write(msg);
      delay(500);
    }
}
