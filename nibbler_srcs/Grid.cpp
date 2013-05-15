
#include <cstdlib>

#include <iostream>
#include <vector>

#include "Game.hh"
#include "Snake.hh"
#include "Grid.hh"
#include "Bonus.hh"
Grid::Grid()
{
}

Grid::Grid(unsigned int x, unsigned int y, Core::Snake const &snake) : _size_x(x),
								       _size_y(y)
{
  Core::CoordList coord = snake.getCoord();
  Core::CoordList::iterator begin = coord.begin();
  Core::CoordList::iterator end = coord.end();

  this->_map.resize(x * y);
  for (unsigned int i = 0; i < y; ++i)
    {
      for (unsigned int j = 0; j < x; ++j)
	{
	  if ((i == 0) || (i == (y - 1)) || (j == 0) || (j == (x - 1)))
	    this->setMap(j, i, Game::Border);
	  else
	    this->setMap(j, i, Game::Empty);
	}
    }
  for (; begin != end; ++begin)
    this->setMap((*begin).first, (*begin).second, Game::Snake);
}

Grid::~Grid()
{
}

Grid::Grid(Grid const &g)
{
  *this = g;
}

Grid& Grid::operator=(Grid const &g)
{
  if (this != &g)
    {
      this->_size_x = g._size_x;
      this->_size_y = g._size_y;
      this->_map = g._map;
    }
  return (*this);
}

int		Grid::accessMap(const unsigned int x, const unsigned int y) const
{
  return ((y * this->_size_x) + x);
}

void		Grid::setMap(unsigned int x,
			     unsigned int y,
			     Game::BoxType b)
{
  unsigned int	idx = this->accessMap(x, y);

  this->_map[idx] = b;
}

Game::BoxType	Grid::getMap(const unsigned int x, const unsigned int y) const
{
  unsigned int	idx = this->accessMap(x, y);

  return (this->_map[idx]);
}

unsigned int	Grid::getSizeX() const
{
  return (this->_size_x);
}

unsigned int	Grid::getSizeY() const
{
  return (this->_size_y);
}

void		Grid::foodToMap(Core::Coord const & food)
{
  this->setMap(food.first, food.second, Game::Food);
}

void		Grid::bonusToMap(Core::Bonus & bonus, Core::Food &food)
{
  int i = 0;
  if (bonus.getIsthere() == false)
    {
      i = random() % 100;
      if (i == 18)
	bonus.setIsthere(true);
    }
  else
    {
      this->setMap(bonus.getCoord().first, bonus.getCoord().second, Game::Bonus);
      bonus.decrTime();
      if (bonus.getTime() == 0)
	{
	  this->setMap(bonus.getCoord().first, bonus.getCoord().second, Game::Empty);
	  bonus.reset(*this, food);
	  bonus.setIsthere(false);
	}
    }
}

void		Grid::snakeToMap(Core::Coord const &head,
				 Core::Coord const &tail)
{
  this->setMap(tail.first, tail.second, Game::Empty);
  this->setMap(head.first, head.second, Game::Snake);
}

