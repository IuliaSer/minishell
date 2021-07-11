/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_redirect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iserzhan <iserzhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 19:08:24 by iserzhan          #+#    #+#             */
/*   Updated: 2020/12/07 20:06:35 by iserzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		close_fds(int *fd)
{
	if (fd[0] > 0)
		close(fd[0]);
	if (fd[1] > 0)
		close(fd[1]);
}

static void		run_redir3(int j, t_info *info)
{
	if ((ft_strncmp(info->tok->red[j - 2], "<", 1)) == 0)
		dup2(info->fd[0], 0);
	if ((ft_strncmp(info->tok->red[j - 2], ">", 1)) == 0)
		dup2(info->fd[1], 1);
}

static int		run_redir2(int j, t_info *info)
{
	while (info->tok->red[j] != NULL)
	{
		if (ft_strncmp(info->tok->red[j], ">>", 2) == 0)
		{
			info->info2->r_redir = 1;
			info->fd[1] = open(info->tok->red[++j],
			O_WRONLY | O_CREAT | O_APPEND, 0664);
		}
		else if (ft_strncmp(info->tok->red[j], ">", 1) == 0)
		{
			info->info2->r_redir = 1;
			if ((info->fd[1] = open(info->tok->red[++j],
				O_WRONLY | O_CREAT | O_TRUNC, 0664)) == -1)
				return (print_error_redir(info->tok->red[j], info));
		}
		else if (ft_strncmp(info->tok->red[j], "<", 1) == 0)
		{
			if ((info->fd[0] = open(info->tok->red[++j], O_RDONLY, 0664)) == -1)
				return (print_error_nsf(info->tok->args, info));
		}
		if (info->tok->red[j + 1])
			close(info->fd[0]);
		j++;
	}
	return (j);
}

int				run_redir(t_info *info)
{
	int	j;

	j = 0;
	if ((j = run_redir2(0, info)) == -1)
		return (1);
	run_redir3(j, info);
	execute(info, info->env);
	close_fds(info->fd);
	reset_fds(info->fd);
	return (0);
}
