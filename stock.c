/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:08:36 by gfranco           #+#    #+#             */
/*   Updated: 2018/11/16 15:02:28 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		nb_column(char *file)
{
	char	*line;
	int		fd;
	int		nbr;
	int		g;
	int		i;

	i = 0;
	nbr = 0;
	fd = open(file, O_RDONLY);
	g = get_next_line(fd, &line);
	while (line[i])
	{
		if (line[i] >= '0' && line[i] <= '9')
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
	int		test;

	nbr = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		nbr++;
		free(line);
	}
	close(fd);
	return (nbr);
}

int		**make_array(int line, int column)
{
	int		**array;
	int		i;

	i = 0;
	if (!(array = (int**)malloc(sizeof(*array) * (line + 1))))
		exit(EXIT_FAILURE);
	while (line-- > 0)
	{
		if (line == 0)
		{
			if (!(array[i] = (int*)malloc(sizeof(*array) * 1)))
				exit(EXIT_FAILURE);
		}
		else
			if (!(array[i] = (int*)malloc(sizeof(*array) * column)))
				exit(EXIT_FAILURE);
		i++;
	}
	return (array);
}

int		**stock(char *file, int *line, int *column)
{
	int		**array;

	*line = nb_line(file);
	*column = nb_column(file);
	array = make_array(*line, *column);
	return (array);
}
