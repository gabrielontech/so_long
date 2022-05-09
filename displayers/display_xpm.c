
void display_floor(t_data *data, t_vector *vector)
{
    t_img floor;
    floor.v_relative_path = "./img/night_sky.xpm";
    floor.v_img = mlx_xpm_file_to_image(data.v_mlx_ptr, floor.v_relative_path, &floor.v_img_width, &floor.v_img_height);
    if(floor.v_img != NULL)
        return (MLX_ERROR);
    data.v_floor = floor;
    if (data->v_win_ptr != NULL){
		mlx_put_image_to_window(data->v_mlx_ptr, data->v_win_ptr, data->v_floor.v_img, vector->v_x, vector->v_y);
	}
};

void display_wall(t_data *data, t_vector *vector)
{
    t_img wall;
    wall.v_relative_path = "./img/wall.xpm";
    wall.v_img = mlx_xpm_file_to_image(data.v_mlx_ptr, wall.v_relative_path, &wall.v_img_width, &wall.v_img_height);
    if(wall.v_img != NULL)
        return (MLX_ERROR);
    data.v_wall = wall;
    if (data->v_win_ptr != NULL){
		mlx_put_image_to_window(data->v_mlx_ptr, data->v_win_ptr, data->v_wall.v_img, vector->v_x, vector->v_y);
	}
};

void display_player(t_data *data, t_vector *vector)
{
    t_img player;
    player.v_relative_path = "./img/player.xpm";
    player.v_img = mlx_xpm_file_to_image(data.v_mlx_ptr, player.v_relative_path, &player.v_img_width, &player.v_img_height);
    if(player.v_img != NULL)
        return (MLX_ERROR);
    data.v_payer = wall;
    if (data->v_win_ptr != NULL){
		mlx_put_image_to_window(data->v_mlx_ptr, data->v_win_ptr, data->v_payer.v_img, vector->v_x, vector->v_y);
	}
};

void display_collect(t_data *data, t_vector *vector)
{
    t_img collect;
    wall.v_relative_path = "./img/collect.xpm";
    wall.v_img = mlx_xpm_file_to_image(data.v_mlx_ptr, wall.v_relative_path, &wall.v_img_width, &wall.v_img_height);
    if(wall.v_img != NULL)
        return (MLX_ERROR);
    data.v_wall = wall;
    if (data->v_win_ptr != NULL){
		mlx_put_image_to_window(data->v_mlx_ptr, data->v_win_ptr, data->v_wall.v_img, vector->v_x, vector->v_y);
	}
};

void display_close(t_data *data, t_vector *vector)
{
    t_img wall;
    wall.v_relative_path = "./img/close_door.xpm";
    wall.v_img = mlx_xpm_file_to_image(data.v_mlx_ptr, wall.v_relative_path, &wall.v_img_width, &wall.v_img_height);
    if(wall.v_img != NULL)
        return (MLX_ERROR);
    data.v_wall = wall;
    if (data->v_win_ptr != NULL){
		mlx_put_image_to_window(data->v_mlx_ptr, data->v_win_ptr, data->v_wall.v_img, vector->v_x, vector->v_y);
	}
};

void display_open(t_data *data, t_vector *vector)
{
    t_img wall;
    wall.v_relative_path = "./img/open_door.xpm";
    wall.v_img = mlx_xpm_file_to_image(data.v_mlx_ptr, wall.v_relative_path, &wall.v_img_width, &wall.v_img_height);
    if(wall.v_img != NULL)
        return (MLX_ERROR);
    data.v_wall = wall;
    if (data->v_win_ptr != NULL){
		mlx_put_image_to_window(data->v_mlx_ptr, data->v_win_ptr, data->v_wall.v_img, vector->v_x, vector->v_y);
	}
};

/*
void *display_xpm(t_data *data)
{
    if(data->v_win_ptr != NULL)sd      
}
*/