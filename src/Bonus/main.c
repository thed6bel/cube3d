/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowathar <lowathar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 10:57:59 by hucorrei          #+#    #+#             */
/*   Updated: 2023/08/25 14:48:29 by lowathar         ###   ########.fr       */
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
	//printf("floor %d\nciel %d\n", hex_color_f, hex_color_c);
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
		// file.mlx_ptr = mlx_init();
		// file.win_ptr = mlx_new_window(file.mlx_ptr, 640, 480, "Hello world!");
		// vars.i = mlx_new_image(file.mlx_ptr, 640, 480);
		// vars.addr = mlx_get_data_addr(vars.i, &vars.bpp, &vars.line_len, &vars.endian);
		// ft_floor_cloud_color(&vars, &file);
		// mlx_put_image_to_window(file.mlx_ptr, file.win_ptr, vars.i, 0, 0);
		// mlx_loop(file.mlx_ptr);
		// ft_start_3d(&cub);
		// ft_free_all_to_exit(&cub);
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
