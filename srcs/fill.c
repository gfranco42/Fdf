/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:45:46 by gfranco           #+#    #+#             */
/*   Updated: 2019/01/14 16:28:17 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	convert(t_m *m, char **arr)
{
	int		int_value;

	int_value = ft_atoi(arr[m->i]);
	if (int_value > MAX_Z)
		m->array[m->j][m->i] = MAX_Z;
	else if (int_value < MIN_Z)
		m->array[m->j][m->i] = MIN_Z;
	else
		m->array[m->j][m->i] = int_value;
}

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
		if (!arr[m.column - 1] || arr[m.column] != '\0')
			fail(5);
		while (arr[m.i])
		{
			convert(&m, arr);
			free(arr[m.i]);
			m.i++;
		}
		free(arr);
		arr = NULL;
		m.j++;
		m.i = 0;
		free(line);
	}
	return (m.array);
}
