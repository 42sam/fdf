/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 08:56:57 by ssachet           #+#    #+#             */
/*   Updated: 2015/01/22 20:05:50 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*apply_precision_hexa(void *myarg, t_a *flag, int strlen, int precision)
{
	if (!(precision) && (flag->zero))
		myarg = makestr("");
	if (precision > strlen)
		myarg = pad_left(myarg, '0', precision);
	return (myarg);
}

void	*apply_precision_string(void *myarg, int strlen, int precision)
{
	if (!precision)
		myarg = makestr("");
	else if ((precision < strlen) && (precision > 0))
		myarg = ft_strsub(myarg, 0, precision);
	return (myarg);
}

void	*apply_precision(void *myarg, t_a *flag)
{
	int precision;
	int strlen;

	strlen = (int)ft_strlen(myarg);
	precision = flag->precision;
	if (numeric_conversion(flag) || octal_conversion(flag))
	{
		if (pointer_conversion(flag) && !(precision) && (ft_atos(myarg) == 0))
			return (makestr(""));
		else if (!precision && (ft_atos(myarg) == 0))
			myarg = makestr("");
		else if (precision > strlen)
		{
			myarg = pad_left(myarg, '0', precision);
		}
	}
	if (hexa_conversion(flag))
		return (apply_precision_hexa(myarg, flag, strlen, precision));
	if (string_conversion(flag))
		return (apply_precision_string(myarg, strlen, precision));
	return (myarg);
}

void	*apply_zerox(void *myarg, t_a *flag)
{
	if (flag->longhexaformat && hexa_conversion(flag))
		if (!flag->zero)
			myarg = ft_strjoin("0x", myarg);
	if (flag->longhexaformat && octal_conversion(flag) && flag->zero)
		myarg = makestr("0");
	if (flag->type == 'X')
		myarg = ft_uppercase(myarg);
	return (myarg);
}

void	*apply_sign(void *myarg, t_a *flag)
{
	if (numeric_conversion(flag))
		if ((flag->sign_pad) && !(flag->sign_put))
			if ((!octal_conversion(flag)) ||
					(flag->sign_pad == '0') || flag->zero)
				if ((flag->type != 'u') && !pointer_conversion(flag))
					myarg = pad_left(myarg, flag->sign_pad,
							ft_strlen(myarg) + 1);
	return (myarg);
}
