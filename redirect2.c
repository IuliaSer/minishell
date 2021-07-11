/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnowbir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 16:01:06 by ssnowbir          #+#    #+#             */
/*   Updated: 2020/12/08 11:08:44 by ssnowbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int						red_in_arr_red(t_info *info)
{
	while (char_in_str(info->line[info->i], ";|", 1) == 1 &&
			(info->line[info->i] == '>' || info->line[info->i] == '<'))
	{
		while (info->line[info->i] == ' ' && info->flag_redir == 0)
			info->i++;
		info->tok->red[info->j] =
				get_new_row(info->tok->red[info->j], info->line[info->i]);
		info->flag_redir = 1;
		if (info->line[info->i] == ' ')
			break ;
		info->i++;
	}
	if (info->flag_redir == 1)
	{
		info->j++;
		while (info->line[info->i] == ' ')
			info->i++;
		if (!(info->tok->red[info->j] = ft_calloc(2, 1)))
			return (0);
	}
	return (1);
}

void					count_sum_red(t_info *info, int *count, int j)
{
	info->flag_redir = 0;
	while (char_in_str(info->line[j], ";|", 1) == 1 &&
			(info->line[j] == '>' || info->line[j] == '<'))
	{
		while (info->line[j] == ' ' && info->flag_redir == 0)
			j++;
		if (info->flag_redir == 0)
			info->sum_red++;
		info->flag_redir = 1;
		j++;
	}
	while (char_in_str(info->line[j], "><;|", 1) == 1
			&& info->flag_redir == 1)
	{
		while (info->line[j] == ' ' && info->flag_word == 0)
			j++;
		if (info->flag_word == 0)
			info->sum_red++;
		info->flag_word = 1;
		j++;
	}
	info->flag_redir = 0;
	if (info->flag_redir == 0 && info->flag_word == 0)
		j++;
	*count = j;
}

int						get_arr_redirect(t_info *info)
{
	int			j;

	j = info->i;
	while (char_in_str(info->line[j], " ;|", 1) == 1)
	{
		info->flag_word = 0;
		count_sum_red(info, &j, j);
	}
	if (!(info->tok->red = ft_calloc(info->sum_red + 1, sizeof(char *))))
		return (0);
	info->tok->red[info->sum_red] = NULL;
	return (1);
}

int						put_arr_redirect(t_info *info)
{
	info->flag_redir = 0;
	while (char_in_str(info->line[info->i], " ;|", 1) == 1)
	{
		info->flag_word = 0;
		red_in_arr_red(info);
		if (!info->flag_redir)
		{
			info->i--;
			break ;
		}
		no_red_in_arr_red(info);
		if (info->flag_word == 1)
		{
			if (++info->j == info->sum_red)
				return (1);
			if (!(info->tok->red[info->j] = ft_calloc(2, 1)))
				return (0);
		}
		info->flag_redir = 0;
		if (info->flag_redir == 0 && info->flag_word == 0)
			info->i++;
	}
	return (1);
}
