#include <stdint.h>
#include <microkit.h>
#include "include/printf.h"

#define PORT_FROM_PERIODIC_DISPATCHER 3

#define PORT_TO_PERIODIC_DISPATCHER 4

void init(void) {
}

void notified(microkit_channel channel) {
  switch(channel) {
    case PORT_FROM_PERIODIC_DISPATCHER:
      microkit_notify(PORT_TO_PERIODIC_DISPATCHER);
    break;
  }
}
