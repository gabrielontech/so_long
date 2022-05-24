#include "../so_long.h"

void    move_down_ext(t_map *map,t_data *data,int i, int j)
{
        if (map->v_map[i +1][j] == '0')
        {
            map->v_map[i + 1][j] = 'P';
            map->v_map[i][j] = '0';
            map->v_game.v_move++;
            ft_printf("Nombre de pas: %d\n", map->v_game.v_move);
        }
        else if (map->v_map[i+1][j] == 'C')
        {
            map->v_map[i + 1][j] = 'P';
            map->v_map[i][j] = '0';
            map->v_game.v_collect++;
            map->v_game.v_move++;
            ft_printf("Nombre de pas: %d\n", map->v_game.v_move);
        }
        else if (map->v_map[i + 1][j] == 'E' && map->v_game.v_collect_nb == map->v_game.v_collect)
        {
            map->v_game.v_move++;
            ft_printf("Nombre de pas: %d\n", map->v_game.v_move);
            endgame(data, map);
        }
}

void    move_left_ext(t_map *map,t_data *data,int i, int j)
{
        if (map->v_map[i][j - 1] == '0')
        {
            map->v_map[i][j - 1] = 'P';
            map->v_map[i][j] = '0';
            map->v_game.v_move++;
            ft_printf("Nombre de pas: %d\n", map->v_game.v_move);
        }
        else if (map->v_map[i][j - 1] == 'C')
        {
            map->v_map[i][j - 1] = 'P';
            map->v_map[i][j] = '0';
            map->v_game.v_collect++;
        }
        else if (map->v_map[i][j - 1] == 'E' && map->v_game.v_collect_nb == map->v_game.v_collect)
        {
            map->v_game.v_move++;
            ft_printf("Nombre de pas: %d\n", map->v_game.v_move);
            endgame(data, map);
        }
        map->v_game.v_move++;
        ft_printf("Nombre de pas: %d\n", map->v_game.v_move);
}

void    move_right_ext(t_map *map,t_data *data,int i, int j)
{
        if (map->v_map[i][j + 1] == '0')
        {
            map->v_map[i][j + 1] = 'P';
            map->v_map[i][j] = '0';
        }
        else if(map->v_map[i][j + 1] == 'C')
        {
            map->v_map[i][j + 1] = 'P';
            map->v_map[i][j] = '0';
            map->v_game.v_collect++;
        }
        else if(map->v_map[i][j + 1] == 'E' && map->v_game.v_collect_nb == map->v_game.v_collect)
        {
            map->v_game.v_move++;
            ft_printf("Nombre de pas: %d\n", map->v_game.v_move);
            endgame(data, map);
        }
        map->v_game.v_move++;
        ft_printf("Nombre de pas: %d\n", map->v_game.v_move);
}

void    move_up_ext(t_map *map,t_data *data,int i, int j)
{
        if (map->v_map[i - 1][j] == '0')
        {
            map->v_map[i - 1][j] = 'P';
            map->v_map[i][j] = '0';
        }
        else if (map->v_map[i - 1][j] == 'C')
        {
            map->v_map[i - 1][j] = 'P';
            map->v_map[i][j] = '0';
            map->v_game.v_collect++;
        }
        else if (map->v_map[i - 1][j] == 'E' && map->v_game.v_collect_nb == map->v_game.v_collect)
        {
            map->v_game.v_move++;
            ft_printf("Nombre de pas: %d\n", map->v_game.v_move);
            endgame(data, map);
        }
        map->v_game.v_move++;
        ft_printf("Nombre de pas: %d\n", map->v_game.v_move);
}