/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/08 10:53:44 by ssachet           #+#    #+#             */
/*   Updated: 2015/02/22 11:59:37 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		iso_x(int y, int x, t_env *e)
{
	x = e->f1 * x - e->f2 * y;
	return (x);
}

int		iso_y(int y, int x, int z, t_env *e)
{
	y = z + (e->f1 / 2) * x + (e->f2 / 2) * y;
	return (y);
}

t_bres	*new_bres(int x0, int x1, int y0, int y1)
{
	t_bres	*b;

	if ((b = (t_bres *)malloc(sizeof(t_bres))) == NULL)
		return (NULL);
	b->dx = abs(x1 - x0);
	b->sx = x0 < x1 ? 1 : -1;
	b->dy = abs(y1 - y0);
	b->sy = y0 < y1 ? 1 : -1;
	b->err = (b->dx > b->dy ? b->dx : -(b->dy)) / 2;
	b->e2 = 0;
	return (b);
}
