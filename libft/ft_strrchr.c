/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 18:27:32 by ssachet           #+#    #+#             */
/*   Updated: 2015/01/07 10:33:55 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *position;

	position = NULL;
	while (*s)
	{
		if (*s == c)
			position = (char *)s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	if (position == NULL)
		return (NULL);
	else
		return (position);
}
