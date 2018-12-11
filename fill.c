/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:45:46 by gfranco           #+#    #+#             */
/*   Updated: 2018/12/11 13:33:33 by gfranco          ###   ########.fr       */
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
		arr = ft_strsplit(line, ' ');
		while (arr[m.i])
		{
			m.array[m.j][m.i] = ft_atoi(arr[m.i]);
			free(arr[m.i]);
			m.i++;
		}
		free(arr);
		arr = NULL;
		m.j++;
		m.i = 0;
	}
	return (m.array);
}
