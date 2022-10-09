/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paht.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdulla <dj.ali9292@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:49:23 by mabdulla          #+#    #+#             */
/*   Updated: 2022/10/07 10:29:40 by mabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_path_control1(t_data *data, char c, int i, int j)
{
	i = -1;
	while (data->map1[++i] != 0)
	{
		j = -1;
		while (data->map1[i][++j] != 0)
		{
			if (data->map1[i][j] == c)
			{
				if (data->map1[i + 1][j] == 'X' || data->map1[i - 1][j] == 'X'
					|| data->map1[i][j - 1] == 'X'
						|| data->map1[i][j + 1] == 'X')
				{
					data->map_status = data->map_status + 0;
					return ;
				}
				else
				{
					data->map_status = data->map_status + 1;
					return ;
				}
			}
		}
	}
}

static void	ft_path_control(t_data *data, char c)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	if (c != 'E')
	{
		while (data->map1[++i] != 0)
		{
			j = -1;
			while (data->map1[i][++j] != 0)
			{
				if (data->map1[i][j] == c)
				{
					data->map_status = data->map_status + 1;
					return ;
				}
			}
		}
		data->map_status = data->map_status + 0;
	}
	else
		ft_path_control1(data, c, i, j);
}

static void	ft_path1(t_data *data, int i, int j)
{
	if (data->map1[i][j + 1] == '0' || data->map1[i][j + 1] == 'C'
		|| data->map1[i][j + 1] == 'P')
	{
		data->map1[i][j + 1] = 'X';
		ft_path1(data, i, j + 1);
	}
	if (data->map1[i][j - 1] == '0' || data->map1[i][j - 1] == 'C'
		|| data->map1[i][j - 1] == 'P')
	{
		data->map1[i][j - 1] = 'X';
		ft_path1(data, i, j - 1);
	}
	if (data->map1[i + 1][j] == '0' || data->map1[i + 1][j] == 'C'
		|| data->map1[i + 1][j] == 'P')
	{
		data->map1[i + 1][j] = 'X';
		ft_path1(data, i + 1, j);
	}
	if (data->map1[i - 1][j] == '0' || data->map1[i - 1][j] == 'C'
		|| data->map1[i - 1][j] == 'P')
	{
		data->map1[i - 1][j] = 'X';
		ft_path1(data, i - 1, j);
	}
}

void	ft_path(t_data *data, char c, int i, int j)
{
	int	k;

	k = 0;
	while (data->map[k] != 0)
		k++;
	data->map1 = (char **)ft_calloc(k + 1, sizeof(char *));
	k = -1;
	while (data->map[++k] != 0)
		data->map1[k] = ft_strdup(data->map[k]);
	if (data->map[i][j] == 'P')
	{
		data->ppath[0] = i;
		data->ppath[1] = j;
	}
	ft_path1(data, i, j);
	ft_path_control(data, c);
	k = -1;
	while (data->map1[++k] != 0)
		free (data->map1[k]);
	free (data->map1[k]);
	free (data->map1);
}
