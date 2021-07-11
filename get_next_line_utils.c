/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnowbir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 14:49:17 by iulias            #+#    #+#             */
/*   Updated: 2020/12/05 20:58:57 by ssnowbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strchr(const char *s, int c)
{
	char	*str;
	int		i;

	str = (char*)s;
	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i++;
	}
	if (c == '\0')
		return (&str[i]);
	return (NULL);
}

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s == 0)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char		*ft_strdup(const char *s)
{
	char	*str;
	size_t	size;
	size_t	i;

	i = 0;
	size = ft_strlen(s);
	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static int	count_len(char const *s1, char const *s2)
{
	int len;

	if (!s2)
		len = ft_strlen(s1);
	else if (!s1)
		len = ft_strlen(s2);
	else
		len = ft_strlen(s1) + ft_strlen(s2);
	return (len);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*nstr;
	int		i;
	int		j;
	int		len;

	if (!s2 && !s1)
		return (0);
	len = count_len(s1, s2);
	if (!(nstr = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
		while (s1[j])
			nstr[i++] = s1[j++];
	j = 0;
	if (s2)
		while (s2[j])
			nstr[i++] = s2[j++];
	nstr[i] = '\0';
	return (nstr);
}
