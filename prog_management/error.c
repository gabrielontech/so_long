/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkitoko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 16:17:16 by gkitoko           #+#    #+#             */
/*   Updated: 2022/05/23 10:50:12 by gkitoko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_failure(t_map *map, t_data *data, char *msg)
{
	free_double_str(map->v_map);
	ft_putstr_fd("Error:\n", 2);
	ft_putstr_fd(msg, 2);
	quit(data);
}

void	file_not_found(void)
{
	ft_putstr_fd("Error:\nNo such file or directory\n", 2);
}

void	empty_map(t_data *data)
{
	ft_putstr_fd("Error:\nEmpty map\n", 2);
	quit(data);
}

void	cep_failure(t_map *map, t_data *data, int response)
{
	if (response == 2)
		map_failure(map, data, "Please make sure that your map content at \
		least:\none Collector\none Exit\n");
	else
		map_failure(map, data, "Please make sure that your map strictely \
		content one player\n");
}

void	ft_error(void)
{
	ft_putstr_fd("Error:\ninvalid arguments number\n", 2);
	exit(EXIT_FAILURE);
}
