/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:23:34 by gfranco           #+#    #+#             */
/*   Updated: 2019/02/04 11:09:55 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	redraw(t_m *m)
{
	int		fd;

	stock(m->av, m);
	if ((fd = open(m->av, O_RDONLY)) == -1)
		fail(1);
	m->array = fill(fd, *m);
	m->i = 0;
	m->j = 0;
	ft_memset(m->str, 0, WIDTH * HEIGHT * 4);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
	draw_rot(*m);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
	string_to_window(m);
}

void	redraw_move(t_m *m, float a, float b)
{
	int		fd;

	stock(m->av, m);
	if ((fd = open(m->av, O_RDONLY)) == -1)
		fail(1);
	m->array = fill(fd, *m);
	m->i = 0;
	m->j = 0;
	m->xinit += a;
	m->yinit += b;
	ft_memset(m->str, 0, WIDTH * HEIGHT * 4);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
	draw_rot(*m);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
	string_to_window(m);
}

void	redraw_zoom_in(t_m *m)
{
	int		fd;

	stock(m->av, m);
	if ((fd = open(m->av, O_RDONLY)) == -1)
		fail(1);
	m->array = fill(fd, *m);
	m->i = 0;
	m->j = 0;
	m->xinit -= (m->gap - m->savegap) * (m->column - 1) / 2;
	m->yinit -= (m->gap - m->savegap) * (m->line - 1) / 2;
	m->savegap = m->gap;
	ft_memset(m->str, 0, WIDTH * HEIGHT * 4);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
	draw_rot(*m);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
	string_to_window(m);
}

void	redraw_zoom_out(t_m *m)
{
	int		fd;

	stock(m->av, m);
	if ((fd = open(m->av, O_RDONLY)) == -1)
		fail(1);
	m->array = fill(fd, *m);
	m->i = 0;
	m->j = 0;
	m->xinit += (m->savegap - m->gap) * (m->column - 1) / 2;
	m->yinit += (m->savegap - m->gap) * (m->line - 1) / 2;
	m->savegap = m->gap;
	ft_memset(m->str, 0, WIDTH * HEIGHT * 4);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
	draw_rot(*m);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
	string_to_window(m);
}
