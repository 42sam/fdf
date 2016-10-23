/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_s_a_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 09:10:11 by ssachet           #+#    #+#             */
/*   Updated: 2015/02/16 03:26:10 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		precision_atoi(const char *str)
{
	int			nb;
	const char	*p;
	int			minus;

	minus = 0;
	while (*str == ' ' || *str == '0')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			minus = 1;
	}
	p = str;
	nb = 0;
	while ((*p >= '0') && (*p <= '9'))
	{
		nb = nb * 10 + (*p - '0');
		p++;
	}
	nb = (minus) ? nb * -1 : nb;
	return (nb);
}

size_t	ft_atos(const char *str)
{
	size_t		nb;
	const char	*p;
	size_t		minus;

	minus = 0;
	while (*str == '\n' || *str == '\f' || *str == '\v' ||
			*str == '\r' || *str == '\t' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			minus = 1;
	}
	p = str;
	nb = 0;
	while ((*p >= '0') && (*p <= '9'))
	{
		nb = nb * 10 + (*p - '0');
		p++;
	}
	nb = (minus) ? nb * -1 : nb;
	return (nb);
}

char	*ft_stoa(size_t n)
{
	char	*str;
	size_t	nc;
	size_t	len;
	char	sign;

	sign = 1;
	len = 2;
	nc = n;
	while ((n = n / (size_t)10))
		len++;
	n = nc;
	if (NULL == (str = (char *)malloc(len--)))
		return (NULL);
	str[len--] = '\0';
	str[len--] = sign * (n % (size_t)10) + '0';
	while ((n = n / (size_t)10))
		str[len--] = sign * (n % (size_t)10) + '0';
	if (sign < 0)
		str[len] = '-';
	return (str);
}
