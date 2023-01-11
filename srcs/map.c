/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:41:05 by agengemb          #+#    #+#             */
/*   Updated: 2023/01/11 05:47:01 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"

t_img	**init_tiles_set(void *mlx)
{
	t_img	**tiles_set;

	tiles_set = malloc(sizeof(t_img) * 4);
	if (!tiles_set)
		return (NULL);
	tiles_set[0] = init_img(mlx, "Images/Tiles/XPM/Ground.xpm");
	tiles_set[1] = init_img(mlx, "Images/Tiles/XPM/Wall.xpm");
	tiles_set[2] = init_img(mlx, "Images/Tiles/XPM/Collectible.xpm");
	tiles_set[3] = init_img(mlx, "Images/Tiles/XPM/Exit.xpm");
	if (!tiles_set[0] || !tiles_set[1] || !tiles_set[2] || !tiles_set[3])
	{
		free_set(mlx, tiles_set, 4);
		return (NULL);
	}
	return (tiles_set);
}

int	init_block_map(void *mlx, t_map *map, t_queue *queue)
{
	t_block	**block_map;

	block_map = malloc(sizeof(t_block *) * map->line_nb);
	if (!block_map || !create_2d_tab(map, block_map))
		return (0);
	map->block_map = block_map;
	if (!fill_map(mlx, map, block_map, queue) || !map->collectibles_nb
		|| !map->player || !map->exit)
	{
		free_block_map(block_map, map->line_nb);
		if (!map->player)
		{
			free_set(mlx, map->player->sprites_set, 4);
			free(map->player);
		}
		return (0);
	}
	return (1);
}

t_map	*init_map(void *mlx, size_t line_nb, size_t row_nb)
{
	t_map	*new_map;

	new_map = malloc(sizeof(t_map));
	if (!new_map)
		return (NULL);
	new_map->line_nb = line_nb;
	new_map->row_nb = row_nb;
	new_map->collectibles_nb = 0;
	new_map->player = NULL;
	new_map->exit = NULL;
	new_map->tiles_set = init_tiles_set(mlx);
	if (!new_map->tiles_set)
	{
		free(new_map);
		return (NULL);
	}
	return (new_map);
}

t_map	*create_map(void *mlx, t_queue *queue, size_t line_nb, size_t row_nb)
{
	t_map	*new_map;

	new_map = init_map(mlx, line_nb, row_nb);
	if (!new_map)
		return (NULL);
	if (!init_block_map(mlx, new_map, queue))
	{
		free_set(mlx, new_map->tiles_set, 4);
		free(new_map);
		return (NULL);
	}
	return (new_map);
}
