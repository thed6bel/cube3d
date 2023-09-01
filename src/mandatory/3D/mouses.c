/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:02:43 by hucorrei          #+#    #+#             */
/*   Updated: 2023/09/01 15:04:39 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

int	cub_mouse_press(int button, int x, int y, t_file *g)
{
	(void)button;
	(void)y;
	if (x >= 0 && y >= 0 && x <= 1080 && y <= 720)
	{
		g->is_mouse_pressed = 1;
		g->prev_x = x;
	}
	return (0);
}

int	cub_mouse_release(int button, int x, int y, t_file *g)
{
	(void)button;
	(void)x;
	(void)y;
	g->is_mouse_pressed = 0;
	return (0);
}

int	cub_motion_hook(int x, int y, t_file *g)
{
	int	delta_x;

	delta_x = x - g->prev_x;
	if (g->is_mouse_pressed && delta_x > 0 && x >= 0 && y >= 0 && x \
		<= 1080 && y <= 720)
		g->ray.angle += 3;
	else if (g->is_mouse_pressed && delta_x < 0 && x >= 0 && y >= 0 && x \
		<= 1080 && y <= 720)
		g->ray.angle -= 3;
	g->prev_x = x;
	return (0);
}
