/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 22:32:36 by mkardes           #+#    #+#             */
/*   Updated: 2022/08/08 17:05:12 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	upgrade(t_ptrs *ptr)
{
	ptr->a = 1;
}

void	draw(t_ptrs *ptr)
{
	map_put(ptr);
	//coin_func(ptr);
}

int	loop(t_ptrs *ptr)
{
	upgrade(ptr);
	draw(ptr);
	return (1);
}
