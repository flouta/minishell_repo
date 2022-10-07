#include "../Includes/minishell.h"

char	*addit(char *s, char c)
{
	char	*str;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen(s);
	str = (char *) malloc(sizeof(char) * (len + 2));
	str[len + 1] = '\0';
	while (s[i] != '\0')
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = c;
	return (str);
}

void	addexp(char *line, int *i, char **s)
{
	*i += 1;
	if (line[*i] == '?')
		expand_dollar_s2(i, s);
	else if (!(line[*i] >= '0' && line[*i] <= '9'))
		expand_j1(line, i, s);
	else if ((line[*i] >= '0' && line[*i] <= '9'))
		*i += 1;
}

int	add_token2(t_lexer **line, t_token **token, int *quote, int *valid)
{
	void	*p;

	if ((*line)->c == '<' && (*line)->content[(*line)->i + 1] != '<')
		to_add(line, token, TOKEN_IN, "<");
	else if ((*line)->c == '>' && (*line)->content[(*line)->i + 1] != '>')
		to_add(line, token, TOKEN_OUT, ">");
	else if ((*line)->c == '|')
		to_add(line, token, TOKEN_PIPE, "|");
	else if ((*line)->c == ' ')
	{
		p = *line;
		*line = init_lexer((*line)->content, (*line)->i + 1);
		free(p);
	}
	else
	{
		*quote = 0;
		*valid = 0;
		g_var.checked = 0;
		if (add_str(line, *quote, token, valid) == 0)
			return (0);
	}
	return (1);
}

static void	addit_empty(t_lexer **line, t_token **token, int *r)
{
	void	*p;

	*r += 1;
	ft_lstadd_backtoken(token, ft_lstnewtoken(TOKEN_STR, ""));
	p = *line;
	*line = init_lexer((*line)->content, (*line)->i + 3);
	free(p);
}

static int	nextc(char c1, char c2, char c3)
{
	if ((c1 == 34 || c1 == 39) && (c2 == c1) && (c3 == ' '
			|| c3 == '<' || c3 == '>' || c3 == '|' || c3 == '\0'))
		return (1);
	return (0);
}

static int	existt(t_lexer **line)
{
	if ((*line)->content[(*line)->i + 1] && (*line)->content[(*line)->i + 2]
		&& (*line)->content[(*line)->i + 3])
	{
		return (1);
	}
	return (0);
}

int	add_token1(t_lexer **line, t_token **token, int *quote, int *valid)
{
	int		r;
	void	*p;

	r = 2;
	if (((*line)->c == '$') && existt(line)
		&& nextc((*line)->content[(*line)->i + 1],
			(*line)->content[(*line)->i + 2], (*line)->content[(*line)->i + 3]))
		addit_empty(line, token, &r);
	else if (((*line)->c == 34) || ((*line)->c == 39))
	{
		r = 1;
		if (quote_str(line, token, quote, valid) == 0)
			return (0);
	}
	else if ((*line)->c == '>' && (*line)->content[(*line)->i + 1] == '>')
		step2(line, token, &r);
	else if ((*line)->c == '<' && (*line)->content[(*line)->i + 1] == '<')
	{
		r = 1;
		ft_lstadd_backtoken(token, ft_lstnewtoken(TOKEN_HEREDOC, "<<"));
		p = *line;
		*line = init_lexer((*line)->content, (*line)->i + 2);
		free(p);
	}
	return (r);
}

int	add_token(t_lexer **line, t_token **token)
{
	int	valid;
	int	quote;
	int	rt;

	quote = 0;
	valid = 0;
	rt = 0;
	while ((*line)->c != '\0')
	{
		if (assign(&rt, add_token1(line, token, &quote, &valid)) == 0)
			return (0);
		else if (rt != 1)
		{
			if (add_token2(line, token, &quote, &valid) == 0)
				return (0);
		}
	}
	ft_lstadd_backtoken(token, ft_lstnewtoken(TOKEN_END, "\0"));
	return (1);
}

int	add_str(t_lexer **line, int quote, t_token **token, int *valid)
{
	char	*str;
	int		keep_up;
	int		expd;

	str = ft_init(line, &expd, &keep_up);
	while (g_var.b)
	{
		while ((*line)->c != quote && (*line)->c != '\0' && keep_up)
		{
			ft_fctn4(line, &quote, valid);
			if (assign(&expd, ft_fctn9(line, quote, token, &str)) == -4)
				return (0);
			if (expd == 1)
				ft_fctn3(line, &quote, valid);
			if (expd == 0)
			{
				ft_fctn1(line, valid, &keep_up);
				if (keep_up)
					ft_fctn2(line, &str, valid, &quote);
			}	
		}
		ft_fctn10(line, &quote, valid);
	}
	ft_fctn11(str, token);
	return (1);
}

void	add_args_str(char **str, t_args *args, int i)
{
	int		len;
	t_args	*actuel;

	len = 0;
	actuel = args;
	while (actuel)
	{
		len = ft_strlen(actuel->arg);
		str[i] = (char *) malloc(sizeof(char) * (len + 1));
		ft_strcpy(str[i], actuel->arg);
		i++;
		actuel = actuel->next;
	}
}

void	add_cmd_str(char **str, char *cmd)
{
	int	len;

	len = 0;
	if (cmd)
	{
		len = ft_strlen(cmd);
		str[0] = (char *) malloc(sizeof(char) * (len + 1));
		ft_strcpy(str[0], cmd);
	}
}



