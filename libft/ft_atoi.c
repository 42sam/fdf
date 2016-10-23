/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 14:27:30 by ssachet           #+#    #+#             */
/*   Updated: 2014/11/19 01:12:30 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_atoi(const char *str)
{
	int			nb;
	const char	*p;
	int			minus;

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
