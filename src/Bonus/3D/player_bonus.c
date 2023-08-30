/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowathar <lowathar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:36:20 by lowathar          #+#    #+#             */
/*   Updated: 2023/08/30 13:34:55 by lowathar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d_bonus.h"

float	distance_to_door(t_file *g, float ray_angle, float *x, float *y)
{
	float	d;
	float	ray_cos;
	float	ray_sin;

	ray_cos = cos(degree_to_radians(ray_angle)) / g->ray.precision;
	ray_sin = sin(degree_to_radians(ray_angle)) / g->ray.precision;
	*x = g->pl.x + 0.5;
	*y = g->pl.y + 0.5;
	while (!ft_strchr("1oc", g->map[(int)*y][(int)*x]) && \
		sqrt(powf(*x - g->pl.x - 0.5, 2.) + \
		powf(*y - g->pl.y - 0.5, 2.)) < g->ray.lim)
	{
		*x += ray_cos;
		*y += ray_sin;
	}
	d = sqrt(powf(*x - g->pl.x - 0.5, 2.) + powf(*y - g->pl.y - 0.5, 2.));
	d = d * cos(degree_to_radians(ray_angle - g->ray.angle));
	return (d);
}

void	move_pl(int k, t_file *g, float ray_cos, float ray_sin)
{
	float	angle;

	angle = g->ray.angle;
	if (k == KEY_A)
		angle = g->ray.angle - 90;
	else if (k == KEY_S)
		angle = g->ray.angle - 180;
	else if (k == KEY_D)
		angle = g->ray.angle + 90;
	ray_cos = cos(degree_to_radians(angle)) * g->pl.speed;
	ray_sin = sin(degree_to_radians(angle)) * g->pl.speed;
	if (!ft_strchr("1co", g->map[(int)(g->pl.y + 0.5 + \
			(3 * ray_sin))][(int)(g->pl.x + 0.5)]))
		g->pl.y += ray_sin;
	if (!ft_strchr("1co", \
		g->map[(int)(g->pl.y + 0.5)][(int)(g->pl.x + 0.5 + (3 * ray_cos))]))
		g->pl.x += ray_cos;
	// printf("player pos x : %f\nplayer pos y : %f\n", g->pl.x, g->pl.y);
	// printf("player move : %d\n", k); // comment
}

void	action_door(t_file *g)
{
	float	d;
	float	x;
	float	y;

	if (g->pl.door_cooldown || \
			ft_strchr("oc", g->map[(int)(g->pl.y + 0.5)][(int)(g->pl.x + 0.5)]))
		return ;
	d = distance_to_door(g, g->ray.angle, &x, &y);
	if (d < g->ray.lim && g->map[(int)y][(int)x] == 'c')
	{
		g->pl.door_cooldown = 1;
		g->map[(int)y][(int)x] = 'o';
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->win_r.i, 0, 0);
	}
	else if (d < g->ray.lim && g->map[(int)y][(int)x] == 'o')
	{
		g->pl.door_cooldown = 1;
		g->map[(int)y][(int)x] = 'c';
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->win_g.i, 0, 0);
	}
}
