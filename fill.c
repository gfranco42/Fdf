/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:45:46 by gfranco           #+#    #+#             */
/*   Updated: 2019/01/04 14:12:59 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

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
