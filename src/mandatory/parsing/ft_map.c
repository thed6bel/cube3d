/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thed6bel <thed6bel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 10:01:27 by hucorrei          #+#    #+#             */
/*   Updated: 2023/07/23 18:51:34 by thed6bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cube3d.h"

int is_map_valid(char **map)
{
    int player_count = 0;

    // Parcourir chaque caractère de la carte
    for (int i = 0; map[i]; i++)
    {
        for (int j = 0; map[i][j]; j++)
        {
            // Compter le nombre de caractères de joueur
            if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W')
                player_count++;
            // Vérifier que la carte est entourée de murs
            if ((i == 0 || !map[i+1] || j == 0 || !map[i][j+1]) && map[i][j] != '1')
                return 0;  // Retourner faux si un caractère non-mur est trouvé sur le bord de la carte
        }
    }
    // Vérifier qu'il y a exactement un caractère de joueur
    if (player_count != 1)
        return 0;  // Retourner faux s'il y a plus ou moins d'un caractère de joueur
    // Si toutes les vérifications passent, retourner vrai
    return 1;
}

int ft_map(t_file *file)
{
    char *line;
    char **temp_map;
    int i = 0;
    int MAP_MAX_SIZE;

    MAP_MAX_SIZE = ft_map_max_size(file);
    temp_map = (char **)malloc(sizeof(char *) * MAP_MAX_SIZE);
    if (!temp_map)
        return 1;
    while ((line = get_next_line(file->fd)))
    {
        for (int j = 0; line[j]; j++) {
            if (line[j] != '0' && line[j] != '1' && line[j] != 'N' && line[j] != 'S' &&
                line[j] != 'E' && line[j] != 'W' && line[j] != ' ') {
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
