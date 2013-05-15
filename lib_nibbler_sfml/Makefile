##
## Makefile for nibbler in /home/moreau_c//work/nibbler/lib_nibbler_sfml
## 
## Made by christopher moreau
## Login   <moreau_c@epitech.net>
## 
## Started on  Wed Mar  2 14:56:26 2011 christopher moreau
## Last update Thu Mar 17 23:17:55 2011 christopher moreau
##

NAME 		=	lib_nibbler_sfml.so
SRCS 		=	SfmlWindow.cpp

OBJS 		=	$(SRCS:.cpp=.o)

CXX		= g++
CXXFLAGS 	+= -W -Wextra -Wall -Werror -fPIC -I../include -ggdb
LDFLAGS		= -lsfml-system -lsfml-graphics -lsfml-window -shared

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