/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnowbir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 00:34:35 by ssnowbir          #+#    #+#             */
/*   Updated: 2020/11/23 14:52:58 by ssnowbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strjoin(char const *s1, char const *s2)
{
	char		*arr;
	size_t		sum;
	size_t		i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	sum = (ft_strlen(s1) + ft_strlen(s2)) + 1;
	if (!(arr = (char*)malloc(sizeof(char) * sum)))
		return (NULL);
	while (*s1 != '\0')
		arr[i++] = *s1++;
	while (*s2 != '\0')
		arr[i++] = *s2++;
	arr[i] = '\0';
	return (arr);
}
