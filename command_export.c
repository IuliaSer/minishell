/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iserzhan <iserzhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:26:12 by iserzhan          #+#    #+#             */
/*   Updated: 2020/12/07 19:14:21 by iserzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	cmd_export_all(t_envp *env)
{
	int	i;

	i = 0;
	ft_putendl_fd(env->value, 1);
	while (env->next != NULL)
	{
		env = env->next;
		ft_putstr_fd("declare -x ", 1);
		ft_putendl_fd(env->value, 1);
		i++;
	}
	return (1);
}

static void	error_not_val_ident(char *args, t_info *info)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd("export", 2);
	ft_putstr_fd(": '", 2);
	ft_putstr_fd(args, 2);
	ft_putstr_fd("'", 2);
	ft_putendl_fd(": not a valid identifier", 2);
	info->info2->ret = 1;
}

int			cmd_export(char **args, t_envp *env, t_info *info)
{
	int		i;

	i = 1;
	if (!args[i])
		return (cmd_export_all(env));
	while (args[i])
	{
		if ((((args[i][0] < 'a' || args[i][0] > 'z') &&
		(args[i][0] < 'A' || args[i][0] > 'Z')) && args[i][0] != '_'))
			error_not_val_ident(args[i], info);
		else if (ft_strchr(args[i], '='))
		{
			ft_envadd_back(&env, ft_envnew(args[i]));
		}
		i++;
	}
	return (1);
}
