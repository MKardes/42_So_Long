#include "so_long.h"

void    direction_UD_continue(t_ptrs *ptr, int key, int n_y, int p_y)
{
    if (key == W)
    {
        ptr->a_p = 1;
        if (ptr->map->map[n_y][ptr->player[0].x / PIX] != '1')
        {
            ptr->move += 1;
		    ptr->player[0].y -= (SPEED + ptr->speed);
        }
    }
	if (key == S)
    {
        ptr->a_p = 0;
        if (ptr->map->map[p_y][ptr->player[0].x / PIX] != '1')
        {
            ptr->move += 1;
            ptr->player[0].y += (SPEED + ptr->speed);
        }
    }
}

void    direction_RL_continue(t_ptrs *ptr, int key, int n_x, int p_x)
{
    if (key == D)
    {
        ptr->a_p = 3;
        if (ptr->map->map[ptr->player[0].y / PIY][p_x] != '1')
        {
            ptr->move += 1;
		    ptr->player[0].x += (SPEED + ptr->speed);
        }
    }
	if (key == A)
    {
        ptr->a_p = 2;
        if (ptr->map->map[ptr->player[0].y / PIY][n_x] != '1')
        {
            ptr->move += 1;
            ptr->player[0].x -= (SPEED + ptr->speed);
        }
    }
}

void    direction(t_ptrs *ptr, int key)
{
    int n_y;
    int p_y;
    int n_x;
    int p_x;

    n_x = (ptr->player[0].x - (SPEED + ptr->speed)) / PIX;
    p_x = (ptr->player[0].x + (SPEED + ptr->speed)) / PIX;
    n_y = (ptr->player[0].y - (SPEED + ptr->speed)) / PIY;
    p_y = (ptr->player[0].y + (SPEED + ptr->speed)) / PIY;
    direction_UD_continue(ptr, key, n_y, p_y);
    direction_RL_continue(ptr, key, n_x, p_x);
}
