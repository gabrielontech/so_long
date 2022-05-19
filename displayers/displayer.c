#include "../so_long.h"

void   init_img(t_data *data)
{
    data->v_collect.v_relative_path = "./img/collect.xpm";
    data->v_collect.v_img = mlx_xpm_file_to_image(data->v_mlx_ptr, data->v_collect.v_relative_path, &data->v_collect.v_img_width, &data->v_collect.v_img_height);
    data->v_player.v_relative_path = "./img/player.xpm";
    data->v_player.v_img = mlx_xpm_file_to_image(data->v_mlx_ptr, data->v_player.v_relative_path, &data->v_player.v_img_width, &data->v_player.v_img_height);

    data->v_wall.v_relative_path = "./img/wall.xpm";
    data->v_wall.v_img = mlx_xpm_file_to_image(data->v_mlx_ptr, data->v_wall.v_relative_path, &data->v_wall.v_img_width, &data->v_wall.v_img_height);

    data->v_floor.v_relative_path = "./img/night_sky.xpm";
    data->v_floor.v_img = mlx_xpm_file_to_image(data->v_mlx_ptr, data->v_floor.v_relative_path, &data->v_floor.v_img_width, &data->v_floor.v_img_height);

    data->v_locked.v_relative_path = "./img/close_door.xpm";
    data->v_locked.v_img = mlx_xpm_file_to_image(data->v_mlx_ptr, data->v_locked.v_relative_path, &data->v_locked.v_img_width, &data->v_locked.v_img_height);

    data->v_unlocked.v_relative_path = "./img/open_door.xpm";
    data->v_unlocked.v_img = mlx_xpm_file_to_image(data->v_mlx_ptr, data->v_unlocked.v_relative_path, &data->v_unlocked.v_img_width, &data->v_unlocked.v_img_height);
}

void    displayer(t_data *data, t_map *map)
{
    int i;
    int j;
    t_vector vector;

    i = 0;
    j = 0;
    vector.v_y = 0;
    vector.v_x = 0;
    while(map->v_map[i] != NULL)
    {
         j = 0;
        while(map->v_map[i][j]){
           if(map->v_map[i][j] == '1')
                display_wall(data, vector);
            if(map->v_map[i][j] == 'P')
                display_player(data, vector);
            if(map->v_map[i][j] == 'E' && map->v_game.v_collect_nb != map->v_game.v_collect)
                display_lock(data, vector);
            if(map->v_map[i][j] == 'E' && map->v_game.v_collect_nb == map->v_game.v_collect)
                display_unlock(data, vector);
            if(map->v_map[i][j] == 'C')
                display_collect(data, vector);
            if(map->v_map[i][j] == '0')
                display_floor(data, vector);
            vector.v_x += 48;
            j++;
        }
        vector.v_y += 48;
        vector.v_x = 0;
        i++;
    }
}