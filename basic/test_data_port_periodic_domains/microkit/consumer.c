#include <stdint.h>
#include <microkit.h>
#include "include/printf.h"

volatile uint8_t *from_producer_vaddr;

#define PORT_FROM_PERIODIC_DISPATCHER 2

void init(void) {
  printf("%s: Init\n", microkit_name);
}

void notified(microkit_channel channel) {
  switch(channel) {
    case PORT_FROM_PERIODIC_DISPATCHER: {

      int value = (int) *from_producer_vaddr; 

      printf("%s: Received %i\n", microkit_name, value);

      break;
    }
  }
}
