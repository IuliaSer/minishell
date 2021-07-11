/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iserzhan <iserzhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 16:15:48 by iserzhan          #+#    #+#             */
/*   Updated: 2020/12/07 17:13:26 by iserzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_args(char **args)
{
	int i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

int			cmd_env(t_info *info, char **args)
{
	int		i;
	t_envp	*temp;

	temp = info->env;
	i = 0;
	if ((count_args(args)) > 1)
		return (print_error_nsf(args, info));
	ft_putendl_fd(temp->value, 1);
	while (temp->next != NULL)
	{
		temp = temp->next;
		ft_putendl_fd(temp->value, 1);
		i++;
	}
	return (1);
}
