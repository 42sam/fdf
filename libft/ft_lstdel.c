/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 16:39:26 by ssachet           #+#    #+#             */
/*   Updated: 2015/01/07 10:33:53 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;

	if (alst && *alst && del)
	{
		tmp = *alst;
		while (tmp)
		{
			del(tmp->content, tmp->content_size);
			tmp = tmp->next;
		}
		*alst = NULL;
	}
}
