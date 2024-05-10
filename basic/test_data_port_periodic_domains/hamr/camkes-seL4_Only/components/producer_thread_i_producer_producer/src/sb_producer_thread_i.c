// Do not edit this file as it will be overwritten if HAMR codegen is rerun

#include <sb_producer_thread_i.h>
#include <string.h>
#include <camkes.h>

void sb_entrypoint_period_producer_thread_i(int64_t *in_arg) {
  compute((int64_t *) in_arg);
}

seqNum_t sb_write_port_seqNum;

bool sb_write_port_write(const int8_t * value) {
  return write_sp_int8_t(sb_write_port, value, &sb_write_port_seqNum);
}

/************************************************************************
 *  sb_entrypoint_producer_thread_i_producer_producer_initializer:
 *
 * This is the function invoked by an active thread dispatcher to
 * call to a user-defined entrypoint function.  It sets up the dispatch
 * context for the user-defined entrypoint, then calls it.
 *
 ************************************************************************/
void sb_entrypoint_producer_thread_i_producer_producer_initializer(const int64_t * in_arg) {
  init((int64_t *) in_arg);
}

void pre_init(void) {
  // initialise data structure for data port write_port
  init_sp_int8_t(sb_write_port, &sb_write_port_seqNum);
}

/************************************************************************
 * int run(void)
 * Main active thread function.
 ************************************************************************/
int run(void) {
  {
    int64_t sb_dummy;
    sb_entrypoint_producer_thread_i_producer_producer_initializer(&sb_dummy);
  }
  sb_self_pacer_tick_emit();
  for(;;) {
    sb_self_pacer_tock_wait();
    {
      int64_t sb_dummy = 0;
      sb_entrypoint_period_producer_thread_i(&sb_dummy);
    }
    sb_self_pacer_tick_emit();
  }
  return 0;
}