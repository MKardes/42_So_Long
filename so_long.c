/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:43:16 by mkardes           #+#    #+#             */
/*   Updated: 2022/08/04 12:29:22 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>

int	map_create(int fd, t_map *map)
{
	int	i;

	i = 0;
	map -> map = (char **)malloc(sizeof(char *) * 100);
	if (!(map -> map))
		return(0);
	while (i < 100)
	{
		(map -> map) [i] = get_next_line(fd);
		if (!(map -> map) [i])
			break;
		i++;
	}
	map -> y = i;
	close(fd);
	return(1);
}

int	check_file(char **av)
{
	int	fd;
	t_map map;

	if (ft_strncmp((ft_strchr(av[1],'.') + 1), "ber", 4))
		return (1);
	fd = open(av[1],O_RDONLY);
	if (fd == -1)
		return (1);
	if (!map_create(fd, &map))
		return(1);
	if (!map_checker(map))
		return(1);
	return(0);
}

char	*join_2(char *str, int a, char *str2)
{
	char *inte;

	inte = ft_itoa(a);
	str = ft_strjoin(str, inte);
	str = ft_strjoin(str, str2);
	free(inte);
	return (str);
}

void coin_create(t_ptrs ptr, void ***coin)
{
	int		i;
	int		x;
	int		y;
	char	*str;

	x = 100;
	y = 100;
	i = 1;
	(*coin) = (void **)malloc(sizeof(char*) * 10);
	while (i <= 9)
	{
		str = join_2("Scripts/Coin/", i, ".xpm");
		ft_printf("%s\n",str);
		(*coin)[i] = mlx_xpm_file_to_image(&(ptr.mlx), str, &x, &y);
		free(str);
		i++;
	}
(*coin)[10] = mlx_xpm_file_to_image(&(ptr.mlx), "Scripts/0/0.xpm", &x, &y);
}

int	clear_f(t_ptrs *ptr)
{
	usleep(1000000);
	mlx_clear_window(ptr->mlx, ptr->win);
	return (0);
}

int	coin_func(t_ptrs *ptr)
{
	
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->coin[ptr->i], 100, 100);
	usleep(40000);
	ptr->i++;
	if (ptr->i == 10)
		ptr->i = 1;
	/*
	int i;
	int j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->coin[10], i * 64, i * 64);
			j++;
		}
		i++;
	}*/
	return (0);
}

void	start(char **av)
{
	if (check_file(av))
	{
		ft_printf("Error\n");
		exit(0);
	}
}

void	upgrade(t_ptrs ptr)
{
	(void)ptr;
}

void	asd(t_ptrs ptr)
{
	int i;
    int j;

    i = 0;
	ft_printf("asd\n");
    while (i < 10)
    {
        j = 0;
        while (j < 10)
        {
            mlx_put_image_to_window(ptr.mlx, ptr.win, ptr.coin[10], i * 64,j * 64);
            j++;
        }
        i++;
    }
}

void    draw(t_ptrs ptr)
{
    ptr.x = 0;
    ptr.y = 0;
    ptr.a = 1;
	ptr.i = 1;
    ptr.win = mlx_new_window(ptr.mlx, 1000, 1000, "Heyyo");
    coin_create(ptr, &(ptr.coin));
	//coin_func(ptr);
	asd(ptr);
	ft_printf("a\n");
    mlx_loop_hook(ptr.mlx, coin_func, &ptr);
	ft_printf("b\n");
	//mlx_loop_hook(ptr.mlx, clear_f, &ptr);
}

int	ft_key_esc(t_ptrs *ptr)
{
	ft_printf("a\n");
	mlx_destroy_window((*ptr).mlx, (*ptr).win);
	exit(0);
}

int	main(int ac, char **av)
{
	t_ptrs	ptr;

	if (ac != 2)
		return(0);
	ptr.mlx = mlx_init();
	start(av);
	upgrade(ptr);
	draw(ptr);
	//mlx_hook(ptr.win, 17, 0, ft_key_esc, &ptr);
	mlx_loop(ptr.mlx);
	return (0);
}
