//
// DlManager.cpp for  in /home/jimene_i//nibbler-2014-moreau_c
// 
// Made by isabel jimenez
// Login   <jimene_i@epitech.net>
// 
// Started on  Mon Mar 14 16:35:06 2011 isabel jimenez
// Last update Tue Mar 15 16:06:26 2011 christopher moreau
//

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
