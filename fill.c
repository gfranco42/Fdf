/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:45:46 by gfranco           #+#    #+#             */
/*   Updated: 2018/12/12 18:31:10 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		**fill(int fd, t_m m)
{
	char	*line;
	char	**arr;

	m.i = 0;
	m.j = 0;
	m.k = 0;
	while ((m.k = get_next_line(fd, &line)) == 1)
	{
//		printf("\t40\n");
		arr = ft_strsplit(line, ' ');
//		printf("\t41\n");
		while (arr[m.i])
		{
//			printf("\t42\n");
			m.array[m.j][m.i] = ft_atoi(arr[m.i]);
//			printf("\t43\n");
			free(arr[m.i]);
//			printf("\t44\n");
			m.i++;
		}
//		printf("\t45\n");
		free(arr);
//		printf("\t46\n");
		arr = NULL;
//		printf("\t47\n");
		m.j++;
		m.i = 0;
	}
//	printf("\t48\n");
	return (m.array);
}
