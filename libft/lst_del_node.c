/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_del_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 06:21:02 by ssachet           #+#    #+#             */
/*   Updated: 2015/02/20 12:30:39 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		lst_del_node(t_list *to_delete, t_list **head)
{
	t_list	*before;
	t_list	*node;

	while (to_delete)
	{
		if (ft_strequ((*head)->name, to_delete->name))
		{
			*head = (*head)->next;
			if (*head == NULL)
				return (-1);
		}
		node = *head;
		while (node)
		{
			if (ft_strequ(node->name, to_delete->name))
				before->next = node->next;
			before = node;
			node = node->next;
		}
		to_delete = to_delete->next;
	}
	return (1);
}
