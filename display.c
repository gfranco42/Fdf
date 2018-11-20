/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 16:14:31 by gfranco           #+#    #+#             */
/*   Updated: 2018/11/20 17:58:24 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		xincr(t_tool *t, t_tri v, int *x2, int *y2)
{
	*x2 = t->xinit + (v.i + 1) * t->gap;
	*y2 = t->yinit + v.j * t->gap;
}

void		yincr(t_tool *t, t_tri v, int *x2, int *y2)
{
	*x2 = t->xinit + v.i * t->gap;
	*y2 = t->yinit + (v.j - 1) * t->gap;
}

void		move(t_trace s, int *x1, int *y1)
{
	*x1 = s.x2;
	*y1 = s.y2;
}

void		draw(t_tool *t, t_tri v, t_trace s)
{
	v.i = 0;
	v.j = 0;
	while (v.i < t->column - 1 || v.j < t->line - 1)
	{
		if (v.j != 0)
		{
			yincr(t, v, &s.x2, &s.y2);
			trace(t, s, DGREEN);
		}
		xincr(t, v, &s.x2, &s.y2);
		trace(t, s, DBLUE);
		move(s, &s.x1, &s.y1);
		v.i++;
		if (v.i == t->column - 1 && v.j != 0)
		{
			yincr(t, v, &s.x2, &s.y2);
			trace(t, s, DGREEN);
		}
		if (v.i == t->column - 1 && v.j != t->line - 1)
		{
			v.j++;
			v.i = 0;
			s.x1 = t->xinit;
			s.y1 = t->yinit + v.j * t->gap;
		}
	}
}
