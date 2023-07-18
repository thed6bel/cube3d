/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thed6bel <thed6bel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 10:57:59 by hucorrei          #+#    #+#             */
/*   Updated: 2023/07/18 16:20:34 by thed6bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"

void my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void ft_floor_cloud_color(t_mlx *data)
{
    int half_height = 480 / 2;

    for (int y = 0; y < half_height; y++)
    {
        for (int x = 0; x < 640; x++)
        {
            my_mlx_pixel_put(data, x, y, 0x87CEEB); //bleu ciel
        }
    }
    for (int y = half_height; y < 480; y++)
    {
        for (int x = 0; x < 640; x++)
        {
            my_mlx_pixel_put(data, x, y, 0x008000); //sol vert
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
		vars.mlx = mlx_init();
		vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
		vars.img = mlx_new_image(vars.mlx, 640, 480);
		vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, &vars.line_length, &vars.endian);
		ft_floor_cloud_color(&vars);
		mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);
		mlx_loop(vars.mlx);
		// ft_start_3d(&cub);
		// exit(0);
	}
	else
	{
		printf("Error exit112\n");
	}
	return (0);
}
