/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:14:50 by ridrissi          #+#    #+#             */
/*   Updated: 2022/09/09 17:58:20 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

static void	parse_exec(t_v *vs)
{
	vs->comd = ft_lstnew_cmd();
	parser(vs->token, &(vs->comd));
	vs->act = vs->comd;
	while (vs->act != 0)
	{
		(vs->act)->arg_arr = create_arg_arr((vs->act)->args, (vs->act)->cmd);
		(vs->act) = (vs->act)->next;
	}
	vs->command = vs->comd;
	execution(vs->command);
	free_comd(vs->comd);
}

static void	init_main(t_v *vs, char **env, char **av, int ac)
{
	(void) av;
	(void) ac;
	vs->act = 0;
	vs->comd = 0;
	vs->command = 0;
	vs->line = 0;
	vs->str = 0;
	vs->token = 0;
	g_var.s2 = 0;
	g_var.allow_expand = 0;
	g_var.env = init_env(env);
	g_var.env = f_oldpwd();
	g_var.her_d = 1;
	g_var.exit_code = 0;
	g_var.sig_flag = 'r';
}

static int	free_str(char *str)
{
	if (str[0] == '\0')
	{
		free(str);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av, char **env)
{
	t_v	vs;

	init_main(&vs, env, av, ac);
	signal(SIGQUIT, q_handler);
	signal(SIGINT, c_handler);
	while (1)
	{
		g_var.sig_flag = 'r';
		vs.str = readline("Minishell ~ ");
		ctrld_handler(vs.str);
		if (free_str(vs.str))
		{
			add_history(vs.str);
			if (syntaxerr_checker(vs.str) != 0)
			{
				vs.line = init_lexer(vs.str, 0);
				if (add_token(&(vs.line), &(vs.token)) != 0
					&& check_err2(vs.token) != 0)
					parse_exec(&vs);
				free_token(vs.token);
				vs.token = 0;
				free_lexer(vs.line);
			}
		}
	}
}
