/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnowbir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 20:44:12 by ssnowbir          #+#    #+#             */
/*   Updated: 2020/05/19 17:00:08 by ssnowbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*a;
	t_list	*b;

	if (!lst || !f)
		return (NULL);
	if (!(a = ft_lstnew(f(lst->content))))
		return (NULL);
	b = a;
	lst = lst->next;
	while (lst)
	{
		if (!(a = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&b, del);
			return (0);
		}
		lst = lst->next;
		ft_lstadd_back(&b, a);
	}
	a->next = NULL;
	return (b);
}
