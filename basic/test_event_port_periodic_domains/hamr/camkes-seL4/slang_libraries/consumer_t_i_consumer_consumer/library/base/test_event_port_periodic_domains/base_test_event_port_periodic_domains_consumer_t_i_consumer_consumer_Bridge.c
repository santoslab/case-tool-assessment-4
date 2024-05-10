#include <all.h>

B base_test_event_port_periodic_domains_consumer_t_i_consumer_consumer_Bridge_initialized_ = F;

union Option_6288B6 _base_test_event_port_periodic_domains_consumer_t_i_consumer_consumer_Bridge_c_initialization_api;
union Option_FB1130 _base_test_event_port_periodic_domains_consumer_t_i_consumer_consumer_Bridge_c_operational_api;

void base_test_event_port_periodic_domains_consumer_t_i_consumer_consumer_Bridge_init(STACK_FRAME_ONLY) {
  if (base_test_event_port_periodic_domains_consumer_t_i_consumer_consumer_Bridge_initialized_) return;
  base_test_event_port_periodic_domains_consumer_t_i_consumer_consumer_Bridge_initialized_ = T;
  DeclNewStackFrame(caller, "consumer_t_i_consumer_consumer_Bridge.scala", "base.test_event_port_periodic_domains.consumer_t_i_consumer_consumer_Bridge", "<init>", 0);
  base_test_event_port_periodic_domains_consumer_t_i_consumer_consumer_Bridge_init_c_initialization_api(SF_LAST);
  base_test_event_port_periodic_domains_consumer_t_i_consumer_consumer_Bridge_init_c_operational_api(SF_LAST);
}

Option_6288B6 base_test_event_port_periodic_domains_consumer_t_i_consumer_consumer_Bridge_c_initialization_api(STACK_FRAME_ONLY) {
  base_test_event_port_periodic_domains_consumer_t_i_consumer_consumer_Bridge_init(CALLER_LAST);
  return (Option_6288B6) &_base_test_event_port_periodic_domains_consumer_t_i_consumer_consumer_Bridge_c_initialization_api;
}

void base_test_event_port_periodic_domains_consumer_t_i_consumer_consumer_Bridge_c_initialization_api_a(STACK_FRAME Option_6288B6 p_c_initialization_api) {
  base_test_event_port_periodic_domains_consumer_t_i_consumer_consumer_Bridge_init(CALLER_LAST);
  Type_assign(&_base_test_event_port_periodic_domains_consumer_t_i_consumer_consumer_Bridge_c_initialization_api, p_c_initialization_api, sizeof(union Option_6288B6));
}

Option_FB1130 base_test_event_port_periodic_domains_consumer_t_i_consumer_consumer_Bridge_c_operational_api(STACK_FRAME_ONLY) {
  base_test_event_port_periodic_domains_consumer_t_i_consumer_consumer_Bridge_init(CALLER_LAST);
  return (Option_FB1130) &_base_test_event_port_periodic_domains_consumer_t_i_consumer_consumer_Bridge_c_operational_api;
}

void base_test_event_port_periodic_domains_consumer_t_i_consumer_consumer_Bridge_c_operational_api_a(STACK_FRAME Option_FB1130 p_c_operational_api) {
  base_test_event_port_periodic_domains_consumer_t_i_consumer_consumer_Bridge_init(CALLER_LAST);
  Type_assign(&_base_test_event_port_periodic_domains_consumer_t_i_consumer_consumer_Bridge_c_operational_api, p_c_operational_api, sizeof(union Option_FB1130));
}

// base.test_event_port_periodic_domains.consumer_t_i_consumer_consumer_Bridge

B base_test_event_port_periodic_domains_consumer_t_i_consumer_consumer_Bridge__eq(base_test_event_port_periodic_domains_consumer_t_i_consumer_consumer_Bridge this, base_test_event_port_periodic_domains_consumer_t_i_consumer_consumer_Bridge other) {
  if (art_Art_BridgeId__ne(this->id, other->id)) return F;
  if (String__ne((String) &this->name, (String) &other->name)) return F;
  if (art_DispatchPropertyProtocol__ne((art_DispatchPropertyProtocol) &this->dispatchProtocol, (art_DispatchPropertyProtocol) &other->dispatchProtocol)) return F;
  if (Option_0247A1__ne((Option_0247A1) &this->dispatchTriggers, (Option_0247A1) &other->dispatchTriggers)) return F;
  if (art_Port_9CBF18__ne((art_Port_9CBF18) &this->consume, (art_Port_9CBF18) &other->consume)) return F;
  return T;
}

