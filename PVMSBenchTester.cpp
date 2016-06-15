/**
 *Implementation for PVMSBenchTester
 **/

#include "PVMSBenchTester.h"
#include <sstream>

//**********************************************************************
PVMSBenchTester::PVMSBenchTester() : USGSBenchmark::ServerBenchMaster()
{
}

//*********************************************************************
PVMSBenchTester::~PVMSBenchTester()
{}

//*********************************************************************
bool PVMSBenchTester::generateConfig()
    throw(USGSBenchmark::BenchmarkException)
{
  PVMServerBenchmarkInputDialog input;

  //setup the defaults
  slave_exe = "benchmarkslave";

  if (!input.exec())
  {
    return false;
  }

  //else get the data
  num_runs = input.getNumberRuns();
  number_slaves = input.getNumberSlaves();
  data_size = input.getDataBufferSize();
  explicit_names = input.useExplicitHosts();
 
  if(explicit_names)
  {
    input.getHostNames(name_table);
  }

  return true;
}

//**********************************************************************
bool PVMSBenchTester::outputResults()
    throw(USGSBenchmark::BenchmarkException)
{
  std::vector<std::string> hosts;
  std::vector<float>   avg;
  int counter(0);
  std::ostringstream out;


  hosts.resize(number_slaves+1);
  avg.resize(number_slaves+1);
  
  hosts[0] = "Master";
  avg[0] =  mavg;

  for(counter = 1; counter < number_slaves+1; ++counter)
  {
    out.str("");
    out << counter;
    if (!explicit_names)
      hosts[counter] = std::string("Slave ") + out.str();
    else
      hosts[counter] = name_table[counter-1];
    
    avg[counter] = savg[counter-1];
  }
 
  
  //create the dialog
  PVMSBenchResultsDialog output(hosts, avg);

  output.exec();
  
  return true;
}


