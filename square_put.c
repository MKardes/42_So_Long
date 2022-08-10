/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_put.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 17:28:21 by mkardes           #+#    #+#             */
/*   Updated: 2022/08/10 20:45:28 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	square_put(t_ptrs *ptr, int color, int x, int u)
{
	int	i;
	int	j;

	i = 0;
	while (i < 15)
	{
		j = u;
		while (j < x)
		{
			mlx_pixel_put(ptr->mlx, ptr->win, j, i, color);
			j++;
		}
		i++;
	}
}
