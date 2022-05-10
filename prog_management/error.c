#include "../so_long.h"

void	map_failure(t_map *map, char *msg)
{
	free_double_str(map->v_map);
	ft_putstr_fd("Error:\n", 2);
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}

void	empty_map(void)
{
	ft_putstr_fd("Error:\nEmpty map\n", 2);
	exit(EXIT_FAILURE);
}

void cep_failure(t_map *map, int response)
{
	if(response == 2){
		map_failure(map, "Please make sure that your map content at least:\none Collector\none Exit\n");
	} else 
	{
		map_failure(map, "Please make sure that your map strictely content one player\n");
	}	
}

void	ft_error(void)
{
	ft_putstr_fd("Error:\ninvalid arguments number\n", 2);
	exit(EXIT_FAILURE);
}