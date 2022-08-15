/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 22:32:18 by mkardes           #+#    #+#             */
/*   Updated: 2022/08/15 22:16:10 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	position(t_ptrs *ptr, int x, int y, char c)
{
	if (c == '1')
		mlx_put_image_to_window(ptr->mlx, ptr->win,
			ptr->images->wall[(WALL + ptr->bg) % W_CNT], x * PIX, y * PIY);
	if (c == 'E')
	{
		if (ptr->door_chc)
			mlx_put_image_to_window(ptr->mlx, ptr->win,
				ptr->images->exit[60], x * PIX, y * PIY);
		mlx_put_image_to_window(ptr->mlx, ptr->win,
			ptr->images->exit[0], x * PIX + 8, y * PIY + 8);
	}
}

void	map_put(t_ptrs *ptr)
{
	int	y;
	int	x;

	y = 0;
	while (y < ptr->map->y)
	{
		x = 0;
		while (x < ptr->map->x)
		{
			mlx_put_image_to_window(ptr->mlx, ptr->win,
				ptr->images->lay[(LAYER + ptr->bg) % L_CNT], x * PIX, y * PIY);
			if (ptr->map->map[y][x] == 'C')
				mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->images->col
				[2], x * PIX + 20, y * PIY + 20);
			if (ptr->map->map[y][x] == '1' || ptr->map->map[y][x] == 'E' ||
				ptr->map->map[y][x] == 'P' || ptr->map->map[y][x] == 'N')
				position(ptr, x, y, ptr->map->map[y][x]);
			x++;
		}
		y++;
	}
}

void	player_put(t_ptrs *ptr)
{
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->player
	[0].skin[PLAYER + ptr->a_p + ptr->c_p], ptr->player[0].x, ptr->player[0].y);
}
