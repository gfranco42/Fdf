/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:45:46 by gfranco           #+#    #+#             */
/*   Updated: 2018/11/13 17:28:28 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		***fill(int ***arr, t_init init, int fd)
{
	char	*l;
	t_tri	t;

	t.i = -1;
	t.j = 0;
	t.k = 0;
	while (get_next_line(fd, &l) > 0)
	{
		while (l[++t.i])
		{
			printf("\033[1;32mi = %d\n", t.i);
			printf("\033[1;33mj = %d\n", t.j);
			printf("\033[1;34mk = %d\033[0m\n\n", t.k);
			if (l[t.i] >= '0' && l[t.i] <= '9')
			{
				arr[t.j][0][t.k] = init.x + init.gap * t.k;
				arr[t.j][1][t.k] = init.y + init.gap * t.k;
				arr[t.j][2][t.k++] = l[t.i] - 1 == '-' ? (l[t.i] - 48) * -1 :
					l[t.i] - 48;
				printf("x = %d, y = %d, z = %d\n", arr[t.j][0][t.k - 1], arr[t.j][1][t.k - 1], arr[t.j][2][t.k - 1]);
			}
		}
		init.x -= init.gap;
		init.y += init.gap;
		t.i = -1;
		t.k = 0;
		t.j++;
	}
	return (arr);
}
