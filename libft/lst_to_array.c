/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_to_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 05:50:14 by ssachet           #+#    #+#             */
/*   Updated: 2015/02/20 12:30:39 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**lst_to_array(t_list *lst)
{
	char	**array;
	int		len;
	int		i;
	int		varlen;

	if (lst == NULL)
		return (NULL);
	i = 0;
	len = ft_lstlen(lst);
	array = malloc(sizeof(char *) * (len + 1));
	while (i < len)
	{
		varlen = LEN(lst->name) + LEN(lst->value) + 2;
		array[i] = (char *)malloc(varlen);
		ft_strcpy(array[i], lst->name);
		ft_strcat(array[i], "=");
		ft_strcat(array[i], lst->value);
		lst = lst->next;
		i++;
	}
	array[i] = '\0';
	return (array);
}
