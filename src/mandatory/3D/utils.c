/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:37:32 by lowathar          #+#    #+#             */
/*   Updated: 2023/08/30 12:05:50 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

float	degree_to_radians(float degree)
{
	return (degree * M_PI / 180);
}

void	go_black(t_file *g)
{
	int	x;
	int	y;

	x = 0;
	while (x <= WIN_W)
	{
		y = 0;
		while (y <= WIN_H)
		{
			my_mlx_pixel_put(&g->win_img, x, y, 0x000000);
			y++;
		}
		x++;
	}
}
