/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pec_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdulla <dj.ali9292@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 11:51:22 by mabdulla          #+#    #+#             */
/*   Updated: 2022/09/30 12:12:39 by mabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	map_pe1(t_data *data, char c)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[++i] != 0)
	{
		j = -1;
		while (data->map[i][++j] != 0)
		{
			if (data->map[i][j] == 'P')
			{
				ft_path(data, c, i, j);
				return ;
			}
		}
	}
	data->map_status = data->map_status + 1;
}

static void	map_pe(t_data *data, char c)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	k = 0;
	while (data->map[++i] != 0)
	{
		j = -1;
		while (data->map[i][++j] != 0)
			if (data->map[i][j] == c)
				k++;
	}
	if (k != 1)
	{
		data->map_status = data->map_status + 1;
		return ;
	}
	map_pe1(data, c);
}

static void	map_c1(t_data *data, char c)
{
	int	i;
	int	j;

	if (data->coins != 0)
	{
		i = -1;
		while (data->map[++i] != 0)
		{
			j = -1;
			while (data->map[i][++j] != 0)
			{
				if (data->map[i][j] == 'P')
				{
					ft_path(data, c, i, j);
					return ;
				}
			}
		}
	}
	data->map_status = data->map_status + 1;
}

static void	map_c(t_data *data, char c)
{
	int	i;
	int	j;

	i = -1;
	data->coins = 0;
	while (data->map[++i] != 0)
	{
		j = -1;
		while (data->map[i][++j])
			if (data->map[i][j] == c)
				data->coins++;
	}
	map_c1(data, c);
}

void	map_pec_path(t_data *data, char c)
{
	if (c == 'C')
	{
		map_c(data, c);
	}
	else
		map_pe(data, c);
}
