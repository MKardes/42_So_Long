/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 15:10:46 by mkardes           #+#    #+#             */
/*   Updated: 2022/08/14 16:33:02 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemies_anim(t_ptrs *ptr)
{
	int	i;

	i = 0;
	while (i < ptr->map->n)
	{
		if (ptr->a_e[i] == 1 && ptr->map->map[ptr->player[i + 1].y / PIY][(ptr->player[i + 1].x + 52) / PIX] != '1')
			ptr->player[i + 1].x += SPEED + ptr->speed;
		else if (ptr->a_e[i] == 0 && ptr->map->map[ptr->player[i + 1].y / PIY][ptr->player[i + 1].x / PIX] != '1')
			ptr->player[i + 1].x -= SPEED + ptr->speed;
		else
		{
			if (ptr->a_e[i] == 0)
			{
				ptr->a_e[i] = 1;
				ptr->player[i + 1].x += (SPEED + ptr->speed);
			}
			else if (ptr->a_e[i] == 1)
			{
				ptr->a_e[i] = 0;
				ptr->player[i + 1].x -= (SPEED + ptr->speed); 
			}
		}
		i++;
	}
}

void	exit_anim(t_ptrs *ptr)
{
	if (ptr->door_chc == 1 && ptr->cycle % EXIT_ANIM == 0)
		ptr->a_x = (ptr->a_x + 1) % X_CNT;
}

void	coin_anim(t_ptrs *ptr)
{
	if (ptr->cycle % COIN_ANIM == 0)
		ptr->a_c = (ptr->a_c + 1) % C_CNT;
}

void	anim_speed(t_ptrs *ptr)
{
	ptr->cycle++;
	if (ptr->cycle == 10000)
		ptr->cycle = 0;
}
