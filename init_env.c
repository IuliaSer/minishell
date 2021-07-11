/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iserzhan <iserzhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 14:07:30 by iserzhan          #+#    #+#             */
/*   Updated: 2020/12/07 19:17:28 by iserzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_envadd_back(t_envp **lst, t_envp *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		while ((*lst)->next)
		{
			lst = &(*lst)->next;
		}
		(*lst)->next = new;
	}
}

t_envp	*ft_envnew(void *value)
{
	t_envp *node;

	if (!(node = (t_envp*)malloc(sizeof(t_envp))))
		return (0);
	node->value = ft_strdup(value);
	node->next = NULL;
	return (node);
}

t_envp	*init_env(char **envp)
{
	int		i;
	t_envp	*env;

	i = 1;
	if (!(env = ft_envnew(envp[0])))
		return (0);
	while (envp[i] != NULL)
	{
		ft_envadd_back(&env, ft_envnew(envp[i]));
		i++;
	}
	return (env);
}
