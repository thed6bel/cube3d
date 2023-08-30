/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:26:22 by lowathar          #+#    #+#             */
/*   Updated: 2023/08/30 15:12:34 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d_bonus.h"

int	cub_keyup(int k, t_file *g)
{
	if (k == KEY_LEFT)
		g->pl.keys.left_pressed = 0;
	else if (k == KEY_RIGHT)
		g->pl.keys.right_pressed = 0;
	else if (k == KEY_W)
		g->pl.keys.w_pressed = 0;
	else if (k == KEY_A)
		g->pl.keys.a_pressed = 0;
	else if (k == KEY_S)
		g->pl.keys.s_pressed = 0;
	else if (k == KEY_D)
		g->pl.keys.d_pressed = 0;
	else if (k == KEY_E)
		action_door(g);
	return (0);
}

int	cub_keydown(int k, t_file *g)
{
	if (k == KEY_Q || k == KEY_ESC)
		cub_end(g);
	if (k == KEY_LEFT)
		g->pl.keys.left_pressed = 1;
	else if (k == KEY_RIGHT)
		g->pl.keys.right_pressed = 1;
	else if (k == KEY_W)
		g->pl.keys.w_pressed = 1;
	else if (k == KEY_A)
		g->pl.keys.a_pressed = 1;
	else if (k == KEY_S)
		g->pl.keys.s_pressed = 1;
	else if (k == KEY_D)
		g->pl.keys.d_pressed = 1;
	return (0);
}

t_vector	ft_newvector(int x, int y)
{
	t_vector	position;

	position.x = x;
	position.y = y;
	return (position);
}

void	init_attr(t_file *g)
{
	g->win_ptr = mlx_new_window(g->mlx_ptr, WIN_W, WIN_H, "Cub3D");
	g->win_img.i = mlx_new_image(g->mlx_ptr, WIN_W, WIN_H);
	g->win_img.addr = mlx_get_data_addr(g->win_img.i, &g->win_img.bpp, \
		&g->win_img.line_len, &g->win_img.endian);
	g->win_g.i = mlx_new_image(g->mlx_ptr, WIN_W, WIN_H);
	g->win_g.addr = mlx_get_data_addr(g->win_g.i, &g->win_g.bpp, \
		&g->win_g.line_len, &g->win_g.endian);
	my_mlx_area_put(&g->win_g, ft_newvector(0, 0), \
		ft_newvector(WIN_W, WIN_H), 0x0000FF00);
	g->win_r.i = mlx_new_image(g->mlx_ptr, WIN_W, WIN_H);
	g->win_r.addr = mlx_get_data_addr(g->win_r.i, &g->win_r.bpp, \
		&g->win_r.line_len, &g->win_r.endian);
	my_mlx_area_put(&g->win_r, ft_newvector(0, 0), \
		ft_newvector(WIN_W, WIN_H), 0x00FF0000);
	g->minimap.i = mlx_new_image(g->mlx_ptr, g->width * SIZE, \
		g->height * SIZE);
	g->minimap.addr = mlx_get_data_addr(g->minimap.i, &g->minimap.bpp, \
		&g->minimap.line_len, &g->minimap.endian);
	g->miniview.i = mlx_new_image(g->mlx_ptr, 30 * SIZE, 15 * SIZE);
	g->miniview.addr = mlx_get_data_addr(g->miniview.i, &g->miniview.bpp, \
		&g->miniview.line_len, &g->miniview.endian);
	g->miniview.width = 30 * SIZE;
	g->miniview.height = 15 * SIZE;
}

void	ft_game_start(t_file *g)
{
	init_attr(g);
	init_ray(g);
	mlx_hook(g->win_ptr, 02, 1L << 0, cub_keydown, g);
	mlx_hook(g->win_ptr, 03, 1L << 1, cub_keyup, g);
	mlx_hook(g->win_ptr, 17, 0, cub_end, g);
	mlx_hook(g->win_ptr, 04, 1L << 2, cub_mouse_press, g);
	mlx_hook(g->win_ptr, 05, 1L << 3, cub_mouse_release, g);
	mlx_hook(g->win_ptr, 06, 1L << 6, cub_motion_hook, g);
	mlx_loop_hook(g->mlx_ptr, cub_update, g);
	mlx_loop(g->mlx_ptr); 
}
