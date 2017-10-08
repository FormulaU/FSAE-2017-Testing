#include "Blink_CAN_adapter.h"
#include "WProgram.h"
#include <logger.h>
#include <cstdio>
#include <sstream>

static const int LED = 13; //Blink LED

void Blink_CAN_adapter::initialize()
{
  //Set the LED pin to output
  pinMode(13, OUTPUT);
}

void Blink_CAN_adapter::Blink_can_callback(CAN_message_t msg, void* ctx)
{
  
  if (msg.buf[0] == 1)
    {
      digitalWriteFast(LED, HIGH);
      FSAE_log(DEBUG, "LED ON");
    }
  else if (msg.buf[0] == 0)
    {
      digitalWriteFast(LED, LOW);
      FSAE_log(DEBUG, "LED OFF");
    }
}
