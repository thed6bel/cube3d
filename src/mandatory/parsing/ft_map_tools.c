/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:01:33 by hucorrei          #+#    #+#             */
/*   Updated: 2023/08/22 14:06:57 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h" 

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
	//MALLOC file->map
}

int ft_ligne_valide_debut(char *ligne)
{
	int i = 0;

	while (ligne[i] == ' ' || ligne[i] == '\t')
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

int ft_ligne_valide(char *line)
{
	int i;
	int len;
	
	i = 0;
	len = ft_strlen(line);
	while (i < len)
	{
		if (line[i] != ' ' && line[i] != '1' && line[i] != '\t')
			return (0);
		i++;
	}
	printf("len = %i\n", len);
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
	if (x < max_x - 1 && (map[x + 1][y] == ' ' || map[x + 1][y] == '\0'))
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
