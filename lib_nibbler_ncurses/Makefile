
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