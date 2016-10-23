/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makestr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 18:57:53 by ssachet           #+#    #+#             */
/*   Updated: 2015/01/07 10:33:56 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *makestr(char *str)
{
	char	*newstr;

	if (NULL == (newstr = ft_strnew(ft_strlen(str))))
		return (NULL);
	newstr = ft_strcpy(newstr, str);
	return (newstr);
}
