 NAME	= a.out

SRCS	=	main.cpp

CFLAGS	= -Wall -Werror -Wextra -std=c++98

CC		= clang++


all: 
	@$(MAKE) $(NAME) --no-print-directory

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean : clean

re : fclean all

.PHONY: re fclean clean all
