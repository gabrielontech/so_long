#include "../so_long.h"

void    displayer(t_data *data, t_img pic, t_map *map)
{
    int i;
    int j;
    t_vector vector;

    i = 0;
    vector.v_x = 0;
    vector.v_y = 0;
    while(map->v_map[i] != NULL)
    {
        j = 0;
        while(map->v_map[i][j] != '\0'){
            if(map->v_map[i][j] == '1')
                display_wall(data, pic, vector);
            if(map->v_map[i][j] == 'P')
                display_player(data, pic, vector);
            if(map->v_map[i][j] == 'E')
                display_lock(data, pic, vector);
            vector.v_x += 48;
            j++;
            printf("j = %d\n",j);
        }
        vector.v_y =+ 48;
        vector.v_x = 0;
        i++;
        printf("i = %d\n",i);
    }
}