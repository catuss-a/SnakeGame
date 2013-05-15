
#ifndef		SFMLWINDOW_HH_
# define	SFMLWINDOW_HH_

#include "Snake.hh"

# define BACKGROUND "img/background.jpg"

class			SfmlWindow : public IWindow
{
public:
  SfmlWindow();
  virtual ~SfmlWindow();

  static std::string const background;
  static std::string const circle;
  static std::string const food;
  static std::string const bonus;

  typedef void (SfmlWindow::*draw_pointer_t)(unsigned int,unsigned int);

public:
  int			CreateWindow(Grid const*, float, float) throw (std::exception&);
  int			Display(int, int);
  int			GetEvent();
  int		        createImage();

  void		        drawMap();
  void		        drawBorder(unsigned int,unsigned int);
  void		        drawBonus(unsigned int,unsigned int);
  void		        drawSnake(unsigned int, unsigned int);
  void		        drawFood(unsigned int, unsigned int);
  void			drawScore(int , int);

private:
  SfmlWindow(SfmlWindow const &);
  SfmlWindow& operator=(SfmlWindow const &);

  sf::RenderWindow	App;


  sf::Image		snakeImg;
  sf::Image		bonusImg;
  sf::Image		bgImg;
  sf::Image		borderImg;
  sf::Image		foodImg;

  sf::Sprite		snakeSprite;
  sf::Sprite		bonusSprite;
  sf::Sprite		bgSprite;
  sf::Sprite		borderSprite;
  sf::Sprite		foodSprite;

  float			_box_x;
  float			_box_y;

  Grid const		*_g;

  sf::String		score;
  std::map<sf::Key::Code, Game::KeyCode>	_keyTab;
  std::map<Game::BoxType, draw_pointer_t>	_drawTab;
};

#endif		// !SFMLWINDOW_HH_
