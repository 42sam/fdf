/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 17:36:20 by ssachet           #+#    #+#             */
/*   Updated: 2015/01/07 10:33:54 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list *head)
{
	if (head)
	{
		ft_putchar('\n');
		while (head != NULL)
		{
			ft_putstr(head->content);
			ft_putchar('\n');
			head = head->next;
		}
		ft_putchar('\n');
	}
}
