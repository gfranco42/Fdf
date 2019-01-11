/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:23:34 by gfranco           #+#    #+#             */
/*   Updated: 2019/01/11 15:45:14 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

void	redraw(t_m *m)
{
	int		fd;

	ft_memset(m->str, 0, WIDTH * HEIGHT * 4);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
	stock(m->av, m);
	if ((fd = open(m->av, O_RDONLY)) == -1)
		fail(1);
	m->array =	fill(fd, *m);
	m->i = 0;
	m->j = 0;
	draw_rot(*m);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
	string_to_window(m);
}

void	redraw_move(t_m *m, float a, float b)
{
	int		fd;

	ft_memset(m->str, 0, WIDTH * HEIGHT * 4);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
	stock(m->av, m);
	if ((fd = open(m->av, O_RDONLY)) == -1)
		fail(1);
	m->array =	fill(fd, *m);
	m->i = 0;
	m->j = 0;
	m->xinit += a;
	m->yinit += b;
	draw_rot(*m);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
	string_to_window(m);
}

void	redraw_zoom_in(t_m *m)
{
	int		fd;

	ft_memset(m->str, 0, WIDTH * HEIGHT * 4);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
	stock(m->av, m);
	if ((fd = open(m->av, O_RDONLY)) == -1)
		fail(1);
	m->array = fill(fd, *m);
	m->i = 0;
	m->j = 0;
	m->xinit -= (m->gap - m->savegap) * (m->column - 1) / 2;
	m->yinit -= (m->gap - m->savegap) * (m->line - 1) / 2;
	m->savegap = m->gap;
	draw_rot(*m);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
	string_to_window(m);
}

void	redraw_zoom_out(t_m *m)
{
	int		fd;

	ft_memset(m->str, 0, WIDTH * HEIGHT * 4);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
	stock(m->av, m);
	if ((fd = open(m->av, O_RDONLY)) == -1)
		fail(1);
	m->array = fill(fd, *m);
	m->i = 0;
	m->j = 0;
	m->xinit += (m->savegap - m->gap) * (m->column - 1) / 2;
	m->yinit += (m->savegap - m->gap) * (m->line - 1) / 2;
	m->savegap = m->gap;
	draw_rot(*m);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
	string_to_window(m);
}
