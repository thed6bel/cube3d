/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 10:01:27 by hucorrei          #+#    #+#             */
/*   Updated: 2023/07/24 10:19:16 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cube3d.h"

int is_map_valid(char **map)
{
    int player_count = 0;

    for (int i = 0; map[i]; i++)
    {
        for (int j = 0; map[i][j]; j++)
        {
            if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W')
                player_count++;
            if ((i == 0 || !map[i+1] || j == 0 || !map[i][j+1]) && map[i][j] != '1')
                return 0;
        }
    }
    if (player_count != 1)
        return 0;
    return 1;
}

int	ft_map(t_file *file)
{
	char	*line;
	char	**temp_map;
	int		i;
	int		MAP_MAX_SIZE;
	int		j;

	MAP_MAX_SIZE = ft_map_max_size(file);
	temp_map = (char **)malloc(sizeof(char *) * MAP_MAX_SIZE);
	if (!temp_map)
		return 1;
	i = 0;
	while ((line = get_next_line(file->fd)))
	{
		for (j = 0; line[j]; j++) {
			if (line[j] != '0' && line[j] != '1' && line[j] != 'N' && line[j] != 'S' &&
				line[j] != 'E' && line[j] != 'W' && line[j] != ' ')
			{
				free(line);
				return 1;
			}
		}
		temp_map[i] = ft_strdup(line);
		free(line);
		i++;
	}
	file->map = temp_map;
	if (!is_map_valid(file->map))
	{
		printf("Error: Invalid map!\n");
		//free tout les malloc
		return 1;
	}
	return 0;
}
