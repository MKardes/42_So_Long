/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chcs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 12:24:30 by mkardes           #+#    #+#             */
/*   Updated: 2022/08/13 02:42:36 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collect_chc(t_ptrs *ptr)
{
	if (ptr->map->map[(ptr->player[0].y / PIY)]
		[(ptr->player[0].x / PIX)] == 'C')
	{
		ptr->map->map[(ptr->player[0].y / PIY)][(ptr->player[0].x / PIX)] = '0';
	}
}

int	chc(t_ptrs *ptr)
{
	int	x;
	int	y;

	y = 0;
	while (y < ptr->map->y)
	{
		x = 0;
		while (x < ptr->map->x)
		{
			if (ptr->map->map[y][x] == 'C')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	check_door(t_ptrs *ptr)
{
	if (chc(ptr))
		ptr->door_chc = 1;
}	
