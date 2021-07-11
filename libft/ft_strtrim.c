/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnowbir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 17:28:21 by ssnowbir          #+#    #+#             */
/*   Updated: 2020/05/15 18:34:09 by ssnowbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				symbol(char s1, const char *set)
{
	int		i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] != s1)
			i++;
		else
			return (1);
	}
	return (0);
}

static char		*empty(void)
{
	char	*empty;

	if (!(empty = (char*)malloc(sizeof(*empty * 1))))
		return (0);
	*empty = '\0';
	return (empty);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char		*arr;
	size_t		sum;
	int			k;
	int			j;
	int			i;

	i = 0;
	sum = ft_strlen(s1);
	j = 0;
	k = sum - 1;
	if (s1 == NULL)
		return (NULL);
	while (symbol(s1[j], set) == 1)
		j++;
	while (symbol(s1[k], set) == 1 && k != 0)
		k--;
	if (k < j)
		return (empty());
	if (!(arr = (char*)malloc(sizeof(char) * ((k - j) + 2))))
		return (NULL);
	while (j <= k)
		arr[i++] = s1[j++];
	arr[i] = '\0';
	return (arr);
}
