#include "../so_long.h"

void display_floor(t_data *data, t_img pic, t_vector vector)
{
    pic.v_relative_path = "./img/night_sky.xpm";
    pic.v_img = mlx_xpm_file_to_image(data->v_mlx_ptr, pic.v_relative_path, &pic.v_img_width, &pic.v_img_height);
    data->v_floor = pic;
    if (data->v_win_ptr != NULL){
		mlx_put_image_to_window(data->v_mlx_ptr, data->v_win_ptr, data->v_floor.v_img, vector.v_x, vector.v_y);
	}
}

void display_wall(t_data *data, t_img pic ,t_vector vector)
{
    pic.v_relative_path = "./img/wall.xpm";
    pic.v_img = mlx_xpm_file_to_image(data->v_mlx_ptr, pic.v_relative_path, &pic.v_img_width, &pic.v_img_height);
    data->v_wall = pic;
    if (data->v_win_ptr != NULL){
		mlx_put_image_to_window(data->v_mlx_ptr, data->v_win_ptr, data->v_wall.v_img, vector.v_x, vector.v_y);
	}
}

void display_player(t_data *data, t_img pic ,t_vector vector)
{
    pic.v_relative_path = "./img/player.xpm";
    pic.v_img = mlx_xpm_file_to_image(data->v_mlx_ptr, pic.v_relative_path, &pic.v_img_width, &pic.v_img_height);
    data->v_player = pic;
    if (data->v_win_ptr != NULL){
		mlx_put_image_to_window(data->v_mlx_ptr, data->v_win_ptr, data->v_player.v_img, vector.v_x, vector.v_y);
	}
}

void display_collect(t_data *data, t_img pic ,t_vector vector)
{
    pic.v_relative_path = "./img/collect.xpm";
    pic.v_img = mlx_xpm_file_to_image(data->v_mlx_ptr, pic.v_relative_path, &pic.v_img_width, &pic.v_img_height);
    data->v_collect = pic;
    if (data->v_win_ptr != NULL){
		mlx_put_image_to_window(data->v_mlx_ptr, data->v_win_ptr, data->v_collect.v_img, vector.v_x, vector.v_y);
	}
}