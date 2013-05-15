//
// Excp.cpp for  in /home/moreau_c//work/nibbler-2014-moreau_c
// 
// Made by christopher moreau
// Login   <moreau_c@epitech.net>
// 
// Started on  Sun Mar 20 12:53:25 2011 christopher moreau
// Last update Sun Mar 20 16:08:05 2011 christopher moreau
//

#include "Excp.hh"

excp::excp(): _s("Execption")
{
}

excp::excp(const std::string& s): _s(s)
{
}

excp::~excp() throw()
{
}

excp::excp(excp const &e)
{
  *this = e;
}

excp& excp::operator=(excp const &e)
{
  if (this != &e)
    this->_s = e._s;
  return (*this);
}

const char* excp::what() const throw()
{
  return (this->_s.c_str());
}
