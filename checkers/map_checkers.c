#include "../so_long.h"

int is_one(char *line)
{
    int i;

    i = 0;
    while(line[i] != '\0')
    {
        if(line[i] != '1')
        {
            return(0);
        }
        i++;
    }
    return(1);
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
    i = 0;
    while(map.v_map[i])
    {
        j = 0
        while(map.v_map[i][j])
        {
            if(is_collector(map.v_map[i][j]))

        }
    }
}