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
	mlx_destroy_display(data->v_mlx_ptr);
	mlx_destroy_image(data->v_mlx_ptr, &data->v_img);
	mlx_destroy_window(data->v_mlx_ptr, data->v_win_ptr);
	free(data->v_mlx_ptr);
	free(map->v_map);
	free(map);
	free(data->v_win_ptr);
}