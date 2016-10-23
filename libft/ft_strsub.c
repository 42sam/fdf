/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 21:17:49 by ssachet           #+#    #+#             */
/*   Updated: 2015/02/20 11:48:23 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	j;

	if (s == NULL)
		return (NULL);
	j = 0;
	if (NULL == (substr = (char *)malloc(len + 1)))
		return (NULL);
	while (len-- && s[start])
		substr[j++] = s[start++];
	substr[j] = '\0';
	return (substr);
}
