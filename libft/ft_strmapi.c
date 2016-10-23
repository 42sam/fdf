/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 21:16:12 by ssachet           #+#    #+#             */
/*   Updated: 2015/01/07 10:33:55 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*s2;
	unsigned int	i;

	i = 0;
	if (!s || !(*f))
		return (NULL);
	if (NULL == (s2 = ft_strnew(ft_strlen((char *)s))))
		return (NULL);
	while (s[i])
	{
		s2[i] = (*f)(i, s[i]);
		i++;
	}
	return (s2);
}
