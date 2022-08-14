/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chcs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 12:24:30 by mkardes           #+#    #+#             */
/*   Updated: 2022/08/14 17:46:30 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enem_chc(t_ptrs *ptr)
{
	int	i;
	int	p_x;
	int	p_y;

	p_x = ptr->player[0].x;
	p_y = ptr->player[0].y;
	i = 0;
	ft_printf("asdasdasdasd\n");
	while (i < ptr->map->n)
	{
		if (ptr->player[i + 1].x >= p_x && ptr->player[i + 1].y >= p_y)// player sol üstte
		{
			if (ptr->player[i + 1].x >= p_x && ptr->player[i + 1].x - 24 <= p_x && ptr->player[i + 1].y >= p_y && ptr->player[i + 1].y - 54 <= p_y)
				ft_printf(".\n");
				//exit(0);
		}
		else if (ptr->player[i + 1].x >= p_x && ptr->player[i + 1].y <= p_y)// player sol altta
		{
			if (ptr->player[i + 1].x >= p_x && ptr->player[i + 1].x - 24 <= p_x && ptr->player[i + 1].y <= p_y && ptr->player[i + 1].y + 64 >= p_y)
				ft_printf(",\n");
                //exit(0);
		}
		else if (ptr->player[i + 1].x < p_x && ptr->player[i + 1].y > p_y)// player sağ üstte
		{
			if (ptr->player[i + 1].x <= p_x && ptr->player[i + 1].x + 24 >= p_x && ptr->player[i + 1].y >= p_y && ptr->player[i + 1].y - 64 <= p_y)
                ft_printf(",\n");
		}
		else if (ptr->player[i + 1].x < p_x && ptr->player[i + 1].y < p_y)// player sağ altta
		{
			if (ptr->player[i + 1].x <= p_x && ptr->player[i + 1].x + 24 >= p_x && ptr->player[i + 1].y <= p_y && ptr->player[i + 1].y + 64 >= p_y)
                ft_printf(",\n");
		}
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
