/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 18:33:53 by ssachet           #+#    #+#             */
/*   Updated: 2015/01/27 16:42:07 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int i;

	if (!s1 || !s2)
		return (NULL);
	if (!ft_strlen(s2))
		return ((char *)s1);
	while (*s1)
	{
		if (*s1 == *s2)
		{
			i = 0;
			while (s2[i] == s1[i] && s2[i] && s1[i])
				i++;
			if (s2[i] == '\0')
				return ((char *)s1);
		}
		s1++;
	}
	return (NULL);
}
