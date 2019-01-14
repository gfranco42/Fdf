/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:30:55 by gfranco           #+#    #+#             */
/*   Updated: 2019/01/14 16:28:24 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	back(t_m *m)
{
	m->x1 += m->xlen;
	m->y1 += m->ylen;
	m->xinit += m->xlen;
	m->yinit += m->ylen;
}

void	zero(t_m *m)
{
	ft_memset(m->str, 0, WIDTH * HEIGHT * 4);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
	m->xout = 0 - (m->column - 1) * m->gap / 2;
	m->yout = 0 - (m->line - 1) * m->gap / 2;
	m->xlen = 0 + m->xinit + (m->column - 1) * m->gap / 2;
	m->ylen = 0 + m->yinit + (m->line - 1) * m->gap / 2;
	m->x1 = m->xout;
	m->y1 = m->yout;
}

void	init_rot(t_m *m)
{
	m->i = 0;
	m->j = 0;
	zero(m);
	m->z = m->array[m->j][m->i] * m->relief;
	first_rotate(m);
	back(m);
}
