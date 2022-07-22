/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:43:10 by mkardes           #+#    #+#             */
/*   Updated: 2022/07/22 21:06:21 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL
# define FRACTOL

# include "Others/ft_printf/ft_printf.h"
# include "mlx/mlx.h"

typedef struct s_ptrs{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	int		a;
}	t_ptrs;

#endif
