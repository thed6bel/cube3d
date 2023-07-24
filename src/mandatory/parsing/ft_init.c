/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thed6bel <thed6bel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:17:36 by thed6bel          #+#    #+#             */
/*   Updated: 2023/07/21 10:56:48 by thed6bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cube3d.h"

int	ft_check_tile(char **tile, char *line, char *cardinal)
{
	printf("1\n");
	if (!*tile)
	{
		printf("2\n");
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
	char	*l;
	char	*tmp;

	while (!file->ea || !file->no || !file->so || !file->we)
	{
		tmp = get_next_line(file->fd);
		if (tmp == NULL)
			break ;
		printf("temp = %s\n", tmp);
		// l = ft_trim(temp);
		// printf("l = %s\n", l);
		// free(temp);
		if (!ft_strncmp("NO ", tmp, 3) && ft_check_tile(&file->no, tmp, "NO"))
			return (1);
		if (!ft_strncmp("SO ", tmp, 3) && ft_check_tile(&file->so, tmp, "SO"))
			return (1);
		if (!ft_strncmp("WE ", tmp, 3) && ft_check_tile(&file->we, tmp, "WE"))
			return (1);
		if (!ft_strncmp("EA ", tmp, 3) && ft_check_tile(&file->ea, tmp, "EA"))
			return (1);
		free(tmp);
		printf("file->ea = %s\n", file->ea);
		printf("file->no = %s\n", file->no);
		printf("file->so = %s\n", file->so);
		printf("file->we = %s\n", file->we);
	}
	if (ft_file_check(file->ea, ".xpm") || ft_file_check(file->no, ".xpm") || \
		ft_file_check(file->so, ".xpm") || ft_file_check(file->we, ".xpm"))
		return (1);
	return (0);
}

int	ft_file_check(char *file_path, char *type)
{
	char	*temp;
	int		i;
	int		fd;

	if (!file_path)
		return (printf("NULL file path! EXPECTED: '*%s'\n", type));
	i = 0;
	temp = type;
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (printf("Exception: %s: '%s'\n", file_path, strerror(errno)));
	while (file_path[i] && (file_path[i] != '.' || file_path[i + 1] == '/'))
		i++;
	if ((!i || file_path[i - 1] == '/') && !close(fd))
		return (printf("Bad file name!\n"));
	while (file_path[i] && *type && file_path[i] == *type++)
		i++;
	if (!*type && !file_path[i])
		return (close(fd));
	else if (!close(fd))
		printf("Bad file type! EXPECTED: '*%s'\n", temp);
	return (1);
}

int	ft_file_init(t_file *file, char *file_path)
{
	file->ceilling.red = -1;
	file->ceilling.green = -1;
	file->ceilling.blue = -1;
	file->floor.red = -1;
	file->floor.green = -1;
	file->floor.blue = -1;
	file->no = NULL;
	file->so = NULL;
	file->we = NULL;
	file->ea = NULL;
	file->map = NULL;
	file->file_path = ft_trim(file_path);
	if (ft_file_check(file->file_path, ".cub"))
		return (1);
	file->fd = open(file->file_path, O_RDONLY);
	return (0);
}
