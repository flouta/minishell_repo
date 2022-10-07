#include "../Includes/minishell.h"

t_token	*ft_lstnewtoken(int id, char *value)
{
	t_token	*new;

	new = malloc (sizeof(t_token));
	if (new == 0)
		return (0);
	new->e_tp = id;
	new->content = value;
	new->expand_flag = 0;
	new->ambg = 0;
	new->prev = 0;
	new->next = 0;
	return (new);
}