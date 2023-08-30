/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_tools_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:01:33 by hucorrei          #+#    #+#             */
/*   Updated: 2023/08/30 15:25:00 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d_bonus.h" 

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

int	ft_line_valid_start(char *ligne)
{
	int	i;

	i = 0;
	while (ligne[i] == ' ' || ligne[i] == '\t')
		i++;
	return (ligne[i] == '1'); 
}

int	ft_line_valid_end(char *ligne)
{
	int	len;

	len = ft_strlen(ligne);
	while (ligne[len - 2] == ' ')
		len--;
	return (ligne[len - 2] == '1');
}

int	ft_line_valid(char *line)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(line);
	while (i < len)
	{
		if (line[i] != ' ' && line[i] != '1' && line[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_around(char **map, int x, int y, int max_x)
{
	if (x > 0 && map[x - 1][y] == ' ')
		return (1);
	if (y > 0 && map[x][y - 1] == ' ')
		return (1);
	if (x < max_x - 1 && (map[x + 1][y] == ' ' || map[x + 1][y] == '\0'))
		return (1);
	if (map[x][y + 1] == '\n' || map[x][y + 1] == '\0')
		return (1);
	return (0);
}
