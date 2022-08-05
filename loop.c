/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 22:32:36 by mkardes           #+#    #+#             */
/*   Updated: 2022/08/05 11:41:19 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start(char **av, t_ptrs *ptr)
{
	if (check_file(av, ptr))
		exit(0);
	ptr->mlx = mlx_init();
	ptr->a = 1;
	ptr->p = 1;
	ptr->i = 0;
	ptr->win = mlx_new_window(ptr->mlx, ptr->map.x * 64, ptr->map.y * 64, "Heyyo");
	image_create(ptr);
}

void	upgrade(t_ptrs *ptr)
{
	ptr->a = 1;
}

void	draw(t_ptrs *ptr)
{
	map_put(ptr);
	asd(*ptr);
	//coin_func(ptr);
}

int	loop(t_ptrs *ptr)
{
	upgrade(ptr);
	draw(ptr);
	return (1);
}
