/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:14:37 by thed6bel          #+#    #+#             */
/*   Updated: 2023/08/23 10:55:08 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

int	ft_start_parse(t_file *file, char *file_path)
{
	if (ft_file_init(file, file_path) || ft_file_load_tiles(file))
		return (1);
	if (ft_check_colors(file) || ft_map(file))
		return (1);
	return (0);
}
//attention car faut faire une fonction pour free car y a des leaks!