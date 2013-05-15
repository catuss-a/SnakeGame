
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