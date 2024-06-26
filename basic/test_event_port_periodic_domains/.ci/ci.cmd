::/*#! 2> /dev/null                                 #
@ 2>/dev/null # 2>nul & echo off & goto BOF         #
if [ -z ${SIREUM_HOME} ]; then                      #
  echo "Please set SIREUM_HOME env var"             #
  exit -1                                           #
fi                                                  #
exec ${SIREUM_HOME}/bin/sireum slang run "$0" "$@"  #
:BOF
setlocal
if not defined SIREUM_HOME (
  echo Please set SIREUM_HOME env var
  exit /B -1
)
%SIREUM_HOME%\\bin\\sireum.bat slang run "%0" %*
exit /B %errorlevel%
::!#*/
// #Sireum

import org.sireum._

val homeDir = Os.slashDir.up

val sireumBin = Os.path(Os.env("SIREUM_HOME").get) / "bin" 
val sireum = sireumBin / (if(Os.isWin) "sireum.bat" else "sireum")

var result: Z = 0

if(result == 0) {
    result = proc"$sireum slang run ${homeDir / "aadl" / "bin" / "clean.cmd"}".console.echo.run().exitCode
}

if(result == 0) {
    result = proc"$sireum slang run ${homeDir / "aadl" / "bin" / "run-hamr.cmd"} Linux".console.echo.run().exitCode
}

if(result == 0) {
    result = proc"${homeDir / "hamr" / "c" / "bin" / "compile.cmd"}".console.echo.run().exitCode
}

if(result == 0) {
    result = proc"$sireum slang run ${homeDir / "aadl" / "bin" / "run-hamr.cmd"} seL4".console.echo.run().exitCode
}

if(result == 0) {
  result = proc"${homeDir / "hamr" / "camkes-seL4" / "bin" / "run-camkes.sh"} -n".console.echo.run().exitCode
}

if(result == 0) {
    result = proc"$sireum slang run ${homeDir / "aadl" / "bin" / "run-hamr.cmd"} seL4_Only".console.echo.run().exitCode
}

if(result == 0) {
  result = proc"${homeDir / "hamr" / "camkes-seL4_Only" / "bin" / "run-camkes.sh"} -n".console.echo.run().exitCode
}

if(result == 0) {
    result = proc"$sireum proyek test ${homeDir / "hamr" / "slang" }".console.echo.run().exitCode
}

Os.exit(result)