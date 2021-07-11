/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnowbir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 16:28:21 by ssnowbir          #+#    #+#             */
/*   Updated: 2020/05/16 15:10:46 by ssnowbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dest, char const *src, size_t size)
{
	size_t		i;
	char		*s;

	i = 0;
	s = (char*)src;
	if (!dest || !src)
		return (0);
	if (size == 0)
		return ((size_t)(ft_strlen((char *)src)));
	if (size != 0)
	{
		while (s[i] && i < size - 1)
		{
			dest[i] = s[i];
			i++;
		}
		dest[i] = 0;
	}
	return (ft_strlen(s));
}
