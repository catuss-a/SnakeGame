##
## Makefile for nibbler in /home/moreau_c//work/nibbler/lib_nibbler_sfml
## 
## Made by christopher moreau
## Login   <moreau_c@epitech.net>
## 
## Started on  Wed Mar  2 14:56:26 2011 christopher moreau
## Last update Sun Mar 20 18:27:01 2011 axel catusse
##

NAME 		=	lib_nibbler_opengl.so
SRCS 		=	OpenglWindow.cpp \
			sdlglutils.cpp

OBJS 		=	$(SRCS:.cpp=.o)

CC		= g++
CPPFLAGS 	+= -W -Wextra -Wall -fPIC -I../include -ggdb
LDFLAGS		= -lGL -shared -lSDL -lGLU -lSDL_image -lSDL_ttf

RM		= rm -f

$(NAME)		: $(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

all		: $(NAME)

re		: fclean all

clean		:
		$(RM) $(OBJS)

fclean		: clean
		$(RM) $(NAME)

.PHONY		: clean fclean re