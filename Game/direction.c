/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 02:43:33 by mkardes           #+#    #+#             */
/*   Updated: 2022/08/16 00:56:07 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	direction_u_continue(t_ptrs *ptr, t_tri tri)
{
	ptr->a_p = 1;
	if (ptr->map->map[tri.y1 / PIY][tri.x2 / PIX] != '1'
			&& ptr->map->map[tri.y1 / PIY][tri.x3 / PIX] != '1')
	{
		ptr->move += 1;
		ft_printf("Move: %d\n", ptr->move);
		ptr->player[0].y -= (SPEED + ptr->speed);
	}
	if (ptr->door_chc == 1 && ptr->map->map[tri.y1 / PIY][tri.x2 / PIX] == 'E'
			&& ptr->map->map[tri.y1 / PIY][tri.x3 / PIX] == 'E')
		exit(0);
}

void	direction_d_continue(t_ptrs *ptr, t_tri tri)
{
	ptr->a_p = 0;
	if (ptr->map->map[tri.y1 / PIY][tri.x2 / PIX] != '1'
			&& ptr->map->map[tri.y1 / PIY][tri.x3 / PIX] != '1')
	{
		ptr->move += 1;
		ft_printf("Move: %d\n", ptr->move);
		ptr->player[0].y += (SPEED + ptr->speed);
	}
	if (ptr->door_chc == 1 && ptr->map->map[tri.y1 / PIY][tri.x2 / PIX] == 'E'
			&& ptr->map->map[tri.y1 / PIY][tri.x3 / PIX] == 'E')
		exit(0);
}

void	direction_r_continue(t_ptrs *ptr, t_tri tri)
{
	ptr->a_p = 3;
	if (ptr->map->map[tri.y2 / PIY][tri.x1 / PIX] != '1' && ptr->map->map
		[tri.y3 / PIY][tri.x1 / PIX] != '1')
	{
		ptr->move += 1;
		ft_printf("Move: %d\n", ptr->move);
		ptr->player[0].x += (SPEED + ptr->speed);
	}
	if (ptr->door_chc == 1 && ptr->map->map[tri.y2 / PIY][tri.x1 / PIX] == 'E'
			&& ptr->map->map[tri.y3 / PIY][tri.x1 / PIX] == 'E')
		exit(0);
}

void	direction_l_continue(t_ptrs *ptr, t_tri tri)
{
	ptr->a_p = 2;
	if (ptr->map->map[tri.y2 / PIY][tri.x1 / PIX] != '1' && ptr->map->map
		[tri.y3 / PIY][tri.x1 / PIX] != '1')
	{
		ptr->move += 1;
		ft_printf("Move: %d\n", ptr->move);
		ptr->player[0].x -= (SPEED + ptr->speed);
	}
	if (ptr->door_chc == 1 && ptr->map->map[tri.y2 / PIY][tri.x1 / PIX] == 'E'
			&& ptr->map->map[tri.y3 / PIY][tri.x1 / PIX] == 'E')
		exit(0);
}

void	direction(t_ptrs *ptr, int key)
{
	t_tri	tri;

	if (key == W)
		direction_u_continue(tri_fill(&tri, ptr, 'W'), tri);
	if (key == S)
		direction_d_continue(tri_fill(&tri, ptr, 'S'), tri);
	if (key == D)
		direction_r_continue(tri_fill(&tri, ptr, 'D'), tri);
	if (key == A)
		direction_l_continue(tri_fill(&tri, ptr, 'A'), tri);
}
