/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnowbir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 19:09:30 by ssnowbir          #+#    #+#             */
/*   Updated: 2020/12/06 19:22:30 by ssnowbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_envp					*make_struct_info_env(void)
{
	t_envp *env;

	if (!(env = (t_envp*)malloc(sizeof(t_envp))))
		return (0);
	env->value = NULL;
	env->next = NULL;
	return (env);
}

t_tok					*make_struct_info_tok(void)
{
	t_tok *tok;

	if (!(tok = (t_tok*)malloc(sizeof(t_tok))))
		return (0);
	tok->args = NULL;
	tok->red = NULL;
	tok->tmp = NULL;
	tok->tmp_redir = NULL;
	tok->tmp2 = NULL;
	return (tok);
}

t_info_					*make_struct_info2(void)
{
	t_info_ *info2;

	if (!(info2 = (t_info_*)malloc(sizeof(t_info_))))
		return (0);
	info2->new = NULL;
	info2->flag = 0;
	info2->sum = 0;
	info2->flag_finish = 0;
	info2->ret = 0;
	info2->flag_start = 0;
	info2->status = 1;
	info2->flag_nsf = 0;
	info2->a = 0;
	info2->r_redir = 0;
	return (info2);
}

t_info					*make_struct_info(char **env)
{
	t_info *info;

	if (!(info = (t_info*)malloc(sizeof(t_info))))
		return (0);
	info->flag_arg = 0;
	info->line = NULL;
	info->redirect = 0;
	info->sintax_err = 0;
	info->i = 0;
	info->name2 = NULL;
	info->name = NULL;
	info->flag_redir = 0;
	info->flag_word = 0;
	info->flag_pipe = 0;
	info->j = 0;
	info->many_redirect = 0;
	info->dollar_quest_mark = 0;
	info->sum_red = 0;
	info->tmp_j = 0;
	info->fd[0] = -1;
	info->fd[1] = -1;
	info->info2 = make_struct_info2();
	info->tok = make_struct_info_tok();
	info->env = init_env(env);
	return (info);
}

void					reset_fds(int *fd)
{
	fd[0] = -1;
	fd[1] = -1;
}
