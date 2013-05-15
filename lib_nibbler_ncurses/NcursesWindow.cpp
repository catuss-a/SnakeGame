//
// NcursesWindow.cpp for nibbler in /home/moreau_c//work/nibbler-2014-moreau_c/lib_nibbler_ncurses
// 
// Made by christopher moreau
// Login   <moreau_c@epitech.net>
// 
// Started on  Thu Mar 17 15:54:57 2011 christopher moreau
// Last update Sun Mar 20 21:32:50 2011 isabel jimenez
//

#include <curses.h>

#include "Game.hh"
#include "Snake.hh"
#include "Grid.hh"

#include "IWindow.hh"
#include "NcursesWindow.hh"

extern "C"
{
  IWindow *getWindow()
  {
    return (new NcursesWindow());
  }
}

NcursesWindow::NcursesWindow()
{
  this->_keyTab[KEY_UP] = Game::Up;
  this->_keyTab[KEY_DOWN] = Game::Down;
  this->_keyTab[KEY_LEFT] = Game::Left;
  this->_keyTab[KEY_RIGHT] = Game::Right;
  this->_keyTab[27] = Game::Esc;
  this->_drawTab[Game::Border] = &NcursesWindow::drawBorder;
  this->_drawTab[Game::Snake] = &NcursesWindow::drawSnake;
  this->_drawTab[Game::Food] = &NcursesWindow::drawFood;
  this->_drawTab[Game::Empty] = &NcursesWindow::drawEmpty;
  this->_drawTab[Game::Bonus] = &NcursesWindow::drawBonus;
}

NcursesWindow::~NcursesWindow()
{
}

int		NcursesWindow::GetEvent()
{
  int ch = getch();

  if (ch == KEY_UP ||
      ch == KEY_DOWN ||
      ch == KEY_LEFT ||
      ch == KEY_RIGHT ||
      ch == 27)
    return (this->_keyTab[ch]);
  return (0);
}

int		NcursesWindow::createImage()
{
  start_color();
  init_pair(1, COLOR_WHITE, COLOR_WHITE);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  init_pair(3, COLOR_RED, COLOR_BLACK);
  init_pair(4, COLOR_YELLOW, COLOR_BLACK);
  curs_set(0);
  return (0);
}

void		NcursesWindow::drawSnake()
{
  attron(COLOR_PAIR(2));
  wprintw(stdscr, "#");
  attroff(COLOR_PAIR(2));
}

void		NcursesWindow::drawFood()
{
  attron(COLOR_PAIR(3));
  wprintw(stdscr, "o");
  attroff(COLOR_PAIR(3));
}

void		NcursesWindow::drawBorder()
{
  attron(COLOR_PAIR(1));
  wprintw(stdscr, "*");
  attroff(COLOR_PAIR(1));
}

void		NcursesWindow::drawBonus()
{
  attron(COLOR_PAIR(4));
  wprintw(stdscr, "@");
  attroff(COLOR_PAIR(4));
}

void		NcursesWindow::drawEmpty()
{
  wprintw(stdscr, " ");
}

int		NcursesWindow::Display(int score, int level)
{
  draw_pointer_t p;
  unsigned int i;

  Game::BoxType			box;
  for (i = 0; i < this->_g->getSizeY(); ++i)
    {
      for (unsigned int j = 0; j < this->_g->getSizeX(); ++j)
	{
	  box = this->_g->getMap(j, i);
	  wmove(stdscr, i, j);
	  p = _drawTab[box];
	  (this->*p)();
	}
    }
  wmove(stdscr, i, 0);
  wprintw(stdscr, "Score: %d Level: %d\n", score, level);
  refresh();
  return (0);
}

int		NcursesWindow::CreateWindow(Grid const *g, float x, float y) throw (std::exception&)
{
  (void)x;
  (void)y;
  this->_g = g;
  initscr();
  raw();
  timeout(0);
  this->createImage();
  keypad(stdscr, TRUE);
  noecho();
  return (0);
}
