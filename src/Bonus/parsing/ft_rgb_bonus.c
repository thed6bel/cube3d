/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgb_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:52:14 by thed6bel          #+#    #+#             */
/*   Updated: 2023/08/30 15:21:41 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d_bonus.h"

int	ft_color_export(char *str)
{
	int	i;
	int	value;

	value = 0;
	i = 0;
	if (str[i] && str[i] == ',')
		str++;
	while (str[i] && str[i] >= '0' && str[i] <= '9' && i < 3)
	{
		value = value * 10;
		value += str[i++] - 48;
	}
	if ((str[i] >= '0' && str[i] <= '9') || str[i] != ',')
	{
		if (str[i])
			return (-2);
	}
	if (i && (value >= 0 && value <= 255))
		return (value);
	return (-1);
}

int	ft_get_colors(t_rgb *rgb, char *str)
{
	char	*temp;

	temp = str;
	if (*str)
		rgb->red = ft_color_export(str);
	while (*str && *str >= '0' && *str <= '9')
		str++;
	if (*str)
		rgb->green = ft_color_export(str++);
	while (*str && *str >= '0' && *str <= '9')
		str++;
	if (*str)
		rgb->blue = ft_color_export(str++);
	while (*str && *str >= '0' && *str <= '9')
		str++;
	if (!*str && rgb->red >= 0 && rgb->red <= 255 && rgb->green >= 0 && \
		rgb->green <= 255 && rgb->blue >= 0 && rgb->blue <= 255)
	{
		free(temp);
		return (0);
	}
	free(temp);
	return (1);
}

int	ft_check_colors(t_file *file)
{
	int		f;
	int		c;
	char	*line;
	char	*temp;

	f = 1;
	c = 1;
	while (c || f)
	{
		temp = get_next_line(file->fd);
		if (!temp)
			break ;
		line = ft_trim(temp);
		free(temp);
		if (f && ft_strlen(line) > 4 && line[0] == 'F' && line[1] == ' ')
			f = ft_get_colors(&file->floor, ft_trim(line + 2));
		else if (c && ft_strlen(line) > 4 && line[0] == 'C' && line[1] == ' ')
			c = ft_get_colors(&file->ceilling, ft_trim(line + 2));
		free(line);
	}
	if ((f && printf("Error in identifier F\n")) || \
		(c && printf("Error in identifier C\n")))
		return (1);
	return (0);
}
