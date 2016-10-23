/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rtrim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 20:46:07 by ssachet           #+#    #+#             */
/*   Updated: 2015/01/07 10:33:54 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_rtrim(char const *s)
{
	char	*trim;
	int		i;

	if (!s)
		return (NULL);
	i = ft_strlen(s) - 1;
	while (i >= 0 && ft_isspace(s[i]))
		i--;
	if (i < 0)
	{
		trim = ft_strnew(0);
		return (trim);
	}
	if (NULL == (trim = (char *)malloc(i + 2)))
		return (NULL);
	ft_strncpy(trim, (char const *)s, i + 1);
	return (trim);
}
