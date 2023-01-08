#include "../includes/map.h"
#include "../includes/block.h"

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

void rec_fill(t_block **block_map, int i, int j)
{
	block_map[i][j].type = 'G';
	if (block_map[i-1][j].type != 'G' && block_map[i-1][j].type != '1')
		rec_fill(block_map, i - 1, j);
	if (block_map[i+1][j].type != 'G' && block_map[i+1][j].type != '1')
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
			if (i > 0)
				free_block_map(block_map, i);
			return (0);
		}
		++i;
	}
	return (1);
}

void	init_map(t_map *new_map, size_t line_nb, size_t row_nb)
{
	new_map->line_nb = line_nb;
	new_map->row_nb = row_nb;
	new_map->collectibles_nb = 0;
	new_map->player = NULL;
	new_map->exit = NULL;
}

t_queue	*load_map_in_queue(int map_fd, size_t *row_nb)
{
	char	*line;
	t_queue	*queue;
	t_queue	*elem;

	line = "";
	queue = NULL;
	while (line != NULL)
	{
		line = get_next_line(map_fd);
		if (line != NULL)
		{
			if (!queue)
				*row_nb = ft_strlen(line) - 1;
			else
				if (!check_row_nb(line, row_nb))
					return (NULL);
			elem = ft_queuenew(line);
			queue_add(&queue, elem);
		}
	}
	return (queue);
}