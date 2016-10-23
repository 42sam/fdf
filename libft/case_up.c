/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 19:11:19 by ssachet           #+#    #+#             */
/*   Updated: 2015/01/07 10:33:52 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*case_up(char *str)
{
	char c;

	while (*str)
	{
		c = *str;
		if (is_lowercase(c))
		{
			*str = *str - 'a' + 'A';
		}
		ft_putchar(*str);
		str++;
	}
	return (str);
}
