#include "../so_long.h"

int collect_valid(t_map *map)
{
    int i;
    int j;
    int collect;

    i = 0;
    collect = 0;
    while(map->v_map[i] != NULL)
    {
        j = 0;
        while(map->v_map[i][j])
        {
            if(map->v_map[i][j] == 'C')
                collect++;
            j++;
        }
        i++;
    }
    return(collect);
}
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
    map->v_game.v_collect_nb = collect_valid(map);
    printf("nb de collectible %d\n", map->v_game.v_collect_nb);
}