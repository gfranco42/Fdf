/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_sounds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 12:37:14 by gfranco           #+#    #+#             */
/*   Updated: 2019/01/07 13:46:33 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

int		key_sounds1(int key, void *param)
{
	t_m	*m;

	m = (t_m *)param;
	if (key == 18)
	{
		if (m->k != 0)
			system("killall afplay");
		system("afplay ./musics/ONE_PUNCH.wav &");
		m->k = 1;
	}
	else if (key == 19)
	{
		if (m->k != 0)
			system("killall afplay");
		system("afplay ./musics/ACDC &");
		m->k = 1;
	}
	else if (key == 20)
	{
		if (m->k != 0)
			system("killall afplay");
		system("afplay ./musics/AVICII &");
		m->k = 1;
	}
	return (0);
}

int		key_sounds2(int key, void *param)
{
	t_m	*m;

	m = (t_m *)param;
	if (key == 21)
	{
		if (m->k != 0)
			system("killall afplay");
		system("afplay ./musics/BoW &");
		m->k = 1;
	}
	else if (key == 23)
	{
		if (m->k != 0)
			system("killall afplay");
		system("afplay ./musics/NARUTO &");
		m->k = 1;
	}
	else if (key == 22)
	{
		if (m->k != 0)
			system("killall afplay");
		system("afplay ./musics/EMINEM &");
		m->k = 1;
	}
	return (0);
}

int		key_sounds3(int key, void *param)
{
	t_m	*m;

	m = (t_m *)param;
	if (key == 26)
	{
		if (m->k != 0)
			system("killall afplay");
		system("afplay ./musics/FUNKYCOPS &");
		m->k = 1;
	}
	else if (key == 28)
	{
		if (m->k != 0)
			system("killall afplay");
		system("afplay ./musics/BACH &");
		m->k = 1;
	}
	else if (key == 25)
	{
		if (m->k != 0)
			system("killall afplay");
		system("afplay ./musics/ARMSTRONG &");
		m->k = 1;
	}
	return (0);
}

int		key_sounds4(int key, void *param)
{
	t_m	*m;

	m = (t_m *)param;
	if (key == 29)
	{
		if (m->k != 0)
			system("killall afplay");
		system("afplay ./musics/ELECRICITY &");
		m->k = 1;
	}
	else if (key == 27)
	{
		if (m->k != 0)
			system("killall afplay");
		system("afplay ./musics/SSBM &");
		m->k = 1;
	}
	else if (key == 24)
	{
		if (m->k != 0)
			system("killall afplay");
		system("afplay ./musics/IRONMAIDEN &");
		m->k = 1;
	}
	return (0);
}

int		key_sounds(int key, void *param)
{
	t_m	*m;

	m = (t_m*)param;
	if (key == 18 || key == 19 || key == 20)
		key_sounds1(key, param);
	else if (key == 21 || key == 23 || key == 22)
		key_sounds2(key, param);
	else if (key == 26 || key == 28 || key == 25)
		key_sounds3(key, param);
	else if (key == 29 || key == 27 || key == 24)
		key_sounds4(key, param);
	return (0);
}
