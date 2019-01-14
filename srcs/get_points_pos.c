/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_points_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:30:55 by gfranco           #+#    #+#             */
/*   Updated: 2019/01/14 16:28:20 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	next_y(t_m *m)
{
	m->x2 = m->xout + m->i * m->gap;
	m->y2 = m->yout + m->j * m->gap;
	m->z = m->array[m->j][m->i] * m->relief;
	rotate(m);
	m->x2 += m->xlen;
	m->y2 += m->ylen;
}

int		***make_tab(t_m m)
{
	m.j = 0;
	if (!(m.tab = (int***)malloc(sizeof(int**) * m.line)))
		exit(0);
	while (m.line-- > 0)
	{
		if (!(m.tab[m.j] = (int**)malloc(sizeof(int*) * 2)))
			exit(0);
		if (!(m.tab[m.j][0] = (int*)malloc(sizeof(int) * m.column)))
			exit(0);
		if (!(m.tab[m.j][1] = (int*)malloc(sizeof(int) * m.column)))
			exit(0);
		m.j++;
	}
	return (m.tab);
}

void	give_value(t_m *m)
{
	m->i = 0;
	m->j++;
	m->z = m->array[m->j][m->i] * m->relief;
	m->x2 = m->xout;
	m->y2 = (m->yout + m->j * m->gap);
	rotate(m);
	m->x2 += m->xlen;
	m->y2 += m->ylen;
}

int		***fill_tab(t_m m)
{
	init_rot(&m);
	if (m.tab == NULL)
		m.tab = make_tab(m);
	m.tab[m.j][0][m.i] = m.x1;
	m.tab[m.j][1][m.i] = m.y1;
	while (++m.i < m.column - 1 || m.j < m.line - 1)
	{
		next_y(&m);
		m.tab[m.j][0][m.i] = m.x2;
		m.tab[m.j][1][m.i] = m.y2;
		if (m.i == m.column - 1 && m.j != m.line - 1)
		{
			give_value(&m);
			m.tab[m.j][0][m.i] = m.x2;
			m.tab[m.j][1][m.i] = m.y2;
		}
	}
	if (m.i == m.column - 1 && m.j == m.line - 1)
	{
		next_y(&m);
		m.tab[m.j][0][m.i] = m.x2;
		m.tab[m.j][1][m.i] = m.y2;
	}
	return (m.tab);
}
