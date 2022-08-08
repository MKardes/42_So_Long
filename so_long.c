/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:43:16 by mkardes           #+#    #+#             */
/*   Updated: 2022/08/08 12:58:38 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	clear_f(t_ptrs *ptr)
{
	usleep(1000000);
	mlx_clear_window(ptr->mlx, ptr->win);
	return (0);
}

int	coin_func(t_ptrs *ptr)
{
	ptr->player->skin=ptr->images->play;
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->images->col[ptr->i], 100, 100);
    mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->player->skin[ptr->i], 200, 200);
	ptr->i++;
    usleep(400000);
    if (ptr->i == 4)
        ptr->i = 0;
    return (0);
}

int	ft_key_esc(t_ptrs *ptr)
{
	mlx_destroy_window((*ptr).mlx, (*ptr).win);
	exit(0);
}

int	key_states(int key, t_ptrs **ptr)
{
	if (key == ESC)
		ft_key_esc(*ptr);
	if (key == W)
	{
		#undef LAYER
		#define LAYER 2
		ft_printf("first: %d\n",LAYER);
		return (0);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_ptrs	*ptr;

	ptr = (t_ptrs *)malloc(sizeof(t_ptrs));
	ptr-> images = (t_images *)malloc(sizeof(t_images));
	//ptr-> player = (t_player *)malloc(sizeof(t_player));
	if (ac != 2)
		return(0);
	start(av, ptr);
	mlx_key_hook(ptr->win, key_states, &ptr);
	mlx_loop_hook(ptr->mlx, loop, ptr);
	mlx_hook(ptr->win, 17, 0, ft_key_esc, ptr);
	mlx_loop(ptr->mlx);
	return (0);
}
