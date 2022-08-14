/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 02:43:33 by mkardes           #+#    #+#             */
/*   Updated: 2022/08/14 16:41:13 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	direction_ud_continue(t_ptrs *ptr, int key, int n_y, int p_y)
{
	if (key == W || key == U_)
	{
		ptr->a_p = 1;
		if (ptr->map->map[n_y][ptr->player[0].x / PIX] != '1')
		{
			ptr->move += 1;
			ptr->player[0].y -= (SPEED + ptr->speed);
		}
	}
	if (key == S || key == D_)
	{
		ptr->a_p = 0;
		if (ptr->map->map[p_y][ptr->player[0].x / PIX] != '1')
		{
			ptr->move += 1;
			ptr->player[0].y += (SPEED + ptr->speed);
		}
	}
}

void	direction_rl_continue(t_ptrs *ptr, int key, int n_x, int p_x)
{
	if (key == D || key == R_)
	{
		ptr->a_p = 3;
		if (ptr->map->map[ptr->player[0].y / PIY][p_x] != '1')
		{
			ptr->move += 1;
			ptr->player[0].x += (SPEED + ptr->speed);
		}
	}
	if (key == A || key == L_)
	{
		ptr->a_p = 2;
		if (ptr->map->map[ptr->player[0].y / PIY][n_x] != '1')
		{
			ptr->move += 1;
			ptr->player[0].x -= (SPEED + ptr->speed);
		}
	}
}

void	direction(t_ptrs *ptr, int key)
{
	int	n_y;
	int	p_y;
	int	n_x;
	int	p_x;

	n_x = (ptr->player[0].x - (SPEED + ptr->speed)) / PIX;
	p_x = (ptr->player[0].x + (SPEED + ptr->speed)) / PIX;
	n_y = (ptr->player[0].y - (SPEED + ptr->speed)) / PIY;
	p_y = (ptr->player[0].y + (SPEED + ptr->speed)) / PIY;
	direction_ud_continue(ptr, key, n_y, p_y);
	direction_rl_continue(ptr, key, n_x, p_x);
}
