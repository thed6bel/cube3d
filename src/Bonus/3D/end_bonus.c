/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:22:04 by lowathar          #+#    #+#             */
/*   Updated: 2023/08/30 15:44:00 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d_bonus.h"

void	ft_free_matrix(char ***m)
{
	int	i;

	i = 0;
	while (m && m[0] && m[0][i])
	{
		free(m[0][i]);
		i++;
	}
	if (m)
	{
		free(m[0]);
		*m = NULL;
	}
}

void	free_animation(t_file *g, t_list *start)
{
	t_list	*temp;

	temp = NULL;
	while (start)
	{
		temp = start;
		start = start->next;
		if (g && ((t_img *)temp->content)->i)
			mlx_destroy_image(g->mlx_ptr, ((t_img *)temp->content)->i);
		free(temp->content);
		free(temp);
	}
}

void	destroy_images(t_file *g)
{
	// free_animation(g, ??);
	if (g->win_img.i)
		mlx_destroy_image(g->mlx_ptr, g->win_img.i);
	if (g->win_g.i)
		mlx_destroy_image(g->mlx_ptr, g->win_g.i);
	if (g->win_r.i)
		mlx_destroy_image(g->mlx_ptr, g->win_r.i);
	if (g->win_ptr)
		mlx_destroy_window(g->mlx_ptr, g->win_ptr);
	if (g->minimap.i)
		mlx_destroy_image(g->mlx_ptr, g->minimap.i);
	if (g->miniview.i)
		mlx_destroy_image(g->mlx_ptr, g->miniview.i);
	if (g->file_path)
		free(g->file_path);
	if (g->tex.n)
		free(g->tex.n);
	if (g->tex.s)
		free(g->tex.s);
	if (g->tex.w)
		free(g->tex.w);
	if (g->tex.e)
		free(g->tex.e);
}

int	cub_end(t_file *g)
{
	if (!g)
		return (0);
	ft_free_matrix(&g->map);
	if (g->fd > 0)
		close(g->fd);
	destroy_images(g);
	system("leaks cub3D");
	exit(0);
}
