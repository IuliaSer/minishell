/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnowbir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 01:09:23 by ssnowbir          #+#    #+#             */
/*   Updated: 2020/05/18 22:45:06 by ssnowbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*arr;
	int		i;
	int		size;

	i = 0;
	if (!s)
		return (ft_strdup(""));
	size = ft_strlen(s) - start;
	if (size <= 0)
		return (ft_strdup(""));
	if ((unsigned int)size < len)
		len = (unsigned int)size;
	arr = (char*)malloc(len + 1 * sizeof(char));
	if (!arr)
		return (NULL);
	while (len != 0)
	{
		arr[i] = s[start];
		start++;
		len--;
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
