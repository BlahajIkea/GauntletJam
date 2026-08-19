# The binary this exercise builds
NAME := gauntlet

# Compiler and the gauntlet's mandatory flags
CXX      := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++17 

# List every .cpp file in the exercise here
SRCS := main.cpp Car.cpp Player.cpp
OBJS := $(SRCS:.cpp=.o)

RAYLIB_DIR	= vendor/raylib/src
RAYLIB		= $(RAYLIB_DIR)/librarylib.a

IFLAGS = -I$(RAYLIB_DIR)
LFLAGS = -L$(RAYLIB_DIR) -lraylib -lX11

# `make` / `make all`: build the binary
all: $(NAME)

$(NAME): $(RAYLIB) $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME) $(LFLAGS)

# Compile each .cpp into a .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(IFLAGS)

$(RAYLIB):
	@make -C $(RAYLIB_DIR) -s
	@touch $(RAYLIB)

# `make clean`: remove object files
clean:
	rm -f $(OBJS)

# `make fclean`: remove objects AND the binary
fclean: clean
	rm -f $(NAME)

# `make re`: rebuild everything from scratch
re: fclean all

.PHONY: all clean fclean re
