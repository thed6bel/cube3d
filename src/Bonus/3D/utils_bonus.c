/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:37:32 by lowathar          #+#    #+#             */
/*   Updated: 2023/09/01 14:56:07 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d_bonus.h"

float	degree_to_radians(float degree)
{
	return (degree * M_PI / 180);
}

t_list	*get_anim(t_img *img, t_list **anim)
{
	if (!img)
		return (*anim);
	if (!img->i)
	{
		free(img);
		return (*anim);
	}
	ft_lstadd_back(anim, ft_lstnew(img));
	return (*anim);
}
