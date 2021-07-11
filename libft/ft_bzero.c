/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnowbir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 22:28:33 by ssnowbir          #+#    #+#             */
/*   Updated: 2020/05/12 22:28:37 by ssnowbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *a, size_t n)
{
	char	*p;

	p = (char*)a;
	while (n > 0)
	{
		*p = '\0';
		n--;
		p++;
	}
}