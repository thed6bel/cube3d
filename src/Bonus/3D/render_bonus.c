/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:11:08 by lowathar          #+#    #+#             */
/*   Updated: 2023/08/30 15:15:48 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d_bonus.h"

void	redraw_elem(t_file *g, t_img img, int x, int y)
{
	int		p[2];
	t_img	images[2];

	p[0] = x;
	p[1] = y;
	images[0] = img;
	images[1] = g->win_img;
	mlx_img_to_img(p, images, 0xFF000000);
}

void	check_move(t_file *g)
{
	if (g->pl.keys.left_pressed)
		g->ray.angle -= 3;
	if (g->pl.keys.right_pressed)
		g->ray.angle += 3;
	if (g->pl.keys.w_pressed)
		move_pl(KEY_W, g, 0, 0);
	if (g->pl.keys.a_pressed)
		move_pl(KEY_A, g, 0, 0);
	if (g->pl.keys.s_pressed)
		move_pl(KEY_S, g, 0, 0);
	if (g->pl.keys.d_pressed)
		move_pl(KEY_D, g, 0, 0);
}

int	cub_update(void *param)
{
	t_file	*g;

	g = param;
	if (!(g->nframes % g->rate))
	{
		// if (!(g->nframes % (2 * g->rate))) // a check pouranimation door 
		// 	animation(g);
		if (!(g->nframes % (10 * g->rate)))
			g->pl.door_cooldown = 0;
		check_move(g);
		cub_minimap(g);
		cub_raycast(g);
		cub_miniview(g);
		redraw_elem(g, *g->scope, WIN_W / 2 - g->scope->width / 2, \
			WIN_H / 2 - g->scope->height / 2);
		redraw_elem(g, g->miniview, WIN_W - g->miniview.width - 20, \
			WIN_H - g->miniview.height - 20);
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->win_img.i, 0, 0);
	}
	g->nframes++;
	return (0);
}
