NAME=minishell
CC=gcc
LIBFT=libft/libft.a
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g
SRC= $(wildcard executer/Builtins/*.c)\
	 $(wildcard executer/Execution/*.c)\
	 $(wildcard executer/Files/*.c)\
	 $(wildcard executer/Signals/*.c)\
	 $(wildcard executer/Utils/*.c)\
	 $(wildcard parser/*.c)\
	 $(wildcard Main/*.c)

OBJ= $(SRC:.c=.o)

all:  $(LIBFT) $(NAME)

$(LIBFT):
		make -C libft

$(NAME): $(OBJ)
		stty -echoctl
		$(CC) $(CFLAGS) $(OBJ) ./libft/libft.a -o $(NAME) -lreadline -L /goinfre/${USER}/.brew/opt/readline/lib
%.o: %.c
	$(CC) -I /goinfre/${USER}/.brew/opt/readline/include ${CFLAGS} -c $< -o $@

clean:
		rm -rf $(OBJ)
		make clean -C libft

fclean: clean
		rm -rf $(NAME)
		make fclean -C libft

re: fclean all

