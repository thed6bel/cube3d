/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowathar <lowathar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:06:08 by lowathar          #+#    #+#             */
/*   Updated: 2023/08/30 13:17:24 by lowathar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d_bonus.h"

void	init_ray(t_file *g)
{
	g->ray.angle = 0;
	if (g->pl.dir == 'S')
		g->ray.angle = 90;
	else if (g->pl.dir == 'W')
		g->ray.angle = 180;
	else if (g->pl.dir == 'N')
		g->ray.angle = 270;
	g->ray.hfov = 30;
	g->ray.incre_angle = 2 * g->ray.hfov / WIN_W;
	g->ray.precision = 50;
	g->ray.lim = 11;
	g->tex.n_bak = mlx_load_img(g->mlx_ptr, g->tex.n);
	g->tex.s_bak = mlx_load_img(g->mlx_ptr, g->tex.s);
	g->tex.w_bak = mlx_load_img(g->mlx_ptr, g->tex.w);
	g->tex.e_bak = mlx_load_img(g->mlx_ptr, g->tex.e);
	g->tex.door_c = mlx_load_img(g->mlx_ptr, "image/animation/port1_c.xpm");
	g->tex.door_o = mlx_load_img(g->mlx_ptr, "image/animation/port1_o.xpm");
	
}

float	distance_to_wall(t_file *g, float ray_angle)
{
	float	d;

	g->ray.cos = cos(degree_to_radians(ray_angle)) / g->ray.precision;
	g->ray.sin = sin(degree_to_radians(ray_angle)) / g->ray.precision;
	g->x = g->pl.x + 0.5;
	g->y = g->pl.y + 0.5;
	while (!ft_strchr("1c", g->map[(int)g->y][(int)g->x])) // without ray_limit
	{
		g->x += g->ray.cos;
		g->y += g->ray.sin;
		if (ft_strchr("1c", g->map[(int)g->y][(int)g->x]))
			my_mlx_pixel_put(&g->minimap, g->x * SIZE, g->y * SIZE, 0x00FF0000);
		else if (ray_angle - 1 < g->ray.angle && ray_angle + 1 > g->ray.angle)
			my_mlx_pixel_put(&g->minimap, g->x * SIZE, g->y * SIZE, 0x0000FF00);
		else
			my_mlx_pixel_put(&g->minimap, g->x * SIZE, g->y * SIZE, 0x00BDC1C6);
	}
	my_mlx_area_put(&g->minimap, ft_newvector((int)(g->pl.x + 0.5) * SIZE, \
		(int)(g->pl.y + 0.5) * SIZE), ft_newvector(SIZE, SIZE), 0x00FDD663);
	d = sqrt(powf(g->x - g->pl.x - 0.5, 2.) + powf(g->y - g->pl.y - 0.5, 2.));
	return (d * cos(degree_to_radians(ray_angle - g->ray.angle)));
}

void	cub_raycast(t_file *g)
{
	float	ray_angle;
	int		ray_count;
	float	dist;

	ray_angle = g->ray.angle - g->ray.hfov;
	ray_count = -1;
	while (++ray_count < WIN_W)
	{
		dist = distance_to_wall(g, ray_angle);
		cub_draw(g, ray_count, dist);
		ray_angle += g->ray.incre_angle;
	}
}
