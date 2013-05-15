
#include <dlfcn.h>
#include <cstdlib>

#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>

#include "DlLoader.hpp"
#include "DlManager.hpp"
#include "Game.hh"
#include "Snake.hh"
#include "Grid.hh"
#include "Bonus.hh"
#include "IWindow.hh"
#include "Nibbler.hh"

static void		launch_game(char const* filename,
				    unsigned int x, unsigned int y)
{
  Core::Nibbler		n(filename, x, y);
  srandom(time(NULL));
  n();
}

static void		parse_arg(char **av, int *x, int *y)
{
  std::istringstream	a(av[1]);
  std::istringstream	b(av[2]);

  a >> *x;
  b >> *y;
}

int			main(int ac, char **av)
{
  int			x;
  int			y;


  if (ac == 4)
    {
      if ((getenv(ENV)) == NULL)
	{
	  std::cerr << "Unable to load environment" << std::endl;
	  return (-1);
	}
      parse_arg(av, &x, &y);
      if (x < 20 || y < 20 || x > 60 || y > 60 )
	{
	  std::cerr << "Usage: x and y must be between 20 and 60" << std::endl;
	  return (-1);
	}
      try
	{
	  launch_game(av[3], x, y);
	}
      catch (std::exception &e)
	{
	  std::cerr << e.what() << std::endl;
	  return (-1);
	}
      return (0);
    }
  std::cerr << "Usage: ./nibbler x y ./lib, x and y must be between 20 and 60" << std::endl;
  return (-1);
}
