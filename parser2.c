/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnowbir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 13:03:20 by ssnowbir          #+#    #+#             */
/*   Updated: 2020/12/05 19:23:36 by ssnowbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char				**dub_in_args(t_info *info, int j)
{
	int		i;

	i = 0;
	if (!(info->tok->args = (char**)malloc(sizeof(char*) * (j + 2))))
		return (NULL);
	info->tok->args[j + 1] = NULL;
	while (info->info2->new[i] != NULL)
	{
		info->tok->args[i] = ft_strdup(info->info2->new[i]);
		free(info->info2->new[i]);
		info->info2->new[i] = NULL;
		i++;
	}
	free(info->info2->new);
	info->info2->new = NULL;
	return (info->tok->args);
}

int					ft_strjoin_new2(char *s1, char *s2)
{
	int len;

	len = 0;
	if (!s2)
		len = ft_strlen(s1);
	else if (!s1)
		len = ft_strlen(s2);
	else
		len = ft_strlen(s1) + ft_strlen(s2);
	return (len);
}

void				get_new_row_2(t_info *info)
{
	if (info->tok->tmp2)
	{
		info->tok->tmp = ft_strjoin_new(info->tok->tmp, info->tok->tmp2, 0, 0);
		info->tok->tmp2 = NULL;
	}
}

void				ft_free_red(t_info *info)
{
	int i;

	i = 0;
	while (info->tok->red[i])
	{
		free(info->tok->red[i]);
		info->tok->red[i] = NULL;
		i++;
	}
	free(info->tok->red);
}
