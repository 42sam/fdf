/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 21:19:50 by ssachet           #+#    #+#             */
/*   Updated: 2015/01/07 10:33:53 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	int		nc;
	size_t	len;
	char	sign;

	sign = (n < 0) ? -1 : 1;
	len = 2 + (n < 0);
	nc = n;
	while ((n = n / 10))
		len++;
	n = nc;
	if (NULL == (str = (char *)malloc(len--)))
		return (NULL);
	str[len--] = '\0';
	str[len--] = sign * (n % 10) + '0';
	while ((n = n / 10))
		str[len--] = sign * (n % 10) + '0';
	if (sign < 0)
		str[len] = '-';
	return (str);
}
