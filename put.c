/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 22:32:18 by mkardes           #+#    #+#             */
/*   Updated: 2022/08/07 18:45:45 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	anim_position(t_player *stuff)
{}

void	position(t_ptrs *ptr, int x, int y, char c)
{
	if (c == '1')
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->images->wall[WALL], x * p_x, y * p_y);
	if (c == 'E')
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->images->exit[EXIT], x * p_x, y * p_y);
	if (c == 'P')
	{
		ptr->player->x = x * p_x;
		ptr->player->y = y * p_y;
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->player->skin[PLAYER], ptr->player->x, ptr->player->y);
	}
}

void	bg_put(t_ptrs *ptr)
{
	int		y;
	int		x;
	
	y = 0;
	ft_printf("put: %d\n",LAYER);
	while (y < ptr->map.y)
	{
		x = 0;
		while (x < ptr->map.x)
		{
			mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->images->lay[LAYER], x * p_x, y * p_y);
			if (ptr->map.map[y][x] == '1' || ptr->map.map[y][x] == 'E' ||
				ptr->map.map[y][x] == 'P'|| ptr->map.map[y][x] == 'N')
				position(ptr, x, y, ptr->map.map[y][x]);
			x++;
		}
		y++;
	}
}

void	map_put(t_ptrs *ptr)
{
	bg_put(ptr);
}
