/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_cntrl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdulla <dj.ali9292@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:29:42 by mabdulla          #+#    #+#             */
/*   Updated: 2022/10/05 15:03:36 by mabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_right(t_data *data)
{
	data->f = 0;
	data->b = 0;
	data->l = 0;
	data->r = 1;
	if (data->map[data->ppath[0]][data->ppath[1] + 1] == 'E')
		game_exit1(data);
	else if (data->map[data->ppath[0]][data->ppath[1] + 1] == 'D')
	{
		ft_printf("%d\n", ++data->step);
		game_over(data);
	}
	else if (data->map[data->ppath[0]][data->ppath[1] + 1] != '1')
	{
		if (data->map[data->ppath[0]][data->ppath[1] + 1] == 'C')
			data->coins--;
		data->map[data->ppath[0]][data->ppath[1] + 1] = 'P';
		data->map[data->ppath[0]][data->ppath[1]] = '0';
		data->ppath[1]++;
		ft_printf("%d\n", ++data->step);
	}
	return ;
}

static void	move_left(t_data *data)
{
	data->f = 0;
	data->b = 0;
	data->l = 1;
	data->r = 0;
	if (data->map[data->ppath[0]][data->ppath[1] - 1] == 'E')
		game_exit1(data);
	else if (data->map[data->ppath[0]][data->ppath[1] - 1] == 'D')
	{
		ft_printf("%d\n", ++data->step);
		game_over(data);
	}
	else if (data->map[data->ppath[0]][data->ppath[1] - 1] != '1')
	{
		if (data->map[data->ppath[0]][data->ppath[1] - 1] == 'C')
			data->coins--;
		data->map[data->ppath[0]][data->ppath[1] - 1] = 'P';
		data->map[data->ppath[0]][data->ppath[1]] = '0';
		data->ppath[1]--;
		ft_printf("%d\n", ++data->step);
	}
	return ;
}

static void	move_down(t_data *data)
{
	data->f = 0;
	data->b = 1;
	data->l = 0;
	data->r = 0;
	if (data->map[data->ppath[0] + 1][data->ppath[1]] == 'E')
		game_exit1(data);
	else if (data->map[data->ppath[0] + 1][data->ppath[1]] == 'D')
	{
		ft_printf("%d\n", ++data->step);
		game_over(data);
	}
	else if (data->map[data->ppath[0] + 1][data->ppath[1]] != '1')
	{
		if (data->map[data->ppath[0] + 1][data->ppath[1]] == 'C')
			data->coins--;
		data->map[data->ppath[0] + 1][data->ppath[1]] = 'P';
		data->map[data->ppath[0]][data->ppath[1]] = '0';
		data->ppath[0]++;
		ft_printf("%d\n", ++data->step);
	}
	return ;
}

static void	move_up(t_data *data)
{
	data->f = 1;
	data->b = 0;
	data->l = 0;
	data->r = 0;
	if (data->map[data->ppath[0] - 1][data->ppath[1]] == 'E')
		game_exit1(data);
	else if (data->map[data->ppath[0] - 1][data->ppath[1]] == 'D')
	{
		ft_printf("%d\n", ++data->step);
		game_over(data);
	}
	else if (data->map[data->ppath[0] - 1][data->ppath[1]] != '1')
	{
		if (data->map[data->ppath[0] - 1][data->ppath[1]] == 'C')
			data->coins--;
		data->map[data->ppath[0] - 1][data->ppath[1]] = 'P';
		data->map[data->ppath[0]][data->ppath[1]] = '0';
		data->ppath[0]--;
		ft_printf("%d\n", ++data->step);
	}
	return ;
}

int	key_signal(int keycode, t_data *data)
{
	if (keycode == 13)
		move_up(data);
	if (keycode == 1)
		move_down(data);
	if (keycode == 0)
		move_left(data);
	if (keycode == 2)
		move_right(data);
	if (keycode == 53)
		game_exit(data);
	put_all(data);
	return (0);
}
