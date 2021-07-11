/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnowbir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 12:18:40 by ssnowbir          #+#    #+#             */
/*   Updated: 2020/05/20 15:17:21 by ssnowbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_rows(const char *str, int j, char c)
{
	int		i;

	i = 0;
	while (str[j] == c)
		str++;
	while (str[j] && str[j] != c)
	{
		j++;
		i++;
	}
	return (i);
}

static int		quantity_symbols(const char *str, char c)
{
	int		sum;

	sum = 0;
	while (*str)
	{
		if (*str != '\0' && *str != c)
			sum++;
		while (*str != c && *str)
			str++;
		while (*str == c && *str)
			str++;
	}
	return (sum);
}

static void		*ft_free(char **str, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
		free(str[i]);
	free(str);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char	**p;
	int		quantity_word;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!s)
		return (NULL);
	quantity_word = quantity_symbols(s, c);
	if (!(p = (char**)malloc((1 + quantity_word) * sizeof(char*))))
		return (NULL);
	while (quantity_word-- > 0)
	{
		while (s[i] == c && s[i])
			i++;
		if (!(p[j++] = ft_substr(s, i, ft_rows(s, i, c))))
			return (ft_free(p, quantity_word));
		i += ft_rows(s, i, c);
	}
	p[j] = NULL;
	return (p);
}
