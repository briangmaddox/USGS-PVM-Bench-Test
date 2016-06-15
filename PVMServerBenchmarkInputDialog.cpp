/**
 *Implementation file for the Input Dialog
 **/

#include "PVMServerBenchmarkInputDialog.h"
#include <qspinbox.h>
#include <qlistbox.h>
#include <qinputdialog.h>
#include <qcheckbox.h>
#include <new>

//****************************************************************************
PVMServerBenchmarkInputDialog::PVMServerBenchmarkInputDialog()
  : PVMServerBenchmark(0, 0, true)
{
  
}

//****************************************************************************
long int PVMServerBenchmarkInputDialog::getNumberRuns() throw()
{
  if (Number_Runs)
  {
    return Number_Runs->text().toLong();
  }
  return 0;
}

//****************************************************************************
long int PVMServerBenchmarkInputDialog::getNumberSlaves() throw()
{
  if (Number_Slaves)
  {
    return Number_Slaves->text().toLong();
  }
  return 0;
}
  
//****************************************************************************
long int PVMServerBenchmarkInputDialog::getDataBufferSize() throw()
{
  if (Data_Size)
  {
    return Data_Size->text().toLong();
  }
  return 0;
}

//****************************************************************************
void PVMServerBenchmarkInputDialog::add_host_clicked()
{
  QListBoxText * temp;

  
  if (!(temp = new (std::nothrow) QListBoxText(Hostname_box, 
     QInputDialog::getText("Hostname", "Enter the hostname:"))))
    throw std::bad_alloc();

  Number_Slaves->setValue(Hostname_box->numRows());


}

//***************************************************************************
void PVMServerBenchmarkInputDialog::rem_host_clicked()
{
  Hostname_box->removeItem(Hostname_box->currentItem());
  Number_Slaves->setValue(Hostname_box->numRows());
}

//***************************************************************************
bool PVMServerBenchmarkInputDialog::useExplicitHosts() const throw()
{
  return Specific_hosts->isOn();
}

//***************************************************************************
void PVMServerBenchmarkInputDialog::
getHostNames(std::vector<std::string> & inlist) throw()
{
  int counter(0), size(0);

  size = Hostname_box->numRows();
  
  inlist.resize(size);

  for (counter = 0; counter < size; ++counter)
  {
    inlist[counter] = Hostname_box->text(counter);
  }


}




