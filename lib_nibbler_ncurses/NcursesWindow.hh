
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
