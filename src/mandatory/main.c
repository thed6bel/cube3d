/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 10:57:59 by hucorrei          #+#    #+#             */
/*   Updated: 2023/07/19 10:10:19 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"

void my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int rgb_to_hex(int r, int g, int b) {
    return (r << 16) + (g << 8) + b;
}

void ft_floor_cloud_color(t_mlx *data, t_file *file)
{
    int half_height = 480 / 2;

	int hex_color_f = rgb_to_hex(file->floor.red, file->floor.green, file->floor.blue);
	int hex_color_c = rgb_to_hex(file->ceilling.red, file->ceilling.green, file->ceilling.blue);
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
	t_mlx	vars;
    t_file	file;
    
	if (argv[2])
		ft_error("Error, too many arguments");
    if (!ft_start_parse(&file, argv[1]))
    {
		printf("parsing OK\n");
		vars.mlx = mlx_init();
		vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
		vars.img = mlx_new_image(vars.mlx, 640, 480);
		vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, &vars.line_length, &vars.endian);
		ft_floor_cloud_color(&vars, &file);
		mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);
		mlx_loop(vars.mlx);
		// ft_start_3d(&cub);
		// ft_free_all_to_exit(&cub);
		// exit(0);
	}
	else
	{
		printf("Error, re-try with a good map!\n");
	}
	return (0);
}
