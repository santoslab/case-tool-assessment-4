// #Sireum

// Do not edit this file as it will be overwritten if HAMR codegen is rerun

package base.consumer_t_i_consumer_consumer

import org.sireum._
import art._
import art.Art.BridgeId._
import art.Art.PortId._
import art.DispatchPropertyProtocol._
import art.PortMode._
import base._
import base.test_event_port_periodic_domains.consumer_t_i_consumer_consumer_seL4Nix

object consumer extends App {

  val consumerBridge : base.test_event_port_periodic_domains.consumer_t_i_consumer_consumer_Bridge = {
    val consume = Port[art.Empty] (id = portId"0", name = "top_impl_Instance_consumer_consumer_consume", mode = EventIn)

    base.test_event_port_periodic_domains.consumer_t_i_consumer_consumer_Bridge(
      id = bridgeId"0",
      name = "top_impl_Instance_consumer_consumer",
      dispatchProtocol = Periodic(period = 1000),
      dispatchTriggers = None(),

      consume = consume
    )
  }

  val entryPoints: Bridge.EntryPoints = consumerBridge.entryPoints
  val noData: Option[DataContent] = None()

  // consume: In EventPort art.Empty
  val consume_id: Art.PortId = consumerBridge.consume.id
  var consume_port: Option[DataContent] = noData

  def dispatchStatus(bridgeId: Art.BridgeId): DispatchStatus = {
    return TimeTriggered()
  }

  def getValue(portId: Art.PortId): Option[DataContent] = {
    if(portId == consume_id) {
      return consume_port
    } else {
      halt(s"Unexpected: consumer.getValue called with: ${portId}")
    }
  }

  def receiveInput(eventPortIds: ISZ[Art.PortId], dataPortIds: ISZ[Art.PortId]): Unit = {
    // ignore params

    consume_port = consumer_t_i_consumer_consumer_seL4Nix.consume_Receive()
  }

  def putValue(portId: Art.PortId, data: DataContent): Unit = {
    halt(s"Unexpected: consumer.putValue called with: ${portId}")
  }

  def sendOutput(eventPortIds: ISZ[Art.PortId], dataPortIds: ISZ[Art.PortId]): Unit = {
    // ignore params


  }

  def initialiseArchitecture(): Unit = {
    // nothing to do - CAmkES is responsible for initialization
  }

  def initialiseEntryPoint(): Unit = { entryPoints.initialise() }

  def computeEntryPoint(): Unit = { entryPoints.compute() }

  def finaliseEntryPoint(): Unit = { entryPoints.finalise() }

  def main(args: ISZ[String]): Z = {

    // need to touch the following for transpiler
    initialiseArchitecture()
    initialiseEntryPoint()
    computeEntryPoint()
    finaliseEntryPoint()

    touch()

    return 0
  }

  def touch(): Unit = {
    if(F) {
      TranspilerToucher.touch()

      // add types used in Platform.receive and Platform.receiveAsync
      val mbox2Boolean_Payload: MBox2[Art.PortId, DataContent] = MBox2(portId"0", Base_Types.Boolean_Payload(T))
      val mbox2OptionDataContent: MBox2[Art.PortId, Option[DataContent]] = MBox2(portId"0", None())

      // touch each payload/type in case some are only used as a field in a record
      def printDataContent(a: art.DataContent): Unit = { println(s"${a}") }

      printDataContent(art.Empty())

      base.test_event_port_periodic_domains.consumer_t_i_consumer_consumer_Bridge.c_initialization_api.get.logInfo("")
      base.test_event_port_periodic_domains.consumer_t_i_consumer_consumer_Bridge.c_initialization_api.get.logDebug("")
      base.test_event_port_periodic_domains.consumer_t_i_consumer_consumer_Bridge.c_initialization_api.get.logError("")
      base.test_event_port_periodic_domains.consumer_t_i_consumer_consumer_Bridge.c_operational_api.get.logInfo("")
      base.test_event_port_periodic_domains.consumer_t_i_consumer_consumer_Bridge.c_operational_api.get.logDebug("")
      base.test_event_port_periodic_domains.consumer_t_i_consumer_consumer_Bridge.c_operational_api.get.logError("")
      val apiUsage_consume: Option[art.Empty] = base.test_event_port_periodic_domains.consumer_t_i_consumer_consumer_Bridge.c_operational_api.get.get_consume()
    }
  }

  def logInfo(title: String, msg: String): Unit = {
    print(consumerBridge.name)
    print(": ")
    println(msg)
  }

  def logError(title: String, msg: String): Unit = {
    eprint(consumerBridge.name)
    eprint(": ")
    eprintln(msg)
  }

  def logDebug(title: String, msg: String): Unit = {
    print(consumerBridge.name)
    print(": ")
    println(msg)
  }

  def run(): Unit = {}

}
