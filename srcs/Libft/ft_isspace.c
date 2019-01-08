/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 16:18:31 by gfranco           #+#    #+#             */
/*   Updated: 2018/06/02 08:21:14 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isspace(int c)
{
	int		result;

	result = 0;
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\r' ||
		c == '\f')
		return (1);
	return (0);
}