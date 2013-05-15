//
// Excp.hh for  in /home/moreau_c//work/nibbler-2014-moreau_c
// 
// Made by christopher moreau
// Login   <moreau_c@epitech.net>
// 
// Started on  Sun Mar 20 16:05:18 2011 christopher moreau
// Last update Sun Mar 20 16:08:49 2011 christopher moreau
//

#ifndef _EXCP_H_
# define _EXCP_H_

#include <iostream>

class excp : public std::exception
{

public:
  excp();
  excp(const std::string& s);
  virtual ~excp() throw();
  excp(excp const&);
  excp&  operator=(excp const &);

  virtual const char* what() const throw();

private:
  std::string	_s;
};

#endif // !_EXCP_H_ 
