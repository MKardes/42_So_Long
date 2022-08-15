/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chcs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 12:24:30 by mkardes           #+#    #+#             */
/*   Updated: 2022/08/16 01:04:04 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	chc_continue(t_ptrs *ptr, int i, int p_x, int p_y)
{
	if (ptr->player[i + 1].x >= p_x && ptr->player[i + 1].y <= p_y)
	{
		if (ptr->player[i + 1].x >= p_x && ptr->player[i + 1].x - 24
			<= p_x && ptr->player[i + 1].y <= p_y && ptr->player
			[i + 1].y + 60 >= p_y)
			exit(0);
	}
	else if (ptr->player[i + 1].x < p_x && ptr->player[i + 1].y > p_y)
	{
		if (ptr->player[i + 1].x <= p_x && ptr->player[i + 1].x + 24
			>= p_x && ptr->player[i + 1].y >= p_y && ptr->player
			[i + 1].y - 55 <= p_y)
			exit(0);
	}
	else if (ptr->player[i + 1].x < p_x && ptr->player[i + 1].y < p_y)
	{
		if (ptr->player[i + 1].x <= p_x && ptr->player[i + 1].x + 24
			>= p_x && ptr->player[i + 1].y <= p_y && ptr->player
			[i + 1].y + 60 >= p_y)
			exit(0);
	}
}

void	enem_check(t_ptrs *ptr)
{
	int	i;
	int	p_x;
	int	p_y;

	p_x = ptr->player[0].x;
	p_y = ptr->player[0].y;
	i = 0;
	while (i < ptr->map->n)
	{
		if (ptr->player[i + 1].x >= p_x && ptr->player[i + 1].y >= p_y)
		{
			if (ptr->player[i + 1].x >= p_x && ptr->player[i + 1].x - 24
				<= p_x && ptr->player[i + 1].y >= p_y && ptr->player
				[i + 1].y - 55 <= p_y)
				exit(0);
		}
		else
			chc_continue(ptr, i, p_x, p_y);
		i++;
	}
}

void	collect_chc(t_ptrs *ptr)
{
	if (ptr->map->map[(ptr->player[0].y / PIY)]
		[(ptr->player[0].x / PIX)] == 'C')
	{
		ptr->map->map[(ptr->player[0].y / PIY)][(ptr->player[0].x / PIX)] = '0';
	}
}

int	chc(t_ptrs *ptr)
{
	int	x;
	int	y;

	y = 0;
	while (y < ptr->map->y)
	{
		x = 0;
		while (x < ptr->map->x)
		{
			if (ptr->map->map[y][x] == 'C')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	check_door(t_ptrs *ptr)
{
	if (chc(ptr))
		ptr->door_chc = 1;
}	
