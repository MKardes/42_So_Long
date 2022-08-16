/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:43:16 by mkardes           #+#    #+#             */
/*   Updated: 2022/08/16 10:12:32 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	change_player(t_ptrs *ptr, int key)
{
	if (key == Z)
		ptr->c_p = 0;
	if (key == X)
		ptr->c_p = 4;
	if (key == C)
		ptr->c_p = 8;
	if (key == V)
		ptr->c_p = 12;
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
	if (key == W || key == S || key == D || key == A
		|| key == U_ || key == D_ || key == R_ || key == L_)
		direction(*ptr, key);
	if (key == B1)
		(*ptr)->bg = 0;
	if (key == B2)
		(*ptr)->bg = 1;
	if (key == B3)
		(*ptr)->bg = 2;
	if (key == B4)
		(*ptr)->bg = 3;
	if (key == B5)
		(*ptr)->bg = 4;
	if (key == B6)
		(*ptr)->bg = 5;
	if (key == O)
		(*ptr)->speed--;
	if (key == P)
		(*ptr)->speed++;
	if (key == Z || key == X || key == C || key == V)
		change_player(*ptr, key);
	return (0);
}

int	main(int ac, char **av)
{
	t_ptrs	*ptr;

	ptr = (t_ptrs *)malloc(sizeof(t_ptrs));
	ptr->images = (t_images *)malloc(sizeof(t_images));
	if (ac != 2)
		return (0);
	start(av, ptr);
	mlx_hook(ptr->win, 2, 1, key_states, &ptr);
	mlx_loop_hook(ptr->mlx, loop, ptr);
	mlx_hook(ptr->win, 17, 0, ft_key_esc, ptr);
	mlx_loop(ptr->mlx);
	return (0);
}
