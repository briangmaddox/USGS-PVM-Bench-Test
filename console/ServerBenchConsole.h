/**
 *This is a simple console i/o implementation
 *of the master/slave benchmark
 **/

#ifndef SERVERBENCHCONSOLE_H_
#define SERVERBENCHCONSOLE_H_

#include "BenchmarkLib/ServerBenchMaster.h"

/**
 *Console i/o benchmark master
 **/
class ServerBenchConsole : public USGSBenchmark::ServerBenchMaster
{
 public:

  /**
   *Main constructor for the class (takes a input file or if 
   *the input file is invalid then it will prompt user for information
   *and write the input file.)
   **/
  ServerBenchConsole(const std::string & inputfile);

  /**
   *Class destructor
   **/
  virtual ~ServerBenchConsole();

  /**
   *This function must be overloaded by clients to supply
   *benchmark configuration
   **/
  virtual bool generateConfig()
    throw(USGSBenchmark::BenchmarkException);
  
  /**
   *This function must be overloaded by clients to handle output.
   **/
  virtual bool outputResults()
    throw(USGSBenchmark::BenchmarkException);

protected:
  
  /**
   *This function prompts the user for configuration
   **/
  void promptUser() throw(USGSBenchmark::BenchmarkException);
  

  /**
   *This function will write the output config file
   **/
  void writeConfig(const std::string & configfile) 
    throw(USGSBenchmark::BenchmarkException);


  std::string inconfig;   //the input config file

};

#endif
