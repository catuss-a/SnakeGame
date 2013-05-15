
#ifndef		GAME_HH_
# define	GAME_HH_

namespace Game
{
  enum KeyCode
    {
      Up = 42,
      Down,
      Right,
      Left,
      Esc,
      Quit
    };

  enum BoxType
    {
      Empty = 4242,
      Border,
      Snake,
      Bonus,
      Food
    };
};

#endif		// !GAME_HH_
