/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iserzhan <iserzhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:58:26 by ssnowbir          #+#    #+#             */
/*   Updated: 2020/12/08 12:56:37 by iserzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				get_args2(t_info *info)
{
	info->info2->r_redir = 0;
	dup2(info->info2->temp_fd[1], 1);
	if (info->tok->red)
	{
		if (run_redir(info))
			return (1);
		info->sum_red = 0;
		info->j = 0;
	}
	else if (info->sintax_err == 0)
		execute(info, info->env);
	return (0);
}

void			get_args3(t_info *info)
{
	if (info->tok->red)
	{
		ft_free(info->tok->red);
		info->tok->red = NULL;
	}
	if (info->tok->args)
	{
		ft_free(info->tok->args);
		info->tok->args = NULL;
	}
	info->sum_red = 0;
	info->j = 0;
}

int				get_args(t_info *info, int status_pars)
{
	info->i = 0;
	if (check_correct_row(info->line, info, -1) == 0)
		print_err(info);
	while (status_pars)
	{
		if (info->sintax_err == 0)
			status_pars = parsing(info, 0, 0);
		if (status_pars == 0 && !info->tok->args && !info->tok->red)
			break ;
		info->info2->ret = 0;
		if (get_args2(info))
		{
			get_args3(info);
			return (1);
		}
		if (info->sintax_err == 1)
		{
			info->sintax_err = 0;
			break ;
		}
		get_args3(info);
	}
	return (0);
}

void			sig_interrupt(int code)
{
	if (code == SIGINT)
	{
		ft_putstr_fd("\b\b  \n", 2);
		ft_putstr_fd("minishell$ ", 2);
		g_ret = 130;
	}
	if (code == SIGQUIT)
	{
		ft_putstr_fd("\b\b  \n", 2);
		ft_putstr_fd("minishell$ ", 2);
		g_ret = 131;
	}
}

int				main(int args, char **argv, char **envp)
{
	t_info	*info;

	(void)args;
	(void)argv;
	info = make_struct_info(envp);
	info->info2->temp_fd[0] = dup(0);
	info->info2->temp_fd[1] = dup(1);
	while (info->info2->status)
	{
		g_ret = 0;
		reset_fds(info->fd);
		write(1, "minishell$ ", 12);
		if ((signal(SIGINT, &sig_interrupt) == SIG_ERR) ||
			(signal(SIGINT, &sig_interrupt) == SIG_ERR))
			exit(EXIT_FAILURE);
		get_input(&info->line, 0);
		if (g_ret > 0)
			info->info2->ret = g_ret;
		get_args(info, 1);
		free(info->line);
		dup2(info->info2->temp_fd[0], 0);
		dup2(info->info2->temp_fd[1], 1);
	}
	return (info->info2->ret);
}
