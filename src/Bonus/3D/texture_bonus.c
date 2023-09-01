/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowathar <lowathar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:29:57 by lowathar          #+#    #+#             */
/*   Updated: 2023/09/01 14:39:14 by lowathar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d_bonus.h"

t_list	*get_anim(t_img *img, t_list **anim)
{
	if (!img)
		return (*anim);
	// if (!img->i)
	// {
	// 	free(img);
	// 	printf("shoooooooooooooo\n");
	// 	return (*anim);
	// }
	printf("height : %d\n", img->height);
	ft_lstadd_back(anim, ft_lstnew(img));
	return (*anim);
}

void	text_lst_init(t_file *g)
{
	t_img *i;

	g->tex.door_c_bak = get_anim(mlx_load_img(g->mlx_ptr, "./image/animation/port1_c.xpm"), &g->tex.door_c);
	i = g->tex.door_c_bak->content;
	printf("height : %d\n", i->height);
	g->tex.door_c_bak = get_anim(mlx_load_img(g->mlx_ptr, "./image/animation/port2_c.xpm"), &g->tex.door_c);
	g->tex.door_c_bak = get_anim(mlx_load_img(g->mlx_ptr, "./image/animation/port3_c.xpm"), &g->tex.door_c);
	g->tex.door_c_bak = get_anim(mlx_load_img(g->mlx_ptr, "./image/animation/port4_c.xpm"), &g->tex.door_c);
	g->tex.door_c_bak = get_anim(mlx_load_img(g->mlx_ptr, "./image/animation/port5_c.xpm"), &g->tex.door_c);
	g->tex.door_c_bak = get_anim(mlx_load_img(g->mlx_ptr, "./image/animation/port6_c.xpm"), &g->tex.door_c);
	g->tex.door_c_bak = get_anim(mlx_load_img(g->mlx_ptr, "./image/animation/port7_c.xpm"), &g->tex.door_c);
}

t_img	*get_texture(t_file *g)
{
	t_img	*i;
	float	ray_cos;
	float	ray_sin;

	ray_cos = g->ray.cos;
	if (ray_cos < 0)
		ray_cos = -ray_cos;
	ray_sin = g->ray.sin;
	if (ray_sin < 0)
		ray_sin = -ray_sin;
	i = g->tex.b;
	if (g->map[(int)g->y][(int)g->x] == 'c')
	{
		i = g->tex.door_c->content;
		return (i);
	}
	if (g->map[(int)(g->y - ray_sin)][(int)g->x] != '1')
		i = g->tex.n_bak;
	else if (g->map[(int)(g->y + ray_sin)][(int)g->x] != '1')
		i = g->tex.s_bak;
	else if (g->map[(int)g->y][(int)(g->x + ray_cos)] != '1')
		i = g->tex.e_bak;
	else if (g->map[(int)g->y][(int)(g->x - ray_cos)] != '1')
		i = g->tex.w_bak;
	return (i);
}

int	get_tex_color(t_file *g, t_img *i, int z)
{
	int	color;

	color = 0x00000000;
	if (g->map[(int)g->y][(int)g->x] == '1')
		color = my_mlx_pixel_get(i, (int)(i->width * (g->x + g->y)) \
			% i->width, z);
	else if (g->map[(int)g->y][(int)g->x] == 'c')
		color = my_mlx_pixel_get(i, (int)(i->width * (g->x + g->y)) \
			% i->width, z);
	return (color);
}

void	draw_texture(t_file *g, t_img *i, int ray_count, int wall_height)
{
	float	dy;
	float	ds;
	float	cy[2];
	int		z;
	int		color;

	if (!i)
		return ;
	dy = ((float)wall_height * 2) / (float)i->height;
	ds = ((float)WIN_H / 2) - (float)wall_height;
	cy[1] = ds;
	z = -1;
	while (++z < i->height)
	{
		color = get_tex_color(g, i, z);
		//color = get_dist_color(color, ds, 0); si on decide pour la profondeur
		cy[0] = cy[1];
		while (cy[0] < cy[1] + dy)
		{
			if (cy[0] >= 0 && cy[0] < (float)WIN_H)
				my_mlx_pixel_put(&g->win_img, ray_count, cy[0], color);
			cy[0]++;
		}
		cy[1] += dy;
	}
}

void	cub_draw(t_file *g, int ray_count, float dis)
{
	int		wall_height;
	float	ds;
	int		j;
	int		hex_color_f;
	int		hex_color_c;

	wall_height = (int)(WIN_H / (1.5 * dis));
	hex_color_f = rgb_to_hex(g->floor.red, g->floor.green, \
		g->floor.blue);
	hex_color_c = rgb_to_hex(g->ceilling.red, g->ceilling.green, \
		g->ceilling.blue);
	ds = ((float)WIN_H / 2) - (float)wall_height;
	j = -1;
	while (++j < WIN_H)
	{
		if (j < ds)
			my_mlx_pixel_put(&g->win_img, ray_count, j, \
				hex_color_c);
		else if (j >= (WIN_H / 2) + wall_height)
			my_mlx_pixel_put(&g->win_img, ray_count, j, \
				hex_color_f);
	}
	draw_texture(g, get_texture(g), ray_count, wall_height);
}
