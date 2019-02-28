/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 11:41:37 by gfranco           #+#    #+#             */
/*   Updated: 2019/02/04 11:31:39 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_tabs(t_m *m)
{
	m->i = 0;
	while (m->i < m->line)
	{
		free(m->array[m->i]);
		m->i++;
	}
	free(m->array);
	m->array = NULL;
	m->i = 0;
	while (m->i < m->line)
	{
		free(m->tab[m->i][0]);
		free(m->tab[m->i][1]);
		free(m->tab[m->i]);
		m->i++;
	}
	free(m->tab);
	m->tab = NULL;
}

void	vert_value(t_m *m)
{
	m->x1 = m->tab[m->j][0][m->i];
	m->y1 = m->tab[m->j][1][m->i];
	m->x2 = m->tab[m->j - 1][0][m->i];
	m->y2 = m->tab[m->j - 1][1][m->i];
	trace(*m);
}

void	hori_value(t_m *m)
{
	m->x1 = m->tab[m->j][0][m->i];
	m->y1 = m->tab[m->j][1][m->i];
	m->x2 = m->tab[m->j][0][m->i + 1];
	m->y2 = m->tab[m->j][1][m->i + 1];
	trace(*m);
}

void	draw_single(t_m m)
{
	m.j = 1;
	m.i = 0;
	while (m.j < m.line - 1)
	{
		vert_value(&m);
		m.j++;
	}
	vert_value(&m);
}

void	draw_rot(t_m m)
{
	if (m.column > 1)
	{
		m.tab = fill_tab(m);
		while (m.i < m.column - 1 || m.j < m.line - 1)
		{
			if (m.j != 0)
				vert_value(&m);
			if (m.i < m.column - 1)
				hori_value(&m);
			if (++m.i == m.column - 1 && m.j != 0)
				vert_value(&m);
			if (m.i >= m.column - 1 && m.j < m.line - 1)
			{
				m.j++;
				m.i = 0;
			}
		}
	}
	else
	{
		m.tab = fill_tab_first(m);
		draw_single(m);
	}
	free_tabs(&m);
}
