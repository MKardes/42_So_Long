/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:46:10 by mkardes           #+#    #+#             */
/*   Updated: 2022/08/15 12:14:06 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image_allocation(t_ptrs *ptr)
{
	(*ptr).images->i = (int *)malloc(sizeof(int) * 6);
	(*ptr).images->i[0] = L_CNT;
	(*ptr).images->i[1] = W_CNT;
	(*ptr).images->i[2] = P_CNT;
	(*ptr).images->i[3] = X_CNT + 1;
	(*ptr).images->i[4] = E_CNT;
	(*ptr).images->i[5] = C_CNT;
	(*ptr).images->lay = (void **)malloc(sizeof(void *) * (*ptr).images->i[0]);
	(*ptr).images->wall = (void **)malloc(sizeof(void *) * (*ptr).images->i[1]);
	(*ptr).images->play = (void **)malloc(sizeof(void *) * (*ptr).images->i[2]);
	(*ptr).images->exit = (void **)malloc(sizeof(void *) * (*ptr).images->i[3]);
	(*ptr).images->enem = (void **)malloc(sizeof(void *) * (*ptr).images->i[4]);
	(*ptr).images->col = (void **)malloc(sizeof(void *) * (*ptr).images->i[5]);
}

char	*join_2(char *str, int a, int b, char *str2)
{
	char	*inte;
	char	*str1;
	char	*str3;
	char	*str4;
	char	*str5;

	inte = ft_itoa(a);
	str1 = ft_strjoin(str, inte);
	str3 = ft_strjoin(str1, "/");
	free(inte);
	inte = ft_itoa(b);
	str4 = ft_strjoin(str3, inte);
	str5 = ft_strjoin(str4, str2);
	free(inte);
	free(str1);
	free(str3);
	free(str4);
	return (str5);
}

void	open_image(t_ptrs *ptr, int i, int j)
{
	if (i == 0)
		ptr->images->lay[j] = mlx_xpm_file_to_image(&(ptr->mlx),
				ptr->images->str, &(ptr->images->x), &(ptr->images->y));
	else if (i == 1)
		ptr->images->wall[j] = mlx_xpm_file_to_image(&(ptr->mlx),
				ptr->images->str, &(ptr->images->x), &(ptr->images->y));
	else if (i == 2)
		ptr->images->play[j] = mlx_xpm_file_to_image(&(ptr->mlx),
				ptr->images->str, &(ptr->images->x), &(ptr->images->y));
	else if (i == 3)
		ptr->images->exit[j] = mlx_xpm_file_to_image(&(ptr->mlx),
				ptr->images->str, &(ptr->images->x), &(ptr->images->y));
	else if (i == 4)
		ptr->images->enem[j] = mlx_xpm_file_to_image(&(ptr->mlx),
				ptr->images->str, &(ptr->images->x), &(ptr->images->y));
	else if (i == 5)
		ptr->images->col[j] = mlx_xpm_file_to_image(&(ptr->mlx),
				ptr->images->str, &(ptr->images->x), &(ptr->images->y));
}

void	image_create(t_ptrs *ptr)
{
	int	i;
	int	j;

	i = 0;
	image_allocation(ptr);
	while (i <= 5)
	{
		j = 0;
		while (j < ptr->images->i[i])
		{
			ptr->images->str = join_2("Scripts/", i, j, ".xpm");
			open_image(ptr, i, j);
			free(ptr->images->str);
			j++;
		}
		i++;
	}
}