B base_test_event_port_periodic_domains_consumer_t_i_consumer_consumer_Bridge__equiv(base_test_event_port_periodic_domains_consumer_t_i_consumer_consumer_Bridge this, base_test_event_port_periodic_domains_consumer_t_i_consumer_consumer_Bridge other) {
  if (art_Bridge_Ports__inequiv((art_Bridge_Ports) &this->ports, (art_Bridge_Ports) &other->ports)) return F;
  if (base_test_event_port_periodic_domains_consumer_t_i_Initialization_Api__inequiv((base_test_event_port_periodic_domains_consumer_t_i_Initialization_Api) &this->initialization_api, (base_test_event_port_periodic_domains_consumer_t_i_Initialization_Api) &other->initialization_api)) return F;
  if (base_test_event_port_periodic_domains_consumer_t_i_Operational_Api__inequiv((base_test_event_port_periodic_domains_consumer_t_i_Operational_Api) &this->operational_api, (base_test_event_port_periodic_domains_consumer_t_i_Operational_Api) &other->operational_api)) return F;
  if (art_Bridge_EntryPoints__inequiv((art_Bridge_EntryPoints) &this->entryPoints, (art_Bridge_EntryPoints) &other->entryPoints)) return F;
  if (art_Art_BridgeId__inequiv(this->id, other->id)) return F;
  if (String__inequiv((String) &this->name, (String) &other->name)) return F;
  if (art_DispatchPropertyProtocol__inequiv((art_DispatchPropertyProtocol) &this->dispatchProtocol, (art_DispatchPropertyProtocol) &other->dispatchProtocol)) return F;
  if (Option_0247A1__inequiv((Option_0247A1) &this->dispatchTriggers, (Option_0247A1) &other->dispatchTriggers)) return F;
  if (art_Port_9CBF18__inequiv((art_Port_9CBF18) &this->consume, (art_Port_9CBF18) &other->consume)) return F;
  return T;
}

B base_test_event_port_periodic_domains_consumer_t_i_consumer_consumer_Bridge__ne(base_test_event_port_periodic_domains_consumer_t_i_consumer_consumer_Bridge this, base_test_event_port_periodic_domains_consumer_t_i_consumer_consumer_Bridge other);
B base_test_event_port_periodic_domains_consumer_t_i_consumer_consumer_Bridge__inequiv(base_test_event_port_periodic_domains_consumer_t_i_consumer_consumer_Bridge this, base_test_event_port_periodic_domains_consumer_t_i_consumer_consumer_Bridge other);

void base_test_event_port_periodic_domains_consumer_t_i_consumer_consumer_Bridge_string_(STACK_FRAME String result, base_test_event_port_periodic_domains_consumer_t_i_consumer_consumer_Bridge this) {
  DeclNewStackFrame(caller, "consumer_t_i_consumer_consumer_Bridge.scala", "base.test_event_port_periodic_domains.consumer_t_i_consumer_consumer_Bridge", "string", 0);
  String_string_(SF result, string("consumer_t_i_consumer_consumer_Bridge("));
  String sep = string(", ");
  art_Art_BridgeId_string_(SF result, this->id);
  String_string_(SF result, sep);
  String_string_(SF result, (String) &this->name);
  String_string_(SF result, sep);
  art_DispatchPropertyProtocol_string_(SF result, (art_DispatchPropertyProtocol) &this->dispatchProtocol);
  String_string_(SF result, sep);
  Option_0247A1_string_(SF result, (Option_0247A1) &this->dispatchTriggers);
  String_string_(SF result, sep);
  art_Port_9CBF18_string_(SF result, (art_Port_9CBF18) &this->consume);
  String_string_(SF result, string(")"));
}

