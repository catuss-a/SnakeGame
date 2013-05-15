
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