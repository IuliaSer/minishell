/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnowbir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 00:59:27 by ssnowbir          #+#    #+#             */
/*   Updated: 2020/05/13 01:01:44 by ssnowbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int symbol)
{
	int		sum;
	int		i;
	int		flag;
	char	*a;

	a = (char*)string;
	i = 0;
	sum = 0;
	flag = 0;
	while (a[i] != '\0')
	{
		if (a[i] == symbol && i == 0)
			flag++;
		if (a[i] == symbol)
			sum = i;
		i++;
	}
	if (sum != 0 || flag != 0)
		return ((char*)a + sum);
	if (a[i] == '\0' && symbol == 0)
		return (&a[i]);
	return (a = NULL);
}
