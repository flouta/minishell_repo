/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <flouta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 19:05:00 by ridrissi          #+#    #+#             */
/*   Updated: 2022/09/09 23:23:39 by flouta           ###   ########.fr       */
/*                                                                            */
/* ******************************* ******************************************* */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <signal.h>

typedef struct s_env
{
	char			*key;
	char			*value;
	char			flag;
	struct s_env	*next;
}	t_env;

typedef struct s_vars
{
	int		allow_expand;
	int		ambgs;
	char	*s2;
	t_env	*env;
	int		b;
	int		checked;
	int		her_d;
	char	sig_flag;
	int		herd_flag;
	int		*stdi_o;
	int		exit_code;
}	t_vars;

t_vars	g_var;

typedef struct s_lexer
{
	char	*content;
	int		i;
	char	c;
}	t_lexer;

typedef struct s_token
{
	enum
	{
		TOKEN_STR,
		TOKEN_IN,
		TOKEN_OUT,
		TOKEN_APPEND,
		TOKEN_HEREDOC,
		TOKEN_PIPE,
		TOKEN_END,
	}				e_tp;
	char			*content;
	int				expand_flag;
	int				ambg;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

typedef struct s_rdr
{
	enum
	{
		IN,
		OUT,
		OUT_APPEND,
		IN_HEREDOC,
	}				e_tp;
	char			*content;
	int				h_fd;
	int				expd_flag;
	int				err_flag;
	struct s_rdr	*next;
}	t_rdr;

typedef struct s_args
{
	char			*arg;
	struct s_args	*next;
}	t_args;

typedef struct s_cmd
{
	char			*cmd;
	t_args			*args;
	t_rdr			*rdr;
	char			**arg_arr;
	int				*in_out;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_v
{
	t_lexer		*line;
	t_token		*token;
	char		*str;
	t_cmd		*comd;
	t_cmd		*command;
	t_cmd		*act;
}	t_v;

//parsing

void	add_args_str(char **str, t_args *args, int i);
void	add_cmd_str(char **str, char *cmd);
int		add_str(t_lexer **line, int quote, t_token **token, int *valid);
int		add_token(t_lexer **line, t_token **token);
int		add_token1(t_lexer **line, t_token **token, int *quote, int *valid);
int		add_token2(t_lexer **line, t_token **token, int *quote, int *valid);
int		ambiguous_redirect(t_token **token, char **s, char **line);
void	ardr(t_rdr **lst, char *s, int tp, int f);
int		assign(int *var, int ret);
char	*char_to_str(char c);
int		check_double_pipe(t_token *token);
int		check_err2(t_token *token);
int		check_pipe_end(t_token *token);
int		check_pipe_start(t_token *token);
int		check_quote(char *str, int quote, int *index);
int		check_range(char c);
int		check_rdr_end(t_token *token);
int		check_rdr_next(t_token *token);
char	**create_arg_arr(t_args *args, char *cmd);
void	expand_dollar_s(t_lexer **line, char **str);
int		expand_join(char **line, t_lexer **str, int quote, t_token **token);
void	expn_hdoc(t_token **token, int quote);
void	free_arg_arr(char **arg_arr);
void	free_args(t_args *args);
void	free_cmdcnt(t_cmd *comd);
void	free_comd(t_cmd *comd);
void	free_gvars2(void);
void	free_lexer(t_lexer *line);
void	free_rdr(t_rdr *rdr);
void	free_s(char **s);
void	free_token_content(t_token *token);
void	free_token(t_token *token);
void	ft_fctn1(t_lexer **line, int *valid, int *keep_up);
void	ft_fctn2(t_lexer **line, char **str, int *valid, int *quote);
void	ft_fctn3(t_lexer **line, int *quote, int *valid);
void	ft_fctn4(t_lexer **line, int *quote, int *valid);
void	ft_fctn5(t_token **token);
int		ft_fctn6(t_lexer **line, char **str, int quote, t_token **token);
void	ft_fctn7(t_lexer **line);
void	ft_fctn8(t_lexer **line, int *valid, int *quote);
int		ft_fctn9(t_lexer **line, int quote, t_token **token, char **str);
void	ft_fctn10(t_lexer **line, int *quote, int *valid);
void	ft_fctn11(char *str, t_token **token);
char	*ft_init(t_lexer **line, int *expd, int *keep_up);
void	ft_lstadd_back_arg(t_args **lst, t_args *new);
void	ft_lstadd_back_cmd(t_cmd **lst, t_cmd *new);
void	ft_lstadd_back_rdr(t_rdr **lst, t_rdr *new);
void	ft_lstadd_backtoken(t_token **lst, t_token *new);
t_args	*ft_lstlast_arg(t_args *lst);
t_cmd	*ft_lstlast_cmd(t_cmd *lst);
t_rdr	*ft_lstlast_rdr(t_rdr *lst);
t_token	*ft_lstlastoken(t_token *lst);
t_args	*ft_lstnew_arg(char *str);
t_cmd	*ft_lstnew_cmd(void);
t_rdr	*ft_lstnew_rdr(char *str, int type, int flag);
t_token	*ft_lstnewtoken(int id, char *value);
char	**ft_split(const char *str, char c);
void	ft_sspace(char **line, t_token **token, char **s);
void	ft_sspace1(char **s, t_token **token);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strcpy(char	*dest, char *src);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
t_lexer	*init_lexer(char *value, int i);
int		joining(int quote, char **line, char *val, t_token **token);
int		len_s(char **s);
int		listlen(t_args *args);
void	no_sspace(char **line, t_token **token, char **s);
void	no_sspace1(char **line, t_token **token, char **s);
void	parser(t_token *token, t_cmd **comd);
int		print_error(void);
int		quote_str(t_lexer **line, t_token **token, int *quote, int *valid);
int		split_expand(char **line, char *str, t_token **token);
int		split_part(char **line, char *str, t_token **token, int start_space);
void	step1(t_lexer **line, int *quote, int *valid);
void	step2(t_lexer **line, t_token **token, int *r);
int		syntaxerr_checker(char *str);
void	to_add(t_lexer **line, t_token **token, int id, char *value);
int		type_rdr(t_token *actuel_tk, t_cmd **actuel);
int		word_range(char c);
char	*word(t_lexer **str);
char	*addit(char *s, char c);
char	*wordd1(char *line, int *i);
void	expand_j1(char *line, int *i, char **s);
void	expand_dollar_s2(int *i, char **s);
void	addexp(char *line, int *i, char **s);
int		checkr(char c, char c2);
char	*expand_linee(char *line);
int		check_lds(char *line);
char	*ft_expdd(char *line);

//builtins
void	b_env(char **arg);
void	b_pwd(void);
void	b_export(char **arg);
void	b_cd(char **arg);
void	b_echo(char **arg);
void	b_unset(char **arg);
void	b_exit(char **arg);
//Builtin utils
void	modify_env(char *var, char *path);
void	change_dir(char *path);
void	cd_home(void);
void	cd_prev(void);
char	**copy_env(char **env);
void	append_value(t_env *found, char *var);
void	overwrite_value(t_env *found, char *var);
t_env	*init_var(char *arg);
int		check_key(char *key);
void	add_first(t_env *var);
void	print_echo(char **arg, int i);
int		is_empty(char *str, char n);
int		check_opt(char **arg);
void	display_export(void);
char	*to_mini(char *str);
void	add_export(char *arg);
//environment
int		str_2dlen(char **str);
int		_2d_len(char **arr);
t_env	*init_env(char **env);
int		key_len(char *var);
int		value_len(char *var);
char	*get_key(char *var);
char	*get_value(char *var);
t_env	*add_env_var(char *env, t_env *head);
void	display_env(void);
char	get_flag(char *arg);
t_env	*f_oldpwd(void);
//files
int		check_srchr(char *s);
int		open_heredoc(t_rdr *rdr);
void	heredoc(t_rdr *rdr, int h_fd);
int		*open_files(t_rdr *files);
void	init_files(t_cmd *input);
int		is_directory(char *path);
void	dup_2(int *i_o);
int		*out_file(t_rdr *head, int *in_out);
int		*in_file(t_rdr *head, int *in_out);
int		*append_file(t_rdr *head, int *in_out);
int		*in_herd(t_rdr *head, int *in_out);
int		*file_type(t_rdr *head, int *in_out);
int		open_herd(t_cmd *files);
//execution
void	run_builtin(t_cmd *node);
int		simple_command(t_cmd *input);
void	single_command(t_cmd *input);
int		is_builtin(char *cmd);
void	cmd_slash(t_cmd *input);
int		search(char *cmd);
int		pipe_line(t_cmd *input);
void	first_child(int *in_out, int *fd);
void	mid_child(int *in_out, int last_in, int *fd);
void	last_child(int *in_out, int last_in);
void	executer(t_cmd *cmd);
void	dup_2(int *i_o);
void	backup_i_o(int *stdi_o);
int		*stdin_stdout(void);
void	execution(t_cmd *input);
void	run_child(t_cmd *input, int *fd, int last_in, t_cmd *cmd);
int		close_parent(int *in_out, int last_in, int *fd);
void	first_child(int *in_out, int *fd);
void	mid_child(int *in_out, int last_in, int *fd);
void	last_child(int *in_out, int last_in);
void	dup_child(t_cmd *input, int *fd, int last_in, t_cmd *cmd);

//others
t_env	*list_srch(char *var);
void	error_handling(char *msg);
t_env	*sort_list(t_env *env_dup);
int		max_len(char *s1, char *s2);
t_env	*copy_list(t_env *env);
char	**lst_to_arr(void);
int		get_path(t_cmd *input);
void	free_2d(char **arr);
void	error_msg(char *cmd, char *msg);
char	*line_join(char *line, char c);
char	*get_line2(int fd);
char	**split_path(char *cmd);
//signals 
void	ctrld_handler(char *str);
void	c_handler(int sig);
void	q_handler(int sig);
#endif