#include "../so_long.h"

int    get_w_height(char **av, t_data *data)
{
	int fd;
    int     i;
	char *tmp;

	tmp = NULL;
    i = 0;
    fd = open(av[1], O_RDONLY);
    if(fd < 0)
    {
        file_not_found();  
        quit(data);
    }
    while((tmp = get_next_line(fd)) != NULL){
		i++;
		free(tmp);
		tmp = NULL;
    }
	free(tmp);
	tmp = NULL;
    close(fd);
    if(i == 0)
        empty_map(data);
    return(i);
}

int     get_w_width(t_data *data, char **av, int i, t_map *map)
{
    char *str;
	char *map_to_str;
	int j;
    int fd;

    str = NULL;
    map_to_str = NULL;
    j = 0;
    fd = open(av[1], O_RDONLY);
    if(fd < 0)
    {
        file_not_found();  
        quit(data);
    }
    while(j < i)
    {
        str = get_next_line(fd);
        map_to_str = ft_strjoin(map_to_str, str);
        free(str);
        str = NULL;
        j++;
    }
    free(str);
    str = NULL;
    close(fd);
    get_next_line(-1);
    map->v_map = ft_split(map_to_str, '\n');
    free(map_to_str);
    map_to_str = NULL;
    valid_map(map, data);
    data->v_map = map;
    return(ft_strlen(map->v_map[0]));
}

void init_window(t_data *data, char **av, t_map *map)
{
    data->v_window_x = (get_w_height(av, data) * 48);
    data->v_window_y = (get_w_width(data, av, get_w_height(av, data), map) * 48);
    data->v_win_ptr = mlx_new_window(data->v_mlx_ptr, data->v_window_y, data->v_window_x, "So_long");
    if (data->v_win_ptr == NULL)
	{
        free_double_str(data->v_map->v_map);
       	mlx_destroy_display(data->v_mlx_ptr);
	    mlx_destroy_window(data->v_mlx_ptr, data->v_win_ptr);
		exit(EXIT_FAILURE);
	}
}