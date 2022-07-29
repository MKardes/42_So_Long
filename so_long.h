/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:43:10 by mkardes           #+#    #+#             */
/*   Updated: 2022/07/29 20:13:24 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG
# define SOLONG

# include "Others/ft_printf/ft_printf.h"
# include "Others/Get_Next_Line/get_next_line.h"
# include "mlx/mlx.h"

typedef struct s_ptrs{
	void	*mlx;
	void	*win;
	void	*image;
	int		x;
	int		y;
	int		a;
}	t_ptrs;

typedef struct s_map{
	char	**map;
	int		x;
	int		y;
	int		e;
	int		c;
	int		p;
}	t_map;

char	*get_next_line(int fd);
int		map_checker(t_map map);

#endif
