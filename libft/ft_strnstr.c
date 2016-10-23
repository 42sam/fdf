/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 18:33:44 by ssachet           #+#    #+#             */
/*   Updated: 2015/01/07 10:33:55 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *s1, const char *s2, size_t n)
{
	int i;
	int n2;

	if (!ft_strlen(s2))
		return ((char *)s1);
	while (*s1 && n--)
	{
		if (*s1 == *s2)
		{
			i = 0;
			n2 = n + 1;
			while (s2[i] == s1[i] && s2[i] && s1[i] && n2--)
				i++;
			if (s2[i] == '\0')
				return ((char *)s1);
		}
		s1++;
	}
	return (NULL);
}