void base_test_event_port_periodic_domains_consumer_t_i_consumer_consumer_Bridge_cprint(base_test_event_port_periodic_domains_consumer_t_i_consumer_consumer_Bridge this, B isOut) {
  #ifndef SIREUM_NO_PRINT
  void *sf = NULL;
  String_cprint(string("consumer_t_i_consumer_consumer_Bridge("), isOut);
  String sep = string(", ");
  art_Art_BridgeId_cprint(this->id, isOut);
  String_cprint(sep, isOut);
  String_cprint((String) &this->name, isOut);
  String_cprint(sep, isOut);
  art_DispatchPropertyProtocol_cprint((art_DispatchPropertyProtocol) &this->dispatchProtocol, isOut);
  String_cprint(sep, isOut);
  Option_0247A1_cprint((Option_0247A1) &this->dispatchTriggers, isOut);
  String_cprint(sep, isOut);
  art_Port_9CBF18_cprint((art_Port_9CBF18) &this->consume, isOut);
  String_cprint(string(")"), isOut);
  #endif
}

B base_test_event_port_periodic_domains_consumer_t_i_consumer_consumer_Bridge__is(STACK_FRAME void* this);
base_test_event_port_periodic_domains_consumer_t_i_consumer_consumer_Bridge base_test_event_port_periodic_domains_consumer_t_i_consumer_consumer_Bridge__as(STACK_FRAME void *this);

