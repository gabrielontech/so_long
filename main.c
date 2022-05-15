#include "so_long.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		endgame(data, data->v_map);
	if (keysym == 119 || keysym == 65362)
		move_up(data, data->v_map);
	if (keysym == 115 || keysym == 65364)
		move_down(data, data->v_map);
	if (keysym == 97 || keysym == 65361)
		move_left(data, data->v_map);
	if (keysym == 100 || keysym == 65363)
		move_right(data, data->v_map);
	return (0);
}

int	render(t_data *data)
{
	if (data->v_win_ptr != NULL){
		displayer(data, data->v_img ,data->v_map);
	}else if(data->v_win_ptr ==  NULL)
	{
		endgame(data, data->v_map);
	}
	return (0);
}

int	handle_keyrelease(int keysym, void *data)
{

	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;
	t_map	map;

	map.v_game.v_move = 0;
	map.v_game.v_collect = 0;
	map.v_game.v_collect_nb = 0;
	checker(ac, av);
	data.v_mlx_ptr = mlx_init();
	 if (data.v_mlx_ptr == NULL)
	{
		free(data.v_mlx_ptr);
		exit(EXIT_FAILURE);
	}  
	init_window(&data, av, &map);
	mlx_loop_hook(data.v_mlx_ptr, &render, &data);
	mlx_hook(data.v_win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data); 
	//mlx_hook(data.v_win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, &data);

	mlx_loop(data.v_mlx_ptr);
}