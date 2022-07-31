/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:43:16 by mkardes           #+#    #+#             */
/*   Updated: 2022/07/31 18:10:18 by mkardes          ###   ########.fr       */
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
	(*coin) = (void **)malloc(sizeof(char*) * 9);
	while (i <= 9)
	{
		str = join_2("./", i, ".xpm");
		ft_printf("%s\n",str);
		(*coin)[i] = mlx_xpm_file_to_image(&(ptr.mlx), str, &x, &y);
		free(str);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_ptrs	ptr;
	void	**coin;
	int		i;

	if (ac == 2)
	{
		if (check_file(av))
		{
			ft_printf("Error\n");
			exit(0);
		}
		ptr.x = 0;
		ptr.y = 0;
		ptr.a = 1;
		ptr.mlx = mlx_init();
		ptr.win = mlx_new_window(ptr.mlx, 1000, 1000, "Heyyo");
		ptr.image = mlx_new_image (ptr.mlx, 100, 100);
		ft_printf("44\n");
		coin_create(ptr, &coin);
		i = 1;
		while (i <= 9)
		{
			ft_printf("1\n");
			mlx_put_image_to_window(ptr.mlx, ptr.win, coin[i], 100, 100);
			ft_printf("2\n");
			usleep(1000000);
			mlx_destroy_image (ptr.mlx, coin[i]);
			ft_printf("3\n");
			i++;
			ft_printf("4\n");
		}
		mlx_loop(ptr.mlx);
	}
	return (0);
}
