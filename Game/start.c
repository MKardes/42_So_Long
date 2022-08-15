/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 02:00:20 by mkardes           #+#    #+#             */
/*   Updated: 2022/08/15 12:22:02 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_movable(t_ptrs *ptr)
{
	int	y;
	int	x;

	y = 0;
	ptr->player = (t_player *)malloc(sizeof(t_player));
	while (y < ptr->map->y)
	{
		x = 0;
		while (x < ptr->map->x)
		{
			if (ptr->map->map[y][x] == 'P')
			{
				ptr->player[0].x = x * PIX;
				ptr->player[0].y = y * PIY;
				ptr->player[0].skin = ptr->images->play;
			}
			x++;
		}
		y++;
	}
}

void	start(char **av, t_ptrs *ptr)
{
	if (check_file(av, ptr))
		exit(0);
	ptr->mlx = mlx_init();
	ptr->a = 1;
	ptr->p = 1;
	ptr->anim = 0;
	ptr->move = 0;
	ptr->bg = 0;
	ptr->a_p = 0;
	ptr->speed = 0;
	ptr->door_chc = 0;
	ptr->cycle = 0;
	ptr->win = mlx_new_window(ptr->mlx, ptr->map->x * PIX,
			ptr->map->y * PIY, "So Long");
	image_create(ptr);
	start_movable(ptr);
}
