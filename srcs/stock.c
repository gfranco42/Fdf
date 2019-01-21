/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:08:36 by gfranco           #+#    #+#             */
/*   Updated: 2019/01/21 12:38:41 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	finish_fd(int fd)
{
	char	*line;

	while (get_next_line(fd, &line) > 0)
		free(line);
}

int		nb_column(char *file)
{
	char	*line;
	int		fd;
	int		nbr;
	int		g;
	int		i;

	i = 0;
	nbr = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		fail(1);
	g = get_next_line(fd, &line);
	while (line[i])
	{
		if (line[i] >= '0' && line[i] <= '9')
		{
			if (line[i + 1] == '\0' || line[i + 1] == ' ')
				nbr++;
		}
		i++;
	}
	free(line);
	finish_fd(fd);
	close(fd);
	return (nbr);
}

int		nb_line(char *file)
{
	char	*line;
	int		fd;
	int		nbr;
	int		g;

	nbr = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		fail(1);
	g = get_next_line(fd, &line);
	if (g == 0)
		fail(6);
	nbr++;
	free(line);
	while (get_next_line(fd, &line) > 0)
	{
		nbr++;
		free(line);
	}
	close(fd);
	return (nbr);
}

int		**make_array(t_m *m)
{
	int		**array;
	int		i;
	int		idx;

	i = 0;
	idx = m->line;
	if (!(array = (int**)malloc(sizeof(*array) * idx)))
		exit(EXIT_FAILURE);
	while (idx-- > 0)
	{
		if (!(array[i] = (int*)malloc(sizeof(*array) * m->column)))
			exit(EXIT_FAILURE);
		i++;
	}
	return (array);
}

void	stock(char *file, t_m *m)
{
	m->line = nb_line(file);
	m->column = nb_column(file);
	m->array = make_array(m);
}
