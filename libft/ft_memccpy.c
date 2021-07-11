/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnowbir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 12:17:44 by ssnowbir          #+#    #+#             */
/*   Updated: 2020/05/12 23:23:53 by ssnowbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *destination, const void *source, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	*p1;

	p = (unsigned char*)destination;
	p1 = (unsigned char*)source;
	while (n > 0)
	{
		if (*p1 == (unsigned char)c)
		{
			*p = *p1;
			p++;
			return (p);
		}
		*p = *p1;
		p++;
		p1++;
		n--;
	}
	return (NULL);
}
