// Do not edit this file as it will be overwritten if HAMR codegen is rerun

#include <sb_T2_i.h>
#include <string.h>
#include <camkes.h>

void sb_entrypoint_period_T2_i(int64_t *in_arg) {
  compute((int64_t *) in_arg);
}

seqNum_t sb_write_port_seqNum;

seqNum_t sb_read_port_seqNum;

/*****************************************************************
 * sb_read_port_is_empty:
 *
 * Helper method to determine if the data infrastructure port has
 * received data
 *
 ****************************************************************/
bool sb_read_port_is_empty() {
  return is_empty_sp_int8_t(sb_read_port);
}

bool sb_read_port_read(int8_t * value) {
  seqNum_t new_seqNum;
  if ( read_sp_int8_t(sb_read_port, value, &new_seqNum) ) {
    sb_read_port_seqNum = new_seqNum;
    return true;
  } else {
    return false;
  }
}

bool sb_write_port_write(const int8_t * value) {
  return write_sp_int8_t(sb_write_port, value, &sb_write_port_seqNum);
}

/************************************************************************
 *  sb_entrypoint_T2_i_p2_t2_initializer:
 *
 * This is the function invoked by an active thread dispatcher to
 * call to a user-defined entrypoint function.  It sets up the dispatch
 * context for the user-defined entrypoint, then calls it.
 *
 ************************************************************************/
void sb_entrypoint_T2_i_p2_t2_initializer(const int64_t * in_arg) {
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
    sb_entrypoint_T2_i_p2_t2_initializer(&sb_dummy);
  }
  sb_pacer_notification_wait();
  for(;;) {
    sb_pacer_notification_wait();
    {
      int64_t sb_dummy = 0;
      sb_entrypoint_period_T2_i(&sb_dummy);
    }
  }
  return 0;
}
