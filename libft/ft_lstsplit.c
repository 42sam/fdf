/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 18:11:25 by ssachet           #+#    #+#             */
/*   Updated: 2015/01/07 10:33:54 by ssachet          ###   ########.fr       */
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

static char		*ft_lstsplit2(t_list **head, t_list **previous, char *word)
{
	if (*head == NULL)
	{
		if (NULL == ((*head) = ft_lstnew(word, ft_strlen(word))))
			return (NULL);
		*previous = *head;
	}
	else
	{
		if (NULL == ((*previous)->next = ft_lstnew(word, ft_strlen(word))))
			return (NULL);
		*previous = (*previous)->next;
	}
	return (word);
}

t_list			*ft_lstsplit(char const *s, char c)
{
	int		i;
	char	*word;
	t_list	*head;
	t_list	*previous;
	int		wrdlen;

	head = NULL;
	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if ((s[i] != c && i == 0) || (s[i] != c && ((s - 1)[i]) == c))
		{
			wrdlen = wordlen((char *)&s[i], c);
			word = ft_strsub(s + i, 0, wrdlen);
			if (NULL == (ft_lstsplit2(&head, &previous, word)))
				return (NULL);
		}
		i++;
	}
	previous->next = NULL;
	return (head);
}
