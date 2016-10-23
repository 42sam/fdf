/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 05:15:59 by ssachet           #+#    #+#             */
/*   Updated: 2015/02/20 12:30:38 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_value(char *name, t_list *node)
{
	while (node)
	{
		if (ft_strequ(name, node->name))
			return (node->value);
		node = node->next;
	}
	return (NULL);
}
