NAME	=	Zombie

SRCS	=	main.cpp        \
			Zombie.cpp      \
			newZombie.cpp	\
			randomChump.cpp \

OBJS	=	$(SRCS:.cpp=.o)

CXX	=	c++

CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98

RM	=	rm -rf

all: $(NAME)

$(NAME): $(OBJS)
		$(CXX) -o $(NAME) $(OBJS)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
