/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iserzhan <iserzhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:00:23 by iserzhan          #+#    #+#             */
/*   Updated: 2020/12/07 20:23:35 by iserzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*search_env(t_info *info, char *var)
{
	int		i;
	int		len_var;
	t_envp	*temp;

	i = 0;
	temp = info->env;
	len_var = ft_strlen(var);
	while (temp->next != NULL)
	{
		if ((ft_strncmp(temp->value, var, len_var) == 0) &&
			(temp->value[len_var] == '='))
			return (ft_strdup(&temp->value[len_var + 1]));
		temp = temp->next;
	}
	return (NULL);
}

static void	create_oldpwd(char *value, t_info *info)
{
	char	*oldpwd_c;

	oldpwd_c = ft_strjoin("OLDPWD=", value);
	ft_envadd_back(&info->env, ft_envnew(oldpwd_c));
	free(oldpwd_c);
}

static void	ft_change_env(t_info *info, char *var, char *value)
{
	int		len_var;
	int		oldpwd;
	int		i;
	int		j;
	t_envp	*temp;

	i = 0;
	j = 0;
	oldpwd = 0;
	len_var = ft_strlen(var);
	temp = info->env;
	while (temp->next != NULL)
	{
		if ((!(ft_strncmp(var, temp->value, len_var))) &&
			(temp->value[len_var] == '='))
		{
			while (value[j])
				temp->value[++len_var] = value[j++];
			temp->value[++len_var] = '\0';
			oldpwd = 1;
		}
		temp = temp->next;
	}
	if (!oldpwd)
		create_oldpwd(value, info);
}

int			cmd_cd(char *path, t_info *info)
{
	char	*path2;
	char	oldpwd[PATH_MAX];
	char	pwd[PATH_MAX];

	path2 = ft_substr(path, 0, ft_strlen(path));
	if (!path)
	{
		free(path2);
		path2 = NULL;
	}
	if (!path2 || (ft_strncmp(path2, "~", 1)) == 0)
		path2 = search_env(info, "HOME");
	getcwd(oldpwd, PATH_MAX);
	ft_change_env(info, "OLDPWD", oldpwd);
	if (chdir(path2) == -1)
		print_error(info->tok->args[0], info);
	getcwd(pwd, PATH_MAX);
	ft_change_env(info, "PWD", pwd);
	if (path2)
		free(path2);
	return (1);
}
