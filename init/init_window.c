#include "../so_long.h"

int    get_w_height(t_data *data, char **av)
{
    int fd;
    int     i;

    i = 0;
    fd = open(av[1], O_RDONLY);
    if(fd < 0)
        file_not_found();
    while(get_next_line(fd) != NULL)
        i++;
    close(fd);
    if(i == 0)
        empty_map();
    return(i);
}

int     get_w_width(t_data *data, char **av, int i, t_map *map)
{
    char *str;
	char *map_to_str;
	int j;
    int fd;

    str = "wait";
    map_to_str = NULL;
    j = 0;
    fd = open(av[1], O_RDONLY);
    if(fd < 0)
        file_not_found();
    while(j < i)
    {
        str = get_next_line(fd);
        map_to_str = ft_strjoin(map_to_str, str);
        free(str);
        j++;
    }
    ft_printf("str : %s\n", map_to_str);
    exit(0);
    close(fd);
    map->v_map = ft_split(map_to_str, '\n');
    free(map_to_str);
    valid_map(map);
    data->v_map = map;
    return(ft_strlen(map->v_map[0]));
}

void init_window(t_data *data, char **av, t_map *map)
{
    data->v_window_x = (get_w_height(data, av)) * 48;
    data->v_window_y = (get_w_width(data, av, get_w_height(data, av), map) * 48);
    data->v_win_ptr = mlx_new_window(data->v_mlx_ptr, data->v_window_y, data->v_window_x, "So_long");
	data->v_img.v_img = mlx_new_image(data->v_mlx_ptr, data->v_window_y, data->v_window_x);   
    if (data->v_win_ptr == NULL)
	{
       // free_double_str(map->v_map);
       	mlx_destroy_display(data->v_mlx_ptr);
	    mlx_destroy_window(data->v_mlx_ptr, data->v_win_ptr);
        free_double_str(data->v_map->v_map);
		exit(EXIT_FAILURE);
	} 
}
