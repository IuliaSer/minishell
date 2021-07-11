/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnowbir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 13:43:22 by ssnowbir          #+#    #+#             */
/*   Updated: 2020/12/05 11:50:54 by ssnowbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	cmd_echo2(char **args, int flag, int flag2)
{
	int i;

	i = 1;
	while (args[i])
	{
		while (args[i][0] == '-' && args[i][1] == 'n' &&
			flag == 0 && flag2 == 0)
		{
			if (!args[i + 1])
			{
				i++;
				break ;
			}
			if ((args[i][0] == '-' && args[i][1] == 'n') &&
			(args[i + 1][0] != '-' && args[i + 1][1] != 'n'))
				flag = 1;
			i++;
		}
		ft_putstr_fd(args[i], 1);
		if (args[i + 1])
			ft_putchar_fd(' ', 1);
		flag2 = 1;
		i++;
	}
}

int			cmd_echo(t_info *info)
{
	int i;
	int flag;
	int flag2;

	i = 1;
	flag2 = 0;
	flag = 0;
	if ((!info->tok->args[1] && info->tok->red == NULL) ||
		(!info->tok->args[1] && info->tok->red[0][0] == '<'))
	{
		ft_putchar_fd('\n', 2);
		return (0);
	}
	if (!info->tok->args[1] && info->tok->red)
		return (0);
	cmd_echo2(info->tok->args, 0, 0);
	if (ft_strcmp(info->tok->args[1], "-n") != 0)
		ft_putchar_fd('\n', 1);
	return (1);
}
