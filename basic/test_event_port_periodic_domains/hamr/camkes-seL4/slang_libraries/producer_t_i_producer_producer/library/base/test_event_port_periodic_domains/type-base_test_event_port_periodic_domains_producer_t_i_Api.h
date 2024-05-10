#ifndef SIREUM_TYPE_H_base_test_event_port_periodic_domains_producer_t_i_Api
#define SIREUM_TYPE_H_base_test_event_port_periodic_domains_producer_t_i_Api

#ifdef __cplusplus
extern "C" {
#endif

#include <misc.h>

// base.test_event_port_periodic_domains.producer_t_i_Api

#include <type-base_test_event_port_periodic_domains_producer_t_i_Initialization_Api.h>
#include <type-base_test_event_port_periodic_domains_producer_t_i_Operational_Api.h>

typedef union base_test_event_port_periodic_domains_producer_t_i_Api *base_test_event_port_periodic_domains_producer_t_i_Api;
union base_test_event_port_periodic_domains_producer_t_i_Api {
  TYPE type;
  struct base_test_event_port_periodic_domains_producer_t_i_Initialization_Api base_test_event_port_periodic_domains_producer_t_i_Initialization_Api;
  struct base_test_event_port_periodic_domains_producer_t_i_Operational_Api base_test_event_port_periodic_domains_producer_t_i_Operational_Api;
};

#define DeclNewbase_test_event_port_periodic_domains_producer_t_i_Api(x) union base_test_event_port_periodic_domains_producer_t_i_Api x = { 0 }

#ifdef __cplusplus
}
#endif

#endif