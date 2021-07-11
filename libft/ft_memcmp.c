/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnowbir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 18:24:22 by student           #+#    #+#             */
/*   Updated: 2020/05/12 23:28:45 by ssnowbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char*)arr1;
	b = (unsigned char*)arr2;
	if (a == b && n == 0)
		return (0);
	while (n > 0)
	{
		if (*a != *b)
		{
			return (*a - *b);
		}
		else
		{
			a++;
			b++;
			n--;
		}
	}
	return (0);
}
