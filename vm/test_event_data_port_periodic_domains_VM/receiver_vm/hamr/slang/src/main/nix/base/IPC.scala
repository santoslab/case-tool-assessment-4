// #Sireum

package base

import org.sireum._
import art._
import art.Art.PortId._

// Do not edit this file as it will be overwritten if HAMR codegen is rerun

object IPCPorts {
  val producer_t_i_producer_producer_App: Art.PortId = Art.PortId.fromZ(2)
  val consumer_t_i_consumer_consumer_App: Art.PortId = Art.PortId.fromZ(3)
  val Main: Art.PortId = Art.PortId.fromZ(4)

  def emptyReceiveOut: MBox2[Art.PortId, DataContent] = {
    return MBox2(portId"0", art.Empty())
  }

  def emptyReceiveAsyncOut: MBox2[Art.PortId, Option[DataContent]] = {
    return MBox2(portId"0", None())
  }
}
