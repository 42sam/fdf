/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 05:18:24 by ssachet           #+#    #+#             */
/*   Updated: 2015/02/20 12:30:39 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*lst_copy(t_list *lst)
{
	t_list	*head;
	t_list	*node;

	head = new_dict(lst->name, lst->value, NULL);
	node = head;
	lst = lst->next;
	while (lst)
	{
		node->next = new_dict(lst->name, lst->value, NULL);
		node = node->next;
		lst = lst->next;
	}
	return (head);
}
