# CASE Micro-examples

This repo supports prototyping of the HAMR to Microkit integration as part of the Collins Aerospace DARPA PROVERS project.  The HAMR Microkit integration is a 
migration of the seL4 HAMR backend from a CAmkES-based integration.  Although 
we expect to continue to support CAmkES, HAMR tool chain development plans 
to emphasize Microkit for PROVERS.

To support the CAmkES to Microkit migration, this repo provides a collection 
of "micro-examples" that illustrate patterns of AADL threading and communication.
Supporting these patterns will provide sufficient knowledge for supporting 
larger PROVERS examples.

The repo aims to provide a side-by-side comparison of HAMR-oriented CAmkES artifacts
and Microkit artifacts.  The CAmkES artifacts are based on a DARPA CASE deliverable
-- the [CASE tool-assessment-4](https://github.com/loonwerks/CASE/tree/master/TA5/tool-assessment-4) repository that only contains the micro-examples illustrating how the various AADL port kinds are handled and a single VM example. 

We aim for all the examples in this repo to be buildable and executable on QEMU.

## Producer-Consumer Illustrating AADL Port Kinds

- [Data Ports](basic/test_data_port_periodic_domains/) (CAmkES, preliminary Microkit)
- [Event Ports](basic/test_event_data_port_periodic_domains/) (CAmkES)
- [Event Data Ports](basic/test_event_data_port_periodic_domains/) (CAmkES)

## Virtual Machine

- [Native Producer, VM Consumer](vm/test_event_data_port_periodic_domains_VM//receiver_vm/) (CAmkES)

## Discussion

High-level requirements for Microkit to support the ARINC 653-like threading and communication emphasized by AADL are currently held separately by UNSW.   Below
we provide a summary of concepts based on what was implemented for CAmkES on CASE, 
along with a discussion of the current status of the Microkit prototype for the Data Ports example above.

### Communication

#### Basic Port Types

Inspired by ARINC 653, AADL contains both data ports (roughly corresponding to "sampling ports" of 653) and event data ports (roughly corresponding to the "queueing" 
ports of 653).  Event data ports implement queued messages with payloads.  AADL has 
a degenerate form of event data ports called event ports that support queued messages
with no payloads.   AADL provides several configuration parameters (model properties)
that determine the specific queuing policy implementation regarding overflow handling, 
dequeuing policies, etc.

For CASE, all the three AADL port types (data, event, event data) were based on 
a common CAmkES port pattern consisting of a 
* memory region holding the exchanged data
* notification indicate the presence of new data

The easiest of the ports to work with from an seL4 perspective are the data ports.  
This allows us to focus on prototyping port channels as memory regions without worrying
about all the variations of AADL queueing policies for the moment.

*If we can get a prototype working using Microkit notification and memory regions, we can easily migrate from CAmkES to microkit, and then continuing refining to get a more elegant implementation from there.*

The results of the initial prototyping effort for the data ports microexample can be seen here
https://github.com/santoslab/case-tool-assessment-4/tree/main/basic/test_data_port_periodic_domains

For the CAmkES artifacts, please consult the "seL4_only" artifacts as these are the artifacts without the additional AADL shim code that implements the queuing semantics.

Note that in the [CAmkES for the producer](basic/test_data_port_periodic_domains/hamr/camkes-seL4_Only/components/producer_thread_i_producer_producer/producer_thread_i_producer_producer.camkes) one sees the declaration for
the int8 shared memory region (e.g., associated with an AADL data port of type int8)

```
dataport sp_int8_t_t sb_write_port;
```
and a correspond port is found in the consumer.  The other "TickTock" ports 
are associated with the CASE scheduling approach using the domain scheduler
(we expect this strategy to be altered when moving to Microkit).

The [CAmkES assembly file](basic/test_data_port_periodic_domains/hamr/camkes-seL4_Only/top_impl_Instance.camkes) shows read/write configurations set to ensure a kernel enforced one-way 
communication from the producer to the consumer
```
configuration {
    producer_producer._domain = 2;
    consumer_consumer._domain = 3;
    producer_producer.sb_write_port_access = "W";
    consumer_consumer.sb_read_port_access = "R";
  }
```

Porting this concept over to microkit seems straightforward.  
See the [Microkit system file](basic/test_data_port_periodic_domains/microkit/dataport.system) that includes
a protection domain (PD) for both the Producer and Consumer with a memory region
shared between them (excerpts shown below).
```
<!-- 4KiB is smallest pages size for AArch64 -->
  <memory_region name="producer_to_consumer_dataport" size="4096" />

  <protection_domain name="producer" 
    priority="100"
    period="1000"
    budget="400"
  >
  
  <program_image path="producer.elf" />

  <map mr="producer_to_consumer_dataport"
    vaddr="0x4000000" perms="wr" setvar_vaddr="to_consumer_vaddr" />

  </protection_domain>
    
  <protection_domain name="consumer" 
    priority="99"
    period="1000"
    budget="400"
  >

  <program_image path="consumer.elf" />

  <map mr="producer_to_consumer_dataport"
    vaddr="0x4000000" perms="r" setvar_vaddr="from_producer_vaddr" />

  </protection_domain>

```



