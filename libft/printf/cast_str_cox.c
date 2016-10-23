/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_str_cox.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 09:20:58 by ssachet           #+#    #+#             */
/*   Updated: 2015/01/22 20:05:51 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*cast_to_x(va_list argp, t_a *flag)
{
	char	*str;
	size_t	x;

	if (flag->l_modifier == 'H')
		x = (unsigned char)va_arg(argp, int);
	if (flag->l_modifier == 'h')
		x = (unsigned short)va_arg(argp, int);
	if (flag->l_modifier == 'l')
		x = (unsigned long)va_arg(argp, long);
	if (flag->l_modifier == 'L')
		x = (unsigned long)va_arg(argp, long);
	if (flag->l_modifier == 'j')
		x = va_arg(argp, uintmax_t);
	if (flag->l_modifier == 'z')
		x = va_arg(argp, size_t);
	if (flag->l_modifier == '\0')
		x = va_arg(argp, long);
	if (x == 0)
	{
		flag->zero = 1;
		str = makestr("0");
	}
	else
		str = ft_ltox(x);
	return (str);
}

char	*cast_to_o(va_list argp, t_a *flag)
{
	char	*str;
	size_t	x;

	x = va_arg(argp, size_t);
	if (flag->l_modifier == 'H')
		x = (unsigned char)x;
	if (flag->l_modifier == 'h')
		x = (unsigned short)x;
	if (flag->l_modifier == 'l')
		x = (unsigned long)x;
	if (flag->l_modifier == 'L')
		x = (unsigned long long)x;
	if (flag->l_modifier == 'j')
		x = (uintmax_t)x;
	if (flag->l_modifier == 'z')
		x = (size_t)x;
	if (flag->l_modifier == 0)
		str = ft_stoa(ft_stoo((unsigned int)x));
	else
		str = (x) ? ft_stoo2(x, 8) : makestr("0");
	if (*str == '0')
		flag->zero = 1;
	if (flag->longhexaformat && (*str != '0'))
		str = ft_strjoin("0", str);
	return (str);
}

char	*cast_to_oo(va_list argp, t_a *flag)
{
	char	*str;
	size_t	x;

	x = va_arg(argp, size_t);
	if (x)
		str = ft_stoo2(x, 8);
	else
	{
		str = makestr("0");
		flag->zero = 1;
	}
	if (flag->longhexaformat && (*str != '0'))
		str = ft_strjoin("0", str);
	return (str);
}

char	*cast_to_s(va_list argp, t_a *flag)
{
	char	*str;

	if (flag->l_modifier == 'l')
		str = cast_to_ws(argp, flag);
	else
	{
		str = ft_strdup(va_arg(argp, char *));
	}
	if (NULL == str)
		return (NULL);
	return (str);
}

char	*cast_to_str(va_list argp, t_a *flag)
{
	char	*str;

	str = NULL;
	if (numeric_conversion(flag))
		return (cast_to_numeric(argp, flag, str));
	if ((flag->type == 'x') || (flag->type == 'X'))
		str = cast_to_x(argp, flag);
	if (flag->type == 'o')
		str = cast_to_o(argp, flag);
	if (flag->type == 'O')
		str = cast_to_oo(argp, flag);
	if (flag->type == 'c')
		str = cast_to_c(argp, flag);
	if (flag->type == 's')
		str = cast_to_s(argp, flag);
	if (flag->type == 'C')
		str = cast_to_wc(argp, flag);
	if (flag->type == 'S')
		str = cast_to_ws(argp, flag);
	return (str);
}
