/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 21:18:51 by ssachet           #+#    #+#             */
/*   Updated: 2015/01/07 10:33:56 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*trim;
	int		i;
	int		j;
	int		trimlen;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	j = ft_strlen(s) - 1;
	while ((s[j] == ' ' || s[j] == '\n' || s[j] == '\t'))
		j--;
	if ((trimlen = j - i + 1) < 0)
		trimlen = 0;
	if (NULL == (trim = (char *)malloc(trimlen + 1)))
		return (NULL);
	j = 0;
	while (j < trimlen)
		trim[j++] = s[i++];
	trim[j] = '\0';
	return (trim);
}
