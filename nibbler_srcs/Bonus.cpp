#include <time.h>
#include <stdlib.h>
#include <iostream>

#include "Game.hh"
#include "Grid.hh"
#include "Bonus.hh"

Core::Bonus::Bonus(int i, int j, Grid const &g) : _x(i),
						  _y(j),
						  _isthere(false),
						  _time(40)
{
  do
    {
      this->_coord.first = random() % this->_x;
      this->_coord.second = random() % this->_y;
    } while (g.getMap(this->_coord.first, this->_coord.second) !=Game::Empty);
}

Core::Bonus::~Bonus()
{
}

void			Core::Bonus::reset(Grid const &g, Core::Food &f)
{
  int i = 0;

  this->_isthere = false;
  f.setScore(f.getValue() + 10);
  f.setValue(f.getValue() + 1);
  this->_time = 40;
  do
    {
      i = random() % 50;
      this->_coord.first = random() % this->_x;
      this->_coord.second = random() % this->_y;
    } while (g.getMap(this->_coord.first, this->_coord.second) !=Game::Empty && i != 42);
}

void			Core::Bonus::decrTime()
{
  this->_time -= 1;
}

void			Core::Bonus::setIsthere(bool b)
{
  this->_isthere = b;
}

int			Core::Bonus::getTime() const
{
  return (this->_time);
}

bool			Core::Bonus::getIsthere() const
{
  return (this->_isthere);
}


Core::Coord		Core::Bonus::getCoord() const
{
  return (this->_coord);
}
