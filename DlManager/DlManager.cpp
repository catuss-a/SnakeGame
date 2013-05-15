
#include <dlfcn.h>
#include <string>
#include "DlLoader.hpp"
#include "DlManager.hpp"

template<typename T>
Dynamic::DlManager<T>::DlManager(std::string const & filename, std::string const & instance_name) : loader(new DlLoader(filename))
{
  this->instance = this->loader->getInstance(instance_name);
}

template<typename T>
Dynamic::DlManager<T>::~DlManager()
{
  delete this->loader;
}

template<typename T>
T	*Dynamic::DlManager<T>::getInstance() const
{
  return (this->instance);
}
