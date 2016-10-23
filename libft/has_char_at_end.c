/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_char_at_end.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 18:55:22 by ssachet           #+#    #+#             */
/*   Updated: 2015/01/07 10:33:56 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		has_char_at_end(char *str, char c)
{
	int			i;
	int			j;

	j = 0;
	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i - 1] == c)
			return (j);
		i--;
		j--;
	}
	return (1);
}
