/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_to_wc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 09:19:55 by ssachet           #+#    #+#             */
/*   Updated: 2015/01/22 20:05:51 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	utf_21_bits(wchar_t c, char **b)
{
	**b = (unsigned char)(((c >> 18)) | 0xF0);
	(*b)++;
	**b = (unsigned char)(((c >> 12) & 0x3F) | 0x80);
	(*b)++;
	**b = (unsigned char)(((c >> 6) & 0x3F) | 0x80);
	(*b)++;
	**b = (unsigned char)((c & 0x3F) | 0x80);
	(*b)++;
}

void	wc_conversion(wchar_t c, char **b)
{
	if (c < (1 << 7))
	{
		**b = (unsigned char)(c);
		(*b)++;
	}
	else if (c < (1 << 11))
	{
		**b = (unsigned char)((c >> 6) | 0xC0);
		(*b)++;
		**b = (unsigned char)((c & 0x3F) | 0x80);
		(*b)++;
	}
	else if (c < (1 << 16))
	{
		**b = (unsigned char)(((c >> 12)) | 0xE0);
		(*b)++;
		**b = (unsigned char)(((c >> 6) & 0x3F) | 0x80);
		(*b)++;
		**b = (unsigned char)((c & 0x3F) | 0x80);
		(*b)++;
	}
	else if (c < (1 << 21))
		utf_21_bits(c, b);
	**b = '\0';
}

char	*cast_to_wc(va_list argp, t_a *flag)
{
	char	wchar[5];
	char	*b;
	char	*str;
	wchar_t c;

	b = wchar;
	c = va_arg(argp, wchar_t);
	wc_conversion(c, &b);
	str = ft_strdup(wchar);
	if (*str == 0)
	{
		str = makestr("");
		flag->zero = 1;
	}
	return (str);
}

char	*cast_to_ws(va_list argp, t_a *flag)
{
	char	wchar[890];
	char	*b;
	char	*str;
	wchar_t *s;
	int		i;

	s = va_arg(argp, wchar_t*);
	if (!s)
		return (NULL);
	i = 0;
	b = wchar;
	while (s[i])
	{
		wc_conversion(s[i], &b);
		i++;
	}
	*b = '\0';
	str = ft_strdup(wchar);
	return (str);
}

char	*cast_to_c(va_list argp, t_a *flag)
{
	char	*str;
	size_t	x;

	if (flag->l_modifier == 'l')
		str = cast_to_wc(argp, flag);
	else
	{
		x = (char)va_arg(argp, int);
		str = char_to_str(x);
	}
	if (*str == 0)
	{
		str = makestr("");
		flag->zero = 1;
	}
	return (str);
}
