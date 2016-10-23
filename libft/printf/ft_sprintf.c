/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 01:54:42 by ssachet           #+#    #+#             */
/*   Updated: 2015/01/31 19:35:04 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		sprint_arg(char **str, va_list argp, char **variable)
{
	void	*myarg;
	t_a		*flag;
	int		rd;

	flag = new_a();
	add_format(str, flag);
	if (**str == '\0')
		return (0);
	add_type(str, flag);
	add_ext_width(argp, flag);
	myarg = cast_to_str(argp, flag);
	if (flag->quit_error)
		return (-1);
	if (flag->type == 0)
		myarg = char_to_str(**str);
	else if (myarg == NULL)
		myarg = makestr("(null)");
	myarg = apply_all(myarg, flag);
	*variable = ft_strjoin(*variable, myarg);
	rd = (int)ft_strlen(myarg);
	if (char_conversion(flag) && (flag->zero))
		rd++;
	return (rd);
}

int		call_to_sprint_arg(char **string, va_list argp, int i, char **variable)
{
	int	j;

	j = 0;
	if ((**string == '%') && (*(*string + 1) == '%'))
	{
		*variable = ft_strjoin(*variable, "%");
		(*string)++;
	}
	else if (**string == '\\')
	{
		sprint_escape(string, *variable);
	}
	else if (**string != '%')
		*variable = ft_strjoin(*variable, char_to_str(**string));
	else
	{
		(*string)++;
		if ((j = sprint_arg(string, argp, variable)) == -1)
			return (-1);
		i = i + j - 1;
	}
	i++;
	if (**string)
		(*string)++;
	return (i);
}

int		ft_sprintf(char **variable, char *string, ...)
{
	va_list		argp;
	t_colors	*color;
	int			i;

	i = 0;
	color = load_colors();
	*variable = makestr("");
	va_start(argp, string);
	while (*string)
	{
		apply_colors(&string, color, variable);
		if ((i = call_to_sprint_arg(&string, argp, i, variable)) == -1)
			return (-1);
	}
	return (i);
}
