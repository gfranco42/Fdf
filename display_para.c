/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_para.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:29:39 by gfranco           #+#    #+#             */
/*   Updated: 2018/11/29 17:51:28 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		xincr(t_m *m, int *x2, int *y2)
{
	(void)x2;
	(void)y2;
	m->x2 = m->xinit + (m->i + 1) * m->gap;
	m->y2 = m->yinit + m->j * m->gap;
}

void		yincr(t_m *m, int *x2, int *y2)
{
	(void)x2;
	(void)y2;
	m->x2 = m->xinit + m->i * m->gap;
	m->y2 = m->yinit + (m->j - 1) * m->gap;
}

void		next(t_m *m)
{
	m->x1 = m->x2;
	m->y1 = m->y2;
}

void		init_variable(t_m *m)
{
	m->xinit = WIDTH / 2 - (m->column * m->gap) / 2;
	m->yinit = HEIGHT / 2 - (m->line * m->gap) / 2;
	m->x1 = m->xinit;
	m->y1 = m->yinit;
}

void		draw(t_m m)
{
	m.i = 0;
	m.j = 0;
	while (m.i < m.column - 1 || m.j < m.line - 1)
	{
		if (m.j != 0)
		{
			yincr(&m, &(m.x2), &(m.y2));
			trace(m);
		}
		xincr(&m, &(m.x2), &(m.y2));
		trace(m);
		next(&m);
		m.i++;
		if (m.i == m.column - 1 && m.j != 0)
		{
			yincr(&m, &(m.x2), &(m.y2));
			trace(m);
		}
		if (m.i == m.column - 1 && m.j != m.line - 1)
		{
			m.j++;
			m.i = 0;
			m.x1 = m.xinit;
			m.y1 = m.yinit + m.j * m.gap;
		}
	}
}
