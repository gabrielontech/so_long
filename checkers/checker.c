/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkitoko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 16:24:03 by gkitoko           #+#    #+#             */
/*   Updated: 2022/05/22 17:34:17 by gkitoko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	checker(int ac, char **ag)
{
	if (ac != 2)
		ft_error();
	if (!(ft_strchr(ag[1], '.')))
	{
		ft_putstr_fd("Error :\nWrong type \
			file, file name must be named as: <filename>.ber\n", 2);
		exit(0);
	}
	if (ft_strncmp(ft_strchr(ag[1], '.'), ".ber", 4) != 0)
	{
		ft_putstr_fd("Error :\nWrong type file, \
			file name must be named as: <filename>.ber\n", 2);
		exit(0);
	}
}

void	check_map_content(t_map *map, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (map->v_map[i] != NULL)
	{
		j = 0;
		while (map->v_map[i][j] != '\0')
		{
			if (map->v_map[i][j] != '0' && map->v_map[i][j] != '1' &&
			map->v_map[i][j] != 'C' && map->v_map[i][j] != 'E'
			&& map->v_map[i][j] != 'P')
				map_failure(map, data, "Wrong map content\n");
			j++;
		}
		i++;
	}
}

void	check_if_map_is_rect(t_map *map, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (map->v_map[i] != NULL)
		i++;
	map->v_height = i;
	i = 0;
	j = ft_strlen(map->v_map[0]);
	while (map->v_map[i] != NULL)
	{
		if (ft_strlen(map->v_map[i]) != j)
			map_failure(map, data, "Please make sure that \
			your map follows the rectangle rules\n");
		i++;
	}
	map->v_width = j;
}
