#include "../so_long.h"

void	free_double_str(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		free(str[++i]);
	free(str);
}

void	endgame(t_data *data, t_map *map)
{
	/*mlx_destroy_image(data->v_mlx_ptr, &data->v_locked);
	mlx_destroy_image(data->v_mlx_ptr, &data->v_unlocked);
	mlx_destroy_image(data->v_mlx_ptr, &data->v_floor);
	mlx_destroy_image(data->v_mlx_ptr, &data->v_wall);
	mlx_destroy_image(data->v_mlx_ptr, &data->v_player);
	mlx_destroy_image(data->v_mlx_ptr, &data->v_collect);
	*/
	//mlx_destroy_image(data->v_mlx_ptr, &data->v_img);
	mlx_clear_window(data->v_mlx_ptr, data->v_win_ptr);
	mlx_destroy_window(data->v_mlx_ptr, data->v_win_ptr);
	free_double_str(map->v_map);
	//free(data->v_win_ptr);
	free(data->v_mlx_ptr);
	exit(0);
}