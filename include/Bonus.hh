
#ifndef BON_H
# define BON_H

#include "Food.hh"

namespace Core
{
  class Bonus
  {
  public:
    ~Bonus();
    Bonus(int, int, Grid const &);

    Core::Coord 	getCoord() const;

    void		reset(Grid const &, Core::Food &);
    void		decrTime();
    void		setIsthere(bool);
    bool		getIsthere() const;
    int			getTime() const;
 private:
    Bonus(Bonus const&);
    Bonus&		operator=(Bonus const&);

  private:
    Core::Coord		_coord;
    int			_x;
    int			_y;
    bool		_isthere;
    int			_time;
  };
}

#endif // !BON_H
