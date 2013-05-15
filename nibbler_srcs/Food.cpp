
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include "Game.hh"
#include "Grid.hh"
#include "Food.hh"

Core::Food::Food(int i, int j, Grid const &g) :	_x(i),
						_y(j),
						_score(0),
						_value(1)
{
  do
    {
      this->_coord.first = random() % this->_x;
      this->_coord.second = random() % this->_y;
    } while (g.getMap(this->_coord.first, this->_coord.second) !=Game::Empty);
}

Core::Food::~Food()
{
}

void			Core::Food::reset(Grid const &g)
{
  this->_score += this->_value;
  this->_value += 1;
  do
    {
      this->_coord.first = random() % this->_x;
      this->_coord.second = random() % this->_y;
    } while (g.getMap(this->_coord.first, this->_coord.second) !=Game::Empty);
}

void			Core::Food::setValue(int i)
{
  this->_value += i;
}

int			Core::Food::getValue() const
{
  return (this->_value);
}

void			Core::Food::setScore(int i)
{
  this->_score += i;
}

Core::Coord		Core::Food::getCoord() const
{
  return (this->_coord);
}

int			Core::Food::getScore() const
{
  return (this->_score);
}
