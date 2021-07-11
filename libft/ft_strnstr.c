/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnowbir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 01:30:02 by ssnowbir          #+#    #+#             */
/*   Updated: 2020/05/14 11:07:46 by ssnowbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t a)
{
	size_t		i;
	size_t		j;

	j = 0;
	i = 0;
	if (*str2 == '\0' || (*str1 == '\0' && *str2 == '\0'))
		return ((char*)str1);
	if (ft_strlen(str1) < ft_strlen(str2) || a < ft_strlen(str2))
		return (NULL);
	while (str1[i] && i < a)
	{
		j = 0;
		while (str1[i + j] == str2[j] && str2[j] && i + j < a)
		{
			j++;
			if (j == ft_strlen(str2))
				return ((char*)str1 + i);
		}
		i++;
	}
	return (NULL);
}
