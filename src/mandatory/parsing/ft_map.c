/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 10:01:27 by hucorrei          #+#    #+#             */
/*   Updated: 2023/07/25 10:55:34 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cube3d.h" 

int	ft_map_player_count(char **map)
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
			if (is_valid_map_obj(map[y][x]))
				return (printf("Check map error! '%c' Is invalid\n", map[y][x]));
			if (is_player(map[y][x]))
				player++;
		}
	}
	if (player != 1)
	{
		printf("Check map error! %i players set in map!'\n", player);
		return (1);
	}
	return (0);
}

int	ft_get_map_alloc(t_file *file, int size)
{
	char	*temp;
	int		result;

	temp = get_next_line(file->fd);
	result = 0;
	while (size == 0 && ft_strisspace(temp))
	{
		free(temp);
		temp = get_next_line(file->fd);
	}
	if (!temp)
	{
		file->map = malloc(sizeof(char *) * (size + 1));
		if (!file->map)
			return (1);
	}
	else
		result = ft_get_map_alloc(file, (size + 1));
	if (result)
		free(temp);
	else
		file->map[size] = temp;
	return (result);
}

int ft_ligne_valide_debut(char *ligne)
{
  int i = 0;

  while (ligne[i] == ' ')
    i++;
  return (ligne[i] == '1'); 
}

int ft_ligne_valide_fin(char *ligne)
{
  int len;

  len = ft_strlen(ligne);
  while (ligne[len - 2] == ' ')
	len--;
  return (ligne[len - 2] == '1');
}

int ft_ligne_valide(char *ligne)
{
    int i;
    
    i = 0;
    while (ligne[i])
    {
        if (ligne[i] != ' ' && ligne[i] != '1')
            return (0);
        i++;
    }
    return (1);
}

int ft_check_around(char **map, int x, int y, int max_x)
{
	if (x > 0 && map[x - 1][y] == ' ')
	{
		printf("x = %i\n", x);
		printf("y = %i\n", y);
		printf("check around 1\n");
		return (1);
	}
	if (y > 0 && map[x][y - 1] == ' ')
	{
		printf("x = %i\n", x);
		printf("y = %i\n", y);
		printf("check around 2\n");
		return (1);
	}
	if (x < max_x - 1 && map[x + 1][y] == ' ')
	{
		printf("x = %i\n", x);
		printf("y = %i\n", y);
		printf("check around 3\n");
		return (1);
	}
	if (map[x][y + 1] == '\n' || map[x][y + 1] == '\0')
	{
		printf("x = %i\n", x);
		printf("y = %i\n", y);
		printf("check around 4\n");
		return (1);
	}
	return (0);
}

int ft_valide_map(char **map, int *nb_lines)
{
	int	i;
	int	j;

	if (*nb_lines == 0) 
	{
		*nb_lines = 0;
		while (map[*nb_lines])
		(*nb_lines)++;
	}
	if (!ft_ligne_valide(map[0]) || !ft_ligne_valide(map[*nb_lines - 1]))
	{
		printf("Error: Map not closed333333333333333333333333333333333\n");
		return (1);
	}
	i = 0;
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
	int 	*nb_lines;

	checkmap = NULL;
	*nb_lines = 0;
	if (ft_get_map_alloc(file, 0) || ft_map_player_count(file->map))
		return (1);
	printf("test map[3] = %s\n", file->map[3]);
	if(ft_valide_map(file->map, nb_lines))
		return (1);
	return (0);
}

