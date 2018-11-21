/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:23:34 by gfranco           #+#    #+#             */
/*   Updated: 2018/11/21 17:52:51 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	redraw_move(t_m *m, float a, float b)
{
	mlx_clear_window(m->ptr, m->win);
	m->xinit += a;
	m->yinit += b;
	m->x1 = m->xinit;
	m->y1 = m->yinit;
	draw(*m);
}

void	redraw_zoom_in(t_m *m)
{
	mlx_clear_window(m->ptr, m->win);
	m->xinit -= (m->gap - m->savegap) * (m->column - 1) / 2;
	m->yinit -= (m->gap - m->savegap) * (m->line - 1) / 2;
	m->savegap = m->gap;
	m->x1 = m->xinit;
	m->y1 = m->yinit;
	draw(*m);
}

void	redraw_zoom_out(t_m *m)
{
	mlx_clear_window(m->ptr, m->win);
	m->xinit -= (m->gap - m->savegap) * (m->column - 1) / 2;
	m->yinit -= (m->gap - m->savegap) * (m->line - 1) / 2;
	m->savegap = m->gap;
	m->x1 = m->xinit;
	m->y1 = m->yinit;
	draw(*m);
}

void	clean(t_m *m)
{
	mlx_clear_window(m->ptr, m->win);
	m->gap = m->initgap;
	m->savegap = m->initgap;
	m->xinit = WIDTH / 2 - ((m->column - 1) * m->gap) / 2;
	m->yinit = HEIGHT / 2 - ((m->line - 1) * m->gap) / 2;
	m->x1 = m->xinit;
	m->y1 = m->yinit;
	draw(*m);
}
/*void		moving(t_m *m)
{
	
}*/
