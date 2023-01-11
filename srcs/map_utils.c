/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 04:36:45 by agengemb          #+#    #+#             */
/*   Updated: 2023/01/11 20:37:15 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"

t_block	**copy(t_map *map, t_block **block_map)
{
	size_t	i;
	size_t	j;
	t_block	**back;

	back = malloc(sizeof(t_block *) * map->line_nb);
	if (!back)
		return (NULL);
	i = 0;
	while (i < map->line_nb)
	{
		back[i] = malloc(sizeof(t_block) * map->row_nb);
		if (!back[i])
		{
			free_block_map(back, i);
			return (NULL);
		}
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

void	rec_fill(t_block **block_map, int i, int j)
{
	block_map[i][j].type = 'G';
	if (block_map[i - 1][j].type != 'G' && block_map[i - 1][j].type != '1')
		rec_fill(block_map, i - 1, j);
	if (block_map[i + 1][j].type != 'G' && block_map[i + 1][j].type != '1')
		rec_fill(block_map, i + 1, j);
	if (block_map[i][j + 1].type != 'G' && block_map[i][j + 1].type != '1')
		rec_fill(block_map, i, j + 1);
	if (block_map[i][j - 1].type != 'G' && block_map[i][j - 1].type != '1')
		rec_fill(block_map, i, j - 1);
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
			free_block_map(block_map, i);
			return (0);
		}
		++i;
	}
	return (1);
}

int	fill_map(void *mlx, t_map *map, t_block **block_map, t_queue *queue)
{
	char	*line;
	size_t	position[2];

	position[0] = 0;
	while (position[0] < map->line_nb)
	{
		line = queue->content;
		position[1] = 0;
		while (position[1] < map->row_nb)
		{
			if (!check_block(mlx, map, line[position[1]], position))
				return (0);
			init_block(&block_map[position[0]][position[1]],
				line[position[1]], map->tiles_set);
			++position[1];
		}
		queue_pop(&queue);
		++position[0];
	}
	if (!check_min(map))
		return (0);
	if (!check_path(map, block_map, map->player->i, map->player->j))
		return (0);
	return (1);
}

t_queue	*load_map_in_queue(int map_fd, size_t *row_nb)
{
	char	*line;
	t_queue	*queue;
	t_queue	*elem;
	int		good;

	line = "";
	queue = NULL;
	good = 1;
	while (line != NULL)
	{
		line = get_next_line(map_fd);
		if (line != NULL)
		{
			if (!queue)
				*row_nb = ft_strlen2(line) - 1;
			else
				if (!check_row_nb(line, row_nb))
					good = 0;
			elem = ft_queuenew(line);
			queue_add(&queue, elem);
		}
	}
	return (is_queue_good(queue, good));
}
