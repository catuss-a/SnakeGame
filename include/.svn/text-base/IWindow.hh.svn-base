//
// IWindow.hh for lib_nibbler_sfml in /home/moreau_c//work/nibbler/lib_nibbler_sfml
// 
// Made by christopher moreau
// Login   <moreau_c@epitech.net>
// 
// Started on  Wed Mar  2 16:24:07 2011 christopher moreau
// Last update Sun Mar 20 21:28:46 2011 isabel jimenez
//

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
