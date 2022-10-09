/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdulla <dj.ali9292@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 12:58:36 by mabdulla          #+#    #+#             */
/*   Updated: 2022/10/06 12:03:34 by mabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	int		ber;

	data = ft_calloc(1, sizeof(t_data));
	data->ppath = (int *)ft_calloc(2, sizeof(int));
	data->f = 0;
	data->b = 1;
	data->l = 0;
	data->r = 0;
	if (argc != 2)
	{
		ft_puterror("Error\n");
		ft_printf("Wrong Argument\n");
		return (0);
	}
	ber = ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 4);
	if (ber != 0)
	{
		ft_puterror("Error\n");
		ft_printf("Wrong File.\n");
	}
	else
		map_read(argv[1], data);
}
