/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 22:32:36 by mkardes           #+#    #+#             */
/*   Updated: 2022/08/11 17:04:54 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	upgrade(t_ptrs *ptr)
{
	collect_chc(ptr);
	ptr->a_e = (ptr->a_e + 1) % X_CNT;
	ptr->a_c = (ptr->a_c + 1) % C_CNT;
	usleep(ANIM_SPEED);
}

void	draw(t_ptrs *ptr)
{
	map_put(ptr);
	mvable_put(ptr);
	move_count_put(ptr);
}

int	loop(t_ptrs *ptr)
{
	upgrade(ptr);
	//usleep(ANIM_SPEED);
	draw(ptr);
	//usleep(ANIM_SPEED);
	return (1);
}
