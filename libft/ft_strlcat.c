/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:51:24 by ssachet           #+#    #+#             */
/*   Updated: 2015/01/07 10:33:55 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t size)
{
	char		*s1bis;
	const char	*s2c;
	size_t		n;
	size_t		s1len;

	n = size;
	s1bis = s1;
	s2c = s2;
	while (*s1bis && n--)
		s1bis++;
	s1len = s1bis - s1;
	n = size - s1len;
	if (n == 0)
		return (s1len + ft_strlen(s2c));
	while (*s2c != '\0')
	{
		if (n != 1)
		{
			*s1bis++ = *s2c;
			n--;
		}
		s2c++;
	}
	*s1bis = '\0';
	return (s1len + (s2c - s2));
}
