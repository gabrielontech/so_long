/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_content_checkers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkitoko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 16:24:46 by gkitoko           #+#    #+#             */
/*   Updated: 2022/05/22 19:39:04 by gkitoko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

int	valid_player(t_map *map)
{
	int	i;
	int	j;
	int	valid;

	i = 0;
	valid = 0;
	while (map->v_map[i] != NULL)
	{
		j = 0;
		while (map->v_map[i][j] != '\0')
		{
			if (is_player(map->v_map[i][j]))
				valid++;
			j++;
		}
		i++;
	}
	if (valid != 1)
		return (0);
	return (valid);
}

int	valid_collector(t_map *map)
{
	int	i;
	int	j;
	int	valid;

	i = 0;
	valid = 0;
	while (map->v_map[i] != NULL)
	{
		j = 0;
		while (map->v_map[i][j] != '\0')
		{
			if (is_collector(map->v_map[i][j]))
				valid++;
			j++;
		}
		i++;
	}
	if (valid == 0)
		return (0);
	return (valid);
}

int	valid_exit(t_map *map)
{
	int	i;
	int	j;
	int	valid;

	i = 0;
	valid = 0;
	while (map->v_map[i] != NULL)
	{
		j = 0;
		while (map->v_map[i][j] != '\0')
		{
			if (is_exit(map->v_map[i][j]))
				valid++;
			j++;
		}
		i++;
	}
	if (valid == 0)
		return (0);
	return (valid);
}

void	check_is_wall(t_map *map, t_data *data)
{
	int	i;
	int	j;
	int	one_p;

	i = 0;
	j = 0;
	if (!(is_wall(map->v_map[i])))
		map_failure(map, data, "your map must be surrounded by a wall\n");
	if (!(is_wall(map->v_map[(map->v_height) - 1])))
		map_failure(map, data, "your map must be surrounded by a wall\n");
	while (map->v_map[i] != NULL)
	{
		if (map->v_map[i][j] != '1')
			map_failure(map, data, "your map must be surrounded by a wall\n");
		if (map->v_map[i][(map->v_width) - 1] != '1')
			map_failure(map, data, "your map must be surrounded by a wall\n");
		i++;
	}
}
