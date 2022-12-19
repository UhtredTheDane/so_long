/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:29:05 by agengemb          #+#    #+#             */
/*   Updated: 2022/12/19 14:10:11 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMG_H
# define IMG_H

# include <stdlib.h>
# include <stddef.h>
# include "../mlx_linux/mlx.h"
# include "img.h"

typedef struct s_img
{
		void	*img;
	int	width;
	int	height;
	char	*path;
}		t_img;

t_img	*init_new_img(void *mlx, char *path);
void	free_img(void *mlx, t_img *img);
void	free_tiles_set(void *mlx, t_img **tiles_set, size_t size_tiles_set);

#endif
