/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 10:58:25 by hucorrei          #+#    #+#             */
/*   Updated: 2023/08/22 13:56:51 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "../libft/libft.h"
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_mlx;

typedef struct s_rgb
{
	int	red;
	int	green;
	int	blue;
}	t_rgb;

typedef struct s_file
{
		int		fd;
		char	**map;
		char	*file_path;
		char	*no; //t_tex
		char	*so;
		char	*we;
		char	*ea;
		t_rgb	floor;
		t_rgb	ceilling;
		char	player_dir; //t_player dir
}				t_file;

void	ft_ctrl_argc(int argc, char **argv);

//ft_tools
void	ft_error(char *message);
char	*ft_trim(const char *str);
int		ft_ncmp(const char *s1, const char *s2, size_t n);
int		is_valid_map_obj(char c, t_file *file);
int		is_player(char c, t_file *file);
int		ft_strisspace(const char *str);


//ft_init
int	ft_file_init(t_file *cub, char *file_path);

//ft_rgb
int	ft_check_colors(t_file *file);
int	ft_get_colors(t_rgb *rgb, char *str);
int	ft_color_export(char *str);

//ft_parsing
int	ft_start_parse(t_file *cub, char *file_path);
int	ft_file_check(char *file_path, char *type);
int	ft_file_load_tiles(t_file *file);
int	ft_check_tile(char **tile, char *line, char *cardinal);

//ft_map
int	ft_map(t_file *file);
int ft_valide_map(char **map, int *nb_lines);
int	ft_map_player_count(char **map, t_file *file);

//ft_map_tools.c
int	ft_get_map_alloc(t_file *file, int size);
int ft_ligne_valide_debut(char *ligne);
int ft_ligne_valide_fin(char *ligne);
int ft_ligne_valide(char *line);
int ft_check_around(char **map, int x, int y, int max_x);

#endif