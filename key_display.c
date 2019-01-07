/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 11:31:29 by gfranco           #+#    #+#             */
/*   Updated: 2019/01/07 11:50:23 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

void	manip(t_m *m)
{
	mlx_string_put(m->ptr, m->win, 5, 20, 0x2FFFE9, " * * * MANIPULATE * * *");
	mlx_string_put(m->ptr, m->win, 5, 50, 0x13FFE9, "*  Rot  Z :  7 & 8    *");
	mlx_string_put(m->ptr, m->win, 5, 70, 0x13EBE9, "*  Rot  Y :  4 & 5    *");
	mlx_string_put(m->ptr, m->win, 5, 90, 0x13D7E9, "*  Rot  X :  1 & 2    *");
	mlx_string_put(m->ptr, m->win, 5, 110, 0x13C3E9, "*  Relief :  3 & 6    *");
	mlx_string_put(m->ptr, m->win, 5, 150, 0x139BE9, "*  Zoom :    + & -    *");
	mlx_string_put(m->ptr, m->win, 5, 130, 0x13AFE9, "*  Move :    Arrows   *");
	mlx_string_put(m->ptr, m->win, 5, 170, 0x1387E9, "*  Clean :   clear    *");
	mlx_string_put(m->ptr, m->win, 5, 190, 0x1373E9, "*  Para :      P      *");
	mlx_string_put(m->ptr, m->win, 5, 210, 0x1373E9, "*  Iso :       [      *");
	mlx_string_put(m->ptr, m->win, 5, 230, 0x1373E9, "* * * * * * * * * * * *");
}

void	color(t_m *m)
{
	mlx_string_put(m->ptr, m->win, WIDTH - 230, 20, 0xFFFFFF,
	" * * * COLOR * * *");
	mlx_string_put(m->ptr, m->win, WIDTH - 230, 50, 0xFFFFFF,
	"* WHITE :    E    *");
	mlx_string_put(m->ptr, m->win, WIDTH - 230, 70, 0xFF0000,
	"* RED :      R    *");
	mlx_string_put(m->ptr, m->win, WIDTH - 230, 90, 0xFF00,
	"* GREEN :    T    *");
	mlx_string_put(m->ptr, m->win, WIDTH - 230, 110, 0xFF,
	"* BLUE :     Y    *");
	mlx_string_put(m->ptr, m->win, WIDTH - 230, 150, 0xFF9B00,
	"* ORANGE :   U    *");
	mlx_string_put(m->ptr, m->win, WIDTH - 230, 130, 0xE600FF,
	"* PINK :     I    *");
	mlx_string_put(m->ptr, m->win, WIDTH - 230, 170, 0xFFF000,
	"* YELLOW :   O    *");
	mlx_string_put(m->ptr, m->win, WIDTH - 230, 190, 0x999999,
	"* ALPHA :  N & M  *");
	mlx_string_put(m->ptr, m->win, WIDTH - 230, 210, rand(),
	"* RANDOM :   A    *");
	mlx_string_put(m->ptr, m->win, WIDTH - 230, 230, 0xFFFFFF,
	"* * * * * * * * * *");
}

void	song1(t_m *m)
{
	mlx_string_put(m->ptr, m->win, 5, HEIGHT - 330, 0xD70000,
	"* * * * * SONG * * * *");
	mlx_string_put(m->ptr, m->win, 5, HEIGHT - 300, 0xD70F00,
	"* One Punch :     1   *");
	mlx_string_put(m->ptr, m->win, 5, HEIGHT - 280, 0xD71E00,
	"* Hard Rock :     2   *");
	mlx_string_put(m->ptr, m->win, 5, HEIGHT - 260, 0xD72D00,
	"* Electro :       3   *");
	mlx_string_put(m->ptr, m->win, 5, HEIGHT - 240, 0xD73C00,
	"* Pop :           4   *");
	mlx_string_put(m->ptr, m->win, 5, HEIGHT - 220, 0xD74B00,
	"* Jap :           5   *");
	mlx_string_put(m->ptr, m->win, 5, HEIGHT - 200, 0xD75A00,
	"* Rap :           6   *");
}

void	song2(t_m *m)
{
	mlx_string_put(m->ptr, m->win, 5, HEIGHT - 180, 0xD76900,
	"* Disco :         7   *");
	mlx_string_put(m->ptr, m->win, 5, HEIGHT - 160, 0xD77800,
	"* Classique :     8   *");
	mlx_string_put(m->ptr, m->win, 5, HEIGHT - 140, 0xD78700,
	"* Jazz :          9   *");
	mlx_string_put(m->ptr, m->win, 5, HEIGHT - 120, 0xD79600,
	"* Funk :          0   *");
	mlx_string_put(m->ptr, m->win, 5, HEIGHT - 100, 0xD7A500,
	"* Jeux Video :    -   *");
	mlx_string_put(m->ptr, m->win, 5, HEIGHT - 80, 0xD7B400,
	"* Metal :         =   *");
	mlx_string_put(m->ptr, m->win, 5, HEIGHT - 60, 0xD7C300,
	"* Stop Music :   Ctrl *");
	mlx_string_put(m->ptr, m->win, 5, HEIGHT - 40, 0xD7D200,
	"* * * * * * * * * * * *");
}

void	string_to_window(t_m *m)
{
	manip(m);
	color(m);
	song1(m);
	song2(m);
}
