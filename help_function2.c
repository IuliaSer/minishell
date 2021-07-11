/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_function2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnowbir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 17:05:03 by ssnowbir          #+#    #+#             */
/*   Updated: 2020/11/25 19:01:36 by ssnowbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int						check_sym_env(char c)
{
	char		*s;
	int			i;

	i = 0;
	s = "AaEeIiOoUuYyBbCcDdFfGgHhJjKkLlMmNnPpQqRrSsTtVvWwXxZz0987654321_";
	while (s[i])
	{
		if (s[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int						char_in_str(char c, char *arr, int flag_null)
{
	int		i;

	i = 0;
	if (flag_null == 1)
	{
		if (c == '\0')
			return (0);
	}
	while (arr[i])
	{
		if (arr[i] == c)
			return (0);
		i++;
	}
	return (1);
}

void					print_err(t_info *info)
{
	if (!info->tok->args && info->sintax_err == 0)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd("", 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd("command not found\n", 2);
		info->info2->ret = 127;
	}
	if (info->sintax_err == 1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd("syntax error near unexpected token\n", 2);
		info->info2->ret = 258;
	}
}

char					*get_new_row(char *arr, char c)
{
	int			i;
	char		*new;

	i = 0;
	if (arr == NULL)
		i = 1;
	if (arr)
		while (arr[i] != '\0')
			i++;
	if (!(new = ft_calloc(i + 2, 1)))
		return (0);
	new[i] = '\0';
	i = 0;
	if (arr)
	{
		while (arr[i])
		{
			new[i] = arr[i];
			i++;
		}
		free(arr);
		arr = NULL;
	}
	new[i] = c;
	return (new);
}

char					*get_home_dir(t_info *info, char *arr, int m, int sum)
{
	t_envp		*find;

	find = info->env;
	while (find)
	{
		info->info2->a = 0;
		info->count = 0;
		while (find->value[info->count] != '=')
			info->count++;
		info->name2 = ft_substr(find->value, 0, info->count);
		while (find->value[info->info2->a] != '=')
			info->info2->a++;
		if (ft_strcmp("HOME", info->name2) == 0)
		{
			sum = ft_strlen(&find->value[++info->info2->a]);
			if (!(arr = ft_calloc(sum + 1, sizeof(char))))
				return (NULL);
			while (find->value[info->info2->a] != '\0')
				arr[m++] = find->value[info->info2->a++];
			return (arr);
		}
		free(info->name2);
		find = find->next;
	}
	return (arr);
}
