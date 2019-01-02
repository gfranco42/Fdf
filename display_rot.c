/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_rot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:30:55 by gfranco           #+#    #+#             */
/*   Updated: 2019/01/02 16:06:43 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	next_y(t_m *m)
{
	m->x2 = m->xout + m->i * m->gap;
	m->y2 = m->yout + m->j * m->gap;
	m->z = m->array[m->j][m->i] * m->relief;
	m->z = m->z >= MAX_Z ? 1000 : m->z;
	m->z = m->z <= MIN_Z ? -1000 : m->z;
	xrotate(m);
	yrotate(m);
	zrotate(m);
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

int		***fill_tab(t_m m)
{
	init_rot(&m);
	m.tab = make_tab(m);
	m.tab[m.j][0][m.i] = m.x1;
	m.tab[m.j][1][m.i] = m.y1;
	m.i++;
	while (m.i < m.column - 1 || m.j < m.line - 1)
	{
		next_y(&m);
		m.tab[m.j][0][m.i] = m.x2;
		m.tab[m.j][1][m.i] = m.y2;
		if (m.i == m.column - 1 && m.j != m.line - 1)
		{
			m.i = 0;
			m.j++;
			m.z = m.array[m.j][m.i] * m.relief;
			m.z = m.z >= MAX_Z ? 1000 : m.z;
			m.z = m.z <= MIN_Z ? -1000 : m.z;
			m.x2 = m.xout;
			m.y2 = (m.yout + m.j * m.gap);
			xrotate(&m);
			yrotate(&m);
			zrotate(&m);
			m.x2 += m.xlen;
			m.y2 += m.ylen;
			m.tab[m.j][0][m.i] = m.x2;
			m.tab[m.j][1][m.i] = m.y2;
		}
		m.i++;
	}
	if (m.i == m.column - 1 && m.j == m.line - 1)
	{
	//	m.tab[m.j][0][m.i] = next_x(&m);
		next_y(&m);
		m.tab[m.j][0][m.i] = m.x2;
		m.tab[m.j][1][m.i] = m.y2;
	}
	return (m.tab);
}

void	vert_value(t_m *m)
{
	m->x1 = m->tab[m->j][0][m->i];
	m->y1 = m->tab[m->j][1][m->i];
	m->x2 = m->tab[m->j - 1][0][m->i];
	m->y2 = m->tab[m->j - 1][1][m->i];
}

void	hori_value(t_m *m)
{
	m->x1 = m->tab[m->j][0][m->i];
	m->y1 = m->tab[m->j][1][m->i];
	m->x2 = m->tab[m->j][0][m->i + 1];
	m->y2 = m->tab[m->j][1][m->i + 1];
}

void	string_to_window(t_m *m)
{
	mlx_string_put(m->ptr, m->win, 40, 20, 0x2FFFE9, " * * * MANIPULATE * * *");
	mlx_string_put(m->ptr, m->win, 40, 50, 0x13FFE9, "*  Rot  Z :     7 & 8   *");
	mlx_string_put(m->ptr, m->win, 40, 70, 0x13EBE9, "*  Rot  Y :     4 & 5   *");
	mlx_string_put(m->ptr, m->win, 40, 90, 0x13D7E9, "*  Rot  X :     1 & 2   *");
	mlx_string_put(m->ptr, m->win, 40, 110, 0x13C3E9, "*  Relief :     3 & 6   *");
	mlx_string_put(m->ptr, m->win, 40, 150, 0x139BE9, "*  Zoom :       + & -   *");
	mlx_string_put(m->ptr, m->win, 40, 130, 0x13AFE9, "*  Move :       Arrows  *");
	mlx_string_put(m->ptr, m->win, 40, 170, 0x1387E9, "*  Clean :      clear   *");
	mlx_string_put(m->ptr, m->win, 40, 190, 0x1373E9, "*  Parallele :    P     *");
	mlx_string_put(m->ptr, m->win, 40, 210, 0x1373E9, "*  Iso :          [     *");
	mlx_string_put(m->ptr, m->win, 40, 230, 0x1373E9, "* * * * * * * * * * * * *");
	mlx_string_put(m->ptr, m->win, WIDTH - 290, 20, 0xFFFFFF, " * * * COLOR * * *");
	mlx_string_put(m->ptr, m->win, WIDTH - 290, 50, 0xFFFFFF, "* WHITE :    E    *");
	mlx_string_put(m->ptr, m->win, WIDTH - 290, 70, 0xFF0000, "* RED :      R    *");
	mlx_string_put(m->ptr, m->win, WIDTH - 290, 90, 0xFF00, "* GREEN :    T    *");
	mlx_string_put(m->ptr, m->win, WIDTH - 290, 110, 0xFF, "* BLUE :     Y    *");
	mlx_string_put(m->ptr, m->win, WIDTH - 290, 150, 0xFF9B00, "* ORANGE :   U    *");
	mlx_string_put(m->ptr, m->win, WIDTH - 290, 130, 0xE600FF, "* PINK :     I    *");
	mlx_string_put(m->ptr, m->win, WIDTH - 290, 170, 0xFFF000, "* YELLOW :   O    *");
	mlx_string_put(m->ptr, m->win, WIDTH - 290, 190, 0x999999, "* ALPHA :  N & M  *");
	mlx_string_put(m->ptr, m->win, WIDTH - 290, 210, rand(), "* RANDOM :   A    *");
	mlx_string_put(m->ptr, m->win, WIDTH - 290, 230, 0xFFFFFF, "* * * * * * * * * *");
}

void	draw_rot(t_m m)
{
	m.tab = fill_tab(m);
	while (m.i < m.column - 1 || m.j < m.line - 1)
	{
		if (m.j != 0)
		{
			vert_value(&m);
			trace(m);
		}
		if (m.i < m.column - 1)
		{
			hori_value(&m);
			trace(m);
		}
		m.i++;
		if (m.i == m.column - 1 && m.j != 0)
		{
			vert_value(&m);
			trace(m);
		}
		if (m.i >= m.column - 1 && m.j < m.line - 1)
		{
			m.j++;
			m.i = 0;
		}
	}
}
