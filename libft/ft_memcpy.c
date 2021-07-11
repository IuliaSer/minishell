/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnowbir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 23:49:34 by ssnowbir          #+#    #+#             */
/*   Updated: 2020/05/12 23:51:05 by ssnowbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t n)
{
	unsigned char	*p;
	unsigned char	*p1;

	p = (unsigned char*)destination;
	p1 = (unsigned char*)source;
	if (destination == NULL && source == NULL)
		return (NULL);
	while (n > 0)
	{
		*p = *p1;
		p++;
		p1++;
		n--;
	}
	return (destination);
}
