/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:45:46 by gfranco           #+#    #+#             */
/*   Updated: 2018/11/20 15:00:50 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		**fill(int **array, t_tool *t, int fd, t_tri v)
{
	char	*l;
	int		g;

	v.i = 0;
	v.j = 0;
	v.k = -1;
	while ((g = get_next_line(fd, &l)) == 1)
	{
		while (l[++v.k])
		{
			if (l[v.k] >= '0' && l[v.k] <= '9')
			{
				array[v.j][v.i] = l[v.k] - 1 == '-' ? (l[v.k] - 48) * -1 
					: l[v.k] - 48;
				v.i++;
			}
		}
		free(l);
		v.i = 0;
		v.j++;
		v.k = -1;
	}
	close(fd);
	return (array);
}
