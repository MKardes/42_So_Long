/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:43:16 by mkardes           #+#    #+#             */
/*   Updated: 2022/08/05 10:41:51 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image_allocation(t_ptrs *ptr)
{
	(*ptr).images->i = (int *)malloc(sizeof(int) * 4);
	(*ptr).images->i[0] = L_CNT;
    (*ptr).images->i[1] = W_CNT;
    (*ptr).images->i[2] = P_CNT;
    (*ptr).images->i[3] = X_CNT;
	(*ptr).images->i[4] = E_CNT;
	(*ptr).images->i[5] = C_CNT;
	(*ptr).images->lay = (void **)malloc(sizeof(void*) * (*ptr).images->i[0]);
	(*ptr).images->wall = (void **)malloc(sizeof(void*) * (*ptr).images->i[1]);
	(*ptr).images->play = (void **)malloc(sizeof(void*) * (*ptr).images->i[2]);
	(*ptr).images->exit = (void **)malloc(sizeof(void*) * (*ptr).images->i[3]);
	(*ptr).images->enem = (void **)malloc(sizeof(void*) * (*ptr).images->i[4]);
	(*ptr).images->col = (void **)malloc(sizeof(void*) * (*ptr).images->i[5]);
}

char	*join_2(char *str,int a, int b, char *str2)
{
	char *inte;

	inte = ft_itoa(a);
	str = ft_strjoin(str, inte);
	str = ft_strjoin(str, "/");
	inte = ft_itoa(b);
	str = ft_strjoin(str, inte);
	str = ft_strjoin(str, str2);
	free(inte);
	return (str);
}

void	open_image(t_ptrs *ptr, int i, int j)
{
	if (i == 0)
		ptr->images->lay[j] = mlx_xpm_file_to_image(&(ptr->mlx), ptr->images->str, &(ptr->images->x), &(ptr->images->y));
	else if (i == 1)
		ptr->images->wall[j] = mlx_xpm_file_to_image(&(ptr->mlx), ptr->images->str, &(ptr->images->x), &(ptr->images->y));
	else if (i == 2)
        ptr->images->play[j] = mlx_xpm_file_to_image(&(ptr->mlx), ptr->images->str, &(ptr->images->x), &(ptr->images->y));
	else if (i == 3)
        ptr->images->exit[j] = mlx_xpm_file_to_image(&(ptr->mlx), ptr->images->str, &(ptr->images->x), &(ptr->images->y));
	else if (i == 4)
        ptr->images->enem[j] = mlx_xpm_file_to_image(&(ptr->mlx), ptr->images->str, &(ptr->images->x), &(ptr->images->y));
	else if (i == 5)
        ptr->images->col[j] = mlx_xpm_file_to_image(&(ptr->mlx), ptr->images->str, &(ptr->images->x), &(ptr->images->y));
}

void image_create(t_ptrs *ptr)
{
	int			i;
	int			j;

	ptr->images->x = 45;
	ptr->images->y = 55;
	i = 0;
	image_allocation(ptr);
	while (i <= 5)
	{
		j = 0;
		while (j < ptr->images->i[i])
		{
			ptr->images->str = join_2("Scripts/", i, j, ".xpm");
			ft_printf("%s\n",ptr->images->str);
			open_image(ptr, i, j);
			free(ptr->images->str);
			j++;
		}
		i++;
	}
}

int	clear_f(t_ptrs *ptr)
{
	usleep(1000000);
	mlx_clear_window(ptr->mlx, ptr->win);
	return (0);
}

int	coin_func(t_ptrs *ptr)
{
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->images->col[ptr->i], 100, 100);
    mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->images->play[ptr->i], 200, 200);
    ptr->i++;
    usleep(100000);
    if (ptr->i == 5)
        ptr->i = 0;
    return (0);

	ptr->i++;
	usleep(40000);
	if (ptr->i == 9)
		ptr->i = 0;
	return (0);
}

void	asd(t_ptrs ptr)
{
	int i;
    int j;

    i = 0;
    while (i < ptr.map.y)
    {
        j = 0;
        while (j < ptr.map.x)
        {
			if (i == 0 || i == ptr.map.y - 1 || j == 0 || j == ptr.map.x - 1)
                mlx_put_image_to_window(ptr.mlx, ptr.win, ptr.images->wall[WALL], j * 64,i * 64);
            j++;
        }
        i++;
    }
}

int	ft_key_esc(t_ptrs *ptr)
{
	mlx_destroy_window((*ptr).mlx, (*ptr).win);
	exit(0);
}

int	key_states(int key, t_ptrs **ptr)
{
	if (key == ESC)
		ft_key_esc(*ptr);
	return (0);
}

int	main(int ac, char **av)
{
	t_ptrs	*ptr;

	ptr = (t_ptrs *)malloc(sizeof(t_ptrs));
	ptr-> images = (t_images *)malloc(sizeof(t_images));
	if (ac != 2)
		return(0);
	start(av, ptr);
	mlx_key_hook(ptr->win, key_states, &ptr);
	mlx_loop_hook(ptr->mlx, loop, ptr);
	mlx_hook(ptr->win, 17, 0, ft_key_esc, ptr);
	mlx_loop(ptr->mlx);
	return (0);
}
