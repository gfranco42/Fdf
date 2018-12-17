/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:08:36 by gfranco           #+#    #+#             */
/*   Updated: 2018/12/13 17:30:43 by gfranco          ###   ########.fr       */
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
//	printf("\t15\n");

	i = 0;
	nbr = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
	{
//		printf("\t16\n");
		fail();
	}
	g = get_next_line(fd, &line);
//	printf("\t17\n");
	while (line[i])
	{
//		printf("\t18\n");
		if (line[i] >= '0' && line[i] <= '9')
		{
//			printf("\t19\n");
			if (line[i + 1] == '\0' || line[i + 1] == ' ')
			{
//				printf("\t20\n");
				nbr++;
			}
		}
		i++;
	}
//	printf("\t21\n");
	free(line);
//	printf("\t22\n");
	while ((g = get_next_line(fd, &line)) == 1)
	{
//		printf("\t23\n");
		free(line);
	}
//	printf("\t24\n");
	close(fd);
//	printf("\t25\n");
	return (nbr);
}

int		nb_line(char *file)
{
	char	*line;
	int		fd;
	int		nbr;

	nbr = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
	{
//		printf("\t10\n");
		fail();
	}
	while (get_next_line(fd, &line) > 0)
	{
//		printf("\t11\n");
		nbr++;
		free(line);
	}
//	printf("\t12\n");
	close(fd);
//	printf("\t13\n");
	return (nbr);
}

int		**make_array(t_m *m)
{
	int		**array;
	int		i;
	int		idx;

	i = 0;
	idx = m->line;
//	printf("\t28\n");
	if (!(array = (int**)malloc(sizeof(*array) * idx)))
		exit(EXIT_FAILURE);
//	printf("\t29\n");
	while (idx-- > 0)
	{
//		printf("\t30\n");
//		if (idx == 0)
//		{
//			printf("\t31\n");
//			if (!(array[i] = (int*)malloc(sizeof(*array) * 1)))
//				exit(EXIT_FAILURE);
//		}
//		else
//		{
//			printf("\t34\n");
			if (!(array[i] = (int*)malloc(sizeof(*array) * m->column)))
				exit(EXIT_FAILURE);
//		}
		i++;
	}
//	printf("\t36\n");
	return (array);
}

int		**stock(char *file, t_m *m)
{
	int		**array;

//	printf("\t8\n");
	m->line = nb_line(file);
//	printf("\t14\n");
	m->column = nb_column(file);
//	printf("\t26\n");
	array = make_array(m);
//	printf("\t37\n");
	return (array);
}
