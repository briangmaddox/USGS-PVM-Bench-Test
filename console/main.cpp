/**
 *main entry point for the console benchmarking program
 **/

#include <iostream>
#include "ServerBenchConsole.h"

int main(int argc, char ** argv)
{
  std::string configfile;
 
  try
  {

    if (argc >= 2)
    {
      configfile = argv[1];
    }
    
    ServerBenchConsole test(configfile);
    
    test.run();

  }
  catch(USGSBenchmark::BenchmarkException & err)
  {
    std::cout << err.getcstrError() << std::endl;
    std::cout << "You are the weakest link. Good-bye." << std::endl;
  }
}
