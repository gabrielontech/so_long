#include "../so_long.h"

void display_lock(t_data *data, t_img pic ,t_vector vector)
{
    pic.v_relative_path = "./img/close_door.xpm";
    pic.v_img = mlx_xpm_file_to_image(data->v_mlx_ptr, pic.v_relative_path, &pic.v_img_width, &pic.v_img_height);
    data->v_locked = pic;
    if (data->v_win_ptr != NULL){
		mlx_put_image_to_window(data->v_mlx_ptr, data->v_win_ptr, data->v_locked.v_img, vector.v_x, vector.v_y);
	}
}

void display_unlock(t_data *data, t_img pic, t_vector vector)
{
    pic.v_relative_path = "./img/open_door.xpm";
    pic.v_img = mlx_xpm_file_to_image(data->v_mlx_ptr, pic.v_relative_path, &pic.v_img_width, &pic.v_img_height);
    data->v_unlocked = pic;
    if (data->v_win_ptr != NULL){
		mlx_put_image_to_window(data->v_mlx_ptr, data->v_win_ptr, data->v_unlocked.v_img, vector.v_x, vector.v_y);
	}
}