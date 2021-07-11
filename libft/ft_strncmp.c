/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnowbir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 23:45:51 by ssnowbir          #+#    #+#             */
/*   Updated: 2020/05/13 00:54:34 by ssnowbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		i;
	int		res;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && n > 1)
	{
		if (s1[i] == '\0' || s2[i] == '\0')
			return (0);
		n--;
		i++;
	}
	res = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (res);
}
