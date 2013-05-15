
#ifndef NIB_H
# define NIB_H

# include "Snake.hh"
# include "Food.hh"

# define ENV "XAUTHORITY"

namespace Core
{
  class Nibbler
  {
  public:
    Nibbler(const char *filename, unsigned int, unsigned int);
    ~Nibbler();

  public:
    bool		handleEvent();
    bool		moveSnake();
    void		setLevel();
    void		operator()();

  private:
    Nibbler(Nibbler const &);
    Nibbler& operator=(Nibbler const &);

    Dynamic::DlLoader					loader;
    IWindow						*_window;
    Core::Snake						_snake;
    Grid						_g;
    Core::Food						_food;
    Core::Bonus						_bonus;
    std::map<int, Game::KeyCode>			_keyMap;
    std::map<Game::KeyCode, Snake::movePointer_t>	_pointerMap;
    int							speed;
    int							level;
  };
};

#endif // !NIB_H
