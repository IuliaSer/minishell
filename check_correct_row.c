/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_correct_row.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iserzhan <iserzhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 16:27:15 by ssnowbir          #+#    #+#             */
/*   Updated: 2020/12/07 15:07:19 by iserzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				check_correct_row2(char *line, t_info *info, int i)
{
	if (info->info2->flag_start > 0 && info->info2->flag_finish > 0)
	{
		info->info2->flag_finish = 0;
		info->info2->flag_start = 0;
	}
	if (char_in_str(line[i], "|><;", 0) == 1)
		info->flag_arg = 1;
	if ((char_in_str(line[i], "|><;", 0) == 0 && info->flag_arg == 0) ||
		((line[i] == '>' || line[i] == '<') && line[i + 1] == '\0'))
	{
		if (line[i] == '>' || line[i] == '<')
			info->redirect++;
		if (((line[i] != '>' && line[i] != '<') && (info->info2->flag_start == 0
		|| (info->info2->flag_finish > 0 && info->info2->flag_start > 0))) ||
		info->redirect > 2 || ((line[i] == '>' || line[i] == '<')
			&& line[i + 1] == '\0') || ((line[i] != '>' || line[i] != '<') &&
		info->flag_arg == 0 && info->redirect == 2 && line[i - 1] != '>'))
		{
			info->sintax_err = 1;
			return (0);
		}
	}
	if (char_in_str(line[i], "|><;", 0) == 0)
		info->flag_arg = 0;
	return (1);
}

int				check_correct_row(char *line, t_info *info, int i)
{
	info->info2->flag_finish = 0;
	info->info2->flag_start = 0;
	info->redirect = 0;
	info->flag_arg = 0;
	while (line[++i] != '\0')
	{
		while ((line[i] == ' ' || line[i] == '\t') && line[i + 1] != '\0')
			i++;
		if ((line[i] == '\'' || line[i] == '\"') &&
						info->info2->flag_start == 0)
			info->info2->flag_start = line[i++];
		if ((line[i] == '\'' || line[i] == '\"') && info->info2->flag_start > 0)
		{
			if (line[i] == info->info2->flag_start)
				info->info2->flag_finish++;
			else
				i++;
		}
		if (check_correct_row2(line, info, i) == 0)
			return (0);
	}
	return (1);
}
