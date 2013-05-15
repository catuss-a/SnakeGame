//
// DlLoader.cpp for DlLoader in /home/moreau_c//work/nibbler/nibbler-2014-moreau_c/nibbler
// 
// Made by christopher moreau
// Login   <moreau_c@epitech.net>
// 
// Started on  Wed Mar  9 22:19:46 2011 christopher moreau
// Last update Sun Mar 20 21:56:30 2011 isabel jimenez
//

#include <dlfcn.h>
#include <iostream>
#include <string>

#include "Excp.hh"
#include "DlLoader.hpp"

Dynamic::DlLoader::DlLoader(std::string const& filename, int flag) throw (std::exception&) : _filename(filename)
{
  this->_handle = dlopen(this->_filename.c_str(), flag);
  if (!this->_handle)
    {
      std::cout << dlerror() << std::endl;
      throw (excp("Unable to open dynamic library: " + this->_filename));
    }
}

Dynamic::DlLoader::~DlLoader()
{
  dlclose(this->_handle);
}


