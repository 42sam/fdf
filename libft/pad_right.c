/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad_right.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 09:01:25 by ssachet           #+#    #+#             */
/*   Updated: 2015/01/07 10:33:56 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*pad_right(char *s1, char c, int x)
{
	char *s2;
	char *s2c;
	char *s1c;

	s1c = s1;
	if (x == (int)ft_strlen(s1))
		return (s1);
	s2 = (char *)malloc(x + 1);
	s2c = s2;
	while (*s1c)
		*s2++ = *s1c++;
	x -= ft_strlen(s1);
	while (x--)
		*s2++ = c;
	*s2 = '\0';
	return (s2c);
}