void base_test_event_port_periodic_domains_consumer_t_i_consumer_consumer_Bridge_apply(STACK_FRAME base_test_event_port_periodic_domains_consumer_t_i_consumer_consumer_Bridge this, art_Art_BridgeId id, String name, art_DispatchPropertyProtocol dispatchProtocol, Option_0247A1 dispatchTriggers, art_Port_9CBF18 consume) {
  DeclNewStackFrame(caller, "consumer_t_i_consumer_consumer_Bridge.scala", "base.test_event_port_periodic_domains.consumer_t_i_consumer_consumer_Bridge", "apply", 0);
  this->id = id;
  Type_assign(&this->name, name, sizeof(struct StaticString));
  Type_assign(&this->dispatchProtocol, dispatchProtocol, sizeof(union art_DispatchPropertyProtocol));
  Type_assign(&this->dispatchTriggers, dispatchTriggers, sizeof(union Option_0247A1));
  Type_assign(&this->consume, consume, sizeof(struct art_Port_9CBF18));
  {
    sfUpdateLoc(21);
    STATIC_ASSERT(0 <= MaxIS_820232, "Insufficient maximum for IS[Z, art.UPort] elements.");
    DeclNewIS_820232(t_1);
    t_1.size = (int8_t) 0;
    STATIC_ASSERT(0 <= MaxIS_820232, "Insufficient maximum for IS[Z, art.UPort] elements.");
    DeclNewIS_820232(t_2);
    t_2.size = (int8_t) 0;
    STATIC_ASSERT(1 <= MaxIS_820232, "Insufficient maximum for IS[Z, art.UPort] elements.");
    DeclNewIS_820232(t_3);
    t_3.size = (int8_t) 1;
    IS_820232_up(&t_3, 0, (art_UPort) base_test_event_port_periodic_domains_consumer_t_i_consumer_consumer_Bridge_consume_(this));
    STATIC_ASSERT(0 <= MaxIS_820232, "Insufficient maximum for IS[Z, art.UPort] elements.");
    DeclNewIS_820232(t_4);
    t_4.size = (int8_t) 0;
    DeclNewart_Bridge_Ports(t_0);
    art_Bridge_Ports_apply(SF &t_0, (IS_820232) (&t_1), (IS_820232) (&t_2), (IS_820232) (&t_3), (IS_820232) (&t_4));
    Type_assign(&this->ports, (&t_0), sizeof(struct art_Bridge_Ports));
  }
  {
    sfUpdateLoc(31);
    {

      sfUpdateLoc(32);
      base_test_event_port_periodic_domains_consumer_t_i_Initialization_Api api;
      DeclNewbase_test_event_port_periodic_domains_consumer_t_i_Initialization_Api(t_5);
      base_test_event_port_periodic_domains_consumer_t_i_Initialization_Api_apply(SF &t_5, base_test_event_port_periodic_domains_consumer_t_i_consumer_consumer_Bridge_id_(this), art_Port_9CBF18_id_(base_test_event_port_periodic_domains_consumer_t_i_consumer_consumer_Bridge_consume_(this)));
      api = (base_test_event_port_periodic_domains_consumer_t_i_Initialization_Api) (&t_5);

      sfUpdateLoc(36);
      {
        DeclNewSome_0B69ED(t_6);
        Some_0B69ED_apply(SF &t_6, (base_test_event_port_periodic_domains_consumer_t_i_Initialization_Api) api);
        base_test_event_port_periodic_domains_consumer_t_i_consumer_consumer_Bridge_c_initialization_api_a(SF (Option_6288B6) (&t_6));
      }
      Type_assign(&this->initialization_api, api, sizeof(struct base_test_event_port_periodic_domains_consumer_t_i_Initialization_Api));
    }
  }
  {
    sfUpdateLoc(40);
    {

      sfUpdateLoc(41);
      base_test_event_port_periodic_domains_consumer_t_i_Operational_Api api;
      DeclNewbase_test_event_port_periodic_domains_consumer_t_i_Operational_Api(t_7);
      base_test_event_port_periodic_domains_consumer_t_i_Operational_Api_apply(SF &t_7, base_test_event_port_periodic_domains_consumer_t_i_consumer_consumer_Bridge_id_(this), art_Port_9CBF18_id_(base_test_event_port_periodic_domains_consumer_t_i_consumer_consumer_Bridge_consume_(this)));
      api = (base_test_event_port_periodic_domains_consumer_t_i_Operational_Api) (&t_7);

      sfUpdateLoc(45);
      {
        DeclNewSome_2EDC17(t_8);
        Some_2EDC17_apply(SF &t_8, (base_test_event_port_periodic_domains_consumer_t_i_Operational_Api) api);
        base_test_event_port_periodic_domains_consumer_t_i_consumer_consumer_Bridge_c_operational_api_a(SF (Option_FB1130) (&t_8));
      }
      Type_assign(&this->operational_api, api, sizeof(struct base_test_event_port_periodic_domains_consumer_t_i_Operational_Api));
    }
  }
  {
    sfUpdateLoc(50);
    DeclNewbase_test_event_port_periodic_domains_consumer_t_i_consumer_consumer_Bridge_EntryPoints(t_9);
    base_test_event_port_periodic_domains_consumer_t_i_consumer_consumer_Bridge_EntryPoints_apply(SF &t_9, base_test_event_port_periodic_domains_consumer_t_i_consumer_consumer_Bridge_id_(this), art_Port_9CBF18_id_(base_test_event_port_periodic_domains_consumer_t_i_consumer_consumer_Bridge_consume_(this)), (Option_0247A1) base_test_event_port_periodic_domains_consumer_t_i_consumer_consumer_Bridge_dispatchTriggers_(this), (base_test_event_port_periodic_domains_consumer_t_i_Initialization_Api) base_test_event_port_periodic_domains_consumer_t_i_consumer_consumer_Bridge_initialization_api_(this), (base_test_event_port_periodic_domains_consumer_t_i_Operational_Api) base_test_event_port_periodic_domains_consumer_t_i_consumer_consumer_Bridge_operational_api_(this));
    Type_assign(&this->entryPoints, (&t_9), sizeof(struct base_test_event_port_periodic_domains_consumer_t_i_consumer_consumer_Bridge_EntryPoints));
  }
}

void base_test_event_port_periodic_domains_consumer_t_i_consumer_consumer_Bridge_init_c_initialization_api(STACK_FRAME_ONLY) {
  #ifdef SIREUM_LOC
  StackFrame sf = caller;
  #endif
  sfUpdateLoc(63);
  DeclNewNone_9DDC16(t_0);
  None_9DDC16_apply(SF &t_0);
  Type_assign(&_base_test_event_port_periodic_domains_consumer_t_i_consumer_consumer_Bridge_c_initialization_api, (&t_0), sizeof(struct None_9DDC16));
};

void base_test_event_port_periodic_domains_consumer_t_i_consumer_consumer_Bridge_init_c_operational_api(STACK_FRAME_ONLY) {
  #ifdef SIREUM_LOC
  StackFrame sf = caller;
  #endif
  sfUpdateLoc(64);
  DeclNewNone_5F2743(t_1);
  None_5F2743_apply(SF &t_1);
  Type_assign(&_base_test_event_port_periodic_domains_consumer_t_i_consumer_consumer_Bridge_c_operational_api, (&t_1), sizeof(struct None_5F2743));
};