// #Sireum

package base.test_event_port_periodic_domains

import org.sireum._
import art.Art
import base._

// Do not edit this file as it will be overwritten if HAMR codegen is rerun
@msig trait producer_t_i_producer_producer_TestApi {

  def BeforeEntrypoint(): Unit = {
    Art.initTest(Arch.top_impl_Instance_producer_producer)
  }

  def AfterEntrypoint(): Unit = {
    Art.finalizeTest(Arch.top_impl_Instance_producer_producer)
  }

  def testCompute(): Unit = {
    Art.manuallyClearOutput()
    Art.testCompute(Arch.top_impl_Instance_producer_producer)
  }

  def testInitialise(): Unit = {
    Art.manuallyClearOutput()
    Art.testInitialise(Arch.top_impl_Instance_producer_producer)
  }

  /** helper function to check producer_t_i_producer_producer's
   * output ports.  Use named arguments to check subsets of the output ports.
   * @param emit method that will be called with the number of events to be sent
   *        on the outgoing event port 'emit'.
   */
  def check_concrete_output(emit: Z => B): Unit = {
    var testFailures: ISZ[ST] = ISZ()

    // TODO: event port getter should return the number of events in
    //       the output queue when queue sizes > 1 support is added to ART
    val emitValue: Z = if(get_emit().nonEmpty) z"1" else z"0"
    if(!emit(emitValue)) {
      testFailures = testFailures :+ st"'emit' did not match expected: ${emitValue} events were in the outgoing event queue"
    }

    assert(testFailures.isEmpty, st"${(testFailures, "\n")}".render)
  }


  // getter for out EventPort
  def get_emit(): Option[art.Empty] = {
    val value: Option[art.Empty] = get_emit_payload() match {
      case Some(art.Empty()) => Some(art.Empty())
      case Some(v) => halt(s"Unexpected payload on port emit.  Expecting 'art.Empty' but received ${v}")
      case _ => None[art.Empty]()
    }
    return value
  }

  // payload getter for out EventPort
  def get_emit_payload(): Option[art.Empty] = {
    return Art.observeOutInfrastructurePort(Arch.top_impl_Instance_producer_producer.initialization_api.emit_Id).asInstanceOf[Option[art.Empty]]
  }

}