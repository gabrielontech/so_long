#include "../so_long.h"

void valid_map(t_map *map)
{
    check_map_content(map);
    check_if_map_is_rect(map);
    check_is_wall(map);
    if(valid_collector(map) == 0)
        cep_failure(map, 2);
    if(valid_exit(map) == 0)
        cep_failure(map, 2);
    if(valid_player(map) == 0)
        cep_failure(map, 1);
}