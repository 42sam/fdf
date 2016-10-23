/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 19:13:52 by ssachet           #+#    #+#             */
/*   Updated: 2015/01/07 10:33:55 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 && (*s1 == *s2) && n)
	{
		s1++;
		s2++;
		n--;
	}
	if (*s1 == *s2 || n == 0)
		return (0);
	return ((*(unsigned char *)s1 < *(unsigned char *)s2) ? -1 : +1);
}
