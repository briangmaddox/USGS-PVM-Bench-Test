/**
 *Implementation file for the console input class for the
 *Server benchmark.
 **/

#include "ServerBenchConsole.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "MiscUtils/cmp_nocase.h"

//****************************************************************************
ServerBenchConsole::ServerBenchConsole(const std::string & inputfile)
{
  inconfig = inputfile;
}

//****************************************************************************
ServerBenchConsole::~ServerBenchConsole()
{}

//****************************************************************************
bool ServerBenchConsole::generateConfig()
    throw(USGSBenchmark::BenchmarkException)
{
  std::ifstream in;
  std::string buf;
  int counter(0); 

  //try to open the config file
  in.open(inconfig.c_str());
  
  if (in.fail())
  {
    //prompt the user
    promptUser();
  }
  else
  {
    //try to read in the stuff
    in >> buf >> num_runs;
    
    if (in.fail())
      throw USGSBenchmark::BenchmarkException
        ("ServerBenchConsole::generateConfig- could not read num_runs");
    
    in >> buf >> number_slaves;
    
    if (in.fail())
      throw USGSBenchmark::BenchmarkException
        ("ServerBenchConsole::generateConfig- could not read number_slaves");
    
    in >> buf >> data_size;
    
    if (in.fail())
      throw USGSBenchmark::BenchmarkException
        ("ServerBenchConsole::generateConfig- could not read the data size");

    in >> buf >> explicit_names;
    
    if (in.fail())
      throw USGSBenchmark::BenchmarkException
        ("ServerBenchConsole::generateConfig- could not read the names");
    
    if (explicit_names)
    {
      name_table.resize(number_slaves);
      
      for(counter = 0; counter < number_slaves; ++counter)
      {
        in >> buf >> name_table[counter];
        
        if (in.fail())
          throw USGSBenchmark::BenchmarkException
            ("ServerBenchConsole::generateConfig- could not read hostname");
      }
    }
    
    in.close();
  }
  
  //set up the slave thing
  slave_exe = "benchmarkslave";
  return true;
    
}
  
//****************************************************************************
bool ServerBenchConsole::outputResults()
    throw(USGSBenchmark::BenchmarkException)
{
  //output to the console
  unsigned int counter(0);
  
  
  std::cout << "Master Average: " << mavg << std::endl;
  
  for (counter = 0; counter < savg.size(); ++counter)
  {
    if (explicit_names)
    {
      std::cout << name_table[counter] << " avg: ";
    }
    else
      std::cout << childtid[counter] << " tid avg: ";
    
    std::cout << savg[counter] << std::endl;
  }

  return true; //we are done

}

//****************************************************************************
void ServerBenchConsole::promptUser() 
  throw(USGSBenchmark::BenchmarkException)
{
  std::string buf;       //temporary buffer
  int counter(0);
  std::istringstream in(""); //for answer conversion
  
  //clear the input buffer 
  std::cin.ignore(std::cin.rdbuf()->in_avail());
  
  //start the questions
  std::cout << "Enter the number of runs (default 100):" << std::endl;
  
  std::getline(std::cin, buf);

  if (buf.size())
  {
    //get the number of runs
    in.str(buf);
    in >> num_runs;

    if (in.fail())
    {
      throw USGSBenchmark::BenchmarkException
        ("ServerBenchConsole::promptUser-unable to get the number of runs");
    }
  }
  else
    num_runs = 100;

  std::cout << "Enter the number of slaves (default 1):" << std::endl;
  std::getline(std::cin, buf);

  if (buf.size())
  {
    //get the number of slaves
    in.str(buf);
    in >> number_slaves;

    if (in.fail())
    {
      throw USGSBenchmark::BenchmarkException
        ("ServerBenchConsole::promptUser-unable to get the number of slaves");
    }
  }
  else
    number_slaves = 1;

  std::cout << "Please enter the data buffer size (Default 256):" << std::endl;
  std::getline(std::cin, buf);

  if(buf.size())
  {
    //get the data size
    in.str(buf);
    in >> data_size;
    
    if (in.fail())
    {
      throw USGSBenchmark::BenchmarkException
        ("ServerBenchConsole::promptUser-unable to get the data size");
    }
  }
  else
    data_size = 256;

  std::cout << "Would you like to specify explicit hosts {y/n} (Default n)"
            << std::endl;
  std::getline(std::cin, buf);
  
  if(buf.size())
  {
    if (MiscUtils::cmp_nocase("y", buf) == 0)
    {
      explicit_names = true;
      name_table.resize(number_slaves);

      for(counter = 0; counter < number_slaves; ++counter)
      {
        std::cout << "Please enter hostname number " << counter << ":" 
                  << std::endl;
        std::cin >> name_table[counter];
      }
      //clear the input buffer
      std::cin.ignore(std::cin.rdbuf()->in_avail());
      
    }
    else
    {
      explicit_names = false;
    }
  }
  else
    explicit_names = false;

  //ask to see if they want to save the config
  std::cout << "Do you wish to save the configuration {y/n} (Default n):"
            << std::endl;
  std::getline(std::cin, buf);
  
  if(buf.size())
  {
    if (MiscUtils::cmp_nocase("y", buf) == 0)
    {
      std::cout << "Please enter the configuration filename: " 
                << std::endl;
      std::cin >> buf;
      
      writeConfig(buf);
    }
  }


  //we are done

}
  
//****************************************************************************
void ServerBenchConsole::writeConfig(const std::string & configfile) 
  throw(USGSBenchmark::BenchmarkException)
{
  std::ofstream out;
  int counter(0);

  out.open(configfile.c_str());
  
  if(out.fail())
  {
    throw USGSBenchmark::BenchmarkException
      ("ServerBenchConsole::writeConfig-could not open the config file");
  }

  //output the info
  out << "Number_Runs: " << num_runs << std::endl;
  out << "Number_Slaves: " << number_slaves << std::endl;
  out << "Data_Size: " << data_size << std::endl;
  out << "Explicit_Hosts: " << explicit_names << std::endl;
  
  if (explicit_names)
  {
    for(counter = 0; counter < number_slaves; ++counter)
    {
      out << "Slave_" << counter << ": " << name_table[counter] 
          << std::endl;
    }
  }
  
  out.close();

}

