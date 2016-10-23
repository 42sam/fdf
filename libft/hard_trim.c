/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_trim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 06:29:09 by ssachet           #+#    #+#             */
/*   Updated: 2015/02/20 12:30:38 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		find_start(char *s, int i, int *trimlen, char c)
{
	while (s[i])
	{
		if (s[i] != c)
			trimlen++;
		i++;
	}
}

static void		set_values(int *i, int *j, int *k, int *trimlen)
{
	*i = 0;
	*j = 0;
	*k = 0;
	*trimlen = 0;
}

char			*hard_trim(char *s, char c)
{
	char	*trim;
	int		i;
	int		k;
	int		j;
	int		trimlen;

	set_values(&i, &j, &k, &trimlen);
	if (!s)
		return (NULL);
	while (s[k] == c)
		k++;
	i = k;
	find_start(s, i, &trimlen, c);
	if (NULL == (trim = (char *)malloc(trimlen + 1)))
		return (NULL);
	while (s[k])
	{
		if (s[k] != c)
			trim[j++] = s[k];
		k++;
	}
	trim[j] = '\0';
	return (trim);
}
