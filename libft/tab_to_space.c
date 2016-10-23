/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_to_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 06:44:28 by ssachet           #+#    #+#             */
/*   Updated: 2015/02/20 12:30:39 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*tab_to_space(char *s)
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
		if (ft_isspace(s[i]))
			s[i] = ' ';
		i++;
	}
	return (s);
}
