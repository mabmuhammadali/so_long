/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdulla <dj.ali9292@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:41:24 by mabdulla          #+#    #+#             */
/*   Updated: 2022/10/05 14:47:08 by mabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	map_d(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[++i] != 0)
	{
		j = -1;
		while (data->map[i][++j] != 0)
			if (data->map[i][j] == 'D')
				data->d++;
	}
	if (data->d > 1)
		data->map_status = data->map_status + 1;
}

static void	map_cntrl(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i] != 0)
		i++;
	data->winy = i * 64;
	data->winx = (ft_strlen(data->map[0]) - 1) * 64;
	data->picx = 64;
	data->picy = 64;
	data->map_status = 0;
	map_sqr(data);
	map_char(data);
	map_wall(data);
	map_pec(data);
	map_d(data);
	if (data->map_status == 0)
		map_render(data);
	else
	{
		ft_puterror("Error\n");
		ft_printf("Wrong Map.\n");
	}
}

static void	map_clone(int fd, t_data *data)
{
	int		i;
	char	**line;

	line = (char **)ft_calloc(10000, sizeof(char *));
	i = -1;
	while (1)
	{
		if (line[i] == 0 && i == 0)
		{
			data->free_map = 1;
			return ;
		}
		if (line[i] == 0 && i > -1)
			break ;
		line[++i] = get_next_line(fd);
	}
	data->map = ft_calloc(i + 1, sizeof(char *));
	i = -1;
	while (line[++i] != 0)
		data->map[i] = ft_strdup(line[i]);
	data->map[i] = 0;
	i = -1;
	while (++i != 10000)
		free (line[i]);
	free (line);
}

static	void	ft_error(char *str)
{
	ft_puterror("Error\n");
	ft_printf("%s", str);
}

void	map_read(char *map, t_data *data)
{
	data->step = 0;
	data->cstatus = 0;
	data->top = 0;
	data->sleep = 0;
	data->d = 0;
	data->free_map = 0;
	data->path = ft_strjoin("./maps/", map);
	data->fd = open(data->path, O_RDONLY);
	free (data->path);
	if (data->fd < 0)
	{
		ft_puterror("Error\n");
		ft_printf("Map not Found. Wrong Filename.\n");
	}
	else
	{
		map_clone(data->fd, data);
		if (data->free_map == 1)
		{
			ft_error("Wrong Map.\n");
			return ;
		}
	}
	map_cntrl(data);
}
