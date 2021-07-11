/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnowbir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 16:15:03 by iserzhan          #+#    #+#             */
/*   Updated: 2020/12/07 19:53:15 by ssnowbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		ft_strisnum(char *args)
{
	int i;

	i = 0;
	if (args[i] == '-')
		i++;
	while (args[i])
	{
		if (args[i] < '0' || args[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

static int		count_args(char **args)
{
	int i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

static void		free_env(t_envp *env)
{
	while (env)
	{
		free(env->value);
		env->value = NULL;
		env = env->next;
	}
	free(env);
	env = NULL;
}

static void		free_mem(t_envp *env, t_info *info)
{
	free_env(env);
	if (info->tok)
		free(info->tok);
	if (info)
		free(info);
	if (info->info2)
		free(info->info2);
	info = NULL;
}

void			cmd_exit(char **args, t_envp *env, t_info *info)
{
	int	retrn;

	ft_putendl_fd("exit ", 2);
	info->info2->status = 0;
	if (count_args(args) > 2)
	{
		info->info2->ret = 1;
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putendl_fd("too many arguments", 2);
	}
	if (args[1] && ft_strisnum(args[1]))
	{
		info->info2->ret = 255;
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(args[1], 2);
		ft_putendl_fd(": numeric argument required", 2);
	}
	else if (args[1])
		info->info2->ret = ft_atoi(args[1]) % 256;
	retrn = info->info2->ret;
	free_mem(env, info);
	exit(retrn);
}
