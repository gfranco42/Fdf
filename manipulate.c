/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:23:34 by gfranco           #+#    #+#             */
/*   Updated: 2018/12/04 13:08:52 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	redraw_move(t_m *m, float a, float b)
{
	ft_memset(m->str, 0, WIDTH * HEIGHT * 4);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
	m->xinit += a;
	m->yinit += b;
	m->x1 = m->xinit;
	m->y1 = m->yinit;
	draw_rot(*m);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
}

void	redraw_zoom_in(t_m *m)
{
	ft_memset(m->str, 0, WIDTH * HEIGHT * 4);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
//	m->xinit = WIDTH / 2 - ((m->column - 1) * m->gap) / 2;
//	m->yinit = HEIGHT / 2 - ((m->line - 1) * m->gap) / 2;
	printf("a in xinit: %f\n", m->xinit);
	m->xinit -= (m->gap - m->savegap) * (m->column - 1) / 2;
	printf("b in xinit: %f\n", m->xinit);
	m->yinit -= (m->gap - m->savegap) * (m->line - 1) / 2;
	m->savegap = m->gap;
	m->x1 = m->xinit;
	m->y1 = m->yinit;
	draw_rot(*m);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
}

void	redraw_zoom_out(t_m *m)
{
	ft_memset(m->str, 0, WIDTH * HEIGHT * 4);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
//	m->xinit = WIDTH / 2 - ((m->column - 1) * (m->gap - m->savegap)) / 2;
//	m->yinit = HEIGHT / 2 - ((m->line - 1) * (m->gap - m->savegap)) / 2;
	printf("a out xinit: %f\n", m->xinit);
	m->xinit += (m->savegap - m->gap) * (m->column - 1) / 2;
//	m->xinit += (m->savegap - m->gap/* - m->savegap)*/ * (m->column - 1)) / 2;
	printf("b out xinit: %f\n", m->xinit);
	m->yinit += (m->savegap - m->gap) * (m->line - 1) / 2;
//	m->yinit += (m->gap/* - m->savegap)*/ * (m->line - 1)) / 2;
	m->savegap = m->gap;
	m->x1 = m->xinit;
	m->y1 = m->yinit;
	draw_rot(*m);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
}

void	iso(t_m *m)
{
	ft_memset(m->str, 0, WIDTH * HEIGHT * 4);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
	m->gap = m->initgap;
	m->savegap = m->initgap;
	m->xinit = WIDTH / 2;
	m->yinit = HEIGHT / 4;
	m->x1 = m->xinit;
	m->y1 = m->yinit;
	draw_rot(*m);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
}

void	paralelle(t_m *m)
{
	ft_memset(m->str, 0, WIDTH * HEIGHT * 4);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
	m->gap = m->initgap;
	m->savegap = m->initgap;
	m->xinit = WIDTH / 2 - ((m->column - 1) * m->gap) / 2;
	m->yinit = HEIGHT / 2 - ((m->line - 1) * m->gap) / 2;
	m->xtheta = 0;
	m->ytheta = 0;
	m->ztheta = 0;
	m->x1 = m->xinit;
	m->y1 = m->yinit;
	draw_rot(*m);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
}

void	conique(t_m *m)
{
	ft_memset(m->str, 0, WIDTH * HEIGHT * 4);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
	m->gap = m->initgap;
	m->savegap = m->initgap;
	m->xinit = WIDTH / 2 - ((m->column - 1) * m->gap) / 2;
	m->yinit = HEIGHT / 2 - ((m->line - 1) * m->gap) / 2;
	m->x1 = m->xinit;
	m->y1 = m->yinit;
	draw_rot(*m);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
}
