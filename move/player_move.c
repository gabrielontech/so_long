/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkitoko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 16:18:41 by gkitoko           #+#    #+#             */
/*   Updated: 2022/05/24 17:48:23 by gkitoko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_down(t_map *map, t_data *data, int i, int j)
{
	if (map->v_map[i +1][j] == '0')
	{
		map->v_map[i + 1][j] = 'P';
		map->v_map[i][j] = '0';
		map->v_game.v_move++;
		ft_printf("Nombre de pas: %d\n", map->v_game.v_move);
	}
	else if (map->v_map[i + 1][j] == 'C')
	{
		map->v_map[i + 1][j] = 'P';
		map->v_map[i][j] = '0';
		map->v_game.v_collect++;
		map->v_game.v_move++;
		ft_printf("Nombre de pas: %d\n", map->v_game.v_move);
	}
	else if (map->v_map[i + 1][j] == 'E' &&
	map->v_game.v_collect_nb == map->v_game.v_collect)
	{
		map->v_game.v_move++;
		ft_printf("Nombre de pas: %d\n", map->v_game.v_move);
		endgame(data, map);
	}
}

void	move_left(t_map *map, t_data *data, int i, int j)
{
	if (map->v_map[i][j - 1] == '0')
	{
		map->v_map[i][j - 1] = 'P';
		map->v_map[i][j] = '0';
		map->v_game.v_move++;
		ft_printf("Nombre de pas: %d\n", map->v_game.v_move);
	}
	else if (map->v_map[i][j - 1] == 'C')
	{
		map->v_map[i][j - 1] = 'P';
		map->v_map[i][j] = '0';
		map->v_game.v_collect++;
		map->v_game.v_move++;
		ft_printf("Nombre de pas: %d\n", map->v_game.v_move);
	}
	else if (map->v_map[i][j - 1] == 'E' &&
	map->v_game.v_collect_nb == map->v_game.v_collect)
	{
		map->v_game.v_move++;
		ft_printf("Nombre de pas: %d\n", map->v_game.v_move);
		endgame(data, map);
	}
}

void	move_right(t_map *map, t_data *data, int i, int j)
{	
	if (map->v_map[i][j + 1] == '0')
	{
		map->v_map[i][j + 1] = 'P';
		map->v_map[i][j] = '0';
		map->v_game.v_move++;
		ft_printf("Nombre de pas: %d\n", map->v_game.v_move);
	}
	else if (map->v_map[i][j + 1] == 'C')
	{
		map->v_map[i][j + 1] = 'P';
		map->v_map[i][j] = '0';
		map->v_game.v_collect++;
		map->v_game.v_move++;
		ft_printf("Nombre de pas: %d\n", map->v_game.v_move);
	}
	else if (map->v_map[i][j + 1] == 'E'
	&& map->v_game.v_collect_nb == map->v_game.v_collect)
	{
		map->v_game.v_move++;
		ft_printf("Nombre de pas: %d\n", map->v_game.v_move);
		endgame(data, map);
	}
}

void	move_up(t_map *map, t_data *data, int i, int j)
{
	if (map->v_map[i - 1][j] == '0')
	{
		map->v_map[i - 1][j] = 'P';
		map->v_map[i][j] = '0';
		map->v_game.v_move++;
		ft_printf("Nombre de pas: %d\n", map->v_game.v_move);
	}
	else if (map->v_map[i - 1][j] == 'C')
	{
		map->v_map[i - 1][j] = 'P';
		map->v_map[i][j] = '0';
		map->v_game.v_collect++;
		map->v_game.v_move++;
		ft_printf("Nombre de pas: %d\n", map->v_game.v_move);
	}
	else if (map->v_map[i - 1][j] == 'E'
	&& map->v_game.v_collect_nb == map->v_game.v_collect)
	{
		map->v_game.v_move++;
		ft_printf("Nombre de pas: %d\n", map->v_game.v_move);
		endgame(data, map);
	}
}

void	move(t_data *data, t_map *map, int keysym)
{
	int	i;
	int	j;

	i = 0;
	while (map->v_map[i] != NULL)
	{
		j = 0;
		while (map->v_map[i][j] != '\0')
		{
			if (map->v_map[i][j] == 'P')
			{
				if (keysym == 119 || keysym == 65362)
					move_up(map, data, i, j);
				if (keysym == 115 || keysym == 65364)
					move_down(map, data, i, j);
				if (keysym == 97 || keysym == 65361)
					move_left(map, data, i, j);
				if (keysym == 100 || keysym == 65363)
					move_right(map, data, i, j);
				return ;
			}
			j++;
		}
		i++;
	}
}
