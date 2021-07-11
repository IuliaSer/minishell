/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnowbir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 00:28:50 by ssnowbir          #+#    #+#             */
/*   Updated: 2020/05/13 00:30:57 by ssnowbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int symbol)
{
	char	*a;

	a = (char*)string;
	while (*a != '\0')
	{
		if (*a == symbol)
			return (a);
		a++;
	}
	if (*a == '\0' && symbol == '\0')
		return (a);
	return (a = NULL);
}
