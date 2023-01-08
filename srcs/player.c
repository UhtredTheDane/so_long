#include "../includes/player.h"

t_player *init_player(void *mlx, size_t i, size_t j)
{
    t_player *player;

    player = malloc(sizeof(t_player));
    if (!player)
        return (NULL);
    player->i = i;
    player->j = j;
    player->direction = 2;
	player->moves_nb = 0;
    player->sprites_set[0] = init_new_img(mlx, "Images/Sprites/XPM/top_player.xpm");
	if (!player->sprites_set[0])
		return (NULL);
	player->sprites_set[1] = init_new_img(mlx, "Images/Sprites/XPM/right_player.xpm");
	if (!player->sprites_set[1])
	{
		free_set(mlx, player->sprites_set, 1);
		return (NULL);
	}
	player->sprites_set[2] = init_new_img(mlx, "Images/Sprites/XPM/bot_player.xpm");
	if (!player->sprites_set[2])
	{
		free_set(mlx, player->sprites_set, 2);
		return (NULL);
	}
	player->sprites_set[3] = init_new_img(mlx, "Images/Sprites/XPM/left_player.xpm");
	if (!player->sprites_set[3])
	{
		free_set(mlx, player->sprites_set, 3);
		return (NULL);
	}
	return (player);
}

void move_player(t_map *map, t_player *player, size_t direction)
{
	player->direction = direction;
	if (direction == 0)
		make_move(map, player, player->i - 1, player->j);
	else if (direction == 1)
		make_move(map, player, player->i, player->j + 1);
	else if (direction == 2)
		make_move(map, player, player->i + 1, player->j);
	else
		make_move(map, player, player->i, player->j - 1);
}

void make_move(t_map **map, t_player *player, size_t i, size_t j)
{
	if (map->block_map[i][j].type != '1')
	{
		map->block_map[player->i][player->j].type = '0';
		player->i = i;
		player->j = j;
		if (map->block_map[i][j].type == 'C')
		{
			map->block_map[i][j].type = '0';
			--map->collectibles_nb;
		}
		else if (map->block_map[i][j].type == 'E')	
		{
			if (!map->collectibles_nb)
			{
				map->block_map[i][j].type = 'P';
				show_map(canvas);
				ft_printf("Bravo, vous avez gagné !\n");
				exit(0);
				//clean_exit()
			}
		}
		map->block_map[i][j].type = 'P';
		ft_printf("Vous avez fait %ld mouvements.\n", player->moves_nb);
	} 
}
