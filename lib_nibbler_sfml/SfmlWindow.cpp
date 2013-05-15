
#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>

#include "Excp.hh"
#include "Game.hh"
#include "Snake.hh"
#include "Grid.hh"
#include "IWindow.hh"
#include "SfmlWindow.hh"

extern "C"
{
  IWindow *getWindow()
  {
    return (new SfmlWindow());
  }
}

std::string const SfmlWindow::background = "img/background.jpg";
std::string const SfmlWindow::circle = "img/snake.png";
std::string const SfmlWindow::food = "img/food.png";
std::string const SfmlWindow::bonus = "img/bonus.png";

SfmlWindow::SfmlWindow() : _g(NULL)
{
  this->_keyTab[sf::Key::Up] = Game::Up;
  this->_keyTab[sf::Key::Down] = Game::Down;
  this->_keyTab[sf::Key::Left] = Game::Left;
  this->_keyTab[sf::Key::Right] = Game::Right;
  this->_keyTab[sf::Key::Escape] = Game::Esc;
  this->_drawTab[Game::Border] = &SfmlWindow::drawBorder;
  this->_drawTab[Game::Snake] = &SfmlWindow::drawSnake;
  this->_drawTab[Game::Food] = &SfmlWindow::drawFood;
  this->_drawTab[Game::Bonus] = &SfmlWindow::drawBonus;
}

SfmlWindow::~SfmlWindow()
{
}

int			SfmlWindow::GetEvent()
{
  sf::Event		Event;

  while (App.GetEvent(Event))
    {
      if (Event.Type == sf::Event::KeyPressed)
	return (this->_keyTab[Event.Key.Code]);
    }
  return (0);
}

int			SfmlWindow::createImage()
{
    this->borderImg.Create(this->_box_x, this->_box_y, sf::Color(92, 164,92));
  if (!this->snakeImg.LoadFromFile(this->circle))
    {
      throw (excp("Fail to load image " + this->circle));
    }
  if (!this->foodImg.LoadFromFile(this->food))
    {
      throw (excp("Fail to load image " + this->food));
    }
  if (!this->bonusImg.LoadFromFile(this->bonus))
    {
      throw (excp("Fail to load image " + this->bonus));
    }
  return (0);
}

int			SfmlWindow::Display(int score, int level)
{
  this->App.Clear();
  this->App.Draw(this->bgSprite);
  this->drawMap();
  this->drawScore(score, level);
  this->App.Display();
  return (0);
}

void			SfmlWindow::drawScore(int score, int level)
{
  std::ostringstream os;
  os << score;
  std::ostringstream oss;
  oss << level;
  this->score.SetText("Score : "  + os.str() + " Level : " + oss.str());
  this->score.SetFont(sf::Font::GetDefaultFont());
  this->score.SetColor(sf::Color(0, 0, 0));
  this->score.SetSize(this->_box_y > this->_box_x ? this->_box_y : this->_box_x);
  this->score.SetPosition(0.f, 0.f);
  this->App.Draw(this->score);
}

void			SfmlWindow::drawBorder(unsigned int i, unsigned int j)
{

  this->borderSprite.SetImage(this->borderImg);
  this->borderSprite.SetPosition(j * this->_box_x, i * this->_box_y);
  this->App.Draw(this->borderSprite);
}

void			SfmlWindow::drawSnake(unsigned int i, unsigned int j)
{
  this->snakeSprite.SetImage(this->snakeImg);
  this->snakeSprite.Resize(this->_box_x, this->_box_y);
  this->snakeSprite.SetPosition(j * this->_box_x, i * this->_box_y);
  this->App.Draw(this->snakeSprite);
}

void			SfmlWindow::drawBonus(unsigned int i, unsigned int j)
{
  this->bonusSprite.SetImage(this->bonusImg);
  this->bonusSprite.Resize(this->_box_x, this->_box_y);
  this->bonusSprite.SetPosition(j * this->_box_x, i * this->_box_y);
  this->App.Draw(this->bonusSprite);
}

void			SfmlWindow::drawFood(unsigned int i, unsigned int j)
{
  this->foodSprite.SetImage(this->foodImg);
  this->foodSprite.Resize(this->_box_x, this->_box_y);
  this->foodSprite.SetPosition(j * this->_box_x, i * this->_box_y);
  this->App.Draw(this->foodSprite);
}

void			SfmlWindow::drawMap()
{
  draw_pointer_t		p;
  Game::BoxType			box;

  for (unsigned int i = 0; i < this->_g->getSizeY(); ++i)
    {
      for (unsigned int j = 0; j < this->_g->getSizeX(); ++j)
	{
	  box = this->_g->getMap(j, i);
	  if (box != Game::Empty)
	    {
	      p = this->_drawTab[box];
	      (this->*p)(i, j);
	    }
	}
    }
}

int			SfmlWindow::CreateWindow(Grid const *g, float box_x, float box_y) throw (std::exception&)
{
  this->_g = g;
  this->_box_x = box_x;
  this->_box_y = box_y;
  if (!this->bgImg.LoadFromFile(this->background))
    {
      throw (excp("Fail to load image " + this->background));
    }
  try
    {
      this->bgSprite.SetImage(this->bgImg);
      this->bgSprite.Resize(800,600);
      this->App.Create(sf::VideoMode(800, 600, 32), "Nibbler");
      this->createImage();
    }
  catch (...)
    {
      throw (excp("Sfml create failed"));
    }
  return (0);
}
