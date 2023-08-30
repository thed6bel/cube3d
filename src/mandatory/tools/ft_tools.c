/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 10:00:36 by thed6bel          #+#    #+#             */
/*   Updated: 2023/08/30 11:07:14 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

int	ft_strisspace(const char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str != '\f' && *str != '\n' && *str != '\r' && *str != '\t'\
			&& *str != '\v' && *str != ' ')
			return (0);
		str++;
	}
	return (1);
}

int	is_player(char c, t_file *file)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (c == 'N')
			file->pl.dir = 'N';
		if (c == 'S')
			file->pl.dir = 'S';
		if (c == 'E')
			file->pl.dir = 'E';
		if (c == 'W')
			file->pl.dir = 'W';
		//printf("player_dir: %c\n", file->pl.dir);
		return (1);
	}
	return (0);
}

int	is_valid_map_obj(char c, t_file *file)
{
	if (c == '0' || c == ' ' || c == '1' || is_player(c, file) || c == '\t')
		return (0);
	return (1);
}

void	ft_error(char *message)
{
	ft_putendl_fd(message, 2);
	exit (1);
}

char	*ft_trim(const char *str)
{
	int		size;
	int		i;
	char	*out;

	out = NULL;
	if (!str)
		return (NULL);
	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;
	i = -1;
	size = 0;
	while (str[++i])
		size++;
	while (i > 0 && (str[--i] == ' ' || str[i] == '\t' || str[i] == '\n'))
		size--;
	out = malloc(sizeof(char) * (size + 1));
	if (!out)
		return (NULL);
	out[size] = 0;
	while (--size >= 0)
		out[size] = str[i--];
	return (out);
}
