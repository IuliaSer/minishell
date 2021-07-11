/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnowbir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:56:04 by ssnowbir          #+#    #+#             */
/*   Updated: 2020/12/08 11:08:17 by ssnowbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int					parsing(t_info *info, int m, int j)
{
	while (info->line[info->i] != '\0')
	{
		get_row(info);
		if (info->tok->tmp)
		{
			m = 0;
			put_new_str(info, j, -1);
			j++;
			free(info->tok->tmp);
			info->tok->tmp = NULL;
		}
		if (char_in_str(info->line[info->i], ";|", 0) == 0)
		{
			if (info->line[info->i] == '|')
				info->flag_pipe = 1;
			info->i++;
			return (1);
		}
	}
	return (0);
}

char				**put_new_str(t_info *info, int j, int i)
{
	i = 0;
	info->tmp_j = 0;
	if (!(info->info2->new = (char**)malloc(sizeof(char*) * (j + 2))))
		return (NULL);
	info->info2->new[j + 1] = NULL;
	if (j != 0)
	{
		while (info->tmp_j < j)
		{
			info->info2->new[info->tmp_j] =
								ft_strdup(info->tok->args[info->tmp_j]);
			free(info->tok->args[info->tmp_j]);
			info->tok->args[info->tmp_j] = NULL;
			info->tmp_j++;
		}
		free(info->tok->args);
		info->tok->args = NULL;
	}
	if (!(info->info2->new[j] = ft_strdup(info->tok->tmp)))
		return (NULL);
	dub_in_args(info, j);
	return (info->tok->args);
}

char				*ft_strjoin_new(char *s1, char *s2, int i, int j)
{
	char	*nstr;
	int		len;

	if (!s2 && !s1)
		return (0);
	len = ft_strjoin_new2(s1, s2);
	if (!(nstr = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (s1)
	{
		while (s1[j])
			nstr[i++] = s1[j++];
		free(s1);
	}
	j = 0;
	if (s2)
	{
		while (s2[j])
			nstr[i++] = s2[j++];
		free(s2);
	}
	nstr[i] = '\0';
	return (nstr);
}

char				*get_row(t_info *info)
{
	while (info->line[info->i] == ' ' || info->line[info->i] == '\t')
		info->i++;
	while (char_in_str(info->line[info->i], " ;|", 1) == 1)
	{
		if (info->line[info->i] == '\"')
			info->tok->tmp2 = quotes_two(info);
		else if (info->line[info->i] == '\'')
			info->tok->tmp2 = quotes_one(info);
		else if (info->line[info->i] == '<' || info->line[info->i] == '>')
		{
			if (info->sum_red == 0)
				get_arr_redirect(info);
			put_arr_redirect(info);
			if (char_in_str(info->line[info->i], ";", 1) == 0)
				break ;
			else
				info->i++;
		}
		else
			info->tok->tmp2 = quotes_no(info);
		get_new_row_2(info);
	}
	return (info->tok->tmp);
}
