/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:43:10 by mkardes           #+#    #+#             */
/*   Updated: 2022/07/28 13:04:06 by mkardes          ###   ########.fr       */
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
	int		x;
	int		y;
	int		a;
}	t_ptrs;

typedef struct s_map{
	char	**map;
	int		x;
	int		y;
}	t_map;

char	*get_next_line(int fd);

#endif
