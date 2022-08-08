/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:43:10 by mkardes           #+#    #+#             */
/*   Updated: 2022/08/08 17:57:29 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG
# define SOLONG

# include "Others/ft_printf/ft_printf.h"
# include "Others/Get_Next_Line/get_next_line.h"
# include "mlx/mlx.h"
# include <fcntl.h>

# define A 0
# define S 1
# define D 2
# define W 13
# define UP 126
# define DOWN 125
# define LEFT 123
# define RİGHT 124
# define P 35
# define ESC 53
# define LAY 0
# define WLL 1
# define PLY 2
# define EXT 3
# define ENM 4
# define COL 5
# define L_CNT 13
# define W_CNT 3
# define P_CNT 4
# define X_CNT 2
# define E_CNT 1
# define C_CNT 9
# define LAYER 9
# define PLAYER 0
# define WALL 2
# define ENEMY 0
# define EXIT 1
# define p_x 48
# define p_y 48

typedef struct s_map{
    char    **map;
    int     x;
    int     y;
    int     e;
    int     c;
    int     p;
	int		n;
}   t_map;

typedef struct s_images{
	void	**play;
	void	**lay;
	void	**exit;
	void	**enem;
	void	**wall;
	void	**col;
	int		*i;
	char	*str;
	int		x;
	int		y;
}	t_images;

typedef struct s_player{
	void	**skin;
	int		x;
	int		y;
}	t_player;

typedef struct s_ptrs{
	void		*mlx;
	void		*win;
	void		*image;
	int			mv_cnt;
	int			x;
	int			y;
	int			a;
	int			i;
	int			p;
	t_map		*map;
	t_player	*player;
	t_images	*images;
}	t_ptrs;

char	*get_next_line(int fd);
int		key_states(int key, t_ptrs **ptr);
int		map_free(t_map *map);
int		ft_error(char *str);
int		map_checker(t_map *map);
int		check_file(char **av, t_ptrs *ptr);
int		loop(t_ptrs *ptr);
int		coin_func(t_ptrs *ptr);
void	image_create(t_ptrs *ptr);
void	start(char **av, t_ptrs *ptr);
void	map_put(t_ptrs *ptr);
void	image_create(t_ptrs *ptr);
void    start_movable(t_ptrs *ptr);
void	start(char **av, t_ptrs *ptr);

#endif
