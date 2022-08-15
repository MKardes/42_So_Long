/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 02:34:26 by mkardes           #+#    #+#             */
/*   Updated: 2022/08/13 02:43:19 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	map_free(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->y)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	return (0);
}

int	ft_error(char *str)
{
	ft_printf("Error\n%s\n", str);
	return (0);
}

int	map_create(int fd, t_map *map)
{
	int	i;

	i = 0;
	map -> map = (char **)malloc(sizeof(char *) * 100);
	if (!(map -> map))
		return (0);
	while (i < 100)
	{
		map->map[i] = get_next_line(fd);
		if (!map->map[i])
			break ;
		i++;
	}
	map -> y = i;
	close(fd);
	return (1);
}

int	check_file(char **av, t_ptrs *ptr)
{
	int		fd;
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	map->p = 0;
	map->n = 0;
	if (ft_strncmp((ft_strchr(av[1], '.') + 1), "ber", 4))
		return (!ft_error("Yanlış dosya türü!"));
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (!ft_error("Dosya mevcut değil!"));
	if (!map_create(fd, map))
		return (1);
	if (!map_checker(map))
		return (1);
	ptr->map = map;
	return (0);
}
