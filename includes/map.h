/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:41:13 by agengemb          #+#    #+#             */
/*   Updated: 2023/01/11 05:10:39 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include "../mlx_linux/mlx.h"
# include "../get_next_line/get_next_line.h"
# include "../ft_printf/includes/ft_printf.h"
# include "img.h"
# include "block.h"
# include "queue.h"
# include "player.h"
# include "checks.h"
# include "so_long.h"

typedef struct s_player	t_player;

typedef struct s_map
{
	t_player	*player;
	size_t		row_nb;
	size_t		line_nb;
	t_img		**tiles_set;
	t_block		*exit;
	t_block		**block_map;
	int			collectibles_nb;
}	t_map;

t_img	**init_tiles_set(void *mlx);
int		fill_map(void *mlx, t_map *map, t_block **block_map, t_queue *queue);
int		init_block_map(void *mlx, t_map *map, t_queue *queue);
t_map	*create_map(void *mlx, t_queue *queue, size_t line_nb, size_t row_nb);
t_block	**copy(t_map *map, t_block **block_map);
void	rec_fill(t_block **block_map, int i, int j);
int		create_2d_tab(t_map *map, t_block **block_map);
t_map	*init_map(void *mlx, size_t line_nb, size_t row_nb);
t_queue	*load_map_in_queue(int map_fd, size_t *row_nb);

#endif
