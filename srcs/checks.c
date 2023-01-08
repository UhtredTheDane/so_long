#include "../includes/checks.h"

int	check_format(char *file_name)
{
	size_t	size_name;

	size_name = ft_strlen(file_name);
	if (file_name[size_name - 1] != 'r')
		return (0);
	else if (file_name[size_name - 2] != 'e')
		return (0);
	else if (file_name[size_name - 3] != 'b')
		return (0);
	else if (file_name[size_name - 4] != '.')
		return (0);
	else
		return (1);
}

int	check_row_nb(char *line, size_t *row_nb)
{
	if (ft_strlen(line) - 1 != *row_nb)
	{
		printf("Error\n");
		return (0);
	}
	return (1);
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

int check_path(t_map *map, t_block **block_map, int i_start, int j_start)
{
	t_block **tempo_block_map;
	size_t	i;
	size_t	j;

	tempo_block_map = copy(map, block_map);
	//check
	rec_fill(tempo_block_map, i_start, j_start);
	i = 0;
	while (i < map->line_nb)
	{
		j = 0;
		while (j < map->row_nb)
		{
			if (tempo_block_map[i][j].type != 'G' && tempo_block_map[i][j].type != '1')
				return (0);
			++j;
		}
		++i;
	}
	free_block_map(tempo_block_map, map->line_nb);
	return (1);
}