/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iserzhan <iserzhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 21:23:06 by iserzhan          #+#    #+#             */
/*   Updated: 2020/12/07 21:33:45 by iserzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "libft/libft.h"
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/errno.h>

# define PATH_MAX 1024

int g_ret;

typedef struct		s_envp
{
	char			*value;
	struct s_envp	*next;
}					t_envp;

typedef struct		s_tok
{
	char			**args;
	char			**red;
	char			*tmp_redir;
	char			*tmp;
	char			*tmp2;
}					t_tok;

typedef struct		s_info_
{
	char			**new;
	int				flag_start;
	int				flag;
	int				sum;
	int				flag_finish;
	int				ret;
	int				status;
	int				temp_fd[2];
	int				flag_nsf;
	int				a;
	int				r_redir;
}					t_info_;

typedef struct		s_info
{
	int				flag_arg;
	char			*line;
	int				redirect;
	int				sintax_err;
	int				flag_pipe;
	char			*arr_env;
	int				dollar_quest_mark;
	int				i;
	int				j;
	int				many_redirect;
	int				count;
	char			*name;
	char			*name2;
	int				flag_redir;
	int				flag_word;
	int				sum_red;
	int				tmp_j;
	t_info_			*info2;
	t_tok			*tok;
	t_envp			*env;
	int				fd[2];
}					t_info;

int					main(int args, char **argv, char **envp);
t_envp				*init_env(char **envp);
t_envp				*ft_envnew(void *value);
void				ft_envadd_back(t_envp **lst, t_envp *new);
t_info				*make_struct_info();
int					parsing(t_info *info, int m, int j);
char				**put_new_str(t_info *info, int j, int i);
char				*get_row(t_info *info);
int					get_arr_redirect(t_info *info);
int					get_args(t_info *info, int status_pars);
int					put_arr_redirect(t_info *info);
char				*quotes_no(t_info *info);
char				*get_home_dir(t_info *info, char *arr, int m, int a);
char				*quotes_one(t_info *info);
char				*quotes_one_redir(t_info *info, int j);
char				*quotes_two(t_info *info);
char				*quotes_two_redir(t_info *info, int j);
char				*get_env(t_info *info, char *arr, int m);
char				*quotes_one_env(t_info *info, char *arr);
char				*quotes_two_env(t_info *info, char *arr);
char				*get_new_row(char *arr, char c);
void				print_err(t_info *info);
int					char_in_str(char c, char *arr, int flag_null);
int					check_correct_row(char *line, t_info *info, int i);
int					check_sym_env(char c);
void				count_sum_red(t_info *info, int *count, int j);
void				no_red_in_arr_red(t_info *info);
int					red_in_arr_red(t_info *info);
int					check_correct_row2(char *line, t_info *info, int i);
char				*is_no_digit_or_no_char(t_info *info, char *arr);
char				*is_digit_env(char *arr, t_info *info);
int					execute(t_info *info, t_envp *env);
void				cmd_exit(char **args, t_envp *env, t_info *info);
int					cmd_cd(char *path, t_info *info);
int					cmd_pwd(char **args);
int					cmd_export(char **args, t_envp *env, t_info *info);
int					cmd_env(t_info *info, char **args);
int					cmd_unset(char **args, t_info *onfo);
int					cmd_echo(t_info *info);
int					run_pipe(t_info *info, int *fd, t_envp *env);
int					run_redir(t_info *info);
void				quotes_no_or_slash_or_no(t_info *info);
void				quotes_two_slash(t_info *info);
void				quotes_two_dollar(t_info *info);
void				quotes_two_redir2(t_info *info, int j);
void				reset_fds(int *fd);
void				ft_free(char **str);
char				*ft_strjoin_new(char *s1, char *s2, int i, int j);
int					ft_strjoin_new2(char *s1, char *s2);
void				sig_interrupt(int code);
void				get_new_row_2(t_info *info);
void				ft_free_red(t_info *info);
char				**dub_in_args(t_info *info, int j);
int					get_args2(t_info *info);
int					print_error(char *args, t_info *info);
int					print_error_redir(char *redir, t_info *info);
int					print_error_cmd(char *args, t_info *info,
char **envp, char *path);
int					print_error_nsf(char **args, t_info *info);
int					run(char **args, t_envp *env, t_info *info);
void				check_signal(t_info *info);
char				*find_path(char **args, t_envp *env,
	int *flag, char **envp);
void				free_memo(char **envp, char *path);
int					print_error_nsf_path(char *args, t_info *info,
	char **envp, char *path);
void				pipe_eof(void);

#endif
