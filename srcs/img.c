/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:28:55 by agengemb          #+#    #+#             */
/*   Updated: 2022/12/19 16:26:41 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/img.h"

t_img	*init_new_img(void *mlx, char *path)
{
	t_img	*new_img;

	new_img = malloc(sizeof(t_img));
	if (!new_img)
		return (NULL);
	new_img->path = path;
	new_img->img = mlx_xpm_file_to_image(mlx, new_img->path,
			&(new_img->width), &(new_img->height));
	if (!(new_img->img))
	{
		free(new_img);
		return (NULL);
	}
	return (new_img);
}

void	free_img(void *mlx, t_img *img)
{
	mlx_destroy_image(mlx, img->img);
	free(img);
}

void	free_set(void *mlx, t_img **set, size_t size_set)
{
	size_t	i;

	i = 0;
	while (set[i] && i < size_set)
	{
		free_img(mlx, set[i]);
		++i;
	}
	free(set);
}
