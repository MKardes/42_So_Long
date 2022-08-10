#include "so_long.h"

void	anim_position(t_player *stuff, int x, int y, t_ptrs *ptr)
{
	stuff->x = x * PIX;
	stuff->y = y * PIY;
	if (ptr->map->map[y][x] == 'P')
		stuff->skin = ptr->images->play;
	else
		stuff->skin = ptr->images->enem;
}

void    start_movable(t_ptrs *ptr)
{
    int	y;
    int	x;

    y = 0;
	ptr->mv_cnt = 1;
	ptr->player = (t_player*)malloc(sizeof(t_player) * (ptr->map->p + ptr->map->n));
    while (y < ptr->map->y)
    {
        x = 0;
        while (x < ptr->map->x)
        {
            if (ptr->map->map[y][x] == 'P')
				anim_position(&(ptr->player[0]), x, y, ptr);
			else if (ptr->map->map[y][x] == 'N')
			{
				anim_position(&(ptr->player[ptr->mv_cnt]), x, y, ptr);
				ptr->mv_cnt++;
			}
            x++;
        }
        y++;
    }
	ptr->mv_cnt--;
}

void	start(char **av, t_ptrs *ptr)
{
	if (check_file(av, ptr))
		exit(0);
	ptr->mlx = mlx_init();
	ptr->a = 1;
	ptr->p = 1;
	ptr->anim = 0;
	ptr->move = 0;
	ptr->bg = 0;
	ptr->c_p = 0;
	ptr->a_p = 0;
	ptr->a_e = 0;
	ptr->a_c = 0;
	ptr->speed = 0;
	ptr->win = mlx_new_window(ptr->mlx, ptr->map->x * PIX, ptr->map->y * PIY, "Heyyo");
	image_create(ptr);
	start_movable(ptr);
}
