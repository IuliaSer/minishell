/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iserzhan <iserzhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 13:07:10 by iserzhan          #+#    #+#             */
/*   Updated: 2020/12/07 16:25:54 by iserzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		check_signal(t_info *info)
{
	info->info2->ret = WEXITSTATUS(info->info2->ret);
	if (WIFSIGNALED(info->info2->ret))
	{
		if (WTERMSIG(info->info2->ret) == 2)
		{
			write(2, "hi\n", 3);
			info->info2->ret = 130;
		}
		else if (WTERMSIG(info->info2->ret) == 3)
		{
			write(2, "\n", 1);
			info->info2->ret = 131;
		}
	}
}

static void	pipe_child(t_info *info, t_envp *env, int *fd)
{
	dup2(fd[1], 1);
	close(fd[0]);
	execute(info, env);
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	close(fd[1]);
	exit(0);
}

int			run_pipe(t_info *info, int *fd, t_envp *env)
{
	pid_t	pid;

	pipe(fd);
	info->flag_pipe = 2;
	pid = fork();
	if (pid == 0)
		pipe_child(info, env, fd);
	else if (pid > 0)
	{
		dup2(fd[0], 0);
		close(fd[1]);
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
		waitpid(pid, &info->info2->ret, WUNTRACED);
		check_signal(info);
		close(fd[0]);
	}
	else
		ft_putstr_fd("Failed to fork\n", 1);
	return (1);
}

int			execute(t_info *info, t_envp *env)
{
	if (!info->tok->args)
		return (1);
	if (info->info2->r_redir && info->flag_pipe)
		pipe_eof();
	if (info->flag_pipe == 1 && !info->info2->r_redir)
		return (run_pipe(info, info->fd, env));
	else if (ft_strcmp(info->tok->args[0], "exit") == 0)
		cmd_exit(info->tok->args, info->env, info);
	else if (ft_strcmp(info->tok->args[0], "cd") == 0)
		return (cmd_cd(info->tok->args[1], info));
	else if (ft_strcmp(info->tok->args[0], "pwd") == 0)
		return (cmd_pwd(info->tok->args));
	else if (ft_strcmp(info->tok->args[0], "export") == 0)
		return (cmd_export(info->tok->args, info->env, info));
	else if (ft_strcmp(info->tok->args[0], "unset") == 0)
		return (cmd_unset(info->tok->args, info));
	else if (ft_strcmp(info->tok->args[0], "echo") == 0)
		return (cmd_echo(info));
	else if (ft_strcmp(info->tok->args[0], "env") == 0)
		return (cmd_env(info, info->tok->args));
	else
		return (run(info->tok->args, info->env, info));
	return (1);
}
