#ifndef SIREUM_TYPE_H_base_Base_Types_Boolean_Payload
#define SIREUM_TYPE_H_base_Base_Types_Boolean_Payload

#ifdef __cplusplus
extern "C" {
#endif

#include <misc.h>

// base.Base_Types.Boolean_Payload

typedef struct base_Base_Types_Boolean_Payload *base_Base_Types_Boolean_Payload;
struct base_Base_Types_Boolean_Payload {
  TYPE type;
  B value;
};

#define DeclNewbase_Base_Types_Boolean_Payload(x) struct base_Base_Types_Boolean_Payload x = { .type = Tbase_Base_Types_Boolean_Payload }

#ifdef __cplusplus
}
#endif

#endif