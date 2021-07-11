/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnowbir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 23:24:10 by ssnowbir          #+#    #+#             */
/*   Updated: 2020/05/12 23:25:51 by ssnowbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	int		i;

	str = (char*)s;
	i = 0;
	while (n > 0)
	{
		if (str[i] == (char)c)
			return ((char*)s + i);
		n--;
		i++;
	}
	return (NULL);
}
