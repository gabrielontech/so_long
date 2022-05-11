#include "../so_long.h"
void swap_char(char *a, char *b)
{
    char tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

void    move_down(t_data *data, t_map *map)
{
    int i;
    int j;
    char player = 'P';
    char wall = '0';

    i = 0;
    while(map->v_map[i] != NULL)
    {
        j = 0;
        while(map->v_map[i][j]!= '\0')
        {
            if(map->v_map[i][j] == 'P')
            {
                if(map->v_map[i+1][j] == '0')
                {
                    swap_char(&map->v_map[i+1][j], &player);
                    swap_char(&map->v_map[i][j], &wall);
                }
                if(map->v_map[i+1][j] == 'C')
                {
                    swap_char(&map->v_map[i+1][j], &player);
                    swap_char(&map->v_map[i][j], &wall);
                    map->v_game.v_collect++;
                }
                if(map->v_map[i+1][j] == 'E' && map->v_game.v_collect_nb == map->v_game.v_collect)
                {
                    map->v_game.v_move++;
                    endgame(data, map);
                }
                map->v_game.v_move++;
                printf("Nombre de pas: %d\n", map->v_game.v_move);
                break;
            }   
            j++;
        }
        i++;
    }
}

void    move_left(t_data *data, t_map *map)
{
    int i;
    int j;
    char player = 'P';
    char wall = '0';

    i = 0;
    while(map->v_map[i] != NULL)
    {
        j = 0;
        while(map->v_map[i][j]!= '\0')
        {
            if(map->v_map[i][j] == 'P')
            {
                if(map->v_map[i][j-1] == '0')
                {
                    swap_char(&map->v_map[i][j-1], &player);
                    swap_char(&map->v_map[i][j], &wall);
                }
                if(map->v_map[i][j-1] == 'C')
                {
                    swap_char(&map->v_map[i][j-1], &player);
                    swap_char(&map->v_map[i][j], &wall);
                    map->v_game.v_collect++;
                }
                if(map->v_map[i][j-1] == 'E' && map->v_game.v_collect_nb == map->v_game.v_collect)
                {
                    map->v_game.v_move++;
                    endgame(data, map);
                }
                map->v_game.v_move++;
                printf("Nombre de pas: %d\n", map->v_game.v_move);
                break;
            }   
            j++;
        }
        i++;
    }
}

void    move_right(t_data *data, t_map *map)
{
    int i;
    int j;
    char player = 'P';
    char wall = '0';

    i = 0;
    while(map->v_map[i] != NULL)
    {
        j = 0;
        while(map->v_map[i][j]!= '\0')
        {
            if(map->v_map[i][j] == 'P')
            {
                if(map->v_map[i][j+1] == '0')
                {
                    swap_char(&map->v_map[i][j+1], &player);
                    swap_char(&map->v_map[i][j], &wall);
                }
                if(map->v_map[i][j+1] == 'C')
                {
                    swap_char(&map->v_map[i][j+1], &player);
                    swap_char(&map->v_map[i][j], &wall);
                    map->v_game.v_collect++;
                }
                if(map->v_map[i][j+1] == 'E' && map->v_game.v_collect_nb == map->v_game.v_collect)
                {
                    map->v_game.v_move++;
                    endgame(data, map);    
                }
                map->v_game.v_move++;
                printf("Nombre de pas: %d\n", map->v_game.v_move);
                break;
            }   
            j++;
        }
        i++;
    }
}

void    move_up(t_data *data, t_map *map)
{
    int i;
    int j;
    char player = 'P';
    char wall = '0';

    i = 0;
    while(map->v_map[i] != NULL)
    {
        j = 0;
        while(map->v_map[i][j]!= '\0')
        {
            if(map->v_map[i][j] == 'P')
            {
                if(map->v_map[i-1][j] == '0')
                {
                    swap_char(&map->v_map[i-1][j], &player);
                    swap_char(&map->v_map[i][j], &wall);
                }
                if(map->v_map[i-1][j] == 'C')
                {
                    swap_char(&map->v_map[i-1][j], &player);
                    swap_char(&map->v_map[i][j], &wall);
                    map->v_game.v_collect++;
                }
                if(map->v_map[i-1][j] == 'E' && map->v_game.v_collect_nb == map->v_game.v_collect)
                {
                    map->v_game.v_move++;
                    endgame(data, map);
                }
                map->v_game.v_move++;
                printf("Nombre de pas: %d\n", map->v_game.v_move);
                break;
            }   
            j++;
        }
        i++;
    }
}