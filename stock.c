/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:08:36 by gfranco           #+#    #+#             */
/*   Updated: 2018/12/03 15:02:11 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fail()
{
	ft_putstr("Failed to open <FILE>\n");
	exit(EXIT_FAILURE);
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
		fail();
	g = get_next_line(fd, &line);
	while (line[i])
	{
		if (line[i] >= '0' && line[i] <= '9')
			if (line[i + 1] == '\0' || line[i + 1] == ' ')
				nbr++;
		i++;
	}
	free(line);
	while ((g = get_next_line(fd, &line)) == 1)
		free(line);
	close(fd);
	return (nbr);
}

int		nb_line(char *file)
{
	char	*line;
	int		fd;
	int		nbr;

	nbr = 0;
//	fd = open(file, O_RDONLY);
	if ((fd = open(file, O_RDONLY)) == -1)
		fail();
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
	if (!(array = (int**)malloc(sizeof(*array) * (idx + 1))))
		exit(EXIT_FAILURE);
	while (idx-- > 0)
	{
		if (idx == 0)
		{
			if (!(array[i] = (int*)malloc(sizeof(*array) * 1)))
				exit(EXIT_FAILURE);
		}
		else
			if (!(array[i] = (int*)malloc(sizeof(*array) * m->column)))
				exit(EXIT_FAILURE);
		i++;
	}
	return (array);
}

int		**stock(char *file, t_m *m)
{
	int		**array;

	m->line = nb_line(file);
	m->column = nb_column(file);
	array = make_array(m);
	return (array);
}
