/**
 *Main entry point for serverbenchmark tester
 **/

#include "PVMSBenchTester.h"
#include <qapplication.h>
#include <qmessagebox.h>

int main(int argc, char ** argv)
{
  QApplication a(argc, argv);
  try
  {
  
    PVMSBenchTester tester;
    tester.run();
    return 0; 
    
  }
  catch(USGSBenchmark::BenchmarkException & e)
  {
    QMessageBox::critical
        (0, "You are the weakest link. Goodbye.", e.getcstrError());
    return 0;
  }
}
