//
// Snake.cpp for nibbler in /home/moreau_c//work/nibbler
// 
// Made by christopher moreau
// Login   <moreau_c@epitech.net>
// 
// Started on  Wed Mar  2 14:16:00 2011 christopher moreau
// Last update Sun Mar 20 21:01:53 2011 christopher moreau
//

#include <iostream>

#include "Game.hh"
#include "Snake.hh"

Core::Snake::Snake(unsigned int x, unsigned int y) : _dir(Game::Up)
{
  for (unsigned int i = 0; i < 4; ++i)
    {
      Core::Coord cas;

      cas.first = x / 2;
      cas.second = (y / 2) + i;
      this->_coord.push_back(cas);
    }
}

Core::Snake::~Snake()
{
}

Core::Snake::Snake(Snake const& s)
{
  *this = s;
}

Core::Snake		&Core::Snake::operator=(Snake const& other)
{
  if (this != &other)
    {
      this->_dir = other._dir;
      this->_coord = other._coord;
    }
  return (*this);
}

void			Core::Snake::setDir(Game::KeyCode dir)
{
  if ((this->_dir == Game::Up && dir != Game::Down) ||
      (this->_dir == Game::Left && dir != Game::Right) ||
      (this->_dir == Game::Down && dir != Game::Up) ||
      (this->_dir == Game::Right && dir != Game::Left))
    this->_dir = dir;
}

Game::KeyCode		Core::Snake::getDir() const
{
  return (this->_dir);
}

bool			Core::Snake::isEmpty(unsigned int x,
					     unsigned int y,
					     Grid const &map)
{
  return (map.getMap(x, y) == Game::Empty ||
	  map.getMap(x, y) == Game::Food ||
	  map.getMap(x, y) == Game::Bonus);
}

bool		Core::Snake::moveUp(Grid const &map, Core::Food &f, Core::Bonus &b)
{
  Coord			head;

  head.first = this->_coord.front().first;
  head.second = this->_coord.front().second - 1;
  if (this->isEmpty(head.first, head.second, map) == false)
      return (false);
  this->_coord.push_front(head);
  if (map.getMap(head.first, head.second) == Game::Food)
    f.reset(map);
  else
    {
      if (map.getMap(head.first, head.second) == Game::Bonus)
	b.reset(map, f);
      this->_coord.pop_back();
    }

  return (true);
}

bool			Core::Snake::moveDown(Grid const &map, Core::Food &f, Core::Bonus &b)
{
  Coord			head;

  head.first = this->_coord.front().first;
  head.second = this->_coord.front().second + 1;
  if (this->isEmpty(head.first, head.second, map) == false)
      return (false);
  this->_coord.push_front(head);
  if (map.getMap(head.first, head.second) == Game::Food)
    f.reset(map);
  else
    {
      if (map.getMap(head.first, head.second) == Game::Bonus)
	b.reset(map, f);
      this->_coord.pop_back();
    }
  return (true);
}

bool			Core::Snake::moveRight(Grid const &map, Core::Food &f, Core::Bonus &b)
{
  Coord			head;

  head.first = this->_coord.front().first + 1;
  head.second = this->_coord.front().second;
  if (this->isEmpty(head.first, head.second, map) == false)
      return (false);
  this->_coord.push_front(head);
  if (map.getMap(head.first, head.second) == Game::Food)
    f.reset(map);
  else
    {
      if (map.getMap(head.first, head.second) == Game::Bonus)
	b.reset(map, f);
      this->_coord.pop_back();
    }
  return (true);
}

bool			Core::Snake::moveLeft(Grid const &map, Core::Food &f, Core::Bonus &b)
{
  Coord			head;

  head.first = this->_coord.front().first - 1;
  head.second = this->_coord.front().second;
  if (this->isEmpty(head.first, head.second, map) == false)
      return (false);
  this->_coord.push_front(head);
  if (map.getMap(head.first, head.second) == Game::Food)
    f.reset(map);
  else
    {
      if (map.getMap(head.first, head.second) == Game::Bonus)
	b.reset(map, f);
      this->_coord.pop_back();
    }
  return (true);
}


Core::CoordList	const	&Core::Snake::getCoord() const
{
  return (this->_coord);
}

Core::Coord const	&Core::Snake::getHead() const
{
  return (this->_coord.front());
}

Core::Coord const	&Core::Snake::getTail() const
{
  return (this->_coord.back());
}
