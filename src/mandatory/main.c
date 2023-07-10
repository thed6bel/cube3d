/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 10:57:59 by hucorrei          #+#    #+#             */
/*   Updated: 2023/07/10 14:31:49 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void ft_floor_cloud_color(t_data *data)
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


// int		main(int argc, char **argv)
// {
// 	t_vars	vars;
// 	t_data	img;

// 	if (argc == 2)
// 	{
// 		vars.mlx = mlx_init();
// 		vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
// 		img.img = mlx_new_image(vars.mlx, 640, 480);
// 		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
// 		ft_floor_cloud_color(&img);
// 		mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
// 		mlx_loop(vars.mlx);
// 	}
// 	else
// 	{
// 		printf("Error\n");
// 	}
// 	return (0);
// }

int		main(int argc, char **argv)
{
	t_data	*data;
	
	ft_ctrl_argc(argc, argv);
}