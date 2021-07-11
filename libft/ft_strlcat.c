/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnowbir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 21:24:27 by ssnowbir          #+#    #+#             */
/*   Updated: 2020/05/16 14:03:48 by ssnowbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		sum;

	if (*src == '\0')
		return (ft_strlen(dst));
	if (size < ft_strlen(dst))
		sum = size + ft_strlen(src);
	else
		sum = ft_strlen(dst) + ft_strlen(src);
	while (*dst && size > 1)
	{
		dst++;
		size--;
	}
	if (size > 1)
	{
		while (*src && size-- > 1)
			*dst++ = *src++;
		*dst = '\0';
	}
	return (sum);
}
