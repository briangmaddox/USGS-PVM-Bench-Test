/**
 *A basic implementation to test the server benchmark class
 **/

#ifndef PVMSBENCHTESTER_H
#define PVMSBENCHTESTER_H

#include "BenchmarkLib/ServerBenchMaster.h"
#include "PVMSBenchResultsDialog.h"
#include "PVMServerBenchmarkInputDialog.h"


class PVMSBenchTester : public USGSBenchmark::ServerBenchMaster
{
public:
  
  /**
   *Class constructor
   **/
  PVMSBenchTester();

  /**
   *Class destructor
   **/
  virtual ~PVMSBenchTester();

  /**
   *This function must be overloaded by clients to supply
   *benchmark configuration
   **/
  bool generateConfig()
    throw(USGSBenchmark::BenchmarkException);

  /**
   *This function must be overloaded by clients to handle output.
   **/
  bool outputResults()
    throw(USGSBenchmark::BenchmarkException);  

};


#endif


