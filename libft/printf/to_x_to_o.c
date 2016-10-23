/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_x_to_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 09:08:05 by ssachet           #+#    #+#             */
/*   Updated: 2015/01/22 20:05:51 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		load_ltox(size_t rem)
{
	if (rem == 10)
		return ('a');
	else if (rem == 11)
		return ('b');
	else if (rem == 12)
		return ('c');
	else if (rem == 13)
		return ('d');
	else if (rem == 14)
		return ('e');
	else if (rem == 15)
		return ('f');
	else
		return (rem + '0');
}

char	*ft_ltox(size_t n)
{
	size_t	i;
	size_t	rem;
	char	*hex;

	i = 0;
	hex = (char *)malloc(256);
	while (n != 0)
	{
		rem = n % 16;
		hex[i] = load_ltox(rem);
		++i;
		n /= 16;
	}
	hex[i] = 0;
	return (ft_strrev(hex));
}

size_t	ft_stoo(size_t n)
{
	size_t rem;
	size_t i;
	size_t octal;

	octal = 0;
	i = 1;
	while (n)
	{
		rem = n % 8;
		n /= 8;
		octal += rem * i;
		i *= 10;
	}
	return (octal);
}

char	*load_digits(void)
{
	char	base_digits[16];

	base_digits[0] = '0';
	base_digits[1] = '1';
	base_digits[2] = '2';
	base_digits[3] = '3';
	base_digits[4] = '4';
	base_digits[5] = '5';
	base_digits[6] = '6';
	base_digits[7] = '7';
	base_digits[8] = '8';
	base_digits[9] = '9';
	base_digits[10] = 'A';
	base_digits[11] = 'B';
	base_digits[12] = 'C';
	base_digits[13] = 'D';
	base_digits[14] = 'E';
	base_digits[15] = 'F';
	return (ft_strdup(base_digits));
}

char	*ft_stoo2(size_t number_to_convert, int base)
{
	int		converted_number[64];
	int		index;
	char	str[90];
	char	*base_digits;
	char	*str2;

	index = 0;
	base_digits = load_digits();
	while (number_to_convert)
	{
		converted_number[index] = number_to_convert % base;
		number_to_convert = number_to_convert / base;
		++index;
	}
	str[index] = '\0';
	--index;
	while (index >= 0)
	{
		str[index] = base_digits[converted_number[index]];
		index--;
	}
	str2 = ft_strdup(ft_strrev(str));
	return (str2);
}
