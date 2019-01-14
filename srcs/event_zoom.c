/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_zoom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 12:27:34 by gfranco           #+#    #+#             */
/*   Updated: 2019/01/14 16:28:13 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		key_clean(int key, void *param)
{
	t_m	*m;

	m = (t_m *)param;
	if (key == 33)
		iso(m);
	else if (key == 35)
		parallele(m);
	else if (key == 71)
	{
		m->relief = 1;
		m->alpha = 0;
		m->dblue = 0xff;
		m->dgreen = 0xff;
		m->dred = 0xff;
		parallele(m);
	}
	return (0);
}

int		key_move(int key, void *param)
{
	t_m *m;

	m = (t_m *)param;
	if (key == 124)
		redraw_move(m, 20, 0);
	else if (key == 123)
		redraw_move(m, -20, 0);
	else if (key == 125)
		redraw_move(m, 0, 20);
	else if (key == 126)
		redraw_move(m, 0, -20);
	return (0);
}

int		key_stop(int key, void *param)
{
	t_m *m;

	m = (t_m *)param;
	if (key == 53)
	{
		if (m->k != 0)
			system("killall afplay");
		exit(0);
	}
	else if (key == 256)
	{
		if (m->k != 0)
		{
			system("killall afplay");
			m->k = 0;
		}
	}
	return (0);
}

int		key_zoom(int key, void *param)
{
	t_m *m;

	m = (t_m *)param;
	if (key == 69)
	{
		if (m->gap * 1.1 < 100)
		{
			m->relief *= 1.1;
			m->gap *= 1.1;
		}
		redraw_zoom_in(m);
	}
	else if (key == 78)
	{
		if (m->gap * 0.9 > 5)
		{
			m->relief *= 0.9;
			m->gap *= 0.9;
		}
		redraw_zoom_out(m);
	}
	return (0);
}
