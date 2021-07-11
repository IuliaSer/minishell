/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnowbir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 16:19:37 by ssnowbir          #+#    #+#             */
/*   Updated: 2020/12/05 19:21:03 by ssnowbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char					*quotes_two_env(t_info *info, char *arr)
{
	info->i++;
	while (char_in_str(info->line[info->i], "\"", 1) == 1)
	{
		if (info->line[info->i] == '\\')
		{
			if (char_in_str(info->line[info->i + 1], "\"\\$`", 1) == 0)
			{
				info->i++;
				arr = get_new_row(arr, info->line[info->i++]);
			}
			else
			{
				arr = get_new_row(arr, info->line[info->i]);
				info->i++;
				arr = get_new_row(arr, info->line[info->i++]);
			}
		}
		else
		{
			arr = get_new_row(arr, info->line[info->i]);
			info->i++;
		}
	}
	info->i++;
	return (arr);
}

char					*quotes_one_env(t_info *info, char *arr)
{
	info->i++;
	while (char_in_str(info->line[info->i], "\'", 1) == 1)
	{
		arr = get_new_row(arr, info->line[info->i]);
		info->i++;
	}
	info->i++;
	return (arr);
}

void					ft_free_name(t_info *info)
{
	free(info->name);
	info->name = NULL;
	if (info->name2)
	{
		free(info->name2);
		info->name2 = NULL;
	}
}

char					*find_env(t_info *info, int m, char *arr, t_envp *find)
{
	while (find)
	{
		info->info2->a = 0;
		info->count = 0;
		while (find->value[info->count] != '=')
			info->count++;
		info->name2 = ft_substr(find->value, 0, info->count);
		while (find->value[info->info2->a] != '=')
			info->info2->a++;
		if (ft_strcmp(info->name, info->name2) == 0)
		{
			info->info2->flag = 1;
			info->info2->sum = ft_strlen(&find->value[++info->info2->a]);
			if (!(arr = (char*)malloc(sizeof(char) * info->info2->sum + 1)))
				return (NULL);
			ft_bzero(arr, info->info2->sum + 1);
			while (find->value[info->info2->a] != '\0')
				arr[m++] = find->value[info->info2->a++];
			return (arr);
		}
		free(info->name2);
		info->name2 = NULL;
		find = find->next;
	}
	return (arr);
}

char					*get_env(t_info *info, char *arr, int m)
{
	t_envp		*find;

	find = info->env;
	info->info2->flag = 0;
	info->count = 0;
	info->i++;
	arr = NULL;
	if (char_in_str(info->line[info->i], ";|", 1) == 0)
		return (get_new_row(arr, info->line[info->i - 1]));
	if (check_sym_env(info->line[info->i]) == 1)
		return (is_no_digit_or_no_char(info, arr));
	while (check_sym_env(info->line[info->i]) == 1 &&
			char_in_str(info->line[info->i], ";|", 1))
		info->i++;
	info->count = info->i;
	if ((info->line[info->i] <= '9' && info->line[info->i] >= '0'))
		arr = is_digit_env(arr, info);
	while (check_sym_env(info->line[info->count]) == 0
				&& info->line[info->count] != '\0')
		info->count++;
	info->name = ft_substr(&info->line[info->i], 0, info->count - info->i);
	arr = find_env(info, m, arr, find);
	ft_free_name(info);
	return (arr);
}
