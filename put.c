/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 22:32:18 by mkardes           #+#    #+#             */
/*   Updated: 2022/08/10 21:24:21 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	position(t_ptrs *ptr, int x, int y, char c)
{
	if (c == '1')
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->images->wall[(WALL + ptr->bg) % W_CNT], x * PIX, y * PIY);
	if (c == 'E')
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->images->exit[EXIT], x * PIX, y * PIY);
}

void	map_put(t_ptrs *ptr)
{
	int		y;
	int		x;
	
	y = 0;
	while (y < ptr->map->y)
	{
		x = 0;
		while (x < ptr->map->x)
		{
			mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->images->lay[(LAYER + ptr->bg) % L_CNT], x * PIX, y * PIY);
			if (ptr->map->map[y][x] == '1' || ptr->map->map[y][x] == 'E' ||
				ptr->map->map[y][x] == 'P'|| ptr->map->map[y][x] == 'N')
				position(ptr, x, y, ptr->map->map[y][x]);
			x++;
		}
		y++;
	}
}

void	mvable_put(t_ptrs *ptr)
{
	int	i;

	i = 0;
	while (i < ptr->mv_cnt)
	{
		ft_printf("%d. -> x: %d  y: %d\n",i, ptr->player[i].x, ptr->player[i].y);
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->player[i].skin[0],
				ptr->player[i].x, ptr->player[i].y);
		i++;
	}
}

void	move_count_put(t_ptrs *ptr)
{
	char	*num;
	char	*str;
	char	*str1;

	str = ft_strdup("Move: ");
	num = ft_itoa(ptr->move);
	str1 = ft_strjoin(str, num);
	free(str);
	free(num);
	ft_printf("%d\n",ptr->x);
	square_put(ptr, 0x00000000, 75, 0);
	mlx_string_put(ptr->mlx, ptr->win, 4, 10, 0x00FF0000, str1);
	free(str1);
	str = ft_strdup("Speed: ");
	num = ft_itoa(SPEED + ptr->speed);
	str1 = ft_strjoin(str, num);
	free(str);
	free(num);
	square_put(ptr, 0x00000000, ptr->map->x * PIX, (ptr->map->x * PIX) - 75);
    mlx_string_put(ptr->mlx, ptr->win, (ptr->map->x * PIX) - 71, 10, 0x00FF0000, str1);
	free(str1);
}

