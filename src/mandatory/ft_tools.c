/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:40:29 by hucorrei          #+#    #+#             */
/*   Updated: 2023/07/19 09:44:26 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"

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
