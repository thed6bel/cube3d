/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thed6bel <thed6bel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:40:29 by hucorrei          #+#    #+#             */
/*   Updated: 2023/07/24 14:52:52 by thed6bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"

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

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	is_valid_map_obj(char c)
{
	if (c == '0' || c == ' ' || c == '1' || is_player(c))
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
