/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 01:54:42 by ssachet           #+#    #+#             */
/*   Updated: 2015/01/31 17:41:13 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*apply_all(void *myarg, t_a *flag)
{
	if (is_type(flag->type))
	{
		myarg = add_sign(myarg, flag);
		myarg = apply_precision(myarg, flag);
		myarg = apply_zerox(myarg, flag);
	}
	myarg = apply_width(myarg, flag);
	if (is_type(flag->type))
		myarg = apply_sign(myarg, flag);
	return (myarg);
}

int		print_arg(char **str, va_list argp)
{
	void	*myarg;
	t_a		*flag;
	int		fd;
	int		rd;

	flag = new_a();
	add_format(str, flag);
	if (**str == '\0')
		return (0);
	add_type(str, flag);
	fd = (flag->fd) ? va_arg(argp, int) : 1;
	add_ext_width(argp, flag);
	myarg = cast_to_str(argp, flag);
	if (flag->quit_error)
		return (-1);
	if (flag->type == 0)
		myarg = char_to_str(**str);
	else if (myarg == NULL)
		myarg = makestr("(null)");
	myarg = apply_all(myarg, flag);
	ft_putstr_fd(myarg, fd);
	rd = (int)ft_strlen(myarg);
	if (char_conversion(flag) && (flag->zero))
		rd++;
	return (rd);
}

int		call_to_print_arg(char **string, va_list argp, int i)
{
	int	j;

	j = 0;
	if ((**string == '%') && (*(*string + 1) == '%'))
	{
		ft_putchar('%');
		(*string)++;
	}
	else if (**string == '\\')
	{
		print_escape(string);
	}
	else if (**string != '%')
		ft_putchar(**string);
	else
	{
		(*string)++;
		if ((j = print_arg(string, argp)) == -1)
			return (-1);
		i = i + j - 1;
	}
	i++;
	if (**string)
		(*string)++;
	return (i);
}

int		ft_printf(char *string, ...)
{
	va_list		argp;
	t_colors	*color;
	int			i;

	i = 0;
	color = load_colors();
	va_start(argp, string);
	while (*string)
	{
		apply_colors(&string, color, NULL);
		if ((i = call_to_print_arg(&string, argp, i)) == -1)
			return (-1);
	}
	return (i);
}
