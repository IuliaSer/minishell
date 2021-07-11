/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnowbir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 17:11:36 by ssnowbir          #+#    #+#             */
/*   Updated: 2020/12/05 19:21:37 by ssnowbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char					*is_digit_env(char *arr, t_info *info)
{
	info->i++;
	while (char_in_str(info->line[info->i], "; |", 1) == 1)
		arr = get_new_row(arr, info->line[info->i++]);
	if (!arr)
		arr = ft_strdup("");
	return (arr);
}

char					*is_no_digit_or_no_char(t_info *info, char *arr)
{
	if (info->line[info->i] == '\'')
		arr = quotes_one_env(info, arr);
	else if (info->line[info->i] == '\"')
		arr = quotes_two_env(info, arr);
	else if (char_in_str(info->line[info->i], "/\\ \t|.,=:;$`+", 1) == 0)
	{
		arr = get_new_row(arr, info->line[info->i - 1]);
		if (char_in_str(info->line[info->i], "!@", 1) == 0)
			info->i++;
		if (char_in_str(info->line[info->i], " +/=.,:", 1) == 1)
			info->i++;
		while (char_in_str(info->line[info->i], " ;|", 1) == 1 ||
		(char_in_str(info->line[info->i], ";|", 0) == 0 &&
		info->line[info->i - 1] == '\\'))
			arr = get_new_row(arr, info->line[info->i++]);
	}
	else if (char_in_str(info->line[info->i], "*()?@!", 1) == 0)
	{
		if (info->line[info->i] == '?')
			arr = ft_strjoin_new(arr, ft_itoa(info->info2->ret), 0, 0);
		info->i++;
	}
	return (arr);
}
