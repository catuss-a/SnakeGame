##
## Makefile for nibbler in /home/moreau_c//work/nibbler/lib_nibbler_sfml
## 
## Made by christopher moreau
## Login   <moreau_c@epitech.net>
## 
## Started on  Wed Mar  2 14:56:26 2011 christopher moreau
## Last update Sun Mar 20 12:42:19 2011 christopher moreau
##

NAME 		=	lib_nibbler_ncurses.so
SRCS 		=	NcursesWindow.cpp

OBJS 		=	$(SRCS:.cpp=.o)

CC		= g++
CPPFLAGS 	+= -W -Wextra -Wall -Werror -fPIC -I../include -ggdb
LDFLAGS		= -lncurses -shared

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