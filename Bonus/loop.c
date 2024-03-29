/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 22:32:36 by mkardes           #+#    #+#             */
/*   Updated: 2022/08/16 00:49:49 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	upgrade(t_ptrs *ptr)
{
	collect_chc(ptr);
	check_door(ptr);
	exit_anim(ptr);
	coin_anim(ptr);
	enemies_anim(ptr);
	anim_speed(ptr);
	enem_check(ptr);
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
