/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnowbir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 22:51:37 by ssnowbir          #+#    #+#             */
/*   Updated: 2020/05/16 13:59:07 by ssnowbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		sum_num(int n)
{
	int		sum;

	sum = 0;
	if (n == -2147483648)
		return (10);
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = n * -1;
	}
	while (n > 0)
	{
		n = n / 10;
		sum++;
	}
	return (sum);
}

static char		count_itoa(char *arr, int n, int sum)
{
	int		copy_int;
	char	*b;

	b = (char*)arr + sum;
	copy_int = n;
	*b-- = '\0';
	if (n == 0)
		*b = 0 + '0';
	while (copy_int > 0)
	{
		*b-- = (copy_int % 10) + '0';
		copy_int = copy_int / 10;
	}
	return (*arr);
}

char			*ft_itoa(int n)
{
	char	*arr;
	int		sum;
	int		i;

	i = 0;
	sum = sum_num(n);
	if (n < 0)
		sum += 1;
	if (!(arr = (char*)malloc(sizeof(char) * sum + 1)))
		return (NULL);
	if (n < 0)
	{
		arr[i++] = '-';
		n = n * -1;
	}
	if (n == -2147483648)
	{
		arr[i++] = 2 + '0';
		count_itoa(arr, 147483648, sum);
	}
	count_itoa(arr, n, sum);
	return (arr);
}
