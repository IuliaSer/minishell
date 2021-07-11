/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnowbir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 18:30:50 by iserzhan          #+#    #+#             */
/*   Updated: 2020/12/07 21:00:37 by ssnowbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		*search_env(t_envp *env, char *var)
{
	int		i;
	int		len_var;

	i = 0;
	len_var = ft_strlen(var);
	while (env->next != NULL)
	{
		if ((ft_strncmp(env->value, var, len_var) == 0) &&
			(env->value[len_var] == '='))
			return (ft_strdup(&env->value[len_var + 1]));
		env = env->next;
	}
	return (NULL);
}

static char		*find_path2(char **path, struct stat	file_name, char **args)
{
	int		i;
	char	*path_to_cmd;
	char	*temp_path;

	i = 0;
	while (path[i])
	{
		path_to_cmd = NULL;
		temp_path = ft_strjoin(path[i], "/");
		path_to_cmd = ft_strjoin(temp_path, args[0]);
		if (!(stat(path_to_cmd, &file_name)))
		{
			free(temp_path);
			return (path_to_cmd);
		}
		i++;
		free(temp_path);
		free(path_to_cmd);
	}
	return (NULL);
}

static void		free_find_path(char **path, char *arr)
{
	int i;

	i = 0;
	while (path[i])
		free(path[i++]);
	if (path)
		free(path);
	free(arr);
}

char			*find_path(char **args, t_envp *env, int *flag, char **envp)
{
	char		**path;
	char		*arr;
	struct stat	file_name;
	char		*arr2;

	if (!(stat(args[0], &file_name)))
		return (ft_strdup(args[0]));
	if (!ft_strncmp(&args[0][0], "/", 1) || !ft_strncmp(&args[0][0], "./", 2)
		|| !ft_strncmp(&args[0][0], "/bin", 4))
	{
		if ((execve(args[0], args, envp)) == -1)
		{
			*flag = 1;
			return (NULL);
		}
	}
	if (!(arr = search_env(env, "PATH")))
	{
		*flag = 1;
		return (NULL);
	}
	path = ft_split(arr, ':');
	arr2 = find_path2(path, file_name, args);
	free_find_path(path, arr);
	return (arr2);
}
