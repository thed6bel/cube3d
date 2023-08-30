/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 10:57:59 by hucorrei          #+#    #+#             */
/*   Updated: 2023/08/30 11:48:03 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
// 	*(unsigned int *)dst = color;
// }

int	rgb_to_hex(int r, int g, int b)
{
	return ((r << 16) + (g << 8) + b);
}

void	ft_floor_cloud_color(t_img *data, t_file *file)
{
	int	x;
	int	y;
	int	half_height;
	int	hex_color_f;
	int	hex_color_c;

	half_height = 480 / 2;
	hex_color_f = rgb_to_hex(file->floor.red, file->floor.green, \
		file->floor.blue);
	hex_color_c = rgb_to_hex(file->ceilling.red, file->ceilling.green, \
		file->ceilling.blue);
	for (int y = 0; y < half_height; y++)
	{
		for (int x = 0; x < 640; x++)
		{
			my_mlx_pixel_put(data, x, y, hex_color_c); //bleu ciel
		}
	}
	for (int y = half_height; y < 480; y++)
	{
		for (int x = 0; x < 640; x++)
		{
			my_mlx_pixel_put(data, x, y, hex_color_f); //sol vert
		}
	}
}


int		main(int argc, char **argv)
{
	t_file	file;
	t_img	vars;

	if (argc < 2 || argv[2])
		ft_error("Error, not enough arguments");
	if (!ft_start_parse(&file, argv[1]))
	{
		printf("parsing OK\n");
		ft_game_start(&file);
		//system("leaks cub3D");
		exit(0);
	}
	else
	{
		printf("Re-try with a good map!\n");
		//system("leaks cub3D");
		//pas oublier de free!!!!!
	}
	return (0);
}
