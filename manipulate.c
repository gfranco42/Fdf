/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:23:34 by gfranco           #+#    #+#             */
/*   Updated: 2019/01/10 18:15:38 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

void	check_rel(t_m *m)
{
	m->i = 0;
	m->j = 0;
	while (m->j < m->line)
	{
		while (m->i < m->column)
		{
			m->a = (m->array[m->j][m->i] * m->relief >= MAX_Z) ? 0 : 1;
			m->b = (m->array[m->j][m->i] * m->relief <= MIN_Z) ? 0 : 1;
			m->array[m->j][m->i] = m->array[m->j][m->i] >= MAX_Z ?
			MAX_Z : m->array[m->j][m->i];
			m->array[m->j][m->i] = m->array[m->j][m->i] <= MIN_Z ?
			MIN_Z : m->array[m->j][m->i];
			m->i++;
		}
		m->j++;
	}
	printf("arr * rel : %f\n", m->array[2][3] * m->relief);
}

void	redraw(t_m *m)
{
	int		fd;

	ft_memset(m->str, 0, WIDTH * HEIGHT * 4);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
	stock(m->av, m);
	if ((fd = open(m->av, O_RDONLY)) == -1)
		fail(1);
	m->array = fill(fd, *m);
	printf("array: %d\n", m->array[3][2]);
	printf("1	a: %d, b: %d\n", m->a, m->b);
	check_rel(m);
	printf("2	a: %d, b: %d\n", m->a, m->b);
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
	check_rel(m);
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
	check_rel(m);
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
	check_rel(m);
	m->i = 0;
	m->j = 0;
	m->xinit += (m->savegap - m->gap) * (m->column - 1) / 2;
	m->yinit += (m->savegap - m->gap) * (m->line - 1) / 2;
	m->savegap = m->gap;
	draw_rot(*m);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
	string_to_window(m);
}
