/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 06:37:05 by ssachet           #+#    #+#             */
/*   Updated: 2015/02/20 12:30:39 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*tr(char *s, char c, char tr)
{
	char	*trim;
	int		i;
	int		k;
	int		j;
	int		trimlen;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			s[i] = tr;
		i++;
	}
	return (s);
}
