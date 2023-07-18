/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thed6bel <thed6bel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 10:58:25 by hucorrei          #+#    #+#             */
/*   Updated: 2023/07/18 16:52:39 by thed6bel         ###   ########.fr       */
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
	int	t;
}	t_rgb;

typedef struct s_file
{
	int		fd;
	char	*file_path;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	t_rgb	floor;
	t_rgb	ceilling;
	char	**map;
}				t_file;

void	ft_ctrl_argc(int argc, char **argv);

//ft_tools
void	ft_error(char *message);
char	*ft_trim(const char *str);
int		ft_ncmp(const char *s1, const char *s2, size_t n);

//ft_init
int	ft_file_init(t_file *cub, char *file_path);

//ft_rgb
int	ft_check_file_colors(t_file *file);
int	ft_get_file_colors(t_rgb *rgb, char *str);
int	ft_color_line_export(char *str);

//ft_parsing
int	ft_start_parse(t_file *cub, char *file_path);
int	ft_file_check(char *file_path, char *type);
int	ft_file_load_tiles(t_file *file);
int	ft_check_tile(char **tile, char *line, char *cardinal);


#endif