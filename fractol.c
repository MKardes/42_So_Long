/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:43:16 by mkardes           #+#    #+#             */
/*   Updated: 2022/07/23 18:25:06 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	cl_info(t_ptrs *ptr)
{
	int	x;
	int	y;

	y = 960;
	while (y <= 1000)
	{
		x = 0;
		while (x <= 100)
		{
			mlx_pixel_put(ptr->mlx ,ptr->win, x, y, 0x00000000);
			x++;
		}
		y++;
	}
	return (0);
}

int	info(t_ptrs *ptr)
{
	char	*x;
	char	*y;

	x = ft_itoa(ptr->x);
	y = ft_itoa(ptr->y);
	cl_info(ptr);
	mlx_string_put(ptr->mlx, ptr->win, 5, 975, 0x0000FF00, "x:");
	mlx_string_put(ptr->mlx, ptr->win, 20, 975, 0x0000FF00, x);
	mlx_string_put(ptr->mlx, ptr->win, 5, 985, 0x0000FF00, "y:");
    mlx_string_put(ptr->mlx, ptr->win, 20, 985, 0x0000FF00, y);
	free(y);
	free(x);
	return (0);
}

int	direction(t_ptrs *ptr, char type)
{
	int	x;
	int	y;

	if (type == '>')
        ptr->x += 110;
    if (type == '<')
        ptr->x -= 110;
	if (type == 'u')
		ptr->y -= 20;
	if (type == 'd')
		ptr->y += 20;
	if (type == 'W')
	{
        ptr->x += 110;
		ptr->y -= 20;
	}
	if (type == 'S')
    {
        ptr->x += 110;
        ptr->y += 20;
    }
	if (type == 'A')
    {
        ptr->x -= 110;
        ptr->y += 20;
    }
	if (type == 'Q')
    {
        ptr->x -= 110;
        ptr->y -= 20;
    }
	y = ptr->y;
	while (y <= ptr->y + 10)
	{
		x = ptr-> x;
		while (x <= ptr->x + 100)
		{
			mlx_pixel_put(ptr->mlx ,ptr->win, x, y, 0x0000FF00);
			x++;
		}
		y++;
	}
	return (0);
}

int	m_exit(int keycode, t_ptrs *rs)
{
	if(keycode == 124)
	{
		mlx_destroy_window(rs->mlx, rs->win);
		exit(0);
		return (1);
	}
	return(0);
}

int	m_close(int keycode, t_ptrs *ptr)
{
	info(ptr);
	if (keycode == 53)
	{
		mlx_destroy_window(ptr->mlx, ptr->win);
	}
	if (keycode == 123)
		direction(ptr, '<');
	if (keycode == 124)
		direction(ptr, '>');
	if (keycode == 125)
		direction(ptr, 'd');
	if (keycode == 126)
		direction(ptr, 'u');
	if (keycode == 12)
        direction(ptr, 'Q');
    if (keycode == 13)
        direction(ptr, 'W');
    if (keycode == 0)
        direction(ptr, 'A');
    if (keycode == 1)
        direction(ptr, 'S');
	if (keycode == 51)
		mlx_clear_window(ptr->mlx, ptr->win);
	return (0);
}

int	main(int ac, char **av)
{
	t_ptrs	ptr;

	(void)av;
	(void)ac;
	ptr.x = 0;
	ptr.y = 0;
	ptr.a = 1;
	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, 1000, 1000, "Heyyo");
	mlx_hook(ptr.win, 2, 0, m_close, &ptr);
	mlx_hook(ptr.win, 17, 0, m_exit, &ptr);
	mlx_loop(ptr.mlx);
	return (0);
}
