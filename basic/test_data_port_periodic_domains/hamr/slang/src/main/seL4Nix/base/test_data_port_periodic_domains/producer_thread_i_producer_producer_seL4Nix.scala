// #Sireum

// Do not edit this file as it will be overwritten if HAMR codegen is rerun

package base.test_data_port_periodic_domains

import org.sireum._
import art._

@ext object producer_thread_i_producer_producer_seL4Nix {
  // send payload 'd' to components connected to seL4's write_port port
  def write_port_Send(d: DataContent): Unit = $
}