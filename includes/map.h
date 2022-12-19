/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:41:13 by agengemb          #+#    #+#             */
/*   Updated: 2022/12/19 14:13:00 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include "../mlx_linux/mlx.h"
# include "img.h"
# include "block.h"
# include "queue.h"

typedef struct s_map
{
	size_t	row_nb;
	size_t	line_nb;
	t_block **block_map;
}	t_map;

int	init_tiles_set(void *mlx, t_img **tiles_set);
void  free_map(t_map *map, size_t index);
int fill_map(void *mlx, t_map *map, t_queue *queue, t_img **tiles_set);
t_map *create_map(void *mlx, t_queue *queue, size_t line_nb, size_t row_nb);

#endif
