/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_background.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdulla <dj.ali9292@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:21:15 by mabdulla          #+#    #+#             */
/*   Updated: 2022/10/05 14:49:47 by mabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_background(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i != data->winy)
	{
		j = 0;
		while (j <= data->winx)
		{
			mlx_put_image_to_window(data->mlx, data->win, data->img[0], j, i);
			j = j + 64;
		}
		i = i + 64;
	}
}

void	put_wall(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i] != 0)
	{
		j = 0;
		while (data->map[i][j] != 0)
		{
			if (data->map[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->win,
					data->img[1], j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void	put_coins(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i] != 0)
	{
		j = 0;
		while (data->map[i][j] != 0)
		{
			if (data->map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->win,
					data->img[2], j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void	put_exit(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i] != 0)
	{
		j = 0;
		while (data->map[i][j] != 0)
		{
			if (data->map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx, data->win,
					data->img[3], j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void	put_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i] != 0)
	{
		j = 0;
		while (data->map[i][j] != 0)
		{
			if (data->map[i][j] == 'P' && data->f == 1)
				mlx_put_image_to_window(data->mlx, data->win,
					data->img[5], j * 64, i * 64);
			else if (data->map[i][j] == 'P' && data->b == 1)
				mlx_put_image_to_window(data->mlx, data->win,
					data->img[4], j * 64, i * 64);
			else if (data->map[i][j] == 'P' && data->l == 1)
				mlx_put_image_to_window(data->mlx, data->win,
					data->img[6], j * 64, i * 64);
			else if (data->map[i][j] == 'P' && data->r == 1)
				mlx_put_image_to_window(data->mlx, data->win,
					data->img[7], j * 64, i * 64);
			j++;
		}
		i++;
	}
}
