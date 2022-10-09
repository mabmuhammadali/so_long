/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdulla <dj.ali9292@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 12:58:55 by mabdulla          #+#    #+#             */
/*   Updated: 2022/10/06 11:54:20 by mabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "./MiniLibX/mlx.h"
# include "./get_next_line/get_next_line.h"
# include "./Libft/libft.h"
# include "./ft_printf/ft_printf.h"

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*xpm;
	void	**img;
	char	**map;
	char	**map1;
	char	*stepc;
	char	*path;
	int		winx;
	int		winy;
	int		picx;
	int		picy;
	int		step;
	int		coins;
	int		*ppath;
	int		map_status;
	int		f;
	int		b;
	int		l;
	int		r;
	int		dx;
	int		dy;
	int		cstatus;
	int		top;
	int		sleep;
	int		d;
	int		free_map;
	int		fd;
	int		fs;
	int		bs;
	int		ls;
	int		rs;
}t_data;

void	map_read(char *map, t_data *data);
void	map_pec(t_data *data);
void	map_wall(t_data *data);
void	map_char(t_data *data);
void	map_sqr(t_data *data);
void	map_pec_path(t_data *data, char c);
void	ft_path(t_data *data, char c, int i, int j);
void	map_render(t_data *data);
void	put_background(t_data *data);
void	put_wall(t_data *data);
void	put_coins(t_data *data);
void	put_exit(t_data *data);
void	put_player(t_data *data);
void	ft_free(t_data *data);
void	put_all(t_data *data);
int		key_signal(int keycode, t_data *data);
int		game_exit(t_data *data);
int		d_animation(t_data *data);
void	game_over(t_data *data);
void	ft_puterror(char *str);
void	game_exit1(t_data *data);
void	p_animation(t_data *data);
void	put_panimation(t_data *data);
void	put_d(t_data *data);

#endif