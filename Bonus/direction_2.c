/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 00:40:52 by mkardes           #+#    #+#             */
/*   Updated: 2022/08/16 00:42:17 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_ptrs	*tri_fill(t_tri *tri, t_ptrs *ptr, char a)
{
	if (a == 'W')
	{
		tri->x2 = ptr->player[0].x + 32;
		tri->x3 = ptr->player[0].x + PIX - 32;
		tri->y1 = ptr->player[0].y - PIY + 64;
	}
	else if (a == 'S')
	{
		tri->x2 = ptr->player[0].x + 32;
		tri->x3 = ptr->player[0].x + PIX - 32;
		tri->y1 = ptr->player[0].y + PIY;
	}
	else if (a == 'D')
	{
		tri->x1 = ptr->player[0].x + PIX - 20;
		tri->y2 = ptr->player[0].y + 32;
		tri->y3 = ptr->player[0].y + PIY - 3 - 32;
	}
	else if (a == 'A')
	{
		tri->x1 = ptr->player[0].x - PIX + 60;
		tri->y2 = ptr->player[0].y + 32;
		tri->y3 = ptr->player[0].y + PIY - 32;
	}
	return (ptr);
}
