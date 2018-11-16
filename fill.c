/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:45:46 by gfranco           #+#    #+#             */
/*   Updated: 2018/11/16 14:36:20 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		**fill(int **array, t_tri t, int fd)
{
	char	*line;
	int		g;

	t.i = 0;
	t.j = 0;
	t.k = -1;
	while ((g = get_next_line(fd, &line)) == 1)
	{
		while (line[++t.k])
		{
			if (line[t.k] >= '0' && line[t.k] <= '9')
			{
				array[t.j][t.i] = line[t.k] - 1 == '-' ? (line[t.k] - 48) * -1 
					: line[t.k] - 48;
				t.i++;
			}
		}
		free(line);
		t.i = 0;
		t.j++;
		t.k = -1;
	}
	close(fd);
	return (array);
}
