# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flouta <flouta@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/28 14:48:38 by ridrissi          #+#    #+#              #
#    Updated: 2022/09/09 23:33:47 by flouta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=minishell
CC=gcc
LIBFT=libft/libft.a
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g
SRC=  open_files2.c signals.c files_utils.c execution_util3.c execution_utils2.c builtins_utils3.c builtin_utils2.c minishell_utils2.c pipeline_utils.c execution.c get_line.c pipeline.c \
 	open_files.c execution_utils.c simple_command.c run_builtin.c b_exit.c b_cd.c b_echo.c b_unset.c b_export.c builtins_utils.c b_pwd.c b_env.c minishell.c minishell_utils.c \
	add_args_str.c add_cmd_str.c  add_str.c add_token.c add_token1.c add_token2.c ambiguous_redirect.c ardr.c assign.c char_to_str.c \
	check_double_pipe.c check_err2.c check_pipe_end.c check_pipe_start.c check_quote.c check_range.c check_rdr_end.c \
	check_rdr_next.c create_arg_arr.c expand_dollar_s.c expand_join.c expn_hdoc.c free_arg_arr.c free_args.c \
	free_cmdcnt.c free_comd.c free_gvars2.c free_lexer.c free_rdr.c free_s.c free_token_content.c free_token.c \
	ft_fctn1.c ft_fctn2.c ft_fctn3.c ft_fctn4.c ft_fctn5.c ft_fctn6.c ft_fctn7.c ft_fctn8.c ft_fctn9.c \
	ft_fctn10.c ft_fctn11.c ft_init.c ft_lstadd_back_arg.c ft_lstadd_back_cmd.c ft_lstadd_back_rdr.c \
	ft_lstadd_backtoken.c ft_lstlast_arg.c ft_lstlast_cmd.c ft_lstlast_rdr.c ft_lstlastoken.c ft_lstnew_arg.c \
	ft_lstnew_cmd.c ft_lstnew_rdr.c ft_lstnewtoken.c ft_split.c ft_sspace.c ft_sspace1.c ft_strcmp.c \
	ft_strcpy.c ft_strlcpy.c ft_strlen.c init_lexer.c joining.c len_s.c listlen.c no_sspace.c no_sspace1.c \
	parser.c print_error.c quote_str.c split_expand.c split_part.c step1.c step2.c syntaxerr_checker.c \
	to_add.c type_rdr.c word_range.c word.c addit.c wordd1.c expand_j1.c expand_dollar_s2.c addexp.c \
	checkr.c expand_linee.c check_lds.c ft_expdd.c
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

