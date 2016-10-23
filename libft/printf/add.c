/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 08:57:18 by ssachet           #+#    #+#             */
/*   Updated: 2015/02/20 17:24:56 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*add_sign(void *myarg, t_a *flag)
{
	if (*(char *)myarg == '-' && !char_conversion(flag)
								&& !string_conversion(flag))
	{
		flag->sign = '-';
		flag->sign_pad = '-';
		myarg = ft_strsub(myarg, 1, ft_strlen(myarg + 1));
	}
	else
		flag->sign = '+';
	return (myarg);
}

int			add_type(char **str, t_a *flag)
{
	if (is_type(**str))
	{
		flag->type = **str;
		return (0);
	}
	return (-1);
}

void		add_ext_width(va_list argp, t_a *flag)
{
	int ext_width;

	if (flag->ext_width)
	{
		ext_width = va_arg(argp, int);
		flag->width = (flag->width == 0) ? ext_width : flag->width;
		if (flag->width < 0)
		{
			flag->width = flag->width * -1;
			flag->pad = 'r';
		}
	}
}

t_colors	*load_colors(void)
{
	t_colors *color;

	color = (t_colors*)malloc(sizeof(t_colors) * 9);
	ft_strcpy((color[0]).name, "eoc");
	ft_strcpy((color[0]).code, "\033[39m");
	ft_strcpy((color[1]).name, "black");
	ft_strcpy((color[1]).code, "\033[30m");
	ft_strcpy((color[2]).name, "red");
	ft_strcpy((color[2]).code, "\033[91m");
	ft_strcpy((color[3]).name, "yellow");
	ft_strcpy((color[3]).code, "\033[33m");
	ft_strcpy((color[4]).name, "underlined");
	ft_strcpy((color[4]).code, "\033[4m");
	ft_strcpy((color[5]).name, "yellowback");
	ft_strcpy((color[5]).code, "\033[43m");
	ft_strcpy((color[6]).name, "eou");
	ft_strcpy((color[6]).code, "\033[24m");
	ft_strcpy((color[7]).name, "lightred");
	ft_strcpy((color[7]).code, "\033[91m");
	ft_strcpy((color[8]).name, "blue");
	ft_strcpy((color[8]).code, "\033[34m");
	return (color);
}

void		apply_colors(char **string, t_colors *color, char **variable)
{
	int		i;
	char	*code;

	i = 0;
	if ((**string == '[') && char_index(*string, ']'))
	{
		while (i < 9)
		{
			if (ft_strnequ(*string + 1, (color[i]).name,
						char_index(*string, ']') - 1))
			{
				code = ((color[i]).code);
				if (variable != NULL)
					*variable = ft_strjoin(*variable, code);
				else
					ft_putstr(code);
				*string = *string + char_index(*string, ']') + 1;
			}
			i++;
		}
	}
}
