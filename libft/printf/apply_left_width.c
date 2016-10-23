/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_left_width.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 08:52:20 by ssachet           #+#    #+#             */
/*   Updated: 2015/01/22 20:05:51 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*apply_left_width_char(void *myarg, t_a *flag, int width)
{
	if (flag->zero)
		width--;
	return (pad_left(myarg, flag->padchar, width));
}

void	*apply_left_width_simple(void *myarg, t_a *flag, int width)
{
	return (pad_left(myarg, flag->padchar, width));
}

void	*apply_left_width_hexa(void *myarg, t_a *flag, int width)
{
	if ((flag->padchar == '0') && (flag->precision == -1))
		return (pad_left(myarg, flag->padchar, width));
	else
		return (pad_left(myarg, ' ', width));
}

void	*apply_left_width_pointer(void *myarg, t_a *flag, int width)
{
	if ((flag->padchar == '0') && (flag->precision == -1))
	{
		myarg = pad_left(myarg, flag->padchar, width);
		myarg = ft_strjoin("0x", myarg);
		width += 2;
	}
	else
	{
		myarg = ft_strjoin("0x", myarg);
		width += 2;
		myarg = pad_left(myarg, flag->padchar, width);
	}
	return (myarg);
}

void	*apply_left_width_numeric(void *myarg, t_a *flag, int width)
{
	width = (flag->sign_pad) ? (flag->width) - 1 : flag->width;
	if ((flag->padchar == '0') && (flag->precision == -1))
	{
		myarg = pad_left(myarg, flag->padchar, width);
		if (flag->type != 'U')
		{
			myarg = apply_sign(myarg, flag);
			flag->sign_put = 1;
		}
	}
	else
	{
		if (flag->type != 'U')
		{
			if (flag->sign_pad)
				width++;
			myarg = apply_sign(myarg, flag);
			flag->sign_put = 1;
			myarg = pad_left(myarg, ' ', width);
		}
		myarg = pad_left(myarg, ' ', width);
	}
	return (myarg);
}
