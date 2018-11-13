/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:08:36 by gfranco           #+#    #+#             */
/*   Updated: 2018/11/13 16:10:58 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		nb_column(char *file)
{
	char	*line;
	int		fd;
	int		nbr;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	nbr = get_next_line(fd, &line);
	nbr = 0;
	while (line[i])
	{
		if (line[i] >= '0' && line[i] <= '9')
			nbr++;
		i++;
	}
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
		nbr++;
	close(fd);
	return (nbr);
}

int		***make_array(int line, int column, t_pos pos)
{
	int		***array;
	int		i;

	i = 0;
	printf("\033[1;31mline = %d\033[0m\n", line);
	if (!(array = (int***)malloc(sizeof(*array) * line)))
		exit(EXIT_FAILURE);
	while (line-- > 0)
	{
		if (!(array[i] = (int**)malloc(sizeof(*array) * 3)))
			exit(EXIT_FAILURE);
		if (!(array[i][0] = (int*)malloc(sizeof(*array) * column)))
			exit(EXIT_FAILURE);
		if (!(array[i][1] = (int*)malloc(sizeof(*array) * column)))
			exit(EXIT_FAILURE);
		if (!(array[i][2] = (int*)malloc(sizeof(*array) * column)))
			exit(EXIT_FAILURE);
		i++;
	}
	return (array);
}

int		***stock(t_pos pos, char *file)
{
	int		***array;
	int		line;
	int		column;

	line = nb_line(file);
	column = nb_column(file);
	array = make_array(line, column, pos);
	return (array);
}
