/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdulla <dj.ali9292@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 13:28:01 by mabdulla          #+#    #+#             */
/*   Updated: 2022/10/06 15:25:54 by mabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	map_naming3(t_data *data)
{
	data->img[36] = mlx_xpm_file_to_image(data->mlx, "./XPM/PR1.xpm",
			&data->picx, &data->picy);
	data->img[37] = mlx_xpm_file_to_image(data->mlx, "./XPM/PR2.xpm",
			&data->picx, &data->picy);
	data->img[38] = mlx_xpm_file_to_image(data->mlx, "./XPM/PR3.xpm",
			&data->picx, &data->picy);
	data->img[39] = mlx_xpm_file_to_image(data->mlx, "./XPM/PR4.xpm",
			&data->picx, &data->picy);
	data->img[40] = mlx_xpm_file_to_image(data->mlx, "./XPM/PR5.xpm",
			&data->picx, &data->picy);
	data->img[41] = mlx_xpm_file_to_image(data->mlx, "./XPM/PR6.xpm",
			&data->picx, &data->picy);
	data->img[42] = mlx_xpm_file_to_image(data->mlx, "./XPM/PR7.xpm",
			&data->picx, &data->picy);
	data->img[43] = mlx_xpm_file_to_image(data->mlx, "./XPM/PR8.xpm",
			&data->picx, &data->picy);
	data->img[44] = mlx_xpm_file_to_image(data->mlx, "./XPM/PR9.xpm",
			&data->picx, &data->picy);
}

static void	map_naming2(t_data *data)
{
	data->img[24] = mlx_xpm_file_to_image(data->mlx, "./XPM/PB7.xpm",
			&data->picx, &data->picy);
	data->img[25] = mlx_xpm_file_to_image(data->mlx, "./XPM/PB8.xpm",
			&data->picx, &data->picy);
	data->img[26] = mlx_xpm_file_to_image(data->mlx, "./XPM/PB9.xpm",
			&data->picx, &data->picy);
	data->img[27] = mlx_xpm_file_to_image(data->mlx, "./XPM/PL1.xpm",
			&data->picx, &data->picy);
	data->img[28] = mlx_xpm_file_to_image(data->mlx, "./XPM/PL2.xpm",
			&data->picx, &data->picy);
	data->img[29] = mlx_xpm_file_to_image(data->mlx, "./XPM/PL3.xpm",
			&data->picx, &data->picy);
	data->img[30] = mlx_xpm_file_to_image(data->mlx, "./XPM/PL4.xpm",
			&data->picx, &data->picy);
	data->img[31] = mlx_xpm_file_to_image(data->mlx, "./XPM/PL5.xpm",
			&data->picx, &data->picy);
	data->img[32] = mlx_xpm_file_to_image(data->mlx, "./XPM/PL6.xpm",
			&data->picx, &data->picy);
	data->img[33] = mlx_xpm_file_to_image(data->mlx, "./XPM/PL7.xpm",
			&data->picx, &data->picy);
	data->img[34] = mlx_xpm_file_to_image(data->mlx, "./XPM/PL8.xpm",
			&data->picx, &data->picy);
	data->img[35] = mlx_xpm_file_to_image(data->mlx, "./XPM/PL9.xpm",
			&data->picx, &data->picy);
}

static void	map_naming1(t_data *data)
{
	data->img[12] = mlx_xpm_file_to_image(data->mlx, "./XPM/PF4.xpm",
			&data->picx, &data->picy);
	data->img[13] = mlx_xpm_file_to_image(data->mlx, "./XPM/PF5.xpm",
			&data->picx, &data->picy);
	data->img[14] = mlx_xpm_file_to_image(data->mlx, "./XPM/PF6.xpm",
			&data->picx, &data->picy);
	data->img[15] = mlx_xpm_file_to_image(data->mlx, "./XPM/PF7.xpm",
			&data->picx, &data->picy);
	data->img[16] = mlx_xpm_file_to_image(data->mlx, "./XPM/PF8.xpm",
			&data->picx, &data->picy);
	data->img[17] = mlx_xpm_file_to_image(data->mlx, "./XPM/PF9.xpm",
			&data->picx, &data->picy);
	data->img[18] = mlx_xpm_file_to_image(data->mlx, "./XPM/PB1.xpm",
			&data->picx, &data->picy);
	data->img[19] = mlx_xpm_file_to_image(data->mlx, "./XPM/PB2.xpm",
			&data->picx, &data->picy);
	data->img[20] = mlx_xpm_file_to_image(data->mlx, "./XPM/PB3.xpm",
			&data->picx, &data->picy);
	data->img[21] = mlx_xpm_file_to_image(data->mlx, "./XPM/PB4.xpm",
			&data->picx, &data->picy);
	data->img[22] = mlx_xpm_file_to_image(data->mlx, "./XPM/PB5.xpm",
			&data->picx, &data->picy);
	data->img[23] = mlx_xpm_file_to_image(data->mlx, "./XPM/PB6.xpm",
			&data->picx, &data->picy);
}

static void	map_naming(t_data *data)
{
	data->img = (void **)ft_calloc(48, sizeof(void *));
	data->img[0] = mlx_xpm_file_to_image(data->mlx, "./XPM/0.xpm",
			&data->picx, &data->picy);
	data->img[1] = mlx_xpm_file_to_image(data->mlx, "./XPM/1.xpm",
			&data->picx, &data->picy);
	data->img[2] = mlx_xpm_file_to_image(data->mlx, "./XPM/C.xpm",
			&data->picx, &data->picy);
	data->img[3] = mlx_xpm_file_to_image(data->mlx, "./XPM/E.xpm",
			&data->picx, &data->picy);
	data->img[4] = mlx_xpm_file_to_image(data->mlx, "./XPM/PF.xpm",
			&data->picx, &data->picy);
	data->img[5] = mlx_xpm_file_to_image(data->mlx, "./XPM/PB.xpm",
			&data->picx, &data->picy);
	data->img[6] = mlx_xpm_file_to_image(data->mlx, "./XPM/PL.xpm",
			&data->picx, &data->picy);
	data->img[7] = mlx_xpm_file_to_image(data->mlx, "./XPM/PR.xpm",
			&data->picx, &data->picy);
	data->img[8] = mlx_xpm_file_to_image(data->mlx, "./XPM/D.xpm",
			&data->picx, &data->picy);
	data->img[9] = mlx_xpm_file_to_image(data->mlx, "./XPM/PF1.xpm",
			&data->picx, &data->picy);
	data->img[10] = mlx_xpm_file_to_image(data->mlx, "./XPM/PF2.xpm",
			&data->picx, &data->picy);
	data->img[11] = mlx_xpm_file_to_image(data->mlx, "./XPM/PF3.xpm",
			&data->picx, &data->picy);
}

void	map_render(t_data *data)
{
	data->fs = 9;
	data->bs = 18;
	data->ls = 27;
	data->rs = 36;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->winx, data->winy, "So_Long");
	map_naming(data);
	map_naming1(data);
	map_naming2(data);
	map_naming3(data);
	put_background(data);
	put_wall(data);
	put_coins(data);
	put_exit(data);
	put_player(data);
	mlx_hook(data->win, 2, 0, key_signal, data);
	mlx_hook(data->win, 17, 0, game_exit, data);
	mlx_loop_hook(data->mlx, d_animation, data);
	mlx_loop(data->mlx);
}
