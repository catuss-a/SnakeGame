
#ifndef		DLLOADER_HH_
# define	DLLOADER_HH_

# include "Excp.hh"

namespace Dynamic
{
  class DlLoader
  {
  public:
    DlLoader(std::string const&, int flag = RTLD_LAZY) throw (std::exception&);
    ~DlLoader();

    template<typename T>
    T		getInstance(std::string const& instanceName) throw (std::exception&)
    {
      typedef	T (*sym)(void);
      T		instance;
      sym	func;

      func = reinterpret_cast<sym>(dlsym(this->_handle, instanceName.c_str()));
      if (func == NULL)
	{
	  std::cerr << dlerror() << std::endl;
	  throw (excp("Cannot load symbol " + instanceName + " from library."));
	}
      instance = func();
      return (instance);
    }

  private:
    DlLoader(DlLoader const &);
    DlLoader& operator=(DlLoader const &);

    void		*_handle;
    std::string const&	_filename;
  };
};

#endif		// !DLLOADER_HH_
