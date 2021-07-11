/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iserzhan <iserzhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 18:35:02 by iserzhan          #+#    #+#             */
/*   Updated: 2020/12/07 15:27:19 by iserzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		print_error(char *args, t_info *info)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(args, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(strerror(errno), 2);
	info->info2->ret = errno;
	return (1);
}

int		print_error_redir(char *redir, t_info *info)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(redir, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(strerror(errno), 2);
	info->info2->ret = errno;
	return (-1);
}

int		print_error_cmd(char *args, t_info *info, char **envp, char *path)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(args, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd("command not found", 2);
	info->info2->ret = 127;
	free_memo(envp, path);
	return (1);
}

int		print_error_nsf_path(char *args, t_info *info, char **envp, char *path)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(args, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd("No such file or directory", 2);
	info->info2->ret = 1;
	if (!path)
		info->info2->ret = 127;
	free_memo(envp, path);
	return (1);
}

int		print_error_nsf(char **args, t_info *info)
{
	ft_putstr_fd(args[0], 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(args[1], 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd("No such file or directory", 2);
	info->info2->ret = 1;
	return (1);
}
