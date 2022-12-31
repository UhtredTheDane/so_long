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

void	free_block_map(t_block **block_map, size_t index)
{
	size_t	i;

	i = 0;
	while (i < index)
	{
		free(block_map[i]);
		++i;
	}
	free(block_map);
}

int	check_block(t_map *map, char symbol, size_t i, size_t j)
{
	if (i == 0 || i == map->line_nb - 1 || j == 0 || j == map->row_nb - 1)
		return (symbol == '1');
	else if (symbol == 'P')
	{
		if (!map->player)
		{
			map->player = &map->block_map[i][j];
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

int	choose_direction(t_block **block_map, int *position, size_t direction)
{
	int	i;
	int	j;

	i = position[0];
	j = position[1];
	if (direction == 0)
		--i;
	else if (direction == 1)
		++j;
	else if (direction == 2)
		++i;
	else if (direction == 3)
		--j;
	if (block_map[i][j].type == '1')
		return (0);
	position[0] = i;
	position[1] = j;
	return (1);	
}

int	is_useless(t_block **block_map, int *position, size_t direction, size_t last_direction)
{
	size_t	i;
	size_t	j;

	i = position[0];
	j = position[1];
	if (direction == 0 && last_direction == 2)
	{
		if (block_map[i][j - 1].type != '1' || block_map[i + 1][j].type != '1' || block_map[i][j + 1].type != '1')
			return (1);
		return (0);
	}
	else if (direction == 2 && last_direction == 0)
	{
		if (block_map[i][j - 1].type != '1' || block_map[i - 1][j].type != '1' || block_map[i][j + 1].type != '1')
			return (1);
		return (0);
	}
	else if (direction == 1 && last_direction == 3)
	{
		if (block_map[i][j - 1].type != '1' || block_map[i + 1][j].type != '1' || block_map[i - 1][j].type != '1')
			return (1);
		return (0);
	}
	else if (direction == 3 && last_direction == 1)
	{
		if (block_map[i - 1][j].type != '1' || block_map[i][j + 1].type != '1' || block_map[i + 1][j].type != '1')
			return (1);
		return (0);
	}
	else
		return (0);
}

int	find_path(t_block **block_map, int *position, t_backtrack_data *data, size_t cross_block_nb)
{
	size_t	direction;
	size_t last_direction;
	size_t	i;
	size_t	j;
	
	if (block_map[position[0]][position[1]].type == 'E' && !data->c_remaining || cross_block_nb == 0)
		return (1);
	direction = 0;
	last_direction = data->last_direction;
	i = position[0];
	j = position[1];
	while (direction < 4 && cross_block_nb)
	{
		if (!is_useless(block_map, position, direction, data->last_direction) && choose_direction(block_map, position, direction))
		{
			
			if (block_map[position[0]][position[1]].type == 'C')
				--data->c_remaining;
			data->last_direction = direction;
			//printf("last_direction = %ld, direction = %ld, empty block: %ld\n", last_direction, direction, cross_block_nb);
			//printf("data c remaining: %d et x: %d et y: %d\n", data->c_remaining, position[0], position[1]);
			if (find_path(block_map, position, data, cross_block_nb - 1))
				return (1);
			if (block_map[position[0]][position[1]].type == 'C')
				++data->c_remaining;
	
			position[0] = i;
			position[1] = j;
			data->last_direction = last_direction;
		}
		++direction;
	}
	return (0);
}
t_block **copy(t_map *map, t_block **block_map)
{
	size_t i;
	size_t j;
	t_block **back;

	back = malloc(sizeof(t_block *) * map->line_nb);
	i = 0;
	while (i < map->line_nb)
	{
		back[i] = malloc(sizeof(t_block) * map->row_nb);
		j = 0;
		while (j < map->row_nb)
		{
			back[i][j] = block_map[i][j];
			++j;
		}
		++i;
	}

	return (back);
}
int	fill_map(t_map *map, t_block **block_map, t_queue *queue, t_img **tiles_set)
{
	size_t	i;
	size_t	j;
	char	*line;
	t_backtrack_data data;
	int position_depart[2];
	t_block **back;

	i = 0;
	while (i < map->line_nb)
	{
		line = queue->content;
		j = 0;
		while (j < map->row_nb)
		{
			if (!check_block(map, line[j], i, j) || !init_block(&block_map[i][j], line[j], tiles_set)) 
				return (0);
			if (block_map[i][j].type == 'P')
			{
				position_depart[0] = i;
				position_depart[1] = j;
			}
			++j;
		}
		queue_pop(&queue);
		++i;
	}
	data.c_remaining = map->collectibles_nb;
	data.last_direction = 4;
	if (!find_path(block_map, position_depart, &data, map->empty_nb))
		return (0);
	printf("sa marche\n");
	return (1);
}

int	create_2d_tab(t_map *map, t_block **block_map)
{
	size_t	i;

	i = 0;
	while (i < map->line_nb)
	{
		block_map[i] = malloc(sizeof(t_block) * map->row_nb);
		if (!block_map[i])
		{
			if (i > 0)
				free_block_map(block_map, i);
			return (0);
		}
		++i;
	}
	return (1);
}

int	init_block_map(void *mlx, t_map *map, t_queue *queue, t_img **tiles_set)
{
	t_block	**block_map;

	block_map = malloc(sizeof(t_block *) * map->line_nb);
	if (!block_map || !create_2d_tab(map, block_map))
		return (0);
	map->block_map = block_map;
	if(!fill_map(map, block_map, queue, tiles_set) || !map->collectibles_nb
	|| !map->player || !map->exit)
	{
		write(2, "Error\n", 6);
		free_block_map(block_map, map->line_nb);
		return (0);
	}
	return (1);
}

void	init_map(t_map *new_map, size_t line_nb, size_t row_nb)
{
	new_map->line_nb = line_nb;
	new_map->row_nb = row_nb;
	new_map->collectibles_nb = 0;
	new_map->empty_nb= line_nb * row_nb;
	new_map->player = NULL;
	new_map->exit = NULL;
}

t_map	*create_map(void *mlx, t_queue *queue, size_t line_nb, size_t row_nb)
{
	t_map	*new_map;
	t_img	*tiles_set[4];
	size_t	i;

	new_map = malloc(sizeof(t_map));
	if (!new_map)
		return (NULL);
	if (!init_tiles_set(mlx, tiles_set))
	{
		free(new_map);
		return (NULL);
	}
	init_map(new_map, line_nb, row_nb);
	if (!init_block_map(mlx, new_map, queue, tiles_set))
	{
		free_tiles_set(mlx, tiles_set, 4);
		free(new_map);
		return (NULL);
	}
	return (new_map);
}
