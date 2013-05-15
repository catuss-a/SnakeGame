##
## Makefile for Nibbler in /home/moreau_c//work/nibbler/nibbler-2014-moreau_c
## 
## Made by christopher moreau
## Login   <moreau_c@epitech.net>
## 
## Started on  Fri Mar 11 13:34:20 2011 christopher moreau
## Last update Sun Mar 20 22:49:56 2011 isabel jimenez
##

CORE_NAME	= 	nibbler
CORE_DIR	= 	nibbler_srcs
DLMANAGER_DIR	=	DlManager
CORE_SRCS	= 	$(CORE_DIR)/main.cpp		\
			$(CORE_DIR)/Bonus.cpp		\
			$(CORE_DIR)/Excp.cpp		\
			$(CORE_DIR)/Food.cpp		\
			$(CORE_DIR)/Grid.cpp		\
			$(CORE_DIR)/Nibbler.cpp		\
			$(CORE_DIR)/Snake.cpp		\
			$(DLMANAGER_DIR)/DlLoader.cpp
CORE_OBJS	=	$(CORE_SRCS:.cpp=.o)

SFML_NAME	=	lib_nibbler_sfml.so
SFML_DIR	=	lib_nibbler_sfml
SFML_SRCS	=	$(SFML_DIR)/SfmlWindow.cpp

SFML_OBJS	=	$(SFML_SRCS:.cpp=.o)
SFML_LDFLAGS	= 	-shared -lsfml-system -lsfml-graphics -lsfml-window


OPENGL_NAME	=	lib_nibbler_opengl.so
OPENGL_DIR	=	lib_nibbler_opengl
OPENGL_SRCS	=	$(OPENGL_DIR)/OpenglWindow.cpp

OPENGL_OBJS	=	$(OPENGL_SRCS:.cpp=.o)
OPENGL_LDFLAGS	= 	-lGL -shared -lSDL -lGLU -lSDL_image

NCURSES_NAME	=	lib_nibbler_ncurses.so
NCURSES_DIR	=	lib_nibbler_ncurses
NCURSES_SRCS	=	$(NCURSES_DIR)/NcursesWindow.cpp

NCURSES_OBJS	=	$(NCURSES_SRCS:.cpp=.o)
NCURSES_LDFLAGS	= 	-lncurses -shared

CXX		= 	g++
CXXFLAGS	+=	-W -Wextra -Wall -fPIC -I./include -Werror
LDFLAGS		+=	-ldl -export-dynamic

RM		= rm -rf

all		: $(CORE_NAME) $(SFML_NAME) $(NCURSES_NAME) $(OPENGL_NAME)
		@echo "Core & graphic libraries compiled"

$(CORE_NAME)	: $(CORE_OBJS)
		$(CXX) -o $(CORE_NAME) $(CORE_OBJS) $(LDFLAGS)

$(SFML_NAME)	: $(SFML_OBJS)
		$(CXX) -o $(SFML_NAME) $(SFML_OBJS) $(SFML_LDFLAGS)

$(OPENGL_NAME)	: $(OPENGL_OBJS)
		$(CXX) -o $(OPENGL_NAME) $(OPENGL_OBJS) $(OPENGL_LDFLAGS)

$(NCURSES_NAME)	: $(NCURSES_OBJS)
		$(CXX) -o $(NCURSES_NAME) $(NCURSES_OBJS) $(NCURSES_LDFLAGS)

re		: fclean all

clean		:
		@echo "Erasing object files"
		$(RM) $(CORE_OBJS)
		$(RM) $(SFML_OBJS)
		$(RM) $(OPENGL_OBJS)
		$(RM) $(NCURSES_OBJS)

fclean		: clean
		@echo "Erasing binaries and safe"
		$(RM) $(CORE_NAME)
		$(RM) $(CORE_DIR)/*~
		$(RM) $(SFML_NAME)
		$(RM) $(SFML_DIR)/*~
		$(RM) $(OPENGL_NAME)
		$(RM) $(OPENGL_DIR)/*~
		$(RM) $(NCURSES_NAME)
		$(RM) $(NCURSES_DIR)/*~

.PHONY		: clean fclean re