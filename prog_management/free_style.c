#include "../so_long.h"

void	free_double_str(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
}

void quit(t_data *data)
{
	mlx_destroy_display(data->v_mlx_ptr);
	free(data->v_mlx_ptr);
	data->v_mlx_ptr = NULL;
	exit(0);
}
void	endgame(t_data *data, t_map *map)
{
	free_double_str(data->v_map->v_map);
	mlx_destroy_image(data->v_mlx_ptr, data->v_locked.v_img);
	mlx_destroy_image(data->v_mlx_ptr, data->v_unlocked.v_img);
	mlx_destroy_image(data->v_mlx_ptr, data->v_floor.v_img);
	mlx_destroy_image(data->v_mlx_ptr, data->v_wall.v_img);
	mlx_destroy_image(data->v_mlx_ptr, data->v_player.v_img);
	mlx_destroy_image(data->v_mlx_ptr, data->v_collect.v_img);
	mlx_clear_window(data->v_mlx_ptr, data->v_win_ptr);
	mlx_destroy_window(data->v_mlx_ptr, data->v_win_ptr);
	mlx_destroy_display(data->v_mlx_ptr);
	free(data->v_mlx_ptr);
	data->v_mlx_ptr = NULL;
	exit(0);
}