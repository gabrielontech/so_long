#include "../so_long.h"

void display_floor(t_data *data, t_vector vector)
{
    if (data->v_win_ptr != NULL)
		mlx_put_image_to_window(data->v_mlx_ptr, data->v_win_ptr, data->v_floor.v_img, vector.v_x, vector.v_y);
}

void display_wall(t_data *data, t_vector vector)
{
    if (data->v_win_ptr != NULL)
		mlx_put_image_to_window(data->v_mlx_ptr, data->v_win_ptr, data->v_wall.v_img, vector.v_x, vector.v_y);
}

void display_player(t_data *data, t_vector vector)
{
    if (data->v_win_ptr != NULL)
		mlx_put_image_to_window(data->v_mlx_ptr, data->v_win_ptr, data->v_player.v_img, vector.v_x, vector.v_y);
}

void display_collect(t_data *data, t_vector vector)
{
    if (data->v_win_ptr != NULL)
		mlx_put_image_to_window(data->v_mlx_ptr, data->v_win_ptr, data->v_collect.v_img, vector.v_x, vector.v_y);
}