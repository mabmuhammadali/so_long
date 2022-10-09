/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdulla <dj.ali9292@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:49:28 by mabdulla          #+#    #+#             */
/*   Updated: 2022/10/06 15:06:11 by mabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	game_exit1(t_data *data)
{
	if (data->coins == 0)
	{
		ft_printf("%d\n", ++data->step);
		game_exit(data);
	}
}

void	game_over(t_data *data)
{
	ft_printf("GAME OVER\n");
	game_exit(data);
}

void	put_d(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i] != 0)
	{
		j = 0;
		while (data->map[i][j] != 0)
		{
			if (data->map[i][j] == 'D')
				mlx_put_image_to_window(data->mlx, data->win,
					data->img[8], j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void	put_all(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	put_background(data);
	put_player(data);
	put_wall(data);
	put_coins(data);
	put_d(data);
	put_exit(data);
	data->stepc = ft_itoa(data->step);
	mlx_string_put(data->mlx, data->win, 10, 20, 0xFFFFFF, "Step: ");
	mlx_string_put(data->mlx, data->win, 55, 20, 0xFFFFFF, data->stepc);
	free (data->stepc);
}

int	game_exit(t_data *data)
{
	int	i;

	put_all(data);
	mlx_clear_window(data->mlx, data->win);
	i = -1;
	while (data->map[++i] != 0)
		free (data->map[i]);
	free (data->map[i]);
	free (data->map);
	free (data->img);
	free (data->ppath);
	free (data);
	ft_printf("EXIT GAME\n");
	exit(0);
}
