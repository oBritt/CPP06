CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp A.cpp B.cpp C.cpp Base.cpp

OBJS = $(SRCS:.cpp=.o)

NAME = a.out

all: $(NAME)

$(NAME): $(OBJS)
	c++ $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re