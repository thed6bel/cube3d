/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 10:57:59 by hucorrei          #+#    #+#             */
/*   Updated: 2023/08/31 12:02:20 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

int	rgb_to_hex(int r, int g, int b)
{
	return ((r << 16) + (g << 8) + b);
}

int	main(int argc, char **argv)
{
	t_file	g;

	if (argc < 2 || argv[2])
		ft_error("Error, not enough arguments");
	if (!ft_start_parse(&g, argv[1]))
		ft_game_start(&g);
	else
	{
		printf("Re-try with a good map!\n");
		cub_end(&g);
		//pas oublier de free!!!!!
		system("leaks cub3D");
	}
	return (0);
}
