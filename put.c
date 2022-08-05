/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 22:32:18 by mkardes           #+#    #+#             */
/*   Updated: 2022/08/05 04:54:24 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	bg_put(t_ptrs *ptr)
{
	int i;
	int j;

	i = 0;
	while (i < ptr->map.y)
	{
		j = 0;
		while (j < ptr->map.x)
		{
			mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->images->lay[LAYER], j * 64, i * 64);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->images->play[PLAYER], 64, 64);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->images->play[PLAYER + 1], 128, 64);
}

void	map_put(t_ptrs *ptr)
{
	bg_put(ptr);
}
