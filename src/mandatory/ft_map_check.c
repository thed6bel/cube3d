/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 11:43:35 by hucorrei          #+#    #+#             */
/*   Updated: 2023/07/10 14:40:16 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"

char	*ft_check_xpm()
{
	
}

static void	ft_valide_ext(char *map)
{
	int fd;
	int	end;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_error("Error\nMap cannot be read or does not exist");
	close(fd);
	end = (ft_strlen(&map[0]) - 1);
	if (map[end] != 'b' || map[end - 1] != 'u'
		|| map[end - 2] != 'c' || map[end - 3] != '.')
		ft_error("Error\nExtension map error, only .cub maps");
}

void	ft_ctrl_argc(int argc, char **argv)
{
	if (argc < 2)
		ft_error("Error\nNo map file");
	ft_valide_ext(argv[1]);
}
