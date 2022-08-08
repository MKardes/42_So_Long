/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 22:32:18 by mkardes           #+#    #+#             */
/*   Updated: 2022/08/08 17:56:28 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	position(t_ptrs *ptr, int x, int y, char c)
{
	if (c == '1')
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->images->wall[WALL], x * p_x, y * p_y);
	if (c == 'E')
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->images->exit[EXIT], x * p_x, y * p_y);
}

void	background_put(t_ptrs *ptr)
{
	int		y;
	int		x;
	
	y = 0;
	while (y < ptr->map->y)
	{
		x = 0;
		while (x < ptr->map->x)
		{
			mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->images->lay[LAYER], x * p_x, y * p_y);
			if (ptr->map->map[y][x] == '1' || ptr->map->map[y][x] == 'E' ||
				ptr->map->map[y][x] == 'P'|| ptr->map->map[y][x] == 'N')
				position(ptr, x, y, ptr->map->map[y][x]);
			x++;
		}
		y++;
	}
}

void	mvable_put(t_ptrs *ptr)
{
	int	i;

	i = 0;
	while (i < ptr->mv_cnt)
	{
		ft_printf("%d. -> x: %d  y: %d\n",i, ptr->player[i].x, ptr->player[i].y);
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->player[i].skin[0],
			ptr->player[i].x * p_x, ptr->player[i].y * p_y);
		i++;
	}
}

void	map_put(t_ptrs *ptr)
{
	background_put(ptr);
	mvable_put(ptr);
}
