
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
