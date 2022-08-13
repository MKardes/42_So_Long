/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 22:32:36 by mkardes           #+#    #+#             */
/*   Updated: 2022/08/13 02:37:56 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	upgrade(t_ptrs *ptr)
{
	collect_chc(ptr);
	check_door(ptr);
	if (ptr->door_chc == 1)
		ptr->a_x = (ptr->a_x + 1) % X_CNT;
	if (ptr->cycle % COIN_ANIM == 0)
		ptr->a_c = (ptr->a_c + 1) % C_CNT;
	ptr->cycle++;
	if (ptr->cycle == 10000)
		ptr->cycle = 0;
}

void	draw(t_ptrs *ptr)
{
	map_put(ptr);
	player_put(ptr);
	enemy_put(ptr);
	move_count_put(ptr);
}

int	loop(t_ptrs *ptr)
{
	upgrade(ptr);
	draw(ptr);
	return (1);
}
