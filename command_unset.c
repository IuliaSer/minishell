/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iserzhan <iserzhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 16:44:59 by iserzhan          #+#    #+#             */
/*   Updated: 2020/12/07 19:19:10 by iserzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	error_not_val_ident(char *args, t_info *info)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd("'", 2);
	ft_putstr_fd(args, 2);
	ft_putstr_fd("': ", 2);
	ft_putendl_fd("not a valid identifier", 2);
	info->info2->ret = 1;
	return (1);
}

static int	cmd_unset2(t_envp *temp_env, char *args, t_info *info, int size)
{
	t_envp	*temp;

	while (temp_env && temp_env->next != NULL)
	{
		if (!(ft_isalpha(args[0])))
			return (error_not_val_ident(args, info));
		if (!(ft_strncmp(args, temp_env->next->value, size)) &&
			(temp_env->next->value[size] == '='))
		{
			temp = temp_env->next->next;
			free(temp_env->next);
			free(temp_env->next->value);
			temp_env->next = temp;
		}
		temp_env = temp_env->next;
	}
	return (0);
}

int			cmd_unset(char **args, t_info *info)
{
	int		i;
	t_envp	*temp_env;
	int		size;

	i = 1;
	size = 0;
	temp_env = info->env;
	if (!args[1])
		return (1);
	while (args[i])
	{
		size = ft_strlen(args[i]);
		temp_env = info->env;
		if (!(ft_strncmp(args[i], temp_env->value, size)) &&
			(temp_env->next->value[size] == '='))
		{
			temp_env = temp_env->next;
			free(temp_env);
		}
		if (cmd_unset2(temp_env, args[i], info, size))
			return (1);
		i++;
	}
	return (1);
}
