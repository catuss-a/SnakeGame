//
// NcursesWindow.hh for nibbler in /home/moreau_c//work/nibbler-2014-moreau_c/lib_nibbler_ncurses
// 
// Made by christopher moreau
// Login   <moreau_c@epitech.net>
// 
// Started on  Thu Mar 17 15:55:08 2011 christopher moreau
// Last update Sun Mar 20 21:29:41 2011 isabel jimenez
//

#ifndef		__NCURSES_HH
# define	__NCURSES_HH

# include <map>

class NcursesWindow : public IWindow
{
public:
  typedef void (NcursesWindow::*draw_pointer_t)();

  NcursesWindow();
  virtual ~NcursesWindow();

  int CreateWindow(Grid const*, float, float) throw (std::exception&);
  int Display(int, int);
  int GetEvent();
  int createImage();

  void drawBorder();
  void drawBonus();
  void drawSnake();
  void drawFood();
  void drawEmpty();

private:
  NcursesWindow(NcursesWindow const &);
  NcursesWindow& operator=(NcursesWindow const &);
  Grid		const				*_g;
  std::map<int, Game::KeyCode>			_keyTab;
  std::map<Game::BoxType, draw_pointer_t>	_drawTab;
};

#endif
