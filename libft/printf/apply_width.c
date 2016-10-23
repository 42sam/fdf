/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 08:53:51 by ssachet           #+#    #+#             */
/*   Updated: 2015/01/22 20:05:51 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*apply_right_width(void *myarg, t_a *flag, int width)
{
	if (width <= (int)ft_strlen(myarg))
	{
		if (pointer_conversion(flag))
		{
			myarg = ft_strjoin("0x", myarg);
			width += 2;
		}
		return (myarg);
	}
	if (!char_conversion(flag) && (flag->precision == 0))
		flag->padchar = ' ';
	if (char_conversion(flag) && flag->zero)
		width++;
	if (numeric_conversion(flag) && flag->sign_pad)
		width--;
	if (pointer_conversion(flag))
	{
		myarg = ft_strjoin("0x", myarg);
		width += 2;
	}
	return (pad_right(myarg, flag->padchar, width));
}

void	*apply_left_width(void *myarg, t_a *flag, int width)
{
	if (width <= (int)ft_strlen(myarg))
	{
		if (pointer_conversion(flag))
			myarg = ft_strjoin("0x", myarg);
		return (myarg);
	}
	if (char_conversion(flag))
		return (apply_left_width_char(myarg, flag, width));
	if (flag->precision == 0
		&& !no_conversion(flag)
		&& !string_conversion(flag))
		flag->padchar = ' ';
	if (no_conversion(flag)
		|| octal_conversion(flag)
		|| string_conversion(flag))
		return (apply_left_width_simple(myarg, flag, width));
	if (pointer_conversion(flag))
		return (apply_left_width_pointer(myarg, flag, width));
	if (hexa_conversion(flag))
		return (apply_left_width_hexa(myarg, flag, width));
	if (numeric_conversion(flag))
		return (apply_left_width_numeric(myarg, flag, width));
	return (myarg);
}

void	*apply_width(void *myarg, t_a *flag)
{
	int width;

	width = flag->width;
	if (!is_type(flag->type) && ((flag->width) == 1))
		flag->width = 0;
	if (flag->pad == 'r')
		return (myarg = apply_right_width(myarg, flag, width));
	else if (flag->pad == 'l')
		return (myarg = apply_left_width(myarg, flag, width));
	return (myarg);
}
