/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_bin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnowbir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 18:28:09 by iserzhan          #+#    #+#             */
/*   Updated: 2020/12/06 19:52:32 by ssnowbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		free_memo(char **envp, char *path)
{
	int	i;

	i = 0;
	while (envp[i])
		free(envp[i++]);
	if (envp)
		free(envp);
	if (path)
		free(path);
}

char		**convert_to_array(t_envp *env)
{
	int		i;
	char	**envp1;
	t_envp	*temp;

	temp = env;
	i = 0;
	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	if (!(envp1 = (char**)malloc(sizeof(char *) * i + 1)))
		return (NULL);
	envp1[i] = NULL;
	i = 0;
	while (env->next != NULL)
	{
		envp1[i] = ft_strdup(env->value);
		env = env->next;
		i++;
	}
	envp1[i++] = ft_strdup(env->value);
	return (envp1);
}

static void	child(t_info *info, char *path, char **envp)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	if ((execve(path, info->tok->args, envp)) == -1)
		print_error(info->tok->args[0], info);
}

static void	parent(t_info *info, pid_t pid)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	waitpid(pid, &info->info2->ret, WUNTRACED);
	check_signal(info);
}

int			run(char **args, t_envp *env, t_info *info)
{
	pid_t	pid;
	char	**envp;
	char	*path;

	info->info2->flag_nsf = 0;
	if (!(info->tok->red) && (info->flag_pipe == 0))
		dup2(info->info2->temp_fd[1], 1);
	envp = convert_to_array(env);
	if (!(path = find_path(args, env, &info->info2->flag_nsf, envp)))
	{
		if (info->info2->flag_nsf == 0)
			return (print_error_cmd(args[0], info, envp, path));
		else
			return (print_error_nsf_path(args[0], info, envp, path));
	}
	else
		pid = fork();
	if (pid == 0)
		child(info, path, envp);
	else if (pid > 0)
		parent(info, pid);
	else
		ft_putendl_fd("Failed to fork", 1);
	free_memo(envp, path);
	return (1);
}
