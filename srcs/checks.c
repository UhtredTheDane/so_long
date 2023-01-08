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
		ft_printf("Error\nLes lignes n'ont pas le même nombre de colonnes");
		return (0);
	}
	return (1);
}

int	check_player(t_map *map, size_t *p_block)
{
	if (!map->player)
	{
		map->player = init_player(mlx, p_block[0], p_block[1]);
		if (!map->player)
			return (0);
		return (1);
	}
	return (0);
}

int	check_block(void *mlx, t_map *map, char symbol, size_t *p_block)
{
	if (p_block[0] == 0 || p_block[0] == map->line_nb - 1 || p_block[1] == 0 || p_block[1] == map->row_nb - 1)
		return (symbol == '1');
	else if (symbol == 'P')
	{
		if (!map->player)
		{
			map->player = init_player(mlx, p_block[0], p_block[1]);
			if (map->player)
				return (1);
		}
	}
	else if (symbol == 'E')
	{
		if (!map->exit)
		{
			map->exit = &map->block_map[p_block[0]][p_block[1]];
			return (1);
		}
	}
	else if (symbol == 'C')
		map->collectibles_nb++;
	else if (symbol == '1')
		return (1);
	ft_printf("Error\nUn blocks de la map n'est pas valide\n");
	return (0);
}

int check_path(t_map *map, t_block **block_map, int i_start, int j_start)
{
	t_block **tempo_block_map;
	size_t	i;
	size_t	j;

	tempo_block_map = copy(map, block_map);
	if (!tempo_block_map)
		return (0);
	rec_fill(tempo_block_map, i_start, j_start);
	i = 0;
	while (i < map->line_nb)
	{
		j = 0;
		while (j < map->row_nb)
		{
			if (tempo_block_map[i][j].type != 'G' && tempo_block_map[i][j].type != '1')
			{
				free_block_map(tempo_block_map, map->line_nb);
				return (0);
			}
			++j;
		}
		++i;
	}
	free_block_map(tempo_block_map, map->line_nb);
	return (1);
}