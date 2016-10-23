/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 16:39:29 by ssachet           #+#    #+#             */
/*   Updated: 2015/01/07 10:33:53 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *copy;
	t_list *head;
	t_list *previous;

	if (!lst || !f)
		return (NULL);
	if (NULL == (copy = (*f)(lst)))
		return (NULL);
	head = copy;
	previous = copy;
	lst = lst->next;
	while (lst)
	{
		if (NULL == (copy = (*f)(lst)))
			return (NULL);
		previous->next = copy;
		previous = copy;
		lst = lst->next;
	}
	copy->next = NULL;
	return (head);
}
