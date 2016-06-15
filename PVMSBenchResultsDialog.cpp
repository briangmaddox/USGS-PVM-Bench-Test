/**
 *Implementation file for the bench mark results dialog
 **/

#include "PVMSBenchResultsDialog.h"
#include <qlistview.h>

//****************************************************************************
PVMSBenchResultsDialog::PVMSBenchResultsDialog(std::vector<std::string> hosts,
                         std::vector<float> avgs)
  : PVMSBenchResults(0, 0, true)
{
  //put the results into the list
  QListViewItem * item = 0;
  QString temp;
  int counter(0);

  Results_List->setSorting(-1);

  try
  {
    if (hosts.size() == avgs.size())
    {
      for (counter = hosts.size()-1; counter >= 0; --counter)
      {
        if (!(item = new (std::nothrow) QListViewItem(Results_List)))
          throw std::bad_alloc();

        item->setText(0, hosts[counter].c_str());
        temp = temp.setNum(avgs[counter]);
        item->setText(1, temp);
      }
    }
  }
  catch(...)
  {
    //qt should delete the list items
  }
}

//****************************************************************************
PVMSBenchResultsDialog::~PVMSBenchResultsDialog()
{}


