
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
