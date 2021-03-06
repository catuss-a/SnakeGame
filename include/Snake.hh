
#ifndef			SNAKE_HH_
# define		SNAKE_HH_

# include		<list>
# include		"Grid.hh"
# include		"Game.hh"
# include		"Food.hh"
# include		"Bonus.hh"

namespace		Core
{

  class			Snake
  {
  public:
    Snake(unsigned int, unsigned int);
    ~Snake();
    Snake(Snake const&);
    Snake& operator=(Snake const&);

    typedef bool (Snake::*movePointer_t)(Grid const &, Core::Food&, Core::Bonus &);
    Game::KeyCode		getDir() const;
    void			setDir(Game::KeyCode);
    CoordList			const &getCoord() const;
    Core::Coord const		&getHead() const;
    Core::Coord const		&getTail() const;

    bool			moveUp(Grid const &, Core::Food &, Core::Bonus &);
    bool			moveDown(Grid const &, Core::Food &, Core::Bonus &);
    bool			moveLeft(Grid const &, Core::Food &, Core::Bonus &);
    bool			moveRight(Grid const &, Core::Food &, Core::Bonus &);

    bool			isEmpty(unsigned int, unsigned int, Grid const &);
    bool			isFood(unsigned int, unsigned int, Grid const &);
  private:
    Game::KeyCode		_dir;
    CoordList			_coord;
  };
}

#endif		// !SNAKE_HH_
