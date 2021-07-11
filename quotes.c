/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnowbir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 16:07:40 by ssnowbir          #+#    #+#             */
/*   Updated: 2020/11/26 18:10:03 by ssnowbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void					quotes_two_dollar(t_info *info)
{
	if (info->line[info->i] == '$' &&
				check_sym_env(info->line[info->i + 1]) == 1)
	{
		if (info->line[info->i + 1] == '?')
		{
			info->i++;
			info->tok->tmp2 = get_new_row(info->tok->tmp2,
							*ft_itoa(info->dollar_quest_mark));
			info->i++;
		}
		else
			info->tok->tmp2 =
					get_new_row(info->tok->tmp2, info->line[info->i++]);
	}
	else
	{
		info->tok->tmp2 = ft_strjoin_new(info->tok->tmp2,
									get_env(info, info->tok->tmp2, 0), 0, 0);
		while (check_sym_env(info->line[info->i]) == 0)
			info->i++;
	}
}

void					quotes_two_slash(t_info *info)
{
	if (char_in_str(info->line[info->i + 1], "\"\\$`", 1) == 0)
	{
		info->i++;
		info->tok->tmp2 =
				get_new_row(info->tok->tmp2, info->line[info->i++]);
	}
	else
	{
		info->tok->tmp2 =
			get_new_row(info->tok->tmp2, info->line[info->i]);
		info->i++;
		info->tok->tmp2 =
			get_new_row(info->tok->tmp2, info->line[info->i++]);
	}
}

char					*quotes_two(t_info *info)
{
	info->i++;
	while (char_in_str(info->line[info->i], "\"", 1) == 1)
	{
		if (info->line[info->i] == '$')
			quotes_two_dollar(info);
		else if (info->line[info->i] == '\\')
			quotes_two_slash(info);
		else
		{
			info->tok->tmp2 =
					get_new_row(info->tok->tmp2, info->line[info->i]);
			info->i++;
		}
	}
	info->i++;
	if (!info->tok->tmp2 && !info->tok->args)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd("", 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd("command not found\n", 2);
		info->info2->ret = 127;
	}
	return (info->tok->tmp2);
}

char					*quotes_one(t_info *info)
{
	info->i++;
	while (char_in_str(info->line[info->i], "\'", 1) == 1)
	{
		info->tok->tmp2 = get_new_row(info->tok->tmp2, info->line[info->i]);
		info->i++;
	}
	info->i++;
	if (!info->tok->tmp2 && !info->tok->args)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd("", 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd("command not found\n", 2);
		info->info2->ret = 127;
	}
	return (info->tok->tmp2);
}

void					quotes_no_or_slash_or_no(t_info *info)
{
	if (info->line[info->i] == '\\')
	{
		info->i++;
		info->tok->tmp2 =
					get_new_row(info->tok->tmp2, info->line[info->i++]);
	}
	else
		info->tok->tmp2 =
					get_new_row(info->tok->tmp2, info->line[info->i++]);
}
