/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_del_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 06:23:29 by ssachet           #+#    #+#             */
/*   Updated: 2015/02/20 12:30:39 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	deal_with_single_quotes(char **to_delete, int i)
{
	while (to_delete[i])
	{
		if (ft_strequ(to_delete[i], "''"))
			to_delete[i] = makestr("");
		i++;
	}
}

int		tab_del_i(char **to_delete, t_list **head)
{
	t_list	*before;
	t_list	*node;
	int		i;

	i = 1;
	deal_with_single_quotes(to_delete, i);
	while (to_delete[i])
	{
		if (ft_strequ((*head)->name, to_delete[i]))
		{
			*head = (*head)->next;
			if (*head == NULL)
				return (-1);
		}
		node = *head;
		while (node)
		{
			if (ft_strequ(node->name, to_delete[i]))
				before->next = node->next;
			before = node;
			node = node->next;
		}
		i++;
	}
	return (1);
}
