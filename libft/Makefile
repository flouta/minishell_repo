NAME=libft.a
CC=gcc
CFLAGS=-Wall -Wextra -Werror
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		ar rc $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)
fclean: clean
		$(RM) $(NAME)

re: fclean all
