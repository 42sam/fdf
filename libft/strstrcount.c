/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstrcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 05:25:28 by ssachet           #+#    #+#             */
/*   Updated: 2015/02/20 12:30:39 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		strstrcount(char *s1, char *s2)
{
	int i;
	int cnt;

	cnt = 0;
	if (!s1 || !s2)
		return (0);
	if (!ft_strlen(s2))
		return (0);
	while (*s1)
	{
		if (*s1 == *s2)
		{
			i = 0;
			while (s2[i] == s1[i] && s2[i] && s1[i])
				i++;
			if (s2[i] == '\0')
			{
				s1 = s1 + i - 1;
				cnt++;
			}
		}
		s1++;
	}
	return (0);
}
