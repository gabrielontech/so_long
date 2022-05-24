/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkitoko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 16:18:41 by gkitoko           #+#    #+#             */
/*   Updated: 2022/05/24 08:39:28 by gkitoko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    move_down(t_data *data, t_map *map)
{
    int i;
    int j;

    i = 0;
    while(map->v_map[i] != NULL)
    {
        j = 0;
        while(map->v_map[i][j]!= '\0')
        {
            if(map->v_map[i][j] == 'P')
            {
                move_down_ext(map, data, i, j);
                return ;
            }   
            j++;
        }
        i++;
    }
}

void    move_left(t_data *data, t_map *map)
{
    int i;
    int j;
    char player = 'P';
    char wall = '0';

    i = 0;
    while(map->v_map[i] != NULL)
    {
        j = 0;
        while(map->v_map[i][j]!= '\0')
        {
            if(map->v_map[i][j] == 'P')
            {
                move_left_ext(map, data, i, j);
                return ;
            }   
            j++;
        }
        i++;
    }
}

void    move_right(t_data *data, t_map *map)
{
    int i;
    int j;
    char player = 'P';
    char wall = '0';

    i = 0;
    while(map->v_map[i] != NULL)
    {
        j = 0;
        while(map->v_map[i][j]!= '\0')
        {
            if(map->v_map[i][j] == 'P')
            {
                move_right_ext(map, data, i, j);
                return ;
            }
            j++;
        }
        i++;
    }
}

void    move_up(t_data *data, t_map *map)
{
    int i;
    int j;
    char player = 'P';
    char wall = '0';

    i = 0;
    while(map->v_map[i] != NULL)
    {
        j = 0;
        while(map->v_map[i][j]!= '\0')
        {
            if(map->v_map[i][j] == 'P')
            {
                move_up_ext(map, data, i, j);
                return ;
            }   
            j++;
        }
        i++;
    }
}
