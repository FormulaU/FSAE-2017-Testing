#ifndef BLINK_CAN_ADAPTER_H
#define BLINK_CAN_ADAPTER_H

#include <can_adapter.h>
class Blink_CAN_adapter
{
 public:
  //Initializes the CAN adapter.
  void initialize();
  //The callback that sets the LED according to the CAN message received.
  static void Blink_can_callback(CAN_message_t msg, void* ctx);
};
#endif //BLINK_CAN_ADAPTER_H
