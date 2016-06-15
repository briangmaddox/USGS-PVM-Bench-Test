/**
 *The shell for the server benchmark client
 **/

#include <fstream>
#include <sstream>
#include "BenchmarkLib/ServerBenchSlave.h"

int main(int argc, char ** argv)
{
  std::ostringstream out;
  std::ofstream log;

  try
  {
    USGSBenchmark::ServerBenchSlave slave;

    slave.run();
  }
  catch(USGSBenchmark::BenchmarkException & err)
  {
    out << pvm_mytid() << "exception";

    log.open(out.str().c_str());
   
    log << err.getcstrError() << std::endl;
    log << "You are the weakest link. Good-bye." << std::endl;
    log.close();
  }
}
