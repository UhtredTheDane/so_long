/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:41:05 by agengemb          #+#    #+#             */
/*   Updated: 2022/12/19 16:06:47 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"

int	init_tiles_set(void *mlx, t_img **tiles_set)
{
	tiles_set[0] = init_new_img(mlx, "Images/Tiles/XPM/Ground.xpm");
	if (!tiles_set[0])
		return (0);
	tiles_set[1] = init_new_img(mlx, "Images/Tiles/XPM/Wall.xpm");
	if (!tiles_set[1])
	{
		free_tiles_set(mlx, tiles_set, 1);
		return (0);
	}
	tiles_set[2] = init_new_img(mlx, "Images/Tiles/XPM/Collectible.xpm");	
	if (!tiles_set[2])
	{
		free_tiles_set(mlx, tiles_set, 2);
		return (0);
	}
	tiles_set[3] = init_new_img(mlx, "Images/Tiles/XPM/Exit.xpm");
	if (!tiles_set[3])
	{
		free_tiles_set(mlx, tiles_set, 3);
		return (0);
	}
	return (1);
}

void  free_map(t_map *map, size_t index)
{
	size_t i;

	i = 0;
	while (i < index)
	{
		free(map->block_map[i]);
		++i;
	}
	free(map->block_map);
	free(map);
}

int fill_map(void *mlx, t_map *map, t_queue *queue, t_img **tiles_set)
{
	size_t	i;
	size_t	j;
	char	*line;
	
	i = 0;
	while (i < map->line_nb)
	{
		line = queue->content;	
		j = 0;
		while (j < map->row_nb)
		{
			if (!init_block(&map->block_map[i][j], line[j], tiles_set))
			{
				write(2, "Error\n", 6);
				free_tiles_set(mlx, tiles_set, 4);
				free_map(map, map->line_nb);
				return (0);
			}
			++j;
	  	}
	  	queue_pop(&queue);
   	 	++i;
	}
	return (1);
}

t_map *create_map(void *mlx, t_queue *queue, size_t line_nb, size_t row_nb)
{
	t_map	*new_map;
	t_img	*tiles_set[4];
	size_t	i;
  
	if (!init_tiles_set(mlx, tiles_set))
		return (NULL);
	new_map = malloc(sizeof(t_map));
	if (!new_map)
		return (NULL);
	new_map->line_nb = line_nb;
	new_map->row_nb = row_nb;
	new_map->block_map = malloc(sizeof(t_block *) * new_map->line_nb);
	if (!new_map->block_map)
	{
		free_tiles_set(mlx, tiles_set, 4);
		free(new_map);
		return (NULL);
	}
	i = 0;
	while (i < new_map->line_nb)
	{
		new_map->block_map[i] = malloc(sizeof(t_block) * new_map->row_nb);
		if (!new_map->block_map[i])
      		{
			if (i > 0)
          			free_map(new_map, i);
				free_tiles_set(mlx, tiles_set, 4);
			return (NULL); 
      		}
      		++i;
  	}
	if(!fill_map(mlx, new_map, queue, tiles_set))
		return (NULL);
	return (new_map);
}
