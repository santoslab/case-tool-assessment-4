// Do not edit this file as it will be overwritten if HAMR codegen is rerun

#ifndef SB_CONSUMER_T_I_H
#define SB_CONSUMER_T_I_H

#include <sb_types.h>

bool sb_read_port_dequeue(int8_t *);

void compute(const int64_t * in_arg);

void init(const int64_t *arg);

#endif // SB_CONSUMER_T_I_H
