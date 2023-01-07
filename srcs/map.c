/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:41:05 by agengemb          #+#    #+#             */
/*   Updated: 2022/12/31 14:36:01 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"

t_img	**init_tiles_set(void *mlx)
{
	t_img	**tiles_set;

	tiles_set = malloc(sizeof(t_img) * 4);
	if (!tiles_set)
		return (NULL);
	tiles_set[0] = init_new_img(mlx, "Images/Tiles/XPM/Ground.xpm");
	if (!tiles_set[0])
		return (NULL);
	tiles_set[1] = init_new_img(mlx, "Images/Tiles/XPM/Wall.xpm");
	if (!tiles_set[1])
	{
		free_set(mlx, tiles_set, 1);
		return (NULL);
	}
	tiles_set[2] = init_new_img(mlx, "Images/Tiles/XPM/Collectible.xpm");
	if (!tiles_set[2])
	{
		free_set(mlx, tiles_set, 2);
		return (NULL);
	}
	tiles_set[3] = init_new_img(mlx, "Images/Tiles/XPM/Exit.xpm");
	if (!tiles_set[3])
	{
		free_set(mlx, tiles_set, 3);
		return (NULL);
	}
	return (tiles_set);
}

int	check_block(void *mlx, t_map *map, char symbol, size_t *position)
{
	size_t i;
	size_t j;

	i = position[0];
	j = position[1];
	if (i == 0 || i == map->line_nb - 1 || j == 0 || j == map->row_nb - 1)
		return (symbol == '1');
	else if (symbol == 'P')
	{
		if (!map->player)
		{
			map->player = init_player(mlx, i, j);
			return (1);
		}
		else
			return (0);
	}
	else if (symbol == 'E')
	{
		if (!map->exit)
		{
			map->exit = &map->block_map[i][j];
			return (1);
		}
		else
			return (0);
	}
	else if (symbol == 'C')
		map->collectibles_nb++;
	return (1);
}

int	fill_map(void *mlx, t_map *map, t_block **block_map, t_queue *queue)
{
	size_t	i;
	size_t	j;
	char	*line;
	size_t position[2];

	position[0] = 0;
	while (position[0] < map->line_nb)
	{
		line = queue->content;
		position[1] = 0;
		while (position[1] < map->row_nb)
		{
			if (!check_block(mlx, map, line[position[1]], position) || !init_block(&block_map[position[0]][position[1]], line[position[1]], map->tiles_set)) 
				return (0);
			++position[1];
		}
		queue_pop(&queue);
		++position[0];
	}
	if (!check_path(map, block_map, map->player->i, map->player->j))
		return (0);
	return (1);
}


int	init_block_map(void *mlx, t_map *map, t_queue *queue)
{
	t_block	**block_map;

	block_map = malloc(sizeof(t_block *) * map->line_nb);
	if (!block_map || !create_2d_tab(map, block_map))
		return (0);
	map->block_map = block_map;
	if(!fill_map(mlx, map, block_map, queue) || !map->collectibles_nb
	|| !map->player || !map->exit)
	{
		write(2, "Error\n", 6);
		free_block_map(block_map, map->line_nb);
		return (0);
	}
	return (1);
}

t_map	*create_map(void *mlx, t_queue *queue, size_t line_nb, size_t row_nb)
{
	t_map	*new_map;
	size_t	i;

	new_map = malloc(sizeof(t_map));
	if (!new_map)
		return (NULL);
	new_map->tiles_set = init_tiles_set(mlx);
	if (!new_map->tiles_set )
	{
		free(new_map);
		return (NULL);
	}
	init_map(new_map, line_nb, row_nb);
	if (!init_block_map(mlx, new_map, queue))
	{
		free_set(mlx, new_map->tiles_set, 4);
		free(new_map);
		return (NULL);
	}
	return (new_map);
}
