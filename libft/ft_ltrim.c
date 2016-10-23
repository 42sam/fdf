/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltrim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 04:06:03 by ssachet           #+#    #+#             */
/*   Updated: 2015/01/07 10:33:54 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ltrim(char const *s)
{
	char	*trim;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && ft_isspace(s[i]))
		i++;
	if ((i > (signed int)ft_strlen(s) - 1))
	{
		trim = ft_strnew(0);
		return (trim);
	}
	if (NULL == (trim = (char *)malloc(ft_strlen(s + i) + 1)))
		return (NULL);
	ft_strcpy(trim, (char const *)(s + i));
	return (trim);
}
