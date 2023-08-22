/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowathar <lowathar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 10:57:59 by hucorrei          #+#    #+#             */
/*   Updated: 2023/08/22 14:08:00 by lowathar         ###   ########.fr       */
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


void	init_sprites(t_file *g)
{
	g->win_img.i = NULL;
	g->win_g.i = NULL;
	g->win_r.i = NULL;
	g->minimap.i = NULL;
	g->miniview.i = NULL;
	g->tex.n = NULL;
	g->tex.n_bak = NULL;
	g->tex.s = NULL;
	g->tex.s_bak = NULL;
	g->tex.e = NULL;
	g->tex.e_bak = NULL;
	g->tex.w = NULL;
	g->tex.w_bak = NULL;
	g->tex.b = mlx_load_img(g->mlx_ptr, "textures/black.xpm");
	g->scope = mlx_load_img(g->mlx_ptr, "textures/scope.xpm");
	if (!g->tex.b || !g->tex.b->i || !g->scope || !g->scope->i)
		cub_perror(inv_pwd, g, NULL, 1);
}

static t_file	cub_init(void)
{
	t_file	g;

	g.width = 0;
	g.fd = -1;
	g.height = 0;
	g.nframes = 0;
	g.map = NULL;
	g.pl.dir = 0;
	g.mlx_ptr = NULL;
	g.win_ptr = NULL;
	g.mlx_ptr = mlx_init();
	init_sprites(&g);
	g.tex.floor = -1;
	g.tex.ceiling = -1;
	g.pl.x = -1;
	g.pl.y = -1;
	g.pl.speed = 0.12;
	g.pl.door_cooldown = 0;
	ft_bzero(&g.pl.keys, sizeof(t_key));
	g.mouse_x = 0;
	g.neg = -1;
	g.rate = 30;
	return (g);
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
		// vars.mlx = mlx_init();
		// vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
		// vars.img = mlx_new_image(vars.mlx, 640, 480);
		// vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, &vars.line_length, &vars.endian);
		// ft_floor_cloud_color(&vars, &file);
		// mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);
		// mlx_loop(vars.mlx);
		// ft_start_3d(&cub);
		// ft_free_all_to_exit(&cub);
		// exit(0);
		//system("leaks cub3D");
	}
	else
	{
		printf("Error, re-try with a good map!\n");
		//pas oublier de free!!!!!
	}
	return (0);
}
