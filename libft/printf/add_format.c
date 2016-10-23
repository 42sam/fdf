/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 08:43:51 by ssachet           #+#    #+#             */
/*   Updated: 2015/01/22 20:05:50 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_format(char **str, t_a *flag)
{
	while (is_valid(**str) && !is_type(**str))
	{
		if (is_flag(**str))
			add_flags(str, flag);
		if (ft_isdigit(**str))
			add_width(str, flag);
		if (is__dot(**str))
			add_precision(str, flag);
		if (is_l_modifier(**str))
			add_l_modifiers(str, flag);
	}
}

t_a		*add_flags(char **str, t_a *flag)
{
	while (is_flag(**str))
	{
		if ((**str == ' ') && (flag->sign_pad != '+'))
			flag->sign_pad = (' ');
		else if ((**str == '0') && (flag->pad != 'r'))
		{
			flag->pad = 'l';
			flag->padchar = '0';
		}
		else if (**str == '#')
			flag->longhexaformat = 1;
		else if (**str == '-')
		{
			flag->pad = 'r';
			flag->padchar = ' ';
		}
		else if (**str == '+')
			flag->sign_pad = '+';
		else if (**str == 'F')
			flag->fd = 1;
		else if (**str == '*')
			flag->ext_width = 1;
		(*str)++;
	}
	return (flag);
}

int		add_width(char **str, t_a *flag)
{
	if (ft_isdigit(**str))
		flag->width = precision_atoi(*str);
	while (ft_isdigit(**str))
		(*str)++;
	return (0);
}

int		add_precision(char **str, t_a *flag)
{
	if (**str == '.')
	{
		flag->precision = 0;
		(*str)++;
		if (ft_isdigit(**str))
			flag->precision = precision_atoi(*str);
		while (ft_isdigit(**str))
			(*str)++;
	}
	return (0);
}

int		add_l_modifiers(char **str, t_a *flag)
{
	while (is_l_modifier(**str))
	{
		if ((**str == 'h') && ((*(*str + 1)) == 'h') && (flag->l_modifier == 0))
		{
			(*str)++;
			flag->l_modifier = 'H';
		}
		else if ((**str == 'l') && ((*(*str + 1)) == 'l'))
		{
			(*str)++;
			flag->l_modifier = 'L';
		}
		else if ((**str == 'h') && (flag->l_modifier != 0))
			;
		else
			flag->l_modifier = **str;
		(*str)++;
	}
	return (0);
}
