/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 21:19:24 by ssachet           #+#    #+#             */
/*   Updated: 2015/01/23 07:35:30 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		wordlen(char *s, int c)
{
	int i;

	i = 0;
	while (s[i] && (s[i] != c))
		i++;
	return (i);
}

static int		wordcount(char *s, int c)
{
	int i;
	int cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if ((s[i] != c && i == 0) || (s[i] != c && (s[i - 1]) == c))
			cnt++;
		i++;
	}
	return (cnt);
}

char			**ft_strsplit(char const *s, char c)
{
	int		words;
	int		i;
	char	**split;
	int		j;
	int		wrdlen;

	if (!s)
		return (NULL);
	words = wordcount((char *)s, c);
	if (NULL == (split = (char **)malloc((sizeof(char *) * words) + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if ((s[i] != c && i == 0) || (s[i] != c && (s[i - 1]) == c))
		{
			wrdlen = wordlen((char *)&s[i], c);
			if (NULL == (split[j++] = ft_strsub(s + i, 0, wrdlen)))
				return (NULL);
		}
		i++;
	}
	split[j] = '\0';
	return (split);
}
