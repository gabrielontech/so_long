#include "../so_long.h"

void    displayer(t_data *data, t_img pic, t_map *map)
{
    int i;
    int j;
    t_vector vector;

    i = 0;
    j = 0;
    vector.v_x = 0;
    vector.v_y = 0;
    /*while(map->v_map[i] !=  NULL)
    {
        printf("mon tableau %s\n", map->v_map[i]);
        i++;
    }
    exit(0);*/
    //i = 0;
    while(map->v_map[i] != NULL)
    {
        while(map->v_map[i][j]){
           if(map->v_map[i][j] == '1')
                display_wall(data, pic, vector);
            if(map->v_map[i][j] == 'P')
                display_player(data, pic, vector);
            if(map->v_map[i][j] == 'E')
                display_lock(data, pic, vector);
            if(map->v_map[i][j] == 'C')
                display_collect(data, pic, vector);
            if(map->v_map[i][j] == '0')
                display_floor(data, pic, vector);
            vector.v_x += 48;
            j++;
        }
        vector.v_y += 48;
        vector.v_x = 0;
        printf("\nvecteur de y = %d\n", vector.v_y);
        i++;
        j = 0;
        //printf("i = %d\n",i);
    }
}