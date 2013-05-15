
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


