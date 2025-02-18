NAME	=	maggots
CC		=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++20
SRCS	=	main.cpp \
			Bureaucrat.cpp \
			Form.cpp
OBJS	=	$(SRCS:.cpp=.o)
HEADER  =	Bureaucrat.hpp \
			Form.hpp

all: $(NAME)

%.o: %.cpp $(HEADER)
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re