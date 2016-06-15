/**
 *Implemnetation of the input form created
 *by the designer.
 *Chris Bilderback
 **/

#ifndef PVMSERVERBENCHMARKINPUTDIALOG_H_
#define PVMSERVERBENCHMARKINPUTDIALOG_H_

#include "PVMSBenchmarkInput.h"
#include <vector>
#include <string>

/**
 *PVMServerBenchmark class
 **/
class PVMServerBenchmarkInputDialog : public PVMServerBenchmark
{
  Q_OBJECT

 public:
  /**
   *This is a modal only dialog
   **/
  PVMServerBenchmarkInputDialog();

  /**
   *This function retrieves the number of runs
   **/
  long int getNumberRuns() throw();

  /**
   *This function retrieves the number of slaves
   **/
  long int getNumberSlaves() throw();
  
  /**
   *This function retrieves the data buffer size
   **/
  long int getDataBufferSize() throw();

  /**
   *This returns whether to use explict hosts or not
   **/
  bool useExplicitHosts() const throw();

  /**
   *This function fills a vector of hostnames
   **/
  void getHostNames(std::vector<std::string> & inlist) throw();


public slots:
    virtual void add_host_clicked();
    virtual void rem_host_clicked();

};


#endif
