
#include <dlfcn.h>

#include <iostream>
#include <map>
#include <vector>
#include <stdio.h>

#include "DlLoader.hpp"
#include "DlManager.hpp"
#include "Game.hh"
#include "Excp.hh"
#include "Snake.hh"
#include "Food.hh"
#include "Grid.hh"
#include "Bonus.hh"
#include "IWindow.hh"
#include "Nibbler.hh"

Core::Nibbler::Nibbler(const char *filename, unsigned int x, unsigned int y) :
  loader(filename),
  _snake(x, y),
  _g(x, y, this->_snake),
  _food(x, y, this->_g),
  _bonus(x, y, this->_g)
{
  try
    {
      this->_window = this->loader.getInstance<IWindow*>("getWindow");
    }
  catch (std::exception &e)
    {
      throw;
    }
  this->speed = 100000;
  this->level = 1;
  this->_keyMap[42] = Game::Up;
  this->_keyMap[43] = Game::Down;
  this->_keyMap[44] = Game::Right;
  this->_keyMap[45] = Game::Left;
  this->_pointerMap[Game::Up] = &Snake::moveUp;
  this->_pointerMap[Game::Down] = &Snake::moveDown;
  this->_pointerMap[Game::Left] = &Snake::moveLeft;
  this->_pointerMap[Game::Right] = &Snake::moveRight;
}

Core::Nibbler::~Nibbler()
{
}

bool			Core::Nibbler::handleEvent()
{
  int			key;

  key = this->_window->GetEvent();
  if (key == Game::Up || key == Game:: Down || key == Game::Left || key == Game::Right)
      this->_snake.setDir(this->_keyMap[key]);
  if (key == Game::Esc)
    return (false);
  return (true);
}

bool			Core::Nibbler::moveSnake()
{
  Core::Snake::movePointer_t f;
  Core::Coord posHead;
  Core::Coord posTail;

  this->_g.foodToMap(this->_food.getCoord());
  this->_g.bonusToMap(this->_bonus, this->_food);
  posTail = this->_snake.getTail();
  f = this->_pointerMap[this->_snake.getDir()];
  if ((this->_snake.*f)(this->_g, this->_food, this->_bonus) == false)
      return (false);
  posHead = this->_snake.getHead();
  this->_g.snakeToMap(posHead, posTail);
  return (true);
}

static int		fibonaci(int level)
{
  if (level <= 1)
    return 100;
  else
    return ((fibonaci(level - 1) + fibonaci(level - 2)));
}

void			Core::Nibbler::setLevel()
{
  if (this->_food.getScore() >= fibonaci(this->level))
    {
      if (this->level <= 9)
	this->speed -= this->_food.getScore() * 5;
      ++this->level;
    }
}

void			Core::Nibbler::operator()()
{
  float		box_x;
  float		box_y;
  bool		run = true;

  box_x = (800.0 / this->_g.getSizeX());
  box_y = (600.0 / this->_g.getSizeY());
  this->_window->CreateWindow(&this->_g, box_x, box_y);
  this->_window->Display(this->_food.getScore(), this->level);
  while (run)
    {
      try
	{
	  this->_window->Display(this->_food.getScore(), this->level);
	}
      catch (...)
	{
	  throw (excp("Fail to display"));
	}
      if (!this->handleEvent())
	run = false;
      if (!this->moveSnake())
      	run = false;
      this->setLevel();
      usleep(this->speed);
    }
}
