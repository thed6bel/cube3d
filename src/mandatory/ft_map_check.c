/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 11:43:35 by hucorrei          #+#    #+#             */
/*   Updated: 2023/07/10 15:04:00 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"

// char	*ft_check_xpm()
// {
	
// }

// static void	ft_valide_ext(char *map)
// {
// 	int fd;
// 	int	end;

// 	fd = open(argv[1], O_RDONLY);
// 	if (fd < 0)
// 		ft_error("Error\nMap cannot be read or does not exist");
// 	close(fd);
// 	end = (ft_strlen(&argv[1][0]) - 1);
// 	if (argv[1][end] != 'b' || argv[1][end - 1] != 'u'
// 		|| argv[1][end - 2] != 'c' || argv[1][end - 3] != '.')
// 		ft_error("Error\nExtension map error, only .cub maps");
// }

void	ft_ctrl_argc(int argc, char **argv)
{
	int fd;
	int	end;
	if (argv[2])
		ft_error("Error, too many arguments");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error("Error, map cannot be read or does not exist");
	close(fd);
	end = (ft_strlen(&argv[1][0]) - 1);
	if (argv[1][end] != 'b' || argv[1][end - 1] != 'u'
		|| argv[1][end - 2] != 'c' || argv[1][end - 3] != '.')
		ft_error("Error, extension map error: only .cub maps");
}
