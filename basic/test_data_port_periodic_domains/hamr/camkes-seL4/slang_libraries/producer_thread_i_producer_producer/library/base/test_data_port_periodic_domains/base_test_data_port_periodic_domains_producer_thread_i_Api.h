#ifndef SIREUM_H_base_test_data_port_periodic_domains_producer_thread_i_Api
#define SIREUM_H_base_test_data_port_periodic_domains_producer_thread_i_Api

#ifdef __cplusplus
extern "C" {
#endif

#include <types.h>

// base.test_data_port_periodic_domains.producer_thread_i_Api

#define base_test_data_port_periodic_domains_producer_thread_i_Api__eq(this, other) Type__eq(this, other)
#define base_test_data_port_periodic_domains_producer_thread_i_Api__ne(this, other) (!Type__eq(this, other))
#define base_test_data_port_periodic_domains_producer_thread_i_Api__equiv(this, other) Type__equiv(this, other)
#define base_test_data_port_periodic_domains_producer_thread_i_Api__inequiv(this, other) (!Type__equiv(this, other))
#define base_test_data_port_periodic_domains_producer_thread_i_Api_cprint(this, isOut) Type_cprint(this, isOut)
B base_test_data_port_periodic_domains_producer_thread_i_Api__is(STACK_FRAME void *this);
base_test_data_port_periodic_domains_producer_thread_i_Api base_test_data_port_periodic_domains_producer_thread_i_Api__as(STACK_FRAME void *this);
inline void base_test_data_port_periodic_domains_producer_thread_i_Api_string_(STACK_FRAME String result, base_test_data_port_periodic_domains_producer_thread_i_Api this) {
  Type_string_(CALLER result, this);
}

Unit base_test_data_port_periodic_domains_producer_thread_i_Initialization_Api_logInfo_(STACK_FRAME base_test_data_port_periodic_domains_producer_thread_i_Initialization_Api this, String msg);

Unit base_test_data_port_periodic_domains_producer_thread_i_Initialization_Api_logDebug_(STACK_FRAME base_test_data_port_periodic_domains_producer_thread_i_Initialization_Api this, String msg);

Unit base_test_data_port_periodic_domains_producer_thread_i_Initialization_Api_logError_(STACK_FRAME base_test_data_port_periodic_domains_producer_thread_i_Initialization_Api this, String msg);

Unit base_test_data_port_periodic_domains_producer_thread_i_Operational_Api_logInfo_(STACK_FRAME base_test_data_port_periodic_domains_producer_thread_i_Operational_Api this, String msg);

Unit base_test_data_port_periodic_domains_producer_thread_i_Operational_Api_logDebug_(STACK_FRAME base_test_data_port_periodic_domains_producer_thread_i_Operational_Api this, String msg);

Unit base_test_data_port_periodic_domains_producer_thread_i_Operational_Api_logError_(STACK_FRAME base_test_data_port_periodic_domains_producer_thread_i_Operational_Api this, String msg);

Unit base_test_data_port_periodic_domains_producer_thread_i_Initialization_Api_put_write_port_(STACK_FRAME base_test_data_port_periodic_domains_producer_thread_i_Initialization_Api this, S8 value);

Unit base_test_data_port_periodic_domains_producer_thread_i_Operational_Api_put_write_port_(STACK_FRAME base_test_data_port_periodic_domains_producer_thread_i_Operational_Api this, S8 value);

#ifdef __cplusplus
}
#endif

#endif