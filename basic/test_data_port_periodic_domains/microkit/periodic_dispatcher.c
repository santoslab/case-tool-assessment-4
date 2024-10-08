#include <stdint.h>
#include <microkit.h>
#include "include/printf.h"

#define PORT_TO_PRODUCER 1
#define PORT_TO_CONSUMER 2
#define PORT_TO_END_OF_SCHEDULE_PING 3

#define PORT_FROM_END_OF_SCHEDULE_PING 4

void pingComponents(){
  microkit_notify(PORT_TO_PRODUCER);
  microkit_notify(PORT_TO_CONSUMER);
  microkit_notify(PORT_TO_END_OF_SCHEDULE_PING);
}

void init(void) {
  pingComponents();
}

void notified(microkit_channel channel) {
  switch(channel) {
    case PORT_FROM_END_OF_SCHEDULE_PING:
      pingComponents();
    break;
  }
}
