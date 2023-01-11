/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:29:05 by agengemb          #+#    #+#             */
/*   Updated: 2023/01/11 05:02:18 by agengemb         ###   ########.fr       */
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
	int		width;
	int		height;
	char	*path;
}		t_img;

t_img	*init_img(void *mlx, char *path);
void	free_img(void *mlx, t_img *img);
void	free_set(void *mlx, t_img **set, size_t size_set);

#endif
