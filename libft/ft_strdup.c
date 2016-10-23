/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:04:58 by ssachet           #+#    #+#             */
/*   Updated: 2015/02/20 11:47:54 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	char	*dup2;

	if (!s1)
		return (NULL);
	if (NULL == (dup = (char *)malloc(ft_strlen(s1) + 1)))
		return (NULL);
	dup2 = dup;
	while (*s1)
		*dup2++ = *s1++;
	*dup2 = '\0';
	return (dup);
}
