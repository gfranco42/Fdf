/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:23:34 by gfranco           #+#    #+#             */
/*   Updated: 2018/11/27 17:06:40 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	redraw_move(t_m *m, float a, float b)
{
//	mlx_clear_window(m->ptr, m->win);
//	mlx_destroy_image(m->ptr, m->img);
	ft_memset(m->str, 0, WIDTH * HEIGHT * 4);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
	m->xinit += a;
	m->yinit += b;
	m->x1 = m->xinit;
	m->y1 = m->yinit;
	draw(*m);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
}

void	redraw_zoom_in(t_m *m)
{
//	mlx_clear_window(m->ptr, m->win);
//	mlx_destroy_image(m->ptr, m->img);
	ft_memset(m->str, 0, WIDTH * HEIGHT * 4);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
	m->xinit -= (m->gap - m->savegap) * (m->column - 1) / 2;
	m->yinit -= (m->gap - m->savegap) * (m->line - 1) / 2;
	m->savegap = m->gap;
	m->x1 = m->xinit;
	m->y1 = m->yinit;
	draw(*m);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
}

void	redraw_zoom_out(t_m *m)
{
//	mlx_clear_window(m->ptr, m->win);
//	mlx_destroy_image(m->ptr, m->img);
	ft_memset(m->str, 0, WIDTH * HEIGHT * 4);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
	m->xinit -= (m->gap - m->savegap) * (m->column - 1) / 2;
	m->yinit -= (m->gap - m->savegap) * (m->line - 1) / 2;
	m->savegap = m->gap;
	m->x1 = m->xinit;
	m->y1 = m->yinit;
	draw(*m);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
}

void	zero(t_m *m)
{
	ft_memset(m->str, 0, WIDTH * HEIGHT * 4);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
	m->xinit = 0 - (m->column - 1) * m->initgap / 2;
	m->yinit = 0 - (m->line - 1) * m->initgap / 2;
	m->x1 = m->xinit;
	m->y1 = m->yinit;
	draw(*m);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
}

void	iso(t_m *m)
{
//	mlx_clear_window(m->ptr, m->win);
//	mlx_destroy_image(m->ptr, m->img);
	ft_memset(m->str, 0, WIDTH * HEIGHT * 4);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
	m->gap = m->initgap;
	m->savegap = m->initgap;
	m->xinit = WIDTH / 2;
	m->yinit = HEIGHT / 4;
	m->x1 = m->xinit;
	m->y1 = m->yinit;
	draw_iso(*m);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
}

void	paralelle(t_m *m)
{
//	mlx_clear_window(m->ptr, m->win);
//	mlx_destroy_image(m->ptr, m->img);
	ft_memset(m->str, 0, WIDTH * HEIGHT * 4);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
	m->gap = m->initgap;
	m->savegap = m->initgap;
	m->xinit = WIDTH / 2 - ((m->column - 1) * m->gap) / 2;
	m->yinit = HEIGHT / 2 - ((m->line - 1) * m->gap) / 2;
	m->x1 = m->xinit;
	m->y1 = m->yinit;
	draw(*m);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
}

void	conique(t_m *m)
{
//	mlx_clear_window(m->ptr, m->win);
//	mlx_destroy_image(m->ptr, m->img);
	ft_memset(m->str, 0, WIDTH * HEIGHT * 4);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
	m->gap = m->initgap;
	m->savegap = m->initgap;
	m->xinit = WIDTH / 2 - ((m->column - 1) * m->gap) / 2;
	m->yinit = HEIGHT / 2 - ((m->line - 1) * m->gap) / 2;
	m->x1 = m->xinit;
	m->y1 = m->yinit;
	draw(*m);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
}

/*void		moving(t_m *m)
{
	
}*/
