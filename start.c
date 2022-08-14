/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 02:00:20 by mkardes           #+#    #+#             */
/*   Updated: 2022/08/14 15:04:09 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	anim_position(t_player *stuff, int x, int y, t_ptrs *ptr)
{
	stuff->x = x * PIX;
	stuff->y = y * PIY;
	if (ptr->map->map[y][x] == 'P')
		stuff->skin = ptr->images->play;
	else
		stuff->skin = ptr->images->enem;
}

void	start_movable(t_ptrs *ptr)
{
	int	y;
	int	x;

	y = 0;
	ptr->mv_cnt = 1;
	ptr->player = (t_player *)malloc(sizeof(t_player) * (1 + ptr->map->n));
	while (y < ptr->map->y)
	{
		x = 0;
		while (x < ptr->map->x)
		{
			if (ptr->map->map[y][x] == 'P')
				anim_position(&(ptr->player[0]), x, y, ptr);
			else if (ptr->map->map[y][x] == 'N')
			{
				anim_position(&(ptr->player[ptr->mv_cnt]), x, y, ptr);
				ptr->a_e[ptr->mv_cnt] = ptr->mv_cnt % 2;
				ptr->mv_cnt++;
			}
			x++;
		}
		y++;
	}
	ptr->mv_cnt--;
}

void	start(char **av, t_ptrs *ptr)
{
	int	i;

	if (check_file(av, ptr))
		exit(0);
	ptr->mlx = mlx_init();
	ptr->a = 1;
	ptr->p = 1;
	ptr->anim = 0;
	ptr->move = 0;
	ptr->bg = 0;
	ptr->c_p = 0;
	ptr->a_p = 0;
	ptr->a_x = 0;
	ptr->a_c = 0;
	ptr->speed = 0;
	ptr->door_chc = 0;
	ptr->cycle = 0;
	ptr->win = mlx_new_window(ptr->mlx, ptr->map->x * PIX,
			ptr->map->y * PIY, "Heyyo");
	ptr->a_e = (int *)malloc(sizeof(int) * ptr->map->n);
	i = -1;
	while (++i < ptr->map->n)
		ptr->a_e[i] = 0;
	image_create(ptr);
	start_movable(ptr);
}
