#include "../so_long.h"

int valid_player(t_map map)
{
    int i;
    int j;
    int valid;

    i = 0;
    valid = 0;
    while(map.v_map[i] != NULL)
    {
        j++;
        while(map.v_map[i][j] != '\0'))
        {
            if(is_player(map.v_map[i][j]))
                valid++;
            j++;
        }
        i++;
    }
    if(valid == 0)
        return(0);
    return(valid);
}

int valid_collector(t_map map)
{
    int i;
    int j;
    int valid;

    i = 0;
    valid = 0;
    while(map.v_map[i] != NULL)
    {
        j++;
        while(map.v_map[i][j] != '\0'))
        {
            if(is_collector(map.v_map[i][j]))
                valid++;
            j++;
        }
        i++;
    }
    if(valid != 0)
        return(0);
    return(valid);
}

int valid_exit(t_map map)
{
    int i;
    int j;
    int valid;

    i = 0;
    valid = 0;
    while(map.v_map[i] != NULL)
    {
        j++;
        while(map.v_map[i][j] != '\0'))
        {
            if(is_exit(map.v_map[i][j]))
                valid++;
            j++;
        }
        i++;
    }
    if(valid == 0)
        return(0);
    return(valid);
}

void check_is_wall(t_map map)
{
    int i;
    int j;
    int one_p;

    i = 0;
    j = 0;
    if(!(is_one(map.v_map[i][j])))
        ft_error();
    if(!(is_one(map.v_map[map.v_height][j])))
        ft_error();
    while(map.v_map[i] != NULL)
    {
        if(map.v_map[i][j] != '1')
            ft_error();
        if(map.v_map[i][map.v_width] != '1')
            ft_error();
        i++;
    }
}