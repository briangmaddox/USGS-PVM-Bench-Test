/**
 *This is the implementation file for the 
 *the designer generated benchmark results 
 *program.
 **/

#ifndef PVMSBENCHRESULTSDIALOG_H
#define PVMSBENCHRESULTSDIALOG_H


#include "PVMSBenchResults.h"
#include <vector>
#include <string>

/**
 *Results class
 **/
class PVMSBenchResultsDialog : public PVMSBenchResults
{
 public:
  
  /**
   *Main constructor for the class
   *use exec to run the dialog!
   **/
  PVMSBenchResultsDialog(std::vector<std::string> hosts,
                         std::vector<float> avgs);

  /**
   *Main destructor for the class
   **/
  virtual ~PVMSBenchResultsDialog();

};

#endif
