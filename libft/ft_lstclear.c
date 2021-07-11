/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnowbir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 19:33:16 by ssnowbir          #+#    #+#             */
/*   Updated: 2020/05/16 14:55:27 by ssnowbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*a;
	t_list	*b;

	if (!lst || !del)
		return ;
	a = *lst;
	while (a)
	{
		b = a->next;
		del(a->content);
		free(a);
		a = b;
	}
	*lst = NULL;
}
