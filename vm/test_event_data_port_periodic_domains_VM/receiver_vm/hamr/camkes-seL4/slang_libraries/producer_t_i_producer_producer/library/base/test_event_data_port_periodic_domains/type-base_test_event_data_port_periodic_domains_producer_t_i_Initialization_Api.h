#ifndef SIREUM_TYPE_H_base_test_event_data_port_periodic_domains_producer_t_i_Initialization_Api
#define SIREUM_TYPE_H_base_test_event_data_port_periodic_domains_producer_t_i_Initialization_Api

#ifdef __cplusplus
extern "C" {
#endif

#include <misc.h>

// base.test_event_data_port_periodic_domains.producer_t_i_Initialization_Api
#include <type-art_Art_BridgeId.h>
#include <type-art_Art_PortId.h>

typedef struct base_test_event_data_port_periodic_domains_producer_t_i_Initialization_Api *base_test_event_data_port_periodic_domains_producer_t_i_Initialization_Api;
struct base_test_event_data_port_periodic_domains_producer_t_i_Initialization_Api {
  TYPE type;
  art_Art_BridgeId id;
  art_Art_PortId write_port_Id;
};

#define DeclNewbase_test_event_data_port_periodic_domains_producer_t_i_Initialization_Api(x) struct base_test_event_data_port_periodic_domains_producer_t_i_Initialization_Api x = { .type = Tbase_test_event_data_port_periodic_domains_producer_t_i_Initialization_Api }

#ifdef __cplusplus
}
#endif

#endif