//
// DlManager.hpp for DlManager in /home/moreau_c//work/nibbler-2014-moreau_c/DlManager
// 
// Made by christopher moreau
// Login   <moreau_c@epitech.net>
// 
// Started on  Fri Mar 11 14:01:34 2011 christopher moreau
// Last update Sun Mar 20 16:09:15 2011 christopher moreau
//

#ifndef		DLMANAGER_HPP_
# define	DLMANAGER_HPP_

namespace Dynamic
{
  template<class T>
  class DlManager
  {
  public:
    DlManager(std::string const& filename,
	      std::string const& instance_name = "getInstance");
    ~DlManager();

    T	*getInstance() const;

  private:
    DlManager(DlManager const&);
    DlManager& operator=(DlManager const&);

    DlLoader		*loader;
    T			*instance;
  };
};

#endif		// !DLMANAGER_HPP_
