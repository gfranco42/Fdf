/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:08:36 by gfranco           #+#    #+#             */
/*   Updated: 2018/11/12 18:01:52 by gfranco          ###   ########.fr       */
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
	int		j;
	int		k;
	int		count;

	i = 0;
	j = 0;
	k = 0;
	count = 0;
	if (!(array = (int***)malloc(sizeof(*array) * 3)))
		exit(EXIT_FAILURE);
	while (line-- > 0)
	{
		if (!(array[i] = (int**)malloc(sizeof(*array) * 3)))
			exit(EXIT_FAILURE);
		while (k++ < 3)
		{
			if (!(array[i][j++] = (int*)malloc(sizeof(*array) * 3)))
				exit(EXIT_FAILURE);
		}
		i++;
		k = 0;
	}
	return (array);
}

int		***parse(t_pos pos, char *file)
{
	int		***array;
	int		line;
	int		column;

	line = nb_line(file);
	column = nb_column(file);
	array = make_array(line, column, pos);
	array[0][0][0] = 1;
	array[0][1][0] = 2;
	array[0][2][0] = 3;
	array[0][0][1] = 4;
	array[0][1][1] = 5;
	array[0][2][1] = 6;
	array[0][0][2] = 7;
	array[0][1][2] = 8;
	array[0][2][2] = 9;
	printf("6 = %d, 7 = %d, 8 = %d, 1 = %d, 2 = %d, 9 = %d, 5 = %d, 3 = %d, 4 = %d\n", array[0][2][1], array[0][0][2], array[0][1][2], array[0][0][0], array[0][1][0], array[0][2][2], array[0][1][1], array[0][2][0], array[0][0][1]);
	return (array);
}
