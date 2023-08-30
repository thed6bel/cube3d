/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:28:29 by lowathar          #+#    #+#             */
/*   Updated: 2023/08/30 15:07:29 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "../libft/libft.h"
# include "my_mlx_bonus.h"
# include "keycode_bonus.h"
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>

# ifndef WIN_H
#  define WIN_H 720
# endif

# ifndef WIN_W
#  define WIN_W 1080
# endif

# ifndef SIZE
#  define SIZE 7
# endif


typedef struct s_rgb
{
	int	red;
	int	green;
	int	blue;
}	t_rgb;

typedef struct s_key
{
	int	w_pressed;
	int	a_pressed;
	int	s_pressed;
	int	d_pressed;
	int	left_pressed;
	int	right_pressed;
}				t_key;

typedef struct s_player
{
	float	x;
	float	y;
	char	dir;
	float	speed;
	int		door_cooldown;
	t_key	keys;
}				t_player;

typedef struct s_ray
{
	float	incre_angle;
	float	angle;
	float	cos;
	float	sin;
	float	hfov;
	float	lim;
	int		precision;
}				t_ray;

typedef struct s_tex
{
	char	*n;
	t_img	*n_bak;
	char	*s;
	t_img	*s_bak;
	char	*w;
	t_img	*w_bak;
	char	*e;
	t_img	*e_bak;
	t_img	*b;
	t_img	*door_c;
	int		floor;
	int		ceiling;
}				t_tex;

typedef struct s_file
{
	int			prev_x;
	int			is_mouse_pressed;
	int			fd;
	char		**map;
	char		*file_path;
	int			height;
	int			width;
	int			mouse_x;
	int			rate;
	int			neg;
	long		nframes;
	void		*mlx_ptr;
	void		*win_ptr;
	t_rgb		floor;
	t_rgb		ceilling;
	t_img		win_img;
	t_img		win_g;
	t_img		win_r;
	t_img		minimap;
	t_img		miniview;
	t_img		*scope;
	t_tex		tex;
	t_ray		ray;
	t_player	pl;
	float		x;
	float		y;
}				t_file;

//moves.c
int 			cub_mouse_press(int button, int x, int y, t_file *g);
int 			cub_mouse_release(int button, int x, int y, t_file *g);
int				cub_motion_hook(int x, int y, t_file *g);

//game_start.c
void			ft_game_start(t_file *g);
void			init_attr(t_file *g);
t_vector		ft_newvector(int x, int y);

//render.c
int				cub_update(void *param);
void			check_move(t_file *g);
void			redraw_elem(t_file *g, t_img img, int x, int y);


//my_mlx.c
void			my_mlx_pixel_put(t_img *data, int x, int y, int color);
unsigned int	my_mlx_pixel_get(t_img *data, int x, int y);
void			my_mlx_area_put(t_img *d, t_vector p, t_vector dim, int c);
void			mlx_img_to_img(int p[2], t_img img[2], int c1);
t_img			*mlx_load_img(void *ptr, char *path);

//player.c
void			move_pl(int k, t_file *g, float ray_cos, float ray_sin);
void			action_door(t_file *g);
float			distance_to_door(t_file *g, float ray_angle, float *x, float *y);

//raycast.c
void			init_ray(t_file *g);
float			distance_to_wall(t_file *g, float ray_angle);
void			cub_raycast(t_file *g);

//texture.c
t_img			*get_texture(t_file *g);
int				get_tex_color(t_file *g, t_img *i, int z);
void			draw_texture(t_file *g, t_img *i, int ray_count, int wall_height);
void			cub_draw(t_file *g, int ray_count, float dis);


//minimap.c
void			cub_minimap(t_file *g);
int				get_mini_color(t_file *g, int len, int xy[2]);
void			cub_miniview(t_file *g);

//utils.c
float			degree_to_radians(float degree);
void			go_black(t_file *g);

//end.c
void			ft_free_matrix(char ***m);
void			destroy_images(t_file *g);
int				cub_end(t_file *g);

///////////
//PARSING//
///////////

void			ft_ctrl_argc(int argc, char **argv);
int				rgb_to_hex(int r, int g, int b);

//ft_tools
void			ft_error(char *message);
char			*ft_trim(const char *str);
int				ft_ncmp(const char *s1, const char *s2, size_t n);
int				is_valid_map_obj(char c, t_file *file);
int				is_player(char c, t_file *file);
int				ft_strisspace(const char *str);

//ft_init & ft_init2
int				ft_file_init(t_file *cub, char *file_path);
void			cub_init(t_file *g);
void			init_sprites(t_file *g);
int				ft_file_c(char *file_path, char *type);


//ft_rgb
int				ft_check_colors(t_file *file);
int				ft_get_colors(t_rgb *rgb, char *str);
int				ft_color_export(char *str);

//ft_parsing
int				ft_check_t(char **tile, char *line, char *cardinal);
int				ft_file_load_tiles(t_file *file);
int				ft_start_parse(t_file *cub, char *file_path);

//ft_map
int				ft_map(t_file *file);
int				ft_valid_map(char **map, int *nb_lines);
int				ft_map_player_count(char **map, t_file *file);

//ft_map_tools.c
int				ft_get_map_alloc(t_file *file, int size);
int				ft_line_valid_start(char *ligne);
int				ft_line_valid_end(char *ligne);
int				ft_line_valid(char *line);
int				ft_check_around(char **map, int x, int y, int max_x);

#endif