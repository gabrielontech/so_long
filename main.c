#include "so_long.h"

#define MLX_ERROR 1

int	handle_no_event(void *data)
{
	/* This function needs to exist, but it is useless for the moment */
	return (0);
}

int	handle_input(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->v_mlx_ptr, data->v_win_ptr);
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->v_mlx_ptr, data->v_win_ptr);

	printf("Keypress: %d\n", keysym);
	return (0);
}

int	handle_keyrelease(int keysym, void *data)
{
	printf("Keyrelease: %d\n", keysym);
	return (0);
}

int	render(t_data *data)
{
	/* if window has been destroyed, we don't want to put the pixel ! */
	if (data->v_win_ptr != NULL){
		mlx_put_image_to_window(data->v_mlx_ptr, data->v_win_ptr, data->v_perso.v_img, 0, 48);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;
	t_img	perso;
	t_img	wall;
	t_img	background;
	t_vector vector;

	int		fd;
	char *strs;
	char *save;
	t_map	map;
	int 	i;
	int		j;
	int		x;
	int		y;
	//t_img	map;

    checker(ac, av);
	vector.v_x = 0;
	vector.v_y = 0;
	i = 0;
	j = 0;
	strs = "l";
	save = NULL;
	data.v_mlx_ptr = mlx_init();

	//get every line of my .ber and store them in the i variable for BUFFER STRS size.
	fd = open(av[1], O_RDONLY);
	if(fd < 0)
		return(0);
	while(get_next_line(fd) != NULL)
		i++;
	close(fd);
	if(i == 0)
		empty_map();
	data.v_window_y = i; // storage for the height of the window
	//get each line of my buffer until the end and store them in BUFFER STRS .
	fd = open(av[1], O_RDONLY);
	if(fd < 0)
		return(0);
	while(j < i)
	{
		strs = get_next_line(fd);
		save = ft_strjoin(save, strs);
		j++;
	}
	close(fd);
	map.v_map = ft_split(save, '\n');
	valid_map(&map);
	data.v_window_x = ft_strlen(map.v_map[0]); // storage of the width of the window
	//mlx purpose
	if (data.v_mlx_ptr == NULL)
		return (MLX_ERROR);
	data.v_win_ptr = mlx_new_window(data.v_mlx_ptr, data.v_window_x * 48, data.v_window_y * 48, "My first window!");
	if (data.v_win_ptr == NULL)
	{
		free(data.v_win_ptr);
		return (MLX_ERROR);
	}
	perso.v_relative_path = "./img/perso.xpm";
	wall.v_relative_path = "./img/pumpkin.xpm";
	background.v_relative_path = "./img/night_sky.xpm";
	//map = (t_img){NULL, "./map.xpm", 48, 26};
	perso.v_img = mlx_xpm_file_to_image(data.v_mlx_ptr, perso.v_relative_path, &perso.v_img_width, &perso.v_img_height);
	if(perso.v_img == NULL)
		return (MLX_ERROR);
	wall.v_img = mlx_xpm_file_to_image(data.v_mlx_ptr, wall.v_relative_path, &wall.v_img_width, &wall.v_img_height);
	if(wall.v_img == NULL)
		return (MLX_ERROR);
	background.v_img = mlx_xpm_file_to_image(data.v_mlx_ptr, background.v_relative_path, &background.v_img_width, &background.v_img_height);
	if(background.v_img == NULL)
		return (MLX_ERROR);
	data.v_perso = perso;
	data.v_wall = wall;
	data.v_background = background;

	//map.img = mlx_xpm_file_to_image(data.mlx_ptr, map.relative_path, &map.img_width, &map.img_height);
	/* Setup hooks */
	mlx_loop_hook(data.v_mlx_ptr, &render, &data);
	mlx_hook(data.v_win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data); /* ADDED */
	mlx_hook(data.v_win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, &data); /* CHANGED */

	mlx_loop(data.v_mlx_ptr);
	mlx_destroy_display(data.v_mlx_ptr);
	free(data.v_mlx_ptr);
}