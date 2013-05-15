
#ifndef OPENGLWINDOW_HH_
# define OPENGLWINDOW_HH_

#include <map>
#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL/SDL_image.h>

#include "Game.hh"
#include "Snake.hh"
#include "Grid.hh"
#include "IWindow.hh"
#include "OpenglWindow.hh"

class OpenglWindow : public IWindow
{
public:
  OpenglWindow();
  virtual ~OpenglWindow();


public:
  int			CreateWindow(Grid const *, float, float) throw (std::exception&);
  int			Display(int, int);
  int			GetEvent();
  int			createImage();
  void		        drawMap();
  GLuint		loadImage(std::string const &fileName);

  SDL_Surface		*flipSurface(SDL_Surface *surface);
  GLuint		loadTexture(const char *filename);

  void			drawFullBox(int x, int y, int z) const;
  void			drawEmptyBox(int x, int y, int z) const;
  void			drawSnake(int x, int y, int z) const;
  void			drawFood(int x, int y, int z, GLuint texture) const;

private:

  float			_box_x;
  float			_box_y;

  int			lookatx;
  int			lookaty;
  int			lookatz;

  Grid const		*_grid;
  Core::Snake		*_snake;

  GLuint		fullBoxTexture;
  GLuint		floor;
  GLuint		snakeTexture;
  GLuint		foodTexture;
  GLuint		bonusTexture;

  std::map<int, Game::KeyCode> _keyTab;
};


#endif // !OPENGLWINDOW_HH_
