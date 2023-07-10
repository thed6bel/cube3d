/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 10:58:25 by hucorrei          #+#    #+#             */
/*   Updated: 2023/07/10 14:55:44 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "../../libft/libft.h"
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_map
{
	int		x;
	int		y;
	int		floor;
	int		ceiling;
	char	**map;
}				t_map;

typedef struct s_texture
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}				t_texture;

void	ft_ctrl_argc(int argc, char **argv);
void	ft_error(char *message);

#endif