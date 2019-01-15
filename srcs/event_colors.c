/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 12:42:55 by gfranco           #+#    #+#             */
/*   Updated: 2019/01/14 16:27:58 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		key_color1(int key, void *param)
{
	t_m	*m;

	m = (t_m*)param;
	if (key == 14)
	{
		m->dred = 0xff;
		m->dgreen = 0xff;
		m->dblue = 0xff;
		redraw(m);
	}
	return (0);
}

int		key_color2(int key, void *param)
{
	t_m	*m;

	m = (t_m*)param;
	if (key == 45)
	{
		if (m->alpha + 16 != 0)
			m->alpha += 16;
		redraw(m);
	}
	if (key == 46)
	{
		if (m->alpha - 16 != 0)
			m->alpha -= 16;
		redraw(m);
	}
	if (key == 0)
	{
		m->dred = rand();
		m->dgreen = rand();
		m->dblue = rand();
		redraw(m);
	}
	return (0);
}

int		key_color3(int key, void *param)
{
	t_m	*m;

	m = (t_m*)param;
	if (key == 15)
	{
		m->dred = 0xff;
		m->dgreen = 0;
		m->dblue = 0;
		redraw(m);
	}
	if (key == 17)
	{
		m->dgreen = 0xff;
		m->dred = 0;
		m->dblue = 0;
		redraw(m);
	}
	if (key == 16)
	{
		m->dblue = 0xff;
		m->dgreen = 0;
		m->dred = 0;
		redraw(m);
	}
	return (0);
}

int		key_color4(int key, void *param)
{
	t_m	*m;

	m = (t_m*)param;
	if (key == 32)
	{
		m->dred = 0xff;
		m->dgreen = 0x9b;
		m->dblue = 0;
		redraw(m);
	}
	if (key == 34)
	{
		m->dred = 0xe6;
		m->dgreen = 0;
		m->dblue = 0xff;
		redraw(m);
	}
	if (key == 31)
	{
		m->dred = 0xff;
		m->dgreen = 0xf0;
		m->dblue = 0;
		redraw(m);
	}
	return (0);
}

int		key_color(int key, void *param)
{
	t_m	*m;

	m = (t_m*)param;
	if (key == 14)
		key_color1(key, param);
	if (key == 45 || key == 46 || key == 0)
		key_color2(key, param);
	if (key == 15 || key == 17 || key == 16)
		key_color3(key, param);
	if (key == 32 || key == 34 || key == 31)
		key_color4(key, param);
	return (0);
}
