/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 13:23:14 by gfranco           #+#    #+#             */
/*   Updated: 2019/01/14 16:28:50 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	trace1(t_m m)
{
	m.i = 0;
	while (m.i++ <= m.cx)
	{
		if (m.x1 > 0 && m.x1 < WIDTH && m.y1 < HEIGHT && m.y1 > 0)
		{
			m.str[(m.x1 + m.y1 * WIDTH) * 4] = m.blue + m.dblue;
			m.str[(m.x1 + m.y1 * WIDTH) * 4 + 1] = m.green + m.dgreen;
			m.str[(m.x1 + m.y1 * WIDTH) * 4 + 2] = m.red + m.dred;
			m.str[(m.x1 + m.y1 * WIDTH) * 4 + 3] = m.alpha;
		}
		m.x1 = m.x1 > m.x2 ? (m.x1 - 1) : (m.x1 + 1);
		m.ex -= m.dy;
		if (m.ex < 0)
		{
			m.y1 = m.y1 > m.y2 ? (m.y1 - 1) : (m.y1 + 1);
			m.ex += m.dx;
		}
	}
}

void	trace2(t_m m)
{
	m.i = 0;
	while (m.i++ <= m.cy)
	{
		if (m.y1 < HEIGHT && m.y1 > 0 && m.x1 < WIDTH && m.x1 > 0)
		{
			m.str[(m.x1 + m.y1 * WIDTH) * 4] = m.blue + m.dblue;
			m.str[(m.x1 + m.y1 * WIDTH) * 4 + 1] = m.green + m.dgreen;
			m.str[(m.x1 + m.y1 * WIDTH) * 4 + 2] = m.red + m.dred;
			m.str[(m.x1 + m.y1 * WIDTH) * 4 + 3] = m.alpha;
		}
		m.y1 = m.y1 > m.y2 ? (m.y1 - 1) : (m.y1 + 1);
		m.ey -= m.dx;
		if (m.ey < 0)
		{
			m.x1 = m.x1 > m.x2 ? (m.x1 - 1) : (m.x1 + 1);
			m.ey += m.dy;
		}
	}
}

void	trace(t_m m)
{
	m.ex = abs(m.x2 - m.x1);
	m.ey = abs(m.y2 - m.y1);
	m.dx = 2 * m.ex;
	m.dy = 2 * m.ey;
	m.cx = m.ex;
	m.cy = m.ey;
	if (m.cx > m.cy)
		trace1(m);
	else
		trace2(m);
}
