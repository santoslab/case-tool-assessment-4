#include <stdint.h>
#include <microkit.h>
#include "include/printf.h"

volatile uint8_t *to_consumer_vaddr;

#define PORT_FROM_PERIODIC_DISPATCHER 1

int counter = 0;

void init(void) {
  printf("%s: Init\n", microkit_name);
  counter = 0;
  *((int*) to_consumer_vaddr) = counter;
}

void notified(microkit_channel channel) {
  switch(channel) {
    case PORT_FROM_PERIODIC_DISPATCHER:

      *((int*) to_consumer_vaddr) = ++counter;

      printf("%s: Sent %i \n", microkit_name, counter);

      break;
  }

}
