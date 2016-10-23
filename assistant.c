/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assistant.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 20:51:06 by ssachet           #+#    #+#             */
/*   Updated: 2015/02/22 11:59:36 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			**str_array_to_int_array(char **str, t_env *e)
{
	int		i;
	int		**iarray;

	i = 0;
	if ((iarray = (int **)malloc(sizeof(int *) * tablen(str))) == NULL)
		return (NULL);
	while (str[i])
	{
		if ((iarray[i] = (int *)malloc(sizeof(int))) == NULL)
			return (NULL);
		*iarray[i] = ft_atoi(str[i]);
		if (*iarray[i] < e->mnb)
			e->mnb = *iarray[i];
		if (*iarray[i] > e->mxb)
			e->mxb = *iarray[i];
		i++;
	}
	return (iarray);
}

void		print_map(t_line *matrix)
{
	int		i;

	while (matrix)
	{
		i = 0;
		while (i < matrix->len)
		{
			ft_printf(ft_itoa((*matrix->line[i])));
			i++;
		}
		C('\n');
		matrix = matrix->next;
	}
}

int			lstlen(t_line *lst)
{
	int		len;

	if (!lst)
		return (-1);
	len = 0;
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}

t_line		*one_line(char *str_line, t_env *e)
{
	t_line	*line;
	char	**int_line;

	if ((line = (t_line *)malloc(sizeof(t_line))) == NULL)
		return (NULL);
	line->next = NULL;
	int_line = ft_strsplit(str_line, ' ');
	if ((line->line = str_array_to_int_array(int_line, e)) == NULL)
		return (NULL);
	if ((line->len = tablen(int_line)) > e->max_x)
		e->max_x = line->len;
	return (line);
}

void		tracing_improvement(t_bres *b, t_pix *pix)
{
	b->e2 = b->err;
	if (b->e2 > -(b->dx))
	{
		b->err -= b->dy;
		pix->x0 += b->sx;
	}
	if (b->e2 < b->dy)
	{
		b->err += b->dx;
		pix->y0 += b->sy;
	}
}
