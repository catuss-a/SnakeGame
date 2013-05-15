//
// Game.hh for nibbler in /home/moreau_c//work/nibbler/include
// 
// Made by christopher moreau
// Login   <moreau_c@epitech.net>
// 
// Started on  Thu Mar  3 13:34:49 2011 christopher moreau
// Last update Sun Mar 20 16:26:32 2011 christopher moreau
//

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
