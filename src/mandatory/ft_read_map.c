/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:36:23 by hucorrei          #+#    #+#             */
/*   Updated: 2023/07/10 14:16:13 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"

static void	ft_valide_ext(char *map)
{
	int	end;

	end = (ft_strlen(&map[0]) - 1);
	if (map[end] != 'b' || map[end - 1] != 'u'
		|| map[end - 2] != 'c' || map[end - 3] != '.')
		ft_error("Error\nExtension map error, only .cub maps");
}

void ft_full_ctrl(char *argv)
{
	ft_valide_ext(argv);
	
}


char	**ft_map_read(char argv[1])
{
	char	*str;
	char	**map;
	int		fd;
	int 	i;

	ft_full_ctrl(argv);
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		ft_error("Error\nMap cannot be read or does not exist");
	str = ft_read_line(fd);
	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[0] == '\n')
			ft_error("Error\nMap error");
		i++;
	}
	if (str[i - 1] == '\n')
		ft_error("Error\nMap error");
	map = ft_split(str, '\n');
	free(str);
	close(fd);
	return (map);
}
