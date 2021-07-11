/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnowbir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 16:07:40 by ssnowbir          #+#    #+#             */
/*   Updated: 2020/12/03 19:04:08 by ssnowbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char					*quotes_no(t_info *info)
{
	while (char_in_str(info->line[info->i], " ;|\"\'><", 1) == 1)
	{
		if (info->line[info->i] == '$')
		{
			info->tok->tmp2 = ft_strjoin_new(info->tok->tmp2,
									get_env(info, info->tok->tmp2, 0), 0, 0);
			while ((check_sym_env(info->line[info->i]) == 0) && info->count)
				info->i++;
			return (info->tok->tmp2);
		}
		else if (info->line[info->i] == '#')
			while (info->line[info->i] != '\0')
				info->i++;
		else if (info->line[info->i] == '~')
		{
			info->tok->tmp2 = ft_strjoin_new(info->tok->tmp2,
							get_home_dir(info, info->tok->tmp2, 0, 0), 0, 0);
			info->i++;
		}
		else
			quotes_no_or_slash_or_no(info);
	}
	return (info->tok->tmp2);
}
