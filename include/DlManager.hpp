
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
