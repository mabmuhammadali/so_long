/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_animation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdulla <dj.ali9292@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:04:13 by mabdulla          #+#    #+#             */
/*   Updated: 2022/10/06 12:13:11 by mabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	d_tmove(t_data *data)
{
	if (data->map[data->dy + 1][data->dx] == 'P')
		game_over(data);
	if (data->map[data->dy + 1][data->dx] == '0'
			|| data->map[data->dy + 1][data->dx] == 'C')
	{
		if (data->cstatus == 1)
		{
			data->map[data->dy][data->dx] = 'C';
			data->cstatus = 0;
		}
		else
			data->map[data->dy][data->dx] = '0';
		if (data->map[data->dy + 1][data->dx] == 'C')
			data->cstatus = 1;
		data->map[data->dy + 1][data->dx] = 'D';
	}
	if (data->map[data->dy + 2][data->dx] == '1')
		data->top = 1;
}

static void	d_bmove(t_data *data)
{
	if (data->map[data->dy - 1][data->dx] == 'P')
		game_over(data);
	else if (data->map[data->dy - 1][data->dx] == '0'
			|| data->map[data->dy - 1][data->dx] == 'C')
	{
		if (data->cstatus == 1)
		{
			data->map[data->dy][data->dx] = 'C';
			data->cstatus = 0;
		}
		else
			data->map[data->dy][data->dx] = '0';
		if (data->map[data->dy - 1][data->dx] == 'C')
			data->cstatus = 1;
		data->map[data->dy - 1][data->dx] = 'D';
	}
	if (data->map[data->dy - 2][data->dx] == '1')
		data->top = 0;
}

static void	d_find(t_data *data)
{
	data->dy = -1;
	while (data->map[++data->dy] != 0)
	{
		data->dx = -1;
		while (data->map[data->dy][++data->dx] != 0)
		{
			if (data->map[data->dy][data->dx] == 'D')
			{
				return ;
			}
		}
	}
}

int	d_animation(t_data *data)
{
	if (data->sleep == 2500 && data->d == 1)
	{
		d_find(data);
		if (data->map[data->dy + 1][data->dx] != '1' && data->top == 0)
			d_tmove(data);
		else if (data->map[data->dy - 1][data->dx] != '1' && data->top == 1)
			d_bmove(data);
		data->sleep = 0;
		put_all(data);
	}
	if ((data->sleep % 500) == 0)
		p_animation(data);
	data->sleep++;
	return (0);
}
