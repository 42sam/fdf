/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 19:11:38 by ssachet           #+#    #+#             */
/*   Updated: 2015/01/07 10:33:52 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*case_down(char *str)
{
	char	c;
	char	*s2;

	s2 = str;
	while (*str)
	{
		c = *str;
		if (is_uppercase(c))
			*str = *str - 'A' + 'a';
		str++;
	}
	return (s2);
}
