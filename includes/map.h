/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:41:13 by agengemb          #+#    #+#             */
/*   Updated: 2022/12/30 20:20:18 by agengemb         ###   ########.fr       */
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
# include "backtrack_data.h"

typedef struct s_map
{
	size_t	row_nb;
	size_t	line_nb;
	int	collectibles_nb;
	size_t	empty_nb;
	t_block	*player;
	t_block	*exit;
	t_block **block_map;
}	t_map;

int	init_tiles_set(void *mlx, t_img **tiles_set);
void	free_block_map(t_block **block_map, size_t index);
int	check_block(t_map *map, char block_value, size_t i, size_t j);
int	fill_map(t_map *map, t_block **block_map, t_queue *queue, t_img **tiles_set);
int	init_block_map(void *mlx, t_map *map, t_queue *queue, t_img **tiles_set);
t_map *create_map(void *mlx, t_queue *queue, size_t line_nb, size_t row_nb);

#endif
