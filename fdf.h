/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 19:46:34 by gfranco           #+#    #+#             */
/*   Updated: 2018/11/08 18:15:17 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include "./Libft/libft.h"
# include "./colors.h"

# define WIDTH 1000
# define HEIGHT 1000
# define GAP 30

typedef struct		s_pos
{
	int		x1;
	int		y1;
	int		x2;
	int		y2;
}					t_pos;

typedef struct		s_mlx
{
	void	*ptr;
	void	*win;
}					t_mlx;

#endif
