/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_to_numeric.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 09:13:19 by ssachet           #+#    #+#             */
/*   Updated: 2015/01/22 20:05:51 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*cast_to_id(va_list argp, t_a *flag)
{
	char	*str;

	if (flag->l_modifier == 'H')
		str = ft_itoa((char)va_arg(argp, int));
	if (flag->l_modifier == 'h')
		str = ft_itoa((short)va_arg(argp, int));
	if (flag->l_modifier == 'l')
		str = ft_ltoa(va_arg(argp, long));
	if (flag->l_modifier == 'L')
		str = ft_ltoa(va_arg(argp, long));
	if (flag->l_modifier == 'j')
		str = ft_ltoa((intmax_t)va_arg(argp, intmax_t));
	if (flag->l_modifier == 'z')
		str = ft_ltoa(va_arg(argp, size_t));
	if (flag->l_modifier == '\0')
		str = ft_itoa(va_arg(argp, int));
	return (str);
}

char	*cast_to_u(va_list argp, t_a *flag)
{
	char	*str;

	if (flag->l_modifier == 'H')
		str = ft_itoa((unsigned char)va_arg(argp, int));
	if (flag->l_modifier == 'h')
		str = ft_itoa((unsigned short)va_arg(argp, int));
	if (flag->l_modifier == 'l')
		str = ft_ltoa((unsigned long)va_arg(argp, size_t));
	if (flag->l_modifier == 'L')
		str = ft_ltoa((unsigned long)va_arg(argp, long));
	if (flag->l_modifier == 'j')
		str = ft_ltoa(va_arg(argp, uintmax_t));
	if (flag->l_modifier == 'z')
		str = ft_ltoa(va_arg(argp, size_t));
	if (flag->l_modifier == '\0')
		str = ft_ltoa(va_arg(argp, size_t));
	if (*str == '-')
		str = makestr(ft_stoa(ft_atos(str)));
	return (str);
}

char	*cast_to_uu(va_list argp)
{
	char			*str;
	unsigned long	u;

	u = va_arg(argp, size_t);
	str = ft_stoa(u);
	return (str);
}

char	*cast_to_numeric(va_list argp, t_a *flag, char *str)
{
	if ((flag->type == 'd') || (flag->type == 'i'))
		str = cast_to_id(argp, flag);
	if (flag->type == 'u')
		str = cast_to_u(argp, flag);
	if (flag->type == 'U')
		str = cast_to_uu(argp);
	if (flag->type == 'p')
		str = cast_to_p(argp, flag);
	if (flag->type == 'D')
		str = ft_ltoa(va_arg(argp, long));
	return (str);
}

char	*cast_to_p(va_list argp, t_a *flag)
{
	char		*str;
	size_t		j;

	j = va_arg(argp, size_t);
	str = ft_ltox(j);
	if (*str == 0)
		str = makestr("0");
	flag->width = flag->width - 2;
	return (str);
}
