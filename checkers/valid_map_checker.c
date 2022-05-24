/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkitoko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 16:27:10 by gkitoko           #+#    #+#             */
/*   Updated: 2022/05/24 09:06:02 by gkitoko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	collect_valid(t_map *map)
{
	int	i;
	int	j;
	int	collect;

	i = 0;
	collect = 0;
	while (map->v_map[i] != NULL)
	{
		j = 0;
		while (map->v_map[i][j])
		{
			if (map->v_map[i][j] == 'C')
				collect++;
			j++;
		}
		i++;
	}
	return (collect);
}

void	valid_map(t_map *map, t_data *data)
{
	check_map_content(map, data);
	check_if_map_is_rect(map, data);
	check_is_wall(map, data);
	if (valid_collector(map) == 0)
		cep_failure(map, data, 2);
	if (valid_exit(map) == 0)
		cep_failure(map, data, 2);
	if (valid_player(map) == 0)
		cep_failure(map, data, 1);
	map->v_game.v_collect_nb = collect_valid(map);
}
