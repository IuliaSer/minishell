/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iserzhan <iserzhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 19:36:34 by iulias            #+#    #+#             */
/*   Updated: 2020/12/08 12:42:23 by iserzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		write_in_remainder(char **temp, int fd, char *copy, char **remainder)
{
	if (!copy)
		return (1);
	if ((*temp = ft_strchr(copy, '\n')) != NULL)
	{
		**temp = '\0';
		if (!(remainder[fd] = ft_strdup(*temp + 1)))
			return (-1);
	}
	return (1);
}

int		check_remainder(char **temp, char **line, char **remainder, int fd)
{
	char	*copy;

	copy = remainder[fd];
	if (write_in_remainder(temp, fd, copy, remainder) == -1)
		return (-1);
	if (!(remainder[fd]))
	{
		if (!(*line = ft_strdup("")))
			return (-1);
	}
	else if (copy != remainder[fd])
	{
		if (!(*line = ft_strdup(copy)))
			return (-1);
		free(copy);
	}
	else
	{
		if (!(*line = ft_strdup(remainder[fd])))
			return (-1);
		free(remainder[fd]);
		remainder[fd] = NULL;
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*remainder[14000];
	char		buf[30 + 1];
	char		*temp;
	int			readed;
	char		*old_line;

	if ((line == NULL) || (fd < 0)
	|| (read(fd, NULL, 0) < 0))
		return (-1);
	temp = 0;
	if (check_remainder(&temp, line, remainder, fd) == -1)
		return (-1);
	while (!temp && (readed = read(fd, buf, 30)))
	{
		buf[readed] = '\0';
		old_line = *line;
		if (write_in_remainder(&temp, fd, buf, remainder) == -1)
			return (-1);
		if (!(*line = ft_strjoin(*line, buf)))
			return (-1);
		free(old_line);
	}
	if (readed == 0 && remainder[fd] == 0)
		return (0);
	return (1);
}

void	get_input(char **line, int res)
{
	static char		*cash;
	char			*tmp;

	while ((res = get_next_line(0, line)) != 1)
	{
		if (res == 0 && **line == '\0' && !cash)
		{
			free(*line);
			write(2, "exit\n", 5);
			exit(0);
		}
		if (res == 0 && (cash || *line != '\0'))
		{
			tmp = cash;
			cash = ft_strjoin(cash, *line);
			free(tmp);
			free(*line);
			continue ;
		}
	}
	tmp = *line;
	*line = ft_strjoin(cash, *line);
	free(cash);
	free(tmp);
	cash = NULL;
}
