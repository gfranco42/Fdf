/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:23:34 by gfranco           #+#    #+#             */
/*   Updated: 2018/12/17 12:57:17 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*void	degrade_blue(t_m *m)
{
	int	count;

	count = 0;
	while ()
}*/

void	redraw_relief(t_m *m, t_color *color)
{
	ft_memset(m->str, 0, WIDTH * HEIGHT * 4);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
	draw_rot(*m, color);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
}

void	redraw_move(t_m *m, float a, float b, t_color *color)
{
	ft_memset(m->str, 0, WIDTH * HEIGHT * 4);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
	m->xinit += a;
	m->yinit += b;
	draw_rot(*m, color);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
}

void	redraw_zoom_in(t_m *m, t_color *color)
{
	ft_memset(m->str, 0, WIDTH * HEIGHT * 4);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
	m->xinit -= (m->gap - m->savegap) * (m->column - 1) / 2;
	m->yinit -= (m->gap - m->savegap) * (m->line - 1) / 2;
	m->savegap = m->gap;
	draw_rot(*m, color);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
}

void	redraw_zoom_out(t_m *m, t_color *color)
{
	ft_memset(m->str, 0, WIDTH * HEIGHT * 4);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
	m->xinit += (m->savegap - m->gap) * (m->column - 1) / 2;
	m->yinit += (m->savegap - m->gap) * (m->line - 1) / 2;
	m->savegap = m->gap;
	draw_rot(*m, color);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
}

void	iso(t_m *m, t_color *color)
{
	ft_memset(m->str, 0, WIDTH * HEIGHT * 4);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
	m->gap = m->initgap;
	m->savegap = m->initgap;
	m->xinit = WIDTH / 2;
	m->yinit = HEIGHT / 4;
	draw_rot(*m, color);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
}

void	parallele(t_m *m, t_color *color)
{
	if (m->str)
		ft_memset(m->str, 0, WIDTH * HEIGHT * 4);
//	printf("\t50\n");
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
//	printf("\t51\n");
	m->gap = m->initgap;
	m->savegap = m->initgap;
	m->xinit = WIDTH / 2 - ((m->column - 1) * m->gap) / 2;
	m->yinit = HEIGHT / 2 - ((m->line - 1) * m->gap) / 2;
	m->xtheta = 0;
	m->ytheta = 0;
	m->ztheta = 0;
//	printf("\t52\n");
	draw_rot(*m, color);
//	printf("\t53\n");
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
//	printf("\t54\n");
}

void	conique(t_m *m, t_color *color)
{
	ft_memset(m->str, 0, WIDTH * HEIGHT * 4);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
	m->gap = m->initgap;
	m->savegap = m->initgap;
	m->xinit = WIDTH / 2 - ((m->column - 1) * m->gap) / 2;
	m->yinit = HEIGHT / 2 - ((m->line - 1) * m->gap) / 2;
	draw_rot(*m, color);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
}
