/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 10:01:27 by hucorrei          #+#    #+#             */
/*   Updated: 2023/07/25 14:40:50 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cube3d.h" 

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
				return (printf("Check map error! '%c' Is invalid321\n", map[y][x]));
			if (is_player(map[y][x], file))
				player++;
		}
	}
	if (player != 1)
	{
		printf("Check map error! %i player(s) set in map!'\n", player);
		return (1);
	}
	return (0);
}

int ft_valide_map(char **map, int *nb_lines)
{
	int	i;
	int	j;
	char **tmp;

	tmp = map;
	if (*nb_lines == 0) 
	{
		while (map[*nb_lines])
		(*nb_lines)++;
	}
	i = 0;
	printf("nb_lines = %i\n", *nb_lines);
	printf("test ft_val_map\n");
	if (!ft_ligne_valide(tmp[i]) || !ft_ligne_valide(tmp[*nb_lines - 1]))
	{
		printf("Error: Map not closed333333333333333333333333333333333\n");
		return (1);
	}
	while (i < *nb_lines)
	{
		if (!ft_ligne_valide_debut(map[i]) || !ft_ligne_valide_fin(map[i]))
		{
			printf("Error: Map not closed11111111111111111111111111111\n");
			return (1);
		}
		
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S' 
				|| map[i][j] == 'E' || map[i][j] == 'W')
			{
				if (ft_check_around(map, i, j, *nb_lines))
				{
					printf("Error: Map not closed or space inside 222222222222222222222222\n");
					return (1);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}


int	ft_map(t_file *file)
{
	char	**checkmap;
	int 	nb_lines;

	checkmap = NULL;
	nb_lines = 0;
	if (ft_get_map_alloc(file, 0) || ft_map_player_count(file->map, file))
		return (1);
	printf("test map[3] = %s\n", file->map[3]);
	if(ft_valide_map(file->map, &nb_lines))
		return (1);
	return (0);
}

