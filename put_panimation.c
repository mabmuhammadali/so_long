/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_panimation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdulla <dj.ali9292@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:51:13 by mabdulla          #+#    #+#             */
/*   Updated: 2022/10/06 15:04:56 by mabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_panimation(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	put_background(data);
	put_wall(data);
	put_coins(data);
	put_d(data);
	put_exit(data);
	data->stepc = ft_itoa(data->step);
	mlx_string_put(data->mlx, data->win, 10, 20, 0xFFFFFF, "Step: ");
	mlx_string_put(data->mlx, data->win, 55, 20, 0xFFFFFF, data->stepc);
	free (data->stepc);
}
