/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 10:01:27 by hucorrei          #+#    #+#             */
/*   Updated: 2023/09/04 14:32:29 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d_bonus.h"

int	ft_player_error(int player)
{
	if (player != 1)
	{
		printf("Check map error! %i player(s) set in map!'\n", player);
		printf("Error: Invalid map\n");
		return (1);
	}
	return (0);
}

int	ft_map_player_count(char **map, t_file *file)
{
	int	x;
	int	y;
	int	player;

	y = -1;
	player = 0;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == '\n')
				map[y][x] = ' ';
			if (is_valid_map_obj(map[y][x], file))
				return (printf("Check map error! '%c' Is invalid\n", map[y][x]));
			if (is_player(map[y][x], file))
			{
				player++;
				file->pl.x = (float)x;
				file->pl.y = (float)y;
			}
		}
	}
	return (ft_player_error(player));
}

int	ft_validate_line(char **map, char *line, int l_nb, int total_lines)
{
	int	j;

	if (!ft_line_valid_start(line) || !ft_line_valid_end(line))
	{
		printf("Error: Invalid line at line %d\n", l_nb);
		return (1);
	}
	j = 0;
	while (line[j])
	{
		if (line[j] == '0' || line[j] == 'N' || line[j] == 'S'
			|| line[j] == 'E' || line[j] == 'W' || line[j] == 'c')
		{
			if (ft_check_around(map, l_nb, j, total_lines))
			{
				printf("Error: Map not closed or space inside map");
				printf(" or more of 1 door at line %d\n", (l_nb + 1));
				return (1);
			}
		}
		j++;
	}
	return (0);
}

int	ft_valid_map(char **map, int *nb_lines)
{
	int		i;
	char	**tmp;

	tmp = map;
	if (*nb_lines == 0)
	{
		while (map[*nb_lines])
			(*nb_lines)++;
	}
	i = 0;
	if (!ft_line_valid(tmp[i]) || !ft_line_valid(tmp[*nb_lines - 1]))
	{
		printf("Error: Map not closed\n");
		return (1);
	}
	while (i < *nb_lines)
	{
		if (ft_validate_line(map, map[i], i, *nb_lines))
			return (1);
		i++;
	}
	return (0);
}

int	ft_map(t_file *file)
{
	char	**checkmap;
	int		nb_lines;
	int		i;
	int		line_l;

	i = 0;
	line_l = 0;
	checkmap = NULL;
	nb_lines = 0;
	if (ft_get_map_alloc(file, 0) || ft_map_player_count(file->map, file))
		return (1);
	if (ft_valid_map(file->map, &nb_lines))
		return (1);
	file->height = nb_lines;
	file->width = (ft_strlen(file->map[0]) - 1);
	while (i < file->height)
	{
		line_l = (ft_strlen(file->map[i]) - 1);
		if (line_l > file->width)
			file->width = line_l;
		i++;
	}
	return (0);
}
