/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:14:37 by thed6bel          #+#    #+#             */
/*   Updated: 2023/09/04 14:30:54 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

int	ft_check_t(char **tile, char *line, char *cardinal)
{
	if (!*tile)
	{
		*tile = ft_trim(line + 2);
		if (!*tile)
			return (printf("Error!\n"));
		return (0);
	}
	else
		free(line);
	printf("ERROR! Double cardinal! '%s'\n", cardinal);
	return (1);
}

int	ft_file_load_tiles(t_file *file)
{
	char	*tmp;

	while (!file->tex.e || !file->tex.n || !file->tex.s || !file->tex.w)
	{
		tmp = get_next_line(file->fd);
		if (tmp == NULL)
			break ;
		if (!ft_strncmp("NO ", tmp, 3) && ft_check_t(&file->tex.n, tmp, "NO"))
			return (1);
		if (!ft_strncmp("SO ", tmp, 3) && ft_check_t(&file->tex.s, tmp, "SO"))
			return (1);
		if (!ft_strncmp("WE ", tmp, 3) && ft_check_t(&file->tex.w, tmp, "WE"))
			return (1);
		if (!ft_strncmp("EA ", tmp, 3) && ft_check_t(&file->tex.e, tmp, "EA"))
			return (1);
		free(tmp);
	}
	if (ft_file_c(file->tex.e, ".xpm") || ft_file_c(file->tex.n, ".xpm") || \
		ft_file_c(file->tex.s, ".xpm") || ft_file_c(file->tex.w, ".xpm"))
		return (1);
	return (0);
}

int	ft_start_parse(t_file *file, char *file_path)
{
	if (ft_file_init(file, file_path) || ft_file_load_tiles(file))
		return (1);
	if (ft_check_colors(file) || ft_map(file))
		return (1);
	return (0);
}
