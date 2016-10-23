/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 08:59:29 by ssachet           #+#    #+#             */
/*   Updated: 2015/01/22 20:05:51 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			numeric_conversion(t_a *flag)
{
	if ((flag->type == 'd') ||
			(flag->type == 'i') ||
			(flag->type == 'D') ||
			(flag->type == 'p') ||
			(flag->type == 'U') ||
			(flag->type == 'u'))
		return (1);
	return (0);
}

int			pointer_conversion(t_a *flag)
{
	if ((flag->type == 'p'))
		return (1);
	return (0);
}

int			char_conversion(t_a *flag)
{
	if ((flag->type == 'c') ||
			(flag->type == 'C'))
		return (1);
	return (0);
}

int			hexa_conversion(t_a *flag)
{
	if ((flag->type == 'x') ||
			(flag->type == 'X'))
		return (1);
	return (0);
}

int			string_conversion(t_a *flag)
{
	if ((flag->type == 's') ||
			(flag->type == 'S'))
		return (1);
	return (0);
}
