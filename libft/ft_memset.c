/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnowbir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 23:57:59 by ssnowbir          #+#    #+#             */
/*   Updated: 2020/05/12 23:58:59 by ssnowbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *a, int c, size_t n)
{
	char	*p;

	p = (char*)a;
	while (n > 0)
	{
		*p = (char)c;
		n--;
		p++;
	}
	return (a);
}
