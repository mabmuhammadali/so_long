/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_animation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdulla <dj.ali9292@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:27:41 by mabdulla          #+#    #+#             */
/*   Updated: 2022/10/06 12:00:50 by mabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	pf_animation(t_data *data, int j, int i)
{
	if (data->fs > 17 || data->fs < 9)
		data->fs = 9;
	put_panimation(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img[data->fs],
		j * 64, i * 64);
	data->fs++;
}

static void	pb_animation(t_data *data, int j, int i)
{
	if (data->bs > 26 || data->bs < 18)
		data->bs = 18;
	put_panimation(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img[data->bs],
		j * 64, i * 64);
	data->bs++;
}

static void	pl_animation(t_data *data, int j, int i)
{
	if (data->ls > 35 || data->ls < 27)
		data->ls = 27;
	put_panimation(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img[data->ls],
		j * 64, i * 64);
	data->ls++;
}

static void	pr_animation(t_data *data, int j, int i)
{
	if (data->rs > 44 || data->rs < 36)
		data->rs = 36;
	put_panimation(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img[data->rs],
		j * 64, i * 64);
	data->rs++;
}

void	p_animation(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i] != 0)
	{
		j = 0;
		while (data->map[i][j] != 0)
		{
			if (data->map[i][j] == 'P')
			{
				if (data->f == 1)
					pb_animation(data, j, i);
				else if (data->b == 1)
					pf_animation(data, j, i);
				else if (data->l == 1)
					pl_animation(data, j, i);
				else if (data->r == 1)
					pr_animation(data, j, i);
				return ;
			}
			j++;
		}
		i++;
	}
}
