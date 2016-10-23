/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_dict.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 05:12:12 by ssachet           #+#    #+#             */
/*   Updated: 2015/02/20 12:30:39 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*new_dict(char *name, char *value, t_list *next)
{
	t_list	*env;

	env = (t_list*)malloc(sizeof(t_list));
	if (name)
		env->name = makestr(name);
	else
		env->name = NULL;
	if (value)
		env->value = makestr(value);
	else
		env->value = NULL;
	if (value)
		env->next = next;
	else
		env->next = NULL;
	return (env);
}
