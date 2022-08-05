#include "so_long.h"

int	ft_error(char *str)
{
	ft_printf("Error\n%s\n", str);
	return (0);
}

int map_create(int fd, t_map *map)
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

int check_file(char **av, t_ptrs *ptr)
{
	int		fd;
	t_map	map;

	if (ft_strncmp((ft_strchr(av[1],'.') + 1), "ber", 4))
		return (1);
	fd = open(av[1],O_RDONLY);
	if (fd == -1)
		return (1);
	if (!map_create(fd, &map))
		return(1);
	if (!map_checker(&map))
		return(1);
	(*ptr).map = map;
	return(0);
}
