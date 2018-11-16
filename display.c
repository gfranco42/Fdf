/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 16:14:31 by gfranco           #+#    #+#             */
/*   Updated: 2018/11/16 17:44:12 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		xincr(int *x2, int *y2, t_tri t, t_init init)
{
	*x2 = init.x + (t.i + 1) * init.gap;
	*y2 = init.y + t.j * init.gap;
}

void		yincr(int *x2, int *y2, t_tri t, t_init init)
{
	*x2 = init.x + t.i * init.gap;
	*y2 = init.y + (t.j - 1) * init.gap;
}

//void		ydecr(int *x2, int *y2, t_tri t, t_init init)
//{
//	*x2 = init.x + 
//}

void		move(int *x1, int *y1, int x2, int y2)
{
	*x1 = x2;
	*y1 = y2;
}
