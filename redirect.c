/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnowbir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 15:02:47 by ssnowbir          #+#    #+#             */
/*   Updated: 2020/12/08 11:08:40 by ssnowbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void					no_red_in_arr_red2(t_info *info)
{
	if (info->line[info->i] == '$')
	{
		info->tok->red[info->j] = ft_strjoin_new(info->tok->red[info->j],
		get_env(info, info->tok->red[info->j], 0), 0, 0);
		while ((check_sym_env(info->line[info->i]) == 0) && info->count)
			info->i++;
		info->flag_word = 1;
	}
	else if (info->line[info->i] == '\\')
	{
		info->i++;
		info->tok->red[info->j] =
			get_new_row(info->tok->red[info->j], info->line[info->i++]);
	}
	else
		while (char_in_str(info->line[info->i], " ><;|$\'\"\\", 1) == 1
									&& info->flag_redir == 1)
		{
			info->tok->red[info->j] =
				get_new_row(info->tok->red[info->j], info->line[info->i++]);
			info->flag_word = 1;
		}
}

void					no_red_in_arr_red(t_info *info)
{
	while (char_in_str(info->line[info->i], " ><;|", 1) == 1
										&& info->flag_redir == 1)
	{
		while (info->line[info->i] == ' ' && info->flag_word == 0)
			info->i++;
		if (info->line[info->i] == '\'')
			info->tok->red[info->j] = quotes_one_redir(info, info->j);
		else if (info->line[info->i] == '\"')
			info->tok->red[info->j] = quotes_two_redir(info, info->j);
		else if (info->line[info->i] == ' ')
			break ;
		else
			no_red_in_arr_red2(info);
	}
}

char					*quotes_one_redir(t_info *info, int j)
{
	info->i++;
	while (char_in_str(info->line[info->i], "\'", 1) == 1)
	{
		info->tok->red[j] =
				get_new_row(info->tok->red[j], info->line[info->i]);
		info->i++;
	}
	info->i++;
	return (info->tok->red[j]);
}

void					quotes_two_redir2(t_info *info, int j)
{
	if (char_in_str(info->line[info->i + 1], "\"\\$`", 1) == 0)
	{
		info->i++;
		info->tok->red[j] =
				get_new_row(info->tok->red[j], info->line[info->i++]);
	}
	else
	{
		info->tok->red[j] =
				get_new_row(info->tok->red[j], info->line[info->i]);
		info->i++;
		info->tok->red[j] =
				get_new_row(info->tok->red[j], info->line[info->i++]);
	}
}

char					*quotes_two_redir(t_info *info, int j)
{
	info->i++;
	while (char_in_str(info->line[info->i], "\"", 1) == 1)
	{
		if (info->line[info->i] == '$')
		{
			info->tok->red[j] = ft_strjoin_new(info->tok->red[j],
			get_env(info, info->tok->red[j], 0), 0, 0);
			while (check_sym_env(info->line[info->i]) == 0)
				info->i++;
			info->flag_word = 1;
		}
		else if (info->line[info->i] == '\\')
			quotes_two_redir2(info, j);
		else
		{
			info->tok->red[j] =
						get_new_row(info->tok->red[j], info->line[info->i]);
			info->i++;
		}
	}
	info->i++;
	return (info->tok->red[j]);
}
