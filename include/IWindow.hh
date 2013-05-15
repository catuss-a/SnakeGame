
#ifndef		IWINDOW_HH_
# define	IWINDOW_HH_

#include	"Snake.hh"

class		IWindow
{
public:
  ~IWindow();

public:
  virtual int	CreateWindow(Grid const*, float, float) throw (std::exception&) = 0;
  virtual int	Display(int, int) = 0;
  virtual int	GetEvent() = 0;
  virtual int	createImage() = 0;
};

#endif		// !IWINDOW_HH_
