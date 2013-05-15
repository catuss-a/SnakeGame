//
// Food.hh for  in /home/jimene_i//nibbler-2014-moreau_c/nibbler_srcs
// 
// Made by isabel jimenez
// Login   <jimene_i@epitech.net>
// 
// Started on  Wed Mar 16 15:16:40 2011 isabel jimenez
// Last update Sun Mar 20 18:31:51 2011 christopher moreau
//

#ifndef _FOOD_H
# define _FOOD_H

namespace Core
{
  class Food
  {
  public:
    ~Food();
    Food(int, int, Grid const &);

    Core::Coord 	getCoord() const;
    int			getScore() const;
    int			getValue() const;
    void		setValue(int);
    void		setScore(int);
    void		reset(Grid const &);
  private:
    Food(Food const&);
    Food&		operator=(Food const&);

  private:
    Core::Coord		_coord;
    int			_x;
    int			_y;
    int			_score;
    int			_value;
  };
}

#endif // !_FOOD_H
