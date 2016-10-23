/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad_left.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 09:01:27 by ssachet           #+#    #+#             */
/*   Updated: 2015/01/08 05:56:47 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*pad_left(char *s1, char c, int x)
{
	char *s2;
	char *s2c;

	if (x == (int)ft_strlen(s1))
		return (s1);
	s2 = (char *)malloc(x + 1);
	s2c = s2;
	x -= (int)ft_strlen(s1);
	while (x--)
		*s2++ = c;
	ft_strcpy(s2, s1);
	return (s2c);
}
