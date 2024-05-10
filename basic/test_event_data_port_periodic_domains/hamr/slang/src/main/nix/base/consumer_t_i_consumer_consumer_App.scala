// #Sireum

package base

import org.sireum._
import art._
import art.Art.PortId._
import art.scheduling.nop.NopScheduler

// Do not edit this file as it will be overwritten if HAMR codegen is rerun

object consumer_t_i_consumer_consumer_App extends App {

  val entryPoints: Bridge.EntryPoints = Arch.top_impl_Instance_consumer_consumer.entryPoints
  val appPortId: Art.PortId = IPCPorts.consumer_t_i_consumer_consumer_App
  val appPortIdOpt: Option[Art.PortId] = Some(appPortId)

  // incoming ports
  val read_portPortId: Art.PortId = Arch.top_impl_Instance_consumer_consumer.read_port.id
  val read_portPortIdOpt: Option[Art.PortId] = Some(read_portPortId)

  def initialiseArchitecture(seed: Z): Unit = {
    PlatformComm.initialise(seed, appPortIdOpt)
    PlatformComm.initialise(seed, read_portPortIdOpt)

    Art.run(Arch.ad, NopScheduler())
  }

  def initialise(): Unit = {
    entryPoints.initialise()
  }

  def compute(): Unit = {

    {
      val out = IPCPorts.emptyReceiveAsyncOut
      PlatformComm.receiveAsync(read_portPortIdOpt, out)
      out.value2 match {
        case Some(v: Base_Types.Integer_8_Payload) => ArtNix.updateData(read_portPortId, v)
        case Some(v) => halt(s"Unexpected payload on port read_port.  Expecting something of type Base_Types.Integer_8_Payload but received ${v}")
        case None() => // do nothing
      }
    }
    entryPoints.compute()
    base.Process.sleep(1000)
  }

  def finalise(): Unit = {
    entryPoints.finalise()
  }

  def main(args: ISZ[String]): Z = {

    val seed: Z = if (args.size == z"1") {
      val n = Z(args(0)).get
      if (n == z"0") 1 else n
    } else {
      1
    }

    initialiseArchitecture(seed)

    PlatformComm.receive(appPortIdOpt, IPCPorts.emptyReceiveOut) // pause after setting up component

    initialise()

    PlatformComm.receive(appPortIdOpt, IPCPorts.emptyReceiveOut) // pause after component init

    println("consumer_t_i_consumer_consumer_App starting ...")

    ArtNix.timeDispatch()

    var terminated = F
    while (!terminated) {
      val out = IPCPorts.emptyReceiveAsyncOut
      PlatformComm.receiveAsync(appPortIdOpt, out)
      if (out.value2.isEmpty) {
        compute()
      } else {
        terminated = T
      }
    }
    exit()

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

      printDataContent(Base_Types.Integer_8_Payload(Base_Types.Integer_8_example()))
      printDataContent(art.Empty())

      base.test_event_data_port_periodic_domains.consumer_t_i_consumer_consumer_Bridge.c_initialization_api.get.logInfo("")
      base.test_event_data_port_periodic_domains.consumer_t_i_consumer_consumer_Bridge.c_initialization_api.get.logDebug("")
      base.test_event_data_port_periodic_domains.consumer_t_i_consumer_consumer_Bridge.c_initialization_api.get.logError("")
      base.test_event_data_port_periodic_domains.consumer_t_i_consumer_consumer_Bridge.c_operational_api.get.logInfo("")
      base.test_event_data_port_periodic_domains.consumer_t_i_consumer_consumer_Bridge.c_operational_api.get.logDebug("")
      base.test_event_data_port_periodic_domains.consumer_t_i_consumer_consumer_Bridge.c_operational_api.get.logError("")
      val apiUsage_read_port: Option[Base_Types.Integer_8] = base.test_event_data_port_periodic_domains.consumer_t_i_consumer_consumer_Bridge.c_operational_api.get.get_read_port()
    }
  }

  def exit(): Unit = {
    finalise()
    PlatformComm.finalise()
  }

  override def atExit(): Unit = {
    exit()
  }
}