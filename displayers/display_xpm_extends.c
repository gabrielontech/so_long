/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_xpm_extends.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkitoko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 16:23:35 by gkitoko           #+#    #+#             */
/*   Updated: 2022/05/23 10:54:32 by gkitoko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	display_lock(t_data *data, t_vector vector)
{
	if (data->v_win_ptr != NULL)
		mlx_put_image_to_window(data->v_mlx_ptr, data->v_win_ptr, \
		data->v_locked.v_img, vector.v_x, vector.v_y);
}

void	display_unlock(t_data *data, t_vector vector)
{
	if (data->v_win_ptr != NULL)
		mlx_put_image_to_window(data->v_mlx_ptr, data->v_win_ptr, \
		data->v_unlocked.v_img, vector.v_x, vector.v_y);
}
