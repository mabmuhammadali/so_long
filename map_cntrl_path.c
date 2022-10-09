/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_cntrl_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdulla <dj.ali9292@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 11:43:48 by mabdulla          #+#    #+#             */
/*   Updated: 2022/09/30 15:02:16 by mabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_pec(t_data *data)
{
	map_pec_path(data, 'P');
	map_pec_path(data, 'E');
	map_pec_path(data, 'C');
}

static void	map_wall_td(t_data *data, int i)
{
	char	*str;
	char	*str1;

	str = ft_strtrim(data->map[0], "1\n");
	str1 = ft_strtrim(data->map[--i], "1");
	if (str[0] != '\0' || str1[0] != '\0')
	{
		free (str);
		free (str1);
		data->map_status = data->map_status + 1;
		return ;
	}
	free (str);
	free (str1);
	data->map_status = data->map_status + 0;
}

void	map_wall(t_data *data)
{
	int		i;

	i = -1;
	while (data->map[++i] != 0)
	{
		if (data->map[i][0] != '1'
			|| data->map[i][ft_strlen(data->map[i]) - 2] != '1')
		{
			data->map_status = data->map_status + 1;
			return ;
		}
	}
	map_wall_td(data, i);
}

void	map_char(t_data *data)
{
	int		i;
	char	*str;

	i = -1;
	while (data->map[++i] != 0)
	{
		str = ft_strtrim(data->map[i], "01CEPD\n");
		if (str[0] != '\0')
		{
			free (str);
			data->map_status = data->map_status + 1;
			return ;
		}
		free (str);
	}
	data->map_status = data->map_status + 0;
}

void	map_sqr(t_data *data)
{
	int		i;
	char	*str;
	char	*str1;

	i = -1;
	while (data->map[++i] != 0)
	{
		str = ft_strtrim(data->map[0], "\n");
		str1 = ft_strtrim(data->map[i], "\n");
		if (ft_strlen(str) != ft_strlen(str1))
		{
			free (str);
			free (str1);
			data->map_status = data->map_status + 1;
			return ;
		}
		free (str);
		free (str1);
	}
	data->map_status = data->map_status + 0;
}
