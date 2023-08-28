/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:17:36 by thed6bel          #+#    #+#             */
/*   Updated: 2023/08/28 15:20:15 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

int	ft_file_c(char *file_path, char *type)
{
	char	*temp;
	int		i;
	int		fd;

	if (!file_path)
		return (printf("NULL file path! EXPECTED: '*%s'\n", type));
	i = 0;
	temp = type;
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (printf("Exception: %s: '%s'\n", file_path, strerror(errno)));
	while (file_path[i] && (file_path[i] != '.' || file_path[i + 1] == '/'))
		i++;
	if ((!i || file_path[i - 1] == '/') && !close(fd))
		return (printf("Bad file name!\n"));
	while (file_path[i] && *type && file_path[i] == *type++)
		i++;
	if (!*type && !file_path[i])
		return (close(fd));
	else if (!close(fd))
		printf("Bad file type! EXPECTED: '*%s'\n", temp);
	return (1);
}

void	init_sprites(t_file *g)
{
	g->win_img.i = NULL;
	g->win_g.i = NULL;
	g->win_r.i = NULL;
	g->minimap.i = NULL;
	g->miniview.i = NULL;
	g->tex.n = NULL;
	g->tex.s = NULL;
	g->tex.w = NULL;
	g->tex.e = NULL;
	g->tex.n_bak = NULL;
	g->tex.s_bak = NULL;
	g->tex.w_bak = NULL;
	g->tex.e_bak = NULL;
	g->prev_x = 0;
	g->is_mouse_pressed = 0;
	// g->tex.b = mlx_load_img(g->mlx_ptr, "image/black.xpm");
	// g->scope = mlx_load_img(g->mlx_ptr, "image/scope.xpm");
}

void	cub_init(t_file *g)
{
	g->width = 0;
	g->fd = -1;
	g->height = 0;
	g->nframes = 0;
	g->map = NULL;
	g->pl.dir = 0;
	g->mlx_ptr = NULL;
	g->win_ptr = NULL;
	g->mlx_ptr = mlx_init();
	init_sprites(g);
	g->tex.floor = -1;
	g->tex.ceiling = -1;
	g->pl.x = -1;
	g->pl.y = -1;
	g->pl.speed = 0.06;
	g->pl.door_cooldown = 0;
	ft_bzero(&g->pl.keys, sizeof(t_key));
	g->mouse_x = 0;
	g->neg = -1;
	g->rate = 30;
}

int	ft_file_init(t_file *file, char *file_path)
{
	file->ceilling.red = -1;
	file->ceilling.green = -1;
	file->ceilling.blue = -1;
	file->floor.red = -1;
	file->floor.green = -1;
	file->floor.blue = -1;
	cub_init(file);
	file->map = NULL;
	file->pl.dir = '\0';
	file->file_path = ft_trim(file_path);
	if (ft_file_c(file->file_path, ".cub"))
		return (1);
	file->fd = open(file->file_path, O_RDONLY);
	return (0);
	//MALLOC file_path
}
