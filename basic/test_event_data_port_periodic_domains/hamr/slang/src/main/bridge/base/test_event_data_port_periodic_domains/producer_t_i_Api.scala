// #Sireum

package base.test_event_data_port_periodic_domains

import org.sireum._
import art._
import base._

@sig trait producer_t_i_Api {
  def id: Art.BridgeId
  def write_port_Id : Art.PortId

  // Logika spec var representing port state for outgoing event data port
  @spec var write_port: Option[Base_Types.Integer_8] = $

  def put_write_port(value : Base_Types.Integer_8) : Unit = {
    Contract(
      Modifies(write_port),
      Ensures(
        write_port == Some(value)
      )
    )
    Spec {
      write_port = Some(value)
    }

    Art.putValue(write_port_Id, Base_Types.Integer_8_Payload(value))
  }

  def logInfo(msg: String): Unit = {
    Art.logInfo(id, msg)
  }

  def logDebug(msg: String): Unit = {
    Art.logDebug(id, msg)
  }

  def logError(msg: String): Unit = {
    Art.logError(id, msg)
  }
}

@datatype class producer_t_i_Initialization_Api (
  val id: Art.BridgeId,
  val write_port_Id : Art.PortId) extends producer_t_i_Api

@datatype class producer_t_i_Operational_Api (
  val id: Art.BridgeId,
  val write_port_Id : Art.PortId) extends producer_t_i_Api {

}
