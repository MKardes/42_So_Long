/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:43:16 by mkardes           #+#    #+#             */
/*   Updated: 2022/07/20 17:38:55 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int	m_close(int keycode, t_ptrs *ptr)
{
	ft_printf("asd\n");	
	if(keycode == 53)
	{
		mlx_destroy_window(ptr->mlx_ptr, ptr->win_ptr);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_ptrs	ptr;

	(void)av;
	(void)ac;
	ptr.mlx_ptr = mlx_init();
	ptr.win_ptr = mlx_new_window(ptr.mlx_ptr, 1000, 1000, "Heyyo");
	ft_printf("\n\nŞimdiye dek BAŞARILI.\n\n(ŞİMDİYE DEK)\n");
	mlx_hook(ptr.win_ptr, 2, 1L<<0, m_close, &ptr);
	mlx_loop(ptr.mlx_ptr);
	return (0);
}
