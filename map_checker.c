/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 12:15:51 by mkardes           #+#    #+#             */
/*   Updated: 2022/08/08 12:33:04 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	continue_func(t_map map)
{
	if (map.e > 0 && map.c > 0 && map.n > 0 && map.p == 1)
		return (1);
	else if (map.p > 1)
		return (ft_error("Birden çok başlama noktası!"));
	return (ft_error("Harita eksik!"));
}

int	all_check(t_map map)
{
	int	i;
	int	j;

	i = 1;
	while (i < map.y - 1)
	{
		j = 1;
		while (j < map.x - 1)
		{
			if (map.map[i][j] == 'E')
				map.e += 1;
			else if (map.map[i][j] == 'C')
				map.c += 1;
			else if (map.map[i][j] == 'P')
				map.p += 1;
			else if (map.map[i][j] == 'N')
				map.n += 1;
			else if (map.map[i][j] != '0' && map.map[i][j] != '1')
				return (ft_error("Yabancı karakter!"));
			j++;
		}
		i++;
	}
	return (continue_func(map));
}

int	left_right_check(t_map map)
{
	int	i;

	i = 1;
	while (i < map.y - 1)
	{
		if (map.map[i][0] != '1' || map.map[i][map.x - 1] != '1')
			return (ft_error("Duvarla kaplı değil!"));
		i++;
	}
	return (1);
}

int	top_bot_check(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] != '1')
			return (ft_error("Duvarla kaplı değil!"));
		i++;
	}
	return (1);
}

int	map_checker(t_map *map)
{
	int	i;
	int	j;

	j = 0;
	map->x = 0;
	map->e = 0;
	map->c = 0;
	while (j < map->y - 1)
	{
		i = 0;
		while ((*map).map[j][i] != '\n' && (*map).map[j][i] != '\0')
			i++;
		if (map->x != 0 && map->x != i)
		{
			ft_error("Harita dikdörtgen değil.");
			return (map_free(*map));
		}
		map->x = i;
		j++;
	}
	if (!top_bot_check(map->map[0]) || !top_bot_check((*map).map[map->y - 1])
		|| !left_right_check(*map) || !left_right_check(*map)
		|| !all_check(*map))
		return (map_free(*map));
	return (1);
}
